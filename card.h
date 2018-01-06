#ifndef card_h
#define card_h

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
void printCardsOld(Card cards[52],int len);
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

#endif
