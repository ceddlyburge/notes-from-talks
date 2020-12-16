## Process automation in cloud native architectures

bernd ruecker

payment gateway example, cope with payment service being down, need to keep state and retry and suchlike. communicates via rest. Usually asynchronous and long running.

So use Workflow engine, like Camunda

move to reactive / event driven example

Easy to separate email notifications to customer from rest of shipping / payment logic

Peer to peer event chains make it hard to see the business process. Have to go an look at the code and work it out, or look at the runtime behaviour. Pinball machine is an anti pattern name for this. Martin fowler has a post about it. Emergent behaviour is another name for this.
https://martinfowler.com/articles/201701-event-driven.html

Event choreography is also a term. This is a hard thing which often goes wrong ...

Bernd says you should model business processes as event driven architectures for this reason. It can be a quick way to get going, but introduces tech debt.

Can be that no team / service is responsible for the overall process, which is bad.

He calls orchestration the command driven style (as opposed to event driven). You can still use queues / messaging or whatever for the command based communication.

SAGA pattern - long lived transactions. Workflow engine can do this. For example if upload a voucher but payment fails, need to ensure the voucher isn't "used".

Clemens Vasters Sagas blog post 2008
https://vasters.com/archive/Sagas.html

Use living documentation, bernd uses BPMN for this.

Mentions 12 factor app

this was a good talk.

## Kubernetes: A Gateway Drug for Vendor Lock-In

Kubernetes does always lock you in to a vendor, no avoiding it. Doesn't necessarily mean you should avoid it though, still might be better than bare vms. Its because k8s is complex to set up, and requires help with security (a vendor) and suchlike.

With serverless you can lock in or not as is best for you.

## Evolving to CloudNative

Shared servers are a bad thing, think we all know this.

Mentions 12 factor app. How far away it is from this is a decent proxy for how easy it will be go to get to the cloud. Can be pragmatic. The more you adhere to, the more cloud native you are and the more benefits you will get from the cloud.

high cohesion, low coupling

graph of evolving ball of mud to modular monolith to microservices is good

Are we retiring an app is not yes / no, but when.

this was a good talk.

## Taming Dependabot: Keeping Microservices Up to Date

Mentions Accelerate book

Use Snyk for security issues.

## Event-Driven Autoscaling on Kubernetes with KEDA and Axure Functions

Kubernetes Event Driven Autoscaling

Azure container instances will take a docker image and run it as a serverless function

dude is a miscrosoft specialised consultant but is working on a mac

Installing Kead on a cluster means you can use a kind: ScaledObject in the k8s yaml

Does scaling with a azure function, which is a bit strange to me. Is the cluster used to run the function? I think it is yes, so its not a serverless thing, azure just runs the docker image, and the docker image polls the azure queue or whatever.

k8s jobs are a way of doing long running tasks. Stops workers getting destroyed / interrupted.

## Designing Loosely Coupled Microservices

Mentions accelerate

run time coupling - have to wait for payment before shipping order

design time coupling - have to deploy things at the same time, lock step changes

Also mentions distributed monolith being the worst of both worlds.

follow mel conway on twitter (of conways law)

Example of an order message with no total, so all apis have to calcualte total themselves, so adding a covidsurchage requires everything to change. Shared library isn't good enough to solve this in microservices (as still have to deploy all apis with new version of the library).

Iceberg priniciple, expose as little as possible, encapsulate as much as possible. Like confluent data on the outside example.

Consume as little as possible (tolerant reader, postels law). Swagger and similar things do the opposite of this, and their client libraries depend on everything.

Avoid sharing database tables. This introduces a design time coupling.

Try and avoid synchronous requests. If doing, use circuit breakers and retries and that.

Can merge two services to avoid synchronous requests / interaction.

Talks about SAGA pattern and choreography. Improves availability as can wait, but increases complexity, and response to client doesn't mean that it has succeeded.

Shift responsibilites and use cqrs, so order service has the data it needs, and doesn't need to talk to customer service. Might be using stale data though, its more complex, potentially confusing. 

Look at patterns of communication when designing microservices. Think about availability and excessive number of hops.

Avoid infrastucture coupling. For example kubernetes has limited capacity, so one service can affect another. Same for database. Might misconfigure k8s and make all services run on it go down. Monzo had a shared cassandra and broke everything when upgrading it. Similar for AWS and Kinesis. Messaging / queues are shared, but if there is a critical service, and a less critical, maybe the critical one has its own queue.

Istio is shared infrastructure, so maybe bad. 

Potentially have multiple swim lanes. Entire deployments of application / service suite. If you break one, there is still another one that is working.

this was a good talk.

http://www.chrisrichardson.net/blog.html

## CI/CD Agility and Controlling Pipeline Sprawl

beef up the build server if useful. It wn't cost much more money, as the jobs finished faster.

run things in parallel

cache things, but do it sensible. If naively cache everything then any change invalidates the cache, which probably means you end up with no cache

Only run things that have need to be run (if code hasn't changed, don't need to build / test it)

don't hardcode commands in pipeline yamls, instead call batch scripts. If have a lot of repos with a lot of pipelines, store shared scripts in one repo, so don't have repeated code in all the repos, and can change pipelines easily in a central place. minimises vendor lock in as well. and adds portability

## Service Mess to Service Mesh

