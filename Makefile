CC     = gcc
CFLAGS = -Wall -Wextra -g

SRC = src/main.c src/commands.c
OBJ = $(SRC:.c=.o)

all: frost

frost: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) frost

.PHONY: all clean
