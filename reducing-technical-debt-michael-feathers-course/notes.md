# michael feathers refactoring legacy code course 

## day 1

Characterisation testing
First test can just be a regression type test to assert the current behaviour, whatever that may be.

Don't try and test a whole app. Just write enough tests to support the change you are trying to make.

### Scheduler

Sprout method page generator MakeHeader

if adding a feature to an untested class, add new classes and methods and test these, then the original code can delegate out to these. Sprout class and sprout method.

3 levels at which we can mock
- test specific subclass and override method works for a specific method
- Parameterising the constructor works for the class
- Overriding set instance works for the whole system

static methods
- getMeeting
- add a isDateaHoliday *instance* method which calls the static method
- add a new getmeeting method that takes a timeservices
- the old getmeeting method calls this new method passing in the TimeServices
- we can now use the new method in our tests
- could also take TimeServices on the constructor

Synergy between testability and good design

### HomeGuard

CentralUnit.cs
- Feature Envy of sensor class in getSensorMessage
- Data clumping at top of class
- switch statement thing, move to polymorphism

Create a Diagnostics class, intially with public variables for the sensortesting stuff
- then use this class in place of the variables in central unit

Don't have an event in central unit that diagnostics can hook into. Instead introduce a higher level class that both diagnostic and centralunit can hook in to to get updates when a radiobroadcast thing has happened.

Open style of tests repeats a lot of stuff. Closed style removes duplication, but can make it harder to work out what is going on.

Michael asserted both the tripped and non tripped in one helper, which is probably better
Michael was happy repeating "<x>" throughout the code instead of creating a const for it

When creating doorsensor etc michael initially copied the bad getmessage method to each sub class. and ran the tests a lot. Then one at a time he removed the code that wasn't relevant for a particular sub class to be left with the important bit.

Don't target a coverage percentage / have it as a metric. If doing this the tests often aren't any good. Use pareto 80/20. Use tests when you need them or think they will be useful.

passing in "1,tripped" was a simple way of checking that the sensor was tripped. Checking for the exception cases wasn't worth the time of day, as the code has been working in production for some time, so it is probably a case that doesn't happen. We should document it somewhere though, prob in a comment. Our code has implicit contracts in it like this one, which say that you are only allowed to call certain methods with certain values.

You can temporarily add state to big methods / classes to make it easy to add temporary tests. This is bad code and shouldn't be checked in. But it can allow us to test the method, refactor the method with the safety of the test, write new tests for the new code, and then remove the old temporary state and tests.

Temporary tests don't need to be good. You can take liberties in order to refactor code.	

when moving code in to the right class by addressing feature envy, we can often make things private afterwards. This makes the api smaller and increases encapsulation etc.

We don't have to go all the way when refactoring.

In c / proecdural languages, we name functions after what they do, as they actually do things.

In ooo and similar, we name it after the intent / 1 level of abstraction up, as there may be different implementations of it, or we don't care how / what it does

There are greenfield opportunities in every code base. eg sprout class to do most of the work and create it with tdd, then delegate over to the new class from the old stuff.

round dory style of doing dojos good at work.

## dot net user group interlude

### cosmos db

Microsoft NoSql, replacement / superset to documentdb

Can be mongo compaitible, key-value, table store or graph database

Can access it via loads of apis, mongo, table storage, document db, normal sql

Consistency
- Strong (Acid)
- Bounded staleness, can tune the maximum out of dateness you will tolerate
- Session staleness. Updates appear to you in the correct order. They might appear to others in a different order.
- Consistent prefix. Everybody sees everything in the correct order, but they might be out of date.
- Eventual

Can override on a per request basis. eg if a particular query needs up to the date info you can specify that.

Can be multi region, apart from acid / strong consistency

Data will be magically read from the nearest datacenter to the requester

Can download a skeleton app in tons of different languages

### asp.net core 2.0 high performance james singletong

asp.net core 2 is basically the first version. works on .net core (so cross platform) and on .net. 

Its faster

lots of templates for scaffolding applications. reactredux is the one we used. `dotnet new` showed this list I think.

client side app is built in typescript in this case

1
`dotnet publish`, creates a release bundle for any processor / os. doesn't require anything to be installed on the target machine.

copies on to a raspberry pi

this still jit compiles, so is a bit slow

when `dotnet native` is finished, will be able to compile to native code for the target platform and do optimisations, which will make things quicker.

### owasp zap ftw

open web application security project

"Zed Attack Proxy"

In scanner mode, Zap will talk to your web app and analyse the responses for problems

it can also be used in proxy mode to go between the browser and the server

can download it from owasp website

put in url to zap and click attack
 
can launch a browser via zap to do the proxy mode.

it can spider once you have done some clicking

can run zap via docker

### things i missed
- correlator sharp
- libgit2sharp
- 10 debugging tips in ten minutes

Ryder - jetbrains replacement for visual studio

## day 2

### generalisation project

remove duplication by creating a super class
I should have looked harder at the footer etc values to see which ones were different and which ones were the same. This takes a bit of time, but actually I wasted time doing the refactor, so it would have worked out.
I missed the fact that the body values had a null terminator, so I put the last terminator in the footer method, which is misleading.

