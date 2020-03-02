#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

int hp = 100; //端径
int sp = 100; //什砺耕蟹
int hung = 100; //壕壱把
int map; // 己
int inven=0;

int intro_screen(); //昔闘稽 鉢檎

int tinput(); // 収切 脊径

//識澱 bar
void sbar_main();
void sbar_move();
void sbar_act();
void sbar_item();
void sbar_hunt();

//楳疑 敗呪
int hunt(); //紫撹 敗呪

//益顕
void forest_pic();
void beach_pic();
void hut_pic();

int main() //五敢
{
	intro_screen(); //print

	while (1)
	{
		system("cls");
		map = 3;
		beach_pic(); //背痕 益顕
		sbar_main(); //print
		Sleep(800);
	}


}



//-----------------------------------[ 識澱 敗呪 ]----------------------
void sbar_main() //五昔 識澱 郊
{
	printf("==========================================\n");
	printf("   端径:%d    什砺耕蟹:%d   買奄:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("  ΓΑΑΑΑΑΑΑΑΔ   ΓΑΑΑΑΑΑΑΑΑΔ   ΓΑΑΑΑΑΑΑΑΑΔ  \n");
	printf("  Β 1 戚疑 Β   Β 2 楳疑  Β   Β 3 焼戚奴Β  \n");
	printf("  ΖΑΑΑΑΑΑΑΑΕ   ΖΑΑΑΑΑΑΑΑΑΕ   ΖΑΑΑΑΑΑΑΑΑΕ  \n");
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
void sbar_move() //戚疑 識澱郊
{
	printf("==========================================\n");
	printf("   端径:%d    什砺耕蟹:%d   買奄:%d \n", hp, sp, hung);
	printf("ΓΑΑΑΑΑΑΔ ΓΑΑΑΑΑΑΑΑΑΔ ΓΑΑΑΑΑΑΑΑΔ ΓΑΑΑΑΑΑΑΔ \n");
	printf("Β 1 州 Β Β 2 神砧厳Β Β 3 背痕 Β Β 4 五敢Β  \n");
	printf("ΖΑΑΑΑΑΑΕ ΖΑΑΑΑΑΑΑΑΑΕ ΖΑΑΑΑΑΑΑΑΕ ΖΑΑΑΑΑΑΑΕ \n");
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
void sbar_act() //楳疑 郊
{
	printf("==========================================\n");
	printf("   端径:%d    什砺耕蟹:%d   買奄:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("ΓΑΑΑΑΑΑΑΔ ΓΑΑΑΑΑΑΑΑΑΔ ΓΑΑΑΑΑΑΑΑΔ ΓΑΑΑΑΑΑΑΔ \n");
	printf("Β 1 紫撹Β Β 2 股奄  Β Β 3 妃縦 Β Β 5 五敢Β  \n");
	printf("ΖΑΑΑΑΑΑΑΕ ΖΑΑΑΑΑΑΑΑΑΕ ΖΑΑΑΑΑΑΑΑΕ ΖΑΑΑΑΑΑΑΕ \n");
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
void sbar_item() //焼戚奴 郊
{
	printf("==========================================\n");
	printf("   端径:%d    什砺耕蟹:%d   買奄:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("                               \n");
	printf("                縦勲 : %d                 \n", inven);
	printf("                              \n");
	printf("==========================================\n");

	Sleep(1000);
	system("cls");
}

void sbar_hunt()
{
	printf("==========================================\n");
	printf("   端径:%d    什砺耕蟹:%d   買奄:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("                      \n");
	printf("           紫撹廃 縦勲 : +1        \n");
	printf("                       \n");
	printf("==========================================\n");
	Sleep(1000);
	system("cls");
}

//-------------------------------[ 楳疑 敗呪 ]-----------------------------------




























//益顕
void forest_pic()
{
	map = 1;
	printf("      けけけ                          [州]   \n");
	printf("     けけけけ                けけけ        \n");
	printf("    けけけけけ             けけけけけ      \n");
	printf("  けけけけけけけ          けけけけけけ      \n");
	printf("  けけけけけけけ         けけけけけけけ     \n");
	printf("  けけけけけけけ   けけ   けけけけけけ      \n");
	printf("  けけけけけけけ  けけけ   けけけけけ       \n");
	printf("    けけけけけ   けけけけ   けけけけ        \n");
	printf("       けけ     けけけけけ    けけ         \n");
	printf("       けけ     けけけけけ    けけ         \n");
	printf("       けけ     けけけけけ    けけ         \n");
	printf("       けけ       けけけ      けけ        \n");
	printf(" ぞぞ  けけ        けけ   ぞ  けけ        \n");
	printf("ぞぞぞ けけ   ぞ   けけ  ぞぞ けけ        \n");
	printf(" ぞぞ  けけ  ぞぞ  けけ   ぞ  けけ        \n");
	printf("  ぞ   けけ ぞぞぞ けけ   ぞ  けけ        \n");
	printf("  ぞ   けけ   ぞ   けけ   ぞ  けけ        \n");
}
void beach_pic()
{
	map = 3;
	printf("                                  [背痕] |\n");
	printf("                ぞぞぞぞぞ               |\n");
	printf("             ぞぞぞぞぞぞぞぞ            |\n");
	printf("           ぞぞぞぞぞぞぞぞぞぞ          |\n");
	printf("         ぞぞぞぞぞぞぞぞぞぞぞぞ        |\n");
	printf("~~~~~~~~ぞぞぞぞぞぞぞぞぞぞぞぞぞ~~~~~~~|\n");
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
	printf("==================但庚但庚================\n");
	printf(" けけけけけけ                   =========|\n");
	printf(" け舌 || 荊け                   |げげげげ|\n");
	printf(" け   ||   け                   |げげげげ|\n");
	printf(" け===||===け                   |げげげげ|\n");
	printf(" け   ||   け                   |奪げげ舌|\n");
	printf(" け   ||   け                   =========|\n");
	printf(" けけけけけけ                            |\n");
	printf("                                         |\n");
	printf("                                         |\n");
	printf("   し し                                 |\n");
	printf(" =========                               |\n");
	printf(" |       |  し                 けけけけけ|\n");
	printf(" |       |                     けげげげけ|\n");
	printf(" |       |  し                 けけけけけ|\n");
	printf(" |       |                     けけ徴けけ|\n");
	printf(" |       |  し                 けけ徴けけ|\n");
	printf(" |       |                     けけ企けけ|\n");
	printf(" |       |  し                 けけけけけ|\n");
	printf(" =========                     けけけけけ|\n");
	printf("   し し                                 |\n");
	printf("==========================================\n");

}


int tinput()
{
	int sel;
	printf("楳疑:");
	scanf_s("%d", &sel);
	return sel;
}

//昔闘稽
int intro_screen()
{
	while (1)
	{
		if (_kbhit())
		{
			break;
		}
		printf("\n\n");
		printf("  けけけけ    けけけ   け    けけけけ \n");
		printf("  け    け   け    け  け    け       \n");
		printf("  けけけけ    けけけ   け    けけけけ  \n");
		printf("                       け              \n");
		printf("  けけけけ       け             け     \n");
		printf("     け          けけけ      けけけけ  \n");
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
		printf("  けけけけ    けけけ   け    けけけけ \n");
		printf("  け    け   け    け  け    け       \n");
		printf("  けけけけ    けけけ   け    けけけけ  \n");
		printf("                       け              \n");
		printf("  けけけけ       け             け     \n");
		printf("     け          けけけ      けけけけ  \n");
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
		printf("  けけけけ    けけけ   け    けけけけ \n");
		printf("  け    け   け    け  け    け       \n");
		printf("  けけけけ    けけけ   け    けけけけ  \n");
		printf("                       け              \n");
		printf("  けけけけ       け             け     \n");
		printf("     け          けけけ      けけけけ  \n");
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
		printf("  けけけけ    けけけ   け    けけけけ \n");
		printf("  け    け   け    け  け    け       \n");
		printf("  けけけけ    けけけ   け    けけけけ  \n");
		printf("                       け              \n");
		printf("  けけけけ       け             け     \n");
		printf("     け          けけけ      けけけけ  \n");
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