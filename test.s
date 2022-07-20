	.file	"test.c"
	.intel_syntax noprefix
	.text
	.globl	_test
	.def	_test;	.scl	2;	.type	32;	.endef
_test:
	push	ebp
	mov	ebp, esp
	mov	eax, 7
	pop	ebp
	ret
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
