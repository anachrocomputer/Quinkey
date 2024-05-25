/* Quinkey --- read chords from Quinkey chord keyboard      2017-06-28 */
/* Copyright (c) John Honniball 2017-2024. All rights reserved.        */


void setup(void)
{
  Serial.begin(9600);
  Serial.println("QUINKEY!");
}


void loop(void)
{
  int buttons;
  int chord;

  do {
    buttons = analogRead(0) >> 4;
    delay(20);
  } while (buttons == 0);

  chord = buttons;
  
  do {
    buttons = getStableButtons();

    if (buttons != 0)
      chord = buttons;
  } while (buttons != 0);

  Serial.print("Chord is ");
  Serial.println(chord, DEC);
}


int getStableButtons(void)
{
  int oldb, newb;
  long int start, elapsed;

  start = millis();
  oldb = averagedAnalogRead(0, 2) >> 4;
  
  do {
    newb = averagedAnalogRead(0, 2) >> 4;

    if (oldb != newb) {
      oldb = newb;
      start = millis();
    }

    elapsed = millis() - start;
  } while (elapsed < 100);

  return (oldb);
}


int averagedAnalogRead(int pin, int n)
{
  int i;
  int avg = 0;

  for (i = 0; i < n; i++)
    avg += analogRead(pin);

  return (avg / n);
}
