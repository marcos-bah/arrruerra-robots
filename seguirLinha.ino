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
  
  //sensor reflexivo
  int portaAnD = 0; //D
  int portaDigD = 8; //D
  int portaAnE = 1; //E
  int portaDigE = 7; //E

  //motor
  int motor_esquerda_1 = 11; //direcao
  int motor_direita_1 = 10; 
  int motor_esquerda_2 = 12; 
  int motor_direita_2 = 13; 
  
  //variaveis para armazenar valores dos sensores
  long val = 0;
  long val1 = 0;

  //variavel para regular igualdade entre sensores
  int reg = 50;

  //variavel para armazenar a diferença entre sensores
  int diff = 0;

void setup() {

  Serial.begin(9600); //inicializando Serial

  pinMode(portaAnD, OUTPUT); //inicializando portas dos sensores
  pinMode(portaDigD, OUTPUT);
  pinMode(portaAnE, OUTPUT);
  pinMode(portaDigE, OUTPUT);

  //motor
  pinMode(motor_esquerda_1, OUTPUT); //inicializando portas dos motores
  pinMode(motor_direita_2, OUTPUT);
  pinMode(motor_esquerda_1, OUTPUT);
  pinMode(motor_direita_2, OUTPUT);

}

void loop() {

  val = analogRead(portaAnD); //recebendo valores dos sensores analogicos
  val1 = analogRead(portaAnE);

  if (val>val1){ //calculando o diferencial entre elas
    diff = val-val1;
  }else{
    diff = val1-val;
  }

  if (val1 < val and diff > reg) { //verificando se sensor interpreta a linha, considerando erro de igualdade
      motor_1(1);
      stop2();
      Serial.println("Ligando motor 1"); //escrevendo no serial caso os motores não estejam disponiveis
  }else{
    if(val < val1 and diff > reg){
       motor_2(1);
       stop1();
       Serial.println("Ligando motor 2");
    }else{
      motor_1(1);
      motor_2(1);
      Serial.println("Ligando os dois motores");
    }
  }

  Serial.println(val); //escrevendo os valores lidos nos sensores analogicos
  Serial.println(val1);
  delay(1000);
}
//inicio das funcoes
void motor_1(int direcao) //definindo direcao do motor 1
{
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direcao == 1){ //caso seja 1, inverta o sentido
    inPin1 = HIGH;
    inPin2 = LOW;
  }
    digitalWrite(motor_esquerda_1, inPin1);
    digitalWrite(motor_direita_1, inPin2);
}

void stop1(){ //parando motor 1
    digitalWrite(motor_esquerda_1, LOW);
    digitalWrite(motor_direita_1, LOW);
}

void motor_2(int direcao) //definindo direcao do motor 2
{
  boolean inPin10 = LOW;
  boolean inPin20 = HIGH;

  if(direcao == 1){ //caso seja 1, inverta o sentido
    inPin10 = HIGH;
    inPin20 = LOW;
  }
    digitalWrite(motor_esquerda_2, inPin10);
    digitalWrite(motor_direita_2, inPin20);
}

void stop2(){ //parando motor 2
    digitalWrite(motor_esquerda_2, LOW);
    digitalWrite(motor_direita_2, LOW);
}
