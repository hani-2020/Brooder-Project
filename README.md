# Smart Brooder System

This is a **Smart Brooder** system designed to automate temperature control for poultry hatcheries using an Arduino-compatible board. The system monitors temperature in real-time, automatically adjusts heating, lighting, and fan control to maintain ideal conditions for the brooder. It uses an OLED display to show real-time temperature data and system status.

## Features

- **Real-time Temperature Monitoring**: Uses a Dallas DS18B20 temperature sensor to continuously monitor the brooder temperature.
- **Automated Heating and Cooling**: Automatically controls a heater, fan, and light to maintain optimal temperature ranges.
- **OLED Display**: Displays current temperature, low/high thresholds, and system status on a 128x64 OLED screen.
- **Fan Control**: Includes a master fan and an in-out fan for air circulation, controlled based on the temperature.
- **Multiple Temperature Sensors**: Supports two additional analog temperature sensors for monitoring low and high temperature thresholds.
  
## Components

- **Arduino-compatible Board**
- **Dallas DS18B20 Temperature Sensor**
- **OLED Display (SSD1306)**
- **Fans (Master and In-out fan)**
- **Heater**
- **Light**
- **Resistors, Cables, and Power Supply**

## Wiring

| Component          | Pin         | Description                            |
|--------------------|-------------|----------------------------------------|
| Dallas DS18B20      | Pin 2       | OneWire bus for temperature sensor     |
| Master Fan          | Pin 6       | Main fan control                       |
| In-out Fan          | Pin 5       | Ventilation fan control                |
| Light               | Pin 8       | Brooder lighting control               |
| Heater              | Pin 3       | Heater control                         |
| Reset Pin           | Pin 9       | Reset control for the pulse mechanism  |
| Analog Low Temp     | A2          | Analog input for low temp sensor       |
| Analog High Temp    | A3          | Analog input for high temp sensor      |
| OLED Reset          | Pin 4       | Reset pin for the OLED display         |

## Installation

1. **Clone the Repository**:
   ```
   git clone https://github.com/hani-2020/Brooder-Project.git
   ```
2. **Install Required Libraries**:
   - [OneWire](https://github.com/PaulStoffregen/OneWire)
   - [DallasTemperature](https://github.com/milesburton/Arduino-Temperature-Control-Library)
   - [Adafruit GFX](https://github.com/adafruit/Adafruit-GFX-Library)
   - [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)

   Install these libraries in your Arduino IDE via **Library Manager**.

3. **Upload the Code**: Open the `.ino` file in the Arduino IDE and upload it to your board.

## Usage

1. After setup, the system will automatically:
   - Start monitoring temperature using the DS18B20 sensor.
   - Display real-time temperature values on the OLED display.
   - Control the heater, fans, and lighting to maintain optimal temperature levels for the brooder.
   
2. **Low/High Temperature Control**: 
   - The system will turn on the heater and light when the temperature is below the lower threshold.
   - The fans will turn on if the temperature exceeds the higher threshold.

3. **OLED Display**: 
   - Low temperature, high temperature, and current temperature will be displayed in real time.

## Customization

You can adjust the **low_temp_raw** and **high_temp_raw** thresholds by modifying the analog readings from `A2` and `A3` to fine-tune the temperature ranges suitable for your brooder.

## Future Improvements

- Add support for remote monitoring using WiFi or Bluetooth.
- Integrate a mobile app for easier control and notifications.
- Make a more advanced air conditioning system.
