void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void text(String textout) {
  Serial.println(textout);
}

void ledon() {
  digitalWrite(LED_BUILTIN, HIGH);
}

void ledoff() {
  digitalWrite(LED_BUILTIN, LOW);
}

int a;
void add(int num) {
  a += num;
  Serial.println(a);
}

void loop() {
  if (Serial.available() > 0) {
    // Multiple functions can be called from serial monitor with one call by seperating them with character \
    // For example: ledon()\ledoff()\text(Hello World)\
    
    String inpstr = Serial.readStringUntil('\\');
    
    if (inpstr.indexOf('(') > 0 && inpstr.indexOf(')') > 0) {
      
      String command = inpstr.substring(0, inpstr.indexOf('('));
      String param = inpstr.substring(inpstr.indexOf('(') + 1, inpstr.indexOf(')'));
      
      if (command == "text") { // Variable "param" is a string. If your function takes a string, it can be fed directly
        text(param);
      }
      
      if (command == "ledon") { // Obviously if a function doesnt need parameters, just dont use it
        ledon();
      }
      
      if (command == "ledoff") {
        ledoff();
      }
      
      if (command == "add") { // If a function requires an integer, convert String param to int with toInt()
        add(param.toInt());
      }
      
    }
  }
  
}
