void PUMP_Setup(){

 if (WATER_LEVEL_PERCENTAGE <=60){
 if(A==0){

     EEPROM.write(1,1);
     EEPROM.commit();   
     digitalWrite(MOTOR_RELAY,LOW); 

     A++;
     B=0;
    }
  } 

if (WATER_LEVEL_PERCENTAGE >= 95) {
if(B==0){

  EEPROM.write(1,0);
  EEPROM.commit();
  digitalWrite(MOTOR_RELAY,HIGH); 

  A=0;
  B++;
  }
} 
}


void EEPROM_DATA(){
  
if(EEPROM_PUMP_AUTO_STATUS_DATA == 1){
 if(A==0){ 
     digitalWrite(MOTOR_RELAY,LOW); 

     A++;
     B=0;
    }
  }
  
if(EEPROM_PUMP_AUTO_STATUS_DATA == 0){
 if(B==0){
  digitalWrite(MOTOR_RELAY,HIGH); 

  A=0;
  B++;
  }
 }
  
  }
