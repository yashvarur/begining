#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

void elf_header(Elf32_Ehdr *header_p);
void section_header( FILE *fp);
void program_header(FILE *fp);
void dynamic_section(FILE*fp);
void section_to_segment(FILE*fp);
void relocation_dyn(FILE*fp);
char* rel_type(Elf32_Word i);
void dynsym(FILE*fp);
void symtab( FILE*fp );
void relocation_section(FILE*fp);
