%macro rwe 3
mov rax, %1
mov rdi, 01h
mov rsi, %2
mov rdx, %3
syscall
%endmacro

section .data
asciiarr db 0,0
pcount db 0ah
ncount db 07h
count db 02h

global _start:
section .text
_start:

	mov rsi,asciiarr
	mov bl,byte[pcount]
again:	rol bl,04
	mov al,bl
	and al,0fh
	cmp al,09h
	jbe next
	add al,07h
next:      add al,30h
	mov [rsi],al
	inc rsi
	dec byte[count]
	jnz again
	rwe 01,asciiarr,02





