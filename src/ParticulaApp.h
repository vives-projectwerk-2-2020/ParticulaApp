#if PRODUCTION_ENVIRONMENT
#define consoleMessage(msg, value1)
#else
#define consoleMessage(...) printf(__VA_ARGS__)
#endif

#pragma once

#include <string>
#include "BME280.h"
#include "settings.h"
#include "SDS011.h"
#include "hardwarestatus.h"
#include "AmbiantSensorMessage.h"

namespace Particula
{
    class ParticulaApp{
        public:
            ParticulaApp(void);
        public:
            void partMeasureCycle(SDS011*,HardwareStatus*, int warmupTime);
            void tphMeasureCycle(BME280*,HardwareStatus*);
            void LoRaWANMakeCycle(AmbiantSensorMessage*,HardwareStatus*);
        private:
            char* partSensorSleep(SDS011*,HardwareStatus*);
            char* partSensorRead(SDS011*,HardwareStatus*);
            char* partSensorWake(SDS011*,HardwareStatus*);
            char* tphSensorSleep(BME280*);
            char* tphSensorRead(BME280*,HardwareStatus*);
            char* tphSensorWake(BME280*,HardwareStatus*);
            char* addToLoRaMessage(AmbiantSensorMessage*,HardwareStatus*);
           
        private:
            double pm25 =0.0;
            double pm10 =0.0;
            double temperature =0.0;
            double humidity =0.0;
            double pressure =0.0;

    };
};
