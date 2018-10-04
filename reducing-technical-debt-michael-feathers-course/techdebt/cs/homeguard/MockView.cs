using System;

namespace Homeguard
{

	public class MockView : IHomeguardView
	{
		public string lastMessage = "";

		public void ShowMessage(string message) {
			lastMessage = message;
		}
	}
}
