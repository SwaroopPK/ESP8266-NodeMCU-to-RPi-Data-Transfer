import paho.mqtt.client as mqtt

# Don't forget to change the variables for the MQTT broker!
mqtt_username = "Your MQTT_username"
mqtt_password = "Your MQTT_password"
mqtt_topic = "MQTT Topic"
mqtt_broker_ip = "broker_ip" #Usually your RPi IP address

client = mqtt.Client()
# Set the username and password for the MQTT client
client.username_pw_set(mqtt_username, mqtt_password)

def on_connect(client, userdata, flags, rc):
    # rc is the error code returned when connecting to the broker
    print ("Connected!" + str(rc))
    client.subscribe(mqtt_topic)
    
def on_message(client, userdata, msg):
   
    print ("Topic: " + msg.topic + "\nMessage: " + str(msg.payload.decode()))
    

# Here, we are telling the client which functions are to be run
# on connecting, and on receiving a message
client.on_connect = on_connect
client.on_message = on_message


client.connect(mqtt_broker_ip, 1883)

# Once we have told the client to connect, let the client object run itself
client.loop_forever()       #without a loop function code won't work properly
client.disconnect()
