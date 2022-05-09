; program to find the length of the string

%macro rwe 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro


section .data

string db "Enter the string:", 10
len1 equ $-string

string2 db "The length of the string is:",10
len2 equ $-string2

count db 20 ;the maximum length of the string


section .bss
asciiarr resb 02h
name resb 20
strlen resb 1

section .text
global _start:
_start:

	rwe 01,string,len1 ;write the string1

	rwe 00,name,20 ;read the input string

	mov rsi,name
again:	mov al,[rsi]
	cmp al,10 ;ascii code for the enter key
	jz new
	inc byte[strlen]
	inc rsi
	dec byte[count]
	jnz again
           
new:       mov rsi,asciiarr
           mov byte[count],02h
           mov al,byte[strlen]	;hex to ascii conversion logic from here
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
           
           rwe 01,string2,len2 ;print the display message
           rwe 01,asciiarr,02  ; length of the string

mov rax,60
mov rdi,00
syscall












