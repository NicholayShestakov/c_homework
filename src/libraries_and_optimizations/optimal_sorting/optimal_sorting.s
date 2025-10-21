	.file	"optimal_sorting.c"
	.text
	.p2align 4
	.globl	merge
	.type	merge, @function
merge:
.LFB11:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	movl	%esi, %r9d
	movl	%ecx, %r10d
	xorl	%eax, %eax
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdx, %rbx
	xorl	%edx, %edx
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	testl	%esi, %esi
	jle	.L2
	testl	%ecx, %ecx
	jg	.L5
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L49:
	movl	%r11d, %esi
	addl	$1, %edx
	movl	%esi, (%rcx)
	cmpl	%eax, %r10d
	jle	.L2
.L50:
	cmpl	%edx, %r9d
	jle	.L22
.L5:
	movslq	%edx, %rsi
	movslq	%eax, %rcx
	movl	(%rdi,%rsi,4), %r11d
	movl	(%rbx,%rcx,4), %esi
	leal	(%rax,%rdx), %ecx
	movslq	%ecx, %rcx
	leaq	(%r8,%rcx,4), %rcx
	cmpl	%r11d, %esi
	jg	.L49
	addl	$1, %eax
	movl	%esi, (%rcx)
	cmpl	%eax, %r10d
	jg	.L50
.L2:
	cmpl	%edx, %r9d
	jle	.L22
	movl	%r9d, %r11d
	movslq	%edx, %rsi
	subl	%edx, %r11d
	leal	-1(%r11), %ecx
	cmpl	$2, %ecx
	movslq	%eax, %rcx
	jbe	.L8
	leaq	(%rcx,%rsi), %rbp
	leaq	4(%rdi,%rsi,4), %r13
	leaq	(%r8,%rbp,4), %r12
	movq	%r12, %rbp
	subq	%r13, %rbp
	cmpq	$8, %rbp
	jbe	.L8
	leaq	(%rdi,%rsi,4), %rbp
	movl	%r11d, %esi
	xorl	%ecx, %ecx
	shrl	$2, %esi
	salq	$4, %rsi
	.p2align 5
	.p2align 4
	.p2align 3
.L9:
	movdqu	0(%rbp,%rcx), %xmm0
	movups	%xmm0, (%r12,%rcx)
	addq	$16, %rcx
	cmpq	%rsi, %rcx
	jne	.L9
	testb	$3, %r11b
	je	.L7
	andl	$-4, %r11d
	addl	%edx, %r11d
	movslq	%r11d, %rdx
	movl	(%rdi,%rdx,4), %ecx
	leal	(%rax,%r11), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%r8,%rdx,4)
	leal	1(%r11), %edx
	cmpl	%edx, %r9d
	jle	.L7
	movslq	%edx, %rcx
	addl	%eax, %edx
	addl	$2, %r11d
	movl	(%rdi,%rcx,4), %esi
	movslq	%edx, %rdx
	movl	%esi, (%r8,%rdx,4)
	cmpl	%r11d, %r9d
	jle	.L7
	movl	4(%rdi,%rcx,4), %edx
	addl	%eax, %r11d
	movslq	%r11d, %r11
	movl	%edx, (%r8,%r11,4)
.L7:
	cmpl	%eax, %r10d
	jle	.L17
	movl	%r10d, %r11d
	movslq	%eax, %rcx
	subl	%eax, %r11d
	leal	-1(%r11), %edx
	cmpl	$2, %edx
	movslq	%r9d, %rdx
	jbe	.L14
	leaq	(%rdx,%rcx), %rsi
	leaq	4(%rbx,%rcx,4), %r12
	leaq	(%r8,%rsi,4), %rbp
	movq	%rbp, %rsi
	subq	%r12, %rsi
	cmpq	$8, %rsi
	jbe	.L14
	leaq	(%rbx,%rcx,4), %rsi
	movl	%r11d, %ecx
	xorl	%edx, %edx
	shrl	$2, %ecx
	salq	$4, %rcx
	.p2align 5
	.p2align 4
	.p2align 3
