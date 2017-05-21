[bits 64]

%define RED 	0
%define GREEN 	1
%define BLUE 	2
%define ALPHA 	3

section .data
	channels dw 3

section .text
	global asm_fnc1
	global asm_fnc2
	global asm_fnc3
	global asm_fnc4

;void asm_fnc1 (guchar * pixels, unsigned int lns, unsigned int cols);
asm_fnc1:
	push 	rbp
	mov 	rbp, rsp
	
	push 	rbx

	mov 	rax, rdx
	mul 	rsi
	jo 		.end

	mov 	rbx, rax
	
	xor 	rdx, rdx
	xor 	rcx, rcx

	mov 	rsi, [channels]
	.inner_loop:
		cmp 	rcx, rbx
		jge 	.end
		movzx 	eax, byte [rdi + rcx + BLUE]
		movzx 	edx, byte [rdi + rcx + GREEN]
		add 	eax, edx
		movzx 	edx, byte [rdi + rcx + RED]
		add 	eax, edx
		xor 	rdx, rdx
		div 	si

		mov 	byte [rdi + rcx + BLUE], al
		mov 	byte [rdi + rcx + GREEN], al
		mov 	byte [rdi + rcx + RED], al
		add 	rcx, 0x3
		jmp 	.inner_loop
	
	.end:
		pop 	rbx
		xor 	rax, rax
		mov 	rsp, rbp
		pop 	rbp
		ret

asm_fnc2:
	push 	rbp
	mov 	rbp, rsp

	.end:
		mov 	rsp, rbp
		pop 	rbp
		ret

asm_fnc3:
	push 	rbp
	mov 	rbp, rsp

	.end:
		mov 	rsp, rbp
		pop 	rbp
		ret

asm_fnc4:
	push 	rbp
	mov 	rbp, rsp

	.end:
		mov 	rsp, rbp
		pop 	rbp
		ret
