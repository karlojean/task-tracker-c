#ifndef CLI_H
#define CLI_H
#include "task.h"
void task_print(const Task *task);
void process_cli(int argc, char *argv[]);
#endif