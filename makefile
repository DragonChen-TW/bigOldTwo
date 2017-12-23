all:test_card
test_card:test.c card.o game.o
	gcc test.c card.o game.o -o test_card
	rm *.o
card.o:card.c card.h
	gcc -c card.c
game.o:game.c game.h
	gcc -c game.c
clean:
	rm test_card
