CC     = gcc
CFLAGS = -Wall -Wextra -g

SRC = src/main.c src/commands.c src/utils.c src/env.c
OBJ = $(SRC:.c=.o)

all: frost

frost: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) frost

install: all
	install -D -m 755 frost ${DESTDIR}${PREFIX}/bin/frost
	mkdir /etc/frost
	test -f /etc/frost/config.cfg || cp config.example /etc/frost/config.cfg

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/frost
	rm -rf /etc/frost

reinstall: uninstall install

.PHONY: all clean install uninstall reinstall
