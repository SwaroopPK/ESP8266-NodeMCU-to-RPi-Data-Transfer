import paho.mqtt.client as mqtt


def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    client.subscribe("Use your Topic name")

def on_message(client,userdata,msg):
    print("Topic: " + msg.topic + "  " + str(msg.payload))
    message = msg.payload.decode()
    print(message)
    
client = mqtt.Client("Your client name")
client.on_connect = on_connect
client.on_message = on_message

client.connect("test.mosquitto.org",1883,60)
#if this code isn't connecting to the server comment the above "client.connect("test.....")" line and uncomment the below line
#client.connect("85.119.83.194")

client.loop_forever()


