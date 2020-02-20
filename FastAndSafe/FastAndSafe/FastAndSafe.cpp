// FastAndSafe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "windows.h"
#include "string.h"
#include "conio.h"
#include "console.h"
#include "Library.h"
#define maunen 11
#define mauchu 15

str Menu[5] = { "====FASR AND SAFE====","    1.PLAY", "    2.AUTOPLAY", "    3.RANK","    4.EXIT" };
str Continue[3] = { "CONTINUE?", "YES", "NO" };
void Move(char a[50][30], int x, int &y, int dich);
int main()
{
flag2:
	Nocursortype();
	int z = DieuKhien(Menu, 5);
	player choi[20];
	int dem, dem2, nplayer, nguoichoi = 0, chon;
	float r = 10;
	switch (z)
	{
	case(1):
	{
	flag1:
		dem = 1;
		char a[50][30];
		Can vatcan[10];
		Slow S;
		Life L;
		int xux, xuy, dem1 = 0;
		int i, j, l, k, n, m, x, y, c, d, o; //c,d: vatcan; x,y: xeF1; n,m: mangduongdua k:bien dem cua vat can o:bienvitritrongmangvatcan
		int diem = 0, tgbua, Mang = 0;;
		float t = 70,tamt;
		srand(time(NULL));
		system("cls");
		n = 29;
		m = 30;
		x = n - 2;
		y = m / 2;
		k = 0;
		for (i = 0; i < n; i++)
			a[i][0] = a[i][m - 1] = '|';
		for (i = 0; i < n; i++)
			for (j = 1; j < m - 1; j++)
				a[i][j] = ' ';
		int color[50];
		InitColor(color);
		for (i = 0; i < 10; i++)
		{
			vatcan[i].c = 0;
		}
		i = 0;
		xux = 0;
		do
		{
			dem1 = 0;
			xuy = rand() % 28;
			for (j = 0; j < k; j++)
				if ((vatcan[j].c < 5) && ((vatcan[j].d == xuy) || (vatcan[j].d == xuy - 1) || (vatcan[j].d == xuy + 1)))
					dem1++;
		} while ((dem1 != 0) || (xuy == 0));
		a[xux][xuy] = '$';
		while (1)
		{
			i++;
			XuatMang(a, n, m,color);
			if (i % 8 == 0)
			{
				for (j = 0; j < 10; j++)
					if (vatcan[j].c == 0)
					{
						o = j;
						break;
					}
				vatcan[o].c = 1;
				if (dem % 3 == 0)
					vatcan[o].sign = 1;
				else vatcan[o].sign = 0;
				dem++;
				do
				{
					vatcan[o].d = rand() % 30;
				} while ((vatcan[o].d <= 1) || (vatcan[o].d >= 28));
				k++;
			}
			XeF1(a, x, y);
			if ((xux == 30) || (xux == -1))
			{
				xux = 0;
				do
				{
					dem1 = 0;
					xuy = rand() % 28;
					for (j = 0; j < k; j++)
						if ((vatcan[j].c < 5) && ((vatcan[j].d == xuy) || (vatcan[j].d == xuy - 1) || (vatcan[j].d == xuy + 1)))
							dem1++;
				} while ((dem1 != 0) || (xuy == 0));
				a[xux][xuy] = '$';
			}
			a[xux][xuy] = ' ';
			xux++;
			a[xux][xuy] = '$';
			if (i % 60 == 0)  // ssan xuat mang song
			{
				L.t = 0;
				do
				{
					dem1 = 0;
					L.h = rand() % 28;
					for (j = 0; j < k; j++)
						if ((vatcan[j].d == L.h) || (vatcan[j].d == L.h - 1) || (vatcan[j].d == L.h + 1) || (xuy == L.h))
							dem1++;
				} while ((dem1 != 0) || (L.h == 0));
				a[L.t][L.h] = 'L';
			}
			if (i >59 && L.t != -1)
			{
				a[L.t][L.h] = ' ';
				L.t++;
				a[L.t][L.h] = 'L';
			}
			if (L.t == 30)
			{
				L.t = -1;
			}
			if (i % 45 == 0)  // ssan xuat bua slow
			{
				S.x = 0;
				do
				{
					dem1 = 0;
					S.y = rand() % 28;
					for (j = 0; j < k; j++)
						if ((vatcan[j].d == S.y) || (vatcan[j].d == S.y - 1) || (vatcan[j].d == S.y + 1) || (xuy == S.y) || (L.h == S.y))
							dem1++;
				} while ((dem1 != 0) || (S.y == 0));
				a[S.x][S.y] = 'S';
			}
			if (i >44 && S.x != -1)
			{
				a[S.x][S.y] = ' ';
				S.x++;
				a[S.x][S.y] = 'S';
			}
			if (S.x == 30)
			{
				S.x = -1;
			}
			if (TestXu(xux, xuy, x, y))
			{
				a[xux][xuy] = ' ';
				diem += 100;
				xux = -1;
			}
			if (Xuli(L.t, L.h, x, y))
			{
				a[L.t][L.h] = ' ';
				Mang++;
				L.t = -1;
			}
			if (Xuli(S.x, S.y, x, y)) // neu nhat bua thoi gian ngu tang 50 ;thoi gian hieu luc cua bua la 20 luot
			{
				a[S.x][S.y] = ' ';
				S.x = -1;
				tamt = t;
				t += 200;
				tgbua = 20;
			}
			if (tgbua == 0)
			{
				t = tamt;
			}
			else tgbua--;
			if (GetAsyncKeyState(VK_UP))
				if (x > 2)
				{
					XoaXeF1(a, x, y);
					x--;
					XeF1(a, x, y);
				}
			if (GetAsyncKeyState(VK_DOWN))
				if (x < 27)
				{
					XoaXeF1(a, x, y);
					x++;
					XeF1(a, x, y);
				}
			if (GetAsyncKeyState(VK_LEFT))
				if (y > 2)
				{
					XoaXeF1(a, x, y);
					y--;
					XeF1(a, x, y);
				}
			if (GetAsyncKeyState(VK_RIGHT))
				if (y < 27)
				{
					XoaXeF1(a, x, y);
					y++;
					XeF1(a, x, y);
				}
			dem2 = 0;
			for (j = 0; j < 10; j++)
				if (vatcan[j].c != 0)
				{
					if (vatcan[j].sign == 1)
					{
						if ((rand() % 27 > y) && (vatcan[j].d < 26) && (!TestXu(xux, xuy, vatcan[j].c, vatcan[j].d)))
						{
							a[vatcan[j].c - 1][vatcan[j].d - 1] = ' ';
							a[vatcan[j].c][vatcan[j].d - 1] = ' ';
							a[vatcan[j].c + 1][vatcan[j].d - 1] = ' ';
							a[vatcan[j].c - 1][vatcan[j].d + 2] = '*';
							a[vatcan[j].c][vatcan[j].d + 2] = '*';
							a[vatcan[j].c + 1][vatcan[j].d + 2] = '*';
							vatcan[j].d += 1;
						}
						else if ((rand() % 27 < y) && (vatcan[j].d > 2) && (!TestXu(xux, xuy, vatcan[j].c, vatcan[j].d)))
						{
							a[vatcan[j].c - 1][vatcan[j].d + 1] = ' ';
							a[vatcan[j].c][vatcan[j].d + 1] = ' ';
							a[vatcan[j].c + 1][vatcan[j].d + 1] = ' ';
							a[vatcan[j].c - 1][vatcan[j].d - 2] = '*';
							a[vatcan[j].c][vatcan[j].d - 2] = '*';
							a[vatcan[j].c + 1][vatcan[j].d - 2] = '*';
							vatcan[j].d -= 1;
						}
					}
					VeCan(a, vatcan[j].c, vatcan[j].d);
				}
			for (j = 0; j <= k; j++)
				if (vatcan[j].c == 30)
				{
					vatcan[j].c = 0;
					o = j;
					k--;
				}
			Sleep(t);
			t -= 0.01;
			gotoxy(35, 4);
			printf("Scores: %d", diem);
			gotoxy(35, 5);
			printf("Life: %d", Mang);
			if (test(a, vatcan, x, y, k,o) && Mang==0)
			{
				gotoxy(10, 14);
				TextColor(12);
				printf("GAME OVER");
				gotoxy(35, 4);
				TextColor(15);
				printf("Scores: %d", diem);
				break;
			}
			else if (test(a, vatcan, x, y, k, o))
			{
				Xoavatcan(a, vatcan[o]);
				Mang--;
			}
			diem++;
		}
		getchar();
		gotoxy(35, 13);
		printf("Nhap ten: ");
		gets_s(choi[0].ten);
		choi[0].diem = diem;
		XepHang(choi, nplayer);
		dem = 0, nplayer, nguoichoi = 0;
		int z = DieuKhien(Continue, 3);
		switch (z)
		{
		case(1):
		{
			goto flag1;
		}
		break;
		case(2):
		{
			goto flag2;
		}
		break;
		}
	}
	break;
	case(2):
	{
		{
			QUEUE q;
			KhoiTaoQueue(q);
			char a[50][30];
			Can vatcan[10];
			int xux, xuy, dem1 = 0;
			int z = 0;
			int i, j, l, k, n, m, x, y, c, d, o; //c,d: vatcan; x,y: xeF1; n,m: mangduongdua k:bien dem cua vat can o:bienvitritrongmangvatcan
			int diemmax = 0, dem = 0, diem = 0;
			float t;
			srand(time(NULL));
			n = 29;
			m = 30;
			x = n - 2;
			y = m / 2;
			k = 0;
			clrscr();
			for (i = 0; i < n; i++)
				a[i][0] = a[i][m - 1] = '|';
			for (i = 0; i < n; i++)
				for (j = 1; j < m - 1; j++)
					a[i][j] = ' ';
			int color[50];
			InitColor(color);
			t = 50;
			for (i = 0; i < 10; i++)
			{
				vatcan[i].c = 0;
			}
			i = 0;
			xux = 0;
			do
			{
				dem1 = 0;
				xuy = rand() % 28;
				for (j = 0; j < k; j++)
					if ((vatcan[j].c < 5) && ((vatcan[j].d == xuy) || (vatcan[j].d == xuy - 1) || (vatcan[j].d == xuy + 1)))
						dem1++;
			} while ((dem1 != 0) || (xuy == 0));
			a[xux][xuy] = '$';
			while (1)
			{
				i++;
				XuatMang(a, n, m, color);
				if (i % 10 == 0)
				{
					for (j = 0; j < n; j++)
						if (vatcan[j].c == 0)
						{
							o = j;
							break;
						}
					vatcan[o].c = 1;
					do
					{
						vatcan[o].d = rand() % 30;
					} while ((vatcan[o].d <= 1) || (vatcan[o].d >= 28));
					k++;
					NODE *p = KhoiTaoNode(vatcan[o].d);
					Push(q, p);
				}
				XeF1(a, x, y);
				if ((xux == 30) || (xux == -1))
				{
					xux = 0;
					do
					{
						dem1 = 0;
						xuy = rand() % 28;
						for (j = 0; j < k; j++)
							if ((vatcan[j].c < 5) && ((vatcan[j].d == xuy) || (vatcan[j].d == xuy - 1) || (vatcan[j].d == xuy + 1)))
								dem1++;
					} while ((dem1 != 0) || (xuy == 0));
					a[xux][xuy] = '$';
				}
				a[xux][xuy] = ' ';
				xux++;
				a[xux][xuy] = '$';
				if (TestXu(xux, xuy, x, y))
				{
					a[xux][xuy] = ' ';
					diem += 100;
					xux = -1;
				}
				Top(q, z);
				if ((y > z - 3) && (y < z + 3))
				{
					if ((y >= 4) && (y <= 24))
					{
						if (y > z)
						{
							XoaXeF1(a, x, y);
							y++;
							XeF1(a, x, y);
						}
						if (y < z)
						{
							XoaXeF1(a, x, y);
							y--;
							XeF1(a, x, y);
						}
						if (z == 5)
						{
							XoaXeF1(a, x, y);
							y--;
							XeF1(a, x, y);
						}
					}
					if ((y < 28) && (y >= 25))
					{
						XoaXeF1(a, x, y);
						y--;
						XeF1(a, x, y);
					}
					if ((y <= 3))
					{
						XoaXeF1(a, x, y);
						y++;
						XeF1(a, x, y);
					}
					if (y == z)
					{
						if (y == 2)
						{
							XoaXeF1(a, x, y);
							y++;
							XeF1(a, x, y);
						}
						else
						{
							XoaXeF1(a, x, y);
							y--;
							XeF1(a, x, y);
						}
					}
				}
				for (j = 0; j < 10; j++)
				{
					if (vatcan[j].c != 0)
					{
						VeCan(a, vatcan[j].c, vatcan[j].d);
					}
				}
				for (j = 0; j <= k; j++)
				{
					if (vatcan[j].c == 30)
					{
						Pop(q, z);
						vatcan[j].c = 0;
						o = j;
						k--;
					}
				}
				Sleep(20);
				gotoxy(35, 4);
				printf("Scores: %d", diem);
				diem++;
				if (_kbhit())
				{
					char c = _getch();
					gotoxy(10, 14);
					printf("GAME OVER");
					printf("\n");
					system("pause");
					goto flag2;
				}
				if (test(a, vatcan, x, y, k,o))
				{
					gotoxy(10, 14);
					printf("GAME OVER");
					gotoxy(35, 4);
					printf("Scores: %d", diem);
					break;
				}
			}
		}
	}
	break;
	case(3):
	{
		while (1)
		{
			clrscr();
			TextColor(mauchu);
			BXH();
			gotoxy(30, 10);
			TextColor(12);
			printf("<= BACKSPACE ");
			int a = _getch();
			TRANGTHAI TT = key(a);
			if (TT == backspace)
			{
				goto flag2;
			}
		}
	}
	case(4):
	{
		return 0;
	}
	}
	printf("\n");
	return 0;
}
void Move(char a[50][30], int x,int &y, int dich)
{
	if (dich < y)
		while (y != dich)
		{
			XoaXeF1(a, x, y);
			y--;
			XeF1(a, x, y);
		}
	else if (dich > y)
		while (y != dich)
		{
			XoaXeF1(a, x, y);
			y++;
			XeF1(a, x, y);
		}
}