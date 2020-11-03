/* 
 *  This program is used for controlling four Chauvet DJ Hurricane 1600 Constant Foggers at A&E Scare Farms
 *  Program made by: Ethen, Owner of A&E Scare Farms
 *  Date modified: 11/2/2020
 */

/*
 * Declare Fog Trigger Ports and Timings and other useful things
 * We start a Digital output pin 2 since 0-1 are used for specific arduino functions that maybe be in use later on
 */

//Fog Machine Relay Ports
int fog_1 = 2;
int fog_2 = 3;
int fog_3 = 4;
int fog_4 = 5;

//Specific Timings in seconds (Wait 60 secs for heat up, blast for 20 sec, wait 180 seconds or three min before next blast)
int initial_heat_time = 60;
int blast_time = 20;
int blast_wait_time = 180;

//The code in here is only ran once during power up!
void setup() {
  //Starts debug serial console in case my computer is being used for debugging the controller
  Serial.begin(9600);
  //Setup pinModes for Fog Machine relays
  pinMode(fog_1, OUTPUT);
  pinMode(fog_2, OUTPUT);
  pinMode(fog_3, OUTPUT);
  pinMode(fog_4, OUTPUT);
  Serial.println("Relay Pins Set!");

  //Set all of the pins to off so no fog is produced
  digitalWrite(fog_1, LOW);
  digitalWrite(fog_2, LOW);
  digitalWrite(fog_3, LOW);
  digitalWrite(fog_4, LOW);

  //Wait for the fog machines to heat up which for these machines are about 15-20 sec but I like to be safe and give them a min
  delay(initial_heat_time);
  
  //Now fog up the haunt
  digitalWrite(fog_1, HIGH);
  digitalWrite(fog_2, HIGH);
  digitalWrite(fog_3, HIGH);
  digitalWrite(fog_4, HIGH);

  delay(blast_time);

  //Now off with the fog and go to loop
  digitalWrite(fog_1, LOW);
  digitalWrite(fog_2, LOW);
  digitalWrite(fog_3, LOW);
  digitalWrite(fog_4, LOW);

  delay(blast_wait_time);
}

//The code in here is ran every loop
void loop() {
  //The foggers are heated up so fire away but in a sequence!
  digitalWrite(fog_1, HIGH);
  digitalWrite(fog_4, HIGH);

  delay(blast_time);

  digitalWrite(fog_1, LOW);
  digitalWrite(fog_4, LOW);
  
  digitalWrite(fog_2, HIGH);
  digitalWrite(fog_3, HIGH);

  delay(blast_time);

  digitalWrite(fog_2, LOW);
  digitalWrite(fog_3, LOW);

  delay(blast_wait_time);
  
}
