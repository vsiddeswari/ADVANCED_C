.global _start
_start:
	
	LDR R0,VALUE1
	MOV R0,R0,LSR#0X3
	
	
	VALUE1: .WORD 0X415D7834
	