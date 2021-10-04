<h1>ARM Embedded Systems</h1>

<h2>The RISC Design Pholosophy</h2>
The ARM core uses a RISC architecture. RISC is a design philosophy aimed at delivering simple instructions that can execute in single clock cycle at high clock speed.

<h2>The RISC Philosophy is implemented with four major design rules</h2>
<h2>1. Instructions</h2>
RISC processors have a reduced number of instruction classes. These clases provide simple operations that can each execute in single cycle. The compiler or programmer synthesizes complicated operations by combining several simple instructions.Each instruction is a fixed length to allow the pipeline to fetch future instructions before decoding the current instruction.


<h2>2. Pipelines</h2>
Pipelining organizes the execution of the multiple instructions simultaneously. Pipelining improves the throughput of the system. In pipelining the instruction is divided into the subtasks. Each subtask performs the dedicated task.



<h2>3. Registers</h2>
RISC machines have a large general-purpose register set. Any register can contain either data or an address. Registers act as the fast memory store for all data processing operations.

<h2>4. Load-store Architecture</h2>
ARM uses a load-store model for memory access which means that only load/store (LDR and STR) instructions can access memory. While on x86 most instructions are allowed to directly operate on data in memory, on ARM data must be moved from memory into registers before being operated on. This means that incrementing a 32-bit value at a particular memory address on ARM would require three types of instructions (load, increment, and store) to first load the value at a particular address into a register, increment it within the register, and store it back to the memory from the register.

LDR R2, [R0] @ [R0] - origin address is the value found in R0. STR R2, [R1] @ [R1] - destination address is the value found in R1.

LDR operation: loads the value at the address found in R0 to the destination register R2.

STR operation: stores the value found in R2 to the memory address found in R1.

<h1>ARM Instruction Set For Embedded Systems</h1>
The ARM instruction set differs from the pure RISC definition in several ways that make the ARM instruction set suitable for embedded applications.
Variable cycle execution for certain instructions
Not every ARM instruction executes in a single cycle. For example, load-store-multiple instructions vary in the number of execution cycles depending upon the number of registers being transferred.

<h2>Inline barrel shifter</h2>
The ARM arithmetic logic unit has a 32-bit barrel shifter that is capable of shift and rotate operations. The second operand to many ARM and Thumb data-processing and single register data-transfer instructions can be shifted, before the data-processing or data-transfer is executed, as part of the instruction.



<h2>Thumb 16-bit instruction set</h2>
The Thumb instruction set consists of 16-bit instructions that act as a compact shorthand for a subset of the 32-bit instructions of the standard ARM. Every Thumb instruction could instead be executed via the equivalent 32-bit ARM instruction.

<h2>Conditional ececution</h2>
An instruction is only executed when a specific condition has been satisfied. This feature improves performence and code density by reducing branch instructions.

<h2>Memory</h2>
An embededde system has to have some form of memory to store and excute code. You have to compare price, performance, and power consumption when deciding upon specific memory characteristics, such as hierarchy, width, and type.

<h3>Hierarchy</h3>
All computer systems have memory arranged in some form of hierarchy.The fastest memory cache is physically located nearer the ARM processor core and the slowest secondary memory is set further away. Generally the closer memory is to the processor core, the more it costs and smaller its capacity. The cache is place between main memory and the core. It is used to speed up data transfer between the processor and main memory. A cache provides an overall increase in performence but with loss of predictble execution time. The main memory is large around 256kb to 256mb depending on the application and is generally stored in separate chips. Load and store instructions access the main memory unless the values have been stored in the cache for fast access. Secondary is the largest and slowest form of memory. Hard disk drives and CD-ROM drives are examples of secondary storage.

<h3>Width</h3>
The memory width is the number of biits the memory returns on each access. Typecally 8, 16, 32, or 64 bits. The memory width has a direct effect on the overall performence and cost ratio. If you have an unchached system using 32-bit ARM instructions and 16-bit wide memory chips, then the processor will have to meake two memory fetches per instruction. Each fetch requires two 16-bit loads. This has the effect of reducing the system performence.

<h2>cache Memory</h2>

