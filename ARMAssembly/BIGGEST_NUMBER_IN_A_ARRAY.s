
/*  Biggest number in a array  */
.global _start
_start:
	
	MOV R0,#5
	ADR R1,DATA
	MOV R3,#0
	LOOP: LDR R2,[R1],#04
		  CMP R2,R3
		  BGT LOOP2
		  SUB R0,R0,#1
		  CMP R0,#0
		  BNE LOOP
		  STR R3,RESULT
		  SWI 11
	LOOP2: MOV R3,R2
			SUB R0,R0,#1
	       CMP R0,#0
		   BNE LOOP
	
DATA: .WORD 0X65,0X79,0X15,0XE3,0X72	
RESULT: .WORD 0
