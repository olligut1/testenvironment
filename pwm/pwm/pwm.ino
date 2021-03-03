#include <Arduino.h>

#define LED_PIN 13

bool MakePulse(int onUs, int offUs);

void setup() 
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() 
{
  int i; // Lichtintensität

  for (i=0;i<100;i++) //1. Sekunde lang erhellen
  {
    if (false == MakePulse(i, 10000))
    {
      Serial.println("Fähler");
      while(1);
    }
  }
  for (i=100;i>0;i--) //1. Sekunde lang erhellen
  {
    MakePulse(i, 1000);
  }
}

bool MakePulse(int relationPercentage, int freq)
{
  long pulsedurationUs;
  int x;
  
  pulsedurationUs = 1000000/freq;
  x = pulsedurationUs / 100;

  if (x <= 0)
  {
    return false;
  }
  
  digitalWrite(LED_BUILTIN, HIGH);
  delayMicroseconds((relationPercentage) * x); 
  digitalWrite(LED_BUILTIN, LOW);   
  delayMicroseconds((100 - relationPercentage) * x); 
  return true;
}
