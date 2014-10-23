Lux_data_logger
===============

Reading data from a TSL2561 lux sensor with an Arduino and then logging the data in a computer with a matching processing code/sketch. The data is transmitted using low and high bytes. 


## Introduction

This is an early code to log data from an adafruit 1 or 2 light sensors (TSL2561).
The lux data is taken from an Arduino (either an Arduino Uno or a Mega).
Then is send with Serial connection (USB) by splitting the read lux value in low and high bytes.

A different logging interval can be set by using the delays in the arduino code. One of the versions has about 1 minute of interval.

A Watch Dog timer is also used to ensure that the Arduino will reset itself in case it gets in an infinite loop.

The serial (lux) data is reconstructed in a Processing sketch that verifies that the data has been received and its checksum.

Then the processing sketch saves the data in txt file, separated by commas and includding a date and time stamp for each set of values.

The txt file is created in the same directory where you have copied your processing sketch.


There are two data naming versions, one with a fixed data name and another that makes a name according to the date. 

## **This is a work in progress.**

When using the codes, remember to match the Arduino code for 1 sensor with the Processing code for 1 sensor, else it wont work because the checksums will be different. Like wise, for the 2 sensors. 
E.g. 
  * LuxMeter3_reads1_sensors_WDT.ino
  * Saving_Lux_data_4th_version_1meters.pde


Also the SCL and SDA ports for Arduino Uno and Mega are different (see picture for connections for Arduino Mega).

## Important

In one of the versions, when the processing sketch is run it will overwrite the file.
In another of the version, it will overwrite it, if the name that creates is the same as the old file. (sketch run in the same day).
Therefore,  you must make a copy of your data before running the sketches again if you dont want to loose your data! You have been warned!.

## Libraries needed

You will need the following libraries.

* Wire
* Adafruit Sensor  - The new libraries, else it wont work.
* Adafruit TSL2561_U.h -  The new libraries, else it wont work.
* avr/wdt.h




