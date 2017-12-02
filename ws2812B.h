/** @file WS2812B.h
 *
 * @author Wassim FILALI
 * Inferred from the Datasheet
 * 
 *
 * @compiler gcc for STM32
 *
 *
 * started on local project                 on 10.10.2015
 * this file was created for refactoring    on 03.01.2016
 * takeover for STM32                       on 02.12.2017
 * $Date:
 * $Revision:
 *
 */

#ifndef __ws2812B__
#define __ws2812B__

#include "mbed.h"

typedef struct
{
  uint8_t R;
  uint8_t G;
  uint8_t B;
}rgb_t;








namespace ws
{

    namespace color
    {
        const rgb_t red = {255,0,0};
        const rgb_t green = {0,255,0};
        const rgb_t blue = {0,0,255};
        const rgb_t black = {0,0,0};
        const rgb_t white = {255,255,255};
    }

}

class ws2812B
{
public:
    ws2812B(PinName pio);

    void set(uint8_t R,uint8_t G,uint8_t B);
private:
    DigitalOut  rgbout;

};

#endif /*__ws2812B__*/
