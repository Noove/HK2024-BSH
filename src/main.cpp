// Includes
#include <Drivers/Matrix.h>
#include <Drivers/Sensor.h>
#include <Drivers/Animation.h>
#include <Drivers/Commander.h>

void setup()
{
    // Peripheal Init
    Serial.begin(115200);
    Wire.begin();

    // Subsystem Init
    Matrix::begin();
    Sensor::begin();
    Matrix::set_brightness(20);
    Commander::begin();
}

void loop()
{
    // Process commands
    serial_commands_.ReadSerial();

    // Animation handler
    if(!gui_mode) Animation::runAnimation();
}