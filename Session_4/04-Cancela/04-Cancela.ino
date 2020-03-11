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
#define WHITE_LED A0
#define YELLOW_LED A1

// Servo
#define SERVO_PIN 3

// Sensor de bloqueio
#define IR_SENSOR 2

// Sensor de ultrassons
#define TRIG_PIN 8
#define ECHO_PIN 7

// Estados
#define SCAN_STATE 0
#define OPEN_STATE 1
#define CLOSED_STATE 2

// Número de cartões na base de dados
#define ID_NUM 2

// Distância a partir da qual a luz de presença acende
#define MAX_DISTANCE 20


MFRC522 rfid(SDA_PIN, RESET_PIN);
Servo servo;


String id = "";
String myid[ID_NUM] = {"", ""};		// base de dados de cartões


int state = 0;				// variável de estado
bool obstacle_flag = 0;		// flag para indicar se há bloqueio
long duration = 0;			// duração do pulso recebido do sensor de ultrassons
int distance = 0;			// distância entre o objeto e o sensor de ultrassons


void setup() {
	// init SPI
	// init RFID
	delay(5);
	// init servo
	// set servo to 0 deg
	// set pin modes (leds, ir sensor, trig and echo)
}

void loop() {

	switch(state) {
		// Estado SCAN_STATE
		case SCAN_STATE:
			// set green led low
			// set red led high
			// set yellow led low
			// read card id and store in variable 'id'
			// search id in myid database
			for(int i=0; i<ID_NUM; i++) {
				if(myid[i].equals(id)) {
					// go to open state
				}
			}
			// set trig pin low
			// wait 2 us
			// set trig pin high
			// wait 10 us
			// set trig pin low
			// get echo pin high time and store in variable 'duration'
			// calculate distance based on duration
			break;

		// Estado OPEN_STATE
		case OPEN_STATE:
			// set green led high
			// set red led low
			delay(300);
			// set servo to 90 deg
			// set obstacle flag to 0
			// wait for 5 sec
			for(int i=0; i<5000; i++) {
				delay(1);
				// check if the passage is blocked, set obstacle flag to 1 and set yellow led high
			}
			// if obstacle flag is 1 go to open state
			// else if obstacle flag is 0 go to closed state
			break;

		// Estado CLOSED_STATE
		case CLOSED_STATE:
			// set yellow led low
			// set servo to 0 deg
			// go to scan state
			break;
	}
	// if distance less than MAX_DISTANCE turn white led on
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
