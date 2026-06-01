CC     = gcc
CFLAGS = -Wall -Wextra -g

SRC = src/main.c src/commands.c
OBJ = $(SRC:.c=.o)

frost: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

