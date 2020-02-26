#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// Leitor RFID
#define SDA_PIN 10
#define SCK_PIN 13
#define MOSI_PIN 11
#define MISO_PIN 12
#define RESET_PIN 9

// Leds
#define RED_LED 4
#define GREEN_LED 5

// Servo
#define SERVO_PIN 3

// Estados
#define SCAN_STATE 0
#define OPEN_STATE 1
#define CLOSED_STATE 2

// Número de cartões na base de dados
#define ID_NUM 2


MFRC522 rfid(SDA_PIN, RESET_PIN);
Servo servo;


String id = "";
String myid[ID_NUM] = {"57366729", "B7D48533"};		// base de dados de cartões


int state = 0;		// variável de estado


void setup() {
  
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);  
	
	// init SPI
  Serial.begin(9600);
  SPI.begin();
	
	// init RFID
  rfid.PCD_Init();
	delay(5);
	
	// init servo
  servo.attach(SERVO_PIN);

	// set servo to 0 deg
  servo.write(0);
  
}

void loop() {

	switch(state) {
		// Estado SCAN_STATE
		case SCAN_STATE:
      	
			// set green led low
      digitalWrite(GREEN_LED, LOW);   // turn the LED on (HIGH is the voltage level)
			
			// set red led high
      digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
	
			// read card id and store in variable 'id'
      id = readCard();
			// search id in myid database
			for(int i=0; i<ID_NUM; i++) {
				if(myid[i].equals(id)) {
					// go to open state
          state = OPEN_STATE;
				}
			}
			break;

		// Estado OPEN_STATE
		case OPEN_STATE:
			// set green led high
      digitalWrite(GREEN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
			
			// set red led low			// ------------> delay(300);
      digitalWrite(RED_LED, LOW);   // turn the LED on (HIGH is the voltage level)
      delay(300);
			
			// set servo to 90 deg
      servo.write(110);
			//for(int i=0; i<90; i++) {
      //        servo.write(i);
              //delay(5);
            //}
			// wait for 5 sec
			for(int i=0; i<5000; i++) {
				delay(1);
			}
      // go to closed state
      state = CLOSED_STATE;
			break;


		// Estado CLOSED_STATE
		case CLOSED_STATE:
			// set servo to 0 deg
      servo.write(0);
//      for(int i=90; i>0; i--) {
  //      servo.write(i);
    //    delay(5);
      //} 
			
			// go to scan state
      state = SCAN_STATE;
			break;
	}

	delay(1);
}


String readCard() {
	String content= "";
	if(rfid.PICC_IsNewCardPresent()) {
		if(rfid.PICC_ReadCardSerial()) {
			for(byte i=0; i<rfid.uid.size; i++) {
				if(rfid.uid.uidByte[i] < 0x10) content.concat(String("0"));
				content.concat(String(rfid.uid.uidByte[i], HEX));
			}
			content.toUpperCase();
		}
	}
	return content;
}
