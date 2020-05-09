#include "ParticulaApp.h"
using namespace std;

namespace Particula{
        ParticulaApp::ParticulaApp(){
            //printf("help");
            int t =5;
        }
        char* ParticulaApp::partSensorWake(SDS011* part_sensor,HardwareStatus* hardwareStatus){
            if(part_sensor->wakeUp() == WAKEUP_SUCCESSFULL){
                return "[Particle sensor] wake up has been successfull \r\n";
            } else {
                hardwareStatus->particle_wakeup_failed();
                return "[Particle sensor] wake up hasn't been successfull \r\n";
            }
        }
        
        char* ParticulaApp::partSensorRead(SDS011* part_sensor,HardwareStatus* hardwareStatus){
            if(part_sensor->read() == READ_SUCCESSFULL){
                this->pm10 = part_sensor->getPM10Value();
                this->pm25 = part_sensor->getPM25Value();
                return "[Particle sensor] read has been successfull \r\n";
            } else {
                hardwareStatus->particle_read_failed();
                return "[Particle sensor] read hasn't been successfull \r\n";
            }
        }

        char* ParticulaApp::partSensorSleep(SDS011* part_sensor,HardwareStatus* hardwareStatus){
            if (part_sensor->sleep() == SLEEP_SUCCESSFULL) {
                return "[Particle sensor] sleep has been successfull \r\n";
            } else {
                hardwareStatus->particle_sleep_failed();
                return "[Particle sensor] sleep hasn't been successfull \r\n";
            }
        }

        char* ParticulaApp::tphSensorWake(BME280* tph_sensor,HardwareStatus* hardwareStatus){
            tph_sensor->awake();
            if (tph_sensor->present()) {
                return "[TPH sensor] sensor is present \r\n";
            } else {
                hardwareStatus->tph_wakeup_failed();
                return "[TPH sensor] sensor is not present \r\n";
            }
        }

        char* ParticulaApp::tphSensorRead(BME280* tph_sensor,HardwareStatus* hardwareStatus){
            bool temperatureValueCorrect = false;
            bool humidityValueCorrect = false;
            bool pressureValueCorrect = false;
            this->temperature = tph_sensor->temperature(&temperatureValueCorrect);  // value in °C
            this->humidity = tph_sensor->humidity(&humidityValueCorrect);           // value in %
            this->pressure = tph_sensor->presure(&pressureValueCorrect);            // value in hPa
            
            if (temperatureValueCorrect && humidityValueCorrect && pressureValueCorrect) {
                return "[TPH sensor] read has been successful \r\n";
            } else {
                hardwareStatus->tph_read_failed();
                return "[TPH sensor] read has been unsuccessful \r\n";
            }
        }

        char* ParticulaApp::tphSensorSleep(BME280* tph_sensor){
            tph_sensor->sleep();
            return "[TPH sensor] sleep has been unsuccessful \r\n";
        }

        char* ParticulaApp::addToLoRaMessage(AmbiantSensorMessage* message, HardwareStatus* hardwareStatus){
            message->addTemperature(this->temperature);
            message->addHumidity(this->humidity);
            message->addPressure(this->pressure);
            message->addPM(this->pm25);
            message->addPM(this->pm10);

            if(hardwareStatus->errors()){
                message->addStatus(hardwareStatus->get_state());              
                return "[Particula] Errors detected, adding them to lora message \r\n";
            } else {
                return "[Particula] No errors detected \r\n";
            }


        }

        double ParticulaApp::returnTemperature(){
            return this->temperature;
        }

        double ParticulaApp::returnHumidity(){
            return this->humidity;
        }

        double ParticulaApp::returnPressure(){
            return this->pressure;
        }

        double ParticulaApp::returnPm25(){
            return this->pm25;
        }

        double ParticulaApp::returnPm10(){
            return this->pm10;
        }
};