.data
	.align 16
	channels: .word 3

.text
	.global asm_fnc1
	.global asm_fnc2
	.global asm_fnc3
	.global asm_fnc4

//void asm_fnc1 (guchar * pixels, unsigned int lns, unsigned int cols);
asm_fnc1:
	push 	%rbp
	mov 	%rsp, %rbp
	
	push 	%rbx

	mov 	%rdx, %rax
	mul 	%rsi
	jo 		.L_1_end

	mov 	%rax, %rbx
	
	xor 	%rdx, %rdx
	xor 	%rcx, %rcx

	mov 	channels, %rsi
	.L_1_inner_loop:
		cmpq 	%rbx, %rcx
		jge 	.L_1_end
		movzb 	2(%rdi, %rcx), %eax
		movzb   1(%rdi, %rcx), %edx
		add 	%edx, %eax
		movzb 	0(%rdi, %rcx), %edx
		add 	%edx, %eax
		xor 	%rdx, %rdx
		div 	%si

		movb 	%al, 2(%rdi, %rcx)
		movb 	%al, 1(%rdi, %rcx)
		movb 	%al, 0(%rdi, %rcx)
		add 	$0x03, %rcx
		jmp 	.L_1_inner_loop
	
	.L_1_end:
		pop 	%rbx
		xor 	%rax, %rax
		mov 	%rbp, %rsp
		pop 	%rbp
		ret

asm_fnc2:
	push 	%rbp
	mov 	%rsp, %rbp

	.L_2_end:
		mov 	%rbp, %rsp
		pop 	%rbp
		ret

asm_fnc3:
	push 	%rbp
	mov 	%rsp, %rbp

	.L_3_end:
		mov 	%rbp, %rsp
		pop 	%rbp
		ret
		
asm_fnc4:
	push 	%rbp
	mov 	%rsp, %rbp

	.L_4_end:
		mov 	%rbp, %rsp
		pop 	%rbp
		ret

