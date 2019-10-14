done in java

uses cucumber
uses screen play pattern
uses serenity, which supports screen play pattern. there is also a javascript version

screenpla approach is to model user interface rather than user interface
- I think this is similar to something nat pryce presented, he wrote a translation language for the tests
- I think he also then used the translation langue in the ui and the back end etc

Actors (users) perform tasks. tasks implement performable.

intellij has good syntax highlighting for parameter names

https://serenity-js.org/design/screenplay-pattern.html

the first test takes a while, but subsequent tests are fairly easy, as most of the dsl already exists.

john smart is testing it with an actual database. adds contacts using the ui in some cases, and using the api in other cases. Using the api means that we get an id back, so that we can delete it afterwards (using the api again).

there was no demo about making sure the data was correct at the start of the test, which I think is the way that is best.