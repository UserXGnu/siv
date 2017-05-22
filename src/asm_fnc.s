/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * asm_fnc.s
 * Copyright (C) 2017 Victor Flores a.k.a UserX <user_x@riseup.net>
 /*
 * asm_fnc.s is part of a free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * png_visualizer is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


.data
	.align 16
	channels: .word 3

.text
	.global asm_fnc1
	.global asm_fnc2
	.global asm_fnc3
	.global asm_fnc4
	.global asm_fnc5

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

asm_fnc5:
	push 	%rbp
	mov 	%rsp, %rbp

	.L_5_end:
		mov 	%rbp, %rsp
		pop 	%rbp
		ret

