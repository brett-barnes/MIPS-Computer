.data


.text 

main:
    la $t0, picture
    addi $t1, $0, 0
    addi $s0, $0, 0
    addi $s1, $0, 0
    draw:
        xLoop:
            lw $t2, 0($t0)
            sw $s0, -224($0) 
            sw $s1, -220($0) 
            
            sw $t2, -216($0) 
           
            sw $0, -212($0) 

            addi $t6, $0, 255
            addi $t0, $t0, 4
            beq $s0, $t6, helper
            addi $s0, $s0, 1
            j xLoop

        helper:
            addi $s0, $0, 0
            addi $s1, $s1, 1

            addi $t4, $0, 255
            beq $s1, $t4, endDraw
            j xLoop
        
    endDraw:
        addi $t0, $0, 100