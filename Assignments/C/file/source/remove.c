/* this function will remove the enterd file and update the  blocks */
#include"header.h"
void remove_file(struct inode_table *itp, int *ibp, int *dbp, struct super_block *sup)
{
    char *file;
    int pos;
    int i;
    int j;
    int t;
    int k = 0;
    if (count == 0)
	printf("no file to remove\n");
    else {
	count--;
	file = malloc(sizeof((20)));
	printf("enter the file name you want to remove\n");
	read(0, file, 8);
	*(file + strlen(file) - 1) = '\0';
	for (i = 0; i < 1024; i++) {
	    if (!(strcmp((char*)(itp + i)->fname, file))) {	/* checking for indode table */
		k++;
		pos = i;
		break;
	    }
	}
	if (k == 0) {
	    printf("file does not exist\n");
	    return;
	} 
	else {
		 printf("datablock pointer before  removing file\n");
             for (i = 31; i >= 0; i--) {		/* printing the datablock  */
                 printf("%d", ((*dbp >> i) & 1) ? 1 : 0);
                 if(!(i%8))
                	printf("\t");
        	}
            printf("\n");
		
	    t = (itp + pos)->blk_used;	 /* printing the remaing datablock pointer */

	    for (j = 0; j < t; j++) {
		printf("blk in remove%d\n",(itp+pos)->blk[j]);	/* resetting the datablocks*/
		 *(dbp + (itp+pos)->blk[j] / 32) &= (~(1 << (32 - (itp+pos)->blk[j])));
	    }
	 
	    printf("file %s is successfully removed\n",(itp + pos)->fname);
	    strcpy((char*)(itp + pos)->fname, "");
	    printf("file name in remov=%s\n",(itp+pos)->fname);
            printf("\n");
	    *(ibp + pos / 32) &= (~(1 << (31 - pos)));
		printf("datablock pointer after removing file\n");
	     for (i = 31; i >= 0; i--) {
                printf("%d", ((*dbp >> i) & 1) ? 1 : 0);
		if(!(i%8))
		printf("\t");
		}
            printf("\n");

	    printf("inode bitmap after removing\n");
	    for (i = 31; i >= 0; i--)
		printf("%d", ((*ibp >> i) & 1) ? 1 : 0);
	    printf("\n");
	    printf("------------------------\n\n\n");
	    printf("super block structure after removing the file\n");
	    sup->total_inodes = 1024;
	    sup->total_datablocks = 999;
	    for (i = 0; i < t; i++) {
		if (*ibp != 0)
		    (sup->free_datablocks)++;
	    }
	    (sup->free_inodes)++;
	    printf("total inodes=%d\n\n", sup->total_inodes);
	    printf("total data blocks=%d\n\n", sup->total_datablocks);
	    printf("free inodes=%d\n\n", sup->free_inodes);
	    printf("free datablocks=%d\n\n", sup->free_datablocks);
	    printf("-------------------------\n\n\n");
	}
    }
}

