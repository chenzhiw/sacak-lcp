CC = gcc
CFLAGS += -Wall 
#CFLAGS += -g -O0
#CFLAGS += -D_FILE_OFFSET_BITS=64 -m64 -O3 -fomit-frame-pointer -Wno-char-subscripts 
CFLAGS += -D_FILE_OFFSET_BITS=64 -m64 -O9 -funroll-loops 

LFLAGS = -lm -lrt -ldl

DIR = dataset/
INPUT = input.100.txt

K	= 1
MODE 	= 1
CHECK	= 1
OUTPUT	= 0

LIBOBJ = \
	lib/utils.o\
	lib/file.o\
	lib/suffix_array.o\
	lib/lcp_array.o\
	external/malloc_count/malloc_count.o\
	external/sais-lcp.o\
	../sacak-lcp.o
##
M64 = 0
DEBUG = 0
##

DEFINES = -DDEBUG=$(DEBUG) -DM64=$(M64)

CFLAGS += $(DEFINES)

all: compile

clean:
	\rm -f lib/*.o external/*.o main sacak-lcp.o

compile: main.c ${LIBOBJ} 
	$(CC) $(CFLAGS) $(LFLAGS) -o main main.c ${LIBOBJ}

run:
	./main $(DIR) $(INPUT) $(K) $(MODE) $(CHECK) $(OUTPUT)

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./main $(DIR) $(INPUT) $(K) $(MODE) $(CHECK) $(OUTPUT)
