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
// card and cardset
int cardsBig(Card a, Card b);
int chooseCardSet(Card card_set[5], int n);
// game
void game();

int main(int argc, char const *argv[]) {
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
		if(cards[i].flow == 'S')printf("黑 ");
		else if(cards[i].flow == 'H')printf("紅 ");
		else if(cards[i].flow == 'D')printf("方 ");
		else if(cards[i].flow == 'C')printf("梅 ");
		// printf("%2c ",cards[i].flow);
	}
	putchar('\n');
	for(i = 0;i < len;++i)printf("%2d ",cards[i].point);
	putchar('\n');
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
int chooseCardSet(Card card_set[5], int n){
    if(n == 1){
		return 1;
	}
	else if(n == 2){
		return 2;
	}
	else if(n == 5){
		return 5;
	}
	else return -1;
}

// game
void game(){
	srand(time(NULL));
	Card all_cards[52], player1[13];
	initCard(all_cards,player1);
	printCards(player1, 13);

	Card now[5];
	now[0] = player1[0];
	printf("%d\n",chooseCardSet(now,1));
}
