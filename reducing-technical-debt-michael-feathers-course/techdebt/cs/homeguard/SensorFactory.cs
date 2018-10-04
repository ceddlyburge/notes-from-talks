using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homeguard
{
    public class SensorFactory
    {
        public Sensor CreateSensor(string id, string location, string type)
        {
            if (type == Sensor.DOOR)
                return new DoorSensor(id, location);
            else if (type == Sensor.WINDOW)
                return new WindowSensor(id, location);
            else if (type == Sensor.MOTION)
                return new MotionSensor(id, location);
            else if (type == Sensor.FIRE)
                return new FireSensor(id, location);

            throw new ArgumentException("Invalid type");
        }
    }
}
