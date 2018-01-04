#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "game.h"

// init hi
void initUser(Card cards[52],Card user[13]){
	char got[52] = {0};		// using char to simulate bool save some memory
	for(int i = 0;i < 13;++i){
		int loc = rand() % 52;
		while(got[loc])loc = rand() % 52;
		got[loc] = 1;
		user[i] = cards[loc];
	}
	sortCards(user);
}
void initCard(Card cards[52],Card user[13]){
	createAllCard(cards);
	initUser(cards,user);
}
