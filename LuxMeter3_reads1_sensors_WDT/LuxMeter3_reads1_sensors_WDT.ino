#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
#include <avr/wdt.h>



/* This driver uses the Adafruit unified sensor library (Adafruit_Sensor),
   which provides a common 'type' for sensor data and some helper functions.
   
   To use this driver you will also need to download the Adafruit_Sensor
   library and include it in your libraries folder.

   You should also assign a unique ID to this sensor for use with
   the Adafruit Sensor API so that you can identify this particular
   sensor in any data logs, etc.  To assign a unique ID, simply
   provide an appropriate value in the constructor below (12345
   is used by default in this example).
   
   Connections
   ===========
   Connect SCL to analog 5
   Connect SDA to analog 4
   Connect VDD to 3.3V DC
   Connect GROUND to common ground

   I2C Address
   ===========
   The address will be different depending on whether you leave
   the ADDR pin floating (addr 0x39), or tie it to ground or vcc. 
   The default addess is 0x39, which assumes the ADDR pin is floating
   (not connected to anything).  If you set the ADDR pin high
   or low, use TSL2561_ADDR_HIGH (0x49) or TSL2561_ADDR_LOW
   (0x29) respectively.
    
   History
   =======
   2013/JAN/31  - First version (KTOWN)
*/
   
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
Adafruit_TSL2561_Unified tsl2 = Adafruit_TSL2561_Unified(TSL2561_ADDR_HIGH, 12346);
//Adafruit_TSL2561_Unified tsl3 = Adafruit_TSL2561_Unified(TSL2561_ADDR_LOW, 12347);



/**************************************************************************/
/*
    Displays some basic information on this sensor from the unified
    sensor API sensor_t type (see Adafruit_Sensor for more information)
*/
/**************************************************************************/

int intValue;
int intValue2;
int checksum;
byte hi1, low1, hi2,low2;


int intValueb;
int intValue2b;
int checksumb;
byte hi1b, low1b, hi2b,low2b;

int intValuec;
int intValue2c;
int checksumc;
byte hi1c, low1c, hi2c,low2c;







void displaySensorDetails(void)
{
  sensor_t sensor;
  tsl.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" lux");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" lux");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" lux");  
  Serial.println("------------------------------------");
  Serial.println("");
  
  
//   sensor_t sensor2;
//  tsl2.getSensor(&sensor2);
//  Serial.println("------------------------------------");
//  Serial.print  ("Sensor:       "); Serial.println(sensor2.name);
//  Serial.print  ("Driver Ver:   "); Serial.println(sensor2.version);
//  Serial.print  ("Unique ID:    "); Serial.println(sensor2.sensor_id);
//  Serial.print  ("Max Value:    "); Serial.print(sensor2.max_value); Serial.println(" lux");
//  Serial.print  ("Min Value:    "); Serial.print(sensor2.min_value); Serial.println(" lux");
//  Serial.print  ("Resolution:   "); Serial.print(sensor2.resolution); Serial.println(" lux");  
//  Serial.println("------------------------------------");
//  Serial.println("");
// 
  
//  sensor_t sensor3;
//  tsl3.getSensor(&sensor3);
//  Serial.println("------------------------------------");
//  Serial.print  ("Sensor:       "); Serial.println(sensor3.name);
//  Serial.print  ("Driver Ver:   "); Serial.println(sensor3.version);
//  Serial.print  ("Unique ID:    "); Serial.println(sensor3.sensor_id);
//  Serial.print  ("Max Value:    "); Serial.print(sensor3.max_value); Serial.println(" lux");
//  Serial.print  ("Min Value:    "); Serial.print(sensor3.min_value); Serial.println(" lux");
//  Serial.print  ("Resolution:   "); Serial.print(sensor3.resolution); Serial.println(" lux");  
//  Serial.println("------------------------------------");
//  Serial.println("");
//  delay(1000);
  
  
  
}

/**************************************************************************/
/*
    Configures the gain and integration time for the TSL2561
*/
/**************************************************************************/
void configureSensor(void)
{
  /* You can also manually set the gain or enable auto-gain support */
  // tsl.setGain(TSL2561_GAIN_1X);      /* No gain ... use in bright light to avoid sensor saturation */
  // tsl.setGain(TSL2561_GAIN_16X);     /* 16x gain ... use in low light to boost sensitivity */
  tsl.enableAutoRange(true);            /* Auto-gain ... switches automatically between 1x and 16x */
//  tsl2.enableAutoRange(true); 
  //tsl3.enableAutoRange(true);  
  
  /* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
  //tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* 16-bit data but slowest conversions */
//  tsl2.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);
//  tsl3.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);

  /* Update these values depending on what you've set above! */  
//  Serial.println("------------------------------------");
//  Serial.print  ("Gain:         "); Serial.println("Auto");
//  Serial.print  ("Timing:       "); Serial.println("13 ms");
//  Serial.println("------------------------------------");
//  
 //
  //tsl.enableAutoRange(true);            /* Auto-gain ... switches automatically between 1x and 16x */
    /* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
  //tsl2.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */

  /* Update these values depending on what you've set above! */  
//  Serial.println("------------------------------------");
//  Serial.print  ("Gain:         "); Serial.println("Auto");
//  Serial.print  ("Timing:       "); Serial.println("13 ms");
//  Serial.println("------------------------------------"); 
//   
//  
//  /* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
//  tsl3.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
//  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
//  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */
  /* Update these values depending on what you've set above! */  
//  Serial.println("------------------------------------");
//  Serial.print  ("Gain:         "); Serial.println("Auto");
//  Serial.print  ("Timing:       "); Serial.println("13 ms");
//  Serial.println("------------------------------------"); 
//  
  
}

