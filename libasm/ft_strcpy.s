global _ft_strcpy

section .text
_ft_strcpy:
            mov rax, 0
.while:
            cmp BYTE [rsi +rax], 0
            jne .not_equal
            mov BYTE [rdi +rax], 0
            mov rax, rdi
            ret
.not_equal:
            mov r8b, byte [rsi + rax]
            mov byte [rdi + rax], r8b
            inc rax
            jmp .while