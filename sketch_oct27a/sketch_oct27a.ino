//#include <Keyboard.h>

const int sensorPin = A0;
int lightVal;
int timer;
enum state { REST, PULLING };
state s;



void setup()
{
  Serial.begin(9600);
  s = REST;
  timer = 0;
  lightVal = analogRead(sensorPin);
  //Keyboard.begin();
}


void loop()
{
  //Take a reading using analogRead() on sensor pin and store it in lightVal
  lightVal = analogRead(sensorPin);
  if (s = REST) {
    //blink
    if (lightVal > 2) {
      s = PULLING;
      timer = 0;
      Serial.print("P\n");
    } else {
      Serial.print("R\n");
    }
  }
  if (s = PULLING) {
    //blink
    timer++;
    if (lightVal > 2) {
      //Do stuff here
      Serial.print("P\n");
      //Keyboard.press('a');
      
      timer = 0;
    } else {
      if (timer >= 10000) {
        Serial.print("R\n");
        s = REST;
        timer = 0;
      }
    }
  }
}





//  Serial.print("Value: ");
//  Serial.print(lightVal);
//  Serial.print('\n');