/**************************************************************************/
/*
    Arduino setup function (automatically called at startup)
*/
/**************************************************************************/
void setup(void) 
{
  Serial.begin(9600);
 
  //wdt_enable(WDTO_8S);  // reset after one second, if no "pat the dog" receive
  Serial.println("Light Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!tsl.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.print("Ooops, no TSL2561 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  /* Display some basic information on this sensor */
  displaySensorDetails();
  
  /* Setup the sensor gain and integration time */
  configureSensor();
  
  /* We're ready to go! */
  Serial.println("");
}

/**************************************************************************/
/*
    Arduino loop function, called once 'setup' is complete (your own code
    should go here)
*/
/**************************************************************************/
void loop(void) 
{  
  
  delay(470);
  /* Get a new sensor event */ 
  sensors_event_t event;
  sensors_event_t event2;
  //sensors_event_t event3;
  
  tsl.getEvent(&event);
  tsl2.getEvent(&event2);
  //tsl3.getEvent(&event3);
  
  
  
  /* Display the results (light is measured in lux) */
  if (event.light)
  {
    Serial.print(event.light); Serial.println(" lux");
    //Serial.print(event2.light); Serial.println(" lux");
    //Serial.print(event3.light); Serial.println(" lux");
    int reading = event.light;
    int readingb = event2.light;
    //int readingc = event3.light;
    
    
    Serial.print(reading);
    if (reading <0){
      reading = 0;
    }
    intValue = reading&0xFF; // get the value of the lower 8 bits
    low1 = lowByte(intValue);
    hi1 = highByte(intValue);
    
    intValue2 = reading>>8; // get the value of thehigher 16 bits
    low2= lowByte(intValue2);
    hi2= highByte(intValue2);
    
    
//    Serial.print(readingb);
//    if (readingb <0){
//      readingb = 0;
//    }
//    
//    intValueb = readingb&0xFF; // get the value of the lower 8 bits
//    low1b = lowByte(intValueb);
//    hi1b = highByte(intValueb);
//    
//    intValue2b = readingb>>8; // get the value of thehigher 16 bits
//    low2b= lowByte(intValue2b);
//    hi2b= highByte(intValue2b);
//    
    
    
    
//    Serial.print(readingc);
//    if (readingc <0){
//      readingc = 0;
//    }
//    intValuec = readingc&0xFF; // get the value of the lower 8 bits
//    low1c = lowByte(intValuec);
//    hi1c = highByte(intValuec);
//    
//    intValue2c = readingc>>8; // get the value of thehigher 16 bits
//    low2c= lowByte(intValue2c);
//    hi2c= highByte(intValue2c);
    
    
     
    
    
    
    
    
    
    if(hi2=255){
      hi2=0;
    }    
    int checksum = low1 + hi1 + low2 + hi2 ;//+    low1b + hi1b + low2b + hi2b; //+      low1c + hi1c + low2c + hi2c        ;
    Serial.write(255);
    Serial.write(low1);  
    Serial.write(hi1);  
    Serial.write(low2);
    Serial.write(hi2);
//    Serial.write(low1b);  
//    Serial.write(hi1b);  
//    Serial.write(low2b);
//    Serial.write(hi2b);
//    Serial.write(low1c);  
//    Serial.write(hi1c);  
//    Serial.write(low2c);
//    Serial.write(hi2c);
    Serial.write(checksum);
 
  
 
  }
  
  
  
  
  
  else
  {
    /* If event.light = 0 lux the sensor is probably saturated
       and no reliable data could be generated! */
    Serial.println("Sensor overload");
  }
  //delay(1*60*1000UL);
  delay(5000);
  wdt_reset(); // resetting watch dog timer
  delay(5000);
  wdt_reset(); // resetting watch dog timer
//  delay(5000);
//  wdt_reset(); // resetting watch dog timer
//  delay(5000);
//  wdt_reset(); // resetting watch dog timer
//  delay(5000);
//  wdt_reset(); // resetting watch dog timer
//  delay(5000);
//  wdt_reset(); // resetting watch dog timer
//  delay(5000);
//  wdt_reset(); // resetting watch dog timer
//  delay(5000);
//  wdt_reset(); // resetting watch dog timer
//  delay(5000);
//  wdt_reset(); // resetting watch dog timer
//  delay(5000);
//  wdt_reset(); // resetting watch dog timer
//  delay(5000);
//  wdt_reset(); // resetting watch dog timer
//  delay(4500);
//  wdt_reset(); // resetting watch dog timer
}
