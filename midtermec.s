    .globl _Z5sumSqPKyi
_Z5sumSqPKyi:
    xor %rax, %rax
loop:
    mov (%rcx), %r8
    mov %r8, %r9
    and $1, %r8
    cmp $1, %r8
    jne next
    imul %r9, %r9
    add %r9, %rax
next:
    add $8, %rcx
    sub $1, %rdx
    jnz loop
    ret
