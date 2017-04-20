#include"header.h"

int main(int argc,char *argv[])
{
	
	FILE *fp;
	Elf32_Ehdr *header_p;

	if(NULL == (fp= fopen("./a.out","r"))) {
		perror("error in opening\n");
		exit(0);
	}
	header_p = (Elf32_Ehdr*) malloc(sizeof(Elf32_Ehdr));

	fread(header_p,sizeof(Elf32_Ehdr),1,fp);
	elf_header(header_p);
	fclose(fp);
	 if(NULL == (fp= fopen("./a.out","r"))) {
                perror("error in opening\n");
                exit(0);
        }
	section_header(fp);
	fclose(fp);
	if(NULL == (fp= fopen("./a.out","r"))) {
                perror("error in opening\n");
                exit(0);
        }
	program_header(fp);
	fclose(fp);
	 if(NULL == (fp= fopen("./a.out","r"))) {
                perror("error in opening\n");
                exit(0);
        }
	dynamic_section(fp);
	fclose(fp);	
	 if(NULL == (fp= fopen("./a.out","r"))) {
                perror("error in opening\n");
                exit(0);
        }
        relocation_dyn(fp);
        fclose(fp);
	
	if(NULL == (fp= fopen("./a.out","r"))) {
                perror("error in opening\n");
                exit(0);
        }
        relocation_section(fp);
        fclose(fp);
	if(NULL == (fp= fopen("./a.out","r"))) {
                perror("error in opening\n");
                exit(0);
        }
	dynsym(fp);
        fclose(fp);
	if(NULL == (fp= fopen("./a.out","r"))) {
                perror("error in opening\n");
                exit(0);
        }
        symtab(fp);
	fclose(fp);
	return 0;
}

