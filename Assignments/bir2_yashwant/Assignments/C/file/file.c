#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define SIZE 4096
#define ALIGN 1024*1024
struct super_block {
    unsigned int total_inodes;
    unsigned int total_datablocks;
    unsigned int free_inodes;
    unsigned int free_datablocks;
};

struct inode_table {
    unsigned int i_no;
    unsigned int size;
    unsigned int blk_used;
    unsigned short blk[5];
    unsigned char fname[8];
};
void display_file(struct inode_table *itp, int *);
void remove_file(struct inode_table *itp, int *, int *,
		 struct super_block *sup);
char *strcpy1(char *, char *, int, int);
void write_file(struct inode_table *itp, int *dbp, int *, int *,
		struct super_block *sup, int *dp);
int count = 0;
void list_file(struct inode_table *itp, int *ip);
void create_file(int *, struct inode_table *, struct super_block *);
int main()
{
    struct inode_table *itp;
    struct super_block *sup;
    int count = 0;
    int *sp;
    int *dbp;
    int *ibp;
    int *ip;
    int *dp;
    int *ptr;
    char *file;
    int k, choice;
    int c = 1;
    int i;
    if ((ptr = (int *) memalign(SIZE, ALIGN)) == NULL) {
	perror("error in memory allocation\n");
	exit(0);
    }
    sup = (struct super_block *) ptr;
    sp = ptr;
    dbp = ptr + 256;
    ibp = dbp + 256;
    ip = ibp + 256;
    itp = (struct inode_table *) ip;
    dp = ip + (256 * 22);

    for (k = 31; k >= 7; k--) {
	*dbp = *dbp | (1 << k);
    }
    printf("\nsetting the first 25 bits t0 1 in datablock bitmap\n");
    for (i = 31; i >= 0; i--)
	printf("%d", (*dbp & (1 << i)) ? 1 : 0);
    printf("\n");

    printf("\n\nsuper block structure\n");
    printf("\n---------------------------\n");
    sup->total_inodes = 1024;
    sup->total_datablocks = 999;
    sup->free_inodes = 1024;
    sup->free_datablocks = 999;
    printf("total inodes     =%d\n\n", sup->total_inodes);
    printf("total data blocks=%d\n\n", sup->total_datablocks);
    printf("free inodes      =%d\n\n", sup->free_inodes);
    printf("free datablocks  =%d\n\n", sup->free_datablocks);
    printf("----------------------------\n");
    do {
	printf("\t\t1-create-file\n");
	printf("\t\t2-list-filename\n");
	printf("\t\t3-writing-file\n");
	printf("\t\t4-remove file\n");
	printf("\t\t5-display file content\n");
	printf("\t\t0-exit\n");
	printf("enter your choice\n");
	scanf("%d", &choice);
	switch (choice) {
	case 1:
	    create_file(ibp, itp, sup);
	    break;
	case 2:
	    list_file(itp, ibp);
	    break;
	case 3:
	    write_file(itp, dbp, sp, ip, sup, dp);
	    break;
	case 4:
	    remove_file(itp, ibp, dbp, sup);
	    break;
	case 5:
	    display_file(itp, dp);
	    break;
	default:
	    exit(0);
	}
    } while (c == 1);
    return 0;

}

void create_file(int *ip, struct inode_table *itp, struct super_block *sup)
{

    char *file;
    int i;
    int d;
    int c = 1;
    int j;
    int pos;
    static int inode_num;
    int *temp;
    int size_file;
    inode_num = 0;	
    file = malloc(20);
    printf("\nenter the file name\n");
    read(0,file,8);  
    *(file + strlen(file) - 1) = '\0';
    for (i = 0; i < 1024; i++) {
	if (strcmp((itp + i)->fname, file) == 0) {
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
    strcpy((itp + pos)->fname, file);
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

void write_file(struct inode_table *itp, int *dbp, int *sp, int *ip,
		struct super_block *sup, int *dp)
{
    int i, j, c;
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
	    if (!(strcmp((itp + i)->fname, file))) {
		pos = i;
		k++;
		break;
	    }
	}
	printf("file found position = %d\n",pos);
	if (k == 0)
	    printf("file does not exist\n");
	else {
	    if((itp + pos)->blk_used < 5) {
	    read_content = (char *) malloc(5 * 1024);
	    printf("enter content of file\n");
	    size = read(0, read_content, 1024 * 5);
	    temp = size /1024;
	    temp1 = size % 1024;
	    if(temp1 != 0)
		temp = temp + 1;
		printf("temp =%d\n",temp);
	    printf("size of file = %d\n", size);
	    for (j = 0; j <= 31; j++) {
		(sup->free_datablocks)--;
		for (i = 31; i >= 0; i--) {
		    if (!(*(dbp + j) & (1 << i))) {
			*(dbp + j) = *(dbp + j) | (1 << i);
			printf("i=%d\n",i);
			 blk_index = (itp + pos)->blk_used;
			(itp + pos)->blk[blk_index] = (j * 32)  + (32 - i);
			(itp + pos)->blk_used += 1;
			printf("blk index = %d\n", (itp + pos)->blk[blk_index]);
			buf =
			    (char *) (sp) +
			    (((itp + pos)->blk[blk_index] - 1) * 1024);
			printf("buf adress=%p\n", buf);
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

char *strcpy1(char *str1, char *str2, int i, int j)
{
    int k = 0;
    while (i <= j) {
	*(str2 + k) = *(str1 + i);
	i++;
	k++;
    }

    *(str2 + k) = '\0';
    return (str2);

}

void remove_file(struct inode_table *itp, int *ibp, int *dbp,
		 struct super_block *sup)
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
	    if (!(strcmp((itp + i)->fname, file))) {
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
             for (i = 31; i >= 0; i--) {
                 printf("%d", ((*dbp >> i) & 1) ? 1 : 0);
                 if(!(i%8))
                	printf("\t");
        	}
            printf("\n");
		
	    t = (itp + pos)->blk_used;
	    for (j = 0; j < t; j++) {
		printf("blk in remove%d\n",(itp+pos)->blk[j]);
		 *(dbp + (itp+pos)->blk[j] / 32) &= (~(1 << (32 - (itp+pos)->blk[j])));
	    }
	 
	    printf("file %s is successfully removed\n",(itp + pos)->fname);
	    strcpy((itp + pos)->fname, "");
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
	    if (!(strcmp((itp + i)->fname, file))) {
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
