using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProjectView
{
    class Program
    {
        static void Main(string[] args)
        {
            new ProjectActions().Create("MicroWind", "Cedd", 0, "...");
        }
    }
}
