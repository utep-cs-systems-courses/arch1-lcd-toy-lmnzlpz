	.arch msp430g2553
	.global isHighScore
	/******************************************************************
	* detects whether the current score is higher than the highscore.*
	******************************************************************/
	
isHighScore:
	sub.w #4, r1		; taking 4 bytes from the stack pointer.
	mov.w r12, 2(r1)	; indexed mode, moving the value of r12 to address 2(r1)
	mov.w r13, @r1		; r1 is used as pointer to memory. 
	cmp.w 2(r1), @r1	; compares the value in address 2(r1) and @r1, 2(r1)-@r1
	jge tempLower		; jump if no overflow and not a negative number or vice versa.
	mov.w 2(r1), @r1
	mov.w @r1, r12
	and #0xff, r12		; makes sure we get the unsigned integer as a result.
	br #tempHigher		; jumps to tempLower, NOTE TI instructions 
tempLower:
	add.w #4, r1
	mov.w 2(r1), r12
	and #0xff, r12		; makes sure we get the unsigned integer as a result.
	ret			
tempHigher:
	add.w #4, r1
	ret			; return from interrupt.

	
