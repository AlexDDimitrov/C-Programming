	.file	"minKratno.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "%d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$12, 24(%esp)
	movl	$18, 20(%esp)
	movl	$2, 28(%esp)
L4:
	movl	28(%esp), %eax
	cltd
	idivl	24(%esp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	L2
	movl	28(%esp), %eax
	cltd
	idivl	20(%esp)
	movl	%edx, %eax
	testl	%eax, %eax
	jne	L2
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	jmp	L6
L2:
	addl	$1, 28(%esp)
	jmp	L4
L6:
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
