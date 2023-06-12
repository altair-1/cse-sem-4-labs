	AREA RESET,CODE,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY 
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,=DST
	MOV R1,#0x12
	MOV R2,#0
up  CMP R1,#0xA
	BCC sto 
	SUB R1,#0xA
	ADD R2,#1
	B up
sto ADD R1,#0x30
	STRB R1,[R0],#1
	MOV R1,R2
	MOV R2,#0
	CMP R1,#0xA
	BCS up
	ADD R1,#0x30
	STRB R1,[R0]
STOP 
	B STOP
	AREA mydata,DATA,READWRITE
DST DCD 0
	END