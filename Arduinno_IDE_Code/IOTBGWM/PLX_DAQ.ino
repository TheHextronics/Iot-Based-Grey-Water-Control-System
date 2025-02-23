void plx_daq_setup(){
Serial.println("CLEARDATA");                           //
Serial.println("LABEL, CLOCK, DAY, FLOW_SENSOR_1, FLOW_SENSOR_2, LEVEL_SENSOR, pH_SENSOR,");//
  }
void plx_daq_loop(){
  
  Serial.print("DATA, TIME, DATE,");                     //
                                                  //
  Serial.print(volume_1);                         // print the Value of x (Sensor1 data)
  Serial.print("L/m");                            //
  Serial.print(",");                              //
                        
  Serial.print(volume_2);                         // print the Value of x (Sensor2 data)
  Serial.print("L/m");                            //
  Serial.print(",");                              //              


  Serial.print(WATER_LEVEL_PERCENTAGE);           // print the Value of x (Sensor3 data)
  Serial.print("%");                              //
  Serial.print(",");                              //


  Serial.print(ph_Data);                          // print the Value of x (Sensor1 data)
  Serial.print("pH");                             // 
  Serial.print(",");      
  //
  Serial.println();                                                        
  }
