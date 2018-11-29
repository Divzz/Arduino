#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

//Variables: 
IRrecv irrecv(11); //Set up the IR Reciever, call it irrecv and attach it to the correct pin 
decode_results results; //Set up a variable to hold the results 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  irrecv.enableIRIn(); // Start the receiver 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) { 

    translateIR();  
    irrecv.resume(); 
  } 
}

void translateIR() // takes action based on IR code received

// describing Remote IR codes 

{
  Serial.println(results.value, HEX); //A new button has been pressed with the value shown. 
  switch(results.value)

  {

  case 0xFFA25D: Serial.println(" POWER"); break;
  case 0xFF629D: Serial.println(" Mode"); break;
  case 0xFFE21D: Serial.println(" MUTE"); break;
  case 0xFF22DD: Serial.println(" PLAY/PAUSE");    break;
  case 0xFF02FD: Serial.println(" LEFT");    break;
  case 0xFFC23D: Serial.println(" RIGHT");   break;
  case 0xFFE01F: Serial.println(" EQ"); break;
  case 0xFFA857: Serial.println(" DECREASE"); break;
  case 0xFF906F: Serial.println(" INCREASE");    break;
  case 0xFF9867: Serial.println(" LOOP");    break;
  case 0xFFB04F: Serial.println(" U/SD");    break;
  case 0xFF6897: Serial.println(" 0");    break;
  case 0xFF30CF: Serial.println(" 1");    break;
  case 0xFF18E7: Serial.println(" 2");    break;
  case 0xFF7A85: Serial.println(" 3");    break;
  case 0xFF10EF: Serial.println(" 4");    break;
  case 0xFF38C7: Serial.println(" 5");    break;
  case 0xFF5AA5: Serial.println(" 6");    break;
  case 0xFF42BD: Serial.println(" 7");    break;
  case 0xFF4AB5: Serial.println(" 8");    break;
  case 0xFF52AD: Serial.println(" 9");    break;
  case 0xFFFFFFFF: Serial.println(" REPEAT");break;  

  default: 
    Serial.println(" other button   ");

  }// End Case

  delay(500);
}
