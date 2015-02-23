#include <zlib.h>
#include <stdio.h>
#include "kseq.h"
KSEQ_INIT(gzFile, gzread)

int main(int argc, char *argv[])
{
	gzFile fp;
	kseq_t *seq;
	int l;
	double i=0;
	double b=0;
	if (argc == 1) {
		fprintf(stderr, "Usage: %s <sequence_file>\n", argv[0]);
		return 1;
	}
	fp = gzopen(argv[1], "r");
	seq = kseq_init(fp);
	while ((l = kseq_read(seq)) >= 0) {
		i++;
		b+=l;
	}
	printf("Num of reads: %.0f\n", i);
	printf("Num of bases: %.0f\n", b);
	kseq_destroy(seq);
	gzclose(fp);
	return 0;
}


