	.file	"main.c"
	.text
	.globl	_return0
	.def	_return0;	.scl	2;	.type	32;	.endef
_return0:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$0, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.globl	_return7
	.def	_return7;	.scl	2;	.type	32;	.endef
_return7:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$7, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.globl	_returnn
	.def	_returnn;	.scl	2;	.type	32;	.endef
_returnn:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "return0() = %d\12\0"
LC1:
	.ascii "return7() = %d\12\0"
LC2:
	.ascii "returnn(%d) = %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	$777, 44(%esp)
	movl	$1, 40(%esp)
	movl	$2, 36(%esp)
	movl	$3, 32(%esp)
	movl	$4, 28(%esp)
	movl	$5, 24(%esp)
	movl	$6, 20(%esp)
	movl	$7, 16(%esp)
	call	_return0
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	call	_return7
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	44(%esp), %eax
	movl	%eax, (%esp)
	call	_returnn
	movl	%eax, 8(%esp)
	movl	44(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
