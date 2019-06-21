.text

.extern global_speed
.extern pattern_controls
.extern output
.extern delayMillis
.global snake_pattern

snake_pattern:
     PUSH {LR}
_snake_init:
     MOV R4, #0 // counter
_snake_move:
     ADD R4, R4, #1
     LDR R5, =_VALUES
     LDRB R5, [R5, R4] // get the beginning of the list's address, and offset it by R4 bytes
     BL pattern_controls
     CMP R0, #0 // if pattern_controls
     BNE _snake_out // return
     MOV R0, R5 
     BL output // output(values[r5])
     LDR R0, =global_speed
     LDR R0, [R0]
     BL delayMillis
     CMP R4, #60 // table size
     BEQ _snake_init
     B _snake_move
_snake_out:
     POP {PC}

.data

_VALUES:
.byte   -126
.byte   66
.byte   34
.byte   18
.byte   10
.byte   6
.byte   6
.byte   3
.byte   6
.byte   12
.byte   24
.byte   48
.byte   96
.byte   -64
.byte   96
.byte   48
.byte   24
.byte   12
.byte   6
.byte   3
.byte   67
.byte   70
.byte   76
.byte   88
.byte   112
.byte   112
.byte   -32
.byte   112
.byte   56
.byte   28
.byte   14
.byte   71
.byte   78
.byte   92
.byte   120
.byte   120
.byte   -16
.byte   120
.byte   60
.byte   30
.byte   -113
.byte   -98
.byte   -67
.byte   -7
.byte   -7
.byte   125
.byte   63
.byte   63
.byte   126
.byte   -4
.byte   126
.byte   -65
.byte   -2
.byte   -2
.byte   -2
.byte   -1
.byte   0
.byte   0
.byte   -1
.byte   -1

.end
