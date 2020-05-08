#include "ParticulaApp.h"

namespace Particula{
    class ParticulaApp{
        ParticulaApp::ParticulaApp(){}
        bool ParticulaApp::partSensorWake(SDS011* part_sensor,HardwareStatus* hardwareStatus){
            if(part_sensor.wakeUp() == WAKEUP_SUCCESSFULL){
                return true;
            } else {
                hardwareStatus.particle_wakeup_failed();
                return false;
            }
        }
        
        bool ParticulaApp::partSensorRead(SDS011* part_sensor,HardwareStatus* hardwareStatus){
            if(part_sensor.read() == READ_SUCCESSFULL){
                this.pm10 = part_sensor.getPM10Value();
                this.pm25 = part_sensor.getPM25Value();
                return true
            } else {
                hardwareStatus.particle_read_failed();
                return false
            }
        }

        bool ParticulaApp::partSensorSleep(SDS011* part_sensor,HardwareStatus* hardwareStatus){
            if (part_sensor.sleep() == SLEEP_SUCCESSFULL) {
                return true;
            } else {
                hardwareStatus.particle_sleep_failed();
                return false;
            }
        }

        bool ParticulaApp::tphSensorWake(BME280* tph_sensor,HardwareStatus* hardwareStatus){
            tph_sensor.awake();
            if (tph_sensor.present()) {
                return true;
            } else {
                hardwareStatus.tph_wakeup_failed();
                return false;
            }
        }

        bool ParticulaApp::tphSensorRead(BME280* tph_sensor,HardwareStatus* hardwareStatus){
            bool temperatureValueCorrect = false;
            bool humidityValueCorrect = false;
            bool pressureValueCorrect = false;
            this.temperature = tph_sensor.temperature(&temperatureValueCorrect);  // value in °C
            this.humidity = tph_sensor.humidity(&humidityValueCorrect);           // value in %
            this.pressure = tph_sensor.presure(&pressureValueCorrect);            // value in hPa
            
            if (temperatureValueCorrect && humidityValueCorrect && pressureValueCorrect) {
                return true;
            } else {
                hardwareStatus.tph_read_failed();
                return false;
            }
        }

        bool ParticulaApp::tphSensorSleep(BME280* tph_sensor){
            tph_sensor.sleep();
        }

        void addToLoRaMessage(AmbiantSensorMessage* message){
            message.addTemperature(this.temperature);
            message.addHumidity(this.humidity);
            message.addPressure(this.pressure);
            message.addPM(this.pm25);
            message.addPM(this.pm10);
        }

    };
};