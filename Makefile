objects = main.o dayone.o daytwo.o
CFLAGS=-DDEBUG
CC=g++ -g3 $(CFLAGS)

nutricli : $(objects)
	$(CC) -o aoc2019 $(objects)

$(objects) : days.h

$(objects): %.o: %.cpp
	$(CC) -c $< -o $@

.PHONY : clean
clean :
	-rm aoc2019 $(objects)
