using System;

namespace Homeguard
{
	/// <summary>
	/// Summary description for Sensor.
	/// </summary>
	public abstract class Sensor
	{
		public const string DOOR = "door";
		public const string MOTION = "motion";
		public const string WINDOW = "window";
		public const string FIRE = "fire";

		private string id;
		private string location;
		private bool tripped = false;

		public Sensor(string id, string location)
        {
			this.id = id;
			this.location = location;
		}

		public String GetID()
		{
			return id;
		}

		public String GetLocation()
		{
			return location;
		}

		public void Trip()
		{
			tripped = true;
		}

		public void Reset()
		{
			tripped = false;
		}

		public bool IsTripped()
		{
			return tripped;
		}

        public void SetStatus(string status)
        {
            if ("TRIPPED" == status)
                Trip();
            else
                Reset();
        }


        public string GetSensorMessage()
        {
            return IsTripped()
            ? GetTrippedMessage()
            : GetNotTrippedMessage();
        }

        public abstract string GetTrippedMessage();
        public abstract string GetNotTrippedMessage();
        
    }
}
