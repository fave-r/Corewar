.name "Boucle Liv"
.comment "So alive"


label1:
	sti r1,%:live,%1
	and r1,%0,r1
live:
	live %1
	zjmp %:live