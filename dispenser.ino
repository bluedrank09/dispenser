#include <Adafruit_NeoPixel.h>
#include <Servo.h>

#define PIN 6 // neopixel pin
#define NUMPIXELS 24 // number of neopixels
#define COINPIN 9 //coin pin(input)
#define SERVOSIGNAL 11 //servo siganl pin

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Servo servo;

int delayval = 100;
int ctr = 1;
int angle = 10;

uint32_t red = pixels.Color(255, 0, 0);
uint32_t orange = pixels.Color(255, 128, 0);
uint32_t yellow = pixels.Color(255, 255, 0);
uint32_t green = pixels.Color(0, 255, 0);
uint32_t blue = pixels.Color(0, 0, 255);
uint32_t purple = pixels.Color(153,51, 255);
uint32_t pink = pixels.Color(255, 51, 153);


void setup() {

  pixels.begin();

  servo.attach(SERVOSIGNAL);
  servo.write(0);
  Serial.begin(9600);

  pinMode(COINPIN,INPUT);
  pinMode(SERVOSIGNAL, OUTPUT);
  
}

void loop() {

  int circuitState = digitalRead(COINPIN);
  Serial.print("Circuit state is ");
  Serial.println(circuitState);
  delay(1000);
  
  if(circuitState == HIGH){
    
    Serial.print("Circuit state is ");
    Serial.println(circuitState);
    servo.write(180);
    delay(1000);
    servo.write(0); 
    delay(1000);
    circuitState = LOW;
    Serial.print("circuit state is back to low");
    Serial.println(circuitState);
  }

 

  ctr++;
  if(ctr > 7){
    ctr = 1;
  }
  
  switch(ctr){
      case 1: 
        pixels.fill(red, 0, NUMPIXELS);
        break;
      case 2: 
        pixels.fill(orange, 0, NUMPIXELS);
        break;
      case 3: 
        pixels.fill(yellow, 0, NUMPIXELS);
        break;
      case 4: 
        pixels.fill(green, 0, NUMPIXELS);
        break;
      case 5: 
        pixels.fill(blue, 0, NUMPIXELS);
        break;
      case 6: 
        pixels.fill(purple, 0, NUMPIXELS);
        break;
      case 7: 
        pixels.fill(pink, 0, NUMPIXELS);
        break;

  }
  pixels.show();
  delay(500);
}
