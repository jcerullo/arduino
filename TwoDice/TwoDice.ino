// Dice
// Original by Charles Platt
// Modified for WeMos D1 Mini by JJC: 
// D4 is a normal WeMos pullup; trying to use a non-pullup pin as input did not seem to work.
// Delays in checkbutton() were required because it seems that WeMos does very fast pin testing
//  at all times, so that the while statements cannot be trusted without a delay.

int i = 0;
int spots = 0;              //     Spots to display
long ignore = 0;            //     When to stop ignoring the button 

void setup() {
  pinMode(D4, INPUT_PULLUP);  //Input current
  pinMode(D1, OUTPUT);        //Dice 1 pins
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);        //Dice 2 pins
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D0, OUTPUT);
  ignore = 2000 + millis();
}

void loop() {

  for (i=0; i<11; i++) {
    
  // Blank dice 1 LEDs
    digitalWrite (D1, LOW);
    digitalWrite (D2, LOW);
    digitalWrite (D3, LOW);
    digitalWrite (D5, LOW);

  // Pick a random number from 1 - 6
  spots = random(1,7);

  // Display the appropriate spot pattern
  if (spots == 6)
    {digitalWrite(D1, HIGH);}  // Side pair of spots

  if (spots == 1 || spots == 3 || spots == 5)
    {digitalWrite(D2, HIGH);}  // Center spot

  if (spots > 3)
    {digitalWrite(D3, HIGH);}  // Diagonal spots, left

  if (spots > 1)
    {digitalWrite(D5, HIGH);}  // Diagonal spots, right

  // Add a small delay for a pleasing display speed  
  delay (20);

  // Blank dice 2 LEDs
    digitalWrite (D6, LOW);
    digitalWrite (D7, LOW);
    digitalWrite (D8, LOW);
    digitalWrite (D0, LOW);

  // Pick a random number from 1 - 6
  spots = random(1,7);

  // Display the appropriate spot pattern
  if (spots == 6)
    {digitalWrite(D6, HIGH);}  // Side pair of spots

  if (spots == 1 || spots == 3 || spots == 5)
    {digitalWrite(D7, HIGH);}  // Center spot

  if (spots > 3)
    {digitalWrite(D8, HIGH);}  // Diagonal spots, left

  if (spots > 1)
    {digitalWrite(D0, HIGH);}  // Diagonal spots, right

  // Add a small delay for a pleasing display speed
  delay (20);
  
  }  //end for
  
  // After 2 seconds have passed, stop ignoring the button.
  if (millis() > ignore)
    {checkbutton();}
    
}  //end loop

// This function waits for the button to be released,
// then waits for it to be pressed to start the next run.

void checkbutton()
{
  delay (50);                     // Button pressed; debounce.
  while (digitalRead(D4) == LOW)  // While button is pressed
   {delay (50);}                             // Do nothing while waiting
  delay (50);                     // Button released; debounce

  while (digitalRead(D4) == HIGH) // While button is released
   {delay (50);}                             // Do nothing while waiting
  ignore = 2000 + millis();       // Set new ignore time
}                                 // Return to the main loop 
