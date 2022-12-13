	.file	"main.c"
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "enter element: \0"
.LC1:
	.ascii "%c\0"
.LC2:
	.ascii "\12stack size is: %d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$80, %rsp
	.seh_stackalloc	80
	.seh_endprologue
	call	__main
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	initStack
	leaq	.LC0(%rip), %rcx
	call	printf
	leaq	-33(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	StackFull
	testb	%al, %al
	jne	.L2
	movzbl	-33(%rbp), %eax
	movsbl	%al, %eax
	leaq	-32(%rbp), %rdx
	movl	%eax, %ecx
	call	push
.L2:
	leaq	-32(%rbp), %rax
	leaq	Display(%rip), %rdx
	movq	%rax, %rcx
	call	DisplayStack
	leaq	-32(%rbp), %rax
	movq	%rax, %rcx
	call	StackSize
	movsbl	%al, %eax
	movl	%eax, %edx
	leaq	.LC2(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$80, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	Display
	.def	Display;	.scl	2;	.type	32;	.endef
	.seh_proc	Display
Display:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	movsbl	16(%rbp), %eax
	movl	%eax, %ecx
	call	putchar
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-W64 project) 6.2.0"
	.def	initStack;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	StackFull;	.scl	2;	.type	32;	.endef
	.def	push;	.scl	2;	.type	32;	.endef
	.def	DisplayStack;	.scl	2;	.type	32;	.endef
	.def	StackSize;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
