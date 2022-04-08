CC=gcc
CFLGAGS=-lm -lpthread -fopenmp
OBJS=main.o sum.o

.PHONY : all
all: prog

prog: $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@

.PHONY : clean
clean:
	rm -f *.o *.i *.s prog

.PHONY : start
start: prog
	./prog

.PHONY : info
info: 
	echo "Compiler $(CC)"