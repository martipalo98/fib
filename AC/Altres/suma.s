.text
	.align 4
	.globl suma
	.type suma,@function

suma:
    movl $12, %edx
    pushl %ebp
    movl %esp, %ebp
    subl 8, %esp
    pushl %ebx
    pushl %esi
    movl 8(%ebp), %eax      # b

    addl 12(%ebp), %eax         # eax: a+b
    popl %esi
    popl %ebx
    movl %ebp, %esp
    popl %ebp
    ret

