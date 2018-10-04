using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace Homeguard
{
    public class ParseRadioBroadcastTests
    {

        [Test]
        public void IgnoresNonMatchingSensor()
        {
            var sut = new CentralUnit();

            sut.AcceptPacket("1,TRIPPED");
        }

        [Test]
        public void SensorTrippableOnParse()
        {
            var sensor = new DoorSensor("1", "");

            var sut = new CentralUnit();
            sut.RegisterSensor(sensor);

            sut.AcceptPacket($"1,TRIPPED");

            Assert.AreEqual(true, sensor.IsTripped());
        }

        [Test]
        public void SendsMessageToView()
        {
            const string SENSOR_ID = "<x>";
            const string NOT_TRIPPED = "anything but tripped";

            var sensor = new DoorSensor(SENSOR_ID, "");

            var view = new MockView();

            var sut = new CentralUnit();
            sut.RegisterSensor(sensor);
            sut.SetView(view);

            sut.AcceptPacket($"{SENSOR_ID},{NOT_TRIPPED}");

            Assert.AreEqual(sensor.GetSensorMessage(), view.lastMessage);
        }
    }
}
