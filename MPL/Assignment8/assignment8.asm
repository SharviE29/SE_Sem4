; to find the factorial of a number

%macro rwe 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro


section .data

num db 00h
fact db "Enter the number to find the factorial of: "

len1 equ $-fact
resultstring db "The factorial is :"
len2 equ $-resultstring

section .bss
dispnum resb 16
result resb 4
temp resb 4

section .text
global _start
_start:

rwe 01,fact,len1
rwe 00,temp,3 ; accept the number

call convert
mov [num],dl
rwe 01,resultstring,len2
xor 





convert: ; ascii to hex
        mov rsi,temp
        mov cl,02h
        xor rax,rax
        xor rdx,rdx
first: rol dl,04h
       mov al,[rsi]
       cmp al,39h
       jbe last
       sub al,07h
last : sub al,30h
       add dl,al
       inc rsi       
       dec cl
       jnz first

ret       