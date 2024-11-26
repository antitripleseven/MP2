section .data
MAX_SIZE dq 1000

section .bss
x resd 1000
y resd 1000
z resd 1000

section .text
    global saxpy

saxpy:
    push rbp
    mov rbp, rsp
    push rbx

    mov r10d, ecx
    mov r12, r8
    mov r13, r9
    mov r14, rdx

    movss xmm0, xmm1

    xor rbx, rbx

.loop:
    cmp rbx, r10
    jae .end

    movss xmm1, [r12 + rbx*4]
    mulss xmm1, xmm0

    movss xmm2, [r13 + rbx*4]
    addss xmm1, xmm2

    movss [r14 + rbx*4], xmm1

    inc rbx
    jmp .loop

.end:
    pop rbx
    pop rbp
    ret