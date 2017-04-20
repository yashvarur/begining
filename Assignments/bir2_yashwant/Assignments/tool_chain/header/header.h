#include<stdio.h>
#include<stdlib.h>
#include<elf.h>
void elf_header(Elf32_Ehdr *header_p);
void section_header( FILE *fp);
void program_header(FILE *fp);
