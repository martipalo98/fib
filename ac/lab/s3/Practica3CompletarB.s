.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo

        movl $0, %ecx 				# res = 0
        movl $0, %esi 				# i = 0
        movl $0, -4(%ebp)			# res = 0
        
for1:   cmpl $3, %esi 				# i < 3
        jge fifor1
        movl $0, %edi 				# j = 0
        
for2:   cmpl $3, %edi 				# j < 3
        jge fifor2
        
        movl 8(%ebp), %ebx 			# direccion base matriz
        
		imul $16, %esi, %eax 		# 4* (3*i + i) = 4*4*i = 16*i
        movl (%ebx, %eax), %ebx 	# M[i][i]
        addl %edi, %ebx         	# base matriz + 4*(i*3 +i)+ j
        
        subl %ebx, -4(%ebp) 		# res-= Matriz[i][i] + j
		incl %edi 					# j++
		jmp for2
        
fifor2: 

		addl 12(%ebp), %esi 		# i+=salto
        jmp for1
        
fifor1:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
