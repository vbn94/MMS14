	.text
	.file	"functions.c"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function main
.LCPI0_0:
	.quad	4631562373907810877     # double 45.229999999999997
.LCPI0_1:
	.quad	4626322717216342016     # double 20
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movsd	.LCPI0_0(%rip), %xmm0   # xmm0 = mem[0],zero
	movsd	.LCPI0_1(%rip), %xmm1   # xmm1 = mem[0],zero
	movl	$0, -4(%rbp)
	movsd	%xmm1, -16(%rbp)
	movsd	-16(%rbp), %xmm1        # xmm1 = mem[0],zero
	callq	max
	movsd	%xmm0, -24(%rbp)
	movsd	-24(%rbp), %xmm0        # xmm0 = mem[0],zero
	movabsq	$.L.str, %rdi
	movb	$1, %al
	callq	printf
	xorl	%ecx, %ecx
	movl	%eax, -28(%rbp)         # 4-byte Spill
	movl	%ecx, %eax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	max                     # -- Begin function max
	.p2align	4, 0x90
	.type	max,@function
max:                                    # @max
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movsd	-16(%rbp), %xmm0        # xmm0 = mem[0],zero
	ucomisd	-24(%rbp), %xmm0
	jbe	.LBB1_2
# %bb.1:
	movsd	-16(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	%xmm0, -8(%rbp)
	jmp	.LBB1_3
.LBB1_2:
	movsd	-24(%rbp), %xmm0        # xmm0 = mem[0],zero
	movsd	%xmm0, -8(%rbp)
.LBB1_3:
	movsd	-8(%rbp), %xmm0         # xmm0 = mem[0],zero
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	max, .Lfunc_end1-max
	.cfi_endproc
                                        # -- End function
	.globl	sum                     # -- Begin function sum
	.p2align	4, 0x90
	.type	sum,@function
sum:                                    # @sum
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	addl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end2:
	.size	sum, .Lfunc_end2-sum
	.cfi_endproc
                                        # -- End function
	.globl	printHello              # -- Begin function printHello
	.p2align	4, 0x90
	.type	printHello,@function
printHello:                             # @printHello
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movabsq	$.L.str.1, %rdi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.2, %rdi
	movl	%eax, -4(%rbp)          # 4-byte Spill
	movb	$0, %al
	callq	printf
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end3:
	.size	printHello, .Lfunc_end3-printHello
	.cfi_endproc
                                        # -- End function
	.globl	getNum                  # -- Begin function getNum
	.p2align	4, 0x90
	.type	getNum,@function
getNum:                                 # @getNum
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$50, %eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end4:
	.size	getNum, .Lfunc_end4-getNum
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%lf\n"
	.size	.L.str, 5

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"Hello\n"
	.size	.L.str.1, 7

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"Bye bye\n"
	.size	.L.str.2, 9

	.ident	"clang version 10.0.0-4ubuntu1 "
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym max
	.addrsig_sym printf
