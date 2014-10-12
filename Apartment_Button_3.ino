// This sketch will send out a Nikon D50 trigger signal (probably works with most Nikons)
// See the full tutorial at http://www.ladyada.net/learn/sensors/ir.html
// this code is public domain, please enjoy!
 
int BasePin =  2;    // LED connected to digital pin 2
int capPowerPin = 7; // Receive pin for power code capacitive sensor
int capInputPin = 8; // Receive pin for input code capacitive sensor
int capVolumePin = 9;
int LedPin = 13;
int touchedCutoff = 30; // Sensor needs to read this value to trigger
int c = 0; // Count variable for multiple pins
 
// The setup() method runs once, when the sketch starts
 
void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(BasePin, OUTPUT);      
  pinMode(LedPin, OUTPUT);
}
 
void loop()                     
{
  digitalWrite(LedPin, LOW);
  c = 0;
 if (readCapacitivePin(capPowerPin) > touchedCutoff){
   c++;
 }
 if (readCapacitivePin(capInputPin) > touchedCutoff){
   c++;
 }
 if ((readCapacitivePin(capPowerPin) > touchedCutoff) && (c == 1) {
   PowerCode(); //If capacitance sensed, send the channel code
  delay(3000);  // wait three seconds (3 seconds = 3000 milliseconds)
 }
 if ((readCapacitivePin(capInputPin) > touchedCutoff) && (c == 1) {
   InputCode(); 
   delay(500);
 }
 if ((readCapacitivePin(capVolumeUpPin) > touchedCutoff) && (c == 1){
   VolumeUpCode();
 }
 if ((readCapacitivePin(capVolumeDownPin) > touchedCutoff) && (c == 1){
   VolumeDownCode();
}
 
// This procedure sends a 38KHz pulse to the BasePin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(BasePin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(BasePin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void PowerCode() {
  // This is the code for the CHANNEL + for the downstairs TV COMCAST
  pulseIR(2400);           //Time on  (Right Column on serial monitor)
  delayMicroseconds(520); //Time off (Left Column on serial monitor)
  pulseIR(1240);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(25360);
  pulseIR(2400);
  delayMicroseconds(520);
  pulseIR(1240);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(25360);
  pulseIR(2360);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(25360);
  pulseIR(2360);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(1240);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(1240);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(25320);
  pulseIR(2400);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(25320);
  pulseIR(2400);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(25320);
  pulseIR(2400);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(1240);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
}

void InputCode() {
  // This is the code for the CHANNEL + for the downstairs TV COMCAST
  pulseIR(2360);           //Time on  (Right Column on serial monitor)
  delayMicroseconds(560); //Time off (Left Column on serial monitor)
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(25360);
  pulseIR(2360);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(1240);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(25360);
  pulseIR(2360);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(1240);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(1240);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(25320);
  pulseIR(2400);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(25320);
  pulseIR(2400);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1240);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1240);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(25320);
  pulseIR(2400);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(1200);
  delayMicroseconds(560);
  pulseIR(640);
  delayMicroseconds(520);
  pulseIR(640);
  delayMicroseconds(560);
  pulseIR(600);
  delayMicroseconds(560);
  pulseIR(640);
}

void VolumeUpCode() {
  for (int i = 0; i < 160; i++) {
    pulseIR();
    delayMicroseconds();
  }
  pulseIR();
}

void VolumeDownCode() {
  VolumeUpCode();
}

uint8_t readCapacitivePin(int pinToMeasure){
  // This is how you declare a variable which
  //  will hold the PORT, PIN, and DDR registers
  //  on an AVR
  volatile uint8_t* port;
  volatile uint8_t* ddr;
  volatile uint8_t* pin;
  // Here we translate the input pin number from
  //  Arduino pin number to the AVR PORT, PIN, DDR,
  //  and which bit of those registers we care about.
  byte bitmask;
  if ((pinToMeasure >= 0) && (pinToMeasure <= 7)){
    port = &PORTD;
    ddr = &DDRD;
    bitmask = 1 << pinToMeasure;
    pin = &PIND;
  }
  if ((pinToMeasure > 7) && (pinToMeasure <= 13)){
    port = &PORTB;
    ddr = &DDRB;
    bitmask = 1 << (pinToMeasure - 8);
    pin = &PINB;
  }
  if ((pinToMeasure > 13) && (pinToMeasure <= 19)){
    port = &PORTC;
    ddr = &DDRC;
    bitmask = 1 << (pinToMeasure - 13);
    pin = &PINC;
  }
  // Discharge the pin first by setting it low and output
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  delay(1);
  // Make the pin an input WITHOUT the internal pull-up on
  *ddr &= ~(bitmask);
  // Now see how long the pin to get pulled up
  int cycles = 16000;
  for(int i = 0; i < cycles; i++){
    if (*pin & bitmask){
      cycles = i;
      break;
    }
  }
  // Discharge the pin again by setting it low and output
  //  It's important to leave the pins low if you want to 
  //  be able to touch more than 1 sensor at a time - if
  //  the sensor is left pulled high, when you touch
  //  two sensors, your body will transfer the charge between
  //  sensors.
  *port &= ~(bitmask);
  *ddr  |= bitmask;
  
  return cycles;
}
