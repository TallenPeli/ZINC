	.file	"zinc_to.cpp"
	.text
#APP
	.globl _ZSt21ios_base_library_initv
#NO_APP
	.globl	_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB1983:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt4cout, %edi
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1983:
	.size	_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_Z5printNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.globl	_Z7printlnv
	.type	_Z7printlnv, @function
_Z7printlnv:
.LFB1985:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEPFRSoS_E
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1985:
	.size	_Z7printlnv, .-_Z7printlnv
	.globl	_Z7newlinev
	.type	_Z7newlinev, @function
_Z7newlinev:
.LFB1986:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEPFRSoS_E
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1986:
	.size	_Z7newlinev, .-_Z7newlinev
	.globl	_Z5inputNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_Z5inputNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_Z5inputNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB1987:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1987
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt4cout, %edi
.LEHB0:
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
.LEHE0:
	jmp	.L8
.L7:
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
.L8:
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1987:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1987:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1987-.LLSDACSB1987
.LLSDACSB1987:
	.uleb128 .LEHB0-.LFB1987
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L7-.LFB1987
	.uleb128 0
	.uleb128 .LEHB1-.LFB1987
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE1987:
	.text
	.size	_Z5inputNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_Z5inputNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.globl	_Z7getlineNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_Z7getlineNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_Z7getlineNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB1989:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1989
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt4cout, %edi
.LEHB2:
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$_ZSt3cin, %edi
	call	_ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
.LEHE2:
	jmp	.L13
.L12:
	movq	%rax, %rbx
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB3:
	call	_Unwind_Resume
.LEHE3:
.L13:
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1989:
	.section	.gcc_except_table
.LLSDA1989:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1989-.LLSDACSB1989
.LLSDACSB1989:
	.uleb128 .LEHB2-.LFB1989
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L12-.LFB1989
	.uleb128 0
	.uleb128 .LEHB3-.LFB1989
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE1989:
	.text
	.size	_Z7getlineNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_Z7getlineNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.section	.rodata
.LC0:
	.string	"Hello"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1990:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1990:
	.size	main, .-main
	.section	.rodata
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.ident	"GCC: (GNU) 13.2.1 20230728 (Red Hat 13.2.1-1)"
	.section	.note.GNU-stack,"",@progbits
