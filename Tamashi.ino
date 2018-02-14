int INF1=12;
int INF2=11;
int MED_INF1=0;
int MED_INF2=0;
int distancia=0;
int tiempo=0;
int ECHO=8;
int TRIGGER=10;
void setup() {
  Serial.begin(9600);
  pinMode(INF1,INPUT);
  pinMode(INF2,INPUT);
  pinMode(ECHO,INPUT);
  pinMode(TRIGGER,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  MED_INF1=digitalRead(INF1);//Atrás
  MED_INF2=digitalRead(INF2);//Adelante
  //Giro
  if(MED_INF1==1 and MED_INF2==1){
    digitalWrite(TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);
    //Medir el tiempo que está en alto
    tiempo=pulseIn(ECHO,HIGH);
    distancia=tiempo/58;
    if(distancia<30){
      //Serial.println(distancia);
      digitalWrite(3,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(9,LOW);
      delay(500);
      digitalWrite(3,HIGH);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(9,HIGH);
      delay(1000);
    }else{
      digitalWrite(3,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(9,HIGH);
    }
  }else if(MED_INF1==0){
    //Delante
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    delay(2000);    
    digitalWrite(3,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(9,LOW);
    delay(2000);
  }else if(MED_INF2==0){
    //Atrás
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    delay(2000);
    digitalWrite(3,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,HIGH);
    delay(2000);
  }
}
