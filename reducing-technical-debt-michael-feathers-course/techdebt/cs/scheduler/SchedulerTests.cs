using SchedulerCSharp;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace scheduler
{
    public class FakeDisplay : SchedulerDisplay
    {
        public override void ShowEvent(Event anEvent)
        {
            
        }
    }

    public class TestingScheduler : Scheduler
    {
        public TestingScheduler(string owner, SchedulerDisplay display) : base(owner, display)
        {

        }

        protected override void SendMail(Event anEvent)
        {
            
        }
    }

    [TestFixture]
    public class SchedulerTests
    {
        [Test]
        public void Instantiate()
        {
            var scheduler = new TestingScheduler("", new FakeDisplay());
            DateTime now = DateTime.Now;
            var dayTime = new DayTime();
            dayTime.value = DayTime.Time10AM;
            scheduler.AddEvent(new Meeting(now, dayTime, "boring meeting"));
        }
    }
}
