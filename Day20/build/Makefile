CC=clang

program1 : main.o sum.o
	$(CC) $^ -o $@

%.o : %.c
	$(CC) -c $< -o $@

.PHONY : clean
clean:
	rm -f *.o program1