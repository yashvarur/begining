/* this function create the file and update the supeblock structure */
#include"header.h"
void create_file(int *ip, struct inode_table *itp, struct super_block *sup)
{

    char *file;
    int i;
    int j;
    int pos;
    file = malloc(20);
    printf("\nenter the file name\n");
    fgets(file,20,stdin);
    *(file + strlen(file) - 1) = '\0';
    while(*file == ' ' )  /* remove the leading spaces */
	file++;

    if(strlen(file) > 8) {
		printf("file name is too long cant exceed 8 character\n");
		return;
    }
	
    for (i = 0; i < 1024; i++) {	/* checking for existing file */
	if (strcmp((char*)(itp + i)->fname, file) == 0) {
	    printf("file already exist\n");
	    return;
	}
    }
    printf("\n");			
    for (i = 0; i < 32; i++) {			/* updating the inode bitmap */
	for (j = 31; j >= 0; j--) {
	    if (((*(ip + i)) & (1 << j)) == 0) {
		*(ip + i) = *(ip + i) | (1 << j);
		pos = (i * 32) + (31 - j);
		goto LABEL;
	    }
	}
    }
  LABEL:
    printf("\n");
    itp->i_no = rand() / 100;
    strcpy((char*)(itp + pos) -> fname, file);	/* updating file name to inode block structure */
    //printf("%s", (itp + pos)->fname);
    printf("------------------------\n\n\n");
    printf("super block structure after creating the file\n");
    sup->total_inodes = 1024;
    sup->total_datablocks = 999;
    (sup->free_inodes)--;
    printf("total inodes=%d\n\n", sup -> total_inodes);
    printf("total data blocks=%d\n\n", sup -> total_datablocks);
    printf("free inodes=%d\n\n", sup -> free_inodes);
    printf("free datablocks=%d\n\n", sup -> free_datablocks);
    printf("-------------------------\n\n\n");
    count++;
}
