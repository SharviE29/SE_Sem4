%macro rwe 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section .data
string db "The largest number is:", 10
len1 equ $-string

numbers db 30h,40h,02h
largest db 00
count db 03h

section .bss
asciiarr resb 02

section .text
global _start:
_start:

	mov rsi,numbers
label2:	mov al,byte[rsi]
	cmp byte[largest],al
	jns first
	mov byte[largest],al
first:	inc rsi
	dec byte[count]
	jnz label2
	
	call hextoascii 
           rwe 01,string,len1
           rwe 01,asciiarr,02h
		
mov rax,60
mov rdi,00
syscall



	hextoascii:
	mov rsi,asciiarr
           mov byte[count],02h
           mov al,byte[largest]	;hex to ascii conversion logic from here
down:      rol al,04h
	mov bl,al
	and bl,0fh
	cmp bl,09h
	jbe next
	add bl,07h
	
next:      add bl,30h
           mov [rsi],bl
           inc rsi
           dec byte[count]
           jnz down
           ret 
