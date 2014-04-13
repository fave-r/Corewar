.name "Buddha Swag"
.comment "Swag dude"


label1:
	sti	r1,%1,%1
	and	r1,%0,r1
live:
	live	%20
	zjmp	%:live
