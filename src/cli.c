#include "../include/task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_cli(int argc, char *argv[])
{

  if (argc < 2)
  {
    printf("Passe um comando! \n");
    return;
  }

  char *command = argv[1];

  if (strcmp("add", command) == 0)
    add_task(argv[2]);
  else if (strcmp("update", command) == 0)
    update_task(atoi(argv[2]), argv[3]);
  else if (strcmp("delete", command) == 0)
    delete_task(atoi(argv[2]));
  else if (strcmp("list", command) == 0)
    list_task(argc, argv);
  else if (strcmp("mark-done", command) == 0)
    mark_done_task(atoi(argv[2]));
  else if (strcmp("mark-in-progress", command) == 0)
    mark_in_progress_task(atoi(argv[2]));
  else
    printf("Comando não encontrado! \n");
}

void task_print(const Task *task)
{
  const char *TASK_STATUS[] = {
      "Done",
      "Todo",
      "In-progress"};

  printf("ID: %d, Descrição: %s, Status: %s\n",
         task->id,
         task->description,
         TASK_STATUS[task->status]);
}