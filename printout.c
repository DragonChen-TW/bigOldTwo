#include <math.h>
#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include "card.h"

#define LEFT_MARGINE 100 //�]�w������
#define TOP_MARGINE 45 //�]�w�W����
#define TABLE_WIDTH 400
#define TABLE_HEIGHT 300
#define CARD_WIDTH 40
#define CARD_HEIGHT 60
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


void openWindow()
{
	int gd=9, gm=2;
	initgraph(&gd,&gm,NULL);
}
void drawCardTable(){
	int startX = 0,startY = 0,endX = 0,endY = 0;
	cleardevice();

	startX = LEFT_MARGINE;
	startY = TOP_MARGINE;
	endX = startX + TABLE_WIDTH;
	endY = startY + TABLE_HEIGHT;
	line(startX,startY,endX,startY);
	line(startX,endY,endX,endY);
	line(startX,startY,startX,endY);
	line(endX,startY,endX,endY);
}
void printCards(Card cards[52],int len)
{
	int i;
	for(i=0;i<len;i++){
		printf("%c ",cards[i].flow);
		printf("%d  ",cards[i].point);
	}
	int startX=0,startY=0,endX=0,endY=0;
	int wordX=0,wordY=0;
	for(i=0;i<=len;i++){
		char strtmp[3] = {};
		char number[3] = {};
		startX = LEFT_MARGINE+i*CARD_WIDTH;
		startY = TOP_MARGINE+TABLE_HEIGHT+50;
		endY = startY + CARD_HEIGHT;
		wordX = startX+10;
		wordY = startY+20;
		strtmp[0] = cards[i].flow;
		sprintf(number,"%d",cards[i].point);
		strncat(strtmp,number,strlen(number));
		line(startX,startY,startX,endY);
		outtextxy(wordX,wordY,strtmp);
	}

 getch();


 return;
}
