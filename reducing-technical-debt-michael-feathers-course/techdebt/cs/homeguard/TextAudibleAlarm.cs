using System;
using System.Threading;


namespace Homeguard
{
	/// <summary>
	/// Summary description for TextAudibleAlarm.
	/// </summary>
	public class TextAudibleAlarm : IAudibleAlarm
	{
		private static bool isOn = false;

		private static void ThreadJob() {
			while(isOn) {
				Console.WriteLine("BUZZ BUZZ BUZZ");
				Thread.Sleep(1000);
			}
		}

		public TextAudibleAlarm() {
			ThreadStart job = new ThreadStart(ThreadJob);
			Thread thread = new Thread(job);
			thread.Start();  
		}

		public void Sound() {
			isOn = true;
		}

		public void Silence() {
			isOn = false;
		}
	}
}
