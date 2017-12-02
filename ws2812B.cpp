
#include "ws2812B.h"

#define RGB_PIO_SET     GPIOB->BSRR = GPIO_BSRR_BS13
#define RGB_PIO_CLEAR   GPIOB->BSRR = GPIO_BSRR_BR13

//T1H 800 ns => 57 : 43
#define WAIT_T1H;       __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
//T1L 450 ns => 32 : 24
#define WAIT_T1L;       __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
//T0H 400 ns => 28 : 21
#define WAIT_T0H;       __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
//T0L 850 ns => 61 : 46
#define WAIT_T0L;       __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();

#define PLAY_ONE;    RGB_PIO_SET;    WAIT_T1H;   RGB_PIO_CLEAR;  WAIT_T1L;
#define PLAY_ZERO;   RGB_PIO_SET;    WAIT_T0H;   RGB_PIO_CLEAR;  WAIT_T0L;

ws2812B::ws2812B(PinName pio):rgbout(pio)
{
    //reset
    rgbout = 0;
    wait_us(50);
}

void wait_corse_nop(uint32_t nb_nop)
{
	for(uint32_t i=0;i<nb_nop;i++)
	{
		__NOP();
	}
}


void wait_RESET()
{
    wait_corse_nop(4);
}

void ws2812B::set(uint8_t R,uint8_t G,uint8_t B)
{
    uint32_t GRB;//Order of WS2812B is G7...G0...R...B...
    GRB = G;
    GRB <<= 8;
    GRB += R;
    GRB <<= 8;
    GRB += B;
    __disable_irq();

    //---- BYTE 3 ----
    if(GRB & 0x800000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x400000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x200000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x100000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x080000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x040000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x020000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x010000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}

    //---- BYTE 2 ----
    if(GRB & 0x8000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x4000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x2000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x1000)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x0800)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x0400)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x0200)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x0100)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}


    //---- BYTE 1 ----
    if(GRB & 0x80)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x40)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x20)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x10)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x08)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x04)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x02)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}
    if(GRB & 0x01)
        {PLAY_ONE;}
    else
        {PLAY_ZERO;}

    __enable_irq();
}
