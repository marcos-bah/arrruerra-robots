  int portaAnD = 0;
  int portaDigD = 8;
  int portaAnE = 1;
  int portaDigE = 7;

  //motor
  int motor_1_gira_esquerda = 11; //direcao
  int motor_1_gira_direita = 10; //direcao
  int motor_2_gira_esquerda = 12; //direcao
  int motor_2_gira_direita = 13; //direcao
  
  long val = 0;
  long val1 = 0;

  int reg = 50;
  int diff = 0;

void setup() {

  Serial.begin(9600);
  pinMode(portaAnD, OUTPUT);
  pinMode(portaDigD, OUTPUT);
  pinMode(portaAnE, OUTPUT);
  pinMode(portaDigE, OUTPUT);

  //motor
  pinMode(motor_1_gira_esquerda, OUTPUT);
  pinMode(motor_1_gira_direita, OUTPUT);
  pinMode(motor_2_gira_esquerda, OUTPUT);
  pinMode(motor_2_gira_direita, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(portaAnD);
  val1 = analogRead(portaAnE);

  if (val>val1){
    diff = val-val1;
  }else{
    diff = val1-val;
  }

  if (val1 < val and diff > reg) {
      motor_1(1);
      stop2();
      Serial.println("Lignado motor 1");
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

  Serial.println(val);
  Serial.println(val1);
  delay(1000);
}

void motor_1(int direcao)
{
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direcao == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }
    digitalWrite(motor_1_gira_esquerda, inPin1);
    digitalWrite(motor_1_gira_direita, inPin2);
}

void stop1(){
    digitalWrite(motor_1_gira_esquerda, LOW);
    digitalWrite(motor_1_gira_direita, LOW);
}

void motor_2(int direcao)
{
  boolean inPin10 = LOW;
  boolean inPin20 = HIGH;

  if(direcao == 1){
    inPin10 = HIGH;
    inPin20 = LOW;
  }
    digitalWrite(motor_2_gira_esquerda, inPin10);
    digitalWrite(motor_2_gira_direita, inPin20);
}

void stop2(){
    digitalWrite(motor_2_gira_esquerda, LOW);
    digitalWrite(motor_2_gira_direita, LOW);
}
