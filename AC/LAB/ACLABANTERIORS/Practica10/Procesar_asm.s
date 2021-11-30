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
	movl $0, %eax			# i=0
	movl 8(%ebp), %ebx		# mata
	movl 12(%ebp), %ecx		# matb
	movl 16(%ebp), %esi		# matc
	movl 20(%ebp), %edi		# n

	imul %edi, %edi
	#addl %ebx, %edi
for:
	cmpl %eax, %edi
	jl fifor
	movb (%ebx), %dl
	subb (%eax), %dl
	movb %dl, (%esi)
if: cmpb $0, (%esi)
	jle els
	movb $255, (%esi)
	jmp fif
els:
	movb $0, (%esi)
fif:
	incl %eax
	incl %ebx
	incl %ecx
	incl %esi
	jmp for
fifor:

# El final de la rutina ya esta programado

	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
