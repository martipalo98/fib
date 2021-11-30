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
	movl $0, %eax
	movl 8(%ebp), %ebx
	movl 12(%ebp), %ecx
	movl 16(%ebp), %esi
	movl 20(%ebp), %edi
	imul %edi, %edi
for:
	cmpl %edi, %eax
	jge fifor
	movdqu (%ebx), %xmm0
	movdqu (%ecx), %xmm1
	psubb (%ecx), %xmm1
	movdqu %xmm0, (%esi)
	movdqu zero, %xmm2
	pcmpgtb %xmm2, %xmm0
	movdqu %xmm0, (%esi)
	addl $16, %eax
	addl $16, %edi
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
