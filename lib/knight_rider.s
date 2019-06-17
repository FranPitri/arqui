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

done: NOP
     BX LR

.data
.end
