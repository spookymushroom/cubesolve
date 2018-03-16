CC = gcc
DEPS = cubesolve.h
CFLAGS = -O2 -Wall -Werror

.PHONY: all
all: cli functest

%.o: %.c $(DEPS)
	gcc $(CFLAGS) -c $< -o $@

cli: cli.o $(DEPS)
	$(CC) $(CFLAGS) cli.o -o cli

functest: functest.o initfunctions.o $(DEPS)
	$(CC) $(CFLAGS) functest.o initfunctions.o -o functest
