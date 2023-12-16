// EE1000 Multi Mode Baby Soother Group 1

// 4/12/23

 

// Including necessary libraries

#include "SoftwareSerial.h"

#include "DFRobotDFPlayerMini.h"

#include "Adafruit_NeoPixel.h"

 

const int pixelPin = 5;

Adafruit_NeoPixel strip(4, pixelPin, NEO_GRB + NEO_KHZ800);

unsigned long LEDTimestamp = 0;

 

int r = 0;

int g = 0;

int b = 0;

bool rising = true;

 

void pixelColour(int time)

{

  if(rising)

  {

  r = 255 - ((millis())/40)%255;

  g = 0;

  b = (millis()/40)%255;

  if((millis()/40)%255 == 254 && (millis() > LEDTimestamp+1000))

    {

      rising = false;

      LEDTimestamp = millis();

    }

  }

  else

  {

  r = ((millis())/40)%255;

  g = 0;

  b = 255 - (millis()/40)%255;

   

  if((millis()/40)%255 == 254 && (millis() > LEDTimestamp+1000))

    {

      rising = true;

      LEDTimestamp = millis();

 

    }

  }  

  return;

}

 

//create a new software based serial object for the mp3Player (see report)

SoftwareSerial mp3Serial(11,10);

 

//create a variable for storing if the mp3 player is busy

bool mp3state = false;

 

//create an mp3 player object

DFRobotDFPlayerMini mp3Player;

// declare a name for the pin attached to the mp3 player busy pin

const int mp3BusyPin = 4;

 

// declare a name for the pin driving the base of the fan transistor

const int fanPin = 3;

 

// declare a pin name for the pin reading the LDR light detection circuit

const int LDR = A0;

// Declare a pin name for the pin attached to the internal active/inactive LED

const int LED = 2;

// Declare a variable to store the ambient light measurement from the LDR

int ambLight = -1;

 

// Declare a pin name for the pin reading the IR sensor

const int IRSens = A1;

 

// Declare the variables to;

// store the value of the IR sensor read

int strutDetect = -1;

// set wether a pass of a strut past the IR seonsor is occuring

bool recentPass = false;

// save time stamps for when the two most recent strut passings occured

unsigned long stamp1 = -1;

unsigned long stamp2 = -1;

// save calculated difference between the two most recent strut pass events

int timeBetweenPasses = -1;

// save calculated frequency of outer ring strut passing occurences

float frequency = 0;

 

 

void setup() {

 

  strip.begin();

  strip.show(); // Initialize all pixels to 'off'

 

  // begin serial mointor for debugging

  mp3Serial.begin(9600);

  // begin software serial for communicating with mp3 player

  Serial.begin(9600);

 

  // if the mp3 player doesn't initialise print a warning to the serial monitor

  if(!mp3Player.begin(mp3Serial))

  {

    Serial.println(F("Unable to begin:"));

    Serial.println(F("Please recheck"));

  }

  //if it does initialise, print confirmation to the serial monitor

  else

  {

      Serial.println("Player Online");

  }

 

  // set the mp3 volume to max and ask it to start playback of the first file

  mp3Player.volume(15);

  // mp3Player.play(1);

 

  // define the pin modes of the various pins used

  pinMode(mp3BusyPin, INPUT);

  pinMode(fanPin, OUTPUT);

  pinMode(LDR, INPUT);

  pinMode(LED, OUTPUT);

  pinMode(pixelPin, OUTPUT);

  pinMode(IRSens, INPUT);

   // TO DO do we need to declare pinmode for rx and tx

 

}

 

 

void loop() {

 

  // This section reads the LDR and detects if the lights are off

  // a high value means the room is DARK

  ambLight = analogRead(LDR);

  // Serial.println(ambLight);

 

  //switch on condition

  if(ambLight > 300)

  {

    digitalWrite(LED, LOW);

    //This section provides the frequency detection function

  // Read the value from the IR sensor

 

  mp3state = (digitalRead(mp3BusyPin));

 

  if(mp3state == HIGH )

  {

    Serial.println(mp3state);

    delay(1000);

    mp3Player.play(1);

  }

 

  strutDetect = analogRead(IRSens);

 

  // if the value is high, a strut is passing, if the same strut was passing on the previous loop too, recent pass will still be true so it won't execute this code again.

 

  if(strutDetect > 300 && recentPass != true)

  {

    // set to state a strut incident is occuring

    recentPass = true;

    // save the current time stamp

    stamp1 = millis();

    // Serial.print("stamp1 ");

    // Serial.println(stamp1);

    // Serial.print("stamp2 ");

    // Serial.println(stamp2);

  }

 

  // if a pass WAS happening, but now the sensor is reading no strut close by, set back to false

  if(recentPass == true && strutDetect < 300)

  {

    recentPass = false;

  }

 

  // If stamp2 has been used (ie it's not the first loop of the program), and the time stamps are different (ie a recent pass has been detected and stamp1 updated) run this

  if(stamp2 != -1 && stamp1 != stamp2)

  {

    //calculate the time between the time stamps

    timeBetweenPasses = stamp1 - stamp2;

 

    // Serial.print("tbp ");

    // Serial.println(timeBetweenPasses);

   

    // timeBetweenPasses is in ms, calculate the frequency at which the struts are passing currently, in seconds.

    frequency = 1000.0/timeBetweenPasses;

   

    Serial.print(frequency);

    Serial.println("Hz");

   

  }

 

  // After this evaluation above, set stamp2 to the same as stamp1, ready for stamp1 to be the next, later, pass

  stamp2 = stamp1;

 

  // If the above determined the strut frequency is less than 1Hz, engage the fan to propel it round until it is 1.5Hz

  if(frequency < 2 || stamp1 + 3000 < millis())

  {

    digitalWrite(fanPin, HIGH);

  }

  else if(frequency > 4)

  {

    digitalWrite(fanPin, LOW);

  }

  pixelColour(millis());

  strip.setPixelColor(0, r, g, b);

  pixelColour(millis()+850);

  strip.setPixelColor(1, r, g, b);

  pixelColour(millis()+1700);

  strip.setPixelColor(2, r, g, b);

  strip.show();

  strip.setPixelColor(3, r, g, b);

  strip.show();

  // Include the neopixel code here

    //The rest of the program will need to go in here

  }

  else

  {

    digitalWrite(LED, HIGH);

    digitalWrite(fanPin, LOW);

    strip.clear();

    strip.show();

    delay(500);

 

    mp3Player.stop();

 

    mp3state = (digitalRead(mp3BusyPin));

  }

 

 

 

 

 

  delay(10);

}
