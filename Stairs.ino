/* Number of used registers */
int numOfRegisters = 2;
/* Number of staris */
int numberOfStairs = 16;

int dataPin = 5;
int latchPin = 6;
int clockPin = 7;

/* motion sensors upstairs and downstairs */
int sensorDownstairs = 2;
int sensorUpstairs = 3;

/* speeds */
int speedUp = 350;
int speedDown = 200;

/* lights turn on for some time in miliseconds */
int lightsOnDelay = 10000;

byte* registerState;

// when move is captured then do the action
bool hasMoved = false; 
bool wasDownToUp = false;
bool wasUpToDown = false;

void setup() {
  // setup registers  
  registerState  = new byte[numOfRegisters];
  for(size_t i = 0; i < numOfRegisters; i++) {
    registerState[i] = 0;
  }

  // setup pins
  pinMode(sensorDownstairs, INPUT);
  pinMode(sensorUpstairs, INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

/**
 * Reed motion sensors upstairs and downstairs
 * When move is detected wherever upstairs or downstairs 
 * turn the lighs on
 * 
 * When lights are turning on from downstairs to upstaris then
 * turning them off is from the same direction and vice versa.
 */
void loop() {  
  // read the sensors  
  int motionUp = digitalRead(sensorDownstairs); // move from downstairs to upstairs
  int motionDown = digitalRead(sensorUpstairs); // move from upstairs to downstairs  
  
  // when motion it does not metter where
  // marke as hasMoved
  if (motionUp || motionDown) {
    hasMoved = true;
  }
  
  if (hasMoved) {    
    if (motionUp) {
      turnOnFromDownstairs(speedUp);
      wasDownToUp = true;    
    }
    if (motionDown) {
      turnOnFromUpstairs(speedUp);  
      wasUpToDown = true;
    }
    hasMoved = false;    
    delay(lightsOnDelay);
  } else {    
    if (wasDownToUp) {
      turnOffFromDownstairs(speedDown);
      wasDownToUp = false;
    }
    if (wasUpToDown) {
      turnOffFromUpstairs(speedDown);
      wasUpToDown = false; 
    }
  } 
}

/**
 * Turn the lights off from upstairs
 * @param effectSpeed - speed of lights bringing off
 */
void turnOffFromUpstairs(int effectSpeed) {
  changeState(effectSpeed, LOW, false);  
}

/**
 * Turn the lights on from upstairs
 * @param effectSpeed - speed of lights bringing on
 */
void turnOnFromUpstairs(int effectSpeed) {
  changeState(effectSpeed, HIGH, false);
}

/**
 * Turn the lights off from downdstairs
 * @param effectSpeed - speed of lights bringing off
 */
void turnOffFromDownstairs(int effectSpeed) {
  changeState(effectSpeed, LOW, true);
}

/**
 * Turn the lights on from downdstairs
 * @param effectSpeed - speed of lights bringing on
 */
void turnOnFromDownstairs(int effectSpeed) {
  changeState(effectSpeed, HIGH, true);
}

/**
 * Method changing state of lights 
 * @param effectSpeed - int speed in miliseconds
 * @param state  - HIGH / LOW
 * @param directionUp - when True then lights direction is from Down to Up 
 * when False then direction from Up to Down
 */
void changeState(int effectSpeed, bool state, bool directionUp) {
  if (directionUp) {  
    for(int i = 0; i < numberOfStairs; i++) {
      regWrite(i, state);
      delay(effectSpeed);
    }
  } else {
    for(int i = numberOfStairs; i >= 0; i--) {
      regWrite(i, state);
      delay(effectSpeed);
    }
  }
}

/**
 * Method write to the shift register
 * @param pin - pin position where to write state
 * @param state - state to write HIGH / LOW
 */
void regWrite(int pin, bool state) {
  int reg = pin / 8;
  int actualPin = pin - (8 * reg);

  digitalWrite(latchPin, LOW);
  
  for (int i = numOfRegisters; i >= 0 ; i--) {
    byte* states = &registerState[i];

    if (i == reg) {
      bitWrite(*states, actualPin, state);
    }
    shiftOut(dataPin, clockPin, MSBFIRST, *states);
  }
  digitalWrite(latchPin, HIGH);
}
