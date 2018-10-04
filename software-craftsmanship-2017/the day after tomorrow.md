the good thing about idris is that the correctness of the code can be verified in the type system, which the compiler can enforce at compile time.

It's a mathematical / logical type proof.

amd has a formal proof of correctness for the floating point arithmetic for its processors

There are other things aside from idris

liquid / dependent types in haskell
something in f#
isabel
coq


Prooving correctness in the types means we can remove some unit tests, and catch errors at compile time rather than test time.

