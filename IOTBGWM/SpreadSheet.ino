void sendData(float flow_sensor_1,float flow_sensor_2,float level_sensor,float pH_sensor){
  client.setInsecure();
  //Serial.print("connecting to ");
  //Serial.println(host);
   if (!client.connect(host, httpsPort)) {
 //   Serial.println("connection failed");
    return; } 
    
  String FLOW_SENSOR_1 = String(flow_sensor_1, DEC);
  String FLOW_SENSOR_2 = String(flow_sensor_2, DEC);

  String LEVEL_SENSOR = String(level_sensor, DEC);

  String pH_SENSOR = String(pH_sensor, DEC);

//=======================================================================
    String url = "/macros/s/" + GAS_ID + "/exec?FLOW_SENSOR_1=" +  FLOW_SENSOR_1+"L/m" + "&FLOW_SENSOR_2=" + FLOW_SENSOR_2 +"L/m" + "&WATER_LEVEL_SENSOR=" + LEVEL_SENSOR + "&pH_SENSOR=" + pH_SENSOR;
  //  Serial.print("requesting URL: ");
  //  Serial.println(url);

   client.print(String("GET ") + url + " HTTP/1.1\r\n" +
         "Host: " + host + "\r\n" +
         "User-Agent: BuildFailureDetectorESP8266\r\n" +
         "Connection: close\r\n\r\n");

 // Serial.println("request sent");
  while (client.connected()) {
  String line = client.readStringUntil('\n');
  if (line == "\r") {
   // Serial.println("headers received");
    break;
  }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
 // Serial.println("esp8266/Arduino CI successfull!");
  } else {
//  Serial.println("esp8266/Arduino CI has failed");
  }
// Serial.println("reply was:");
// Serial.println("==========");
// Serial.println(line);
// Serial.println("==========");
// Serial.println("closing connection");
  
  
}
