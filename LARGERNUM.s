.global _start
_start:
	LDR R1,VALUE1
	LDR R2,VALUE2
	CMP R1,R2
	BHI LOOP
	MOV R1,R2
	LOOP: STR R1,RESULT
	
	VALUE1: .WORD 0X567
	VALUE2: .WORD 0X456
	RESULT: .WORD 0X0