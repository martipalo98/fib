	.file	"Simple.c"
	.text
	.type	getticks, @function
getticks:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
#APP
# 178 "cycle.h" 1
	rdtsc
# 0 "" 2
#NO_APP
	movl	%eax, -8(%ebp)
	movl	%edx, -4(%ebp)
	movl	-8(%ebp), %eax
	movl	-4(%ebp), %edx
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	getticks, .-getticks
	.type	elapsed, @function
elapsed:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -12(%ebp)
	fildq	-8(%ebp)
	cmpl	$0, -4(%ebp)
	jns	.L4
	fldt	.LC0
	faddp	%st, %st(1)
.L4:
	fstpl	-24(%ebp)
	fldl	-24(%ebp)
	fildq	-16(%ebp)
	cmpl	$0, -12(%ebp)
	jns	.L5
	fldt	.LC0
	faddp	%st, %st(1)
.L5:
	fstpl	-24(%ebp)
	fldl	-24(%ebp)
	fsubrp	%st, %st(1)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	elapsed, .-elapsed
	.section	.rodata
.LC2:
	.string	"Resultado = %lld\n"
.LC3:
	.string	"Milisegundos = %9f\n"
.LC4:
	.string	"Ciclos = %lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$68, %esp
	movl	$0, -24(%ebp)
	movl	$0, -20(%ebp)
	call	getticks
	movl	%eax, -32(%ebp)
	movl	%edx, -28(%ebp)
	call	GetTime
	movl	%eax, -60(%ebp)
	fildl	-60(%ebp)
	fstps	-36(%ebp)
	movl	$0, -16(%ebp)
	movl	$0, -12(%ebp)
	jmp	.L8
.L9:
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	addl	%eax, -24(%ebp)
	adcl	%edx, -20(%ebp)
	addl	$1, -16(%ebp)
	adcl	$0, -12(%ebp)
.L8:
	cmpl	$0, -12(%ebp)
	js	.L9
	cmpl	$0, -12(%ebp)
	jg	.L12
	cmpl	$2999999, -16(%ebp)
	jbe	.L9
.L12:
	subl	$4, %esp
	pushl	-20(%ebp)
	pushl	-24(%ebp)
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	call	GetTime
	movl	%eax, -60(%ebp)
	fildl	-60(%ebp)
	fstps	-40(%ebp)
	flds	-40(%ebp)
	fsubs	-36(%ebp)
	subl	$4, %esp
	leal	-8(%esp), %esp
	fstpl	(%esp)
	pushl	$.LC3
	call	printf
	addl	$16, %esp
	call	getticks
	movl	%eax, -48(%ebp)
	movl	%edx, -44(%ebp)
	pushl	-28(%ebp)
	pushl	-32(%ebp)
	pushl	-44(%ebp)
	pushl	-48(%ebp)
	call	elapsed
	addl	$16, %esp
	subl	$4, %esp
	leal	-8(%esp), %esp
	fstpl	(%esp)
	pushl	$.LC4
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 16
.LC0:
	.long	0
	.long	2147483648
	.long	16447
	.ident	"GCC: (SUSE Linux) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
