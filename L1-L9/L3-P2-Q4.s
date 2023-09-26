# Moshe Moskowitz and Erik Bobinsky
	.globl main
main:
	mov $0xDEADBEEF1234567, %rax
	mov $0xABBAF0BB0BBE98D, %rbx

	mov %rax, %rcx
	AND %rbx, %rcx

	mov %rax, %rdx
	OR %rbx, %rdx

	mov %rax, %rsi
	XOR %rbx, %rsi


	ret
