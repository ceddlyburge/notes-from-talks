using System;

namespace SchedulerCSharp
{

	public class TimeServices
	{
		public static bool IsPastDue(DateTime date) 
		{
			// imagine this method has a real implementation
			return false;
		}
	
		public static bool IsWorkDay(DateTime date) 
		{
			// imagine this method has a real implementation
			return false;
		}
	
		public static bool IsHoliday(DateTime date) 
		{
			// imagine this method has a real implementation
			return false;
		}

        public bool IsDateAHoliday(DateTime date)
        {
            return IsHoliday(date);
        }

    }
}
