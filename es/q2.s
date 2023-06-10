	;program to copy a value from data memory to another location in data memory
	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0, =OP1
	LDR R3, [R0]
	LDR R1, =OP2
	STR R3, [R1]
STOP
	B STOP
	AREA MDATA,DATA,READONLY
OP1 DCD 0x1768
	AREA mydata,DATA,READWRITE
OP2 DCD 0x00
	END