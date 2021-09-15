<h1>EXUCUTABLE AND  LINKABLE FILE(ELF)</h1>

Each ELF file is made up of one ELF header, followed by file data. The data can include:

Program header table, describing zero or more memory segments
Section header table, describing zero or more sections
Data referred to by entries in the program header table or section header table 

The segments contain information that is needed for run time execution of the file, while sections contain important data for linking and relocation. Any byte in the entire file can be owned by one section at most, and orphan bytes can occur which are unowned by any section.

00000000 7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 |.ELF............|

00000010 02 00 3e 00 01 00 00 00 c5 48 40 00 00 00 00 00 |..>......H@.....|

Example hexdump of ELF file header[4] 


<h2>ELF HEADER</h2>

The ELF header  is 32 bytes long,and identifies the fotmat of the file.It starts with a sequence of four unique bytes called magic bytes. The header also indicates whether it is an Elf file for 32 bit or 64 bit format,uses littele or big endianness,shows the ELF version etc..,
the command used to get ELF header  of an application is readelf -h prog

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/9e151ef6a6ff770156f250cd5caf5b1af194524d/figures/ELF%20Header.jpg">
</p>

<b>Class</b>

After the type declaration, there is a Class field defined. This value determines the architecture for
the file.It can be 32-bit (= 01) or 64-bit (= 02) architecture. The magic shows a 02, which is translated
by the readelf command as an ELF64 file. In other words, an ElF file using the 64-bit architecture.

<b>Data</b>

Next part is the data field. It knows two options: 01 for LSB also known as little-endian. Then there is the
value 02, for MSB known as big-endian. This particular value helps to interpet the remaining objects
correctly within the file. This is important, as different types of processors deal differently with the 
incoming instructions and data structures. In this case, LSB is used, which is common for AMD64 processors.

<b>Version</b>

Next in line is another “01” in the magic, which is the version number.
Currently, there is only 1 version type:currently, which is the value “01”.

<b>OS/ABI </b>

Each operating system has a big overlap in common functions. In addition, each of them has specific ones,
or at least minor differences between them. The definition of the right set is done with an
Application Binary Interface (ABI). This way the operating system and applications both know what to expect
and functions are correctly forwarded. These two fields describe what ABI is used and the related version.
In this case, the value is 00, which means no specific extension is used. The output shows this as System V.

<b>ABI Version </b>

ABI is short for Application Binary Interface and specifies a low-level interface between the operating
system and a piece of executable code. When needed, a version for the ABI can be specified.

<h2>PROGRAM HEADER</h2>

An executable or shared object file's program header table is an array of structures, each describing a segment or other information the system needs to prepare the program for execution. An object file segment contains one or more sections, as Segment Contents'' describes below. Program headers are meaningful only for executable and shared object files. A file specifies its own program header size with the ELF header's e_phentsize and e_phnum members. 


typedef struct {
	Elf32_Word	p_type;
	Elf32_Off	p_offset;
	Elf32_Addr	p_vaddr;
	Elf32_Addr	p_paddr;
	Elf32_Word	p_filesz;
	Elf32_Word	p_memsz;
	Elf32_Word	p_flags;
	Elf32_Word	p_align;
} Elf32_Phdr;

typedef struct {
	Elf64_Word	p_type;
	Elf64_Word	p_flags;
	Elf64_Off	p_offset;
	Elf64_Addr	p_vaddr;
	Elf64_Addr	p_paddr;
	Elf64_Xword	p_filesz;
	Elf64_Xword	p_memsz;
	Elf64_Xword	p_align;
} Elf64_Phdr;

<b>p_type</b>

This member tells what kind of segment this array element describes or how to interpret the array element's information. Type values and their meanings appear below.

<b>p_offset</b>

This member gives the offset from the beginning of the file at which the first byte of the segment resides.

<b>p_vaddr</b>

This member gives the virtual address at which the first byte of the segment resides in memory.

<b>p_paddr</b>

On systems for which physical addressing is relevant, this member is reserved for the segment's physical address. Because System V ignores physical addressing for application programs, this member has unspecified contents for executable files and shared objects.

<b>p_filesz</b>

This member gives the number of bytes in the file image of the segment; it may be zero.

<b>p_memsz</b>

This member gives the number of bytes in the memory image of the segment; it may be zero.

