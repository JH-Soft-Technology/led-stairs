/* Number of used registers */
int numOfRegisters = 2;
/* Number of staris */
int numberOfStairs = 16;

int blueLed = 10;
int greenLed = 9;

int dataPin = 2; /* Atmega 328P pin 32 */
int latchPin = 7; /* Atmega 328P pin 11 */
int clockPin = 8; /* Atmega 328P pin 12 */

/* Light sensor */
unsigned int lightSensorPin = A2; /* Atmega328P pin 25 */

/* motion sensors upstairs and downstairs */
int sensorDownstairs = 6; /* Atmega 328P pin 10 */
int sensorUpstairs = 4; /* Atmega 328P pin 2 */

/* speeds */
int speedUp = 250;
int speedDown = 200;

/* lights turn on for some time in miliseconds */
int lightsOnDelay = 10000;

byte *registerState;

// when move is captured then do the action
bool hasMoved = false;
bool wasDownToUp = false;
bool wasUpToDown = false;

void setup()
{
  Serial.begin(9600);
  // setup registers
  registerState = new byte[numOfRegisters];
  for (size_t i = 0; i < numOfRegisters; i++)
  {
    registerState[i] = 0;
  }

  // setup pins
  pinMode(sensorDownstairs, INPUT);
  pinMode(sensorUpstairs, INPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  digitalWrite(greenLed, HIGH);  
}

/**
 * Reed motion sensors upstairs and downstairs
 * When move is detected wherever upstairs or downstairs
 * turn the lighs on
 *
 * When lights are turning on from downstairs to upstaris then
 * turning them off is from the same direction and vice versa.
 */
void loop()
{
  // read the sensors
  int motionUp = digitalRead(sensorUpstairs); // move from downstairs to upstairs
  int motionDown = digitalRead(sensorDownstairs); // move from upstairs to downstairs
  int lightSensor = analogRead(lightSensorPin); // get the light sensitivity

  Serial.print("Light level: ");
  Serial.println(lightSensor);
  Serial.print("MotionUP: ");
  Serial.println(motionUp);
  Serial.print("MotionDown: ");
  Serial.println(motionDown);

  // when motion it does not metter where
  // marke as hasMoved
  if ((motionUp || motionDown) /*&& lightSensor > 200*/)
  {    
    Serial.print("Moving changing from ");
    Serial.print(hasMoved);
    hasMoved = true;
    Serial.print(" to ");
    Serial.println(hasMoved);
  }

  if (hasMoved)
  {
    digitalWrite(blueLed, HIGH);
    if (motionUp)
    {      
      Serial.println("Turning on from downsatirs");
      turnOnFromDownstairs(speedUp);
      wasDownToUp = true;
    }
    if (motionDown)
    {
      Serial.println("Turning on from upstairs");
      turnOnFromUpstairs(speedUp);
      wasUpToDown = true;
    }

    Serial.print("Moving changing from ");
    Serial.print(hasMoved);
    hasMoved = false;
    Serial.print(" to ");
    Serial.println(hasMoved);
    
    delay(lightsOnDelay);
  }
  else
  {
    if (wasDownToUp)
    {
      Serial.println("Turning off from downstairs");
      turnOffFromDownstairs(speedDown);
      wasDownToUp = false;
      digitalWrite(blueLed, LOW);
    }
    if (wasUpToDown)
    {
      Serial.println("Turning off from upstairs");
      turnOffFromUpstairs(speedDown);
      wasUpToDown = false;
      digitalWrite(blueLed, LOW);
    }
  }
}

/**
 * Turn the lights off from upstairs
 * @param effectSpeed - speed of lights bringing off
 */
void turnOffFromUpstairs(int effectSpeed)
{
  changeState(effectSpeed, LOW, false);
}

/**
 * Turn the lights on from upstairs
 * @param effectSpeed - speed of lights bringing on
 */
void turnOnFromUpstairs(int effectSpeed)
{
  changeState(effectSpeed, HIGH, false);
}

/**
 * Turn the lights off from downdstairs
 * @param effectSpeed - speed of lights bringing off
 */
void turnOffFromDownstairs(int effectSpeed)
{
  changeState(effectSpeed, LOW, true);
}

/**
 * Turn the lights on from downdstairs
 * @param effectSpeed - speed of lights bringing on
 */
void turnOnFromDownstairs(int effectSpeed)
{
  changeState(effectSpeed, HIGH, true);
}

/**
 * Method changing state of lights
 * @param effectSpeed - int speed in miliseconds
 * @param state  - HIGH / LOW
 * @param directionUp - when True then lights direction is from Down to Up
 * when False then direction from Up to Down
 */
void changeState(int effectSpeed, bool state, bool directionUp)
{
  if (directionUp)
  {
    for (int i = 0; i < numberOfStairs; i++)
    {
      regWrite(i, state);
      delay(effectSpeed);
    }
  }
  else
  {
    for (int i = numberOfStairs; i >= 0; i--)
    {
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
void regWrite(int pin, bool state)
{
  int reg = pin / 8;
  int actualPin = pin - (8 * reg);

  digitalWrite(latchPin, LOW);

  for (int i = numOfRegisters; i >= 0; i--)
  {
    byte *states = &registerState[i];

    if (i == reg)
    {
      bitWrite(*states, actualPin, state);
    }
    shiftOut(dataPin, clockPin, MSBFIRST, *states);
  }
  digitalWrite(latchPin, HIGH);
}
