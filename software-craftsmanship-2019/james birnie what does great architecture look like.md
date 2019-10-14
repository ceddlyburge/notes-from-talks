what is architecture
- stuff that is hard to change
- stuff that wants / has a shared understanding

architecture anti patterns

technology police
- need a standard way of doing things, don't do it thay way
- probably don't need to standardise any more
- databases used to be a coupling point for everything, but apis are not
- licencing costs used to be cheaper if you standardise
- cloud solutions make this sort of stuff easier as well

framework designer
- we should all use the framework i made
- treat tech as a value creator instead of cost centre
- be an advisor, not a dictator
- trust you dev teams to use the rught tools and do good stuff. the framework won't help if you don't trust the developers
- mainly due to lack of trust probably
- provide libraries not frameworks to try and keep consistency

the librarian
- most document everything
- risk management theatre is a fun term.
- is documentation best way to communicate

architectology
- enterprise architect, know all enterprise stuff and require people to work within a bad system.
- can come about with a lot of important legacy systems.
- and with lots of knowledge silos


good architecture

use conways law to your advantage
reduce coupling
archiects can work on cross cutting concerns or someting

understand the problem you are trying to solve
understand how to measure success

prefer libraries over frameworks
value business outcomes over systems
value the right tool for the job over uneccesary standardisations
use 12 factor application principles.

be careful with measurements. unintended cosequences

embrace architectural fitness functions (recommends building evolutionary architectures)
- constantly monitor them
- look for trends
- maybe set alerts
- often won't have absolute numbers (but the relative / change in numbers is still useful)

unit tests are fitness functions, can use them
size of commits (related to coupling)
number of releases
performance ones are easy
size of change per releases

accelerate dev ops four key metrics
- lead time
- deployment frequency
- mean time to restore
- change fail percentage

24 key capabilities, in 5 categories
- cd
- architecture
- product and process
- lean management and monitoring
- cultural

identify weakest capability (of 24) and fix it

