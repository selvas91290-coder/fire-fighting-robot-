#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5

#define ir_R A0
#define ir_F A1
#define ir_L A2

#define servo A4
#define pump A5

int Speed = 160;

int s1, s2, s3;

// =================================================
// Flame Sensor Reading with Averaging
// =================================================
int readFlame(int pin)
{
  long total = 0;

  for (int i = 0; i < 10; i++)
  {
    total += analogRead(pin);
    delay(2);
  }

  return total / 10;
}

// =================================================
// SETUP
// =================================================
void setup()
{
  Serial.begin(9600);

  // Flame sensors
  pinMode(ir_R, INPUT);
  pinMode(ir_F, INPUT);
  pinMode(ir_L, INPUT);

  // Motor driver
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Servo and pump
  pinMode(servo, OUTPUT);
  pinMode(pump, OUTPUT);

  // Initial pump OFF
  digitalWrite(pump, LOW);

  // Initial motor STOP
  Stop();

  // Set motor speed
  analogWrite(enA, Speed);
  analogWrite(enB, Speed);

  // =================================================
  // Initial Servo Sweep
  // =================================================
  for (int angle = 90; angle <= 140; angle += 5)
  {
    servoPulse(servo, angle);
  }

  for (int angle = 140; angle >= 40; angle -= 5)
  {
    servoPulse(servo, angle);
  }

  for (int angle = 40; angle <= 90; angle += 5)
  {
    servoPulse(servo, angle);
  }

  delay(500);
}

// =================================================
// MAIN LOOP
// =================================================
void loop()
{
  // Read flame sensors
  s1 = readFlame(ir_R);
  s2 = readFlame(ir_F);
  s3 = readFlame(ir_L);

  // Display sensor values
  Serial.print("Right: ");
  Serial.print(s1);

  Serial.print("  Front: ");
  Serial.print(s2);

  Serial.print("  Left: ");
  Serial.println(s3);

  // =================================================
  // FIRE DETECTION
  // =================================================

  // RIGHT FLAME
  if (s1 < 150)
  {
    Stop();

    // Pump ON
    digitalWrite(pump, HIGH);

    // Servo sweep right side
    for (int angle = 90; angle >= 40; angle -= 3)
    {
      servoPulse(servo, angle);
    }

    for (int angle = 40; angle <= 90; angle += 3)
    {
      servoPulse(servo, angle);
    }
  }

  // FRONT FLAME
  else if (s2 < 180)
  {
    Stop();

    // Pump ON
    digitalWrite(pump, HIGH);

    // Servo sweep
    for (int angle = 90; angle <= 140; angle += 3)
    {
      servoPulse(servo, angle);
    }

    for (int angle = 140; angle >= 40; angle -= 3)
    {
      servoPulse(servo, angle);
    }

    for (int angle = 40; angle <= 90; angle += 3)
    {
      servoPulse(servo, angle);
    }
  }

  // LEFT FLAME
  else if (s3 < 150)
  {
    Stop();

    // Pump ON
    digitalWrite(pump, HIGH);

    // Servo sweep left side
    for (int angle = 90; angle <= 140; angle += 3)
    {
      servoPulse(servo, angle);
    }

    for (int angle = 140; angle >= 90; angle -= 3)
    {
      servoPulse(servo, angle);
    }
  }

  // =================================================
  // MOVEMENT
  // =================================================

  // RIGHT SENSOR DETECTS OBJECT/CONDITION
  else if (s1 >= 200 && s1 <= 700)
  {
    digitalWrite(pump, LOW);

    backword();
    delay(100);

    turnRight();
    delay(200);
  }

  // FRONT SENSOR
  else if (s2 >= 200 && s2 <= 800)
  {
    digitalWrite(pump, LOW);

    forword();
  }

  // LEFT SENSOR
  else if (s3 >= 200 && s3 <= 700)
  {
    digitalWrite(pump, LOW);

    backword();
    delay(100);

    turnLeft();
    delay(200);
  }

  // NO DETECTION
  else
  {
    digitalWrite(pump, LOW);
    Stop();
  }

  delay(10);
}

// =================================================
// SERVO FUNCTION
// =================================================
void servoPulse(int pin, int angle)
{
  int pwm = (angle * 11) + 500;

  digitalWrite(pin, HIGH);
  delayMicroseconds(pwm);

  digitalWrite(pin, LOW);
  delay(50);
}

// =================================================
// MOTOR FUNCTIONS
// =================================================

// FORWARD
void forword()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

// BACKWARD
void backword()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// TURN RIGHT
void turnRight()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

// TURN LEFT
void turnLeft()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// STOP
void Stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}