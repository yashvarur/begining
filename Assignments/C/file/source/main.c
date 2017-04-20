#include"header.h"
int main()
{
    struct inode_table *itp;
    struct super_block *sup;
    int *sp;
    int *dbp;
    int *ibp;
    int *ip;
    int *dp;
    int *ptr;
    int k;
    int choice = 0;
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
    for (k = 31; k >= 7; k--) {		/*n setting the first 25 bits t0 1 in datablock bitmap */
	*dbp = *dbp | (1 << k);
    }		
 
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
    while(1) {
	printf("\t\t1-create-file\n");
	printf("\t\t2-list-filename\n");
	printf("\t\t3-writing-file\n");
	printf("\t\t4-remove file\n");
	printf("\t\t5-display file content\n");
	printf("\t\t6-exit\n");
	printf("enter your choice\n");
	choice = int_read();
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
	case 6: 
	      exit(0);	
	      break;
	default:printf("enter the valid choice\n");
		break;

	}
    } 
    return 0;

}

