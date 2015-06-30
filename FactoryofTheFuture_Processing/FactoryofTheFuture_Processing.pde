/*
 
A simple Processing script for enabling or disabling the LED on an Arduino using a web interface and serial communication.
Author: Sindre Lindstad
Created: 19th of January 2011
 
http://projects.sindrelindstad.com
 
*/
 
 import processing.serial.*;
 Serial port;
 
 void setup()  {
 
   /* This part must be altered to fit your local settings. The number in brackets after "Serial.list()" is where you declare what COM port your Arduino is connected to.
      If you get error messages, try a different number starting from 0 (e.g. 0, 1, 2, 3...) . */
    println(Serial.list());
    port = new Serial(this, Serial.list()[0], 9600);  // Open the port that the Arduino board is connected to, at 9600 baud
 
}
 void draw() {
 
   
   //load info about compressor state
  String comp_onoroff[] = loadStrings("http://localhost/website/compressorLEDstate.txt"); // Insert the location of your .txt file
  print(comp_onoroff[0]);  // Prints whatever is in the file ("1" or "0")
 
  if (comp_onoroff[0].equals("1") == true) {
    println(" - TELLING ARDUINO TO TURN COMPRESSOR LED ON");
    port.write('A'); // Send "H" over serial to set LED to HIGH
 
  } else {
 
    println(" - TELLING ARDUINO TO TURN COMPRESSOR LED OFF");
    port.write('B');  // Send "L" over serial to set LED to LOW
 }
 
 delay(100); // Set your desired interval here, in milliseconds
 
  //load info about BOILER state
  String boiler_onoroff[] = loadStrings("http://localhost/website/boilerLEDstate.txt"); // Insert the location of your .txt file
  print(boiler_onoroff[0]);  // Prints whatever is in the file ("1" or "0")
 
  if (boiler_onoroff[0].equals("1") == true) {
    println(" - TELLING ARDUINO TO TURN BOILER LED ON");
    port.write('C'); // Send "H" over serial to set LED to HIGH
 
  } else {
 
    println(" - TELLING ARDUINO TO TURN BOILER LED OFF");
    port.write('D');  // Send "L" over serial to set LED to LOW
 }
 
 delay(100); // Set your desired interval here, in milliseconds
 
  //load info about REACTOR state
  String reactor_onoroff[] = loadStrings("http://localhost/website/reactorLEDstate.txt"); // Insert the location of your .txt file
  print(reactor_onoroff[0]);  // Prints whatever is in the file ("1" or "0")
 
  if (reactor_onoroff[0].equals("1") == true) {
    println(" - TELLING ARDUINO TO TURN REACTOR LED ON");
    port.write('E'); // Send "H" over serial to set LED to HIGH
 
  } else {
 
    println(" - TELLING ARDUINO TO TURN REACTOR LED OFF");
    port.write('F');  // Send "L" over serial to set LED to LOW
 }
 
 delay(100); // Set your desired interval here, in milliseconds
 
  //load info about FISCHER state
  String fischer_onoroff[] = loadStrings("http://localhost/website/fischerLEDstate.txt"); // Insert the location of your .txt file
  print(fischer_onoroff[0]);  // Prints whatever is in the file ("1" or "0")
 
  if (fischer_onoroff[0].equals("1") == true) {
    println(" - TELLING ARDUINO TO TURN FISCHER LED ON");
    port.write('G'); // Send "H" over serial to set LED to HIGH
 
  } else {
 
    println(" - TELLING ARDUINO TO TURN FISCHER LED OFF");
    port.write('H');  // Send "L" over serial to set LED to LOW
 }
 
 
  delay(100); // Set your desired interval here, in milliseconds
  
  //load info about WIND state
  String wind_state[] = loadStrings("http://localhost/website/windLEDstate.txt"); // Insert the location of your .txt file
  print(wind_state[0]);  // Prints whatever is in the file ("1" or "0" or "2")
 
  if (wind_state[0].equals("0") == true) {
    println(" - TELLING ARDUINO TO TURN WIND LED RED");
    port.write('I'); // Send "I" over serial to set RED WIND LED to HIGH
 
  } else if (wind_state[0].equals("1") == true){
    println(" - TELLING ARDUINO TO TURN WIND LED BLUE");
    port.write('J'); // Send "J" over serial to set BLUE WIND LED to HIGH
  }
  else{ 
    println(" - TELLING ARDUINO TO TURN WIND LED GREEN");
    port.write('K');  // Send "K" over serial to set GREEN WIND LED to HIGH
 }
 
 delay(100); // Set your desired interval here, in milliseconds
  
  //load info about GRID state
  String grid_state[] = loadStrings("http://localhost/website/gridLEDstate.txt"); // Insert the location of your .txt file
  print(grid_state[0]);  // Prints whatever is in the file ("1" or "0" or "2")
 
  if (grid_state[0].equals("0") == true) {
    println(" - TELLING ARDUINO TO TURN GRID LED RED");
    port.write('L'); // Send "L" over serial to set RED GRID LED to HIGH
 
  } else if (grid_state[0].equals("1") == true){
    println(" - TELLING ARDUINO TO TURN GRID LED BLUE");
    port.write('M'); // Send "M" over serial to set BLUE GRID LED to HIGH
  }
  else{ 
    println(" - TELLING ARDUINO TO TURN GRID LED GREEN");
    port.write('N');  // Send "N" over serial to set GREEN GRID LED to HIGH
 }
 
 
  delay(100); // Set your desired interval here, in milliseconds
  
  
  
  
 }
