CC = cc
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = PIFIncDec.c TimerLinux.c CPrinter.c ClockLinux.c PIFStarter.c PIFEnder.c CPIF.c runtime.c
OBJS = PIFIncDec.o TimerLinux.o CPrinter.o ClockLinux.o PIFStarter.o PIFEnder.o CPIF.o runtime.o

all : CPIF

.c.o :
	${CC} ${CFLAGS} -c $< 

CPIF : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ CPIF