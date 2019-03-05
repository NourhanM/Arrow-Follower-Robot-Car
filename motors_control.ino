#include<SoftwareSerial.h>
SoftwareSerial x(16,17); //Tx,Rx

int c=1;
int _time;
int distance;
byte h = 0;
const int echo = 14;
const in trig = 15;

int en1=6;  //motor 1
int m1b=2;
int m1f=3;

int en2=9;  //motor 2
int m2b=5;
int m2f=4;

int en3=10;  //motor 3
int m3b=8;
int m3f=7;

int en4=11; //motor 4
int m4b=12;
int m4f=13;

int motorSpeed =0;
char bt =0;

void Backward(){
  digitalWrite(m1f,1);
  digitalWrite(m1b,0);
  digitalWrite(m2f,1);
  digitalWrite(m2b,0);

  digitalWrite(m3f,1);
  digitalWrite(m3b,0);
  digitalWrite(m4f,1);
  digitalWrite(m4b,0);
  
  }
void Forward(){
  digitalWrite(m1f,0);
  digitalWrite(m1b,1);
  digitalWrite(m2f,0);
  digitalWrite(m2b,1);

  digitalWrite(m3f,0);
  digitalWrite(m3b,1);
  digitalWrite(m4f,0);
  digitalWrite(m4b,1);
  
  }
void Right(){
  digitalWrite(m1f,0);
  digitalWrite(m1b,1);
  digitalWrite(m2f,1);
  digitalWrite(m2b,0);

  digitalWrite(m3f,0);
  digitalWrite(m3b,1);
  digitalWrite(m4f,1);
  digitalWrite(m4b,0);
  
  }  
void Left(){
  digitalWrite(m1f,1);
  digitalWrite(m1b,0);
  digitalWrite(m2f,0);
  digitalWrite(m2b,1);

  digitalWrite(m3f,1);
  digitalWrite(m3b,0);
  digitalWrite(m4f,0);
  digitalWrite(m4b,1);
  
  } 
void Stop(){
  digitalWrite(m1f,0);    
  digitalWrite(m1b,0);
  digitalWrite(m2f,0);
  digitalWrite(m2b,0);

  digitalWrite(m3f,0);
  digitalWrite(m3b,0);
  digitalWrite(m4f,0);
  digitalWrite(m4b,0);
  
  }   
void movee (int c){
  if (x.available() > 0 && c==1){
    bt = x.read();
    c=0;
    }
  if (bt == 'b'){
    Backward();
    }  
  else if (bt == 'f'){
    Forward();
    }
  else if (bt == 's'){
    Stop();
    }  
  else if (bt == 'r'){
    Right();
    delay(350);
    bt='f';
    } 
  else if (bt == 'l'){
    Left();
    delay(350);
    bt ='f';
    }   
  }

void setup(){
  analogWrite(en1,150);
  analogWrite(en2,150);
  analogWrite(en3,150);
  analogWrite(en4,150);

  Serial.begin(9600);

  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  pinMode(en3,OUTPUT);
  pinMode(en4,OUTPUT);
  pinMode(m1f,OUTPUT);
  pinMode(m1b,OUTPUT);
  pinMode(m2f,OUTPUT);
  pinMode(m2b,OUTPUT);
  pinMode(m3f,OUTPUT);
  pinMode(m3b,OUTPUT);
  pinMode(m4f,OUTPUT);
  pinMode(m4b,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(18,OUTPUT);
  digitalWrite(18,HIGH);
  }

void loop(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  _time = pulseIn(echo,HIGH);
  distance = (_time/2)*0.034 ;

  if (distance >= 40 && distance <= 45){
    delay(30);
    Stop();
    bt ='s';
    delay (2000);
    x.println('q');
    c=1;
    movee(c);
    }
  else
  Movee(c);
  }
    
