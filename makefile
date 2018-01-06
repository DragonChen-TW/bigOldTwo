all:s_c
s_c:server.c client.c game.o card.o
	gcc server.c card.o game.o -o server
	gcc client.c -o client
	rm *.o
test:test.c card.o game.o printout.o
	gcc test.c card.o game.o printout.o -o test_c -lgraph
	rm *.o
card.o:card.c card.h
	gcc -c card.c
game.o:game.c game.h
	gcc -c game.c
printout.o:printout.c printout.h
	gcc -c printout.c
clean:
	rm test_c server client
