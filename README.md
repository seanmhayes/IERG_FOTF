# IERG_FOTF
IERG Factory of the Future Model

This repository provides a means of controlling an Arduino Uno for the IERG Model through a web browser.

To use it, the following are required:

1. Wampserver: http://www.wampserver.com/en/
2. Processing: https://processing.org/download/
3. Arduino IDE: https://www.arduino.cc/en/Main/Software

Steps to get this repository working:

1. Once Wampserver is running, browse to C:\wamp\www and create a new folder called "website". Paste the contents of [this section](Website_Files) of the respository into "website".
2. Upload [this file](FactoryoftheFuture_Arduino/FactoryoftheFuture_Arduino.ino) to an Arduino Uno.
3. Run [this file](FactoryofTheFuture_Processing/FactoryofTheFuture_Processing.pde) in Processing.
4. Open [http://localhost/website/index.html] in a web browser.
5. Provided LEDs are connected to the relevant pins of the Arduino as outlined in the Arduino sketch, the web page should control the Arduino.
