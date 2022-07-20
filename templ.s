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
	.file	"ex6.18.i.c"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"input g: \000"
	.align	2
.LC1:
	.ascii	"%d\000"
	.align	2
.LC2:
	.ascii	"input h: \000"
	.align	2
.LC3:
	.ascii	"before: g = %d, h = %d\012\000"
	.align	2
.LC4:
	.ascii	"after:  g = %d, h = %d\012\000"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	stmfd	sp!, {fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	movw	r0, #:lower16:.LC0
	movt	r0, #:upper16:.LC0
	bl	printf
	sub	r3, fp, #8
	movw	r0, #:lower16:.LC1
	movt	r0, #:upper16:.LC1
	mov	r1, r3
	bl	__isoc99_scanf
	movw	r0, #:lower16:.LC2
	movt	r0, #:upper16:.LC2
	bl	printf
	sub	r3, fp, #12
	movw	r0, #:lower16:.LC1
	movt	r0, #:upper16:.LC1
	mov	r1, r3
	bl	__isoc99_scanf
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-12]
	movw	r0, #:lower16:.LC3
	movt	r0, #:upper16:.LC3
	mov	r1, r2
	mov	r2, r3
	bl	printf

	// r2 <- g, r3 <- h
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-12]

	// write here --- begin ---
    cmp r2,r3
    movle r2,#0
    movgt r3,#0
	// write here ---  end  ---

	movw	r0, #:lower16:.LC4
	movt	r0, #:upper16:.LC4
	mov	r1, r2
	mov	r2, r3
	bl	printf
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	ldmfd	sp!, {fp, pc}
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.3 20140911 (Red Hat 4.8.3-9)"
	.section	.note.GNU-stack,"",%progbits
