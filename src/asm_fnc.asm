; -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
;
; asm_fnc.asm
; Copyright (C) 2017 Victor Flores a.k.a UserX <user_x@riseup.net>
;
; asm_fnc.asm is part of a free software: you can redistribute it and/or modify it
; under the terms of the GNU General Public License as published by the
; Free Software Foundation, either version 3 of the License, or
; (at your option) any later version.
;
; png_visualizer is distributed in the hope that it will be useful, but
; WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
; See the GNU General Public License for more details.
;
; You should have received a copy of the GNU General Public License along
; with this program.  If not, see <http://www.gnu.org/licenses/>.
;/

[bits 64]
[default rel]

%define RED 	0x00
%define GREEN 	0x01
%define BLUE 	0x02
%define ALPHA 	0x03

%define COLOR_CHANNELS 0x04

section .data
	channels dw 3

section .text
	global asm_fnc1
	global asm_fnc2
	global asm_fnc3
	global asm_fnc4
	global asm_fnc5

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
		add 	rcx, COLOR_CHANNELS
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

	mov 	rax, rdx
	mul 	rsi

	push 	rax
	sub 	rsp, rax

	xor 	rdx, rdx
	mov 	rsi, 0x04
	div 	rsi

	xor 	rdx, rdx
	mov 	rcx, rax

	mov 	rsi, rsp
	.invert:
		mov 	eax, dword [rdi + rcx * 4]
		mov 	dword [rsi + rdx * 4], eax
		inc 	rdx
		loop 	.invert

	mov 	rcx, qword [rbp-0x08]
	xor 	rdx, rdx
	xor 	rax, rax

	.cpy:
		mov 	al, byte [rsi + rdx * 1]
		mov 	byte [rdi + rdx * 1], al
		inc 	rdx
		loop 	.cpy

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

asm_fnc5:
	push 	rbp
	mov 	rbp, rsp

	.end:
		mov 	rsp, rbp
		pop 	rbp
		ret
