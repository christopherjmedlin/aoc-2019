objects = main.o dayone.o

nutricli : $(objects)
	g++ -o aoc2019 $(objects)

$(objects) : days.h

.PHONY : clean
clean :
	-rm aoc2019 $(objects)
