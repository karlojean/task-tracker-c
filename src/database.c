#include <stdio.h>
#include <cjson/cJSON.h>
#include "../include/task.h"
#include <string.h>
#include <stdlib.h>

int load_json(char data_path[])
{
  FILE *fp = fopen(data_path, "r");

  if (fp == NULL)
  {
    printf("ERROR: Não foi possível ler o JSON! \n");
    return 1;
  }

  char buffer[1024];
  fread(buffer, 1, sizeof(buffer), fp);
  fclose(fp);

  cJSON *json = cJSON_Parse(buffer);

  if (json == NULL)
  {
    printf("Erro ao analisar o JSON\n");
    return 1;
  }

  if (cJSON_IsArray(json))
  {
    int size = cJSON_GetArraySize(json);
    for (int i = 0; i < size && i < MAX_TASKS; i++)
    {
      cJSON *item = cJSON_GetArrayItem(json, i);

      cJSON *id = cJSON_GetObjectItem(item, "id");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(item, "description");
      cJSON *status = cJSON_GetObjectItemCaseSensitive(item, "status");

      tasks[i].id = id->valueint;
      strcpy(tasks[i].description, description->valuestring);
      tasks[i].status = status->valueint;

      tasks_size++;
    }
  }

  return 0;
}

int save_json(char data_path[])
{
  cJSON *json_array = cJSON_CreateArray();

  for (int i = 0; i < tasks_size; i++)
  {
    cJSON *task_obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(task_obj, "id", tasks[i].id);
    cJSON_AddStringToObject(task_obj, "description", tasks[i].description);
    cJSON_AddNumberToObject(task_obj, "status", tasks[i].status);
    cJSON_AddItemToArray(json_array, task_obj);
  }

  char *json_string = cJSON_Print(json_array);
  FILE *fp = fopen(data_path, "w");
  if (fp == NULL)
  {
    perror("Erro ao abrir o arquivo para escrita");
    cJSON_Delete(json_array);
    free(json_string);
    return 1;
  }

  fprintf(fp, "%s\n", json_string);
  fclose(fp);

  cJSON_Delete(json_array);
  free(json_string);

  return 0;
}