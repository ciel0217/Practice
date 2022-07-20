	.arch armv7-a
	.eabi_attribute 27, 3
	.eabi_attribute 28, 1
	.fpu vfpv3-d16
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"ex_sub.s"
	.text

	.align	2
	.global	return0
	.type	return0, %function
return0:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	@ --- begin --- 
	mov	r0, #0
	@ ---  end  ---
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	return0, .-return0

	.align	2
	.global	return7
	.type	return7, %function
return7:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	@ --- begin --- 
	mov	r0, #7
	@ ---  end  ---
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	return7, .-return7

	.align	2
	.global	returnn
	.type	returnn, %function
returnn:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	@ --- begin --- 
	@ nothing to do
	@ ---  end  ---
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	returnn, .-returnn

	.align	2
	.global	add2
	.type	add2, %function
add2:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	@ --- begin --- 
	add	r0, r0, r1	@r0 <- a1+a2
	@ ---  end  ---
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	add2, .-add2

	.align	2
	.global	add3
	.type	add3, %function
add3:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	@ --- begin --- 
	push	{lr}
	bl	add2
	add	r0, r0, r2	@r0 <- a1+a2+a3
	pop	{lr}
	@ ---  end  ---
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	add3, .-add3

	.align	2
	.global	add4
	.type	add4, %function
add4:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	@ --- begin --- 
	push	{lr}
	bl	add3
	add	r0, r0, r3
	pop	{lr}
	@ ---  end  ---
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	add4, .-add4

	.align	2
	.global	add5
	.type	add5, %function
add5:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	@ --- begin --- 
	push	{lr}
	bl	add4
	ldr	r1, [fp, #4]	@r1 <- a5
	add	r0, r0, r1
	pop	{lr}
	@ ---  end  ---
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	add5, .-add5

	.align	2
	.global	add6
	.type	add6, %function
add6:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	@ --- begin --- 
	push	{r4, lr}
	sub	sp, sp, #4
	ldr	r4, [fp, #4]	@r4 <- a5
	str	r4, [sp]
	bl	add5
	add	sp, sp, #4
	ldr	r1, [fp, #8]	@r1 <- a6
	add	r0, r0, r1
	pop	{r4, lr}
	@ ---  end  ---
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	add6, .-add6

	.align	2
	.global	add7
	.type	add7, %function
add7:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	@ --- begin --- 
	push	{r4, r5, lr}
	sub	sp, sp, #8
	ldr	r4, [fp, #4]	@r4 <- a5
	ldr	r5, [fp, #8]	@r5 <- a6
	str	r4, [sp]
	str	r5, [sp, #4]
	bl	add6
	add	sp, sp, #8
	ldr	r1, [fp, #12]	@r1 <- a7
	add	r0, r0, r1
	pop	{r4, r5, lr}
	@ ---  end  ---
	sub	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	@ fp = sp
	@ fp = *sp
	bx	lr
	.size	add7, .-add7

	.ident	"GCC: (GNU) 4.8.3 20140911 (Red Hat 4.8.3-9)"
	.section	.note.GNU-stack,"",%progbits