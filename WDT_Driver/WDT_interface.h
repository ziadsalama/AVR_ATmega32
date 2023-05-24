
#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_


#define SLEEP_TIME_1SEC             6



void WDT_voidEnable(void);


/* set the run watch dog timer with specific sleep time */
void WDT_voidSetSleepTime(u8 Copy_u8SleepTime);

void WDT_voidDisable(void);


#endif /* WDT_INTERFACE_H_ */
