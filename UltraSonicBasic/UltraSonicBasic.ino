//the simple code for the ultra sonic sensor.

int trigg = 9;
int echo = 10;
int buzz = 13;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
pinMode(trigg , OUTPUT);
pinMode(echo , INPUT);
pinMode(buzz , OUTPUT);
Serial.begin(9600);
}

void loop() {
  // initially the trigg should be off so to make sure that this is done.
  digitalWrite(trigg , LOW);
  delayMicroseconds(2);

  digitalWrite(trigg , HIGH);
  delayMicroseconds(10);
  digitalWrite(trigg , LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;
  Serial.print("DISTANCE:");
  Serial.println(distance);
  if(distance < 25)
  {
    digitalWrite( buzz, HIGH);
    delay(50);
    digitalWrite( buzz, LOW);
    }
   if(distance > 25 && distance < 40)
   {
    digitalWrite( buzz, HIGH);
    delay(500);
    digitalWrite( buzz, LOW);
    } 
    else
    digitalWrite( buzz, LOW );
    delay(1000);
}
