	.file	"provaprevi.c"
	.text
	.globl	i
	.data
	.align 4
	.type	i, @object
	.size	i, 4
i:
	.long	100
	.globl	a
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	2
	.globl	b
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.long	50
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	jmp	.L2
.L3:
	movl	a@GOTOFF(%eax), %ecx
	movl	b@GOTOFF(%eax), %edx
	cmpl	%edx, %ecx
	je	.L2
	movl	b@GOTOFF(%eax), %ecx
	movl	a@GOTOFF(%eax), %edx
	subl	%edx, %ecx
	movl	%ecx, %edx
	addl	%edx, %edx
	addl	%ecx, %edx
	movl	%edx, b@GOTOFF(%eax)
.L2:
	movl	i@GOTOFF(%eax), %edx
	testl	%edx, %edx
	jg	.L3
	movl	$0, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB1:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE1:
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
