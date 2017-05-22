; -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
;
; asm_fncx86.asm
; Copyright (C) 2017 Victor Flores a.k.a UserX <user_x@riseup.net>
;
; asm_fncx86.asm is part of a free software: you can redistribute it and/or modify it
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
	global asm_fnc5

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
;********************************************************************

asm_fnc5:
	push 	ebp
	mov 	ebp, esp

	.end:
		mov 	esp, ebp
		pop 	ebp
		ret
