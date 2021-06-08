int obs_status;
float count = 0;
long int start_time;
float angular_speed;



void setup() {
  // put your setup code here, to run once:
pinMode(9, INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
obs_status = digitalRead(9);
count = 0;
start_time = millis();
while (millis() - start_time < 19) {
  if (obs_status != digitalRead(9)) {
    count ++;
    obs_status = !obs_status;
    // Serial.println(count);
    
  }
}
angular_speed = ((count / 40) / (10)) * 60000;
Serial.println(angular_speed);
//Serial.println(" rev per min ");

//if(obs_status == 0){
//Serial.println("No Obstruction Detected ");
//}
//else{
// Serial.println("Obstruction Detected ");
//
//}
}
