.global _start
_start:
	/* 1's compliment program */
	LDR R1,VALUE1
	MVN R1,R1
	STR R1,RESULT
	
	VALUE1: .WORD 0X123
	
	RESULT: .WORD 0
