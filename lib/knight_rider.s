// 4 de Junio de 2019
// Arqui I UCC

.text

.global main
main:
     MOV R4, #7

      
delay:
     MOV R12, R0 
_delay:
     SUB R12, R12, #1
     BNE delay
     MOV PC, LR

done: NOP            // dummy instruction for breakpoint
     BX LR          // return from main

.data
/*
array:
     .byte 0x08
     .byte 0x10
     .byte 0xFF
*/
.end
