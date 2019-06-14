#include <Ultrasonic.h>

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

#define pino_trigger 9
#define pino_echo 8
 
bool direita, esquerda, dce;
int centro, soma;
float branco, preta;
long cmMsec;

Ultrasonic ultrassom(pino_trigger,pino_echo);
 
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
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);
}
 
void loop() {
  //ultra
  cmMsec = ultrassom.Ranging(CM);
  Serial.println("Distancia em cm: ");
  Serial.println(cmMsec);
  
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
  Serial.print(esquerda);
  Serial.print(" || ");
  Serial.println(centro);

  if(centro>500){
    digitalWrite(ledVerde, HIGH);
    dce = true;
  }else{
    digitalWrite(ledVerde, LOW);
    dce = false;
  }

if(cmMsec>25){
   //Rodando os motores dependendo das leituras
 if(direita == false && esquerda == false && dce == true){ //centro deve estar encima da linha 
     digitalWrite(MotorA_frente, HIGH);
     digitalWrite(MotorB_frente, HIGH);
     Serial.println("Ligando Todos os Motores.");
 }else if(direita == false && esquerda == true && dce == true){ //centro deve estar encima da linha 
     digitalWrite(MotorA_frente, HIGH);
     digitalWrite(MotorB_frente, LOW);
     Serial.println("Ligando motor esquerdo.");
 }else if(direita == true && esquerda == false && dce == true){ //centro deve estar encima da linha 
     digitalWrite(MotorA_frente, LOW);
     digitalWrite(MotorB_frente, HIGH);
     Serial.println("Ligando motor direito.");
 }else if(direita == true && esquerda == true && dce == true){ //centro deve estar encima da linha 
     digitalWrite(MotorA_frente, HIGH);
     digitalWrite(MotorB_frente, HIGH);
     Serial.println("Ligando Todos os Motores.");
 }else if(direita == false && esquerda == false && dce == false){ //arena ou erro
      Serial.println("Arena ou Erro.");
 }else if(direita == false && esquerda == true && dce == true){ //virar 90* not work
      Serial.println("Virar");
 }else if(direita == true && esquerda == false && dce == true){ //virar 90* not work
      Serial.println("Virar");
 }else{
  Serial.println("Cena não esperada ou erro");
 }
}else{
  Serial.println("Desviando de obstaculo");
}

 digitalWrite(MotorB_frente, LOW);
 digitalWrite(MotorA_frente, LOW);
 delay(50);
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
