%macro rwe 3
mov rax, %1
mov rdi, 01h
mov rsi, %2
mov rdx, %3
syscall
%endmacro

section .data

posres db "The number of positive numbers are :"
len1 equ $-posres
negres db "The number of negative numbers are :"
len2 equ $-negres

positive db 00h
negative db 00h
array dq 1234567898473924h, 0F01276423487453h, 9453454254243556h, 0D64348236917356h
count db 04h
num db 00h


global _start
section .text
_start:

      ;mov byte[count], 04h
      mov rbx,array
abc:  mov rdx,[rbx]
      rcl rdx, 01h
      jc next
      inc byte[positive]
      jmp next1
next: inc byte[negative]
next1:add rbx,08h
      dec byte[count]
      jnz abc
      mov bl,byte[pcount] ;storing the value at bl
      mov byte[num],bl    ;storing the value in a variable num
      call hextoascii     ;calling the procedure to get the value 
      mov bl,byte[ncount] ;moving the negative count values in bl
      mov byte[num],bl    
      call hextoascii
      
      ;add byte[positive],30h
      ;add byte[negative],30h

     ;mov al,byte[positive]
     ;mov cl,byte[negative]
xa:      
      rwe 01,posres,len1
      rwe 01,positive,01h
      rwe 01,negres,len1
      rwe 01,negative,01h
      
      mov rax,60
      mov rdi,00
      syscall
      
      
hextoascii: 
;implementing a procedure
           mov bl,byte[num]
	;mov rsi,asciiarr
	mov bl,byte[positive]
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
	;rwe 01,asciiarr,02
           
      
      
      
            
      

