
	.globl _Z3f1ay
_Z3f1ay:	
	# write a function that counts from 0 to n (which is in %rdi for Mac, %rcx for Windows)
	xor %rax, %rax
	loop1:
		add $1, %rax
		cmp %rax, %rcx
		jne loop1
	ret

	.globl _Z3f1by
_Z3f1by:
	# write a function that counts from n down to 1
	sub $1, %rcx
	cmp $1, %rcx
	jne _Z3f1by
	ret

	.globl _Z3f1cy
_Z3f1cy:
	# Write a function that counts from n down to 1 without using the compare (sub will do!)
	sub $1, %rcx
	jg _Z3f1by
	ret


	.globl _Z3f2ay
_Z3f2ay:
	# write a function that sums the numbers from 1 to n (which is in %rdi for Mac, %rcx for Windows)
	# answers should be returned in %rax
	xor %rax, %rax
	mov $1, %r8
	loop2:
		add %r8, %rax
		add $1, %r8
		cmp %r8, %rcx
		jne loop2
	add %r8, %rax
	ret

	.globl _Z3f2by
_Z3f2by:
	# write a function that computes n factorial (products 1 to n)
	mov $1, %rax
	mov $1, %r8
	loop3:
		add $1, %r8
		imul %r8, %rax
		cmp %r8, %rcx
		jne loop3
	ret

