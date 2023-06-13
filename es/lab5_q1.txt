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
	MOV R0,#7
	MOV R1,#5
	MOV R2,#6
	MOV R3,#2
	MOV R4,#9
	MOV R5,#1
	MOV R6,#3
	MOV R7,#4
	MOV R8,#10
	MOV R9,#8
	MOV R10,R13		  ;storing the initial address of stack pointer in R10 before pushing
	STM R13!,{R0-R9}  ;push r0 to r9 onto stack
	ADD R8,R10,#4	  ;make r8 point to second address from the base of the stack
	MOV R11,R13		  ;r11 is pointing to available address for push
OUTERLOOP
	LDMDB R13,{R0}	  ;pop the top element of the stack onto r0, note here no write-back
	SUB R12,R13,#4    ;r12 pointing to the top where element is there
	SUB R9,R13,#4     ;r9 pointing to the top where element is there 
INNERLOOP
	LDMDB R12!,{R1}   ;pop the second element from the stack onto r1 with write-back
	CMP R1,R0         ;compare first two elements of the stack (r1 is pointing to the second element)
	MOVHI R2,R0		  ;interchange the values in the register if r1>0
	MOVHI R0,R1
	MOVHI R1,R2
	MOVHI R9,R12	  ;r9 contains the address where the largest element is there
	CMP R12,R10       ;condition for checking the termination for innerloop, r10 has base address of the stack
	BNE INNERLOOP
	LDMDB R13!,{R4}   ;put the top element of the stack onto r4 with write-back, now r13 is pointing to second top element
	STM R9,{R4}		  ;put the element into the address for smallest element
	STM R13,{R0}	  ;put the largest element (r0) onto tos
	CMP R13,R8		  ;address of stack pointer should match the address of second element from the base to exit outerloop
	BNE OUTERLOOP
	LDMDB R11!,{R0-R9} ;pop all the elements into the registers
HERE 
	B HERE
	END