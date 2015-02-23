all:kseq.h RnB_counter.c
		$(CC) -g -O2 RnB_counter.c -o RnB_counter -lz

clean:
		rm -f *.o RnB_counter
