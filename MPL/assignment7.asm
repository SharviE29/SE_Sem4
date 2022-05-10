; non-overlapped block transfer of 64 bit word

%macro rwe 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section .data

sourceadd db "Source address: ",10
destadd db "Destination address: ",10
srcarr db abcd, efgh, jkli, pqrst, uvwx

section .bss
asciiarr resb 16 ;for the procedure
vp resq 01
dstarr resq 4

section .text
global _start:
_start:

;to implement block transfer

	rsi, srcarr ;pointer to the source array
	rdi, dstarr ;pointer to the destination array
	cl,04h      ;repeat prefix decrements from the cl register only so we cant explicitly declare it in a variable in the data section
	cld 
	rep movs ;repeat prefix

;to print the source array indexes and values

	mov rsi,srcarr
	mov qword[vp],rsi ;to take the address of the variable and print it via htoa procedure
	push rsi
	call htoa
	pop rsi
	mov rax,[rsi] ; to take the contents of the pointer and print it via htoa procedure
	mov qword[vp],rax
	push rsi
	call htoa
	pop rsi
	

;to print the destination array indexes and values

	mov rsi,dstarr
	mov qword[vp],rsi ;to take the address of the variable and print it via htoa procedure
	push rsi
	call htoa
	pop rsi
	mov rax,[rsi] ; to take the contents of the pointer and print it via htoa procedure
	mov qword[vp],rax
	push rsi
	call htoa
	pop rsi	
	
	mov rax,60
	mov rdi,00
	syscall
	
htoa:
         mov rax,qword[vp]
         mov rsi,asciiarr
         mov byte[count],16
         mov al,byte[result]	;hex to ascii conversion logic from here
 down:   rol rax,04h
         mov bl,al
         and bl,0fh
         cmp bl,09h
         jbe next
         add bl,07h
	
next:    add bl,30h
         mov [rsi],bl
         inc rsi
         dec byte[count]
         jnz down
         rwe 01,asciiarr,16
         ret   	
	
	
	
	
	
	
	
	
	
	
	









