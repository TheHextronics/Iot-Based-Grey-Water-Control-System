void flow_sensor_loop(){
  
    volume_1 = 2.663 * pulse_1 / 1000 * 30;
    volume_2 = 2.663 * pulse_2 / 1000 * 30;
  if (millis() - lastTime_1 > 2000) {
    pulse_1 = 0;
    lastTime_1 = millis();
  }
   if (millis() - lastTime_2 > 2000) {
    pulse_2 = 0;
    lastTime_2 = millis();
  }
 // Serial.print(volume_1);
 // Serial.println(" L/m");
 // Serial.print(volume_2);
 // Serial.println(" L/m");
}
