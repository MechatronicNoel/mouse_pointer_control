#include <mouse_control.h>

/**
* @copyright (c) 2022 Noel Dom.
*
* @brief ESP32 firmware to control mouse pointer by some sensor 
* @file mouse_control.cpp
* @version 0.1.0
* @date   10/09/2022
* @author Noel Dominguez
*
* CHANGELOG:
*/

/* Puedes sustituir por el valor de tu sensor */
#define MAX_DISTANCE 200 
#define MID_DISTANCE 120
#define MIN_DISTANCE 25  
/* */

/*!
 *    @brief  Instantiates a new Mouse_control class
 */
Mouse_control::Mouse_control(){}

/*!
 *    @brief  Cleans up the Mouse_control class
 */
Mouse_control::~Mouse_control(){}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Mouse_control::init(void){

    mouser_err_t err = eOK;

    Serial.begin(115200);
    
    bleMouse.begin();
    Serial.println("Starting BLE now!");
    return err;
}

/**
 * @brief Run move mouser app
 * 
 * @return true If everything is fine
 * @return false Something wrong
 */
bool Mouse_control::run(void){
    
    mouser_err_t err = eOK;

    move_mouse();

    return err;
}

/**
 * @brief  Move mouse if bluetooth connection is true
 * 
 */
 void Mouse_control::move_mouse(void){


    if(bleMouse.isConnected()) {

        logic_control();

    }

 }

/**
 * @brief Read ADC sensor
 * 
 * @return int adc value
 */
 int Mouse_control::read_adc_sensor(void){

    return analogRead(ADC_PIN);
 }

/**
 * @brief Control Mouse logic you can changue the MIN,MID and max sensor, depending onyour sensor input
 * 
 */
 void Mouse_control::logic_control(void){
    
    int adc_val = read_adc_sensor();

    if ( adc_val > MID_DISTANCE && adc_val < MAX_DISTANCE){ /* Scroll up */

        Serial.println("Scroll up");
        bleMouse.move(0,0,1);
    }
    
    else if ( adc_val > MIN_DISTANCE && adc_val < MID_DISTANCE ){
        
        Serial.println("Scroll down"); /* Scroll down */
        bleMouse.move(0,0,-1);
    }
    
 }
