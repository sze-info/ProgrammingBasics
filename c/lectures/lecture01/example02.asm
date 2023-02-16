Pelda02	Segment		                ;Segment definition
	assume cs:Pelda02,ds:Pelda02	;cs es ds registers are set
					;to the start of the segment.
Start:	mov	ax,Pelda02		;Set ds register
	mov	ds,ax
	mov	ax,0b800h		;Loads the segment and offset addresses
	mov	es,ax			;of screen memory to the es register
	mov	di,1146			;Sets the offset address in
					;di index register
	mov	al,"A"			;Loads the ASCII code of letter "A"
					;in register al
	mov	ah,7			;The color of the character is black
					;on white background
	mov	es:[di],ax		;Writes the content
					;(letter "A" with the specified colors)
					;to the address described by es:di
	mov	ax,4c00h		;Back to DOS
	int	21h
Pelda02	Ends				;Segment end
	End	Start			;Program end
