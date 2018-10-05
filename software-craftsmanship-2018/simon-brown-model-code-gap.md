# The model-code app

book: Just enough software architecture, george fairbanks

if I draw a model of the architecture, and then programatically create a model from the code, they will look different. This is the model-code gap.

architecture diagrams don't match the code / aren't useful

Uses c4 diagrams, can google

layers and components etc often only exist conceptually

code structure should match architectural intent / diagram.

## package by layer

organise code according to layer its in. eg data layer. Look for violations of layers. eg code in one layer jumping over one layer to speak to another, when it should go through the intermediate layer.

If layers (which we say are vertical), then if they get big want to split horizontally within the layers as well

Often need to change all layers when adding a feature

## package by feaure

groups all code for a feature together, so less to change when adding a feature. Has its own trade offs though.

## ports and adapters

hexagonal, clean architecture etc

## package by component

a bit of functionality behind a ui probably. or an api or something.

a bit like bounded contexts within a monolith, so makes easier to split out in to microservices later.

There is a difference between organisation of code and encapsulation. Make everything as private as possible

If everything is public, all of the architectures above look the same in code / syntatically. His two slides showing this are very powerful. The following slide showing the things you can make private in each type of architecture is also very good.

The surface area of your internal public apis (eg public methods on public classes) should match your architectural intent.

This is better than using tooling to enforce architecture such as fitness functions (from evolutionary architetures book) and suchlike.

Probably should have an architecture diagram for our apps, and then encapsulate to the architecture

Easier to talk about, onboard new staff, architecture refactoring, understanding etc

I have downloaded a couple of his books which might be interesting