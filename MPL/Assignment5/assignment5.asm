%macro rwe 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section .data
n1 db 05h
n2 db 03h
choice db 00h
menu db "Menu 1.Add 2.Subtract 3.Multiply 4.Divide 5.Exit ,Enter your choice : ", 10
len1 equ $-menu
count db 00h

section .bss
sum resb 1
diff resb 1
prod resb 1
quot resb 1
result resb 1
asciiarr resb 02


section .text
global _start:
_start:

label1:	rwe 01,menu,len1
	rwe 00,choice,02     ;31h,32h,33h,34h,35h
	sub byte[choice],30h ;01h,02h,03h,04h,05h
	cmp byte[choice],01h
	jz addnum
	cmp byte[choice],02h
	jz subnum
	cmp byte[choice],03h
	jz mulnum
	cmp byte[choice],04h
	jz divnum
	cmp byte[choice],05h
	jz exit

	addnum:call addnumproc
	jmp label1
	subnum:call subnumproc
	jmp label1
	mulnum:call mulnumproc
	jmp label1
	divnum:call divnumproc
	jmp label1

exit:	mov rax,60
	mov rdi,00
	syscall
	
addnumproc:
mov al,byte[n1]
add al,byte[n2]
mov byte[result],al
call hextoascii
ret 
 
subnumproc:
mov al,byte[n1]
sub al,byte[n2]
mov byte[result],al
call hextoascii
ret 
 
mulnumproc:
mov al,byte[n1]
mul byte[n2]
mov byte[result],al
call hextoascii
ret 
 
divnumproc:
mov al,byte[n1]
div byte[n2]
mov byte[result],al
call hextoascii
ret 
  
hextoascii:
           mov rsi,asciiarr
           mov byte[count],02h
           mov al,byte[result]	;hex to ascii conversion logic from here
 down:    rol al,04h
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
           rwe 01,asciiarr,02h
           ret   

