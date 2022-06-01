	.file	"ProgramaPractica2_Main.c"
	.text
	.globl	trad
	.data
	.align 4
	.type	trad, @object
	.size	trad, 13
trad:
	.byte	50
	.byte	51
	.byte	52
	.byte	53
	.byte	54
	.byte	55
	.byte	56
	.byte	57
	.byte	49
	.byte	74
	.byte	81
	.byte	75
	.byte	65
	.comm	baraja,416,32
	.globl	pareja
	.bss
	.align 4
	.type	pareja, @object
	.size	pareja, 4
pareja:
	.zero	4
	.globl	trio
	.align 4
	.type	trio, @object
	.size	trio, 4
trio:
	.zero	4
	.globl	poker
	.align 4
	.type	poker, @object
	.size	poker, 4
poker:
	.zero	4
	.globl	full
	.align 4
	.type	full, @object
	.size	full, 4
full:
	.zero	4
	.globl	color
	.align 4
	.type	color, @object
	.size	color, 4
color:
	.zero	4
	.globl	nada
	.align 4
	.type	nada, @object
	.size	nada, 4
nada:
	.zero	4
	.globl	doblepareja
	.align 4
	.type	doblepareja, @object
	.size	doblepareja, 4
doblepareja:
	.zero	4
	.globl	escalera
	.align 4
	.type	escalera, @object
	.size	escalera, 4
escalera:
	.zero	4
	.globl	escaleracolor
	.align 4
	.type	escaleracolor, @object
	.size	escaleracolor, 4
escaleracolor:
	.zero	4
	.globl	V
	.align 4
	.type	V, @object
	.size	V, 4
V:
	.zero	4
	.text
	.globl	Init
	.type	Init, @function
Init:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	$0, -4(%ebp)
	jmp	.L2
