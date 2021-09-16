.global _start
_start:
	MOV R0,#05
	LDR R1,=ARRAY
	MOV R2,#0
LOOP: LDR R3,[R1],#0X4
      ADD R2,R2,R3
	  SUB R0,R0,#0X1
	  CMP R0,#0X0
	  BNE LOOP
	  
ARRAY: .WORD 0X1,0X2,0X3,0X4,0X5	  