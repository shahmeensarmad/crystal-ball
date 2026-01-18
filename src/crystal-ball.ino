// Project - Crystal Ball
  // Create a crystal ball to tell your future// Personal Project Ideas: Pomodoro Timer, Music Player, Realy anything to do with LCD displays
  // Note: Tilt switch helps replicate the motion of shaking the ball for answers

// set up the LiquidCrystal library (import + initialize)
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // which pins it will be using to communicate

// constants and variables
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  // put your setup code here, to run once:

  lcd.begin(16,2);  // how big the lcd is, 16 columns, 2 rows                                                                                                                                                                                                                                
  pinMode(switchPin, INPUT);

  lcd.print("Ask the"); // print first line
  
  lcd.setCursor(0,1);  // where the cursor should start now (first column, second line)
  lcd.print("Crystal Ball!");
}

void loop() {
  // put your main code here, to run repeatedly:

  switchState = digitalRead(switchPin);

  // if switchState is different then below and is currently LOW, then choose a random number between 0-7
  if (switchState != prevSwitchState){
    if (switchState == LOW){
      reply = random(8); // number between 0-7


    lcd.clear();  // clears the screen, automatically sets the cursor back to (0,0)
    // DON'T NEED: lcd.setCursor(0, 0);  // set cursor back to first column, first line
    lcd.print("The ball says: ");
    lcd.setCursor(0,1);

  // switch() statement executes different pieces of code depending on the value you give it, each different piece of code is called a case
    // basically a bunch of if/ else if statements
    // switch(variable) checks the value of the variable (in this case, reply)
    // case #, where # = value of the variable
      switch(reply){
        case 0:
        lcd.print("Yes");                                                                               
        break;
        case 1:
        lcd.print("Most likely");
        break;
        case 2:
        lcd.print("Certainly");
        break;
        case 3:
        lcd.print("Outlook good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask again");
        break;
        case 6:
        lcd.print("Doubtful");
        break;
        case 7:
        lcd.print("No");
        break;
      }
    }
  }  
  prevSwitchState = switchState;
}