Cache memory is a high-speed memory, which is small in size but faster than the main memory (RAM). The CPU can access it more quickly than the primary memory. So, it is used to synchronize with high-speed CPU and to improve its performance.

Cache memory can only be accessed by CPU. It can be a reserved part of the main memory or a storage device outside the CPU. It holds the data and programs which are frequently used by the CPU. So, it makes sure that the data is instantly available for CPU whenever the CPU needs this data. In other words, if the CPU finds the required data or instructions in the cache memory, it doesn't need to access the primary memory (RAM). Thus, by acting as a buffer between RAM and CPU, it speeds up the system performance.

<h3>Types of Cache Memory:</h3>

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/f0f3d51667a8982330a30b700ffd4e13dc8c03c0/figures/cache%20memory.png">
</p>


L1: It is the first level of cache memory, which is called Level 1 cache or L1 cache. In this type of cache memory, a small amount of memory is present inside the CPU itself. If a CPU has four cores (quad core cpu), then each core will have its own level 1 cache. As this memory is present in the CPU, it can work at the same speed as of the CPU. The size of this memory ranges from 2KB to 64 KB. The L1 cache further has two types of caches: Instruction cache, which stores instructions required by the CPU, and the data cache that stores the data required by the CPU.

L2: This cache is known as Level 2 cache or L2 cache. This level 2 cache may be inside the CPU or outside the CPU. All the cores of a CPU can have their own separate level 2 cache, or they can share one L2 cache among themselves. In case it is outside the CPU, it is connected with the CPU with a very high-speed bus. The memory size of this cache is in the range of 256 KB to the512 KB. In terms of speed, they are slower than the L1 cache.

L3: It is known as Level 3 cache or L3 cache. This cache is not present in all the processors; some high-end processors may have this type of cache. This cache is used to enhance the performance of Level 1 and Level 2 cache. It is located outside the CPU and is shared by all the cores of a CPU. Its memory size ranges from 1 MB to 8 MB. Although it is slower than L1 and L2 cache, it is faster than Random Access Memory (RAM).

<b>How does cache memory work with CPU?</b>
When CPU needs the data, first of all, it looks inside the L1 cache. If it does not find anything in L1, it looks inside the L2 cache. If again, it does not find the data in L2 cache, it looks into the L3 cache. If data is found in the cache memory, then it is known as a cache hit. On the contrary, if data is not found inside the cache, it is called a cache miss.

If data is not available in any of the cache memories, it looks inside the Random Access Memory (RAM). If RAM also does not have the data, then it will get that data from the Hard Disk Drive.

So, when a computer is started for the first time, or an application is opened for the first time, data is not available in cache memory or in RAM. In this case, the CPU gets the data directly from the hard disk drive. Thereafter, when you start your computer or open an application, CPU can get that data from cache memory or RAM.
<h2>Types of memory</h2>
There are different types of memory:

<h2>Read Only Memory(ROM)</h2>
ROM stands for Read Only Memory. The memory from which we can only read but cannot write on it. This type of memory is non-volatile. The information is stored permanently in such memories during manufacture. A ROM stores such instructions that are required to start a computer. This operation is referred to as bootstrap. ROM chips are not only used in the computer but also in other electronic items like washing machine and microwave oven.

<h2>Flash ROM</h2>
special type of memory that works like both RAM and ROM. You can write information to flash memory, like you can with RAM, but that information isn’t erased when the power is off, like it is with ROM. The erasing and writing of flash ROM are completely software controlled with no additional hardware circutary required, Which reduces the manufacturing costs.

<h2>DRAM</h2>
As the name DRAM, or dynamic random access memory, implies, this form of memory technology is a type of random access memory. It stores each bit of data on a small capacitor within the memory cell. The capacitor can be either charged or discharged and this provides the two states, "1" or "0" for the cell.

Since the charge within the capacitor leaks, it is necessary to refresh each memory cell periodically. This refresh requirement gives rise to the term dynamic - static memories do not have a need to be refreshed.

<h2>SRAM</h2>
Static random access memory (SRAM) is faster than the DRAM, but requires more silicon area. SRAM does not require refreshing. The access time for SRAM is shorter than the DRAM because SRAM does not require a pause between data accesses. It is mostly used as caches.

