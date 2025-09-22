global _ft_strdup
extern ___error
extern _ft_strlen
extern _ft_strcpy
extern _malloc

section .text
_ft_strdup:
            mov rbx, rdi
            sub rsp, 8
            call _ft_strlen
            inc rax
            mov rdi, rax
            call _malloc
            cmp rax, 0
            je .error
            mov rdi, rax
            mov rsi, rbx
            call _ft_strcpy
            add rsp, 8
            ret
.error:
            add rsp, 8
            ret