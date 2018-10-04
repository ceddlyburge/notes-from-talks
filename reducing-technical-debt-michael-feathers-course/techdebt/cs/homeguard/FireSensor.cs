using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Homeguard
{
    public class FireSensor : Sensor
    {
        public FireSensor(string id, string location)
            : base(id, location)
        {
        }

        public override string GetTrippedMessage() =>
            GetLocation() + " is on FIRE!";

        public override string GetNotTrippedMessage() =>
            GetLocation() + " temperature is normal";

    }
}
