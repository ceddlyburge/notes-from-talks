using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;
using System.IO;

namespace PersistProjectsTest
{
    [TestFixture]
    public class PersistsProjectsTest
    {
        [Test]
        public void Creation()
        {
            const string rootPath = @"C:\Users\cburge\Desktop\PCWMicroServciesTest"
                 , projectName = "MicroServices"
                 , projectManager = "Cedd"
                 , etc = "...";
            const int phase = 0;

            CleanWorkspace(rootPath);

            CreateProjectCreateEvent(rootPath, projectName, projectManager, phase, etc);

            PersistProjects.Program.Main(new string[] { rootPath });

            // check that project has been persisted
            Assert.AreEqual(
                GetExpectedPersistedProject(projectName, projectManager, phase, etc)
                , File.ReadAllText(rootPath + @"\PersistedProjects\projects.txt"));
        }

        [Test]
        public void DuplicatesNotCreated()
        {
            const string rootPath = @"C:\Users\cburge\Desktop\PCWMicroServciesTest"
                 , projectName = "MicroServices"
                 , projectManager = "Cedd"
                 , etc = "...";
            const int phase = 0;

            CleanWorkspace(rootPath);

            CreateProjectCreateEvent(rootPath, projectName, projectManager, phase, etc);

            // run projectpersist service twice
            PersistProjects.Program.Main(new string[] { rootPath });
            PersistProjects.Program.Main(new string[] { rootPath });

            // check that project has been persisted just once
            Assert.AreEqual(
                GetExpectedPersistedProject(projectName, projectManager, phase, etc)
                , File.ReadAllText(rootPath + @"\PersistedProjects\projects.txt"));
        }

        private static string GetExpectedPersistedProject(string name, string projectManager, int phase, string etc)
        {
            return $"{{\"Name\":\"{name}\",\"ProjectManager\":\"{projectManager}\",\"Phase\":{phase},\"etc\":\"{etc}\"}}\r\n";
        }

        private static void CreateProjectCreateEvent(string rootPath, string name, string projectManager, int phase, string etc)
        {
            File.WriteAllText(rootPath +  @"\Messages\test.txt", $"{{\"Name\":\"{name}\",\"ProjectManager\":\"{projectManager}\",\"Phase\":{phase},\"etc\":\"{etc}\"}}");
        }

        private static void CleanWorkspace(string rootPath)
        {
            if (Directory.GetFiles(rootPath, "*", SearchOption.AllDirectories).Count() > 10)
                throw new Exception("Are you sure you have got the rootpath correct");

            foreach (var file in Directory.GetFiles(rootPath, "*", SearchOption.AllDirectories))
                File.Delete(file);
        }
    }
}
