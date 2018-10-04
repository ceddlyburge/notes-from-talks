He uses ansible to specify the desired state of the server

there is playbook that ansible users. If the thing exists, then ansible just does nothing.

It 
- creates a user account for the app
- create the application directory
- clones the game of life repo
- installs the app dependencies
- sets up nginx to proxy traffic from port 80 to the app
- uses linux supervisor app to run the code, and restart it if it crashes, or if the server restarts etc etc
- updates the dns to point to the blue or the green

This can be run as a nightly job in case somebody changes something

He uses a jenkins job to monitor deployed web apps

although third party things are better if you can use them

also run all tests that don't mutate against the live system as a monitoring system.

he knows how to ship docker images to production, can ask him if I have questions.