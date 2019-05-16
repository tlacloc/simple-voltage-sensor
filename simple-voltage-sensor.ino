
// SIMPLE SETUP FOR A J2 VOLTAGE SENSOR
/*
 *  WAY TO SETUP THE SENSOR
 *
 * connect all J2 gnd to arduino gnd
 * then connect SIG to analogInput
 * described below, and finally connect
 * VOL to the voltage you want to measure
 */
// port init
int analogInput = A1; // THIS CAN BE CHANGE TO ANY PORT

// resistors
float R1 = 178000.0; // R1 from sensor
float R2 = 822000.0; // R2 from sensor

// init variables
int value = 0;
float vout = 0.0;
float vin = 0.0;

void setup(){
  pinMode(analogInput, INPUT);
  Serial.begin(9600);
}
void loop(){
 
  // read the value at analog input
  value = analogRead(analogInput);
  vout = (value * 5) / 1024.0;
  vin = vout / (R2/(R1+R2));

  // print data
  Serial.print("Vin = ");
  Serial.println(vin,2);
  delay(500);

}
// a code by Erick Casanova
