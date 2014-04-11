.name "Boucle Liv"
.comment "So alive"


label1:
	ld %:live,%:label1
	sti r1,%:live,%1
	and r1,%0,r1
live:
	live %42
	zjmp %:live
