OPENMP_CFLAGS=-fopenmp
OPENMP_LIBS=

LIBS=-lm ${OPENMP_LIBS}
CFLAGS=${OPENMP_CFLAGS}

all: main.c
	gcc ${CFLAGS} -o main main.c ${LIBS}
