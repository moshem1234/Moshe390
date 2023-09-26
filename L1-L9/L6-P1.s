# Question 1
    .globl _Z5counti
_Z5counti:
    mov $1, %rax
    sub $3, %rcx
    countloop:
        add $3, %rax
        cmp %rcx, %rax
        jle countloop
    ret

# Question 2
    .globl _Z5sumsqPKyj
_Z5sumsqPKyj:
#    xor %r8, %r8
    xor %rax, %rax
    sumsqloop:
        mov   (%rcx), %r8
        imul %r8, %r8
        add %r8, %rax
        mov %r8, (%rcx)
        add   $8, %rcx
        sub  $1, %rdx
        jnz  sumsqloop
    ret

# Question 3
    .globl _Z4add1Pyj
_Z4add1Pyj:
#     xor %r8, %r8
    add1loop:
        mov  (%rcx), %r8
        add  $1, %r8
        mov  %r8, (%rcx)
        add  $8, %rcx
        sub  $1, %rdx
        jnz  add1loop
    ret

# Question 4
    .globl _Z11replaceZeroy
_Z11replaceZeroy:
    mov $0b111001110000, %rax
    not %rax
    and %rcx, %rax
    ret

# Question 5
    .globl _Z10replaceOney
_Z10replaceOney:
    mov $0b111001110000, %rax
    or %rcx, %rax
    ret

# Question 6
    .globl _Z7togglesy
_Z7togglesy:
    mov $0b111001110000, %rax
    xor %rcx, %rax
    ret

# Question 7
    .globl _Z8replaceDy
_Z8replaceDy:
    mov $2, %r9
    mov %rcx, %rax
StartD:
    mov $0xF, %r8
    and %rax, %r8
    cmp $0xD, %r8
    jne NextD
    sub $1, %rax
NextD:
    ror $4, %rax
    sub $1, %r9
    jnz StartD
    rol $8, %rax
    ret

# Question 8 (Extra Credit)
    .globl _Z8replaceCy
_Z8replaceCy:
    mov $16, %r9
    mov %rcx, %rax
StartC:
    mov $0xF, %r8
    and %rax, %r8
    cmp $0xD, %r8
    jne NextC
    sub $1, %rax
NextC:
    ror $4, %rax
    sub $1, %r9
    jnz StartC
    ret
