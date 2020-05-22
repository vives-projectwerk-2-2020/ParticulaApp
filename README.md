# ParticulaApp

The ParticulaApp is a library that combines all the necessary librarys of the Particula project and makes shorter, easier to understand functions for it that combines multiple librarys.


## Functions

### UML DIAGRAM

```bash
---------------------------------------------------------------------
|                           ParticulaApp                            |
---------------------------------------------------------------------
| -pm25 : double                                                    |
| -pm10 : double                                                    |
| -temperature : double                                             |
| -humidity : double                                                |
| -pressure : double                                                |
|-------------------------------------------------------------------|
| +partMeasureCycle(SDS011*,HardwareStatus*, int warmupTime) : void |
| +tphMeasureCycle(BME280*,HardwareStatus*) : void                  |
| +LoRaWANMakeCycle(AmbiantSensorMessage*,HardwareStatus*) : void   |
| -partSensorSleep(SDS011*,HardwareStatus*) : char*                 |
| -partSensorRead(SDS011*,HardwareStatus*) :char*                   |
| -partSensorWake(SDS011*,HardwareStatus*) :char*                   |
| -tphSensorSleep(BME280*) : char*                                  |
| -tphSensorRead(BME280*,HardwareStatus*) : char*                   |
| -tphSensorWake(BME280*,HardwareStatus*) : char*                   |
| -addToLoRaMessage(AmbiantSensorMessage*,HardwareStatus*) : char*  |
---------------------------------------------------------------------
```

### Functional

partMeasureCycle(SDS011*,HardwareStatus*, int warmupTime) : wakes the particle sensor, waits for an warmupTime before reading and then puts the sensor to sleep again.

tphMeasureCycle(BME280*,HardwareStatus*) : wakes the tph sensor, reads from it and then put it to sleep again.

LoRaWANMakeCycle(AmbiantSensorMessage*,HardwareStatus*) : adds all the measered values to the LoRaWAN messages and prints out all of the values to the console of in develop mode.

partSensorSleep(SDS011*,HardwareStatus*) : puts the particle sensor to sleep.

partSensorRead(SDS011*,HardwareStatus*) : reads values from the particle sensor.

partSensorWake(SDS011*,HardwareStatus*) : wakes the particle sensor up.

tphSensorSleep(BME280*) : puts the tph sensor to sleep.      

tphSensorRead(BME280*,HardwareStatus*) : reads from the tph sensor.

tphSensorWake(BME280*,HardwareStatus*) : wakes the tph sensor up.

addToLoRaMessage(AmbiantSensorMessage*,HardwareStatus*) : adds al the values to the LoRaWan message.




