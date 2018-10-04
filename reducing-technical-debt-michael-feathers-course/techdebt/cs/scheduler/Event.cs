using System;

namespace SchedulerCSharp
{

	public class Event
	{
		private DateTime date;
		private DayTime slot;
	
		public Event(DateTime date, DayTime slot) 
		{
			this.date = date;
			this.slot = slot;
		}
	
		public void Added() 
		{
		}
	
		public DateTime Date 
		{ 
			get 
			{
				return date.Date;
			}
		}
	
		public DayTime Slot  
		{
			get 
			{
				return slot;
			}
		}
	
		public override string ToString() 
		{
			return date + " @" + slot + ":00 hours";
		}
	}
}
