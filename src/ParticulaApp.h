#pragma once
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
            bool partSensorSleep(SDS011*,HardwareStatus*);
            bool partSensorRead(SDS011*,HardwareStatus*);
            bool partSensorWake(SDS011*,HardwareStatus*);
            bool tphSensorSleep(BME280*);
            bool tphSensorRead(BME280*,HardwareStatus*);
            bool tphSensorWake(BME280*,HardwareStatus*);
            void addToLoRaMessage(AmbiantSensorMessage*);

        private:
            double pm25;
            double pm10;
            double temperature;
            double humidity;
            double pressure;

    };
};
