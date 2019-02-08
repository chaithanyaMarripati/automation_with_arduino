#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;
int l1=2;
int l2=3;
int l3=4;
int l4=5;
void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
  pinMode(l4,OUTPUT);
}
void one(){
    digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);
    digitalWrite(l3,LOW);
    digitalWrite(l4,LOW);
  }
  void two(){
    digitalWrite(l2,HIGH);
    digitalWrite(l1,LOW);
    digitalWrite(l3,LOW);
    digitalWrite(l4,LOW);
}
void three(){
      digitalWrite(l3,HIGH);
    digitalWrite(l4,LOW);
    digitalWrite(l1,LOW);
    digitalWrite(l2,LOW);
}
void four(){
    digitalWrite(l4,HIGH);
    digitalWrite(l1,LOW);
    digitalWrite(l2,LOW);
    digitalWrite(l3,LOW);
}

void power(){
    digitalWrite(l1,HIGH);
    digitalWrite(l2,HIGH);
    digitalWrite(l3,HIGH);
    digitalWrite(l4,HIGH);
}

void off(){
    digitalWrite(l1,LOW);
    digitalWrite(l2,LOW);
    digitalWrite(l3,LOW);
    digitalWrite(l4,LOW);
}
void fun(){
  
  one();
  delay(100);
  two();
  delay(100);
  three();
  delay(100);
  four();
  delay(100);
  digitalWrite(l4,LOW);}
void loop() {
  if (irrecv.decode(&results)) {
    if (results.value==12582913)
    one();
    if (results.value==12582914)
    two();
    if(results.value==12582915)
    three();
    if (results.value==12582916)
    four();
    if (results.value==12583004){
      fun();
      fun();
      fun(); }
    if (results.value==12582924)
    power();
    if (results.value==12583044)
    off();

    irrecv.resume(); // Receives the next value
  }
  delay(100);
  }