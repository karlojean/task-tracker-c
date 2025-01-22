#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "../include/task.h"
#include "../include/cli.h"

Task tasks[MAX_TASKS];
int tasks_size;

int add_task(char taskName[])
{
  assert(taskName != NULL);

  if (tasks_size >= MAX_TASKS)
  {
    printf("Limite de tarefas excedido!\n");
    exit(1);
  }

  tasks[tasks_size].id = get_last_task_id() + 1;
  strncpy(tasks[tasks_size].description, taskName, 79);
  tasks[tasks_size].status = TODO;

  tasks_size++;

  return 1;
}

int update_task(int id, char newTaskName[])
{

  for (int i = 0; i <= tasks_size; i++)
  {
    if (tasks[i].id == id)
    {
      strncpy(tasks[i].description, newTaskName, 79);
    }
  }

  return 1;
}

int delete_task(int id)
{

  int found = -1;

  for (int i = 0; i <= tasks_size; i++)
  {
    if (tasks[i].id == id)
    {
      found = i;
      break;
    }
  }

  if (found == -1)
  {
    printf("Tarefa não encontrada!");
    return 0;
  }

  for (int i = found; i < tasks_size - 1; i++)
  {
    tasks[i] = tasks[i + 1];
  }

  tasks_size--;
  return 1;
}

int mark_in_progress_task(int id)
{
  for (int i = 0; i <= tasks_size; i++)
  {
    if (tasks[i].id == id)
    {
      tasks[i].status = IN_PROGRESS;
    }
  }

  return 1;
}

int mark_done_task(int id)
{
  for (int i = 0; i <= tasks_size; i++)
  {
    if (tasks[i].id == id)
    {
      tasks[i].status = DONE;
    }
  }

  return 1;
}

void list_task(int argc, char *argv[])
{
  if (argc >= 3)
  {
    if (strcmp("done", argv[2]) == 0)
    {
      for (int i = 0; i < tasks_size; i++)
      {
        if (tasks[i].id != 0)
        {
          if (tasks[i].status == 0)
          {

            task_print(&tasks[i]);
          }
        }
      }
      return;
    }
    else if (strcmp("todo", argv[2]) == 0)
    {
      for (int i = 0; i < tasks_size; i++)
      {
        if (tasks[i].id != 0)
        {
          if (tasks[i].status == 1)
          {

            task_print(&tasks[i]);
          }
        }
      }
      return;
    }
    else if (strcmp("in-progress", argv[2]) == 0)
    {
      for (int i = 0; i < tasks_size; i++)
      {
        if (tasks[i].id != 0)
        {
          if (tasks[i].status == 2)
          {

            task_print(&tasks[i]);
          }
        }
      }
      return;
    }
  }

  for (int i = 0; i < tasks_size; i++)
  {
    if (tasks[i].id != 0)
    {
      task_print(&tasks[i]);
    }
  }
}

int get_last_task_id()
{
  int last_id = 0;
  for (int i = 0; i < tasks_size; i++)
  {
    last_id = last_id > tasks[i].id ? last_id : tasks[i].id;
  }
  return last_id;
}