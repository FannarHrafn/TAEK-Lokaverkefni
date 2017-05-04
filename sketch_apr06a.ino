#include <Servo.h> //using the servo library
const int TrigPin = 3;
const int EchoPin = 4;
float cm;
Servo myservo; // create an servo object
int styripinni = A0;
int takki = 2; 
int styripinniValue = 0;
int teljari = 0;
int takki_stada = 1;
int ljos = 6;

void setup() {
  Serial.begin(9600);
  myservo.attach(9); 
  pinMode(takki,INPUT_PULLUP); 
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
}

void loop() {
  //athuga hvort var ýtt á takka
  takki_stada = digitalRead(takki);
  if(takki_stada == 0){
      teljari=teljari+1;
      delay(200);
      Serial.print(teljari);
  }
  //wf teljari er 0 þá snýst servo sjálfkrafa
  if(teljari==0){
      for(int i = 180; i >= 0; i--){
        //notum break ef ýtt er á takka til að sleppa úr for lykkju strax
      takki_stada = digitalRead(takki);
      if(takki_stada == 0){
          teljari=teljari+1;
          delay(200);
          Serial.print(teljari);
          break;
        }
        //athugum hvort við finnum eitthvað innan 20 cm
      myservo.write(i);
      digitalWrite(TrigPin,LOW);
      delayMicroseconds(2);
      digitalWrite(TrigPin,HIGH);
      delayMicroseconds(10);
      digitalWrite(TrigPin,LOW);
      cm = pulseIn(EchoPin,HIGH)/58.0;  
      cm = (int(cm * 100.0))/100.0;
      if(cm < 0)
      {
        cm = 0;
      }
      if(cm<21){
      digitalWrite(ljos,HIGH);
      while(cm<21){
          digitalWrite(TrigPin,LOW);
          delayMicroseconds(2);
          digitalWrite(TrigPin,HIGH);
          delayMicroseconds(10);
          digitalWrite(TrigPin,LOW);
          cm = pulseIn(EchoPin,HIGH)/58.0;  
          cm = (int(cm * 100.0))/100.0;
          if(cm < 0)
          {
             cm = 0;
           }
            
          }
        }
      else{
        digitalWrite(ljos,LOW);
        }
        delay(15);
      }
  }
   if (teljari==0){
      for(int i = 0; i <= 180; i++){
        //notum break ef ýtt er á takka til að sleppa úr for lykkju strax
      takki_stada = digitalRead(takki);
      if(takki_stada == 0){
          teljari=teljari+1;
          delay(200);
          Serial.print(teljari);
          break;
        }
        //athugum hvort við finnum eitthvað innan 20 cm
        myservo.write(i);
        digitalWrite(TrigPin,LOW);
        delayMicroseconds(2);
        digitalWrite(TrigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(TrigPin,LOW);
        cm = pulseIn(EchoPin,HIGH)/58.0;  
        cm = (int(cm * 100.0))/100.0;
        if(cm < 0)
        {
          cm = 0;
        }
        if(cm<21){
        digitalWrite(ljos,HIGH);
        while(cm<21){
          digitalWrite(TrigPin,LOW);
          delayMicroseconds(2);
          digitalWrite(TrigPin,HIGH);
          delayMicroseconds(10);
          digitalWrite(TrigPin,LOW);
          cm = pulseIn(EchoPin,HIGH)/58.0;  
          cm = (int(cm * 100.0))/100.0;
          if(cm < 0)
          {
             cm = 0;
           }
            
          }
          }
        else{
          digitalWrite(ljos,LOW);
          }
          delay(15);
        }
  }
  // ef ýtt er á takkan þá ntum við stýripinna til að stjórna snúning
  else if (teljari==1){
      styripinniValue = analogRead(styripinni);
      styripinniValue = map(styripinniValue, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
      myservo.write(styripinniValue);                  // sets the servo position according to the scaled value 
    }
        digitalWrite(TrigPin,LOW);
        delayMicroseconds(2);
        digitalWrite(TrigPin,HIGH);
        delayMicroseconds(10);
        digitalWrite(TrigPin,LOW);
        cm = pulseIn(EchoPin,HIGH)/58.0;  
        cm = (int(cm * 100.0))/100.0;
        if(cm < 0)
        {
          cm = 0;
        }
        if(cm<21){
        digitalWrite(ljos,HIGH);
          }
        else{
          digitalWrite(ljos,LOW);
          }
  if (teljari==2){
     teljari=0;
   }
  
}
