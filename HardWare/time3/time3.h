#ifndef  __TIME3_H
#define  __TIME3_H

#include "main.h"

extern uint8_t time1sFlag ;
extern uint8_t time5sFlag ;
extern uint8_t time10sFlag;

void time3_Init(void);
static void time3_nvic_init(void);
static void time3_mode_init(void);

#endif/*__TIME3_H*/

