.name "Buddha Swag"
.comment "Swag dude"


label1:
	sti r1,%:live,%1
	and r1,%0,r1
	fork %42
live:
	live %1
	zjmp %:live
