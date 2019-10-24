
# Lantern from Hell
This repository contains the code and documentation for making a lantern controlled by a force-resistance sensor using an ESP32 Dev Board and a Raspberry Pi.

## Installation
Clone this repository onto your Raspberry Pi and your local machine. Flash sensor.ino to your ESP32.

### DIY Force-Resistance Sensor
The following are instructions to make your own ***Spooky Pompom Sensor!***
You will need the following materials:
* Cardboard
* One-sided copper conductive tape
* 1/4in thick non-conductive foam
* 2 large pompoms
* 2 male-male jumper cables
* Soldering iron
* Hot glue gun

The steps are as follows:
1. Cut two pieces of tape the desired size of the sensor.
2. Cut two pieces of cardboard the same size as the tape.
3. Stick the tape to the cardboard pieces.
4. Solder one end of each wire to the conductive tape.
5. Glue two small squares of foam on the end of one piece of cardboard on the copper side so that there is a good amount of copper not covered by the foam in the middle.
6. Glue the other cardboard piece onto the foam squares so that the foam pieces are sandwiched between the two copper sides. Make sure you can press the middle the sensor together so that the copper touches.
7. Hot glue one pompom to each side of the sensor so that when you squeeze them together, the copper in the middle touches.
8. You're done!
9. (Optional) Put the sensor in a box with the pompoms sticking out the top to tie things up nicely.

### Circuit
You will need the following materials:
* 3.7V 600 mAh battery (actually not recommended, find a better battery than the one I had)
* ESP32 Dev Board
* Raspberry Pi
* Four LEDs
* Four 10 Ohm Resistors
* Four female-male jumper cables
* Two male-male jumper cables

Arrange your circuit like the picture below:
[INSERT PICTURE]

**Important:** make sure that the GPIO pins you use on your ESP32 for your sensor are ADC1 and not ADC2. ADC2 pins will not work when the ESP32 is using WiFi capabilities. Also, I recommend avoiding using GPIO pins on the Pi that would be used for a screen you would mount on it.

### Enclosure
To make the enclosure, you have some freedom. You can make your lantern however you want, but I used the following materials:
* Two 6-inch squares of black construction paper
* Ten 6-inch flat wooden dowels
* One 3-inch cylindrical wooden dowel
* Four 4x6in pieces of wax paper
* Hot glue gun
* Duct Tape
* Masking Tape
* String

The steps are as follows:
1. Glue 4 of the flat dowels in a square on one piece of black construction paper along the edges of the square. Only glue the ends of the dowels down---not the middles, so there should be a gap between the paper and the dowels. These are your edge dowels.
2. Glue another dowel along the diagonal of the square. 
3. Repeat steps 1 & 2 for the other square.
4. Glue the cylindrical dowel onto the center of one of the diagonal dowels. This is your center dowel. 
5. Glue the other end of the cylindrical dowel to the center of the other diagonal dowel so the corners of the squares line up.
6. Glue one of the wax paper sheets, oriented so that the 6-inch side lines up with the square, on the top of the lantern that 1/2 inch of the sheet folds over onto the top of the lantern.
7. Repeat step 6 for the other three sheets of wax paper.
8. Place your Raspberry Pi and breadboard in the lantern on the bottom square on either side of the center dowel. Make sure the power port for the Pi is facing the edge of the lantern.
9. Thread your string through a hole in the corner of your Raspberry Pi. Tie this string around one of the flat dowels.  Repeat this for the two other holes that are next to edge dowels.
10. Tape the breadboard down onto the dowels with masking tape.
11. Tape the loose ends of the wax paper to the bottom of the lantern, folding half an inch over the corner, with the duct tape. Make sure there is a way for a power cord to get to the micro-USB port on the Pi.
 
 ### Running on boot
 The code in this repo does not run on boot. However, if you are interested in running this on boot on the Pi, which is a good idea for future reproductions, you should follow steps like the ones in [this guide for running Python scripts on boot on the Pi.](https://www.instructables.com/id/Raspberry-Pi-Launch-Python-script-on-startup/ "Run Python on Boot")

## Usage
Connect the ESP32 jumpers to the battery jumpers. This will start the ESP32 and create the WiFi network with SSID "beepbopboopbop" and password "123456789". You are free to change these within sensor.ino, but make sure that the password is 8 or more characters or else the network will not work.

Plug your Pi in. You can either connect your Pi to a screen to connect it to the network or you can follow the steps in the [Pi documentation to ssh in and connect it to the network from the terminal.](https://www.raspberrypi.org/documentation/configuration/wireless/wireless-cli.md "Connect to WiFi via the terminal")

Once you're on the network hosted by the ESP32, you can run wireless.py.

Finally, squeeze away! Whenever you squeeze on the pompoms, the lantern will light up. Happy Halloween! :)
