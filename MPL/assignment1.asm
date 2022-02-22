%macro rwe 3
mov rax, %1
mov rdi, 01h
mov rsi, %2
mov rdx, %3
syscall
%endmacro

section .data

m1 db "Enter the numbers:",10
len1 equ $-m1 ; are equate directives, that calculate the length automatically
m2 db "The numbers are:",10
len2 equ $-m2
count db 05h
count2 db 05h


section .bss

num resb 85 ; read a 16 bit number along with the space


global _start
section .text
_start:
       
        rwe 01, m1, len1 ;print the string m1
        mov rbx,num ;setting the pointer
again:  rwe 00, rbx, 11h
        add rbx,11h ; incrementing the pointer
        dec byte[count]
        jnz again

        rwe 01, m2, len2
        mov rbx,num
again2: rwe 01, rbx, 11h
        add rbx,17 ;
        dec byte[count2]
        jnz again2

mov rax,60
mov rdi,00
syscall