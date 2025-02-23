void Ultrasonic_Loop(){
//=====================================================================================================================s
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
//=====================================================================================================================s
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);
//=====================================================================================================================s
  duration = pulseIn(ECHO_PIN, HIGH);                     // Reads the echoPin, returns the sound wave travel time in microseconds
//=====================================================================================================================s    
 ULTRASONIC_DATA_CM = duration * SOUND_VELOCITY/2;              // Calculate the distance
 //ULTRASONIC_DATA_INCH = distanceCm * CM_TO_INCH;                // Convert to inches
 CALCULATION_WATER_LEVEL_PERCENTAGE=((ULTRASONIC_DATA_CM/100)*100);
 WATER_LEVEL_PERCENTAGE = map(CALCULATION_WATER_LEVEL_PERCENTAGE, 100, 20, 0, 98);

// WATER_LEVEL_PERCENTAGE=(((ULTRASONIC_DATA_CM-LRV)/-SPAN)*100);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  }
