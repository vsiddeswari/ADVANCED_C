
/*  LEFT SHIFT BY COUNT  TIMES  */

.global _start
_start:
	
	LDR R1,VALUE
	LDR R2,COUNT
	MOV R1,R1,LSL R2
VALUE: .WORD 0X0000182B
COUNT: .WORD 20
