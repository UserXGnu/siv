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
	pushd 	%ebp
	mov 	%esp, %ebp
	
	pushd 	%ebx

	mov 	0x10(%ebp), %eax
	mov 	0x0c(%ebp), %esi
	mul 	%esi
	jo 		.L_1_end

	mov 	%eax, %ebx
	
	xor 	%edx, %edx
	xor 	%ecx, %ecx

	mov 	channels, %esi
	mov 	0x08(%ebp), %edi
	.L_1_inner_loop:
		cmp 	%ebx, %ecx
		jge 	.L_1_end
		movzb 	2(%edi, %ecx), %eax
		movzb   1(%edi, %ecx), %edx
		add 	%edx, %eax
		movzb 	0(%edi, %ecx), %edx
		add 	%edx, %eax
		xor 	%edx, %edx
		div 	%si

		movb 	%al, 2(%edi, %ecx)
		movb 	%al, 1(%edi, %ecx)
		movb 	%al, 0(%edi, %ecx)
		add 	$0x03, %ecx
		jmp 	.L_1_inner_loop
	
	.L_1_end:
		pop 	%ebx
		xor 	%eax, %eax
		mov 	%ebp, %esp
		pop 	%ebp
		ret

asm_fnc2:
	push 	%ebp
	mov 	%esp, %ebp

	.L_2_end:
		mov 	%ebp, %esp
		pop 	%ebp
		ret

asm_fnc3:
	push 	%ebp
	mov 	%esp, %ebp

	.L_3_end:
		mov 	%ebp, %esp
		pop 	%ebp
		ret
		
asm_fnc4:
	push 	%ebp
	mov 	%esp, %ebp

	.L_4_end:
		mov 	%ebp, %esp
		pop 	%ebp
		ret

