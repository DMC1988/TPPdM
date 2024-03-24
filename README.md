# Microprocessor programming: Final project
Final work for the subject Microprocessor Programming for the Specialization in Embedded Systems at FIUBA.

### Alumn: Damián Caputo
### Platafor: EDU-CIAA-NXP
## Aplicaction:
The firmware controls a display that displays a 3-option menu. The menu is navigated through the action of two buttons and a third acts as an enter button.
1. Settings Int: The user sets the number of training intervals (maximum 5), interval time (maximum 3) and rest time between intervals (maximum 60s).
Upon accepting the configuration, the device displays a screen with the current interval, the countdown of the remaining interval time and the rest time,
also in countdown.
2. Temp and HR.: The LCD display shows the ambient temperature and the measured relative humidity.
3. Battery Measurement: The display shows the battery voltage. If it measures a voltage lower than 2.7V, a low battery warning is displayed on the screen and the red LED lights up.
After the warning, return to the main menu by pressing the enter button when the voltage is greater than 2.7V.

## Peripherals:
GPIO, ADC, TIMER.

## States description:
Presentation: Displays the project title on the screen for 3 s.

MainMenu: Displays 3 options on the screen that can be selected using the keyboard:
1. *Settings Int.*
2. *Temp. and HR.*
3. *Med. Battery*

- **MenuConfigInterval:** Displays on the screen the option to set the number of intervals, interval time and time between intervals using the keyboard.
- **Count Screen:** Displays the current interval, the countdown of the interval time and the rest time, also in countdown. During the interval time the green LED flashes and during the rest time the yellow LED flashes.
- **IntervalCount:** 1 s timing routine and periodic display update.
- **Screen Temp. and humidity:** Displays the measured temperature and humidity.
- **TemperatureAndHumidity:** Routine to measure temperature and humidity.
- **Battery Voltage:** Displays the temperature voltage.
- **Battery measurement:** Routine to measure battery voltage.
- 
## Software modules
TPPdM.c and TPPdM.h, contain the state machine and state variables.

MenuLCD.c and MenuLCD.h contain the menus and variables associated with them.

Functions.c and functions.h, contain functions for timing and measuring physical quantities.

### MenuLCD.h

\brief Presents the main on-screen menu on the LCD and manages the selection of functions

*estadoLCD MenuPrincipalLCD(void);*

\brief Presents the temperature and humidity on the LCD screen..

*estadoLCD TempHRLCD(struct THRm);*

\brief Displays the low battery message on the LCD.

*void MsgBateriaBajaLCD(void);*

\brief Presents the battery voltage measurement on the LCD.
 
*estadoLCD VBatLCD(float);*

\brief Presents the training time configuration on the LCD screen and manages the selection of times using the buttons.

*struct tiempos ConfiguracionInternavalo(void);*


### Funciones.h

\brief Displays the title of the project and the name of the student on LCD

*void LCDPresentacion(void);*

\brief Measures temperature and humidity through the DHT11.

*struct THRm medicionTHR(void);*

\brief Detects low battery.

*bool_t EstaBateriaBaja(void);*

\brief Function that displays and counts training times.

*estadoLCD TemporzacionIntervalo(struct tiempos);*

\brief Pushbutton debounce function.

*bool_t debounce(gpioMap_t );*

\brief Function to time one second.
*void BasedeTiempo();*
