

/*FINDING SMALLEST NUMBER IN 3 THREE NUMBERS */

.global _start
_start:
	LDR R0,VALUE1
	LDR R1,VALUE2
	LDR R2,VALUE3
	LDR R9,MASK
	AND R4,R0,R9
	AND R5,R1,R9
	AND R6,R2,R9
	CMP R4,R5
	BCS LOOP1
	CMP R4,R6
	BCS LOOP3
	MOV R8,R4
	STR R1,RESULT
	SWI 11
LOOP1: CMP R5,R6
		BCS LOOP2
		MOV R8,R5
		STR R2,RESULT
		SWI 11
LOOP2:  MOV R8,R6
		STR R3,RESULT
		SWI 11
LOOP3:  MOV R8,R6
		STR R3,RESULT
VALUE1: .WORD 0X31258465
VALUE2: .WORD 0X602C2056
VALUE3: .WORD 0X90409254
RESULT: .WORD 0X0

MASK: .WORD 0XF0000000 