Mick fowler did the same refactoring as me more or less but in less time, with less keystrokes and without looking panicked. How did he do that.

removing all the duplication, including the instance variables is probably a good thing in this case. It's super easy to maintain (easy to create new commands and hard to create bugs). Interesting. Its a matter of acclimation. As is a lot of things.

### tech debt management

Don't use hard limits for code quality etc (eg don't specify that methods must be less than 15 lines long)

Quntitative measures for technical debt aren't very useful (eg we have 10 million pounds worth of technical debt). This is because some of the code we aren't going to work on ever again, or at least very little, so there is no point making it super clean.

Behavioural economics. In C++ adding a new class is a lot more difficult than adding a new method, so classes get big. Things like this are part of the reason of the entropy in a code base.

Tech debt. The amount of time it takes to modify your code to add the next feature non invasively. This means you can only calculate it with respect to the next feature, and not across an entire code base.

### Design decision cards. 
Maintain cards for each of the design decisions you make. periodically reestimate to consider feasibility. Eg support Mac's. It will generally get worse over time, and you can notice this and do something about it. eg how easy would it be to move to a different persistent mechanism. How hard to remove csla. How hard to move away from code gen. How hard to use python calculations in economic. Think about O(1) or O(n).

### Feature trend cards. 
Hypothesize a couple of features that you will never add to your code. Task them and estimate them periodically. See the debt trend for the areas they touch.

Can use other metaphors than technical debt, such as the aeroplance service metaphor.

https://www.infoq.com/podcasts/tesla-colin-breck

### Scratch refactoring

Do it together. Don't check it in. No need for tests. Can help to understand the code.

Do it in a text editor so we don't get distracted by compile errors etc

Just to understand what is going on.

It is good for this, much better than just reading the code and trying to work it out.

### Suggestive refactorings.
put small refactorings and put them on the backlog. Gets people in the habit. But can mean that people only do the refactoring on the backlog.

### Splt prep-refactorings
Highlight refactoring within a team by making it a separate task done by different people. The handoff forces discussion.
The refactor should allow the new feature to be added without modifying code. Or at least only a tiny bit.

### Priveleged Abstractions
Select the abstractions that you consider primary in the system and document them. Have conversations around them.

market assumptions, project assumptions, calculations (also assumptions)

### Limited WIP Refactoring

Never have more than 1 or 2 large scale refactoring in progress at one. This forces focus and emphasizes completion.

### Architectural mapping

Draw your code base as a tolkein map. write "here be dragons" in the relevant places. Have a common team vision of where the best coe resides.

### Silent alarms

Don't fail the build. let people make mistakes, investigate them afterwards and then intervene. One company had a very strict build and it caused quality to go down. This is because it was so hard to get commits through all the gates, that developers did less refactoring. And the feedback cycle was very long

### Scrape the pan

If you have singletons / global mutable state, you can remove them and pass them through everywhere, but it can be difficult. You can just give up and instead combine all the global mutable state in a single object which is easier to reason about / handle.

### Direction tagging

Create tags / comments that need work. Tackle them in a limitied WIP type way. Tag the specific refactoring, rather than just that it needs refactoring in general.

### Transparent design quality.

SHow a diagram of the class / code etc to management, so that they understand the state of the code.

Managers basically have a duty to be aware of the quality of the code.

colin breck talk mentions this. Maybe show this to the management team.

### Synergy between testability and good design
good design is easy to test

but easy to test code is not necessarily well designed.

- Want to access a local variable during test: method too long, violation of srp
- Difficult to set up, eg have to instantiate 12 things to test a class: Too much coupling
- Resource leaking
- State leaks across tests: global mutable state problem
- Hard to write tests in presence of a framework: Not enough domain separation
- Difficult mocking.  Writing mocks for objects returned by other objects: law of demeter violations
- Hidden effects / Indirect output. not enough separation of concerns. srp violation.
- Hidden inputs / Indirect input. eg date time stuff that is dependent on when the test is run.
- Large parameter lists: method too long / too many responsibilities
- Insufficient access / wanting to test a private method: srp violation, refactor out the responsibility and then test that.
- Test thrash, many unit tests change when you change the code: Code not localised encapsulated well enough.

Why? Because tests are basically a user of the software / code. Tests are a program to test / understand another program. If it is difficult for the tests to understand the program, it is probably difficult for us as well.

### tdd

null object pattern represents the absence of something. Works better for objects that are more behavioural than representational.

In OO telling another class / object what to do is better thank asking it something.

Mike takes longer steps later on in the process.

He creates some classes / does some refactorings, without adding any tests.

When creating the total test, this then basically wants the price to be an integer instead of a string. He then starts writing tests for the item class. Starts off with a test that passes. Then add constructor which takes an int instead of a string.

Inventory class that got pushed out contained the setup inside it, instead of that being inside the test.
Mike wants to tdd the core domain logic. Not worried about the cruft round the edge like ui, databases and suchlike.