<b>p_flags</b>

This member gives flags relevant to the segment. Defined flag values appear below.

<b>p_align</b>

As Program Loading'' describes in this chapter of the processor supplement, loadable process segments must have congruent values for p_vaddr and p_offset, modulo the page size. This member gives the value to which the segments are aligned in memory and in the file. Values 0 and 1 mean no alignment is required. Otherwise, p_align should be a positive, integral power of 2, and p_vaddr should equal p_offset, modulo p_align
    
<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/37f3ebe0ae165d4061b3f6ed076ff58e61444f60/figures/Program%20header.png">
</p>

 Commands to see program headers:

->  dumpelf

->  elfls -S /bin/ps

->  eu-readelf -program-headers /bin/ps


<h2>SECTION HEADER</h2>

Sections can be found in an ELF binary after the GNU C compiler transformed C code into assembly, followed
by the GNU assembler, which creates objects of it.

A segment can have 0 or more sections. For executable files there are four main sections: .text, .data,
.rodata, and .bss. Each of these sections is loaded with different access rights, which can be seen with
readelf -S.


<p align="center"
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/3aaf6b14b1b4650a46f0708cada2d83a13a3e5e4/figures/section%20header.png">
</p>



<b>.text</b>

Contains executable code. It will be packed into a segment with read and execute access rights. It is only
loaded once, as the contents will not change. This can be seen with the objdump utility.


<b>.data</b>

Initialized data with read/write access rights.

<b>.rodata<b/>

Initialized data, with read access rights (only =A)

<b>.bss</b>

Uninitialized data, with read/write access rights (=WA)


<b>.comment</b>

This section holds version control information. This section is of type SHT_PROGHITS.No attribute types are used.

<b>.ctors</b>

This section holds initialized pointers to the C++ constructor functions. This section is of type SHT_PROGBITS.
The attribute types are SHF_ALLOC and SHF_WRITE.

<b>.data1</b>

This section holds initialized data that contribute to the program's memory image. This section is of type
SHT_PROGBITS. The attribute types are SHF_ALLOC and SHF_WRITE.

<b>.debug</b>

This section holds information for symbolic debugging. The contents are unspecified. This section is of type
SHT_PROGBITS.  No attribute types are used.

<b>.dtors</b>

This section holds initialized pointers to the C++ destructor functions. This section is of type SHT_PROGBITS.
The attribute types are SHF_ALLOC and SHF_WRITE.

<b>.dynamic</b>

This section holds dynamic linking information. The section's attributes will include the SHF_ALLOC bit.
Whether the SHF_WRITE bit is set is processor-specific. This section is of type SHT_DYNAMIC.

<b>.dynstr</b>

This section holds strings needed for dynamic linking, most commonly the strings that represent the names
associated with symbol table entries.  This section is of type SHT_STRTAB.  The attribute type used is
SHF_ALLOC.

<b>.gnu.version</b>

This section holds the version symbol table, an array of ElfN_Half elements. This section is of type
SHT_GNU_versym.  The attribute type used is SHF_ALLOC.

<b>.got</b>

This section holds the global offset table. This section is of type SHT_PROGBITS. The attributes are
processor-specific.

<b>.hash</b>

This section holds a symbol hash table. This section is of type SHT_HASH. The attribute used is SHF_ALLOC.

<b>.init</b>

This section holds executable instructions that contribute to the process initialization code.  When a program
starts to run the system arranges to execute the code in this section before calling the main program entry
point. This section is of type SHT_PROGBITS.  The attributes used are SHF_ALLOC and SHF_EXECINSTR.

<b>.interp</b>

This section holds the pathname of a program interpreter. If the file has a loadable segment that includes the
section, the section's attributes will include the SHF_ALLOC bit. Otherwise, that bit will be off. This
section is of type SHT_PROGBITS.

<b>.symtab</b>

This section holds a symbol table.  If the file has a loadable segment that includes the symbol table, the
section's attributes will include the SHF_ALLOC bit. Otherwise, the bit will be off. This section is of type
SHT_SYMTAB.


Commands to see section headers:

->  dumpelf

->  elfls -p /bin/ps

->  eu-readelf -section-headers /bin/ps

->  readelf -S /bin/ps

->  objdump -h /bin/ps
