/*
    So basics here... (in case of Neuro wants to fuck with this and add to the basics repo)

    Jump start and important shit:
    - This is a blink example for the ESP32 using the ESP-IDF framework.
    - Get your env set up and ready to go(or this fucks you), you can find the instructions here: https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html
    - after getting settled run $HOME/esp/esp-idf/export.sh to set up the environment variables for the ESP-IDF framework.(and the terminal session)
    - run idf.py build to build the project, and idf.py flash to flash it to the ESP32. after setting the fucking  target esp board with idf.py set-target 'esp32' or whatever the fuck you have.
    
    - to flash the ESP32 you need to have it connected to your computer 
    and you need to know what port it is connected to. you can find this out by running lsusb and then ls -l /dev/serial/by-id/.
    before and after plugging in the ESP32, the new device that shows up is your ESP32. (on Linux, on Windows it will be COMx where x is a number)
*/

#include <stdio.h>


#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>

//Setup

static const gpio_num_t led = GPIO_NUM_4;

//Not main, main gets handled by the ESP32 framework, so we use app_main instead. 
//think main as crt0 for the ESP32, it sets up the environment and then calls app_main.
void app_main(void)
{
    uint8_t led_state = 0;

    gpio_reset_pin(led);
    gpio_set_direction(led, GPIO_MODE_OUTPUT);

    while (1)
    {
        //Toggle the LED state
        led_state = !led_state;
        gpio_set_level(led, led_state);

        //Print the current state of the LED to the console
        printf("LED state: %d\n", led_state);

        //expects a delay in ticks, so we convert the fucker to ticks using the portTICK_PERIOD_MS
        vTaskDelay(1000 / portTICK_PERIOD_MS); //Delay for 1 second
    

    }

    return;
}