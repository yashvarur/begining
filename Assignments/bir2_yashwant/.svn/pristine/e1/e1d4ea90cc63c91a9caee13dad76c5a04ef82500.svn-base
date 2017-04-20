#include"header.h"
void program_header(FILE *fp)
{

	int i;
        Elf32_Ehdr *h;
	Elf32_Phdr *p;
        h = (Elf32_Ehdr*) malloc(sizeof(Elf32_Ehdr));
	fread(h,sizeof(Elf32_Ehdr),1,fp);
        rewind(fp);
	p = (Elf32_Phdr*)malloc(9*sizeof(Elf32_Phdr));
        fseek(fp,h -> e_phoff,0);
        fread(p,9*(sizeof(Elf32_Phdr)),1,fp);
	printf("Program Header:\n");
	printf("  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align\n");
	i = 0;
	while(i < 9) {
		printf("  ");
		if(p[i].p_type == PT_NULL)
			printf("            ");
		if(p[i].p_type == PT_LOAD)
			printf("LOAD        ");
		if(p[i].p_type ==  PT_DYNAMIC)
                        printf("DYNAMIC     ");
		if(p[i].p_type == PT_INTERP)
			printf("INTERP      ");
		if(p[i].p_type == PT_NOTE)
                        printf("NOTE        ");
		if(p[i].p_type == PT_SHLIB)
                        printf("SHLIB       ");
		if(p[i].p_type == PT_PHDR)
                        printf("PHDR        ");
		if(p[i].p_type == PT_TLS)
                        printf("TLS         ");
		if(p[i].p_type == PT_NUM)
                        printf("NUM         ");
		if(p[i].p_type == PT_LOOS)
                        printf("LOOS        ");
		if(p[i].p_type == PT_GNU_EH_FRAME)
                        printf("GNU_EH_FRAME");
		if(p[i].p_type == PT_GNU_STACK)
                        printf("GNU_STACK   ");
		if(p[i].p_type == PT_GNU_RELRO)
                        printf("GNU_RELRO   ");
		if(p[i].p_type == PT_LOSUNW)
                        printf("LOSUNW      ");
		if(p[i].p_type == PT_SUNWBSS)
                        printf("SUNWBSS     ");
		if(p[i].p_type ==  PT_SUNWSTACK)
                        printf("SUNWSTACK   ");
		if(p[i].p_type ==  PT_HISUNW)
                        printf("HISUNW      ");
		if(p[i].p_type ==  PT_HIOS )
                        printf("HIOS        ");
		if(p[i].p_type ==  PT_LOPROC )
                        printf("LOPROC      ");
		if(p[i].p_type ==  PT_HIPROC )
                        printf("HIPROC      ");

		printf("\t");
		printf("%x\t",p[i].p_offset);
		printf("%x",p[i].p_vaddr);
		printf("%x",p[i].p_memsz);
		printf("\n");
		i++;		

	}
}
	
