
server.out: queue.o m-quicksort.o utils.o server.o
	gcc -o server.out queue.o m-quicksort.o utils.o server.o 

server.o: server.c server.h
	gcc -c server.c

queue.o: queue.c queue.h
	gcc -c queue.c

m-quicksort.o: m-quicksort.c m-quicksort.h
	gcc -c m-quicksort.c


clean:
	rm *.o server.out