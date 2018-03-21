# Components
For this project, you will need:


* **ESP8266 (v01)**  - http://amzn.to/2u79UYY or https://goo.gl/feJq7w
* **Magnetic Switch**  - http://amzn.to/2HR0zGX or https://goo.gl/St6Zte
* **HW-655** ESP8266 Relay Board  - http://goo.gl/8ZhWXD

# Dependencies

This projects make use of the ESP8266 libraries for Arduino found as https://github.com/esp8266/Arduino. 

# Wiring
On the Relay module, you will need to solder the two ends of the magnetic switch to the GND and GPIO02 ( doesn't matter which to which). The picture shows the connection to the ESP8266 itself, but I found it eaiser to solder to the relay module instead. This way you can place/remove  ESP8266 freely.

![wiring](https://github.com/onada/ESP8266-Garage-Door/blob/master/switch-magnetic-door_bb.png?raw=true)

The ESP8266 plug directly into the Relay module

![HW-655](https://github.com/onada/ESP8266-Garage-Door/blob/master/bbbb.jpg)

# How-to program ESP8266 using Arduino IDE

Here is a tutorial on how to code ESP8266 using Arduino IDE http://www.instructables.com/id/ESP8266-Programming-Using-FTDI-and-Arduino-IDE/

