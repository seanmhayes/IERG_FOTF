//  Energy sources use rgb leds to show whether they are not available, ready to be used, or being used


// The below block of code is a relic from when the plan was to have rgb leds for wind and grid elec. It can be brought back into play if needs be.

////  Wind
//const int windNoneledPin = 11; // use rgb led in red for this to show states of energy source - none
//const int windReadyledPin = 10; // use rgb led in blue for this to show states of energy source - not in use
//const int windUsedledPin = 9; // use rgb led in green for this to show states of energy source - being used
//
////  Grid
//const int gridNoneledPin = 6; // use rgb led in red for this to show states of energy source - none
//const int gridReadyledPin = 5; // use rgb led in blue for this to show states of energy source - not in use
//const int gridUsedledPin = 3; // use rgb led in green for this to show states of energy source - being used


//  Utility equipment uses red leds, on for on, off for off
const int compressorledPin = 13; // use red led for utility equipment
const int boilerledPin = 12; //// use red led for utility equipment

//  Factory equipment uses green leds, on for on, off for off
const int reactorledPin = 8; // use green led for factory equipment
const int fischerledPin = 7; // use green led for factory equipment

// Wind and grid elec use green leds, on for on, off for off
const int windledPin = 11;
const int gridledPin = 6;

int incomingByte;      // a variable to read incoming serial data into
 
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initializ#e the LED pin as an output:
  pinMode(compressorledPin, OUTPUT);
  pinMode(boilerledPin, OUTPUT);
  pinMode(reactorledPin, OUTPUT);
  pinMode(fischerledPin, OUTPUT);
  pinMode(windledPin, OUTPUT);
  pinMode(gridledPin, OUTPUT);
/* relic to brought into use when wind is displayed with an rgb led
  pinMode(windNoneledPin, OUTPUT);
  pinMode(windReadyledPin, OUTPUT);
  pinMode(windUsedledPin, OUTPUT);
  */
}
 
void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the compressor LED:
    if (incomingByte == 'A') {
      digitalWrite(compressorledPin, HIGH);
    }
    // if it's an L (ASCII 76) turn off the compressor LED:
    if (incomingByte == 'B') {
      digitalWrite(compressorledPin, LOW);
    }
    
    
// turn boiler led on
digitalWrite(boilerledPin, HIGH);
    
/* relic from when boiler was able to be turned on and off from dashboard
    //  if byte = C turn boiler on
    if (incomingByte == 'C') {
      digitalWrite(boilerledPin, HIGH);
    }
    // if byte = D turn boiler off:
    if (incomingByte == 'D') {
      digitalWrite(boilerledPin, LOW);
    }
 */
  
  
 // turn reactor on
digitalWrite(reactorledPin, HIGH);
    
 /* relic from when reactor was able to be turned on and off from dashboard
    // if byte = E turn reactor on
    if (incomingByte == 'E') {
      digitalWrite(reactorledPin, HIGH);
    }
    // if it's an F (ASCII 76) turn off the reactor LED:
    if (incomingByte == 'F') {
      digitalWrite(reactorledPin, LOW);
    }
*/
    
    // if byte = G turn on fischer
    if (incomingByte == 'G') {
      digitalWrite(fischerledPin, HIGH);
    }
    // if it's an H (ASCII 76) turn off the fischer LED:
    if (incomingByte == 'H') {
      digitalWrite(fischerledPin, LOW);
    }
    
    // if byte = I turn on wind
    if (incomingByte == 'I') {
      digitalWrite(windledPin, HIGH);
    }
    // if it's a J turn off wind:
    if (incomingByte == 'J') {
      digitalWrite(windledPin, LOW);
    }
   
    // if byte = L turn on grid
    if (incomingByte == 'L') {
      digitalWrite(gridledPin, HIGH);
    }
    // if it's an M (ASCII 76) turn off the fischer LED:
    if (incomingByte == 'M') {
      digitalWrite(gridledPin, LOW);
    } 
    
    /* relic for grid and wind to be displayed via rgb leds
    
    // if byte = I turn wind red and other wind off
    if (incomingByte == 'I') {
      digitalWrite(windNoneledPin, HIGH);
      digitalWrite(windReadyledPin, LOW);
      digitalWrite(windUsedledPin, LOW);
    }
    
    // if byte = J turn wind blue and other wind off
    if (incomingByte == 'J') {
      digitalWrite(windNoneledPin, LOW);
      digitalWrite(windReadyledPin, HIGH);
      digitalWrite(windUsedledPin, LOW);
    }
    
    // if byte = K turn wind green and other wind off
    if (incomingByte == 'K') {
      digitalWrite(windNoneledPin, LOW);
      digitalWrite(windReadyledPin, LOW);
      digitalWrite(windUsedledPin, HIGH);
    }
    
    // if byte = L turn GRID RED and other GRID off
    if (incomingByte == 'L') {
      digitalWrite(gridNoneledPin, HIGH);
      digitalWrite(gridReadyledPin, LOW);
      digitalWrite(gridUsedledPin, LOW);
    }
    
    // if byte = M turn GRID BLUE and other GRID off
    if (incomingByte == 'M') {
      digitalWrite(gridNoneledPin, LOW);
      digitalWrite(gridReadyledPin, HIGH);
      digitalWrite(gridUsedledPin, LOW);
    }
    
    // if byte = N turn GRID GREEN and other GRID off
    if (incomingByte == 'N') {
      digitalWrite(gridNoneledPin, LOW);
      digitalWrite(gridReadyledPin, LOW);
      digitalWrite(gridUsedledPin, HIGH);
    }
    */
    
  }
}
