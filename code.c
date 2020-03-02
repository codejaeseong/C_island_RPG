#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

int hp = 100; //체력
int sp = 100; //스테미나
int hung = 100; //배고픔
int map; // 맵
int inven=0;

int intro_screen(); //인트로 화면

int tinput(); // 숫자 입력

//선택 bar
void sbar_main();
void sbar_move();
void sbar_act();
void sbar_item();
void sbar_hunt();

//행동 함수
int hunt(); //사냥 함수

//그림
void forest_pic();
void beach_pic();
void hut_pic();

int main() //메뉴
{
	intro_screen(); //print

	while (1)
	{
		system("cls");
		map = 3;
		beach_pic(); //해변 그림
		sbar_main(); //print
		Sleep(800);
	}


}



//-----------------------------------[ 선택 함수 ]----------------------
void sbar_main() //메인 선택 바
{
	printf("==========================================\n");
	printf("   체력:%d    스테미나:%d   허기:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("  ┌────────┐   ┌─────────┐   ┌─────────┐  \n");
	printf("  │ 1 이동 │   │ 2 행동  │   │ 3 아이템│  \n");
	printf("  └────────┘   └─────────┘   └─────────┘  \n");
	printf("==========================================\n");
	int count = tinput();
	if (count == 1) {
		system("cls");
		if (map == 3) {
			beach_pic();
		}
		else if (map == 1) {
			forest_pic();
		}
		else if (map == 2) {
			hut_pic();
		}
		sbar_move();
	}
	//
	else if (count == 2) {
		system("cls");
		if (map == 3) {
			beach_pic();
		}
		else if (map == 1) {
			forest_pic();
		}
		else if (map == 2) {
			hut_pic();
		}
		sbar_act();
	}
	//
	else if (count == 3) {
		system("cls");
		sbar_item();
		if (map == 1) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			forest_pic(), sbar_main();
		}
		else if (map == 2) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			hut_pic(), sbar_main();
		}
		else if (map == 3) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			beach_pic(), sbar_main();
		}
		if (map == 3) {
			beach_pic();
		}
		else if (map == 1) {
			forest_pic();
		}
		else if (map == 2) {
			hut_pic();
		}
	}
}
void sbar_move() //이동 선택바
{
	printf("==========================================\n");
	printf("   체력:%d    스테미나:%d   허기:%d \n", hp, sp, hung);
	printf("┌──────┐ ┌─────────┐ ┌────────┐ ┌───────┐ \n");
	printf("│ 1 숲 │ │ 2 오두막│ │ 3 해변 │ │ 4 메뉴│  \n");
	printf("└──────┘ └─────────┘ └────────┘ └───────┘ \n");
	printf("==========================================\n");

	int a = tinput();

	if (a == 1) {
		sp = sp - 10;
		hung = hung - 10;
		system("cls");
		forest_pic(), sbar_main();
	}
	else if (a == 2) {
		sp = sp - 10;
		hung = hung - 10;
		system("cls");
		hut_pic(), sbar_main();
	}
	else if (a == 3) {
		sp = sp - 10;
		hung = hung - 10;
		system("cls");
		beach_pic(), sbar_main();
	}
}
void sbar_act() //행동 바
{
	printf("==========================================\n");
	printf("   체력:%d    스테미나:%d   허기:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("┌───────┐ ┌─────────┐ ┌────────┐ ┌───────┐ \n");
	printf("│ 1 사냥│ │ 2 먹기  │ │ 3 휴식 │ │ 5 메뉴│  \n");
	printf("└───────┘ └─────────┘ └────────┘ └───────┘ \n");
	printf("==========================================\n");

	int a = tinput();

	if (a == 1) {
		system("cls");
		inven += 1;
		sp -= 10;
		hung -= 10;
		if (map == 1) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			forest_pic(), sbar_main();
		}
		sbar_hunt();
		if (map == 2) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			hut_pic(), sbar_main();
		}
		else if (map == 3) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			beach_pic(), sbar_main();
		}
	}
	if (a == 2){
		if (hung < 100)
			hung += 10;
			inven -= 1;
		system("cls");
		if (map == 1) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			forest_pic(), sbar_main();
		}
		else if (map == 2) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			hut_pic(), sbar_main();
		}
		else if (map == 3) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			beach_pic(), sbar_main();
		}
	}
	if (a == 3) {
		if (sp < 100)
			sp = sp + 10;
		system("cls");
		if (map == 1) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			forest_pic(), sbar_main();
		}
		else if (map == 2) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			hut_pic(), sbar_main();
		}
		else if (map == 3) {
			//sp = sp - 10;
			//hung = hung - 10;
			//system("cls");
			beach_pic(), sbar_main();
		}
	}
}
void sbar_item() //아이템 바
{
	printf("==========================================\n");
	printf("   체력:%d    스테미나:%d   허기:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("                               \n");
	printf("                식량 : %d                 \n", inven);
	printf("                              \n");
	printf("==========================================\n");

	Sleep(1000);
	system("cls");
}

void sbar_hunt()
{
	printf("==========================================\n");
	printf("   체력:%d    스테미나:%d   허기:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("                      \n");
	printf("           사냥한 식량 : +1        \n");
	printf("                       \n");
	printf("==========================================\n");
	Sleep(1000);
	system("cls");
}

//-------------------------------[ 행동 함수 ]-----------------------------------




























//그림
void forest_pic()
{
	map = 1;
	printf("      ㅁㅁㅁ                          [숲]   \n");
	printf("     ㅁㅁㅁㅁ                ㅁㅁㅁ        \n");
	printf("    ㅁㅁㅁㅁㅁ             ㅁㅁㅁㅁㅁ      \n");
	printf("  ㅁㅁㅁㅁㅁㅁㅁ          ㅁㅁㅁㅁㅁㅁ      \n");
	printf("  ㅁㅁㅁㅁㅁㅁㅁ         ㅁㅁㅁㅁㅁㅁㅁ     \n");
	printf("  ㅁㅁㅁㅁㅁㅁㅁ   ㅁㅁ   ㅁㅁㅁㅁㅁㅁ      \n");
	printf("  ㅁㅁㅁㅁㅁㅁㅁ  ㅁㅁㅁ   ㅁㅁㅁㅁㅁ       \n");
	printf("    ㅁㅁㅁㅁㅁ   ㅁㅁㅁㅁ   ㅁㅁㅁㅁ        \n");
	printf("       ㅁㅁ     ㅁㅁㅁㅁㅁ    ㅁㅁ         \n");
	printf("       ㅁㅁ     ㅁㅁㅁㅁㅁ    ㅁㅁ         \n");
	printf("       ㅁㅁ     ㅁㅁㅁㅁㅁ    ㅁㅁ         \n");
	printf("       ㅁㅁ       ㅁㅁㅁ      ㅁㅁ        \n");
	printf(" ㅎㅎ  ㅁㅁ        ㅁㅁ   ㅎ  ㅁㅁ        \n");
	printf("ㅎㅎㅎ ㅁㅁ   ㅎ   ㅁㅁ  ㅎㅎ ㅁㅁ        \n");
	printf(" ㅎㅎ  ㅁㅁ  ㅎㅎ  ㅁㅁ   ㅎ  ㅁㅁ        \n");
	printf("  ㅎ   ㅁㅁ ㅎㅎㅎ ㅁㅁ   ㅎ  ㅁㅁ        \n");
	printf("  ㅎ   ㅁㅁ   ㅎ   ㅁㅁ   ㅎ  ㅁㅁ        \n");
}
void beach_pic()
{
	map = 3;
	printf("                                  [해변] |\n");
	printf("                ㅎㅎㅎㅎㅎ               |\n");
	printf("             ㅎㅎㅎㅎㅎㅎㅎㅎ            |\n");
	printf("           ㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎ          |\n");
	printf("         ㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎ        |\n");
	printf("~~~~~~~~ㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎ~~~~~~~|\n");
	printf("           ~~~~~~~~~~~~~~~~~~~~          |\n");
	printf("   ~~~   ~~~~~~~~~~~~~~~~~~~~~~    ~~~   |\n");
	printf("             ~~~~~~~~~~~~~~~~            |\n");
	printf("                             ~~~~        |\n");
	printf("      ~~~      ~~~                  ~~~  |\n");
	printf("                       ~~~               |\n");
	printf(" ~~~         ~~~               ~~~       |\n");
	printf("                       ~~~               |\n");
	printf("     ~~~            ~~~              ~~~ |\n");
	printf("           ~~~              ~~~          |\n");
	printf("-----------------------------------------|\n");
	printf(".........................................|\n");
	printf(".........................................|\n");
}
void hut_pic()
{
	map = 2;
	printf("==================창문창문================\n");
	printf(" ㅁㅁㅁㅁㅁㅁ                   =========|\n");
	printf(" ㅁ장 || 롱ㅁ                   |ㅂㅂㅂㅂ|\n");
	printf(" ㅁ   ||   ㅁ                   |ㅂㅂㅂㅂ|\n");
	printf(" ㅁ===||===ㅁ                   |ㅂㅂㅂㅂ|\n");
	printf(" ㅁ   ||   ㅁ                   |책ㅂㅂ장|\n");
	printf(" ㅁ   ||   ㅁ                   =========|\n");
	printf(" ㅁㅁㅁㅁㅁㅁ                            |\n");
	printf("                                         |\n");
	printf("                                         |\n");
	printf("   ㅇ ㅇ                                 |\n");
	printf(" =========                               |\n");
	printf(" |       |  ㅇ                 ㅁㅁㅁㅁㅁ|\n");
	printf(" |       |                     ㅁㅂㅂㅂㅁ|\n");
	printf(" |       |  ㅇ                 ㅁㅁㅁㅁㅁ|\n");
	printf(" |       |                     ㅁㅁ침ㅁㅁ|\n");
	printf(" |       |  ㅇ                 ㅁㅁ침ㅁㅁ|\n");
	printf(" |       |                     ㅁㅁ대ㅁㅁ|\n");
	printf(" |       |  ㅇ                 ㅁㅁㅁㅁㅁ|\n");
	printf(" =========                     ㅁㅁㅁㅁㅁ|\n");
	printf("   ㅇ ㅇ                                 |\n");
	printf("==========================================\n");

}


int tinput()
{
	int sel;
	printf("행동:");
	scanf_s("%d", &sel);
	return sel;
}

//인트로
int intro_screen()
{
	while (1)
	{
		if (_kbhit())
		{
			break;
		}
		printf("\n\n");
		printf("  ㅁㅁㅁㅁ    ㅁㅁㅁ   ㅁ    ㅁㅁㅁㅁ \n");
		printf("  ㅁ    ㅁ   ㅁ    ㅁ  ㅁ    ㅁ       \n");
		printf("  ㅁㅁㅁㅁ    ㅁㅁㅁ   ㅁ    ㅁㅁㅁㅁ  \n");
		printf("                       ㅁ              \n");
		printf("  ㅁㅁㅁㅁ       ㅁ             ㅁ     \n");
		printf("     ㅁ          ㅁㅁㅁ      ㅁㅁㅁㅁ  \n");
		printf("\n                                   v.0.1\n");
		printf("\n");
		printf("==========================================\n");
		printf("             PRESS ANY KEY.             \n");
		printf("==========================================\n");
		Sleep(800);
		system("cls");
		if (_kbhit())
		{
			break;
		}
		printf("\n\n");
		printf("  ㅁㅁㅁㅁ    ㅁㅁㅁ   ㅁ    ㅁㅁㅁㅁ \n");
		printf("  ㅁ    ㅁ   ㅁ    ㅁ  ㅁ    ㅁ       \n");
		printf("  ㅁㅁㅁㅁ    ㅁㅁㅁ   ㅁ    ㅁㅁㅁㅁ  \n");
		printf("                       ㅁ              \n");
		printf("  ㅁㅁㅁㅁ       ㅁ             ㅁ     \n");
		printf("     ㅁ          ㅁㅁㅁ      ㅁㅁㅁㅁ  \n");
		printf("\n                                   v.0.1\n");
		printf("\n");
		printf("==========================================\n");
		printf("             PRESS ANY KEY..            \n");
		printf("==========================================\n");
		Sleep(800);
		system("cls");
		if (_kbhit())
		{
			break;
		}
		printf("\n\n");
		printf("  ㅁㅁㅁㅁ    ㅁㅁㅁ   ㅁ    ㅁㅁㅁㅁ \n");
		printf("  ㅁ    ㅁ   ㅁ    ㅁ  ㅁ    ㅁ       \n");
		printf("  ㅁㅁㅁㅁ    ㅁㅁㅁ   ㅁ    ㅁㅁㅁㅁ  \n");
		printf("                       ㅁ              \n");
		printf("  ㅁㅁㅁㅁ       ㅁ             ㅁ     \n");
		printf("     ㅁ          ㅁㅁㅁ      ㅁㅁㅁㅁ  \n");
		printf("\n                                   v.0.1\n");
		printf("\n");
		printf("==========================================\n");
		printf("             PRESS ANY KEY...           \n");
		printf("==========================================\n");
		Sleep(800);
		system("cls");
		if (_kbhit())
		{
			break;
		}
		printf("\n\n");
		printf("  ㅁㅁㅁㅁ    ㅁㅁㅁ   ㅁ    ㅁㅁㅁㅁ \n");
		printf("  ㅁ    ㅁ   ㅁ    ㅁ  ㅁ    ㅁ       \n");
		printf("  ㅁㅁㅁㅁ    ㅁㅁㅁ   ㅁ    ㅁㅁㅁㅁ  \n");
		printf("                       ㅁ              \n");
		printf("  ㅁㅁㅁㅁ       ㅁ             ㅁ     \n");
		printf("     ㅁ          ㅁㅁㅁ      ㅁㅁㅁㅁ  \n");
		printf("\n                                   v.0.1\n");
		printf("\n");
		printf("==========================================\n");
		printf("             PRESS ANY KEY              \n");
		printf("==========================================\n");
		Sleep(500);
		system("cls");
		if (_kbhit())
		{
			break;
		}
	}
	return 0;
}
