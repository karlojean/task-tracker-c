#include <assert.h>
#include "../include/database.h"
#include "../include/cli.h"

#define DATA_PATH "./data/data.json"

int main(int argc, char *argv[])
{
  assert(argc <= 4);
  load_json(DATA_PATH);
  process_cli(argc, argv);
  save_json(DATA_PATH);

  return 1;
}