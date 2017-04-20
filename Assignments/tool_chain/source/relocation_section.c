# include "header.h"
void relocation_section(FILE*fp)
{
	Elf32_Rel *r;
	Elf32_Shdr *s;
	Elf32_Ehdr *h;
	Elf32_Sym *sym;
	int i,j;
	int temp;
	char *buf;
	h = (Elf32_Ehdr*) malloc(sizeof(Elf32_Ehdr));
        s = (Elf32_Shdr*)malloc(30*sizeof(Elf32_Shdr));
	fread(h,sizeof(Elf32_Ehdr),1,fp);
	printf("\nrel.plt\n");
        rewind(fp);
        fseek(fp,h->e_shoff,0);
	fread(s,30*sizeof(Elf32_Shdr),1,fp);
	if(NULL==(buf = malloc(s[h->e_shstrndx].sh_size))) {
                printf("failed to allocate memory\n");
                exit(0);
        }
        fseek(fp,s[h->e_shstrndx].sh_offset,SEEK_SET);
        fread(buf,s[h->e_shstrndx].sh_size,1,fp);

	r = (Elf32_Rel*)malloc(13*sizeof(Elf32_Rel));
	for(i = 0;i < 30 ; i++) {
                if(!(strcmp(s[i].sh_name+buf,".rel.plt"))) {
                        break;
                }
        }
	rewind(fp);
	fseek(fp,s[i].sh_offset,SEEK_SET);
	fread(r,s[i].sh_size,1,fp);
	temp = s[i].sh_link;
	sym = (Elf32_Sym *)malloc( s[temp].sh_size);
	fseek(fp,s[temp].sh_offset,0);
	fread(sym,s[temp].sh_size,1,fp);
	temp = s[temp].sh_link;	
	printf("\n\nrelocation table rel.plt\n");
	printf("Offset    \tInfo\n");
	for(j = 0 ; j< s[i].sh_size/s[i].sh_entsize ; j++) {
		printf("%08x\t",r[j].r_offset);
		printf("%08x\t", r[j].r_info);	
		switch(ELF32_R_TYPE(r[j].r_info)) {
			case R_386_NONE:printf("R_386_NONE");
				break;
			case R_386_32:printf("R_386_32");
				break;
			case R_386_PC32:printf("R_386_PC32");
				break;
			case R_386_GOT32: printf("R_386_GOT32"); 	
				break;
			case R_386_PLT32:printf("R_386_PLT32");
				break;
			case R_386_COPY:printf("R_386_COPY");
				break;
			case R_386_GLOB_DAT:printf("R_386_GLOB_DAT");
				break;
			case R_386_JMP_SLOT:printf("R_386_JMP_SLOT");
				break;
			case R_386_RELATIVE:printf("R_386_RELATIVE");
				break;
			case R_386_GOTOFF:printf("R_386_GOTOFF");
				break;
			case R_386_GOTPC:printf("R_386_GOTPC");
				break;
			case R_386_32PLT:printf("R_386_32PLT");
				break;
			case R_386_TLS_TPOFF:printf("R_386_TLS_TPOFF");
				break;
			case R_386_TLS_IE:printf("R_386_TLS_IE");
				break;
			case R_386_TLS_GOTIE:printf("R_386_TLS_GOTIE");
				break;	
			case R_386_TLS_LE:printf("R_386_TLS_LE ");
				break;
			case R_386_TLS_GD:printf("R_386_TLS_GD");
				break;
			case R_386_TLS_LDM :printf("R_386_TLS_LDM");
				break;
			case R_386_16 :printf("R_386_16 ");
				break; 
		}
		printf(" %08x ",sym[ELF32_R_SYM(r[j].r_info)].st_value);
		char *buff1 = (char *)malloc(s[temp].sh_size);
		fseek(fp,s[temp].sh_offset,0);
		fread(buff1,s[temp].sh_size,1,fp);
		printf(" %s ",sym[ELF32_R_SYM(r[j].r_info)].st_name + buff1);
		printf("\n");	
	}
	printf("\nThe decoding of unwind sections for machine type Intel 80386 is not currently supported.\n");
}

		
		
		


	
	
	

	



