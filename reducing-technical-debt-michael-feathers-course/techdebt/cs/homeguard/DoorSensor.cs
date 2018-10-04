using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homeguard
{
    public class DoorSensor : Sensor
    {
        public DoorSensor(string id, string location)
            : base(id, location)
        {
        }

        public override string GetTrippedMessage() =>
            GetLocation() + " is open";

        public override string GetNotTrippedMessage() =>
            GetLocation() + " is closed";

    }
}
