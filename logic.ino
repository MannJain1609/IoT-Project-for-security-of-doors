/*Task 1
Team Name:- Circuit Breakers
Member's Name:-
1. Ekansh Bansal
2. Mann Jain

*/


#include<Servo.h>

const int buzzer = 8;
int sound=500;
String a,b,c,d;
char *pass="barbosa";
char *ans2="1";
char *ans3="99";
char *ans4="108";
int flag=0,pass2=0,pass3=0,pass4=0;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
int d1=0,d2=0,d3=0,d4=0;

void setup() {
  Serial.begin(9600);
  noTone(buzzer);
  pinMode(buzzer, OUTPUT);
  servo1.attach(2);
  pinMode(2,OUTPUT);
  servo2.attach(3);
  pinMode(3,OUTPUT);
  servo3.attach(4);
  pinMode(4,OUTPUT);
  servo4.attach(5);
  pinMode(5,OUTPUT);
  Serial.print("Door 1: Enter password as name of a pirate cursed of a black pearl\n\n");
  Serial.print("Door 2: Enter a positive integer which when added with 2000 is greater than when multiplied by 2000\n\n");
  Serial.print("Door 3: On Monday, a pirate ate half paratha. He ate of what wsa left on Tuesday and so on for one week.\n");
  Serial.print("write approx integer of percentage of the paratha he have eaten durrring the week\n\n");
  Serial.print("Door 4:Among the following set, write the maximum number of 4's between the numbers\n");
  Serial.print("a.) 700-900  b.) 300-500  c.) 1-100 \n\n");
  Serial.print("Enter for door 1");
}


void loop()
{ 
  int loop1=1,loop2=0,loop3=0,loop4=0;
  servo1.write(d1);
  servo2.write(d2);
  servo3.write(d3);
  servo4.write(d4);
  
  
  while(loop1==1) {
    if (Serial.available()>0)
  	{
    	flag=1;
    	a=Serial.readString();
    	Serial.print("rec: ");
    	Serial.println(a);
  	}
  	if (flag==1 && a!=pass)
  	{
    	tone(buzzer,sound);
    	delay(2000);
  	}
  	else if (a==pass)
  	{
    	d1=90;
      	servo1.write(90);
    	delay(15);
    	noTone(buzzer);
    	delay(2000);
    	Serial.print("Door 1 has opened.\n");
    	Serial.print("Enter for Door 2");
      	loop1=0;
      	loop2=1;
  	}
  	flag=0;
  }
  while(loop2==1){
     if (Serial.available()>0)
  	{
    	flag=1;
    	b=Serial.readString();
    	Serial.print("rec: ");
    	Serial.println(b);
  	}
  	if (flag==1 && b!=ans2)
  	{
    	tone(buzzer,sound);
    	delay(2000);
  	}
  	else if (b==ans2)
  	{
      d2=90;
      servo2.write(90);
      delay(15);
      noTone(buzzer);
      delay(2000);
      Serial.print("Door 2 has opened. You got to treasure but don't be so happy you also have to go out\n");
      Serial.print("Enter for Door 3");
      loop2=0;
      loop3=1;
  	}
  	flag=0;
  }
  while(loop3==1){
    if (Serial.available()>0)
    {
      flag=1;
      c=Serial.readString();
      Serial.print("rec: ");
      Serial.println(c);
    }
    if (flag==1 && c!=ans3)
  	{
    	tone(buzzer,sound);
    	delay(2000);
  	}
  	else if (c==ans3)
  	{
    	d3=90;
      	servo3.write(90);
    	delay(15);
    	noTone(buzzer);
    	delay(2000);
    	Serial.print("Door 3 has opened.");
    	Serial.print("Enter for Door 4");
      	loop3=0;
    	loop4=1;
  	}
  	flag=0; 
  }
  while(loop4==1){
    if (Serial.available()>0)
    {
      flag=1;
      d=Serial.readString();
      Serial.print("rec: ");
      Serial.println(d);
    }
    if (flag==1 && d!=ans4)
  	{
    	tone(buzzer,sound);
    	delay(2000);
  	}
  	else if (d==ans4)
  	{
    	d4=90;
      	servo4.write(90);
    	delay(15);
    	noTone(buzzer);
    	delay(2000);
    	Serial.print("Door 4 has opened.\n");
    	Serial.print("Ohh you are smart, you unlocked all the doors :(");
      	loop4=0;
      	delay(2000);
      	exit(0);
  	}
  	flag=0; 
  }
  delay(5000);
}