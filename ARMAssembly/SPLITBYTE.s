

/* SPLITING OF BYTE */

.global _start
_start:
	LDR R1,VALUE    /* STORING VALUE IN R1 */
	LDR R2,MASK     /* STORING MASK IN R2 */
	MOV R3,R1,LSR#0X4  /* RIGHT SHIFTING OF R1 BY 4 TIMES AND MOVING TO R3 */
	MOV R3,R3,LSL #0X8  /* LEFT SHIFTING OF R3 BY 8 TIMES AND MOVING TO R3  */
	
	AND R1,R1,R2    /* AND OPERATION OF R1 AND R2 */
	ADD R1,R1,R3    /* ADDING R1,R3 AND STORING IN R1  */
	
	STR R1,RESULT  /* STORING IN RESULT */
	
	VALUE: .WORD 0XF5
	MASK: .WORD 0X000F
	RESULT: .WORD 0X0
