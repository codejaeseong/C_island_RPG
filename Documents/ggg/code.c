#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

int hp = 100; //ü��
int sp = 100; //���׹̳�
int hung = 100; //�����
int map; // ��
int inven=0;

int intro_screen(); //��Ʈ�� ȭ��

int tinput(); // ���� �Է�

//���� bar
void sbar_main();
void sbar_move();
void sbar_act();
void sbar_item();
void sbar_hunt();

//�ൿ �Լ�
int hunt(); //��� �Լ�

//�׸�
void forest_pic();
void beach_pic();
void hut_pic();

int main() //�޴�
{
	intro_screen(); //print

	while (1)
	{
		system("cls");
		map = 3;
		beach_pic(); //�غ� �׸�
		sbar_main(); //print
		Sleep(800);
	}


}



//-----------------------------------[ ���� �Լ� ]----------------------
void sbar_main() //���� ���� ��
{
	printf("==========================================\n");
	printf("   ü��:%d    ���׹̳�:%d   ���:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("  ��������������������   ����������������������   ����������������������  \n");
	printf("  �� 1 �̵� ��   �� 2 �ൿ  ��   �� 3 �����ۦ�  \n");
	printf("  ��������������������   ����������������������   ����������������������  \n");
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
void sbar_move() //�̵� ���ù�
{
	printf("==========================================\n");
	printf("   ü��:%d    ���׹̳�:%d   ���:%d \n", hp, sp, hung);
	printf("���������������� ���������������������� �������������������� ������������������ \n");
	printf("�� 1 �� �� �� 2 ���θ��� �� 3 �غ� �� �� 4 �޴���  \n");
	printf("���������������� ���������������������� �������������������� ������������������ \n");
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
void sbar_act() //�ൿ ��
{
	printf("==========================================\n");
	printf("   ü��:%d    ���׹̳�:%d   ���:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("������������������ ���������������������� �������������������� ������������������ \n");
	printf("�� 1 ��ɦ� �� 2 �Ա�  �� �� 3 �޽� �� �� 5 �޴���  \n");
	printf("������������������ ���������������������� �������������������� ������������������ \n");
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
void sbar_item() //������ ��
{
	printf("==========================================\n");
	printf("   ü��:%d    ���׹̳�:%d   ���:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("                               \n");
	printf("                �ķ� : %d                 \n", inven);
	printf("                              \n");
	printf("==========================================\n");

	Sleep(1000);
	system("cls");
}

void sbar_hunt()
{
	printf("==========================================\n");
	printf("   ü��:%d    ���׹̳�:%d   ���:%d \n", hp, sp, hung);
	printf("==========================================\n");
	printf("                      \n");
	printf("           ����� �ķ� : +1        \n");
	printf("                       \n");
	printf("==========================================\n");
	Sleep(1000);
	system("cls");
}

//-------------------------------[ �ൿ �Լ� ]-----------------------------------




























//�׸�
void forest_pic()
{
	map = 1;
	printf("      ������                          [��]   \n");
	printf("     ��������                ������        \n");
	printf("    ����������             ����������      \n");
	printf("  ��������������          ������������      \n");
	printf("  ��������������         ��������������     \n");
	printf("  ��������������   ����   ������������      \n");
	printf("  ��������������  ������   ����������       \n");
	printf("    ����������   ��������   ��������        \n");
	printf("       ����     ����������    ����         \n");
	printf("       ����     ����������    ����         \n");
	printf("       ����     ����������    ����         \n");
	printf("       ����       ������      ����        \n");
	printf(" ����  ����        ����   ��  ����        \n");
	printf("������ ����   ��   ����  ���� ����        \n");
	printf(" ����  ����  ����  ����   ��  ����        \n");
	printf("  ��   ���� ������ ����   ��  ����        \n");
	printf("  ��   ����   ��   ����   ��  ����        \n");
}
void beach_pic()
{
	map = 3;
	printf("                                  [�غ�] |\n");
	printf("                ����������               |\n");
	printf("             ����������������            |\n");
	printf("           ��������������������          |\n");
	printf("         ������������������������        |\n");
	printf("~~~~~~~~��������������������������~~~~~~~|\n");
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
	printf("==================â��â��================\n");
	printf(" ������������                   =========|\n");
	printf(" ���� || �դ�                   |��������|\n");
	printf(" ��   ||   ��                   |��������|\n");
	printf(" ��===||===��                   |��������|\n");
	printf(" ��   ||   ��                   |å������|\n");
	printf(" ��   ||   ��                   =========|\n");
	printf(" ������������                            |\n");
	printf("                                         |\n");
	printf("                                         |\n");
	printf("   �� ��                                 |\n");
	printf(" =========                               |\n");
	printf(" |       |  ��                 ����������|\n");
	printf(" |       |                     ����������|\n");
	printf(" |       |  ��                 ����������|\n");
	printf(" |       |                     ����ħ����|\n");
	printf(" |       |  ��                 ����ħ����|\n");
	printf(" |       |                     �����뤱��|\n");
	printf(" |       |  ��                 ����������|\n");
	printf(" =========                     ����������|\n");
	printf("   �� ��                                 |\n");
	printf("==========================================\n");

}


int tinput()
{
	int sel;
	printf("�ൿ:");
	scanf_s("%d", &sel);
	return sel;
}

//��Ʈ��
int intro_screen()
{
	while (1)
	{
		if (_kbhit())
		{
			break;
		}
		printf("\n\n");
		printf("  ��������    ������   ��    �������� \n");
		printf("  ��    ��   ��    ��  ��    ��       \n");
		printf("  ��������    ������   ��    ��������  \n");
		printf("                       ��              \n");
		printf("  ��������       ��             ��     \n");
		printf("     ��          ������      ��������  \n");
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
		printf("  ��������    ������   ��    �������� \n");
		printf("  ��    ��   ��    ��  ��    ��       \n");
		printf("  ��������    ������   ��    ��������  \n");
		printf("                       ��              \n");
		printf("  ��������       ��             ��     \n");
		printf("     ��          ������      ��������  \n");
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
		printf("  ��������    ������   ��    �������� \n");
		printf("  ��    ��   ��    ��  ��    ��       \n");
		printf("  ��������    ������   ��    ��������  \n");
		printf("                       ��              \n");
		printf("  ��������       ��             ��     \n");
		printf("     ��          ������      ��������  \n");
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
		printf("  ��������    ������   ��    �������� \n");
		printf("  ��    ��   ��    ��  ��    ��       \n");
		printf("  ��������    ������   ��    ��������  \n");
		printf("                       ��              \n");
		printf("  ��������       ��             ��     \n");
		printf("     ��          ������      ��������  \n");
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