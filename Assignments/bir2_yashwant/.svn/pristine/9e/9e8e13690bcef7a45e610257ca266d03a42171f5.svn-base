#include"header.h"
void section_header(FILE *fp)
{
	int i;
	Elf32_Shdr *s;
	Elf32_Ehdr *h;
	h = (Elf32_Ehdr*) malloc(sizeof(Elf32_Ehdr));
	s = (Elf32_Shdr*)malloc(30*sizeof(Elf32_Shdr));
	fread(h,sizeof(Elf32_Ehdr),1,fp);
	rewind(fp);
	fseek(fp,h -> e_shoff,0);
	printf("%ld\n",ftell(fp));
	fread(s,30*sizeof(Elf32_Shdr),1,fp);
	printf("[Nr] Name\t\t\t\ttype\t\tAddr\t\tOff\t\tSize\tES\tFlg\tLK\tInf\tAl");
	printf("\n");
	i = 0;
	while(i < 30) {
		printf("[%d]\t\t",i);
		if(s[i].sh_type == SHT_NULL) 
			printf("\t\t\tNULL\t");
		else if(s[i].sh_type == SHT_RELA)
                        printf("\t\t\tREL\t");
		 else if(s[i].sh_type == SHT_REL)
                        printf("\t\t\tREL\t");
		else if(s[i].sh_type == SHT_PROGBITS)
			printf("\t\t\tPROGBITS");
		else if(s[i].sh_type == SHT_SYMTAB)
			printf("\t\t\tSYMTAB\t");
		else if(s[i].sh_type == SHT_STRTAB)
			printf("\t\t\tSTRTAB\t");
		else if(s[i].sh_type == SHT_DYNAMIC)
			printf("\t\t\tDYNAMIC\t");
		else if(s[i].sh_type == SHT_NOBITS)
			printf("\t\t\tNOBITS\t");
		else if(s[i].sh_type == SHT_HASH)
                        printf("\t\t\tHASH\t");
		else if(s[i].sh_type == SHT_NOTE)
                        printf("\t\t\tNOTE\t");
		else if(s[i].sh_type == SHT_SHLIB)
                        printf("\t\t\tRESERVED\t");
		else if(s[i].sh_type == SHT_DYNSYM)
                        printf("\t\t\tDYNSYM\t");
		else if(s[i].sh_type == SHT_INIT_ARRAY)
                        printf("\t\t\tINIT_ARRAY");
		else if(s[i].sh_type == SHT_FINI_ARRAY)
                        printf("\t\t\tFNIT_ARRAY");
		else if(s[i].sh_type == SHT_PREINIT_ARRAY)
                        printf("\t\t\tPREINIT_ARRAY");
		else if(s[i].sh_type == SHT_SHLIB)
                        printf("\t\t\tSHLIB\t");
		else if(s[i].sh_type == SHT_GROUP)
                        printf("\t\t\tGROUP\t");
		else if(s[i].sh_type == SHT_SYMTAB_SHNDX)
                        printf("\t\t\tSYMTAB_SHNDX");
		else if(s[i].sh_type == SHT_NUM)
                        printf("\t\t\tNUM\t");
		else if(s[i].sh_type == SHT_LOOS)
                        printf("\t\t\tLOOS");
		else if(s[i].sh_type == SHT_GNU_ATTRIBUTES)
                        printf("\t\t\tGNU_ATTRIBUTES");
		else if(s[i].sh_type == SHT_GNU_HASH)
                        printf("\t\t\tGNU_HASH");
		else if(s[i].sh_type == SHT_GNU_LIBLIST)
                        printf("\t\t\tGNU_LIBLIST");
		else if(s[i].sh_type == SHT_CHECKSUM )
                        printf("\t\t\tCHECKSUM\t");
		else if(s[i].sh_type == SHT_LOSUNW  )
                        printf("\t\t\tLOSUNW\t");
		else if(s[i].sh_type == SHT_SUNW_move)
                        printf("\t\t\tSUNW_move");
		else if(s[i].sh_type == SHT_SUNW_COMDAT)
                        printf("\t\t\tSUNW_COMDAT");
		else if(s[i].sh_type == SHT_SUNW_syminfo)
                        printf("\t\t\tSUNW_syminfo");
		else if(s[i].sh_type == SHT_GNU_verdef )
                        printf("\t\t\tGNU_verdef");
		else if(s[i].sh_type == SHT_GNU_verneed)
                        printf("\t\t\tVERNEED\t");
		else if(s[i].sh_type == SHT_GNU_versym )
                        printf("\t\t\tVERSYM\t");
		else if(s[i].sh_type == SHT_HISUNW )
                        printf("\t\t\tHISUNW\t");
		else if(s[i].sh_type == SHT_HIOS )
                        printf("\t\t\tHIOS\t");
		else if(s[i].sh_type == SHT_LOPROC)
                        printf("\t\t\tLOPROC");
		else if(s[i].sh_type == SHT_LOUSER)
                        printf("\t\t\tLOUSER\t");
		else if(s[i].sh_type == SHT_HIUSER)
                        printf("\t\t\tSHT_HIUSER");
		printf("\t%08x\t",s[i].sh_addr);
		printf("%06x\t",s[i]. sh_offset);
		printf("\t%06x\t",s[i].sh_size);
		printf("%02d\t",s[i].sh_entsize);
		if(s[i].sh_flags & SHF_WRITE)
			printf("W");
		if(s[i].sh_flags & SHF_ALLOC)
                        printf("A");
		if(s[i].sh_flags & SHF_EXECINSTR)
                        printf("X");
		if(s[i].sh_flags & SHF_MERGE )
                        printf("M");
		if(s[i].sh_flags & SHF_STRINGS )
                        printf("S");
		if(s[i].sh_flags & SHF_INFO_LINK  )
                        printf("I");
		if(s[i].sh_flags & SHF_LINK_ORDER )
                        printf("L");
		if(s[i].sh_flags & SHF_OS_NONCONFORMING )
                        printf("NC");
		if(s[i].sh_flags & SHF_GROUP)
                        printf("g");
		if(s[i].sh_flags & SHF_TLS)
                        printf("T");
		if(s[i].sh_flags & SHF_MASKOS)
                        printf("o");
		if(s[i].sh_flags & SHF_MASKPROC)
                        printf("P");
		if(s[i].sh_flags & SHF_ORDERED)
                        printf("O");
		printf("\t%d",s[i].sh_link);
		printf("\t%d",s[i].sh_info);
		printf("\t%d",s[i].sh_addralign);
		printf("\n");	
		i++;
	}	
}
