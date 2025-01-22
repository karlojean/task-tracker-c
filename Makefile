CC = gcc
CFLAGS = -Wall -Wextra -g 
SRC = src/main.c src/cli.c src/task.c src/database.c
OBJ = $(SRC:.c=.o)
INCLUDE = -Iinclude

all: task_list

task_list: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o task_list -lcjson

clean:
	rm -f src/*.o task_list