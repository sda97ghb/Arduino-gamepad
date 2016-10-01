void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(12, INPUT);
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
  pinMode(10, INPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int y1 = map(analogRead(0), 0, 1023, -100, 100);
  int x1 = map(analogRead(1), 0, 1023, -100, 100);
  int y2 = map(analogRead(2), 0, 1023, -100, 100);
  int x2 = map(analogRead(3), 0, 1023, -100, 100);

  String toSend = "";
  toSend += x1;
  toSend += ' ';
  toSend += y1;
  toSend += ' ';
  toSend += x2;
  toSend += ' ';
  toSend += y2;
  toSend += ' ';
  toSend += (digitalRead(10) == HIGH ? 1 : 0);
  toSend += ' ';
  toSend += (digitalRead(8) == HIGH ? 1 : 0);
  toSend += '\n';
  
  Serial.write(toSend.c_str());
  delay(50);
}

