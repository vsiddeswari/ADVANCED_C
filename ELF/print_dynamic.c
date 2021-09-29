

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
 Elf64_Dyn dynamic;
char *dynstr;
 FILE *fptr;
 char *snames;
 int i;
char *name;
char *library;

 fptr=fopen(argv[1],"r");
if(fptr==NULL)
{
printf("file not opened\n");
exit(0);
}
 fread(&header,1,sizeof(header),fptr);

 fseek(fptr,header.e_shoff+header.e_shstrndx*header.e_shentsize,SEEK_SET);
fread(&section,1,sizeof(section),fptr); 
fseek(fptr,section.sh_offset,SEEK_SET);
 snames=(char *)malloc(section.sh_size);


 fread(snames,1,section.sh_size,fptr);

 for(i=0;i<header.e_shnum;i++)
 {
	 fseek(fptr,header.e_shoff+(i*header.e_shentsize),SEEK_SET);
	 fread(&section,1,sizeof(section),fptr);
	name=section.sh_name+snames;
	if(strcmp(name,".dynstr")==0)
{
dynstr=(char*)malloc(section.sh_size);
fseek(fptr,section.sh_offset,SEEK_SET);
fread(dynstr,1,section.sh_size,fptr);
}
if(strcmp(name,".dynamic")==0)
{
fseek(fptr,section.sh_offset,SEEK_SET);
fread(&dynamic,1,sizeof(dynamic),fptr);
library = dynamic.d_un.d_val+dynstr;
break;
}
}
printf("library: %s\n",library);
}

