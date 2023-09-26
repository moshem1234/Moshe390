	.file	"new.cc"
	.text
	.globl	_Z8functionffdd
	.def	_Z8functionffdd;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z8functionffdd
_Z8functionffdd:
.LFB2070:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movsd	%xmm2, 32(%rbp)
	movsd	%xmm3, 40(%rbp)
	movss	16(%rbp), %xmm0
	addss	24(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	addsd	32(%rbp), %xmm0
	addsd	40(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2071:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movsd	.LC0(%rip), %xmm1
	movsd	.LC1(%rip), %xmm0
	movapd	%xmm1, %xmm3
	movapd	%xmm0, %xmm2
	movss	.LC2(%rip), %xmm1
	movl	.LC3(%rip), %eax
	movd	%eax, %xmm0
	call	_Z8functionffdd
	movq	%xmm0, %rax
	movq	%rax, %xmm1
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSolsEd
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.align 8
.LC0:
	.long	0
	.long	1074921472
	.align 8
.LC1:
	.long	1717986918
	.long	1074423398
	.align 4
.LC2:
	.long	1074580685
	.align 4
.LC3:
	.long	1066192077
	.ident	"GCC: (Rev4, Built by MSYS2 project) 13.1.0"
	.def	_ZNSolsEd;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
