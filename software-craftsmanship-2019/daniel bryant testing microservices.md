standing up a full microservice environment is hard, is processor heavy so probably won't be happening locally, and things are changing quickly. Whereas standing up a monolith is usually doable.

testing pyramid is maybe not the thing. test funnel instead. testing in production and suchlike.

https://medium.com/@copyconstruct/testing-microservices-the-sane-way-9bb31d158c16

https://www.continuousdeliveryconsulting.com/blog/end-to-end-testing-considered-harmful/

useful tools for mocking microservices
 mountebank
 karate
 wiremock
 soap ui
 hoverfly
 
localstack can be used to spin up amazon aws stuff locally so you can test. not recommended though.
there is a google one as well

advocates for consumer driven contracts
- can tdd the api
- can run tests when changing the api to see what breaks / make sure it doesn't break
- there is pact, and spring (just java I think)
- they are resource intensive to create and maintain

testcontainers is a good helper for spinning up docker type stuff when testing.

need to test with diverse data, umlauts etc

jailer can take your production data and obfuscate the personal / sensitive stuff but leave the rest, so can test on big / diverse data.

## secutiry 

"bdd security" can be used with owasp's ZAP to do some penetration style testing.

run static analysis on your code

can use "owasp dependency check" to check 3rd party code

want to scan the container you are running on as well really. maybe `Clair` can do this.

we should think more about security