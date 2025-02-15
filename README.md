Digital Clock with I2C RTC using LPC2129 and 16x2 LCD
======================================================
> This project is a simple Digital Clock built using the LPC2129 microcontroller, a 16x2 LCD, I2Cbased RTC (RealTime Clock), and switches for time setting. 
> It demonstrates how to interface an RTC module with the LPC2129 for accurate timekeeping and display it on an LCD screen.

=> Features:
> Displays current time (hours, minutes, seconds) on a 16x2 LCD.
> Uses I2C RTC module (e.g., DS3231 or similar) for accurate timekeeping.
> User can set the time through physical push buttons (e.g., for hours, minutes, and seconds).
> LCD communicates with the LPC2129 via I2C for efficient data transfer.
> Easy to use with minimal external components.

=> Components Used:
> LPC2129 Microcontroller: 32bit ARM7based MCU.
> 16x2 LCD: Used to display the current time.
> I2C RTC Module: Provides accurate realtime clock functionality (e.g., DS3231).
> Push Buttons: Used for setting the time.
> Resistors & Capacitors: For button debouncing and proper circuit functioning.

=> Working:
1. Initialization: On powerup, the LPC2129 communicates with the RTC module over I2C to read the current time and displays it on the LCD.
2. User Interaction: The user can adjust the time using physical switches. Each switch is mapped to either hour, minute, or second adjustments.
3. RealTime Clock: The RTC module maintains time continuously, even when the system is powered down, as it has a backup battery.
4. LCD Display: The 16x2 LCD continuously updates to display the current time in the format `HH:MM:SS`.

=> How to Use:
1. Power up the circuit.
2. The current time will be displayed on the LCD.
3. Press the set time switches to adjust hours, minutes, and seconds.
4. The clock will continue updating, and time will be saved in the RTC module even if power is lost.

 Installation:
1. Download the repository.
2. Open the project in your preferred IDE.
3. Upload the code to the LPC2129.
4. Ensure the RTC module is properly connected via I2C.

Feel free to adjust it according to any specific details or modifications you've made to the project!
