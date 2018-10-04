using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace Homeguard
{
    public class SensorTests
    {
        const bool Tripped = true;
        const bool NotTripped = false;

        [Test]
        [TestCase(Tripped, Sensor.DOOR, " is open")]
        [TestCase(NotTripped, Sensor.DOOR, " is closed")]
        [TestCase(Tripped, Sensor.WINDOW, " is ajar")]
        [TestCase(NotTripped, Sensor.WINDOW, " is sealed")]
        [TestCase(Tripped, Sensor.MOTION, "Motion detected in ")]
        [TestCase(NotTripped, Sensor.MOTION, " is motionless")]
        [TestCase(Tripped, Sensor.FIRE, " is on FIRE!")]
        [TestCase(NotTripped, Sensor.FIRE, " temperature is normal")]
        public void GetSensorMessage(bool isTripped, string sensorType, string expectedMessage)
        {
            var sensor = new SensorFactory().CreateSensor("not relevant to test", "", sensorType);

            if (isTripped) sensor.Trip();

            var expected = sensor.GetSensorMessage();

            Assert.AreEqual(expected, expectedMessage);
        }
    }
}
