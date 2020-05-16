/*
 * Sketch: ESP8266_Lampe_Control
 * Control an UV Lampe from a web browser
 * Intended to be run on an ESP8266
 * 
 * connect to the ESP8266 AP then
 * use web broswer to go to 192.168.4.1
 * 
 */
 
 
#include <ESP8266WiFi.h>
const char WiFiPassword[] = "12345678";
const char AP_NameChar[] = "UVlight" ;
 
WiFiServer server(80);

String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String html_1 = " <!DOCTYPE html> <html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\"><title>UV Lampe Control System</title>";
String html_2 = "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto 35px;text-align: center;}body{margin-top: 50px;} h1";
String html_3 = "{color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}p {font-size: 14px;color: #888;margin-bottom: 10px;}";
String html_4 = ".button {display: block;width: 110px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;";
String html_5 = "text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}";
String html_6 = ".button-on {background-color: #1abc9c;}.button-off {background-color: #34495e;}";
String html_7 = "</style></head><body><h1>UV Lampe Control Systeme</h1><h3>Made by Jawher MANSOUR</h3>";
String html_8 = "<form id='F1' action='LampON'><input class='button button-on' type='submit' value='ON' ></form>";
String html_9 = "<form id='F2' action='LampOFF'><input class='button button-off' type='submit' value='OFF' ></form>";
String html_10="</body></html>" ;

String request = "";

const byte ReBufferON[] = {0xA0, 0x01, 0x01, 0xA2};
//

const byte ReBufferOFF[] = {0xA0, 0x01, 0x00, 0xA1};
//
 
void setup() 
{
    //pinMode(LED_Pin, OUTPUT); 
    Serial.begin(9600);
    boolean conn = WiFi.softAP(AP_NameChar, WiFiPassword);
    server.begin();
 
} // void setup()
 
 
void loop() 
{
 
    // Check if a client has connected
    WiFiClient client = server.available();
    if (!client)  {  return;  }
 
    // Read the first line of the request
    request = client.readStringUntil('\r');
 
    if       ( request.indexOf("LampON") > 0 )  {Serial.write(ReBufferON, sizeof(ReBufferON)); }
    else if  ( request.indexOf("LampOFF") > 0 ) {Serial.write(ReBufferOFF, sizeof(ReBufferOFF));}
 
    client.flush();
 
    client.print( header );
    client.print( html_1 );
    client.print( html_2 );
    client.print( html_3 );
    client.print( html_4);
     client.print( html_5);
      client.print( html_6);
       client.print( html_7);
        client.print( html_8);
         client.print( html_9);
          client.print( html_10);
 
    delay(5);
  // The client will actually be disconnected when the function returns and 'client' object is detroyed
 
} // void loop()


