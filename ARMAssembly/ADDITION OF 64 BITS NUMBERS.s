.global _start
_start:
	ADR R0,VALUE1
	LDMIA R0,{R1,R2}
	ADR R0,VALUE2
	LDMIA R0,{R3,R4}
	ADDS R6,R2,R4
	ADC R5,R1,R3
	ADR R0,RESULT
	STMIA R0,{R5,R6}
	
	VALUE1: .WORD 0X12A2E640,0XF2100123
	VALUE2: .WORD 0X001019BF,0X40023F51
	RESULT: .WORD 0