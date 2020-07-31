# IoT-Linear-Actuator
A linear actuator controlled with google assistant and an Arduino.


# Setup
1) Get an authentication token from blynk
2) ping blynk-cloud.com for their IP address
3) put together the url in the format http:/<ipaddress>/<auth_token>/update/<a_virtual_pin_on_blynk>
4) create 2 web hooks on ifttt.com to get a web requests from the url in step 3
5) On ifttt: Method: PUT; Body: ["0"]; Content: application/json
6) repeat step 5, but with a body of ["1"]. Updating to 0 is sending a "off" signal. updating to 1 is sending an "on" signal. Or you can configure it vice versa
7) yay u done!
