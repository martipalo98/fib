.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo

	movl 16(%ebp), %edx
	imul %edx, %edx
	movl 8(%ebp), %eax
	movl 12(%ebp), %ebx
	addl %eax, %edx

for:
	cmp %eax, %edx
	jle fifor

	movdqa (%eax), %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0	
	movdqa %xmm0, (%ebx)

	addl $16, %eax
	addl $16, %ebx
	jmp for
fifor:


# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
