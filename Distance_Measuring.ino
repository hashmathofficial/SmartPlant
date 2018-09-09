#define TRIG_PIN 4            
#define ECHO_PIN 5            

void setup() 
{
  pinMode(TRIG_PIN, OUTPUT);  
  pinMode(ECHO_PIN, INPUT);   
  Serial.begin(9600);         
}

void loop() 
{
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);       //Emmitting a ultrasonic burst of 10 microseconds 
  digitalWrite(TRIG_PIN, LOW);
  
  float microseconds = pulseIn(ECHO_PIN, HIGH, 100000); 
  float seconds = microseconds / 1000000;               
  float meters = seconds * 343;                         
  float cm = meters * 100;                              
  cm = cm/2;                                            
  Serial.println(cm);  //Printing the distance in cm                                 
  delay(50);           //Delay 50 milliseconds until the next measurement                                 
}
