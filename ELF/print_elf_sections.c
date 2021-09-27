

#include<stdio.h>
#include<elf.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv) 
 {
 if(argc < 2) {
	 printf("usage: %s <ELF_FILE>\n", argv[0]);
         exit(1);
 }
 Elf64_Ehdr header;
 Elf64_Shdr section;
 Elf32_Addr address;
 FILE *fptr;
 char *snames;
 int i;

 fptr=fopen(argv[1],"r");

 fread(&header,1,sizeof(header),fptr);

 fseek(fptr,header.e_shoff+header.e_shstrndx*sizeof(section),SEEK_SET);

 fread(&section,1,sizeof(section),fptr);

 snames=(char *)malloc(section.sh_size);

 fseek(fptr,section.sh_offset,SEEK_SET);

 fread(snames,1,section.sh_size,fptr);

 for(i=0;i<header.e_shnum;i++)
 {
	 char *name="";
	 fseek(fptr,header.e_shoff+i*sizeof(section),SEEK_SET);
	 fread(&section,1,sizeof(section),fptr);
	 if(section.sh_name)
	 {
		 name=snames+ section.sh_name;
	 }
	 printf("%2u %s\n",i,name);
 }

}
