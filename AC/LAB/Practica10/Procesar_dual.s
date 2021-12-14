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

  	movl %eax, %ecx
  	andl $0xF, %ecx
  	cmp $0, %ecx
  	jne unaligned

  	movl %ebx, %ecx
  	andl $0xF, %ecx
  	cmp $0, %ecx
  	jne unaligned
	  
aligned:
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

	jmp aligned

unaligned:
	cmp %eax, %edx
	jle fifor

	movdqu (%eax), %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0
	paddb %xmm0, %xmm0
	movdqu %xmm0, (%ebx)

	addl $16, %eax
	addl $16, %ebx

	jmp unaligned

fifor:


# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
