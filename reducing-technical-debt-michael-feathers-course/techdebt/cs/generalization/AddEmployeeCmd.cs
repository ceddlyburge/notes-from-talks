using System;
using System.IO;
using System.Linq;

namespace GeneralizationCs
{

    public class AddEmployeeCmd : Cmd
    {
        protected override char[] commandChar => 
            new char[] { (char)0x02 };

        public AddEmployeeCmd(string name, string address, string city, string state, int yearlySalary)
        {
            bodyValues = new string[] { name, address, city, state, yearlySalary.ToString() };
        }
    }
}
