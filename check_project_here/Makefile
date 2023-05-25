CFLAGS=-lm -O3 # added compiler flag for optimization
INCLUDES=-I/. # specify the correct path to the header files

all: task1 task2 task3 task4

task1: task1.c
	gcc task1.c $(CFLAGS) $(INCLUDES) -o task1

task2: task2.c
	gcc task2.c $(CFLAGS) $(INCLUDES) -o task2

task3: task3.c
	gcc task3.c $(CFLAGS) $(INCLUDES) -o task3

task4: task4.c
	gcc task4.c $(CFLAGS) $(INCLUDES) -o task4

valgrind: all
	timeout 3 valgrind --leak-check=full --log-file=valgrind_task1.log ./task1
	timeout 3 valgrind --leak-check=full --log-file=valgrind_task2.log ./task2
	timeout 3 valgrind --leak-check=full --log-file=valgrind_task3.log ./task3
	timeout 3 valgrind --leak-check=full --log-file=valgrind_task4.log ./task4

clean:
	rm -f task1 task2 task3 task4 valgrind_task*.log