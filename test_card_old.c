#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Card{
	char flow; // 'S' 'H' 'D' 'C'
	int point;
};
typedef struct Card Card;

// functional tool
Card makeCard(char f, int p);
void swapCard(Card *a, Card *b);
void sortCards(Card user[13]);
// cards
void createAllCard(Card cards[52]);
void printCards(Card cards[52],int len);
// init
void initUser(Card cards[52],Card user[13]);
void initCard(Card cards[52],Card user[13]);
// card
int cardsBig(Card a, Card b);
// cardSet
int isPair(Card card_set[5]);
int isStraight(Card card_set[5]);
int isFullHouse(Card card_set[5]);
int isFourKind(Card card_set[5]);
int isStraightFlush(Card card_set[5]);
int getCardSetNum(Card card_set[5], int n);
void printCardSet(Card card_set[5], int n);
// game
void game();
// testing
void testCardSet();


int main(int argc, char const *argv[]){
	game();

	return 0;
}


// functional tool
Card makeCard(char f, int p){
	Card temp = {.flow = f, .point = p};
	return temp;
}
void swapCard(Card *a, Card *b){
	Card temp = *a;
	*a = *b;
	*b = temp;
}
void sortCards(Card user[13]){
    // just bubble sort
	int i, j;
	for(i = 12;i > 0;--i){
		for(j = 0;j < i;++j){
			if(cardsBig(user[j],user[j + 1])){
				swapCard(&user[j],&user[j + 1]);
			}
		}
	}
}

// cards
void createAllCard(Card cards[52]){
	int i;
	for(i = 0;i < 13;++i)cards[i] = makeCard('S',i % 13 + 1);
	for(i = 13;i < 26;++i)cards[i] = makeCard('H',i % 13 + 1);
	for(i = 26;i < 39;++i)cards[i] = makeCard('D',i % 13 + 1);
	for(i = 39;i < 52;++i)cards[i] = makeCard('C',i % 13 + 1);
}
void printCards(Card cards[52],int len){
	int i;
	for(i = 0;i < len;++i){
        // char version
		if(cards[i].flow == 'S')printf("黑 ");
		else if(cards[i].flow == 'H')printf("紅 ");
		else if(cards[i].flow == 'D')printf("方 ");
		else if(cards[i].flow == 'C')printf("梅 ");

        // unicode symbol version (super small)
		// if(cards[i].flow == 'S')printf(" %s ","\u2660");
		// else if(cards[i].flow == 'H')printf(" %s ","\u2665");
		// else if(cards[i].flow == 'D')printf(" %s ","\u2666");
		// else if(cards[i].flow == 'C')printf(" %s ","\u2663");

		// printf("%2c ",cards[i].flow);
	}
	printf("\n");
	for(i = 0;i < len;++i)printf("%2d ",cards[i].point);
	printf("\n");
}

// init
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

// card and cardset
int cardsBig(Card a, Card b){

	if(a.point != b.point) return a.point > b.point;
	else{
		char big[4] = {'S','H','D','C'};
		int f1, f2;
		for(int i = 0;i < 4;++i){
			if(a.flow == big[i])f1 = i;
			if(b.flow == big[i])f2 = i;
		}

		return f1 > f2;
	}
}
int isPair(Card card_set[5]){
	return card_set[0].point == card_set[1].point;
}
int isStraight(Card card_set[5]){
	if(card_set[0].point == 1 && card_set[1].point == 10 && card_set[2].point == 11 &&
	card_set[3].point == 12 && card_set[4].point == 13)
		return 1;

	for(int i = 1;i < 5;++i)
		if(card_set[i].point - card_set[i - 1].point != 1)return 0;
	return 1;
}
int isFullHouse(Card card_set[5]){
	if(card_set[0].point == card_set[1].point &&
	card_set[3].point == card_set[4].point &&
	(card_set[2].point == card_set[1].point ||
	card_set[2].point == card_set[3].point))
		return 1;
	else return 0;
}
int isFourKind(Card card_set[5]){
	if(card_set[1].point == card_set[2].point &&
	card_set[2].point == card_set[3].point &&
	(card_set[0].point == card_set[1].point ||
	card_set[3].point == card_set[4].point))
		return 1;
	else return 0;
}
int isStraightFlush(Card card_set[5]){
	if(!isStraight(card_set))return 0;
	else{
		for(int i = 1;i < 5;++i)
			if(card_set[i].flow != card_set[i - 1].flow)return 0;
		return 1;
	}
}
int getCardSetNum(Card card_set[5], int n){
    if(n == 1)			//single
		return 1;
	else if(n == 2){	// pair
		if(isPair(card_set))return 2;
	}
	else if(n == 5){
		if(isFullHouse(card_set))return 4;
		else if(isFourKind(card_set))return 5;
		else if(isStraightFlush(card_set))return 6;
		else if(isStraight(card_set))return 3;
	}

	return -1;		// not any card_set
}
void printCardSet(Card card_set[5], int n){
	printCards(card_set,n);

	int num = getCardSetNum(card_set,n);
	if(num == -1)
		printf("None\n");
	else if(num == 1)
		printf("Single\n");
	else if(num == 2)
		printf("Pair\n");
	else if(num == 3)
		printf("Straight\n");
	else if(num == 4)
		printf("Full House\n");
	else if(num == 5)
		printf("Four of a kind\n");
	else if(num == 6)
		printf("Straight Flush\n");

	printf("\n");
}

// game
void game(){
	srand(time(NULL));

	Card all_cards[52], player1[13];
	initCard(all_cards,player1);
	printCards(player1, 13);

	char opt = getchar();
	while(opt != 'e'){
		printCards(player1,13);

		printw("^");
		opt = getchar();
	}

	endwin();
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
