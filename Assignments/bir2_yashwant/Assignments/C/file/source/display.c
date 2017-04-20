#include"header.h"
void display_file(struct inode_table *itp, int *dp)
{

    int k = 0;
    int b;
    int pos;
    int i;
    char *file;
    char *t = NULL;
    if (count == 0)
	printf("no file exist\n");
    else {
	file = malloc(sizeof((20)));
	printf("enter the file name you want to display\n");
	read(0, file, 8);
	*(file + strlen(file) - 1) = '\0';
	for (i = 0; i < 1024; i++) {
	    if (!(strcmp((char*)(itp + i)->fname, file))) {
		k++;
		printf("found\n");
		pos = i;
		break;
	    }
	}
	printf("pos=%d\n", pos);
	if (k == 0) {
	    printf("file does not exist\n");
	    return;
	} else {
	    printf("content of file\n");
	    b = (itp + pos)->blk_used;
	    printf("block used =%d\n", b);
	    for (i = 0; i < b; i++) {
		k = (itp + pos)->blk[i];
		printf("k=%d\n", k);
		t = (char *) dp + (k - 26) * 1024;
		printf("t adrsss=%p\n", t);
		printf("%s\n", t);
	    }
	}
    }
}
