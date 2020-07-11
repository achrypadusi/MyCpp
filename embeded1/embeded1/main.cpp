#include <intrinsics.h>
#include <vector>
#include "TM4C123GH6PM.h"
#include "bsp.h"


//uint32_t volatile dataRed = 999;
//uint32_t volatile dataSw1 = 999;
//uint32_t volatile dataSw2 = 999;
//uint32_t sysTickVal;

unsigned long getTime(int reset);
void initPer();

using std::vector;

int main(void)
{

    initPer();

    uint32_t noSeq = 0;
    uint64_t prevSysValSeq;
    uint64_t currentSysValSeq;
    vector<uint64_t> sysValSeq;
    vector<uint64_t> colorSeq;

    uint32_t OneSClockHz = SYS_CLOCK_HZ - 1U;
    SysTick->LOAD = OneSClockHz;
    //SysTick->LOAD = 0xFFFFFFFF;
    SysTick->VAL = 0U;
    SysTick->CTRL = (1U << 2) | (1U << 1) | 1U;

    __disable_interrupt();
    while (1)
    {
        if (!(GPIOF_AHB->DATA_Bits[SWITCH1])) {
            prevSysValSeq = currentSysValSeq = 0;
            getTime(1);
            uint32_t TenSClockHz = 10 * OneSClockHz;
            noSeq = 0;
            while (getTime(0) < TenSClockHz) {
                //i++;
                //getTime(0);
                if (GPIOF_AHB->DATA_Bits[SWITCH1]) {
                    if (GPIOF_AHB->DATA_Bits[LED_RED] == LED_RED) {
                        GPIOF_AHB->DATA_Bits[LED_RED] = 0;
                        currentSysValSeq = getTime(0);
                        sysValSeq.push_back(currentSysValSeq - prevSysValSeq);
                        prevSysValSeq = currentSysValSeq;
                        colorSeq.push_back(0);
                        noSeq++;
                    }
                }
                else {
                    if (GPIOF_AHB->DATA_Bits[LED_RED] == 0) {
                        GPIOF_AHB->DATA_Bits[LED_RED] = LED_RED;
                        currentSysValSeq = getTime(0);
                        sysValSeq.push_back(currentSysValSeq - prevSysValSeq);
                        prevSysValSeq = currentSysValSeq;
                        colorSeq.push_back(LED_RED);
                        noSeq++;
                    }
                }
            }
            GPIOF_AHB->DATA_Bits[LED_RED] = 0;

            //i = 0;
            //while (i < 2000000)
            //    i++;
            getTime(1);
            while (getTime(0) < OneSClockHz) {}

            SysTick->LOAD = sysValSeq[1];
            __enable_interrupt();
            break;
        }
    }
    while (1) {};

    return 0;
}

unsigned long getTime(int reset)
{
    static unsigned long currentTime;
    static uint32_t prevSysVal;
    uint32_t actSysVal = SysTick->VAL;
    uint32_t diff;
    if (reset == 1) {
        currentTime = 0;
    }
    else {
        diff = prevSysVal - actSysVal;
        if (diff > 0)
            currentTime += diff;
        else
            currentTime += (SysTick->LOAD) - actSysVal;
    }
    prevSysVal = actSysVal;
    return currentTime;
}

void initPer()
{
    SYSCTL->RCGCGPIO |= (1U << 5); // enable Run mode for GPIOF 
    SYSCTL->GPIOHBCTL |= (1U << 5); // enable AHB for GPIOF 
    GPIOF_AHB->DIR |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIOF_AHB->DEN |= (LED_RED | LED_BLUE | LED_GREEN | SWITCH1 | SWITCH2);
    GPIOF_AHB->PUR |= (SWITCH1 | SWITCH2);

    GPIOF_AHB->DATA_Bits[LED_RED] = 0;
    GPIOF_AHB->DATA_Bits[LED_BLUE] = 0;
    GPIOF_AHB->DATA_Bits[LED_GREEN] = 0;
}