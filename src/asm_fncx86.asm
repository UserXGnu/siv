[bits 32]

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
	push 	ebp
	mov 	ebp, esp
	
	push 	ebx

	mov 	eax, dword [ebp+0x10]
	mov 	esi, dword [ebp+0x0c]
	mul 	esi
	jo 		.end

	mov 	ebx, eax
	
	xor 	edx, edx
	xor 	ecx, ecx

	mov 	esi, [channels]
	mov 	edi, dword [ebp+0x08]
	.inner_loop:
		cmp 	ecx, ebx
		jge 	.end
		movzx 	eax, byte [edi + ecx + BLUE]
		movzx 	edx, byte [edi + ecx + GREEN]
		add 	eax, edx
		movzx 	edx, byte [edi + ecx + RED]
		add 	eax, edx
		xor 	edx, edx
		div 	si

		mov 	byte [edi + ecx + BLUE], al
		mov 	byte [edi + ecx + GREEN], al
		mov 	byte [edi + ecx + RED], al
		add 	ecx, 0x3
		jmp 	.inner_loop
	
	.end:
		pop 	ebx
		xor 	eax, eax
		mov 	esp, ebp
		pop 	ebp
		ret

;********************************************************************

asm_fnc2:
	push 	ebp
	mov 	ebp, esp

	.end:
		mov 	esp, ebp
		pop 	ebp
		ret


;********************************************************************

asm_fnc3:
	push 	ebp
	mov 	ebp, esp

	.end:
		mov 	esp, ebp
		pop 	ebp
		ret

;********************************************************************

asm_fnc4:
	push 	ebp
	mov 	ebp, esp

	.end:
		mov 	esp, ebp
		pop 	ebp
		ret
