# Code Review Best Practices

We are more critical / think difference reading code compared to writing code.

- gateway reviews (probably pull requests)
- knowledge sharing (might happen after code has gone in to production)
- early design feedback (possibly pairing)

anti patterns
- nit picking (autoformat the code)
- require design changes when the code works (I think this is ok, its a learning / teaching opportunity. Inisting on changing it is probabl wrong though)
- inconsistent feedback
- ghost reviewer (no response from reviewer, probably because its too hard to review)
- ping pong reviews (only bring up problems on the first comment. Don't let someone make some changes and then introduce a new thing)

Developers hate code reviews

## 1. Why: Think about why doing code reviews

Some options
- ensure code meets standards (need to know what the standards are)
- find bugs (this is not why I am doing it)
- share knowledge
- check code is understandable
- collaborate on design
- evolve application code (eg github removing jquery)

## 2. When 

If do it right at the end then can't really require big deisng changes
- during implementation
- before merging
- after merging

## 3. when is review complete
- when everyone agrees
- when a gatekeeper agrees
- when all comments are addressed

## 4. who
- juniors are good. If they can understand it its probably well written

Can I get pull request releases for the ram? and or our apis?

## 5. Where
- show to colleague on a computer (forces reviewer to be nice)
- mob reviewing in a conference room
- remote screen sharing
- async, eg pull requests, check out commit and take a look
- code review software. jet brains thing is free for up to ten people


# conclusions
decide what should be addressed during review
humans should be doing what can be automated
should submit / review small amounts of code
do the review as quickly as possible
checklist of what to look for. This seems like a good idea.
be constructive, specific (giving feedback skills)
prioritise the comments.

