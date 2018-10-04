using System;

namespace SchedulerCSharp
{
	public class SchedulerDisplay 
	{
		public virtual void ShowEvent(Event anEvent) 
		{
			for(int n = 0; n < 1000; n++) 
			{
				Console.WriteLine("[" + anEvent.Date + "]");	
			}
		}
	}
}
