using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homeguard
{
    public class Diagnostics
    {
        // sensor test status options
        public static readonly string PASS = "PASS";
        public static readonly string FAIL = "FAIL";
        public static readonly string PENDING = "pending";
        public static readonly string READY = "ready";

        public Hashtable sensorTestStatusMap;
        public bool runningSensorTest;
        public string sensorTestStatus;

        public string GetSensorTestStatus()
        {
            return sensorTestStatus;
        }

        public Hashtable GetSensorTestStatusMap()
        {
            return sensorTestStatusMap;
        }

        public void RunSensorTest(IEnumerable<Sensor> sensors)
        {
            runningSensorTest = true;
            sensorTestStatus = PENDING;

            // initialize the status map
            sensorTestStatusMap = new Hashtable();
            foreach (Sensor sensor in sensors)
            {
                sensorTestStatusMap[sensor.GetID()] = PENDING;
            }
        }

        public void AdjustStatusForSensorTest(string id, string status)
        {
            // check if a sensor test is running and adjust status
            if (runningSensorTest)
            {
                if ("TRIPPED" == status)
                {
                    sensorTestStatusMap[id] = Diagnostics.PASS;
                }

                // check to see if test is complete
                bool done = true;
                IDictionaryEnumerator myEnumerator = sensorTestStatusMap.GetEnumerator();
                while (myEnumerator.MoveNext())
                {
                    string testStatus = (string)myEnumerator.Value;
                    if (PENDING == testStatus)
                    {
                        done = false;
                        break;
                    }
                }

                //terminate test if complete
                if (done)
                    TerminateSensorTest();
            }
        }


        public void TerminateSensorTest()
        {
            runningSensorTest = false;

            // look at individual sensor status to determine the overall test status
            sensorTestStatus = PASS;
            IDictionaryEnumerator myEnumerator = sensorTestStatusMap.GetEnumerator();
            while (myEnumerator.MoveNext())
            {
                string status = (string)myEnumerator.Value;
                if (status == PENDING)
                {
                    sensorTestStatus = FAIL;
                    break;
                }
            }
        }
    }
}
