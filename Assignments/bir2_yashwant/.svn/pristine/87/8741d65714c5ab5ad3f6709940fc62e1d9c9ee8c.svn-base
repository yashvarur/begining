#include"header.h"
void create_file(int *ip, struct inode_table *itp, struct super_block *sup)
{

    char *file;
    int i;


    int j;
    int pos;
 //   static int inode_num;


   //    inode_num = 0;	
    file = malloc(20);
    printf("\nenter the file name\n");
    read(0,file,8);  
    *(file + strlen(file) - 1) = '\0';
    for (i = 0; i < 1024; i++) {
	if (strcmp((char*)(itp + i)->fname, file) == 0) {
	    printf("file already exist\n");
	    return;
	}
    }
    printf("\n");
    for (i = 0; i < 32; i++) {
	for (j = 31; j >= 0; j--) {
	    if (((*(ip + i)) & (1 << j)) == 0) {
		*(ip + i) = *(ip + i) | (1 << j);
		pos = (i * 32) + (31 - j);
		goto LABEL;
	    }
	}
    }
  LABEL:printf("inode bitmap\n");
    for (i = 31; i >= 0; i--)
	printf("%d", ((*ip >> i) & 1) ? 1 : 0);
    printf("\n");
    printf("position of bit=%d\n\n", pos);
    itp->i_no = rand() / 100;
    printf("inode number=%d\n\n", itp->i_no);
    strcpy((char*)(itp + pos)->fname, file);
    printf("%s", (itp + pos)->fname);
    printf("------------------------\n\n\n");
    printf("super block structure after creating the file\n");
    sup->total_inodes = 1024;
    sup->total_datablocks = 999;
    (sup->free_inodes)--;
    printf("total inodes=%d\n\n", sup->total_inodes);
    printf("total data blocks=%d\n\n", sup->total_datablocks);
    printf("free inodes=%d\n\n", sup->free_inodes);
    printf("free datablocks=%d\n\n", sup->free_datablocks);
    printf("-------------------------\n\n\n");
    count++;


}
