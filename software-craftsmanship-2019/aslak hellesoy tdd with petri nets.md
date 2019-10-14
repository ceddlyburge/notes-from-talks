event storming is a popular post it type technique

state diagram for tic tac toe is extremely large

petri net diagram for it is vastly simpler

a place is a circle. often a noun (bus), buffer, queue, location, 

places contain 0 or more tokens (state). little dots inside the circle

vertical bar / rectangles are a transition.
- can be enabled or disabled.
- to be enabled must have a place pointing to it with at least one tokens
- transitions presumably move the tokens along
- transition move one token from each of the things pointing at them.

tokens are inside of a place and are moved by the transitions
- one token moves at a time

an arc is a thing that connects a place to a transition, or a transition to a place

reminds aslak of waterfall. but don't have to do it this way

can make living documentation using the model (petri net).

there is a tool that aslak has written that can create an animated gif from the results of a test that is based on a petri net

model at this point allowed two users to be in the xray at once, which is wrong

Adds available and busy place to represent whether xray room is in use. 

Is using Pipe, plattform independent petri net editor

the busy and available thing is a bit wwird, but does work. Some of the tokens represent people, and some represent the busy / available status. but the chart treats them both the same so you have to make it work out

at this point the test in ruby passes but the petri net model validation fails.

recommends living documentation by cyrille from last year

try annd connect modelling tools to your software, so that living documentation can be generated.

the tool that aslak wrote takes input the xml from the petri net model, and from the output of the test. The test must output this file, its a simple dsl created for the purpose.

I could mention living documentation in customertestsexcel. could see if can bring in for any new stuff this year.
