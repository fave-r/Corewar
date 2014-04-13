.name           "Bulls on Parade"
.comment        "Come wit it now!"

	live	%1
	sti	r1,%:live,%1
	fork	%:live
	fork	%:lives
	fork	%:gg
	fork	%:check

live:	live	%1
	sti	r1,%:live,%1
	st	r15,1
	zjmp	%:live

lives:	live	%84
	sti	r1,%:live,%84
	st	r15,1
	zjmp	%:lives

gg:	ld	%4200,r10
	ld	%1,r5
	ld	%0,r11
	ld	%42,r3
	add	r2,r2,r2
	fork	%:gg
	st	r2,420
	zjmp	%:gg

check:	fork	%:lop
	live	%42
	fork	%:lope
	live	%42
	fork	%:lopet
	ld	%420,r5
	ld	%4200,r6
	ld	%42000,r7
	zjmp	%:check

lop:	ld	%420,r5
	sti	r1,%:live,%-40000000000000000000000000
	ld	%4200,r6
	ld	%0,r7
	st	r5,7
	st	r6,-1

lope:	ld	%420000,r5
	ld	%42000,r6
	ld	%0,r7
	st	r5,7
	st	r6,-1

lopet:	st	r1,r5
	ld	%84000000,r6
	ld	%0,r7
	st	r5,7
	st	r6,-1