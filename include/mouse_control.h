/**
* @copyright (c) 2022 Noel Dom.
*
* @brief ESP32 firmware to control mouser pointer by sensor 
* @file mouse_control.h
* @version 0.1.0
* @date   10/09/2022
* @author Noel Dominguez
*
* CHANGELOG:
*/


#include <Arduino.h>
#include <BleMouse.h>

#define LED 2
#define ADC_PIN 2

class Mouse_control final {

    typedef enum {
        eOK,
        eFailed
    }mouser_err_t;

    public:
    
        Mouse_control();
        ~Mouse_control();

        bool init(void);
        bool run(void);

    private:

        BleMouse bleMouse;
        

        void move_mouse(void);
        int read_adc_sensor(void);
        void logic_control(void);
        
        
};