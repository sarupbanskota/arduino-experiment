/* stuff that won't change */
const int redLight = 4;
const int whiteLight = 3;
const int button = 9;
const int trigger = 13;
const int echo = 12;

void setup() {
  // put your setup code here, to run once:
  // UV dude
  Serial.begin (9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(redLight, OUTPUT);

  // alert dude
  pinMode(button, INPUT);
  pinMode(whiteLight, OUTPUT);
}

void loop() {
    int buttonState = 0; // pushbutton state
    // stuff that I don't want to bother with - for UV dude  
    long duration, distance;
    digitalWrite(trigger, LOW);  
    delayMicroseconds(2); 
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    duration = pulseIn(echo, HIGH);
    distance = (duration / 2) / 29.1;

    if (distance < 5) { 
      digitalWrite(redLight, HIGH); 
      // # TODO beep here
    }
    else{
      digitalWrite(redLight, LOW);
    }
    if (distance >= 200 || distance <= 0) {
      Serial.println("Out of range");
    }
    else {
      Serial.print(distance);
      Serial.println(" cm");
    }
  delay(500);


  // button push logic
  // read the state of the pushbutton value:
  buttonState = digitalRead(button);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    digitalWrite(whiteLight, HIGH);
  } else {
    digitalWrite(whiteLight, LOW);
  }

}
