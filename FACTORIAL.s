.global _start
_start:
	LDR R0,=DATATABLE
	LDR R1,VALUE
	MOV R1,R1,LSL#0X2
	ADD R0,R0,R1
	LDR R2,[R0]
	ADR R3,RESULT
	STR R2,[R3]
	DATATABLE: .WORD 1,1,2,6,24,120,720,5040
	VALUE: .WORD 5
	RESULT: .WORD 0