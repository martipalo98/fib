	.file	"prova.c"
	.text
	.globl	a
	.data
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
	.long	4
	.section	.rodata
.LC0:
	.string	"%i \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x78,0x6
	.cfi_escape 0x10,0x3,0x2,0x75,0x7c
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	b@GOTOFF(%eax), %ecx
	movl	a@GOTOFF(%eax), %edx
	subl	%edx, %ecx
	movl	%ecx, %edx
	movl	%edx, %ecx
	shrl	$31, %ecx
	addl	%ecx, %edx
	sarl	%edx
	movl	%edx, %ecx
	movl	b@GOTOFF(%eax), %edx
	addl	%ecx, %edx
	movl	%edx, b@GOTOFF(%eax)
	movl	b@GOTOFF(%eax), %edx
	subl	$8, %esp
	pushl	%edx
	leal	.LC0@GOTOFF(%eax), %edx
	pushl	%edx
	movl	%eax, %ebx
	call	printf@PLT
	addl	$16, %esp
	movl	$0, %eax
	leal	-8(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
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
