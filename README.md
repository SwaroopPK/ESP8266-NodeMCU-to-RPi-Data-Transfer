# ESP8266-NodeMCU-to-RPi-Data-Transfer
  This repoisitory tells how wireless data transfer can be done from ESP8266 to RPi. Here ESP8266 acts as a **Publisher**, and RPi as a **Client** or a **Subscriber** and **MQTT** protocol is usedd to transfer data. The common methods used to traansfer data are as follows:
  
  * Making use of [test.mosquitto.org](http://test.mosquitto.org/) server as a MQTT broker and sending the data via this server.
  
  * Making use of a common WiFi network to share the data.
  
  * Making one of the ends (i.e either ESP8266 or the RPi) as an *Access Point* and connect the other to it.
  
    The 2nd and the 3rd methods do not use any online brokers. Therefore a broker is to be installed in the RPi. For information on how to install mosquitto broker on your RPi use the link [Getting Started with Mosquitto MQTT Broker on a Raspberry Pi](https://www.youtube.com/watch?v=AsDHEDbyLfg&t=72s).
  
 
