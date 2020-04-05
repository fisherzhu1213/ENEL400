  #include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
const char* ssid = "Colorsan";
const char* password = "yumo1990";
//const char* ssid = "SASKTEL204";
//const char* password = "4574146898";

int ledPin = 13; // GPIO13---D7 of NodeMCU
SoftwareSerial ESPserial(0, 2); // RX（N/A） | TX(D4) on the board
WiFiServer server(80);


void setup() {
  Serial.begin(115200);
  ESPserial.begin(9600);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Request table
 
  int value ;
  if (request.indexOf("/DATA=SEND") != -1)  {
    ESPserial.write(118);
    value = 1;
  }
  
  if (request.indexOf("/DATA=NO_SEND") != -1)  {
    ESPserial.write(132);
    value = 2;
  }

   if (request.indexOf("/DATA=ARM_FORWARD") != -1)  {
    ESPserial.write('G');
    value = 1;
  }


   if (request.indexOf("/DATA=ARM_STOP") != -1)  {
    ESPserial.write('I');
    value = 2;
  }

   if (request.indexOf("/DATA=ARM_BACKWARD") != -1)  {
    ESPserial.write('H');
    value = 3;
  }
  
   if (request.indexOf("/DATA=CLAMP_ROTATE_RIGHT") != -1)  {
    ESPserial.write('m');
    value = 4;
  }
    if (request.indexOf("/DATA=CLAMP_ROTATE_LEFT") != -1)  {
    ESPserial.write('n');
    value = 22;
  }
   if (request.indexOf("/DATA=CLAMP_STOP") != -1)  {
    ESPserial.write('x');
    value = 5;
  } 

   if (request.indexOf("/DATA=CLAMP_GET") != -1)  {
    ESPserial.write('a');
    value = 6;
  }

   if (request.indexOf("/DATA=CLAMP_LEASE") != -1)  {
    ESPserial.write('b');
    value = 7;
  }   

   if (request.indexOf("/DATA=MOVE_FORWARD") != -1)  {
    ESPserial.write('A');
    value = 8;
  }  
   
   if (request.indexOf("/DATA=2ND_ACC") != -1)  {
    ESPserial.write('E');
    value = 9;
  }  
   
   if (request.indexOf("/DATA=3RD_ACC") != -1)  {
    ESPserial.write('F');
    value = 10;
  }  
   
   if (request.indexOf("/DATA=ROBOT_STOP") != -1)  {
    ESPserial.write('O');
    value = 11;
  }  
   
   if (request.indexOf("/DATA=MOVE_BACKWARD") != -1)  {
    ESPserial.write('B');
    value = 12;
  }   
  
   if (request.indexOf("/DATA=ROBOT_TURN_LEFT") != -1)  {
    ESPserial.write('C');
    value = 13;
  }   
  
   if (request.indexOf("/DATA=ROBOT_TURN_RIGHT") != -1)  {
    ESPserial.write('D');
    value = 14;
  }   

   if (request.indexOf("/DATA=servo_test") != -1)  {
    ESPserial.write('h');
    value = 17;
  }   

   if (request.indexOf("/DATA=FWD_5_DEG") != -1)  {
    ESPserial.write('i');
    value = 18;
  }   
  
   if (request.indexOf("/DATA=BWD_5_DEG") != -1)  {
    ESPserial.write('j');
    value = 19;
  } 

    if (request.indexOf("/DATA=SUB_FWD_5_DEG") != -1)  {
    ESPserial.write('o');
    value = 23;
  }   
  
   if (request.indexOf("/DATA=SUB_BWD_5_DEG") != -1)  {
    ESPserial.write('p');
    value = 24;
  }  
  
   if (request.indexOf("/DATA=CLAMP_GET_5_DEG") != -1)  {
    ESPserial.write('k');
    value = 20;
  }   
  
   if (request.indexOf("/DATA=CLAMP_LEASE_5_DEG") != -1)  {
    ESPserial.write('l');
    value = 21;
  } 
     if (request.indexOf("/DATA=ARM_ROTATE_LEFT") != -1)  {
    ESPserial.write('d');
    value = 22;
  }       
     if (request.indexOf("/DATA=ARM_ROTATE_RIGHT") != -1)  {
    ESPserial.write('e');
    value = 23;
  }   
     if (request.indexOf("/DATA=SUBARM_FWD") != -1)  {
    ESPserial.write('J');
    value = 24;
  }
     if (request.indexOf("/DATA=SUBARM_BWD") != -1)  {
    ESPserial.write('K');
    value = 25;
  }
     if (request.indexOf("/DATA=ARR10") != -1)  {
    ESPserial.write('L');
    value = 26;
  }
     if (request.indexOf("/DATA=ARL10") != -1)  {
    ESPserial.write('M');
    value = 27;
  }
     if (request.indexOf("/DATA=INITIALIZATION") != -1)  {
    ESPserial.write('q');
    value = 28;
  }
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("SELECT FUNCTIONS <br />");
 
  if(value == 1) {
    client.print("MOVING FORWARD");
  } else if ( value == 2) {
    client.print("ARM_STOP");
  }else if ( value == 3) {
    client.print("ARM_BACKWARD");
  }else if ( value == 4) {
    client.print("CLAMP_ROTATE_RIGHT");
  }else if ( value == 5) {
    client.print("CLAMP_ROTATE_LEFT");
  }else if ( value == 22) {
    client.print("CLAMP_STOP");
  }else if ( value == 6) {
    client.print("CLAMP_GET");
  }else if ( value == 7){
    client.print("CLAMP LEASE");
  }else if ( value == 8){
    client.print("MOVE FORWARD");
  }else if ( value == 9){
    client.print("2ND_ACC");
  }else if ( value == 10){
    client.print("3RD_ACC");
  }else if ( value == 11){
    client.print("ROBOT_STOP");
  }else if ( value == 12){
    client.print("MOVE_BACKWARD");
  }else if ( value == 13){
    client.print("ROBOT_TURN_LEFT");
  }else if ( value == 14){
    client.print("ROBOT_TURN_RIGHT");
  }else if ( value == 17){
    client.print("servo test");
  }else if ( value == 18){
    client.print("ARM MOVE FORWARD FOR 5 DEG");
  }else if ( value == 19){
    client.print("ARM MOVE BACKWARD FOR 5 DEG");
  }else if ( value == 23){
    client.print("SUB ARM MOVE FORWARD FOR 5 DEG");
  }else if ( value == 24){
    client.print("SUB ARM MOVE BACKWARD FOR 5 DEG");
  }else if ( value == 20){
    client.print("CLAMP GET FOR 5 DEG");
  }else if ( value == 21){
    client.print("CLAMP LEASE FOR 5 DEG");
  }else if ( value == 22){
    client.print("ARM ROTATE LEFT");
  }else if ( value == 23){
    client.print("ARM ROTATE RIGHT");
  }else if ( value == 24){
    client.print("SUBARM FWD 20DEG");
  }else if ( value == 25){
    client.print("SUBARM BWD 20DEG");
  }else if ( value == 26){
    client.print("ARM ROTATE RIGHT 10DEG");
  }else if ( value == 27){
    client.print("ARM ROTATE LEFT 10DEG");
  }else if ( value == 28){
    client.print("INITIALIZATION");
  }else{
    client.print("UNKNOWN COMMAND");
  }

  //HTML TABLE
  client.println("<html>");
  client.println("<style>");
  client.println("table{\n\nborder-collapse: collapse;\nempty-cells: show;\n}");
  client.println("table, th, td {\n border: 1px solid black;\n}");
  client.println("th,td{\npadding: 15px;\n}");
  client.println("td{\nheight: 30px;\n}");
  client.println("</style>");
  
  client.println("<table>");
  client.println("<tr>");
  client.println("<th>Arm Forward</th>");
  client.println("</tr>");
  client.println("<tr>");
  client.println("<td><a href=\"/DATA=ARM_FORWARD\"\"><button>ARM_FORWARD</button></a></td>");
  client.println("<td><a href=\"/DATA=FWD_5_DEG\"\"><button>AMF 5 DEG</button></a></td>");  
  client.println("<td><a href=\"/DATA=BWD_5_DEG\"\"><button>AMB 5 DEG</button></a></td>");
  client.println("<td><a href=\"/DATA=ARM_BACKWARD\"\"><button>ARM_BACKWARD</button></a></td>");
  client.println("</tr>");
  client.println("<tr>");
  client.println("<tr>");
  client.println("<th>Arm Backward</th>");
  client.println("</tr>");
  client.println("<td><a href=\"/DATA=SUB_FWD_5_DEG\"\"><button>SAMF 5 DEG</button></a></td>");
  client.println("<td><a href=\"/DATA=SUBARM_FWD\"\"><button>SAMF 20DEG</button></a></td>");    
  client.println("<td><a href=\"/DATA=SUB_BWD_5_DEG\"\"><button>SAMB 5 DEG</button></a></td>");  
  client.println("<td><a href=\"/DATA=SUBARM_BWD\"\"><button>SAMB 20DEG</button></a></td>");
  
  client.println("</tr>");
  client.println("<tr>");
  client.println("<th>Arm Stop</th>");
  client.println("<tr>");
  client.println("</tr>");
  client.println("<td><a href=\"/DATA=ARM_STOP\"\"><button>ARM_STOP</button></a></td>");
  client.println("</tr>");

  client.println("<th>Arm  Rotation</th>");
  client.println("<tr>");
  client.println("</tr>");
  client.println("<td><a href=\"/DATA=ARM_ROTATE_LEFT\"\"><button>ARM ROTATE LEFT</button></a></td>");  
  client.println("<td><a href=\"/DATA=ARL10\"\"><button>ARM ROTATE L10</button></a></td>");  
  client.println("<td><a href=\"/DATA=ARM_ROTATE_RIGHT\"\"><button>ARM ROTATE RIGHT</button></a></td>");
  client.println("<td><a href=\"/DATA=ARR10\"\"><button>A ROTATE R10</button></a></td>");  
  client.println("</tr>");
  
  client.println("<tr>");
  client.println("<th>Clamp Rotation</th>");
  client.println("</tr>");
  client.println("<tr>");
  client.println("<td><a href=\"/DATA=CLAMP_ROTATE_RIGHT\"\"><button>CLAMP ROTATE RIGHT</button></a></td>");
  client.println("<td><a href=\"/DATA=CLAMP_ROTATE_LEFT\"\"><button>CLAMP ROTATE LEFT</button></a></td>");
  client.println("<td><a href=\"/DATA=CLAMP_STOP\"\"><button>CLAMP_STOP</button></a></td>");
  client.println("</tr>");
  
  
  client.println("<tr>");
  client.println("<th>Clamp Action</th>");
  client.println("</tr>");
  client.println("<tr>");
  client.println("<td><a href=\"/DATA=CLAMP_GET\"\"><button>CLAMP_GET</button></a></td>");
  client.println("<td><a href=\"/DATA=CLAMP_GET_5_DEG\"\"><button>CG 5 DEG</button></a></td>"); 
  client.println("<td><a href=\"/DATA=CLAMP_LEASE_5_DEG\"\"><button>CL 5 DEG</button></a></td>"); 
  client.println("<td><a href=\"/DATA=CLAMP_LEASE\"\"><button>CLAMP_LEASE</button></a></td>");
  client.println("</tr>");
  
  client.println("<tr>");
  client.println("<th>Robot Movement</th>");
  client.println("</tr>");
  client.println("<tr>");
  client.println("<td><a href=\"/DATA=MOVE_FORWARD\"\"><button>MOVE FORWARDRD</button></a></td>");
  client.println("<td><a href=\"/DATA=ROBOT_STOP\"\"><button>STOP</button></a></td>");
  client.println("<td><a href=\"/DATA=MOVE_BACKWARD\"\"><button>MOVE BACKWARD</button></a></td>");
  client.println("</tr>");
  client.println("<tr>");
  client.println("<td><a href=\"/DATA=2ND_ACC\"\"><button>2ND SPEED</button></a></td>");
  client.println("<td><a href=\"/DATA=3RD_ACC\"\"><button>3RD SPEED</button></a></td>");
  client.println("</tr>");

  client.println("<tr>");
  client.println("<th>Robot Rotation</th>");
  client.println("</tr>");
  client.println("<tr>");
  client.println("<td><a href=\"/DATA=ROBOT_TURN_LEFT\"\"><button>TURN LEFT</button></a></td>");
  client.println("<td><a href=\"/DATA=ROBOT_TURN_RIGHT\"\"><button>TURN RIGHT</button></a></td>");
  client.println("</tr>");

  client.println("<tr>");
  client.println("<th>Robot initialize</th>");
  client.println("<td><a href=\"/DATA=INITIALIZATION\"\"><button>initialize</button></a></td>");
  client.println("</tr>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
