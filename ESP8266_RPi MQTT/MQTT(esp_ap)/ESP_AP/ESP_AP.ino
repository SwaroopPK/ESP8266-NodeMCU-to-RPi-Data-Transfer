#include <ESP8266WiFi.h>
#include <PubSubClient.h> // Allows us to connect to, and publish to the MQTT broker

#define Pot_Pin A0;

// WiFi
// Make sure to update this for your own WiFi network!
const char* ssid = "ESPAP_APPIKO";
const char* wifi_password = "esp@appiko";

// MQTT
// Make sure to update this for your own MQTT Broker!
const char* mqtt_server = "192.168.43.208";
const char* mqtt_topic = "Voltage";
const char* mqtt_username = "appiko";
const char* mqtt_password = "appiko@123";
// The client id identifies the ESP8266 device. Think of it a bit like a hostname (Or just a name, like Greg).
const char* clientID = "swaroop";


// Initialise the WiFi and MQTT Client objects
WiFiClient wifiClient;
PubSubClient client(mqtt_server, 1883, wifiClient); // 1883 is the listener port for the Broker


void setup()
{
  Serial.begin(115200);
  Serial.println();

  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP(ssid, wifi_password) ? "Ready" : "Failed!");
  
  // Connect to MQTT Broker
  // client.connect returns a boolean value to let us know if the connection was successful.
  // If the connection is failing, make sure you are using the correct MQTT Username and Password (Setup Earlier in the Instructable)
  if (client.connect(clientID, mqtt_username, mqtt_password)) {
    Serial.println("Connected to MQTT Broker!");
  }
  else {
    Serial.println("Connection to MQTT Broker failed...");
  }
}

void loop()
{
  void loop(){
   mqttClient.loop();
  voltage = analogRead(Pot_Pin);
  float V_pot = float(3)*voltage/1023;
  dtostrf(voltage,10,3,c);
  if(mqttClient.publish("Appiko_Data/test", c))
  {
    Serial.println("Publish message success");
  }
  else
  {
    Serial.println("Could not send message :(");
  }
 
  delay(2000);
}
}
