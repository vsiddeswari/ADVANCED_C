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
