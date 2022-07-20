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
	.file	"countbits.c"
	.section	.rodata
	.align	2
.LC0:
	.ascii	"input x: \000"
	.align	2
.LC1:
	.ascii	"%d\000"
	.align	2
.LC2:
	.ascii	"x = %#010x\012\000"
	.align	2
.LC3:
	.ascii	"cnt = %d\012\000"
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
	sub	r3, fp, #12
	movw	r0, #:lower16:.LC1
	movt	r0, #:upper16:.LC1
	mov	r1, r3
	bl	__isoc99_scanf
	ldr	r3, [fp, #-12]
	movw	r0, #:lower16:.LC2
	movt	r0, #:upper16:.LC2
	mov	r1, r3
	bl	printf

	// write here --- begin ---
	// x: r3, cnt: r2, temp:r0, r1

	// write here ---  end  ---

	movw	r0, #:lower16:.LC3
	movt	r0, #:upper16:.LC3
	mov	r1, r2
	bl	printf
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	ldmfd	sp!, {fp, pc}
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.3 20140911 (Red Hat 4.8.3-9)"
	.section	.note.GNU-stack,"",%progbits
