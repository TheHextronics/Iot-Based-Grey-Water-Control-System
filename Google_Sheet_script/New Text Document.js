function doGet(e) { 
  Logger.log( JSON.stringify(e) );  // view parameters
  var result = 'Ok'; // assume success
  if (e.parameter == 'undefined') {
    result = 'No Parameters';
  }
  else {
    var sheet_id = '1t2P4NO1vvZ_VYUEKFtFM3j0aS-4tuj6muBJE8qkuT08'; 		                       // Enter your Spreadsheet ID
    var sheet = SpreadsheetApp.openById(sheet_id).getActiveSheet();		                       // get Active sheet
    var newRow = sheet.getLastRow() + 1;						
    var rowData = [];
	
	const month = ["January","February","March","April","May","June","July","August","September","October","November","December"];
	const day = ["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"]
	d=new Date();
	rowData[0] = d;                         // Date in column A
    rowData[1] = d.toLocaleTimeString();    // Timestamp in column B
	rowData[2] = day[d.getDay()];           // Day in column C
	rowData[3] = month[d.getUTCMonth()];    // Month in column  D
	rowData[4] = d.getHours(); 
	
	for (var param in e.parameter) {
      Logger.log('In for loop, param=' + param);
      var value = stripQuotes(e.parameter[param]);
      Logger.log(param + ':' + e.parameter[param]);
      switch (param) {
        case 'FLOW_SENSOR_1': //Parameter 1, It has to be updated in Column in Sheets in the code, orderwise
          rowData[5] = value; //Value in column A
          result += 'Written on column F';
          break;
        case 'FLOW_SENSOR_2': //Parameter 2, It has to be updated in Column in Sheets in the code, orderwise
          rowData[6] = value; //Value in column B
          result += ' Written on column G';
          break;
        case 'WATER_LEVEL_SENSOR': //Parameter 3, It has to be updated in Column in Sheets in the code, orderwise
          rowData[7] = value; //Value in column C
          result += ' Written on column H';
          break;
		case 'pH_SENSOR': //Parameter 4, It has to be updated in Column in Sheets in the code, orderwise
          rowData[8] = value; //Value in column C
          result += ' Written on column H';
          break;
        default:
          result = "unsupported parameter";
      }
    }
    Logger.log(JSON.stringify(rowData));
    // Write new row below
    var newRange = sheet.getRange(newRow, 1, 1, rowData.length);
    newRange.setValues([rowData]);
  }
  // Return result of operation
  return ContentService.createTextOutput(result);
}
function stripQuotes( value ) {
  return value.replace(/^["']|['"]$/g, "");
}
