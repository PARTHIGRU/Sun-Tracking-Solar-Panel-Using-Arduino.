
#include<Servo.h>     // library for servo motor 

Servo sv; // define Vertical servo
Servo sh; // define Horizontal servo           
int start1 = 90; // initially starting from 90 degree
int start2 = 90; 
int L1 = A0;  //for read data from LDR1         
int L2 = A1;  //for read data from LDR2
int L3 = A2;  //for read data from LDR3        
int L4 = A3;  //for read data from LDR4        
int a = 15;          

void setup() 
{ 
  sv.attach(9); //connect vertical servo to digital pin 9 of arduino  
  sh.attach(10);  //connect horizontal servo to pin 10 of arduino 
  pinMode(L1, INPUT);  //define LDR as input
  pinMode(L2, INPUT);
  pinMode(L3, INPUT);  
  pinMode(L4, INPUT);
  sv.write(start1); //it will start servo from 90 when we reset system
  sh.write(start2);           
} 
void loop() 
{ 
  int LDR1 = analogRead(L1); //read value from LDR
  int LDR2 = analogRead(L2); 
  int LDR3 = analogRead(L3);
  int LDR4 = analogRead(L4);
  int plus12 =(LDR1+LDR2);  //average of two top LDRs
  int plus24 =(LDR2+LDR4);	//average of two right LDRs
  int plus13 =(LDR1+LDR3);	//average of two left LDRs
  int plus34 =(LDR3+LDR4);	//average of two bottom LDRs
  int diff1= abs(plus12 - plus34);  // difference to take proper value
  int diff2= abs(plus34 - plus12);
  int diff3= abs(plus13 - plus24);  
  int diff4= abs(plus24 - plus13);
  
  if((diff1 <= a) || (diff2 <= a))
 {
   //difference is less then 15 so do nothing
  } 
else 
{    
    if(plus12 > plus34) //move vertical servo in lessthen 90 degree
    {
     start2= --start2;   
    }
 if(plus12 < plus34) 
    {
      start2 = ++start2;  //move vertical servo in greaterthen 90 degree
    }
  }
       if(plus13 > plus24 )
  {
    start1= --start1;   // move horizontal servo in lessthen 90 degree
  }
  if(plus13 < plus24)
  {
   start1= ++start1;  //move horizontal servo in greaterthen 90 degree
   }
   sv.write(start1);
  sh.write(start2);
   delay(100);
}
