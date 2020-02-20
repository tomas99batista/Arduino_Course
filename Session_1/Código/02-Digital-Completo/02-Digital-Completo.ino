#define RED_PIN       5
#define GREEN_PIN     4
#define BLUE_PIN      3

#define BUTTON_R_PIN  8
#define BUTTON_G_PIN  7
#define BUTTON_B_PIN  6


void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  pinMode(BUTTON_R_PIN, INPUT);
  pinMode(BUTTON_G_PIN, INPUT);
  pinMode(BUTTON_B_PIN, INPUT);

}

void loop() {
  int bt_red = digitalRead(BUTTON_R_PIN);
  int bt_green = digitalRead(BUTTON_G_PIN);
  int bt_blue = digitalRead(BUTTON_B_PIN);

  if(bt_red == 1) {
    digitalWrite(RED_PIN,1);
  }
  else {
    digitalWrite(RED_PIN,0);
  }
  
  if(bt_green == 1) {
    digitalWrite(GREEN_PIN,1);
  }
  else {
    digitalWrite(GREEN_PIN,0);
  }
  
  if(bt_blue == 1) {
    digitalWrite(BLUE_PIN,1);
  }
  else {
    digitalWrite(BLUE_PIN,0);
  }
}
