# Wifi Controlled UV Lampe

This project is based on LC Technologyy ESP8266-01 Relay Module to control an UV-C lampe throught a web browser  

![alt text](https://github.com/jawher-Mansour/pics/blob/master/wifirelay2.png)
![alt text](https://github.com/jawher-Mansour/pics/blob/master/Lampe.jpg)


### Description

  LC Technologyy ESP8266-01 Relay Module is ideally suited to controlling larger voltages in your project through WIFI. This is a 1 channel relay module which can be used to activate up to 250V AC and 30V DC. This allows you to build in device control, operating remote lights or triggering systems when the module is supplied with a signal from an ESP8266 module (included).	

  As you may notice throught out the schematics ,This board does not use GPIO0 or GPIO2 of the ESP8266 in order to activate the relay, it use the serial communication instead of it.

![alt text](https://github.com/jawher-Mansour/pics/blob/master/esp8266_schematics.jpg)

 So in order to control the relay , the ESP module must send commands to the STC15F104 microcontroller that will triger the relay , the code handels this process since the ESP will act as an access point and using the following interface (on a web browser) you will be able to controll the Lampe.

![alt text](https://github.com/jawher-Mansour/pics/blob/master/interface.png)

