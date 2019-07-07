import paho.mqtt.client as mqtt


def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    client.subscribe("Appiko/test")

def on_message(client,userdata,msg):
    print("Topic: " + msg.topic + "  " + str(msg.payload))
    message = msg.payload.decode()
    print(message)
    
client = mqtt.Client("RVCE")
client.on_connect = on_connect
client.on_message = on_message

#client.connect("test.mosquitto.org",1883,60)
client.connect("85.119.83.194")

client.loop_forever()

#use sketch_nov22a
