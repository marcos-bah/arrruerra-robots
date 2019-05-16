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
#define MotorA_sentido1 10
#define MotorA_sentido2 12
#define MotorB_sentido1 11
#define MotorB_sentido2 13
 
#define Sensor_direita 3
#define Sensor_esquerda 2
 
bool direita, esquerda;
 
void setup() {
  Serial.begin(9600);
  pinMode(MotorA_sentido1, OUTPUT);
  pinMode(MotorA_sentido2, OUTPUT);
  pinMode(MotorB_sentido1, OUTPUT);
  pinMode(MotorB_sentido2, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);
  
}
 
void loop() {
   //Define o sentido de rotação dos motores
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, HIGH);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, LOW);
  
  //Leituras dos Sensores
  direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);


  //viraDireita();

  
  /*Serial.print(direita);
  Serial.print(" || ");
  Serial.println(esquerda);*/
 
  //Rodando os motores dependendo das leituras
 if(direita == false && esquerda == false){
 digitalWrite(MotorA_sentido2, HIGH);
 digitalWrite(MotorB_sentido1, HIGH);
 Serial.println("Ligando Todos os Motores.");
 } else if(direita == false && esquerda == true){
 digitalWrite(MotorA_sentido2, HIGH);
 digitalWrite(MotorB_sentido1, LOW);
 Serial.println("Ligando motor esquerdo.");
 }else if(direita == true && esquerda == false){
 digitalWrite(MotorA_sentido2, LOW);
 digitalWrite(MotorB_sentido1, HIGH);
 delay(250);
 Serial.println("Ligando motor direito.");
 }else if(direita == true && esquerda == true){
 digitalWrite(MotorA_sentido2, LOW);
 digitalWrite(MotorB_sentido1, LOW);
 Serial.println("Desligando Todos os Motores.");
 }
}

void viraDireita(){
   digitalWrite(MotorA_sentido2, LOW);
   digitalWrite(MotorB_sentido1, LOW);

   digitalWrite(MotorB_sentido2, HIGH);
   digitalWrite(MotorA_sentido1, HIGH);
   Serial.println("Re");
   delay(100);
   digitalWrite(MotorB_sentido2, LOW);
   digitalWrite(MotorA_sentido1, LOW);
   
   delay(200);
   
   digitalWrite(MotorA_sentido2, HIGH);
   delay(530);
   Serial.println("Virando");
   digitalWrite(MotorA_sentido2, LOW);
   delay(2000);
}
