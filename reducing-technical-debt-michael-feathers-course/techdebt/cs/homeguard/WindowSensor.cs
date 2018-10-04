using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homeguard
{
    public class WindowSensor : Sensor
    {
        public WindowSensor(string id, string location)
            : base(id, location)
        {
        }

        public override string GetTrippedMessage() =>
            GetLocation() + " is ajar";

        public override string GetNotTrippedMessage() =>
            GetLocation() + " is sealed";

    }
}
