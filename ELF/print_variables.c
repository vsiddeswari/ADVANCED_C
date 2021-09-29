#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<elf.h>

Elf64_Sym symtab;
Elf64_Ehdr header;
Elf64_Shdr section,section1;

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		printf("Elf file missing..\n");
		exit(0);
	}

	FILE *fptr;
	char *snames;
	char *name;
	char *strtab;
	char *var;
	int data,i,ptr;

	fptr = fopen(argv[1],"r");
	if(fptr == NULL)
	{
		printf("file not opened..\n");
		exit(0);
	}

	fread(&header,1,sizeof(header),fptr);

	fseek(fptr,header.e_shoff+(header.e_shstrndx * header.e_shentsize),SEEK_SET);
	fread(&section,1,sizeof(section),fptr);

	snames = (char *)malloc(section.sh_size);

	fseek(fptr,section.sh_offset,SEEK_SET);
	fread(snames,1,section.sh_size,fptr);
	
	for(i=0;i<header.e_shnum;i++)
	{
		fseek(fptr,header.e_shoff+i*header.e_shentsize,SEEK_SET);
		fread(&section,1,sizeof(section),fptr);
		name = snames+section.sh_name;
		if(strcmp(name,".data")==0)
		{
			data = i;
		}
		if(strcmp(name,".strtab")==0)
		{
			
			strtab = (char *)malloc(section.sh_size);
			fseek(fptr,section.sh_offset,SEEK_SET);
			fread(strtab,1,sizeof(section.sh_size),fptr);
			
			

		}
		if(strcmp(name,".symtab")==0)
		{
			fseek(fptr,-64,SEEK_CUR);
			fread(&section1,1,sizeof(section1),fptr);
		}
	}

	for(i=0;i<77;i++)
	{
		fseek(fptr,section1.sh_offset+(i*sizeof(symtab)),SEEK_SET);
		fread(&symtab,1,sizeof(symtab),fptr);
		if(data == symtab.st_shndx && symtab.st_info == (STB_LOCAL|STB_GLOBAL)&&STT_OBJECT)
		{
			fseek(fptr,symtab.st_value-0x1000,SEEK_SET);
			fread(&ptr,1,4,fptr);
			var = strtab+symtab.st_name;
			printf("%s = ",var);
			printf("%d\n",ptr);
		
		}

	}


	return 0;
}


