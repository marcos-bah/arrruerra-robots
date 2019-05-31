//Programa em desenvolvimento

  /*
    IFSULDEMINAS - Campus Avançado Carmo de Minas
    Criado por: Marcos Barbosa
    Equipe: Marcos Barbosa, Pedro, Murilo Rocha, Julia Almeida.
    Participação na elaboração do Projeto: Juliete Costa, Isabel Bento (Docentes) - Mariana Barcelar, Emannuel (Discentes)
    Obs.:
       #################|Wiki:|##################################################################
       # Direita ou Esquerda simbolizam a direção (Norte ou Sul, sendo o norte o bico do robo). #
       # D ou E significam respectivamente Direita e Esquerda.                                  #
       ##########################################################################################
       #################|Sintaxe:|###############################################################
       # Toda as alterações devem ser ricas em comentarios e manterem a sintaxe e semantica, com#
       # espascamentos e omissao de acentuacoes.                                                #
       ##########################################################################################
  */
  
  /*DECLARACAO DE VARIAVEIS*/
#define MotorA_frente 10
#define MotorA_tras 12
#define MotorB_frente 11
#define MotorB_tras 13
 
#define Sensor_direita 3
#define Sensor_esquerda 2
#define Sensor_LDR A5
#define ledVerde 6
#define ledVermelho 7
 
bool direita, esquerda;
int centro, soma;
float branco, preta;
 
void setup() {
  Serial.begin(9600);
  pinMode(MotorA_tras, OUTPUT);
  pinMode(MotorA_frente, OUTPUT);
  pinMode(MotorB_frente, OUTPUT);
  pinMode(MotorB_tras, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}
 
void loop() {
   //Calibrando
    char dados  = "";
    if(Serial.available () > 0){
      dados = Serial.read();
      if(dados == "b"){
        Serial.println(dados);
        digitalWrite(ledVerde, HIGH);
        delay(2000);
        branco = calibrarBranco();
        Serial.println("Calibrado Linha Branca: ");
        Serial.print(branco);
        Serial.println("");
        digitalWrite(ledVerde, LOW);
      }
      if(dados == "p"){
          digitalWrite(ledVermelho, HIGH);
          delay(2000);
          preta = calibrarPreta();
          Serial.println("Calibrado Linha Preta: ");
          Serial.print(preta);
          Serial.println("");
          digitalWrite(ledVermelho, LOW);
          digitalWrite(ledVerde, HIGH);
      }
    }
  //Define o sentido de rotação dos motores
  digitalWrite(MotorA_tras, LOW);
  digitalWrite(MotorA_frente, HIGH);
  digitalWrite(MotorB_frente, HIGH);
  digitalWrite(MotorB_tras, LOW);
  
  //Leituras dos Sensores
  direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);
  centro = analogRead(Sensor_LDR);

  Serial.print(direita);
  Serial.print(" || ");
  Serial.println(esquerda);

   
  //Rodando os motores dependendo das leituras
 if(direita == false && esquerda == false){
 digitalWrite(MotorA_frente, HIGH);
 digitalWrite(MotorB_frente, HIGH);
 Serial.println("Ligando Todos os Motores.");
 } else if(direita == false && esquerda == true){
 digitalWrite(MotorA_frente, HIGH);
 digitalWrite(MotorB_frente, LOW);
 Serial.println("Ligando motor esquerdo.");
 }else if(direita == true && esquerda == false){
 digitalWrite(MotorA_frente, LOW);
 digitalWrite(MotorB_frente, HIGH);
 delay(250);
 Serial.println("Ligando motor direito.");
 }else if(direita == true && esquerda == true){
 digitalWrite(MotorA_frente, LOW);
 digitalWrite(MotorB_frente, LOW);
 Serial.println("Desligando Todos os Motores.");
 }
}

void viraEsquerda(){
   digitalWrite(MotorA_frente, LOW);
   digitalWrite(MotorB_frente, LOW);

   digitalWrite(MotorB_tras, HIGH);
   digitalWrite(MotorA_tras, HIGH);
   Serial.println("Re");
   delay(100);
   digitalWrite(MotorB_tras, LOW);
   digitalWrite(MotorA_tras, LOW);
   
   delay(200);
   
   digitalWrite(MotorA_frente, HIGH);
   delay(530); //valor aproximado para angulacao de 90*
   Serial.println("Virando");
   digitalWrite(MotorA_frente, LOW);
}

int calibrarBranco(){
  soma = 0;
  for(int i = 0; i<10; i++){
    soma += analogRead(Sensor_LDR);
    delay(100);
  }
  return (soma/5)*1.2;
}

int calibrarPreta(){
  soma = 0;
  for(int i = 0; i<10; i++){
    soma += analogRead(Sensor_LDR);
    delay(100);
  }
  return (soma/5);
}
