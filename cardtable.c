#include <math.h>

#include <graphics.h>

#include <conio.h>

#include <dos.h>
#define SCREEN_HEIGHT 700 //設定遊戲視窗高度 
#define SCREEN_WIDTH 1500 //設定遊戲視窗寬度
#define LEFT_MARGINE 50 //設定左邊界 
#define TOP_MARGINE 45 //設定上邊界
#define CARD_WIDTH 100
#define CARD_HEIGHT 150

struct Card{
	char flow; // 'S' 'H' 'D' 'C'
	int point;
};
typedef struct Card Card;
int main()

{
	
 return 0;

}

int test(){
	int test();
 	int gd=9, gm=2;
	char* strtmp = new char[3] ;
	int a[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
 	float f;
 	initwindow(SCREEN_WIDTH + LEFT_MARGINE , SCREEN_HEIGHT + TOP_MARGINE , "Backgammon");
 /**drawcard*/
	for(int j = 0,left = LEFT_MARGINE,right = left+CARD_WIDTH;j<13;j++){
		int top = SCREEN_HEIGHT-TOP_MARGINE-CARD_HEIGHT;
		int down = SCREEN_HEIGHT-TOP_MARGINE;
	 	rectangle(left,top,right,down);
	 	settextstyle(TRIPLEX_FONT, HORIZ_DIR , 5);
	 	sprintf(strtmp,"%s","B");
		outtextxy(left+10,top+10,strtmp);
	 	sprintf(strtmp,"%d",a[j]);
	 	outtextxy(left+20,top+60,strtmp);
	 	left+=CARD_WIDTH+10;
	 	right = left+CARD_WIDTH;
	}
 getch();

 closegraph();
}