.L15:
	movdqu	(%rsi,%rdx), %xmm0
	movups	%xmm0, 0(%rbp,%rdx)
	addq	$16, %rdx
	cmpq	%rcx, %rdx
	jne	.L15
	testb	$3, %r11b
	je	.L17
	movl	%r11d, %edx
	andl	$-4, %edx
	addl	%edx, %eax
	movslq	%eax, %rdx
	movl	(%rbx,%rdx,4), %ecx
	leal	(%r9,%rax), %edx
	movslq	%edx, %rdx
	movl	%ecx, (%r8,%rdx,4)
	leal	1(%rax), %edx
	cmpl	%edx, %r10d
	jle	.L17
	movslq	%edx, %rcx
	addl	%r9d, %edx
	addl	$2, %eax
	movl	(%rbx,%rcx,4), %esi
	movslq	%edx, %rdx
	movl	%esi, (%r8,%rdx,4)
	cmpl	%eax, %r10d
	jle	.L17
	movl	4(%rbx,%rcx,4), %edx
	addl	%eax, %r9d
	movslq	%r9d, %r9
	movl	%edx, (%r8,%r9,4)
.L17:
	call	free@PLT
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movq	%rbx, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	jmp	free@PLT
	.p2align 4,,10
	.p2align 3
.L14:
	.cfi_restore_state
	leaq	(%r8,%rdx,4), %rdx
	.p2align 4
	.p2align 4
	.p2align 3
.L19:
	movl	(%rbx,%rcx,4), %eax
	movl	%eax, (%rdx,%rcx,4)
	addq	$1, %rcx
	cmpl	%ecx, %r10d
	jg	.L19
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L8:
	leaq	(%r8,%rcx,4), %rcx
	.p2align 4
	.p2align 4
	.p2align 3
.L11:
	movl	(%rdi,%rsi,4), %edx
	movl	%edx, (%rcx,%rsi,4)
	addq	$1, %rsi
	cmpl	%esi, %r9d
	jg	.L11
	jmp	.L7
	.p2align 4,,10
	.p2align 3
.L22:
	movl	%edx, %r9d
	jmp	.L7
	.cfi_endproc
.LFE11:
	.size	merge, .-merge
	.p2align 4
	.globl	mergeSort
	.type	mergeSort, @function
mergeSort:
.LFB12:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	movq	%rdi, %r13
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	cmpl	$1, %esi
	jle	.L59
	movl	%esi, %ebp
	movl	%esi, %ebx
	movl	$4, %esi
	sarl	%ebp
	movl	%ebx, %r12d
	movslq	%ebp, %r14
	subl	%ebp, %r12d
	movq	%r14, %rdi
	call	calloc@PLT
	movslq	%r12d, %rdi
	movl	$4, %esi
	movq	%rax, %r15
	call	calloc@PLT
	movl	%ebp, %edx
	movq	%r13, %rsi
	movq	%r15, %rdi
	salq	$2, %rdx
	movq	%rax, 8(%rsp)
	call	memcpy@PLT
	testl	%r12d, %r12d
	je	.L54
	movl	%r12d, %edx
	movq	8(%rsp), %rdi
	leaq	0(%r13,%r14,4), %rsi
	salq	$2, %rdx
	call	memcpy@PLT
.L54:
	movl	%ebp, %esi
	movq	%r15, %rdi
	call	mergeSort
	movq	8(%rsp), %rdi
	movl	%r12d, %esi
	movq	%rax, %r13
	call	mergeSort
	movslq	%ebx, %rdi
	movl	$4, %esi
	movq	%rax, %r14
	call	calloc@PLT
	movl	%r12d, %ecx
	movq	%r14, %rdx
	movl	%ebp, %esi
	movq	%rax, %r8
	movq	%r13, %rdi
	movq	%rax, %rbx
	call	merge
.L51:
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%rbx, %rax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L59:
	.cfi_restore_state
	movl	$4, %esi
	movl	$1, %edi
	call	calloc@PLT
	movq	%rax, %rbx
	movl	0(%r13), %eax
	movl	%eax, (%rbx)
	jmp	.L51
	.cfi_endproc
.LFE12:
	.size	mergeSort, .-mergeSort
	.ident	"GCC: (GNU) 15.2.1 20250813"
	.section	.note.GNU-stack,"",@progbits
