#include"header.h"
void section_header(FILE *fp)
{
	int i;
	Elf32_Shdr *s;
	Elf32_Ehdr *h;
	char *buf;
	h = (Elf32_Ehdr*) malloc(sizeof(Elf32_Ehdr));
	s = (Elf32_Shdr*)malloc(30*sizeof(Elf32_Shdr));
	fread(h,sizeof(Elf32_Ehdr),1,fp);
	rewind(fp);
	fseek(fp,h -> e_shoff,0);
	//printf("%ld\n",ftell(fp));
	fread(s,30*sizeof(Elf32_Shdr),1,fp);
	if(NULL==(buf = malloc(s[h->e_shstrndx].sh_size))) {
		printf("failed to allocate memory\n");
		exit(0);
	}
	fseek(fp,s[h->e_shstrndx].sh_offset,SEEK_SET);
	fread(buf,s[h->e_shstrndx].sh_size,1,fp);
	printf("[Nr] Name\t\ttype\t\tAddr\t  Off\t  Size\t  ES Flg   LK Inf  Al");
	printf("\n");
	i = 0;
	while(i < 30) {
		printf("[%2d] ",i);
		printf("%-20s",s[i].sh_name+buf);
		if(s[i].sh_type == SHT_NULL) 
			printf("%-15s","NULL");
		else if(s[i].sh_type == SHT_RELA)
                        printf("%-15s","REL");
		 else if(s[i].sh_type == SHT_REL)
                        printf("%-15s","REL");
		else if(s[i].sh_type == SHT_PROGBITS)
			printf("%-15s","PROGBITS");
		else if(s[i].sh_type == SHT_SYMTAB)
			printf("%-15s","SYMTAB");
		else if(s[i].sh_type == SHT_STRTAB)
			printf("%-15s","STRTAB");
		else if(s[i].sh_type == SHT_DYNAMIC)
			printf("%-15s","DYNAMIC");
		else if(s[i].sh_type == SHT_NOBITS)
			printf("%-15s","NOBITS");
		else if(s[i].sh_type == SHT_HASH)
                        printf("%-15s","HASH");
		else if(s[i].sh_type == SHT_NOTE)
                        printf("%-15s","NOTE");
		else if(s[i].sh_type == SHT_SHLIB)
                        printf("%-15s","RESERVED");
		else if(s[i].sh_type == SHT_DYNSYM)
                        printf("%-15s","DYNSYM");
		else if(s[i].sh_type == SHT_INIT_ARRAY)
                        printf("%-15s","INIT_ARRAY");
		else if(s[i].sh_type == SHT_FINI_ARRAY)
                        printf("%-15s","FNIT_ARRAY");
		else if(s[i].sh_type == SHT_PREINIT_ARRAY)
                        printf("%-15s","PREINIT_ARRAY");
		else if(s[i].sh_type == SHT_SHLIB)
                        printf("%-15s","SHLIB");
		else if(s[i].sh_type == SHT_GROUP)
                        printf("%-15s","GROUP");
		else if(s[i].sh_type == SHT_SYMTAB_SHNDX)
                        printf("%-15s","SYMTAB_SHNDX");
		else if(s[i].sh_type == SHT_NUM)
                        printf("%-15s","NUM");
		else if(s[i].sh_type == SHT_LOOS)
                        printf("%-15s","LOOS");
		else if(s[i].sh_type == SHT_GNU_ATTRIBUTES)
                        printf("%-15s","GNU_ATTRIBUTES");
		else if(s[i].sh_type == SHT_GNU_HASH)
                        printf("%-15s","GNU_HASH");
		else if(s[i].sh_type == SHT_GNU_LIBLIST)
                        printf("%-15s","GNU_LIBLIST");
		else if(s[i].sh_type == SHT_CHECKSUM )
                        printf("%-15s","CHECKSUM");
		else if(s[i].sh_type == SHT_LOSUNW  )
                        printf("%-15s","LOSUNW");
		else if(s[i].sh_type == SHT_SUNW_move)
                        printf("%-15s","SUNW_move");
		else if(s[i].sh_type == SHT_SUNW_COMDAT)
                        printf("%-15s","SUNW_COMDAT");
		else if(s[i].sh_type == SHT_SUNW_syminfo)
                        printf("%-15s","SUNW_syminfo");
		else if(s[i].sh_type == SHT_GNU_verdef )
                        printf("%-15s","GNU_verdef");
		else if(s[i].sh_type == SHT_GNU_verneed)
                        printf("%-15s","VERNEED");
		else if(s[i].sh_type == SHT_GNU_versym )
                        printf("%-15s","VERSYM");
		else if(s[i].sh_type == SHT_HISUNW )
                        printf("%-15s","HISUNW");
		else if(s[i].sh_type == SHT_HIOS )
                        printf("%-15s","HIOS");
		else if(s[i].sh_type == SHT_LOPROC)
                        printf("%-15s","LOPROC");
		else if(s[i].sh_type == SHT_LOUSER)
                        printf("%-15s","OUSER");
		else if(s[i].sh_type == SHT_HIUSER)
                        printf("%-15s","SHT_HIUSER");
		printf("%08x  ",s[i].sh_addr);
		printf("%06x  ",s[i]. sh_offset);
		printf("%06x  ",s[i].sh_size);
		printf("%02d  ",s[i].sh_entsize);
		switch(s[i].sh_flags) {
			case 0:
				printf("%-3s"," ");
				break;
			case 2:
				printf("%-3s"," A");
				break;
			case 3:
				printf("%-3s","WA");
				break;
			case 6:
				printf("%-3s","AX");
				break;
			case 48:
				printf("%-3s","MS");
				break;
			}
		printf("  %2d",s[i].sh_link);
		printf("  %2d",s[i].sh_info);
		printf("  %2d",s[i].sh_addralign);
		printf("\n");	
		i++;
	}
	
	printf("Key to Flags:\n");
  printf("\tW (write), A (alloc), X (execute), M (merge), S (strings)\n");
  printf("\tI (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)\n");
  printf("\tO (extra OS processing required) o (OS specific), p (processor specific\n");
	
}
