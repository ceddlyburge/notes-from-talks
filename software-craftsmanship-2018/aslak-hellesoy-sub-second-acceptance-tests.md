# Sub second acceptance tests

book: usability engineering, jakob nielson

based on research
100ms feels instantaneous (no spinners or whatever)
1 sec allows users thought to stay un interrupted, still no spinners
10 secs cant stay focused beyond this

book: flow, mihaly somebody (state of flow, as in pragmattic programmer)

the everything psychology book, kendra cherry also describes flow

Has a test pyramid that has layers for fast, medium and slow, instead of unit, service and ui

full stack test takes about 10 secs

take out selenium and browser and replace with dom actor goins down to 1 second

if using same language for front end and back end can replace api calls with direct method calls, down to 100ms

can replace database with in memory database, down to 10ms

can separate out back ad front end tests to get down to 1ms

They are not as end to end as original, but you can have many more of them. Could still potentially have 1 end to end test to check its all wired up properly. Doesn't check cors headers set up properly on server for example.

You have to write tests in high level business domain language. so instead of "click button x" it will be "launchLoginUi()"
- domain specific commands
- domain specific test views

using electron can run chrome dom in same process as tests

https://github.com/subsecondtdd/codebreaker-js

how hard would this be to do in the RAM? could i make it an early morning project?

ui tests are brittle as well as slow, but we can remove this brittleness using this technique. They will still break, but we will only need to update the dom driver, which should only have one place where each button / text field / whatever is defined, so easy to fix up. Could even tdd the ui changes in this way.
