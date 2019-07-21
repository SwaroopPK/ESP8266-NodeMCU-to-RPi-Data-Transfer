# ESP8266-NodeMCU-to-RPi-Data-Transfer
  This repository tells how wireless data transfer can be done from ESP8266 to RPi. Here ESP8266 acts as a **Publisher**, and RPi as a **Client** or a **Subscriber** and **MQTT** protocol is used to transfer data. 
    
   *Wondering what these Publisher, Subscriber or MQTT means??* Don't worry!! **:)**. Let's look into a brief detail on what MQTT is or how it works.
   
MQTT is one of the most commonly used protocols in IoT projects. It stands for Message Queuing Telemetry Transport.

  In addition, it is designed as a lightweight messaging protocol that uses publish/subscribe operations to exchange data between clients and the server. Furthermore, its small size, low power usage, minimized data packets and ease of implementation make the protocol ideal of the “machine-to-machine” or “Internet of Things” world.

## WHY MQTT??

MQTT has unique features you can hardly find in other protocols, like:

* It’s a lightweight protocol. So, it’s easy to implement in software and fast in data transmission.
* It’s based on a messaging technique. You know how fast your messenger/WhatsApp message delivery is. MQTT protocol is a similar one.
* Minimized data packets. Hence, low network usage.
* Low power usage. As a result, it saves the connected device’s battery.

## How MQTT works
Like any other internet protocol, MQTT is based on clients and a server. The server is the guy who is responsible for handling the client’s requests of receiving or sending data between each other. MQTT server is called a broker and the clients are simply the connected devices.
#### So:

When a device (a client) wants to send data to the broker, we call this operation a *“Publish”* and the device *"Publisher"*.
When a device (a client) wants to receive data from the broker, we call this operation a *“Subscribe”* and this device as *"Subscriber"*.

  
  <p align="center"><img src="https://wso2.com/files/mqtt-article-buddhima.png" height="350" ></p>
  
 ## MQTT Components

* *Broker*, which is the server that handles the data transmission between the clients.
* A *Topic*, which is the place a device want to put or retrieve a message to/from.
* The *Message*, which is the data that a device receives “when subscribing” from a topic or send “when publishing” to a topic.
* *Publish*, is the process a device does to send its message to the broker.
* *Subscribe*, where a device does to retrieve a message from the broker.
  
  
  By now hopefully you would have an idea how a MQTT network will looks or works like. 
  
  
  The common methods used to transfer data are as follows:
  
  * Making use of [test.mosquitto.org](http://test.mosquitto.org/) server as a MQTT broker and sending the data via this server.
  
  * Making use of a common WiFi network to share the data.
  
  * Making one of the ends (i.e either ESP8266 or the RPi) as an *Access Point* and connect the other to it.
  
    The 2nd and the 3rd methods do not use any online brokers. Therefore a broker is to be installed in the RPi. For information on how to install mosquitto broker on your RPi use the link [Getting Started with Mosquitto MQTT Broker on a Raspberry Pi](https://www.youtube.com/watch?v=AsDHEDbyLfg&t=72s).
  
 
