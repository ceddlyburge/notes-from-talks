using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Script.Serialization;

namespace ProjectView
{
    public class ProjectActions
    {
        public void Create(string Name,
         string ProjectManager,
         int Phase,
         string etc)
        {
            var message = new JavaScriptSerializer().Serialize(new ProjectEvents.Create()
            {
                Name = Name,
                ProjectManager = ProjectManager,
                Phase = Phase,
                etc = etc
            });

            // do something with message
            File.WriteAllText($@"c:\users\cburge\desktop\messages\{Guid.NewGuid()}.txt", message);

        }

    }
}
