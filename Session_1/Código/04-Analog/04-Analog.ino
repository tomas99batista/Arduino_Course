// Definição de constantes para facilitar a identificação dos portos
  // LEDs
#define RED_PIN       5
#define GREEN_PIN     4
#define BLUE_PIN      3
  // Potenciómetro
#define POT_PIN       A0
  // LED RGB
#define RGB_RED_PIN   9
#define RGB_GREEN_PIN 10
#define RGB_BLUE_PIN  11


// Função setup - é executada uma única vez
void setup() {
  pinMode(RED_PIN, ...);
  pinMode(GREEN_PIN, ...);
  pinMode(BLUE_PIN, ...);

  pinMode(POT_PIN, ...);

  pinMode(RGB_RED_PIN, ...);
  pinMode(RGB_GREEN_PIN, ...);
  pinMode(RGB_BLUE_PIN, ...);
}


// Função loop - é executada em ciclo infinito
void loop() {  
  /* Código */
}


// Função setColor - envia uma cor em formato (R,G,B) para o LED RGB
  /*  
   *   RED:   setColor(255,0,0);
   *   GREEN: setColor(0,255,0);
   *   BLUE:  setColor(0,0,255);
  */
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(RGB_RED_PIN, 255-redValue);
  analogWrite(RGB_GREEN_PIN, 255-greenValue);
  analogWrite(RGB_BLUE_PIN, 255-blueValue);
}
