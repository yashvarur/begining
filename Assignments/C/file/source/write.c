/* this function will write into particular file and update the necessary blocks */
#include"header.h"
void write_file(struct inode_table *itp, int *dbp, int *sp, int *ip,
		struct super_block *sup, int *dp)
{
    int i, j;
    int pos;
    int blk_index;
    int size;
    char *file;
    char *buf;
    int  f = 0;
    int k = 0;
    int temp = 0;
    int temp1 = 0;
    char *read_content;
    if (count == 0)
	printf("no file exist to write\n");
    else {
	file = malloc(sizeof((20)));
	int start = 0, end = 1022;
	for (i = 31; i >= 0; i--) {
	    printf("%d", ((*dbp >> i) & 1) ? 1 : 0);
	    if (!(i % 8))
		printf("\t");
	}
	printf("\n");
	printf("enter the file name you want to write\n");
	read(0, file, 8);
	*(file + strlen(file) - 1) = '\0';
	for (i = 0; i < 1024; i++) {
	    if (!(strcmp((char*)(itp + i)->fname, file))) {
		pos = i;
		k++;
		break;
	    }
	}
	if(k != 0)
		printf("file found position = %d\n",pos);
	if (k == 0)
	    printf("file does not exist\n");
	else {
	    if((itp + pos)->blk_used < 5) {
	    	read_content = (char *) malloc(5 * 1024);
	    	printf("enter content of file\n");
	    	//size = read(0, read_content, 1024 * 5);
		fgets(read_content, 5*1024,stdin);
		*(read_content + strlen(read_content) - 1) = '\0';
		size = strlen(read_content);
		if(size > (5*1024)) {
			printf("entered file size is too large\n");
			return;
		}
	    	temp = size /1024;
	    	temp1 = size % 1024;
	    	if(temp1 != 0)
			temp = temp + 1;
	    	printf("size of file = %d\n", size);
	   	for (j = 0; j <= 31; j++) {
			(sup->free_datablocks)--;
			for (i = 31; i >= 0; i--) {
		    		if (!(*(dbp + j) & (1 << i))) {
					*(dbp + j) = *(dbp + j) | (1 << i);
					blk_index = (itp + pos)->blk_used;
					(itp + pos)->blk[blk_index] = (j * 32)  + (32 - i);
					(itp + pos)->blk_used += 1;
					printf("blk index = %d\n", (itp + pos)->blk[blk_index]);
					buf = (char *) (sp) + (((itp + pos)->blk[ blk_index ] - 1) * 1024);
					printf("blocked used = %d\n",
					(itp + pos)->blk_used);
					if(temp > 0) {
						buf = strcpy1(read_content, buf, start, end);
                        			printf("content of file=%s", buf);
						start += 1022;
						end += 1022;
						temp--;
					}
					if(temp == 0){
						f=1;	
						break;			
					}
		    		}

			}
 	              if(f == 1)
			break;
	    	}
	    		printf("------------------------\n\n\n");
	    		printf("super block structure after writing into file\n");
	    		sup->total_inodes = 1024;
	   		sup->total_datablocks = 999;
	   	 	printf("total inodes=%d\n\n", sup->total_inodes);
	    		printf("total data blocks=%d\n\n", sup->total_datablocks);
	    		printf("free inodes=%d\n\n", sup->free_inodes);
	    		printf("free datablocks=%d\n\n", sup->free_datablocks);
	    		printf("-------------------------\n\n\n");
		}
		else
			printf("no enough space for writting only 5 blocks are allowed\n");
	}
    }
}
