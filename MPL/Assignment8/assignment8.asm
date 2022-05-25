; to find the factorial of a number

%macro rwe 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro


section .data
invalid db "Invalid number of arguments"
len1 equ $-invalid
newline db 10
count db 05
count1 db 2
num db 00h
colon db ":"


section .bss
asciiarr resb 16
global _start:
section .text
_start:
         

              pop rax
              cmp rax,02h
              jz goahead
              rw 01,invalid,len1
              jmp exit


goahead:      pop rax
              pop rax
              mov al,[rax]
              mov byte[num],al
              rwe 01,num,01h
              rwe 01,newline,02h 
              sub byte[num],30h
              mov eax,dword[num]
              cmp byte[num],01h
              je factorial1
factorial:    dec byte[num]
              mul dword[num]
              cmp byte[num],01h
              je endfactorial
              jmp factorial

factorial1:   mul dword[num]    

endfactorial: call hextoascii16

exit: mov rax,60
      mov rdi,00
      syscall

hextoascii16:

             mov byte[count1],16h
             mov rsi,asciiarr
again1:      rol rax,04h
             mov rbx,rax
             cmp rbx,09h
             jbe next
             add rbx,07h
next:        add rbx,30h    
             mov [rsi],rbx
             inc rsi
             dec byte[count1]
             jnz again1

             rw 01,asciiarr,010h
             ret

hextoAscii:
	mov byte[count1], 02h
	mov rsi, asciiarr
	mov al, dl
again2:rol al, 04h
	mov bl, al
	and bl, 0Fh
	cmp bl, 09h
	jbe l2
	add bl, 07h
l2:	add bl, 30h
	
	
	mov [rsi],bl
	inc rsi
	dec byte[count1]
	jnz again2
	
	rw 01, asciiarr, 02h
	rw 1, newline, 02h
ret

         