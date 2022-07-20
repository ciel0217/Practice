#include <stdio.h>

int return0(void); // 0 を返す
int return7(void); // 7 を返す
int returnn(int n); // 第一引数の値をそのまま帰す

/* add? は引数の合計値を返す */
int add2(int a, int b); 
int add3(int a, int b, int c);
int add4(int a, int b, int c, int d);
int add5(int a, int b, int c, int d, int e);
int add6(int a, int b, int c, int d, int e, int f);
int add7(int a, int b, int c, int d, int e, int f, int g);

int main(void)
{
	int n = 777;
	int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7;

	printf("return0() = %d\n", return0());
	printf("return7() = %d\n", return7());
	printf("returnn(%d) = %d\n", n, returnn(n));
	printf("add2(%d, %d) = %d\n", a, b, add2(a, b));
	printf("add3(%d, %d, %d) = %d\n", a, b, c, add3(a, b, c));
	printf("add4(%d, %d, %d, %d) = %d\n", a, b, c, d, add4(a, b, c, d));
	printf("add5(%d, %d, %d, %d, %d) = %d\n", a, b, c, d, e, add5(a, b, c, d, e));
	printf("add6(%d, %d, %d, %d, %d, %d) = %d\n", a, b, c, d, e, f, add6(a, b, c, d, e, f));
	printf("add7(%d, %d, %d, %d, %d, %d, %d) = %d\n", a, b, c, d, e, f, g, add7(a, b, c, d, e, f, g));

	return 0;
}