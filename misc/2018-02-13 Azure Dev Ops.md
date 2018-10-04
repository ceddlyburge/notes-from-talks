
# questions

How much is vsts?
- 10$ per person
set up an sql server on build machine?
- yes
database migrations during deployment?
- ready roll from red gate - in marketplace
- entity framework 
- ssdt
- azure swl deployments - in marketplace
blue / green releasing?
- yes
would a vsts bug tracking system work with single sign on for us?
- yes. And the users don't cost $10 per month.

vsts git, no ip white listing or anything. Can't stop people downloading to personal pcs. Microsft keep all their stuff on that and don't care. One guy in the crowd definitely did care.
compiled artifacts. can be stored in vsts, or if you have a on prem agent can store locally.
vsts is in azure. you can choose which azure region it is in.
audit trail for permissions changes. 
- yes.
There is a "rollback" thing coming, although its not very good. All it is is a build / release stage that runs when there is a problem.

# Deploy to azure (Donovan Brown) @donovanbrown twitter

Microsoft want us to put our stuff in azure.

- IDE
- command line (vsts cli, powershell)
- jenkins
- team foundation server
- vsts
- azure devops projects (inside the azure portal)

and to use vsts

# Demo azure dev ops projects

Abel Wang

create new DevOps Project in azure portal
choose language and framework
choose infrastructure (windows / linux)
Choose instance of vsts (can create a new one at this point)
Creates a team project in vsts
creates a sample project and commits to git
creates ci / cd pipeline for sample code
deploys to azure

clones git repo
deletes everything
copies existing code to repo and commits

# Back to Donovan

It has a yaml definition for the build definition

safe deployment - does canary releasing. There are gates. You can set these up as you want. They look at the azure metrics and suchlike, and you can specify exception limits or whatever. After each gate I guess more users are moved over to the new version.
 - Query work items (bugs)
 - Query metrics
 - call an azure function
 - call a rest api

# Back to Abel

Can deploy to app store

no yaml for the release pipeline yet, but it is coming soon.

vsts command line

# Back to Donovan

Unlimited private repos on vsts

# Back to Abel

vsts has good git pull requests

can do pull requests from a fork

can have pre merge policies, like codecov and whatever.

Has a codeowners equivalent feature

# Back to Donovan

Can get started for free, up to 5 people

has wiki stuff like github

