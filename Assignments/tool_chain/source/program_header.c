#include"header.h"
void program_header(FILE *fp)
{

	int i;
        Elf32_Ehdr *h;
	Elf32_Phdr *p;
	char *buf1;
        h = (Elf32_Ehdr*) malloc(sizeof(Elf32_Ehdr));
	fread(h,sizeof(Elf32_Ehdr),1,fp);
        rewind(fp);
	p = (Elf32_Phdr*)malloc(9*sizeof(Elf32_Phdr));
	 if(NULL ==(buf1 = malloc(p->p_filesz))) {
                perror("error \n");
                exit(0);
        }

        fseek(fp,h -> e_phoff,0);
        fread(p,9*(sizeof(Elf32_Phdr)),1,fp);
	if(h -> e_phnum == 0) {
		printf("There are no section groups in this file.\n");
		return;
	}
	printf("Program Header:\n");
	printf("  Type          Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align\n");
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
		printf("0x%06x ",p[i].p_offset);
		printf("0x%08x ",p[i].p_vaddr);
		printf("0x%08x ",p[i].p_paddr);
		printf("0x%05x ",p[i].p_filesz);
		printf("0x%05x ",p[i].p_memsz);
		switch(p[i].p_flags) {
		case PF_X:
			printf("  X");
			break;
		case PF_W:
			printf(" W ");
			break;
		case PF_R:
			printf("R  ");	
			break;
		case PF_MASKOS:
			printf("OS");
			break;
		case (PF_R | PF_W):
			printf("RW ");
			break;
		case (PF_R | PF_X):
			printf("R E");
			break;
		case (PF_W | PF_X):
			printf(" WE");
			break;
		case PF_MASKPROC:
			printf("PROC");
			break;
		}
		printf("  0x%x",p[i].p_align);
		printf("\n");
		if(p[i].p_type == PT_INTERP) {
			fread(buf1,p[i].p_filesz,1,fp);
			printf("  [Requesting program interpreter:%s]\n",buf1);
		}
		i++;		

	}
}

	
