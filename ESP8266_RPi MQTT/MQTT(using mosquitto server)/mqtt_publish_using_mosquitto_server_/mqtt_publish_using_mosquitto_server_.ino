#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define Pin A0
const char* ssid     = "SSID";
const char* password = "WiFi Password";
char c[10];

const char* server = "test.mosquitto.org";
//If the code doesn't connect to the server comment the above line and uncomment the below line

//const char* server = "85.119.83.194";

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
  pinMode(Pin,INPUT);
  Serial.begin(115200);
  delay(100);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  mqttClient.setServer(server,1883);
   

   if (mqttClient.connect("Your Client ID")) 
  {
    Serial.println("Connection has been established, well done");
 
    // Establish the subscribe event
   // mqttClient.setCallback(subscribeReceive);
  } 
  else 
  {
    Serial.println("Looks like the server connection failed...");
  }
  
}

void loop(){
   mqttClient.loop();
  float voltage = analogRead(Pin);
  float V_pot = float(3-0)*voltage/1023;
  dtostrf(V_pot,4,3,c);
  if(mqttClient.publish("Your Topic", c))
  {
    Serial.println("Publish message success");
  }
  else
  {
    Serial.println("Could not send message :(");
  }
  delay(2000);
}
  
