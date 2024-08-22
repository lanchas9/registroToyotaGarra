int input = 0;      // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
int monedero = 11;
int led = 12;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(monedero, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}


//AQUI MANDAMOS A HUGH EL PIN QUE MANDA LA SEÑAL Y 1 SEGUNDO DESPUES LO MANDAMOS A LOW
void loop() {
  while (Serial.available()) {
    Serial.print("llego: ");
    char in = Serial.read();
    input = (int)in;
    
    int final = input-48;
    int delayTime = final * 1000;
    Serial.println(final);
    for (int i = 0; i < final ; i++) {
      digitalWrite(monedero, HIGH);  // turn the LED on (HIGH is the voltage level)
      digitalWrite(led, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(500);                      // wait for a second
      digitalWrite(monedero, LOW); 
      digitalWrite(led, LOW); 
      delay(500);                      // wait for a second
    } 
  }  
}