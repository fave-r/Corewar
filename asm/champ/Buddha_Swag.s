.name "Buddha Swag"
.comment "Swag dude"


label1:
	sti	r1,%:live,%1
	and	r1,%0,r1
live:
	live	%:label1
	zjmp	%:1
