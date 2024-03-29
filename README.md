The purpose of this device is to allow network/internet access to your garage door using ESP8266, a NO magnetic switch and the HW-655 relay board. A typical garage door opener is trigged by a press on a wall mounted button. This project will emulate this press. It uses  the magnetic switch to check if the garage door is closed.

**Logic**:
* openGarageDoor() { if ( door-is-closed) simulateButtonPress() }
* closeGarageDoor(){ if ( door-is-open) simulateButtonPress() }


# Components
For this project, you will need:


* **ESP8266 (v01)**  - http://amzn.to/2u79UYY or https://goo.gl/feJq7w
* **Magnetic Switch NO**  - http://amzn.to/2HR0zGX or https://goo.gl/St6Zte
* **HW-655** ESP8266 Relay Board  - http://goo.gl/8ZhWXD

# Dependencies

The ESP8266 libraries for Arduino found at https://github.com/esp8266/Arduino. 

# Wiring
On the Relay module, you will need to solder the two ends of the magnetic switch to the GND and GPIO02 ( doesn't matter which to which). The picture shows the connection to the ESP8266 itself, but I found it eaiser to solder to the relay module instead. This way you can place/remove  ESP8266 freely.

![wiring](https://github.com/onada/ESP8266-Garage-Door/blob/master/switch-magnetic-door_bb.png?raw=true)

The ESP8266 plug directly into the Relay module

![HW-655](https://github.com/onada/ESP8266-Garage-Door/blob/master/HW-655.jpg)

# How-to program ESP8266 using Arduino IDE

Here is a tutorial on how to code ESP8266 using Arduino IDE http://www.instructables.com/id/ESP8266-Programming-Using-FTDI-and-Arduino-IDE/

# Actions

* To **Open** the garage door, visit http://the-esp8266-ip-address/open ( ex http://192.168.2.10/open) 
* To **Close** the garage door, visit http://the-esp8266-ip-address/close
* To **Check the door status**, visit http://the-esp8266-ip-address/status( 0=closed, 1=open)

