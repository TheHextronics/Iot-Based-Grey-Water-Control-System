void wifi_setup(){
WiFi.begin(ssid, password);            // Connect to your WiFi router
Serial.println("");                    // Print the data into Serial Monitor

pinMode(2,OUTPUT);                    // Pin D0 is output
digitalWrite(2, HIGH);                // Pin D0 is HIGH
//=======================================================================
Serial.print("Connecting To Wifi");            // Connecation Status
Serial.println(ssid);
WiFi.mode(WIFI_STA);

while (WiFi.status() != WL_CONNECTED)
  
{
Serial.print(".");

     digitalWrite(2, LOW);   // LED status to indecated is Low
     delay(250);              // 1/4 Microsecound Delay
     digitalWrite(2, HIGH);  // LED status to indecated is HIGH
     delay(300);              // 1/4 Microsecound Delay
}
//=======================================================================
digitalWrite(LED_BUILTIN, HIGH);       // Turn off the On Board LED
Serial.println("");
Serial.print("Successfully connected to : ");
Serial.println(ssid);
Serial.print("IP address: ");
Serial.println(WiFi.localIP());
Serial.println();
client.setInsecure();
}
