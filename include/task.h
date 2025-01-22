#ifndef TASK_H
#define TASK_H

#include <stdio.h>

typedef enum
{
  TODO = 0,
  IN_PROGRESS = 1,
  DONE = 2,
} TaskStatus;

typedef struct
{
  int id;
  char description[100];
  TaskStatus status;
} Task;

#define MAX_TASKS 300
extern Task tasks[MAX_TASKS];
extern int tasks_size;

int add_task(char taskName[]);
int update_task(int id, char newTaskName[]);
int delete_task(int id);
int mark_in_progress_task(int id);
int mark_done_task(int id);
void list_task(int argc, char *argv[]);
int get_last_task_id();

#endif