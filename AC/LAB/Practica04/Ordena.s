.text
	.align 4
	.globl Ordenar
	.type Ordenar,@function
Ordenar:
        push %ebp
        movl %esp, %ebp

        subl $8, %esp                                   # reservem espai a la pila

        pushl %ebx                                      # salvem registres
        pushl %esi

        movl 8(%ebp), %ebx                              # ebx: @v
        movl $0, %esi                                   # esi = i = 0

fori:   imull $12, %esi, %eax                           # eax: i*12
        cmpl $0x80000000, 4(%ebx, %eax)                
        je endfori                                      # salta si v[i] != 0x80000000
        movl $1, %ecx
        addl %esi, %ecx                                 # i++

forj:   imull $12, %ecx, %edx                           # edx: j*12
        cmpl $0x80000000, 4(%ebx, %edx)                 
        je endforj                                      # salta si v[j] != 0x80000000
        
        movl 4(%ebx, %edx), %edx                        
        cmpl 4(%ebx, %eax), %edx
        jge endif

        pushl %ecx                                      # salvem la j
        
        pushl %ecx                                      # passem els parametres
        pushl %esi
        pushl %ebx
        call Intercambiar                               # cridem intercambiar
        addl $12, %esp 
        popl %ecx

endif:  incl %ecx
        jmp forj

endforj: incl %esi
        jmp fori

endfori: movl %esi, %eax                                # eax: resultat Ordena (i)


        popl %esi                                       # recuperem la pila
        popl %ebx
        movl %ebp,%esp
        popl %ebp
        ret

