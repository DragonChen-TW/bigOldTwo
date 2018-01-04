all:test_card
test_card:test.c card.o game.o printout.o
	gcc test.c card.o game.o printout.o -o test_card -lgraph
	rm *.o
card.o:card.c card.h
	gcc -c card.c
game.o:game.c game.h
	gcc -c game.c
printout.o:printout.c printout.h
	gcc -c printout.c
clean:
	rm test_card
