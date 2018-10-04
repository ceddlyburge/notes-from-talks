using System;
using System.IO;


namespace GeneralizationCs
{
    public class LoginCommand : Cmd
    {
        protected override char[] commandChar => 
            new char[] { (char)0x01 };

        public LoginCommand(string name, string password)
        {
            bodyValues = new string[] { name, password };
        }
    }
}
