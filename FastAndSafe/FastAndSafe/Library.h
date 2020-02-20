struct Can
{
	int c;
	int d;
	int sign;
};
struct xu
{
	char c = '@';
	int x;
	int y;
};
struct Slow
{
	int x;
	int y;
};
struct Life
{
	int h;
	int t;
};
struct player
{
	char ten[30];
	int diem;
};
struct node
{
	int data;
	struct node *pNext;
};
typedef struct node NODE;
struct queue
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct queue QUEUE;
void Nocursortype();
void gotoxy(int x, int y);
void KhoiTaoQueue(QUEUE &q);
NODE *KhoiTaoNode(int x);
bool IsEmpty(QUEUE q);
bool Push(QUEUE &q, NODE *p);
bool Pop(QUEUE &q, int &x);
bool Top(QUEUE &q, int &x);
typedef char str[50];
int test(char a[50][30], Can vatcan[10], int x, int y, int k, int &o);
int TestXu(int xux, int xuy, int x, int y);
int Xuli(int xux, int xuy, int x, int y);
void XeF1(char a[50][30], int x, int y);
void Xoavatcan(char a[50][30], Can &x);
void XoaXeF1(char a[50][30], int x, int y);
void VeCan(char a[50][30], int &x, int y);
void XuatMang(char a[50][30], int n, int m);
void XepHang(player choi[20], int &nplayer);
void BXH();
enum TRANGTHAI { up, down, enter, esc, backspace };
TRANGTHAI key(int a);
int DieuKhien(str Menu[], int n);
void InitColor(int color[50]);
void XuatMang(char a[50][30], int n, int m, int color[50]);