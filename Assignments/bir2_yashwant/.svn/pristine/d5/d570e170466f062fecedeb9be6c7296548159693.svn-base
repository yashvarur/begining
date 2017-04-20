#include"header.h"
void list_file(struct inode_table *itp, int *ibp)
{
    int i;
    int j;
    int pos;
    if (count == 0)
	printf("no file exist\n");

    else {
	printf("list of file name\n");
	for (i = 0; i < 32; i++) {
	    for (j = 31; j >= 0; j--) {
		if (*(ibp + i) & (1 << j)) {
		    pos = (i * 32) + (31 - j);
		    printf("%s\n", (itp + pos)->fname);
		}
	    }

	}
    }
}

