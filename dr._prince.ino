#include <IRremote.h>  //including infrared remote header file   
#include <EEPROM.h>  
int RECV_PIN = 2; // the pin where you connect the output pin of IR sensor
bool semaphor1 = false;
bool semaphor2 = false;
bool semaphor3 = false;    
IRrecv irrecv(RECV_PIN);     
decode_results results;     
void setup()     
{     
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);     
irrecv.enableIRIn();     
}     
void loop(){     
if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.     
{     
// int results.value = results;// Results of decoding are stored in result.value     
 Serial.println(" ");     
 Serial.print("Code: ");     
 Serial.println(results.value); //prints the value a a button press     
 Serial.println(" ");     
 irrecv.resume(); // Restart the ISR state machine and Receive the next value   
 if(results.value == 16740495 || EEPROM.read(memory_location)== '1'){
  if(semaphor1 == false){
    Serial.println(" one on ");
    digitalWrite(9, HIGH);
    semaphor1 = true;
    EEPROM.write(memory_location, '1');
  }
  else{
    digitalWrite(9, LOW);
    Serial.println(" one off ");
    semaphor1 = false;
  }
 }

 if(results.value == 16769055 || EEPROM.read(memory_location)== '2'){
  if(semaphor2 == false){
    digitalWrite(10, HIGH);
    Serial.println(" two on ");
    semaphor2 = true;
    EEPROM.write(memory_location, '2');
  }
  else{
    digitalWrite(10, LOW);
    Serial.println(" two off ");
    semaphor2 = false;
  }
 }


 if(results.value == 16734375 || EEPROM.read(memory_location)== '3')){
  if(semaphor3 == false){
    digitalWrite(11, HIGH);
    Serial.println(" three on ");
    semaphor3 = true;
    EEPROM.write(memory_location, '3');
  }
  else{
    digitalWrite(11, LOW);
    Serial.println(" three off ");
    semaphor3 = false;
  }
 }
}
}     
