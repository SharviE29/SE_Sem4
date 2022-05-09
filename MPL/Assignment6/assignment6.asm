
;Write a x86/64 ALP to detect protected mode and display the values of GDTR, IDTR, ;;LDTR, TR and TR and MSW registers also identify the CPU type using CPUID instruction
;


%macro rwe 3
mov rax,%1
mov rdi,01
mov rsi,%2
mov rdx,%3
syscall
%endmacro

section .data

realmode db 10,"Real mode"
reallen: equ $-realmode

protectedmode db 10,"Protected mode"
protectedlen: equ $-protectedmode

gdtcontents db 10,"GDT contents"
gdtcontentslen: equ $-gdtcontents

ldtcontents db 10,"LDT contents"
ldtcontentslen: equ $-ldtcontents


idtcontents db 10,"IDT contents"
idtcontentslen: equ $-idtcontents

trcontents db 10,"TR contents"
trcontentslen: equ $-trcontents

mswoutput db 10,"MSW output"
mswoutputlen: equ $-mswoutput

section .bss

  gdt resd 1
      resw 1
  ldt resw 1
  idt resd 1
      resw 1
  tr resw 1 

  cr0_data resd 1 ;machine status word
  
  buffer resb 04

section .text
global _start
_start:

    smsw eax ; reading the control register 1
    mov [cr0_data],rax ; storing the control register 1 value in cr0_data
     
    bt rax,1 ; checking if the bit 1 is set
    ; if the bit 1 is set then the machine is in protected mode

    jc protected
    rwe 01,realmode,reallen
    jmp next

    protected: rwe 01,protectedmode,protectedlen

    next: sgdt [gdt] ; storing the GDT address in gdt

    sldt [ldt] ; storing the LDT address in ldt
    sidt [idt] ; storing the IDT address in idt
    str [tr] ; storing the TR address in tr
    rwe 01,gdtcontents,gdtcontentslen

    mov bx,[gdt+4]
    call display

    mov bx,[gdt +2]
    call display

    mov bx,[gdt]
    call display

    rwe 01,ldtcontents,ldtcontentslen

    mov bx,[ldt]
    call display

    rwe 01,idtcontents,idtcontentslen

    mov bx,[idt+4]
    call display

    mov bx,[idt+2]
    call display

    mov bx,[idt]
    call display

    rwe 01,trcontents,trcontentslen

    mov bx,[tr]
    call display

    rwe 01,mswoutput,mswoutputlen

    mov bx,[cr0_data+2]
    call display

    mov bx,[cr0_data]
    call display

    exit:
    mov rax,60
    mov rdi,0
    syscall


    display:
    mov rsi,buffer
    mov rcx,04

    up:
    rol bx,4
    mov dl,bl
    and al,0fh
    add al,30h
    cmp dl,39h
    jbe skip 
    add dl,07h

    skip:
    mov [rsi],dl
    inc rsi
    loop up

    rwe 01,buffer,4

    ret







