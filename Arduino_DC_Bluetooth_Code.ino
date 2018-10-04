int motor1Pin1 = 3; 
int motor1Pin2 = 4; 
int motor2Pin1 = 8; 
int motor2Pin2 = 9;
int state;
int flag=0;        
int stateStop=0;
void setup() {
    
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
         
    Serial.begin(9600);
}

void loop() {
    if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
    }   
    if (state == 'F') {
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("FORWARD!");
          flag=1;
        }
    }
    
    else if (state == 'R') {
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("LEFT!");
          flag=1;
        }
        delay(1500);
        state=3;
        stateStop=1;
    }
    else if (state == 'S' || stateStop == 1) {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("STOP!");
          flag=1;
        }
        stateStop=0;
    }
    else if (state == 'L') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        if(flag == 0){
          Serial.println("RIGHT!");
          flag=1;
        }
        delay(1500);
        state=3;
        stateStop=1;
    }
    else if (state == 'B') {
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        if(flag == 0){
          Serial.println("REVERSE!");
          flag=1;
        }
    }
    
}
