using System;
using System.Text;

namespace SchedulerCSharp
{
	public class Meeting : Event
	{
		private string description;
	
		public Meeting(DateTime date, DayTime slot, String description) 
			: base (date, slot)
		{
			this.description = description;
		}

		public string Text
		{
			get 
			{
				return description;
			}
		}

		public bool IsPastDue() 
		{
			return TimeServices.IsPastDue(Date);
		}
	
		public override string ToString() 
		{
			StringBuilder builder = new StringBuilder();
			int n = 0;
			builder.Append(base.ToString());
			string result = FormatText(description);
			builder.Append("[" + result.Length);
			for(n = 0; n < result.Length; n++) 
			{
				builder.Append("{");			
			}
			builder.Append(FormatText(description));
			for(n = 0; n < result.Length; n++) 
			{
				builder.Append("}");			
			}		
			builder.Append(result.Length + "]");
			return builder.ToString();
		}

  

		public void AppendToText(string newText)
		{
			description += newText;
		}


		public static string FormatToStringText(string text)
		{
			StringBuilder result = new StringBuilder();
			for (int n = 0; n < text.Length; ++n) 
			{
				int c = text[n];
				if (c == '<') 
				{
					++n;
					while(text[n] != '>')
						n++;
				}
				else if (n < text.Length)
					result.Append(text[n]);
			}
			return result.ToString();			
		}

		private string FormatText(String text) 
		{
			return FormatToStringText(text);
		}

	}
}
