// Definição de constantes para facilitar a identificação dos portos
  // LEDs
#define RED_PIN       5
#define GREEN_PIN     4
#define BLUE_PIN      3

  // Botões
#define BUTTON_R_PIN  6
#define BUTTON_G_PIN  7
#define BUTTON_B_PIN  8


// Função setup - é executada uma única vez
void setup() {
  pinMode(BUTTON_R_PIN, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BUTTON_G_PIN, INPUT);
  pinMode(GREEN_PIN, OUTPUT);  
  pinMode(BUTTON_B_PIN, INPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
}


// Função loop - é executada em ciclo infinito
void loop() {
  int bt_red = digitalRead(BUTTON_R_PIN);   // o valor lógico de tensão no porto 8 (BUTTON_R_PIN) é lido para a variável bt_read
  int bt_green = digitalRead(BUTTON_G_PIN);   // o valor lógico de tensão no porto 8 (BUTTON_R_PIN) é lido para a variável bt_read
  int bt_blue = digitalRead(BUTTON_B_PIN);   // o valor lógico de tensão no porto 8 (BUTTON_R_PIN) é lido para a variável bt_read
  // red
  if (bt_red == 1){
    //acender led
  }
  else {
    //apagar
  }
  
  // green
  if (bt_green == 1){
    //acender led
  }
  else {
    //apagar
  }
  
  // blue
  if (bt_blue == 1){
    //acender led
  }
  else {
    //apagar
  }
  /* Continuar o código aqui */
}
