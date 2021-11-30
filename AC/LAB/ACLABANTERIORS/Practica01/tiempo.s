	.file	"tiempo.c"
	.text
	.globl	GetTime
	.type	GetTime, @function
GetTime:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$104, %esp
	subl	$8, %esp
	leal	-88(%ebp), %eax
	pushl	%eax
	pushl	$0
	call	getrusage
	addl	$16, %esp
	movl	-88(%ebp), %eax
	movl	-84(%ebp), %edx
	movl	%eax, -16(%ebp)
	movl	%edx, -12(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, -96(%ebp)
	fildl	-96(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, -96(%ebp)
	fildl	-96(%ebp)
	fldl	.LC0
	fdivrp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	.LC1
	fmulp	%st, %st(1)
	fstps	-92(%ebp)
	flds	-92(%ebp)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	GetTime, .-GetTime
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1093567616
	.align 8
.LC1:
	.long	0
	.long	1083129856
	.ident	"GCC: (SUSE Linux) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