Api gateway - traffic cop at edge of town. Only stops north - south problems (internatl to external). Doesn't stop east west (microservice a talking to database of micrservice b)

can do lots of stuff with mesh
 https / secure
 observe / dashboards
 logic
 circuit breakers
 a / b testing.
 canary releasing I expect
 
linkerd, istio

Linkerd 
 spins up fast
 constributs to rust
 prob have to use 3rd party stuff
 
Istio
 already includes mst good 3rd party stuff
 
Demo, install linkerd on a k8s cluster. Was there something on the cluster already that linkerd connected to, or was linkerd just monitoring itself? It automatically attaches to things based on namespace, but in the demo it was just monitoring itself.

Istio demo. ALready installed, with 3 almost identicaly replicas of a service. Does an a/b type thing with v1 / v2 and star ratings. Then add a thing where jason gets v3. kiali dashboard shows the run time architecture of the system. Observability.

This is tricky to do with vanilla k8s.

https://robrich.org/presentations/

there is a cost to service mesh, roughly double the containers in a cluster. So make sure you need it.

## circleci demo

running things in parralel is good

caching is maybe good maybe bad. Its quite a manual thing, but maybe that makes it more powerful.

having to match names in the workflow to the steps in the yml is bad

vulnerability scan is good

rerun job with ssh is good, can get in there and debug

hold-for-approval is good

## Minimum viable migrations

ben ellerby

serverless is the future. Cost reduction. Less ops. more scalable

often adopting an even driven approach for cloud native. THis statement conflicts with the process automation talk.

release before reaching parity with old system.
 beta version / opt in
 just remove high cost low value features
 need to be able to run two systems in parralel
  dont negatively impact new system with constraints of old system
  also need an exit strategy
  
Use events / share the schema of the events
 legacy system has to be able to emit and respond to events
 on prem / cloud networking issues can be hard
 
will probably have duplicated data
 gdpr harder
 
Bernd Ruecker talked about Process automation on day 1, and talked about some downsides of event driven architectures (mainly that the overall process flow isn't easily visible). Is this a problem you have seen / solved?

## Technologies for Microservices

Eberhard wolff

New / interesting technologies, not just the usual ones (usual ones still good, just not the topic)

Self contained systems. Don't have a back end and a front end microservice, as they are basically coupled, so put buth in the same thing.

Showing info from multiple front end services on one page. Have links to the content on the page, and some javascript to replace the link with the content of the destination of that link. Still works reasonly well even if a service is down, as can see rest of the page, and click on the link later when it is working.

Can do something server side as well (ESI).

Rest can be asynchronous. Could use Atom for async communication. Can use http caching to optimise polling. last-modified, and if-modified-after headers. returns 304 if not modified. Could use your own json instead of atom as well.

Synchronous has issues as well. have to find other services, have to cope if they are down / blocking / slow. 

k8s is good for it. service discovery done with dns. load balancing down via IP. Routing down via Load Balancer or ports. Resilience with service mesh? Can use any language.

Consul as well. service discovery with consul dns and registrator. load balancing done with DNS. Routing with Apache httpd and consul templates. Resilience maybe with hystrix library.

## E Pluribus Unum: Adventures in Polycloud Delivery

Paula Paula

best of breed - integrate multipe saas things
 procurement harder
 security harder
 network harder, sso harder
 

vertically integrated - all microsoft, including for git and devops and teams and sharepoint. Did use Okta and Twilio outside of azure. Used terraform.
 reduces dev ops / provisioning friction
 can increase developer frictions

downdetector.com

think about blast radious of stolen tokens

there are gaps in observability for our saas. twilio uses aws for example.

## Event-Driven Microservices: The Sense, Nonsense and a Way Forward

Allard buijze

shows same graph from previous presentation, about making a monolith modular, and then making it microservices.

There are strong forces trying to stop you making things modular. These forces getting stronger as move to microservices (harder to refactor across multiple services).

Events make things easier, decouples the microservices. But there is that process automation thing again.

Event sourcing: Store all the events (git commits) and recreate state (checkout) as required.

Events invert and obfuscate dependencies. Also talks about finding it hard to follow the overall process, as in bernd's talk.

Should use commands as well as events. And queries.

Recommends event storming, event modelling and ddd

good talk.

## NodeJS, ML, K8s, and Unethical Face Recognition 

joel lord

generally want to use a pretrained ai, at least for the first iteration of your thing

using face-api

monkeyPatch is a node js thing for faking browsers things, like canvas and img and suchlike.

sentiment npm package for sentiment analysis of text

uses rabbitmq

uses amqplib npm package

doesn't use request / reply message thing, instead just has multiple queues.

fun talk, good speaker.

## What an Architect can Learn from Retrospective Failures

need to discuss the problems and not the symptoms

consensus better than democracy, although not always achievable. Could use consent instead, where make sure nobody is mad about it. Dictatorship also a possibility.

do prep for meetings and encourage everyone to. Send an email day before with links and reading and stuff to get people thinking about it. Also send 15 mins before. Insist on video for online meetings.

Asking if the architecture was a car, what car would it be, is a fun question. And similar ones.

Try and make sure everybody contributes equally.

## How Cities Heal: Minneapolis 2021 

As a policy initiative, defunding police departments involves the reallocation of local and state resources away from law enforcement into public services, designed to address issues of poverty, inequality and mental health – factors that contribute to crime.

This talk needs challenging on its position against defund the police.