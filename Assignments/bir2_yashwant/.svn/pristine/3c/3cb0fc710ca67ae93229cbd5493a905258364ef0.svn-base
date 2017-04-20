#include"header.h"
void elf_header(Elf32_Ehdr *header_p)
{
	int i;
	printf("ELF Header:\n");
        printf("  Magic: ");
        for(i = 0 ; i < EI_NIDENT ;i++)
        printf("%02x ",header_p -> e_ident[i] );
        printf("\n");

        printf("  Class:                             " );
        if( header_p -> e_ident[4] == ELFCLASS32 )
                printf("ELF32");
        else if( header_p ->  e_ident[4] == ELFCLASSNONE)
                printf("invalid class\n");
        else if( header_p ->  e_ident[4] == EI_CLASS )
                printf("file class index\n");
        else if( header_p ->  e_ident[4] == ELFCLASS64 )
                printf("ELF64");
        printf("\n");
        printf("  Data:                     ");
        if( header_p ->  e_ident[5] ==  EI_DATA )
                printf(" Data encoding byte index");
        else if( header_p ->  e_ident[5] == ELFDATANONE )
                printf(" Invalid data encoding \n");
        else if( header_p ->  e_ident[5] == ELFDATA2LSB )
                printf("         2's complement, little endian");
        else if( header_p ->  e_ident[5]  == ELFDATA2MSB )
                printf(" 2's complement, big endian");
	 printf("\n  Version:                           ");
        if(header_p -> e_ident[6] ==  EV_NONE )
                printf("invalid ELF version\n");
        else if( header_p -> e_ident[6] == EV_CURRENT)
                printf("1 (current)\n");
        printf("  OS/ABI:                         ");
        if( header_p ->  e_ident[7] == ELFOSABI_NONE)
                printf("   UNIX - System V\n");
        printf("  ABI Version:                       ");
                printf("%d\n",header_p -> e_ident[8]);
          printf("  type:                              ");
        if( header_p->e_type == ET_EXEC )
                printf("EXEC (Executable file)\n");
        else if( header_p->e_type == ET_REL )
                printf("REL (Relocatable file)");
        else if( header_p->e_type ==  ET_NONE )
                printf("NO FILE TYPE\n");
        else if( header_p->e_type == ET_DYN )
                printf(" DYN (Shared object file)");
        else if( header_p->e_type ==  ET_CORE  )
                printf(" CORE (Core file)");
        else if( header_p->e_type ==  ET_NUM  )
                printf("Number of defined types");
        else if( header_p->e_type ==  ET_LOOS  )
                printf(" OS-specific range start");
        else if( header_p->e_type == ET_HIOS  )
                printf("  OS-specific range end ");
        else if( header_p->e_type == ET_LOPROC)
              printf("  Processor-specific range start ");
        else if( header_p->e_type ==ET_HIPROC )
             printf("  Processor-specific range ends");

        printf("  Machine                            ");
        if( header_p -> e_machine ==  EM_NONE )
                printf("No Machine\n");
        else if( header_p-> e_machine == EM_386 )
                printf("Intel 80386\n");
        printf("  Version:                           ");
        printf("0x%x\n",header_p -> e_version);
        printf("  Entry point address:               ");
 	printf("0x%x\n",header_p -> e_entry);
        printf("  Start of program headers:          ");
        printf("%d  (bytes into file)\n",header_p -> e_phoff);
        printf("  Start of section headers:          ");
        printf("%d(bytes into file)\n",header_p ->  e_shoff);
        printf("  Flags:                             ");
        printf("0x%d\n",header_p -> e_flags);
        printf("  Size of this header:               ");
        printf("%d (bytes)\n",header_p -> e_ehsize);
        printf("  Number of program headers:         ");
        printf("%d (bytes)\n",header_p -> e_phentsize);
        printf("  Number of program headers:         ");
        printf("%d\n",header_p -> e_phnum);
        printf("  Size of section headers:           ");
        printf("%d\n",header_p -> e_shentsize);
        printf("  Number of section headers:         ");
        printf("%d\n",header_p -> e_shnum);
        printf("  Section header string table index: ");
        printf("%d\n",header_p ->  e_shstrndx);
        
}
