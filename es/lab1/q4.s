	AREA RESET,DATA,READONLY 
	EXPORT __Vectors 
__Vectors 
	DCD 0X10001000 
	DCD Reset_Handler 
	ALIGN 
	AREA MYCODE,CODE,READONLY 
	EXPORT Reset_Handler 
Reset_Handler 
	LDR R0, =SRC 
	LDR R1, =0 
	LDR R2, =36 
UP	LDR R3, [R0, R1] 
	LDR R4, [R0, R2] 
	STR R3, [R0, R2] 
	STR R4, [R0, R1] 
	SUB R2, #4 
	ADD R1, #4 
	CMP R1, R2 
	BCC UP 
STOP B STOP 
	AREA MYDATA, DATA, READWRITE 
SRC DCD 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 
	END 