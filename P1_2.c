#include <alarm.h>
#include <types.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <cglob.h>


main(){
	signal_code ReceivedSginal;
	u_int32 SleepValue;

	alarm_id MyAlarm;
	signal_code WakeupSignal;

	u_int32 TimeToDelay;
	u_int32 i;

    int	reads[] = {2, 4, 8, 7, 9.11};
	i = 0;
   
	TimeToDelay = 3900;
	WakeupSignal = 1; 
   
	if ((errno = _os_alarm_cycle(&MyAlarm, WakeupSignal, TimeToDelay)) != 0)
		{
			printf("error creating alarm\n");
		}

	SleepValue = 0; /* Infinite loop, sleep forever */
     	
		  
	while (1){
		_os_sleep(&SleepValue, &ReceivedSginal);
		if(ReceivedSginal ==0){
 			printf("P1_2: Temperture:  %d\n", reads[i]);
			if(	i==4)
				i=0;
			else
				i= i +1;
			}
		else
			printf("P1_2: The signal value which caused the alarm is %d\n", ReceivedSginal);

		}
	}