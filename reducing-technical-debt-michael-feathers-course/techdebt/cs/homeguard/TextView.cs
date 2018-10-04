using System;

namespace Homeguard
{
	/// <summary>
	/// Summary description for TextView.
	/// </summary>
	public class TextView : IHomeguardView
	{
		public void ShowMessage(string message) {
			Console.WriteLine(message);
		}

	}
}
