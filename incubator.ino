// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>
float temp;
int relay = 8;
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

/*
 * The setup function. We only start the sensors here
 */
void setup(void)
{
  // start serial port
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
//  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
//  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
//  Serial.println("DONE");
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
//  Serial.print("Temperature for the device 1 (index 0) is: ");
//  Serial.println(sensors.getTempCByIndex(0));  
  temp=sensors.getTempCByIndex(0);

  
    if (temp<38.00){
      digitalWrite(relay, HIGH);
      Serial.println("temp is below 38");
    }
    else if (temp>38.00){
      if(temp<38.50){
        digitalWrite(relay, HIGH);
      Serial.println("temp is below 38");
      }
      else{
      digitalWrite(relay,LOW);
      Serial.print("temp is above 38");
      }
      delay(10000);
  }
        delay(5000);
}