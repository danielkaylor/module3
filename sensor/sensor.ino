/**
 * Interfacing Photoresistor using ESP32
 * By TechMartian
 */


//cosntants for the pins where sensors are plugged into.
const int sensorPin = 14;
const int ledPin = 18;
const int diyPin = 2;

//Set up some global variables for the light level an initial value.
int lightInit;  // initial value
int lightVal;   // light reading

//DIY Sensors
int diyVal;


void setup()
{
  Serial.begin(9600);
  // We'll set up the LED pin to be an output.
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  lightInit = analogRead(sensorPin);
  
  //we will take a single reading from the light sensor and store it in the lightCal        //variable. This will give us a prelinary value to compare against in the loop
}


void loop()
{
//  digitalWrite(ledPin, HIGH);
//  Serial.println("PLEASE GOD");
  lightVal = analogRead(sensorPin); // read the current light levels
  diyVal = analogRead(diyPin);
  Serial.println(diyVal);
//  Serial.println(lightVal);

  //if lightVal is less than our initial reading withing a threshold then it is dark.
//  if(lightVal - lightInit <  0)
  if (diyVal == 0)
  {
      digitalWrite (ledPin, HIGH); // turn on light
  }

  //otherwise, it is bright
  else
  {
    digitalWrite (ledPin, LOW); // turn off light
  }

}
