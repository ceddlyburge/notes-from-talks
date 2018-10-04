using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace Homeguard
{
    public class CentralUnit
    {

        private bool armed = false;
        private string securityCode;
        private IList sensors = new ArrayList();
        private IHomeguardView view = new TextView();
        private IAudibleAlarm audibleAlarm = new TextAudibleAlarm();

        // members to help with sensor tests
        Diagnostics diagnostics = new Diagnostics();

        public bool IsArmed()
        {
            return armed;
        }

        public void Arm()
        {
            armed = true;
        }

        public void SetSecurityCode(string code)
        {
            securityCode = code;
        }

        public bool IsValidCode(string code)
        {
            return securityCode == code;
        }

        public void EnterCode(string code)
        {
            if (IsValidCode(code))
            {
                armed = false;
                audibleAlarm.Silence();
            }
        }

        public bool AudibleAlarmIsOn()
        {
            return false;
        }

        public IList GetSensors()
        {
            return sensors;
        }

        public void RegisterSensor(Sensor sensor)
        {
            sensors.Add(sensor);
        }

        public void SetView(IHomeguardView view)
        {
            this.view = view;
        }

        public void SetAudibleAlarm(IAudibleAlarm alarm)
        {
            audibleAlarm = alarm;
        }

        public void AcceptPacket(string packet)
        {
            //parse the packet
            string[] tokens = packet.Split(",".ToCharArray());
            string id = tokens[0];
            string status = tokens[1];

            var sensor = FindSensor(id);

            if (sensor == null)
                return;

            sensor.SetStatus(status);

            //get the message from the sensor and display it
            string message = sensor.GetSensorMessage();
            view.ShowMessage(message);

            // sound the alarm if armed
            if (IsArmed())
                audibleAlarm.Sound();

            diagnostics.AdjustStatusForSensorTest(id, status);
        }

        private Sensor FindSensor(string id)
        {
            Sensor sensor = null;
            foreach (Sensor s in sensors)
            {
                if (s.GetID() == id)
                {
                    sensor = s;
                    break;
                }
            }

            return sensor;
        }

        public void RunSensorTest()
        {
            diagnostics.RunSensorTest(sensors.Cast<Sensor>());
        }

    }
}
