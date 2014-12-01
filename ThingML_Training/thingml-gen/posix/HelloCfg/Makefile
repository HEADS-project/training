CC = cc
LIBS = -lpthread 
CFLAGS = -O2 -w
SRCS = HelloThing.c HelloCfg.c runtime.c
OBJS = HelloThing.o HelloCfg.o runtime.o

all : HelloCfg

.c.o :
	${CC} ${CFLAGS} -c $< 

HelloCfg : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ HelloCfg