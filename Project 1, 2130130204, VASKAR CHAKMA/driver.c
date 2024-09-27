/**
 * Driver.c
 * Project 1 - Curriculum Design of Operating System
 * Schedule is in the format
 *
 *  [task name] [priority] [CPU burst] 
 姓名：VASKAR CHAKMA; 学号：2130130204; 班级：2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"

#define SIZE    100

int main(int argc, char *argv[])
{
    FILE *in;
    char *temp;
    char task[SIZE];

    char *name;
    int priority;
    int burst;

    in = fopen(argv[1],"r");
    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
		// returns a pointer to T1
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
		
        add(name,priority,burst);
		
        free(temp);
    }

    fclose(in);

    // invoke the scheduler
    schedule();

    return 0;
}