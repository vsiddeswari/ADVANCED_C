.global _start
_start:
	LDR R1,VALUE
	LDR R2,MASK
	MOV R3,R1,LSR#0X4
	MOV R3,R3,LSL #0X8
	AND R1,R1,R2
	ADD R1,R1,R3
	
	STR R1,RESULT
	
	VALUE: .WORD 0XF5
	MASK: .WORD 0X000F
	RESULT: .WORD 0X0