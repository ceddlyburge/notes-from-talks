using System;

namespace Homeguard
{
	public class MockAudibleAlarm : IAudibleAlarm
	{
		public bool isOn = false;

		public void Sound() {
			isOn = true;
		}

		public void Silence() {
			isOn = false;
		}
	}
}
