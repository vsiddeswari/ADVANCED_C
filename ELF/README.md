   FILE LAYOUT:

Each ELF file is made up of one ELF header, followed by file data. The data can include:

Program header table, describing zero or more memory segments
Section header table, describing zero or more sections
Data referred to by entries in the program header table or section header table 

The segments contain information that is needed for run time execution of the file, while sections contain important data for linking and relocation. Any byte in the entire file can be owned by one section at most, and orphan bytes can occur which are unowned by any section.



00000000 7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 |.ELF............|

00000010 02 00 3e 00 01 00 00 00 c5 48 40 00 00 00 00 00 |..>......H@.....|

Example hexdump of ELF file header[4] 



FILE HEADER:



All ELF object files start with the ELF header. It is in binary but has the following data structure format:

# define EI_NIDENT 16
 
typedef struct {
unsigned char
e_ident[EI_NIDENT];
Elf64_Half e_type;
Elf64_Half e_machine;
Elf64_Word e_version;
Elf64_Addr e_entry;
Elf64_Off e_phoff;
Elf64_Off e_shoff;
Elf64_Word e_flags;
Elf64_Half e_ehsize;
Elf64_Half e_phentsize;
Elf64_Half e_phnum;
Elf64_Half e_shentsize;
Elf64_Half e_shnum;
Elf64_Half e_shstrndx;
} Elf64_Ehdr;


e_ident    : This variable marks the file as an ELF object file and provides information about the object file.
e_type     : This member determines the object file type.
e_machine  : This member specifies the architecture for which this ELF is compiled.
e_version  : This member provides information about the version of the ELF object file.
e_entry    : This is the entry point or the start address of the program.
e_phoff    : This member provides offset from the ELF header at which the program header is present.
e_shoff    : This member provides offset from the ELF header at which the section header is present.
e_flags    : This member holds processor specific tags.
e_ehsize   : This member holds the ELF header size in bytes.
e_phentsize: This member holds the size in bytes of one entry in the file’s program header table.
e_phnum    : This member holds the number of entries in the program header table.
E_shentsize: This member holds a section header’s size in bytes.


PROGRAM HEADER:

The program header table tells the system how to create a process image. It is found at file offset e_phoff, and consists of e_phnum entries, each with size e_phentsize. The layout is slightly different in 32-bit ELF vs 64-bit ELF, because the p_flags are in a different structure location for alignment reasons.


p_type  :Identifies the type of segment
p_offset:Offset of the segment in the file image.
p_vaddr	:Virtual address of the segment in memory.
p_paddr	:On systems where physical address is relevant, reserved for segment's physical address.
p_files :Size in bytes of the segment in the file image. May be 0.
p_memsz	:Size in bytes of the segment in memory. May be 0.
p_flags	:Segment-dependent flags (position for 32-bit structure).
p_align	:0 and 1 specify no alignment. Otherwise should be a positive, integral power of 2, with p_vaddr equating p_offset modulus p_align.
End of Program Header (size).



SECTION HEADER:

sh_name	     :An offset to a string in the .shstrtab section that represents the name of this section.
sh_type	     :Identifies the type of this header.
sh_flags     :Identifies the attributes of the section.
sh_addr      :Virtual address of the section in memory, for sections that are loaded.
sh_offset    :Offset of the section in the file image.
sh_size	     :Size in bytes of the section in the file image. May be 0.
sh_link	     :Contains the section index of an associated section. This field is used for several purposes, depending on the type of section.
sh_info      :Contains extra information about the section. This field is used for several purposes, depending on the type of section.
sh_addralign :Contains the required alignment of the section. This field must be a power of two.
sh_entsize   :Contains the size, in bytes, of each entry, for sections that contain fixed-size entries. Otherwise, this field contains zero.
End of Section Header (size)
