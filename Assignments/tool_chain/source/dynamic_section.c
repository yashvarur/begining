# include "header.h"
void dynamic_section(FILE *fp)
{
	Elf32_Shdr *s;
        Elf32_Ehdr *h;
	Elf32_Dyn *d;
	int i;
        char *buf;
        h = (Elf32_Ehdr*) malloc(sizeof(Elf32_Ehdr));
        s = (Elf32_Shdr*)malloc(30*sizeof(Elf32_Shdr));
	d = (Elf32_Dyn*)malloc(24*sizeof(Elf32_Dyn));
        fread(h,sizeof(Elf32_Ehdr),1,fp);
        rewind(fp);
	char *b;
        fseek(fp,h->e_shoff,0);
        //printf("%ld\n",ftell(fp));
        fread(s,30*sizeof(Elf32_Shdr),1,fp);
        if(NULL==(buf = malloc(s[h->e_shstrndx].sh_size))) {
                printf("failed to allocate memory\n");
                exit(0);
        }
        fseek(fp,s[h->e_shstrndx].sh_offset,SEEK_SET);
        fread(buf,s[h->e_shstrndx].sh_size,1,fp);
	
	for(i = 0;i < 30 ; i++) {
		if(!(strcmp(s[i].sh_name+buf,".dynamic"))) {
			break;
		}	
	}
	rewind(fp);
	fseek(fp,s[6].sh_offset,0);
	b = malloc(s[6].sh_size);
	fread(b,s[6].sh_size,1,fp);
	int num;
	num = (s[i].sh_size)/10;
	printf("Dynamic section at offset 0x%x contains  %d entries:\n",s[i].sh_offset,num+1);
	rewind(fp);
	fseek(fp, s[i].sh_offset,0);
	fread(d,24*sizeof(Elf32_Dyn),1,fp);
	printf("Tag\t    Type\t\tName\\Value\n");
	for(i = 0;i <= num ; i++) {
		printf("0x%08x  ",d[i].d_tag);
		switch(d[i].d_tag) {
			case DT_NULL:
					printf("%s\t\t0x0","NULL");
						break;
			case DT_NEEDED:
					printf("(NEEDED)");
					printf("\t\tShared library:%s",++b);
						break;
			case DT_PLTRELSZ:
					printf("%s\t\t%d (bytes)","(PLTRELSZ)",d[i].d_un.d_val);
						break;
			case DT_PLTGOT  :
					printf("%s\t\t0x%07x","(PLTGOT)",d[i].d_un.d_ptr);
						break;
			case DT_HASH    :
					printf("%s\t\t0x%07x","(GNU_HASH)",d[i].d_un.d_ptr);
						break;
			case DT_STRTAB:
					printf("%s\t\t0x%07x","(STRTAB)",d[i].d_un.d_ptr);
						break;
			case DT_SYMTAB:
					printf("%s\t\t0x%07x","(SYMTAB)",d[i].d_un.d_ptr);
						break;
			case  DT_RELA :
					printf("%s\t\t0x%07x","(RELA)",d[i].d_un.d_ptr);
						break;
			case DT_RELASZ:
					printf("%s\t\t%d(bytes)","(RELSZ)",d[i].d_un.d_val);
						break;
			case DT_RELAENT :
					printf("%s\t\t%d(bytes)","(RELAENT)",d[i].d_un.d_val);
						break;
			case DT_STRSZ:
					printf("%s\t\t%d(bytes)","(STRSZ)",d[i].d_un.d_val);
						break;
			case  DT_SYMENT :
					printf("%s\t\t%d(bytes)","(SYMENT)",d[i].d_un.d_val);
						break;
			case DT_INIT :
					printf("%s\t\t%07x","(INIT)",d[i].d_un.d_ptr);
						break;
			case DT_FINI :
					printf("%s\t\t0x%07x","(FINI)",d[i].d_un.d_ptr);
						break;
			case DT_SONAME:
					printf("(SONAME)");
						break;
			case  DT_RPATH :
					printf("(RPATH)");
						break;
			case DT_GNU_HASH:
					printf("%s\t\t0x%07x","(GNU_HASH)",d[i].d_un.d_ptr);
						break;
			case DT_REL :
					printf("%s\t\t0x%07x","(REL)",d[i].d_un.d_ptr);
						break;
			case DT_RELSZ :
					printf("%s\t\t%d(bytes)","(RELSZ)",d[i].d_un.d_val);
						break;
			case DT_RELENT :
					printf("%s\t\t%d(bytes)","(RELENT)",d[i].d_un.d_val);
						break;
			case DT_PLTREL:
					printf("%s\t\t%s","(PLTREL)","REL");
						break;
			case DT_DEBUG:
					printf("%s\t\t0x0","(DEBUG)");
						break;
			case DT_TEXTREL :
					printf("(TEXTREL)");
						break;
			case DT_JMPREL  :
					printf("%s\t\t0x%07x","(JMPREL)",d[i].d_un.d_ptr);
						break;
			case DT_BIND_NOW:
					printf("(BIND_NOW)");
						break;
			case DT_INIT_ARRAY:
					printf("%s\t0x%07x","(INIT_ARRAY)",d[i].d_un.d_ptr);
						break;
			case DT_FINI_ARRAY :
					printf("%s\t0x%07x","(FINI_ARRAY)",d[i].d_un.d_ptr);
						break;
			case DT_INIT_ARRAYSZ:
					printf("%s\t%d(bytes)","(INIT_ARRAYSZ)",d[i].d_un.d_val);
						break;
			case DT_FINI_ARRAYSZ :
					printf("%s\t%d(bytes)","(FINI_ARRAYSZ)",d[i].d_un.d_val);
						break;
			case DT_RUNPATH:
					printf("(RUNPATH)");
						break;
			case DT_FLAGS :
					printf("(FLAGS)");
						break;
			case DT_ENCODING :
					printf("(ENCODING)");
						break;
			case DT_PREINIT_ARRAYSZ:
					printf("(PREINIT_ARRASZ)");
						break;
			case DT_NUM  :
					printf("(NUM)");
						break;
			case DT_LOOS:
					printf("LOOS");
						break;
			case DT_HIOS   :
					printf("(HIOS)");
						break;

			case DT_LOPROC  :
					printf("(LOPROC)");
						break;
			case DT_HIPROC :
					printf("(HIPROC)");
						break;
			case DT_PROCNUM :printf("(PROCNUM)");
                                                break;
		/*	case  DT_VERDEFNUM:
					  printf("%s\t%d","VERDEFNUM","VERDEFNUM");
						break;*/
			case DT_VERNEED:
					printf("%s\t\t0x%07x","VERNEED",d[i].d_un.d_ptr);
						break;
			case DT_VERNEEDNUM:
					printf("%s\t\t%d","VERNEEDNUM",1);
						break;
			case 	DT_VERSYM :
						printf("%s\t\t0x%07x","VERSYM",d[i].d_un.d_ptr);
						break;
			
				
					 
		}
		
//		printf("\t%s",d[i].d_val);
	printf("\n");	
	}
}
	
	
