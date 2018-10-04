// Learn more about F# at http://fsharp.org
// See the 'F# Tutorial' project for more help.

[<EntryPoint>]
let main argv = 
    let projectNagListStore = System.IO.File.CreateText(@"c:\users\cburge\desktop\naglist\naglist.txt")
           
    for messageFile in System.IO.Directory.GetFiles(@"c:\users\cburge\desktop\messages\") do
        let message = System.IO.File.ReadAllText(messageFile)
        projectNagListStore.WriteLine(message)

    projectNagListStore.Close()

    0 // return an integer exit code

