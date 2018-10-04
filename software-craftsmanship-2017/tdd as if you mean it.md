Alex Bolboaca

Pure TDD / TDD as if you mean it.

there are constraints on writing the tests, can only remove duplication and name constants and things

use bank kata

Start with an assert(false) test

then assert 2 = 5

then assert 0 + 5 = 5

this has accidental duplication of the 5, there look the same but are different concepts.

then do same with with some named variables

then add some more tests for the same things based on equivalence partitioning

this allows us to remove some duplication by creating a test method that calculates a new balance using an existing balance and a deposit amount.

this test method can then become production code.

next we can make a choice between functional code and object oriented code

Aclass is just a set of cohesive partially applied pure functions.

and we can do property based testing with a relevan framework.

