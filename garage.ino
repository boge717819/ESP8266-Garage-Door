#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "........";
const char* password = "........";

int garage_status = 0;

ESP8266WebServer server ( 80 );
HTTPClient http;

/* ===================================================================== */

void setup ( void ) {

  // 9600 speed is needed for HW-655 to work
  Serial.begin(9600);
  pinMode(  2 , INPUT_PULLUP);

  WiFi.mode ( WIFI_STA );
  WiFi.begin ( ssid, password );
  Serial.println ( "" );

  // Wait for connection
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 1000 );
    Serial.print ( "." );
  }

  Serial.println ( "" );
  Serial.print ( "Connected to " );
  Serial.println ( ssid );
  Serial.print ( "IP address: " );
  Serial.println ( WiFi.localIP() );

  server.on("/", handleRoot);
  server.on("/status", handleStatus);
  server.on("/pushButton", handlePushButton);
  server.on("/open", handleOpen);
  server.on("/close", handleClose);
  server.onNotFound(handleNotFound);
  server.begin();

  Serial.println ( "HTTP server started" );
}

/* ===================================================================== */

void loop ( void ) {

  server.handleClient();
  readSwitch();
  delay(100);

}


/*===================================================================
                          ACTIONS
  ===================================================================*/

void updateRemoteGarageStatus() {

  // send the new status of the door to your server
  Serial.println ( "updateGarageStatus" );
  if (garage_status == 1) {
    http.begin("http://IP-ADDRESS/file.php?value=1");
  } else {
    http.begin("http://IP-ADDRESS/file.php?value=0");
  }
  int httpCode = http.GET();
  http.end();
}


void pressGarageButton() {

  // special code for the HW-655 to trigger the Relay On then Off to simulate the user press on the garage door opener on the wall
  Serial.write("\xa0\x01\x01\xa2"); // CLOSE RELAY
  delay(700);
  Serial.write("\xa0\x01"); // OPEN RELAY
  Serial.write(0x00); // null terminates a string so it has to be sent on its own
  Serial.write(0xa1);
}

/*===================================================================
                          STATUS
  ===================================================================*/

void readSwitch() {
  int state = digitalRead(2);
  if ( state != garage_status) {
    garage_status = state;
    updateRemoteGarageStatus();
    delay(50);
  }
}

/*===================================================================
                          SERVER URLs
  ===================================================================*/

void handleRoot() {
  server.send(200, "text/plain", "Hello, the Garage Door gateway is ready");
}

void handleNotFound() {
  server.send(404, "text/plain", "404");
}

void handleStatus() {
  if (garage_status == 1)
    server.send ( 200, "text/plain", "1" );
  else
    server.send ( 200, "text/plain", "0" );
}

void handlePushButton() {
  pressGarageButton();
  server.send ( 200, "text/plain", "1" );
}

void handleOpen() {
  // only open the door if it was closed
  if (garage_status == 0) pressGarageButton();
  server.send ( 200, "text/plain", "1" );
}

void handleClose() {
  // only close the door if it is open
  if (garage_status == 1) pressGarageButton();
  server.send ( 200, "text/plain", "1" );
}




