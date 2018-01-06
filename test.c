#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "game.h"
#include "printout.h"

void game();
void testCardSet();

int main(int argc, char const *argv[]) {
  openWindow();/*open game */
  game();

  return 0;
}
// game
void game(){
	srand(time(NULL));

  drawCardTable();
	Card all_cards[52], player[4][13];
	initCard(all_cards,player);
	printCards(player[0], 13);

  // testCardSet();
}

void testCardSet(){
	Card now[5];
	now[0] = makeCard('C',9);
	printCardSet(now, 1);

	now[0] = makeCard('H',2);
	now[1] = makeCard('S',2);
	printCardSet(now, 2);

	now[0] = makeCard('H',5);
	now[1] = makeCard('S',6);
	now[2] = makeCard('D',7);
	now[3] = makeCard('D',8);
	now[4] = makeCard('D',9);
	printCardSet(now, 5);

	now[0] = makeCard('H',3);
	now[1] = makeCard('S',3);
	now[2] = makeCard('D',11);
	now[3] = makeCard('H',11);
	now[4] = makeCard('D',11);
	printCardSet(now, 5);

	now[0] = makeCard('H',8);
	now[1] = makeCard('S',8);
	now[2] = makeCard('D',8);
	now[3] = makeCard('H',12);
	now[4] = makeCard('D',12);
	printCardSet(now, 5);

	now[0] = makeCard('S',9);
	now[1] = makeCard('H',9);
	now[2] = makeCard('D',9);
	now[3] = makeCard('C',9);
	now[4] = makeCard('H',5);
	printCardSet(now, 5);

	now[0] = makeCard('D',3);
	now[1] = makeCard('S',10);
	now[2] = makeCard('H',10);
	now[3] = makeCard('D',10);
	now[4] = makeCard('C',10);
	printCardSet(now, 5);

	now[0] = makeCard('D',8);
	now[1] = makeCard('D',9);
	now[2] = makeCard('D',10);
	now[3] = makeCard('D',11);
	now[4] = makeCard('D',12);
	printCardSet(now, 5);
}
