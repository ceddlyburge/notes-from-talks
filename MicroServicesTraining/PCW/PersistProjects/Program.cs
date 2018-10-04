using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Web.Script.Serialization;

namespace PersistProjects
{
    public class Program
    {
        public static int Main(string[] args)
        {
            string rootPath = args[0];
            if (File.Exists(GetInconsistentMarkerFile(rootPath)))
            {
                Console.WriteLine(File.ReadAllText(GetInconsistentMarkerFile(rootPath)));
                return 1;
            }
            
            using (var projectsStore = File.AppendText($@"{rootPath}\PersistedProjects\projects.txt"))
            {
                foreach (var file in Directory.GetFiles($@"{rootPath}\messages\"))
                {
                    // TODO: need to check to see if it is a project create message at some point

                    if (HasEventBeenActioned(rootPath, file) == false)
                    {
                        PersistProjectFromProjectCreateEvent(projectsStore, file);

                        TryMarkEventAsActioned(rootPath, file);

                        // TODO: need to create a project created event
                    }
                }
            }

            return 0;
        }

        private static void TryMarkEventAsActioned(string rootPath, string file)
        {
            try
            {
                MarkEventAsActioned(rootPath, file);
            }
            catch (Exception e)
            {
                // if we can't mark the event and actioned and it isn't idempotent then we will be left in an invalid state
                // If we can't write somewhere its also possible that we won't be able to create this file either, so we should probably try some other angles. Write to the registry, write to a database, call another service etc etc.
                File.WriteAllText(GetInconsistentMarkerFile(rootPath), $"Event: '{file}' was processed but wasn't marked as actioned, so would be processed again. Please mark the event as actioned manually and then remove the file marker ('{GetInconsistentMarkerFile(rootPath)}'). The error returned was: '{e.Message}");
            }
        }

        private static string GetInconsistentMarkerFile(string rootPath)
        {
            return rootPath + @"\.inconsistent";
        }

        private static void MarkEventAsActioned(string rootPath, string file)
        {
            File.Copy(file, Path.Combine($@"{rootPath}\PersistProjectsActionedMessages", Path.GetFileName(file)));
        }

        private static void PersistProjectFromProjectCreateEvent(StreamWriter projectsStore, string file)
        {
            projectsStore.WriteLine(File.ReadAllText(file));
        }

        private static bool HasEventBeenActioned(string rootPath, string file)
        {
            return File.Exists(Path.Combine($@"{rootPath}\PersistProjectsActionedMessages", Path.GetFileName(file)));
        }
    }
}
