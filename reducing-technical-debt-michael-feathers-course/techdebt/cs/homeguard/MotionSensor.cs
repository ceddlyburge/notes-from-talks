using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homeguard
{
    public class MotionSensor : Sensor
    {
        public MotionSensor(string id, string location)
            : base(id, location)
        {
        }

        public override string GetTrippedMessage() =>
            "Motion detected in " + GetLocation();

        public override string GetNotTrippedMessage() =>
            GetLocation() + " is motionless";

    }
}
