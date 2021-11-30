.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)

# Aqui has de introducir el codigo

	movl $1, %ecx
for: cmpl 12(%ebp),%ecx 
	jge fifor
	movl 8(%ebp), %edx 
	movl (%edx,%ecx,4), %edx
if: cmpl -4(%ebp), %edx
	jge fiif
	movl %edx, -4(%ebp)
fiif: incl %ecx
	jmp for
fifor:

# El final de la rutina ya esta programado

	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
