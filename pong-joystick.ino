const int pinPot = A0;
int valuePot;
int flagPot = -1;

int pinButtonDown = D8;
int valueButtonDown;

int pinButtonUp = D1;
int valueButtonUp;

int flagButton;
void setup() {
  Serial.begin(9600);
  pinMode(pinPot,INPUT);
  pinMode(pinButtonDown,INPUT);
  pinMode(pinButtonUp,INPUT);
}

void loop() {
  
    valuePot = map(analogRead(pinPot),0,1023,0,100);
    playerOne(valuePot);
    flagButton = 1;
    
    while((valueButtonUp = digitalRead(pinButtonUp))==1 && flagButton == 1){
      Serial.println("Sobe\n");
      valueButtonUp = 0;
    }
      flagButton = 0;
      delay(1); 
    while((valueButtonDown = digitalRead(pinButtonDown))==1 && flagButton == 0){
      Serial.println("Desce\n");
      valueButtonDown = 0;
    }
    delay(1);
}
void playerOne(int valuePot){
  if(valuePot != flagPot){
    flagPot = valuePot;
    Serial.print("Player2 ");
    Serial.print(valuePot);
    Serial.print("\n");
  }
}
