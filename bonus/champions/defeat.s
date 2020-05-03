.name "defeat"
.comment "or victory"

                st r1, 9
                fork %:conqueror
                live %42
                fork %:live
                fork %:wall

beginning:      fork %:attack
                fork %:live_one
                fork %:wall_one
                zjmp %:beginning

attack:         fork %:first_attack
                fork %:second_attack
                fork %:live_one
                zjmp %:attack

live:           st r1, 6

live_one:       live %42
                fork %:live_two
                st r1, 24
                st r1, 18
                st r1, 12
                st r1, 6
                live %42
                live %42
                live %42
                live %42
                zjmp %-20

live_two:       fork %:live_three
                st r1, 24
                st r1, 18
                st r1, 12
                st r1, 6
                live %42
                live %42
                live %42
                live %42
                zjmp %-20

live_three:     fork %:live_four
                st r1, 24
                st r1, 18
                st r1, 12
                st r1, 6
                live %42
                live %42
                live %42
                live %42
                zjmp %-20

live_four:      fork %:live_one
                st r1, 24
                st r1, 18
                st r1, 12
                st r1, 6
                live %42
                live %42
                live %42
                live %42
                zjmp %-20

wall:           ld :jump, r6
                fork %:wall_one
                fork %:live
                zjmp %-6

wall_one:       st r6, -400
                st r6, -401
                st r6, -402
                st r6, -403
                st r6, -404
                st r6, -405
                st r6, -406
                st r6, -407
                st r6, -408
                st r6, -409
                st r6, -410
                st r6, -411
                st r6, -412
                st r6, -413
                st r6, -414
                st r6, -415
                st r6, -416
                st r6, -417
                st r6, -418
                st r6, -419
                st r6, -420
                st r6, -421
                st r6, -422
                st r6, -423
                st r6, -424
                st r6, -425
                zjmp %:wall_one

first_attack:   lfork %-2024
                lfork %-3024
                lfork %-4024
                lfork %5500
                zjmp %:first_attack

second_attack:  lfork %-2024
                lfork %-3024
                lfork %-4024
                lfork %5500
                zjmp %:second_attack

jump:           zjmp %:live_one

conqueror:      ld %0, r15
                sti r1, %28, %1
                sti r1, %349, %1
                sti r1, %178, %1
                st r1, r10
                fork %:label_two
                live %42
                fork %:label_one
                ld %655339, r7
                ld %655329, r8
                ld %655319, r9
                ld %655309, r10
                ld %655299, r11
                ld %40, r1
                ld %45, r2
                ld %50, r3
                ld %55, r4
                ld %55, r5
                xor r16, r16, r16
                zjmp %:label_four

label_one:      ld %655289, r7
                ld %655279, r8
                ld %655269, r9
                ld %84476042, r10
                ld %1409748737, r11
                ld %90, r1
                ld %95, r2
                ld %100, r3
                ld %14, r4
                ld %144, r5
                xor r16, r16, r16
                zjmp %:label_four

label_two:      live %42
                fork %:label_three
                ld %190056463, r7
                ld %251857748, r8
                ld %168756225, r9
                ld %42, r11
                ld %151000843, r11
                ld %5, r1
                ld %8, r2
                ld %7, r3
                ld %6, r4
                ld %140, r5
                xor r16, r16, r16
                zjmp %:label_four

label_three:    ld %34296841, r7
                ld %655259, r8
                ld %655249, r9
                ld %190057231, r10
                ld %167770889, r11
                ld %9, r1
                ld %115, r2
                ld %120, r3
                ld %10, r4
                ld %0, r5
                xor r16, r16, r16
                zjmp %:label_four

label_four:     live %42
                fork %:label_four
                zjmp %:label_five

label_five:     sti r10, r15, r4
                live %42
                sti r11, r15, r5
                zjmp %138
