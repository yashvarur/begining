#include<malloc.h>
#include<string.h>
#include<unistd.h>
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
void display_file(struct inode_table *itp, int *dp);
void remove_file(struct inode_table *itp, int *, int *,struct super_block *sup);
char *strcpy1(char * str1, char * str2, int i, int j);
void write_file(struct inode_table *itp, int *dbp, int *sp, int *ip,struct super_block *sup, int *dp);
int count;
void list_file(struct inode_table *itp, int *ibp);
void create_file(int *ip, struct inode_table *itp, struct super_block *sup);