<h2>SDRAM</h2>
Synchronous dynamic random access memory (SDRAM) is dynamic random access memory (DRAM) with an interface synchronous with the system bus carrying data between the CPU and the memory controller hub. SDRAM has a rapidly responding synchronous interface, which is in sync with the system bus. SDRAM waits for the clock signal before it responds to control inputs.

<h2>Peripherals</h2>
Embedded System that interact with the outside world need some form of peripheral device. A peripheral device performs input and output functions for the chip by connecting to other devices or sensors that aree off-chip.
<h2>Interrupt controllers</h2>
When a peripheral or device requires attention, it raises an interrupt to the processor. There are two types of interrupt controllers avaiable for the ARM processor. The standard interrupt controller and the Vector interrupt controller(VIC).

The standard interrupt controller sends an interrupt signal to the processor core when an external device request servicing.

Nested vector interrupt control (NVIC) is a method of prioritizing interrupts, improving the MCU’s performance and reducing interrupt latency. NVIC also provides implementation schemes for handling interrupts that occur when other interrupts are being executed or when the CPU is in the process of restoring its previous state and resuming its suspended process.

<h1>REGISTERS</h1>

In all ARM processors, the following registers are available and accessible in any processor mode:

13 general-purpose registers R0-R12
1 Stack Pointer (SP)
1 Link Register (LR)
1 Program Counter (PC)

<h2>Stack Pointer</h2>

Register R13 is used as a pointer to the active stack.

In Thumb code, most instructions cannot access SP. The only instructions that can access SP are those designed to use SP as a stack pointer. The use of SP for any purpose other than as a stack pointer is deprecated. Note Using SP for any purpose other than as a stack pointer is likely to break the requirements of operating systems, debuggers, and other software systems, causing them to malfunction.

<h2>Link Register</h2>

Register R14 is used to store the return address from a subroutine. At other times, LR can be used for other purposes.

When a BL or BLX instruction performs a subroutine call, LR is set to the subroutine return address. To perform a subroutine return, copy LR back to the program counter. This is typically done in one of two ways, after entering the subroutine with a BL or BLX instruction:

• Return with a BX LR instruction.


<h2>Program Counter</h2>
The Program Counter (PC) is accessed as PC (or R15). It is incremented by the size of the instruction executed (which is always four bytes in ARM state). Branch instructions load the destination address into PC. You can also load the PC directly using data operation instructions. For example, to branch to the address in a general purpose register, use:


   ex:- MOV PC,R0

During execution, PC does not contain the address of the currently executing instruction. The address of the currently executing instruction is typically PC-8 for ARM, or PC-4 for Thumb.

<h1>current program status register</h1>

ARM v6/v7 maintains a status register called the CPSR (current program status register) that holds four status bits, negative (N), zero (Z), carry (C), and overflow (O). These bits can be used for conditional execution of subsequent instructions.

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/a21b03cf877406c105b5843474e7ed7046bb3fbe/figures/cpsr.png">
</p>


The bits are set according to the most recently executed ALU instruction that includes the special “s” suffix. For example, the “adds” instruction will modify the status bits but the “add” instruction will not.

Nearly all ARM instructions can include an optional condition code that determines if the instruction will be executed or skipped over. In other words, an instruction whose condition code is evaluated to false will not change the state of the processor, such as writing a result register to changing the PC.

For example, the ldreq instruction will only execute if the Z-bit in the CPSR is set, which will be the case if the most recent computational instruction resulted in a result of zero.

For example, the sequence:

 subs r2,r2,#1

 streq r3, [r0]

…will decrement register r2 and store r3 only if the new value of r2 is zero.

The compare (cmp) instruction can be used to set the status bits without any other side effect.

For example:

 cmp r2,r3

 streq r4, [r0]

…will store register r4 only if the contents of registers r2 and r3 are equal.

When combining the condition code and the “s” suffix, the condition code comes first, for example,

 addeqs r0,r0,r1


