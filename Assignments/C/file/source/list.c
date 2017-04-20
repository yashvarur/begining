/* this function list name of files */
#include"header.h"
void list_file(struct inode_table *itp, int *ibp)
{
    int i;
    int j;
    int pos;
    if (count == 0)
	printf("no file exist\n");

    else {
	printf("list of file names\n");
	for (i = 0; i < 32; i++) {
	    for (j = 31; j >= 0; j--) {
		if (*(ibp + i) & (1 << j)) { /* checking the inode bitmap block of files */
		    pos = (i * 32) + (31 - j);
		    printf("%s\t", ( itp + pos ) -> fname);
		}
	    }

	}
    }
printf("\n");
}

