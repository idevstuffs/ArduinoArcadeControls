#include <Keypad.h>

const byte ROWS = 2; //two rows (two players)
const byte COLS = 8; //seven columns (seven buttons)

char keys[ROWS][COLS] = {
  {'Z','X','C','V','B','N','M', 'N'},
  {'A','S','D','F','G','H','J', 'O'}
};

byte rowPins[ROWS] = {2, 3}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {4, 5, 6, 7, 8, 9, 10, 11}; //connect to the column pinouts of the kpd

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
    Keyboard.begin();
}

void loop() {
    if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if (kpd.key[i].stateChanged)   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                        Keyboard.press(kpd.key[i].kchar);
                        break;
                    case HOLD:

                        break;
                    case RELEASED:
                        Keyboard.release(kpd.key[i].kchar);
                        break;
                    case IDLE:

                        break;
                }
            }
        }
    }
}