<h2>PROCESSOR MODES</h2>
The processor mode determines which registers are active and the access rights to the cpsr register itself. Each processor mode is either privileged or nonprivileged: A privileged mode allows full read-write access to the cpsr. Conversely, a nonprivileged mode only allows read access to the control field in the cpsr but still allows read-write access to the condition flags.

There are seven processor modes in total: six privileged modes (abort, fast interrupt request, interrupt request, supervisor, system, and undefined) and one nonprivileged mode (user).

<p align="center"
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/a21b03cf877406c105b5843474e7ed7046bb3fbe/figures/processor%20modes.png">
</p>

The processor enters abort mode when there is a failed attempt to access memory. Fast interrupt request and interrupt request modes correspond to the two interrupt levels available on the ARM processor. Supervisor mode is the mode that the processor is in after reset and is generally the mode that an operating system kernel operates in. System mode is a special version of user mode that allows full read-write access to the cpsr. Undefined mode is used when the processor encounters an instruction that is undefined or not supported by the implementation. User mode is used for programs and applications.

<h2>CONDITION FLAGS</h2>

Most instructions update the condition flags only if the S suffix is specified. The instructions CMP, CMN, TEQ, and TST always update the flags.
The condition flags are held in the APSR. They are set or cleared as follows:
N
Set to 1 when the result of the operation is negative, cleared to 0 otherwise.
Z
Set to 1 when the result of the operation is zero, cleared to 0 otherwise.
C
Set to 1 when the operation results in a carry, or when a subtraction results in no borrow, cleared to 0 otherwise.
V
Set to 1 when the operation causes overflow, cleared to 0 otherwise.
C is set in one of the following ways:
For an addition, including the comparison instruction CMN, C is set to 1 if the addition produced a carry (that is, an unsigned overflow), and to 0 otherwise.
For a subtraction, including the comparison instruction CMP, C is set to 0 if the subtraction produced a borrow (that is, an unsigned underflow), and to 1 otherwise.
For non-addition/subtractions that incorporate a shift operation, C is set to the last bit shifted out of the value by the shifter.
For other non-addition/subtractions, C is normally left unchanged, but see the individual instruction descriptions for any special cases.

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/a21b03cf877406c105b5843474e7ed7046bb3fbe/figures/condition%20flags.png">
<p/>

<h1>PIPELINE</h1>

A pipeline is the mechanism a RISC processor uses to execute instructions. Using a pipeline speeds up execution by fetching the next instruction while other instructions are being decoded and executed. One way to view the pipeline is to think of it as an automobile assembly line, with each stage carrying out a particular task to manufacture the vehicle.
<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/450ee38cd5dff1aa4a6323cdbfa16b000714ad12/figures/pipeline1.jpg">
</p>
Fetch loads an instruction from memory.

Decode identifies the instruction to be executed.

Execute processes the instruction and writes the result back to a register.

The pipeline using a simple example. It shows a sequence of three instructions being fetched, decoded, and executed by the processor. Each instruction takes a single cycle to complete after the pipeline is filled.

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/450ee38cd5dff1aa4a6323cdbfa16b000714ad12/figures/pipeline2.jpg">
</p>

The pipeline design for each ARM family differs. For example, The ARM9 core increases the pipeline length to five stages. The ARM9 adds a memory and writeback stage, which allows the ARM9 to process on average 1.1 Dhrystone MIPS per MHz—an increase in instruction throughput by around 13% compared with an ARM7. The maximum core frequency attainable using an ARM9 is also higher.

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/450ee38cd5dff1aa4a6323cdbfa16b000714ad12/figures/pipeline3.jpg">
</p>

The ARM10 increases the pipeline length still further by adding a sixth stage. The ARM10 can process on average 1.3 Dhrystone MIPS per MHz, about 34% more throughput than an ARM7 processor core, but again at a higher latency cost.

<p align="center">
<img src="https://github.com/vsiddeswari/ADVANCED_C/blob/450ee38cd5dff1aa4a6323cdbfa16b000714ad12/figures/pipeline4.jpg">
</p>

Even though the ARM9 and ARM10 pipelines are different, they still use the same pipeline executing characteristics as an ARM7. Code written for the ARM7 will execute on an ARM9 or ARM10.



