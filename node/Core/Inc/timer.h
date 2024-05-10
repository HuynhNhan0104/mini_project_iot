/*
 * timer.h
 *
 *  Created on: May 4, 2024
 *      Author: NHAN
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_



#define TIME_CYCLE 														10 //(10ms)
#define NUMBER_OF_TIMER												15

extern int timer_counter[NUMBER_OF_TIMER];
extern int timer_flag[NUMBER_OF_TIMER];

void set_timer(int index, int duration);
void clear_timer(int index);
int is_timer_timeout(int index);
int get_time_of_counter(int index);
void timer_run();


#endif /* INC_TIMER_H_ */
