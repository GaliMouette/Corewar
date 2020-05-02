	.name "Abel"
	.comment "L'amer noir."

	sti r1, %:hi, %1

hi:	live %234
	ld
	zjmp %:hi
