#include "DHT.h"
#include "Servo.h"
  
const int basicServo1WritePin1 = 13;  
const int humidityandTemperatureSensorRHT031ReadPin1 = 6;  
const int tS2ReadPin1 = 10;  
const int infrared850nmLED1WritePin1 = 2;  
const int tS1ReadPin1 = 3;  
const int infrared850nmLED2WritePin1 = 9;  
const int basicServo2WritePin1 = 12;  
const int red633nmLED1WritePin1 = 7;  

void setup() {
  low(26);
  low(27);
  drive_setRampStep(12);
}

void loop() {
  dht22_read(humPin);
  float humidity = dht22_getHumidity();
  humidity = humidity / 10.0;
  float temp = dht22_getTemp(CELSIUS) / 10.0;
  myPrintf(humidity);
  putchar('\n');
  myPrintf(temp);
  putchar('\n');
  if(temp > humThresh) {
        high(ledPin);
      } else {
        low(ledPin);
      }
  freqout(11, 1, 38000);
  irLeft = input(10);
  freqout(1, 1, 38000);
  irRight = input(2);
  if(irRight == 1 && irLeft == 1) {            // No obstacles?
        drive_rampStep(128, 128);                 // ...full speed ahead
      } else if(irLeft == 0 && irRight == 0)        // Left & right obstacles?
        drive_rampStep(-128, -128);               // ...full speed reverse
      else if(irRight == 0)                       // Just right obstacle?
        drive_rampStep(-128, 128);                // ...rotate left
      else if(irLeft == 0)                        // Just left obstacle?
        drive_rampStep(128, -128);
}

void myPrintf(float fVal)
{
    char result[100];
    int dVal, dec, i;

    fVal += 0.005;   // added after a comment from Matt McNabb, see below.

    dVal = fVal;
    dec = (int)(fVal * 100) % 100;

    memset(result, 0, 100);
    result[0] = (dec % 10) + '0';
    result[1] = (dec / 10) + '0';
    result[2] = '.';

    i = 3;
    while (dVal > 0)
    {
        result[i] = (dVal % 10) + '0';
        dVal /= 10;
        i++;
    }

    for (i=strlen(result)-1; i>=0; i--) {
        putc(result[i], stdout);
    }
}

int dht22_getHumidity() {
	// TODO: complete method
}

void drive_setRampStep(int stepsize) {
	// TODO: complete method
}

void low(int pin) {
	// TODO: complete method
}

void freqout(int pin, int msTime, int frequency) {
	// TODO: complete method
}

void drive_rampStep(int left, int right) {
	// TODO: complete method
}

int input(int pin) {
	// TODO: complete method
}

char dht22_read(int dht_pin) {
	// TODO: complete method
}

int dht22_getTemp(char temp_units) {
	// TODO: complete method
}

void high(int pin) {
	// TODO: complete method
}

