//motor 1
int enA = 9;
int in1 = 7;
int in2 = 6;
//motor 2
int enB = 3;
int in3 = 5;
int in4 = 4;
//US up
int Trig1 = 8;
int Echo1 = 2;
//US left
int Trig2 = 11;
int Echo2 = 10;

void Stop (){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA,0);
  analogWrite(enB,0);
}

void fwd (int speed1, int speed2){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA,speed1);
  analogWrite(enB,speed2);
  }

void bwd (int speed1, int speed2){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA,speed1);
  analogWrite(enB,speed2);
  }  

void turn_R (int speed1, int speed2){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA,speed1);
  analogWrite(enB,speed2);
  }  

int USensor (int Trig, int Echo){
  digitalWrite(Trig, HIGH); 
  /* Подаем импульс на вход trig дальномера */
  delayMicroseconds(10); // равный 10 микросекундам 
  digitalWrite(Trig, LOW); // Отключаем  
  return (pulseIn(Echo, HIGH)/58); // Выводим на порт   
}

void setup() {
  Serial.begin(9600);
  pinMode(Trig1, OUTPUT); //инициируем как выход 
  pinMode(Echo1, INPUT); //инициируем как вход 

  pinMode(Trig2, OUTPUT); //инициируем как выход 
  pinMode(Echo2, INPUT); //инициируем как вход   

  for (int i = 3; i < 10; i++){
    pinMode(i, OUTPUT);
    }
}

void loop() {

 // Serial.println(USensor(Trig2,Echo2));
if(USensor(Trig2,Echo2)<10){
  turn_R(120,120);
  }else{
   if(USensor(Trig1,Echo1)<12){
             fwd(150,150);
             delay(700);
             bwd(150,150);
             delay(700);
             Stop();
         } else {
              Stop();
                 }
  }

  delay(1);
}
