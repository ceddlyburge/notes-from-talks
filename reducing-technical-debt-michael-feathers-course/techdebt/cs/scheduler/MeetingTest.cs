using System;
using NUnit.Framework;

namespace SchedulerCSharp
{

	[TestFixture]
	public class MeetingTest
	{
		[Test]
		public void TestFormat()
		{
			Assert.AreEqual("", Meeting.FormatToStringText(""));
			Assert.AreEqual("", Meeting.FormatToStringText("<a></a>"));
			Assert.AreEqual("a", Meeting.FormatToStringText("<a>a</a>"));
			Assert.AreEqual("bb", Meeting.FormatToStringText("<a>bb</a>"));

			//Assert.AreEqual("<p></p>", Meeting.FormatToStringText("<p></p>"));
		}
	}
}
