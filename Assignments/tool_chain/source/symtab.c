# include <header.h>

void symtab( FILE*fp )
{
	Elf32_Ehdr *h;
	Elf32_Shdr *s;
        Elf32_Sym *sym;
        int temp;
        char *buf;
        int i;
        int j;

        h = (Elf32_Ehdr*) malloc(sizeof(Elf32_Ehdr));
        s = (Elf32_Shdr*)malloc(30*sizeof(Elf32_Shdr));
        fread(h,sizeof(Elf32_Ehdr),1,fp);
        rewind(fp);
        fseek(fp,h->e_shoff,0);
        fread(s,30*sizeof(Elf32_Shdr),1,fp);
        if(NULL==(buf = malloc(s[h->e_shstrndx].sh_size))) {
                printf("failed to allocate memory\n");
                exit(0);
        }
        fseek(fp,s[h->e_shstrndx].sh_offset,SEEK_SET);
        fread(buf,s[h->e_shstrndx].sh_size,1,fp);
        for(i = 0;i < 30 ; i++) {
                if(!(strcmp(s[i].sh_name+buf,".symtab"))) {
                        break;
                }
        }
	rewind(fp);
	fseek(fp,s[i].sh_offset,0);
	sym = malloc(s[i].sh_size);
	fread(sym,s[i].sh_size,1,fp);
	printf("sh_size = %d\n",s[i].sh_size);
	printf("sh_entsize = %d\n",s[i].sh_entsize);
	temp = s[i].sh_link;
        fseek(fp,s[temp].sh_offset,0);
        char *buff1 = (char *)malloc(s[temp].sh_size);
        fread(buff1,s[temp].sh_size,1,fp);
	for(j = 0 ; j < s[i].sh_size/s[i].sh_entsize ; j++ ) {
                printf("%03d",j);
                printf("%08x  ",sym[j].st_value);
                printf("%4d   ",sym[j].st_size);
                switch(ELF32_ST_TYPE(sym[j].st_info)) {
                        case STT_NOTYPE:printf("%-7s","NOTYPE");
                                break;
                        case STT_OBJECT:printf("%-7s","OBJECT");
                                        break;
                        case  STT_FUNC:printf("%-7s","FUNC");
                                        break;
                        case STT_SECTION:printf("%-7s","SECTION");
                                        break;
                        case STT_FILE:printf("%-7s","FILE");
                                        break;
                        case STT_COMMON:printf("%-7s","COMMON");
                                        break;
                        case STT_TLS:printf("%-7s","TLS");
                                        break;
                        case STT_NUM:printf("%-7s","NUM");
                                        break;
                        case STT_GNU_IFUNC:printf("%-7s","IFUNC");
                                        break;
                        case STT_HIOS :printf("%-7s","HIOS");
                                        break;
                        case STT_LOPROC:printf("%-7s","LOPROC");
                                        break;
                        case STT_HIPROC:printf("%-7s","HIPROC");
                                        break;

                }
		 printf("   ");
                switch(ELF32_ST_BIND(sym[j].st_info))  {
                        case STB_LOCAL:printf("%-7s","LOCAL");
                                        break;
                        case  STB_GLOBAL:printf("%-7s","GLOBAL");
                                        break;
                        case  STB_WEAK:printf("%-7s","WEAK");
                                        break;
                        case  STB_NUM:printf("%-7s","NUM");
                                        break;
                        case  STB_GNU_UNIQUE:printf("%-7s","UNIQUE");
                                        break;
                        case  STB_HIOS:printf("%-7s","HIOS");
                                        break;
                        case   STB_LOPROC:printf("%-7s","LOPROC");
                                        break;
                        case  STB_HIPROC:printf("%-7s","STB_HIPROC");
                                        break;
                }
                printf("  ");
                switch(ELF32_ST_VISIBILITY(sym[j].st_other)) {
                        case STV_DEFAULT:printf("%-7s","DEFAULT");
                                        break;
                        case STV_INTERNAL:printf("%-7s","INTERNAL");
                                        break;
                        case STV_HIDDEN:printf("%-7s","HIDDEN");
                                        break;
                        case STV_PROTECTED:printf("%-7s","PROTECTED");
                                        break;
                }
	 	printf(" %s ",sym[j].st_name + buff1);
		printf("\n");
	}
}

