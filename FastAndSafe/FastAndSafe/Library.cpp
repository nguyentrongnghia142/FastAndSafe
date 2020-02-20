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
const int vientrang = 7;
const int vienden = 0;

void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
void KhoiTaoQueue(QUEUE &q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}
NODE *KhoiTaoNode(int x)
{
	NODE *p = new NODE();
	if (p == NULL)
	{
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
bool IsEmpty(QUEUE q)
{
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;
}
bool Push(QUEUE &q, NODE *p)
{
	if (p == NULL)
	{
		return false;
	}
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p;
	}
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;
	}
	return true;
}
bool Pop(QUEUE &q, int &x)
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE *p = q.pHead;
		x = p->data;
		q.pHead = q.pHead->pNext;
		delete p;
	}
	return true;
}
bool Top(QUEUE &q, int &x)
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	x = q.pHead->data;
	return true;
}
int test(char a[50][30], Can vatcan[10], int x, int y, int k,int &o)
{
	int i;
	for (i = 0; i <= k; i++)
		if ((vatcan[i].c == x - 2) || (vatcan[i].c == x - 1) || (vatcan[i].c == x) || (vatcan[i].c == x + 1) || (vatcan[i].c == x + 2))
			if ((vatcan[i].d == y - 2) || (vatcan[i].d == y - 1) || (vatcan[i].d == y) || (vatcan[i].d == y + 1) || (vatcan[i].d == y + 2))
			{
				o = i;
				return 1; 
			}
				
	return 0;
}
int TestXu(int xux, int xuy, int x, int y)
{
	if ((xux == x - 1) || (xux == x) || (xux == x + 1))
		if ((xuy == y - 1) || (xuy == y) || (xuy == y + 1))
			return 1;
	return 0;
}
int Xuli(int xux, int xuy, int x, int y)
{
	if ((xux == x - 1) || (xux == x) || (xux == x + 1))
		if ((xuy == y - 1) || (xuy == y) || (xuy == y + 1))
			return 1;
	return 0;
}
void XeF1(char a[50][30], int x, int y)
{
	a[x - 1][y - 1] = a[x - 1][y + 1] = a[x + 1][y - 1] = a[x + 1][y + 1] = 'o';
	a[x][y - 1] = a[x][y + 1] = '|';
	a[x - 1][y] = '^';
	a[x + 1][y] = '_';
	a[x][y] = '0';
}
void Xoavatcan(char a[50][30], Can &x)
{
	a[x.c][x.d] = a[x.c - 1][x.d] = a[x.c + 1][x.d] = a[x.c][x.d - 1] = ' ';
	a[x.c - 1][x.d - 1] = a[x.c + 1][x.d - 1] = a[x.c][x.d + 1] = a[x.c - 1][x.d + 1] = a[x.c + 1][x.d + 1] = ' ';
	x.c = 0;
}
void XoaXeF1(char a[50][30], int x, int y)
{
	a[x][y] = a[x - 1][y] = a[x + 1][y] = a[x][y - 1] = a[x - 1][y - 1] = a[x + 1][y - 1] = a[x][y + 1] = a[x - 1][y + 1] = a[x + 1][y + 1] = ' ';
}
void VeCan(char a[50][30], int &x, int y)
{
	a[x - 1][y - 1] = a[x - 1][y] = a[x - 1][y + 1] = ' ';
	a[x][y - 1] = a[x][y] = a[x][y + 1] = 219;
	a[x + 1][y - 1] = a[x + 1][y] = a[x + 1][y + 1] = 219;
	a[x + 2][y - 1] = a[x + 2][y] = a[x + 2][y + 1] = 219;
	x++;
}
void XuatMang(char a[50][30], int n, int m, int color[50])
{
	for (int i = 0; i < 50; i++)
	{
		if (color[i] == vientrang)
			color[i] = vienden;
		else color[i] = vientrang;
	}
	int i, j;
	gotoxy(0, 0);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (j == 0 || j == m - 1)
			{
				TextColor(color[i]);
				printf("%c", a[i][j]);
				TextColor(7);
			}
			else {
				if (a[i][j] == 'o' || a[i][j] == '|' )
					TextColor(12);
				else if (a[i][j] == '^' || a[i][j] == '_' || a[i][j] == '0')
					TextColor(10);
				else if (a[i][j] == '$')
					TextColor(14);
				else if (a[i][j] == 'L')
					TextColor(13);
				else if (a[i][j] == 'S')
					TextColor(9);
				else TextColor(3);
				
				printf("%c", a[i][j]);
			}
		}
		printf("\n");
	}
}
void XepHang(player choi[20], int &nplayer)
{
	int i, j;
	nplayer = 1;
	char c;
	FILE *f;
	fopen_s(&f, "BXH.txt", "r");
	if (f == NULL)
	{
		printf("Khong doc duoc file.\n");
		return;
	}
	while (!feof(f))
	{
		j = 0;
		fscanf_s(f, "%c", &c);
		if (c == -52)
			break;
		fscanf_s(f, "%d", &choi[nplayer].diem);
		fscanf_s(f, "%c", &c);
		while (1)
		{
			fscanf_s(f, "%c", &c);
			if ((c == '\n') || (feof(f)) || (c == 52))
			{
				choi[nplayer].ten[j] = '\0';
				nplayer++;
				break;
			}
			choi[nplayer].ten[j] = c;
			j++;
		}
	}
	fclose(f);
	for (i = 0; i < nplayer - 1; i++)
		for (j = i + 1; j < nplayer; j++)
			if (choi[i].diem < choi[j].diem)
			{
				player temp = choi[i];
				choi[i] = choi[j];
				choi[j] = temp;
			}
	fopen_s(&f, "BXH.txt", "wt");
	if (f == NULL)
	{
		printf("Khong ghi duoc file.\n");
		return;
	}
	for (i = 0; i < nplayer - 1; i++)
	{
		fprintf(f, " %d ", choi[i].diem);
		fprintf(f, "%s\n", choi[i].ten);
	}
	fprintf(f, " %d %s", choi[nplayer - 1].diem, choi[nplayer - 1].ten);
	fclose(f);
}
void BXH()
{
	FILE *f;
	char c;
	fopen_s(&f, "BXH.txt", "r");
	if (f == NULL)
	{
		printf("Khong doc duoc file.\n");
		return;
	}
	TextColor(11);
	printf("\n-----BANG XEP HANG:-----\n\n");
	TextColor(15);
	while (!feof(f))
	{
		fscanf_s(f, "%c", &c);
		printf("%c", c);
	}
	fclose(f);
}
TRANGTHAI key(int a)
{
	if (a == 224)
	{
		char c;
		c = _getch();
		if (c == 72)
		{
			return up;
		}
		if (c == 80)
		{
			return down;
		}
	}
	else if (a == 13)
	{
		return enter;
	}
	else if (a == 8)
	{
		return backspace;
	}
	else if (a == 27)
	{
		return esc;
	}
}
int DieuKhien(str Menu[], int n)
{
	int tt = 1;
	int *color = new int[n];
	for (int i = 1; i <= n; i++)
	{
		color[i] = mauchu;
	}
	color[1] = maunen;
	while (1)
	{
		clrscr();
		int x = 14;
		gotoxy(45, x);
		x++;
		TextColor(12);
		puts(Menu[0]);
		for (int i = 1; i < n; i++)
		{
			gotoxy(45, x++);
			TextColor(color[i]);
			puts(Menu[i]);
		}
		int a = _getch();
		TRANGTHAI TT = key(a);
		switch (TT)
		{
		case(up):
		{
			if (tt == 1)
			{
				tt = n - 1;
			}
			else
			{
				tt--;
			}
			break;
		}
		case(down):
		{
			if (tt == n - 1)
			{
				tt = 1;
			}
			else
			{
				tt++;
			}
			break;
		}
		case(enter):
		{
			return tt;
			break;
			free(color);
		}
		case(esc):
		{
			return 0;
		}
		}
		for (int i = 1; i < n; i++)
		{
			color[i] = mauchu;
		}
		color[tt] = maunen;
	}
}
void InitColor(int color[50])
{
	for (int i = 0; i < 50; i++)
	{
		if (i % 2 == 0)
			color[i] = vientrang;
		else color[i] = vienden;
	}
}