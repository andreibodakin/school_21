global _ft_strcmp

section .text
_ft_strcmp:
            mov rax, 0
            mov r8, 0
            mov r9, 0
.while:
            cmp byte [rdi + rax], 0
            je .quit
            mov r10b, byte [rsi + rax]
            cmp byte [rdi +rax], r10b
            jne .quit
            inc rax
            jmp .while
.quit:
            mov r8b, byte [rdi + rax]
            mov r9b, byte [rsi + rax]
            sub r8, r9
            mov rax, r8
            ret