CC = gcc
CFLAGS += -Wall 
#CFLAGS += -g -O0
#CFLAGS += -D_FILE_OFFSET_BITS=64 -m64 -O3 -fomit-frame-pointer -Wno-char-subscripts 
CFLAGS += -D_FILE_OFFSET_BITS=64 -m64 -O9 -funroll-loops -DNDEBUG 

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
	src/sacak-lcp.o

all: compile

clean:
	\rm src/*.o lib/*.o external/*.o sacak-lcp

compile: main.c ${LIBOBJ} 
	$(CC) $(CFLAGS) $(LFLAGS) -o sacak-lcp main.c ${LIBOBJ}

run:
	./sacak-lcp $(DIR) $(INPUT) $(K) $(MODE) $(CHECK) $(OUTPUT)

valgrind:
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./sacak-lcp $(DIR) $(INPUT) $(K) $(MODE) $(CHECK) $(OUTPUT)
