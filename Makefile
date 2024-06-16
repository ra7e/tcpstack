CC=gcc
CFLAGS=-g
TARGET:test

OBJS=gluethread/glthread.o \
		  graph.o 		   \
		  topologies.o	   \
		  net.o			   \
		  comm.o		   \
		  utils/utils.o

test:testapp.o ${OBJS}
	${CC} ${CFLAGS} testapp.o ${OBJS} -o test
testapp.o:testapp.c
	${CC} ${CFLAGS} -c testapp.c -o testapp.o
gluethread/glthread.o:gluethread/glthread.c
	${CC} ${CFLAGS} -c -I gluethread gluethread/glthread.c -o gluethread/glthread.o
graph.o:graph.c
	${CC} ${CFLAGS} -c -I . graph.c -o graph.o
topologies.o:topologies.c
	${CC} ${CFLAGS} -c -I . topologies.c -o topologies.o
net.o:net.c
	${CC} ${CFLAGS} -c -I . net.c -o net.o
utils.o:utils.c
	${CC} ${CFLAGS} -c -I utils utils/utils.c -o utils/utils.o
comm.o:communication.c
	${CC} ${CFLAGS} -c -I comm communication.c -o comm.o

clean:
	rm *.o
	rm utils/*.o
	rm gluethread/glthread.o
	rm test
