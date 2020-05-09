#pragma once
#include <string>
#include "BME280.h"
#include "SDS011.h"
#include "hardwarestatus.h"
#include "AmbiantSensorMessage.h"
#include "hardwarestatus.h"

namespace Particula
{
    class ParticulaApp{
        public:
            ParticulaApp(void);
        public:
            char* partSensorSleep(SDS011*,HardwareStatus*);
            char* partSensorRead(SDS011*,HardwareStatus*);
            char* partSensorWake(SDS011*,HardwareStatus*);
            char* tphSensorSleep(BME280*);
            char* tphSensorRead(BME280*,HardwareStatus*);
            char* tphSensorWake(BME280*,HardwareStatus*);
            char* addToLoRaMessage(AmbiantSensorMessage*,HardwareStatus*);
            double returnTemperature();
            double returnHumidity();
            double returnPressure();
            double returnPm25();
            double returnPm10();

        private:
            double pm25 =0.0;
            double pm10 =0.0;
            double temperature =0.0;
            double humidity =0.0;
            double pressure =0.0;

    };
};
