
/*transfer of 64 bit number */

.global _start
_start:
	ADR R0,VALUE
	LDMIA R0,{R1,R2}
	MOV R3,R1
	MOV R4,R2
	SWI 11
VALUE: .WORD 0X3E2A42A1,0X214260A0
	
	
