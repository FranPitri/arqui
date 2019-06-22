.text

.extern global_speed
.extern pattern_controls
.extern output
.extern delayMillis
.global newton_pattern

newton_pattern:
     PUSH {R4-R7, LR}
_newton_init:
     MOV R4, #0 // forwards counter
     MOV R5, #0 // backwards counter
_newton_move_forwards:
     BL pattern_controls
     CMP R0, #0 // if pattern_controls
     BNE _newton_out // return
     CMP R4, #3
     MOVLT R6, #0x18 // base
     MOVGE R6, #0x30 // base
     MOVLT R7, #0x80 // mark
     MOVGE R7, #0x8 // mark
     MOV R0, R4 // r0 = i
     MOV R1, #3 // % 3
     BL _modulo
     LSR R7, R7, R0 // mark >> i % 3
     ORR R0, R6, R7 // base | (mark >> i % 3)
     BL output
     LDR R0, =global_speed
     LDR R0, [R0]
     BL delayMillis
     ADD R4, R4, #1
     CMP R4, #6
     BNE _newton_move_forwards
_newton_move_backwards:
     BL pattern_controls
     CMP R0, #0 // if pattern_controls
     BNE _newton_out // return
     CMP R5, #3
     MOVLT R6, #0x30 // base
     MOVGE R6, #0x18 // base
     MOVLT R7, #0x1 // mark
     MOVGE R7, #0x20 // mark
     MOV R0, R5 // r0 = i
     MOV R1, #3 // % 3
     BL _modulo
     LSL R7, R7, R0 // mark << i % 3
     ORR R0, R6, R7 // base | (mark >> i % 3)
     BL output
     LDR R0, =global_speed
     LDR R0, [R0]
     BL delayMillis
     ADD R5, R5, #1
     CMP R5, #6
     BNE _newton_move_backwards
     B _newton_init
_newton_out:
     POP {R4-R7, PC}

_modulo:
     SUB R2, R0, R1
     CMP R2, #0
     BLT _modulo_end
     MOV R0, R2
     B _modulo
_modulo_end:
     ADD R2, R1
     MOV R0, R2
     MOV PC, LR

.data


.end
