/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

// Load Wi-Fi library
#include <WiFi.h>

// Replace with your network credentials
const char *ssid = "2.4G-Vectra-WiFi-91370A";
const char *password = "ng7vh344w4zh0q17";


// Set web server port number to 80
WiFiServer server(8083);

const int heartPin = 32;
const int iloscProbek = 8000;
const int stopClient = iloscProbek -1;

void setup() {
  disableCore0WDT();
  Serial.begin(115200);
  // Initialize the output variables as outputs

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port

      for(int i = 0; i <iloscProbek; i++){
        int heartValue = analogRead(heartPin);
        client.print(heartValue+1000);
        Serial.println(heartValue);
    
        delay(4); 
        if( i == stopClient){
           client.stop(); 
           Serial.println("Connection closed");
        }
      
   }
  }
}