.L3:
	movl	-4(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	%eax, (%edx)
	movl	-4(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	$0, 4(%eax)
	movl	-4(%ebp), %eax
	addl	$13, %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	%eax, (%edx)
	movl	-4(%ebp), %eax
	addl	$13, %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	$1, 4(%eax)
	movl	-4(%ebp), %eax
	addl	$26, %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	%eax, (%edx)
	movl	-4(%ebp), %eax
	addl	$26, %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	$2, 4(%eax)
	movl	-4(%ebp), %eax
	addl	$39, %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	%eax, (%edx)
	movl	-4(%ebp), %eax
	addl	$39, %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	$3, 4(%eax)
	addl	$1, -4(%ebp)
.L2:
	cmpl	$12, -4(%ebp)
	jle	.L3
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	Init, .-Init
	.globl	Ordenar
	.type	Ordenar, @function
Ordenar:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	$0, -12(%ebp)
	jmp	.L5
.L9:
	movl	-12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -8(%ebp)
	jmp	.L6
.L8:
	movl	-12(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	leal	0(,%eax,8), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jle	.L7
	movl	-12(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	-8(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	-12(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	8(%ebp), %edx
	addl	%ecx, %edx
	movl	(%eax), %eax
	movl	%eax, (%edx)
	movl	-8(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	%eax, (%edx)
	movl	-12(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	4(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	-8(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	-12(%ebp), %edx
	leal	0(,%edx,8), %ecx
	movl	8(%ebp), %edx
	addl	%ecx, %edx
	movl	4(%eax), %eax
	movl	%eax, 4(%edx)
	movl	-8(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	movl	%eax, 4(%edx)
.L7:
	addl	$1, -8(%ebp)
.L6:
	cmpl	$4, -8(%ebp)
	jle	.L8
	addl	$1, -12(%ebp)
.L5:
	cmpl	$4, -12(%ebp)
	jle	.L9
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	Ordenar, .-Ordenar
	.section	.rodata
.LC0:
	.string	"10 - "
.LC1:
	.string	" %c - "
.LC2:
	.string	"COR"
.LC3:
	.string	"PIC"
.LC4:
	.string	"TRE"
.LC5:
	.string	"DIA"
	.text
	.globl	Mostrar
	.type	Mostrar, @function
Mostrar:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$20, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	subl	$12, %esp
	pushl	$10
	call	putchar@PLT
	addl	$16, %esp
	movl	$0, -20(%ebp)
	jmp	.L11
.L20:
	movl	-20(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -16(%ebp)
	movl	-20(%ebp), %eax
	leal	0(,%eax,8), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	4(%eax), %eax
	movl	%eax, -12(%ebp)
	leal	trad@GOTOFF(%ebx), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	cmpb	$49, %al
	jne	.L12
	subl	$12, %esp
	leal	.LC0@GOTOFF(%ebx), %eax
	pushl	%eax
	call	printf@PLT
	addl	$16, %esp
	jmp	.L13
.L12:
	leal	trad@GOTOFF(%ebx), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	movsbl	%al, %eax
	subl	$8, %esp
	pushl	%eax
	leal	.LC1@GOTOFF(%ebx), %eax
	pushl	%eax
	call	printf@PLT
	addl	$16, %esp
.L13:
	movl	-12(%ebp), %eax
	cmpl	$1, %eax
	je	.L15
	cmpl	$1, %eax
	jg	.L16
	testl	%eax, %eax
	je	.L17
	jmp	.L14
.L16:
	cmpl	$2, %eax
	je	.L18
	cmpl	$3, %eax
	je	.L19
	jmp	.L14
.L17:
	subl	$12, %esp
	leal	.LC2@GOTOFF(%ebx), %eax
	pushl	%eax
	call	puts@PLT
	addl	$16, %esp
	jmp	.L14
.L15:
	subl	$12, %esp
	leal	.LC3@GOTOFF(%ebx), %eax
	pushl	%eax
	call	puts@PLT
	addl	$16, %esp
	jmp	.L14
.L19:
	subl	$12, %esp
	leal	.LC4@GOTOFF(%ebx), %eax
	pushl	%eax
	call	puts@PLT
	addl	$16, %esp
	jmp	.L14
.L18:
	subl	$12, %esp
	leal	.LC5@GOTOFF(%ebx), %eax
	pushl	%eax
	call	puts@PLT
	addl	$16, %esp
	nop
.L14:
	addl	$1, -20(%ebp)
.L11:
	cmpl	$4, -20(%ebp)
	jle	.L20
	subl	$12, %esp
	pushl	$10
	call	putchar@PLT
	addl	$16, %esp
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	Mostrar, .-Mostrar
	.section	.rodata
.LC6:
	.string	"%s"
	.text
	.globl	verbose
	.type	verbose, @function
verbose:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	V@GOTOFF(%eax), %edx
	testl	%edx, %edx
	je	.L22
	subl	$8, %esp
	pushl	8(%ebp)
	leal	.LC6@GOTOFF(%eax), %edx
	pushl	%edx
	movl	%eax, %ebx
	call	printf@PLT
	addl	$16, %esp
.L22:
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	verbose, .-verbose
	.globl	Color
	.type	Color, @function
Color:
.LFB4:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	4(%eax), %eax
	cmpl	%eax, %edx
	jne	.L24
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	4(%eax), %eax
	cmpl	%eax, %edx
	jne	.L24
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	4(%eax), %eax
	cmpl	%eax, %edx
	jne	.L24
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	4(%eax), %eax
	cmpl	%eax, %edx
	jne	.L24
	movl	$1, %eax
	jmp	.L26
.L24:
	movl	$0, %eax
.L26:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	Color, .-Color
	.globl	Poker
	.type	Poker, @function
Poker:
.LFB5:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L28
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L28
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L28
	movl	$1, %eax
	jmp	.L29
.L28:
	movl	$0, %eax
.L29:
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L30
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L30
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L30
	movl	$1, %eax
	jmp	.L31
.L30:
	movl	$0, %eax
.L31:
	movl	%eax, -4(%ebp)
	cmpl	$0, -8(%ebp)
	jne	.L32
	cmpl	$0, -4(%ebp)
	je	.L33
.L32:
	movl	$1, %eax
	jmp	.L35
.L33:
	movl	$0, %eax
.L35:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	Poker, .-Poker
	.globl	Full
	.type	Full, @function
Full:
.LFB6:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L37
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L37
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L37
	movl	$1, %eax
	jmp	.L38
.L37:
	movl	$0, %eax
.L38:
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L39
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L39
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L39
	movl	$1, %eax
	jmp	.L40
.L39:
	movl	$0, %eax
.L40:
	movl	%eax, -4(%ebp)
	cmpl	$0, -8(%ebp)
	jne	.L41
	cmpl	$0, -4(%ebp)
	je	.L42
.L41:
	movl	$1, %eax
	jmp	.L44
.L42:
	movl	$0, %eax
.L44:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE6:
	.size	Full, .-Full
	.globl	Escalera
	.type	Escalera, @function
Escalera:
.LFB7:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	addl	$8, %edx
	movl	(%edx), %edx
	subl	$1, %edx
	cmpl	%edx, %eax
	jne	.L46
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	addl	$16, %edx
	movl	(%edx), %edx
	subl	$2, %edx
	cmpl	%edx, %eax
	jne	.L46
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	addl	$24, %edx
	movl	(%edx), %edx
	subl	$3, %edx
	cmpl	%edx, %eax
	jne	.L46
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %edx
	addl	$32, %edx
	movl	(%edx), %edx
	subl	$4, %edx
	cmpl	%edx, %eax
	jne	.L46
	movl	$1, %eax
	jmp	.L47
.L46:
	movl	$0, %eax
.L47:
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	.L48
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	cmpl	$1, %eax
	jne	.L48
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jne	.L48
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	cmpl	$3, %eax
	jne	.L48
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	cmpl	$12, %eax
	jne	.L48
	movl	$1, %eax
	jmp	.L49
.L48:
	movl	$0, %eax
.L49:
	movl	%eax, -4(%ebp)
	cmpl	$0, -8(%ebp)
	jne	.L50
	cmpl	$0, -4(%ebp)
	je	.L51
.L50:
	movl	$1, %eax
	jmp	.L53
.L51:
	movl	$0, %eax
.L53:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE7:
	.size	Escalera, .-Escalera
	.globl	Trio
	.type	Trio, @function
Trio:
.LFB8:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L55
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L55
	movl	$1, %eax
	jmp	.L56
.L55:
	movl	$0, %eax
.L56:
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L57
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L57
	movl	$1, %eax
	jmp	.L58
.L57:
	movl	$0, %eax
.L58:
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L59
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L59
	movl	$1, %eax
	jmp	.L60
.L59:
	movl	$0, %eax
.L60:
	movl	%eax, -4(%ebp)
	cmpl	$0, -12(%ebp)
	jne	.L61
	cmpl	$0, -8(%ebp)
	jne	.L61
	cmpl	$0, -4(%ebp)
	je	.L62
.L61:
	movl	$1, %eax
	jmp	.L64
.L62:
	movl	$0, %eax
.L64:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE8:
	.size	Trio, .-Trio
	.globl	Pareja
	.type	Pareja, @function
Pareja:
.LFB9:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	sete	%al
	movzbl	%al, %eax
	movl	%eax, -4(%ebp)
	cmpl	$0, -16(%ebp)
	jne	.L66
	cmpl	$0, -12(%ebp)
	jne	.L66
	cmpl	$0, -8(%ebp)
	jne	.L66
	cmpl	$0, -4(%ebp)
	je	.L67
.L66:
	movl	$1, %eax
	jmp	.L69
.L67:
	movl	$0, %eax
.L69:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE9:
	.size	Pareja, .-Pareja
	.globl	DoblePareja
	.type	DoblePareja, @function
DoblePareja:
.LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L71
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L71
	movl	$1, %eax
	jmp	.L72
.L71:
	movl	$0, %eax
.L72:
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L73
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L73
	movl	$1, %eax
	jmp	.L74
.L73:
	movl	$0, %eax
.L74:
	movl	%eax, -8(%ebp)
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$16, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L75
	movl	8(%ebp), %eax
	addl	$24, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	addl	$32, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jne	.L75
	movl	$1, %eax
	jmp	.L76
.L75:
	movl	$0, %eax
.L76:
	movl	%eax, -4(%ebp)
	cmpl	$0, -12(%ebp)
	jne	.L77
	cmpl	$0, -8(%ebp)
	jne	.L77
	cmpl	$0, -4(%ebp)
	je	.L78
.L77:
	movl	$1, %eax
	jmp	.L80
.L78:
	movl	$0, %eax
.L80:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE10:
	.size	DoblePareja, .-DoblePareja
	.section	.rodata
.LC7:
	.string	"EC "
.LC8:
	.string	"PK "
.LC9:
	.string	"FL "
.LC10:
	.string	"CL "
.LC11:
	.string	"ES "
.LC12:
	.string	"TR "
.LC13:
	.string	"PP "
.LC14:
	.string	"PR "
.LC15:
	.string	" . "
	.text
	.globl	Test
	.type	Test, @function
Test:
.LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$4, %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	pushl	8(%ebp)
	call	Color
	addl	$4, %esp
	testl	%eax, %eax
	je	.L82
	pushl	8(%ebp)
	call	Escalera
	addl	$4, %esp
	testl	%eax, %eax
	je	.L82
	movl	escaleracolor@GOTOFF(%ebx), %eax
	addl	$1, %eax
	movl	%eax, escaleracolor@GOTOFF(%ebx)
	subl	$12, %esp
	leal	.LC7@GOTOFF(%ebx), %eax
	pushl	%eax
	call	verbose
	addl	$16, %esp
	jmp	.L91
.L82:
	subl	$12, %esp
	pushl	8(%ebp)
	call	Poker
	addl	$16, %esp
	testl	%eax, %eax
	je	.L84
	movl	poker@GOTOFF(%ebx), %eax
	addl	$1, %eax
	movl	%eax, poker@GOTOFF(%ebx)
	subl	$12, %esp
	leal	.LC8@GOTOFF(%ebx), %eax
	pushl	%eax
	call	verbose
	addl	$16, %esp
	jmp	.L91
.L84:
	subl	$12, %esp
	pushl	8(%ebp)
	call	Full
	addl	$16, %esp
	testl	%eax, %eax
	je	.L85
	movl	full@GOTOFF(%ebx), %eax
	addl	$1, %eax
	movl	%eax, full@GOTOFF(%ebx)
	subl	$12, %esp
	leal	.LC9@GOTOFF(%ebx), %eax
	pushl	%eax
	call	verbose
	addl	$16, %esp
	jmp	.L91
.L85:
	subl	$12, %esp
	pushl	8(%ebp)
	call	Color
	addl	$16, %esp
	testl	%eax, %eax
	je	.L86
	movl	color@GOTOFF(%ebx), %eax
	addl	$1, %eax
	movl	%eax, color@GOTOFF(%ebx)
	subl	$12, %esp
	leal	.LC10@GOTOFF(%ebx), %eax
	pushl	%eax
	call	verbose
	addl	$16, %esp
	jmp	.L91
.L86:
	subl	$12, %esp
	pushl	8(%ebp)
	call	Escalera
	addl	$16, %esp
	testl	%eax, %eax
	je	.L87
	movl	escalera@GOTOFF(%ebx), %eax
	addl	$1, %eax
	movl	%eax, escalera@GOTOFF(%ebx)
	subl	$12, %esp
	leal	.LC11@GOTOFF(%ebx), %eax
	pushl	%eax
	call	verbose
	addl	$16, %esp
	jmp	.L91
.L87:
	subl	$12, %esp
	pushl	8(%ebp)
	call	Trio
	addl	$16, %esp
	testl	%eax, %eax
	je	.L88
	movl	trio@GOTOFF(%ebx), %eax
	addl	$1, %eax
	movl	%eax, trio@GOTOFF(%ebx)
	subl	$12, %esp
	leal	.LC12@GOTOFF(%ebx), %eax
	pushl	%eax
	call	verbose
	addl	$16, %esp
	jmp	.L91
.L88:
	subl	$12, %esp
	pushl	8(%ebp)
	call	DoblePareja
	addl	$16, %esp
	testl	%eax, %eax
	je	.L89
	movl	doblepareja@GOTOFF(%ebx), %eax
	addl	$1, %eax
	movl	%eax, doblepareja@GOTOFF(%ebx)
	subl	$12, %esp
	leal	.LC13@GOTOFF(%ebx), %eax
	pushl	%eax
	call	verbose
	addl	$16, %esp
	jmp	.L91
.L89:
	subl	$12, %esp
	pushl	8(%ebp)
	call	Pareja
	addl	$16, %esp
	testl	%eax, %eax
	je	.L90
	movl	pareja@GOTOFF(%ebx), %eax
	addl	$1, %eax
	movl	%eax, pareja@GOTOFF(%ebx)
	subl	$12, %esp
	leal	.LC14@GOTOFF(%ebx), %eax
	pushl	%eax
	call	verbose
	addl	$16, %esp
	jmp	.L91
.L90:
	movl	nada@GOTOFF(%ebx), %eax
	addl	$1, %eax
	movl	%eax, nada@GOTOFF(%ebx)
	subl	$12, %esp
	leal	.LC15@GOTOFF(%ebx), %eax
	pushl	%eax
	call	verbose
	addl	$16, %esp
.L91:
	nop
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE11:
	.size	Test, .-Test
	.globl	Repartir
	.type	Repartir, @function
Repartir:
.LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	baraja@GOT(%eax), %edx
	movl	12(%ebp), %ecx
	movl	(%edx,%ecx,8), %ecx
	movl	8(%ebp), %edx
	movl	%ecx, (%edx)
	movl	8(%ebp), %edx
	leal	8(%edx), %ebx
	movl	baraja@GOT(%eax), %edx
	movl	16(%ebp), %ecx
	movl	(%edx,%ecx,8), %edx
	movl	%edx, (%ebx)
	movl	8(%ebp), %edx
	leal	16(%edx), %ebx
	movl	baraja@GOT(%eax), %edx
	movl	20(%ebp), %ecx
	movl	(%edx,%ecx,8), %edx
	movl	%edx, (%ebx)
	movl	8(%ebp), %edx
	leal	24(%edx), %ebx
	movl	baraja@GOT(%eax), %edx
	movl	24(%ebp), %ecx
	movl	(%edx,%ecx,8), %edx
	movl	%edx, (%ebx)
	movl	8(%ebp), %edx
	leal	32(%edx), %ebx
	movl	baraja@GOT(%eax), %edx
	movl	28(%ebp), %ecx
	movl	(%edx,%ecx,8), %edx
	movl	%edx, (%ebx)
	movl	baraja@GOT(%eax), %edx
	movl	12(%ebp), %ecx
	movl	4(%edx,%ecx,8), %ecx
	movl	8(%ebp), %edx
	movl	%ecx, 4(%edx)
	movl	8(%ebp), %edx
	leal	8(%edx), %ebx
	movl	baraja@GOT(%eax), %edx
	movl	16(%ebp), %ecx
	movl	4(%edx,%ecx,8), %edx
	movl	%edx, 4(%ebx)
	movl	8(%ebp), %edx
	leal	16(%edx), %ebx
	movl	baraja@GOT(%eax), %edx
	movl	20(%ebp), %ecx
	movl	4(%edx,%ecx,8), %edx
	movl	%edx, 4(%ebx)
	movl	8(%ebp), %edx
	leal	24(%edx), %ebx
	movl	baraja@GOT(%eax), %edx
	movl	24(%ebp), %ecx
	movl	4(%edx,%ecx,8), %edx
	movl	%edx, 4(%ebx)
	movl	8(%ebp), %edx
	leal	32(%edx), %ecx
	movl	baraja@GOT(%eax), %eax
	movl	28(%ebp), %edx
	movl	4(%eax,%edx,8), %eax
	movl	%eax, 4(%ecx)
	nop
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE12:
	.size	Repartir, .-Repartir
	.comm	manita,40,32
	.comm	i,4,4
	.comm	j,4,4
	.comm	k,4,4
	.comm	m,4,4
	.comm	n,4,4
	.comm	tot,4,4
	.section	.rodata
.LC16:
	.string	"  \n"
	.align 4
.LC17:
	.string	"%7d COMBINACIONES:\n - ESCALERA COLOR (%d)\n - POKER (%d)\n - FULL (%d)\n - COLOR (%d)\n - ESCALERA (%d)\n - TRIO (%d)\n - DOBLE PAREJA (%d)\n - PAREJA (%d)\n - NADA (%d) \n"
	.align 4
.LC18:
	.string	"Pierdo algo de tiempo mientras calculo el numero: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB13:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x70,0x6
	.cfi_escape 0x10,0x7,0x2,0x75,0x7c
	.cfi_escape 0x10,0x6,0x2,0x75,0x78
	.cfi_escape 0x10,0x3,0x2,0x75,0x74
	subl	$40, %esp
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	movl	%ecx, %eax
	movl	tot@GOT(%ebx), %edx
	movl	$0, (%edx)
	cmpl	$2, (%eax)
	jne	.L94
	movl	4(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %eax
	subl	$12, %esp
	pushl	%eax
	call	atoi@PLT
	addl	$16, %esp
	movl	%eax, V@GOTOFF(%ebx)
	jmp	.L95
.L94:
	movl	$0, V@GOTOFF(%ebx)
.L95:
	subl	$12, %esp
	movl	baraja@GOT(%ebx), %eax
	pushl	%eax
	call	Init
	addl	$16, %esp
	movl	i@GOT(%ebx), %eax
	movl	$0, (%eax)
	jmp	.L96
.L106:
	movl	i@GOT(%ebx), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	j@GOT(%ebx), %eax
	movl	%edx, (%eax)
	jmp	.L97
.L105:
	movl	j@GOT(%ebx), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	k@GOT(%ebx), %eax
	movl	%edx, (%eax)
	jmp	.L98
.L104:
	movl	k@GOT(%ebx), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	m@GOT(%ebx), %eax
	movl	%edx, (%eax)
	jmp	.L99
.L103:
	movl	m@GOT(%ebx), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	n@GOT(%ebx), %eax
	movl	%edx, (%eax)
	jmp	.L100
.L102:
	movl	tot@GOT(%ebx), %eax
	movl	(%eax), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	0(,%eax,4), %edx
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	testl	%edx, %edx
	jne	.L101
	subl	$12, %esp
	leal	.LC16@GOTOFF(%ebx), %eax
	pushl	%eax
	call	verbose
	addl	$16, %esp
.L101:
	movl	n@GOT(%ebx), %eax
	movl	(%eax), %edi
	movl	m@GOT(%ebx), %eax
	movl	(%eax), %esi
	movl	k@GOT(%ebx), %eax
	movl	(%eax), %ecx
	movl	j@GOT(%ebx), %eax
	movl	(%eax), %edx
	movl	i@GOT(%ebx), %eax
	movl	(%eax), %eax
	subl	$8, %esp
	pushl	%edi
	pushl	%esi
	pushl	%ecx
	pushl	%edx
	pushl	%eax
	movl	manita@GOT(%ebx), %eax
	pushl	%eax
	call	Repartir
	addl	$32, %esp
	subl	$12, %esp
	movl	manita@GOT(%ebx), %eax
	pushl	%eax
	call	Ordenar
	addl	$16, %esp
	subl	$12, %esp
	movl	manita@GOT(%ebx), %eax
	pushl	%eax
	call	Test
	addl	$16, %esp
	movl	tot@GOT(%ebx), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	tot@GOT(%ebx), %eax
	movl	%edx, (%eax)
	movl	n@GOT(%ebx), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	n@GOT(%ebx), %eax
	movl	%edx, (%eax)
.L100:
	movl	n@GOT(%ebx), %eax
	movl	(%eax), %eax
	cmpl	$51, %eax
	jle	.L102
	movl	m@GOT(%ebx), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	m@GOT(%ebx), %eax
	movl	%edx, (%eax)
.L99:
	movl	m@GOT(%ebx), %eax
	movl	(%eax), %eax
	cmpl	$50, %eax
	jle	.L103
	movl	k@GOT(%ebx), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	k@GOT(%ebx), %eax
	movl	%edx, (%eax)
.L98:
	movl	k@GOT(%ebx), %eax
	movl	(%eax), %eax
	cmpl	$49, %eax
	jle	.L104
	movl	j@GOT(%ebx), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	j@GOT(%ebx), %eax
	movl	%edx, (%eax)
.L97:
	movl	j@GOT(%ebx), %eax
	movl	(%eax), %eax
	cmpl	$48, %eax
	jle	.L105
	movl	i@GOT(%ebx), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	i@GOT(%ebx), %eax
	movl	%edx, (%eax)
.L96:
	movl	i@GOT(%ebx), %eax
	movl	(%eax), %eax
	cmpl	$47, %eax
	jle	.L106
	subl	$12, %esp
	pushl	$10
	call	putchar@PLT
	addl	$16, %esp
	movl	nada@GOTOFF(%ebx), %edx
	movl	pareja@GOTOFF(%ebx), %esi
	movl	doblepareja@GOTOFF(%ebx), %eax
	movl	%eax, -28(%ebp)
	movl	trio@GOTOFF(%ebx), %edi
	movl	%edi, -32(%ebp)
	movl	escalera@GOTOFF(%ebx), %ecx
	movl	%ecx, -36(%ebp)
	movl	color@GOTOFF(%ebx), %eax
	movl	%eax, -40(%ebp)
	movl	full@GOTOFF(%ebx), %edi
	movl	%edi, -44(%ebp)
	movl	poker@GOTOFF(%ebx), %edi
	movl	escaleracolor@GOTOFF(%ebx), %ecx
	movl	tot@GOT(%ebx), %eax
	movl	(%eax), %eax
	subl	$4, %esp
	pushl	%edx
	pushl	%esi
	pushl	-28(%ebp)
	pushl	-32(%ebp)
	pushl	-36(%ebp)
	pushl	-40(%ebp)
	pushl	-44(%ebp)
	pushl	%edi
	pushl	%ecx
	pushl	%eax
	leal	.LC17@GOTOFF(%ebx), %eax
	pushl	%eax
	call	printf@PLT
	addl	$48, %esp
	subl	$12, %esp
	pushl	$10002
	call	PierdeTiempo@PLT
	addl	$16, %esp
	subl	$8, %esp
	pushl	%eax
	leal	.LC18@GOTOFF(%ebx), %eax
	pushl	%eax
	call	printf@PLT
	addl	$16, %esp
	movl	$0, %eax
	leal	-16(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE13:
	.size	main, .-main
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB14:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE14:
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LFB15:
	.cfi_startproc
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE15:
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
