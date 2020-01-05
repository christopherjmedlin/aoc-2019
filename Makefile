objects = dayone.o daytwo.o daythree.o dayfour.o util/lines.o \
		  util/bst.o
testobjects = tests/main.o tests/bst.o tests/lines.o

CFLAGS=-DDEBUG
CC=g++ -g3 $(CFLAGS)

aoc2019 : main.o $(objects)
	$(CC) -o aoc2019 main.o $(objects)

$(objects) : days.h
util/lines.o : util/lines.h util/bst.h
util/bst.o : util/bst.h
daythree.o : util/lines.h

$(objects) $(testobjects) main.o: %.o: %.cpp
	$(CC) -c $< -o $@

test_runner : $(objects) $(testobjects)
	$(CC) -o test_runner $(objects) $(testobjects)

.PHONY : test
test : test_runner
	./test_runner

.PHONY : clean
clean :
	-rm aoc2019 test_runner main.o $(objects) $(testobjects)
