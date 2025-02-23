void pH_sensor_loop(){
  
pH_Value= analogRead(PH_PIN);      //
voltage=pH_Value*(3.3/4096.0);     //
ph_Data=(8.8*voltage); 
}
