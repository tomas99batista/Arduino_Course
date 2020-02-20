#define RED_PIN       5
#define GREEN_PIN     4
#define BLUE_PIN      3

#define BUTTON_R_PIN  8
#define BUTTON_G_PIN  7
#define BUTTON_B_PIN  6

#define POT_PIN       A7

#define RGB_RED_PIN   9
#define RGB_GREEN_PIN 10
#define RGB_BLUE_PIN  11


void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  pinMode(BUTTON_R_PIN, INPUT);
  pinMode(BUTTON_G_PIN, INPUT);
  pinMode(BUTTON_B_PIN, INPUT);

  pinMode(POT_PIN, INPUT);

  pinMode(RGB_RED_PIN, OUTPUT);
  pinMode(RGB_GREEN_PIN, OUTPUT);
  pinMode(RGB_BLUE_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop() {  
  int pot = analogRead(POT_PIN);
  Serial.println(pot);
  
  if(pot >= 680) {
    setColor(0,0,255);
    digitalWrite(RED_PIN, 1);
    digitalWrite(GREEN_PIN, 1);
    digitalWrite(BLUE_PIN, 1);
  }
  else if(pot >=340) {
    setColor(0,255,0);
    digitalWrite(RED_PIN, 1);
    digitalWrite(GREEN_PIN, 1);
    digitalWrite(BLUE_PIN, 0);
  }
  else if(pot > 50) {
    setColor(255,0,0);
    digitalWrite(RED_PIN, 1);
    digitalWrite(GREEN_PIN, 0);
    digitalWrite(BLUE_PIN, 0);
  }
  else {
    digitalWrite(GREEN_PIN, 0);
    digitalWrite(BLUE_PIN, 0);
    setColor(255,0,0);
    digitalWrite(RED_PIN, 1);
    delay(500);
    setColor(0,0,0);
    digitalWrite(RED_PIN, 0);
    delay(500);
  }

}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(RGB_RED_PIN, redValue);
  analogWrite(RGB_GREEN_PIN, greenValue);
  analogWrite(RGB_BLUE_PIN, blueValue);
}
