#include <stdio.h>
int main(void)
{
	int a[100][100],b[100][100],ans[100][100],ans2[100][100],ans3[100][100];
	int xa, xb, ya, yb, i, j, k;

///////////////////////////////////////////////////////////////////////
//ここで入力
///////////////////////////////////////////////////////////////////////

	printf("何行何列かをスペース区切りで入力\n");//一つ目の行列を入力
	scanf("%d%d", &ya, &xa);

	for (i = 0; i < ya; i++)//一つ目の行列
	{
		for (j = 0; j < xa; j++)
		{
			scanf("%d", &a[j][i]);
		}
	}

	printf("何行何列かをスペース区切りで入力\n");//二つ目の行列を入力
	scanf("%d%d", &yb, &xb);

	for (i = 0; i < yb; i++)//一つ目の行列
	{
		for (j = 0; j < xb; j++)
		{
			scanf("%d", &b[j][i]);
		}
	}
///////////////////////////////////////////////////////////////////////
//ここから計算
///////////////////////////////////////////////////////////////////////
	for (i = 0; i < yb; i++)//足し引き
	{
		for (j = 0; j < xb; j++)
		{
			ans[j][i]=a[j][i]+b[j][i];
			ans2[j][i]=a[j][i]-b[j][i];
		}
	}
	for (i = 0; i < ya; i++)//掛け算
	{
		for (j = 0; j < xb; j++)
		{
			for (k = 0; k < 100; k++)
			{
				ans3[j][i]+=a[k][i]*b[j][k];
			}
		}
	}
	

	if (xa == xb && ya == yb)
	{
		for (i = 0; i < ya; i++)
		{
			for (j = 0; j < xa; j++)
			{
				printf("%3d", ans[j][i]);
			}
		printf("\n");
		}
		printf("\n");

		for (i = 0; i < ya; i++)
		{
			for (j = 0; j < xa; j++)
			{
				printf("%3d", ans2[j][i]);
			}
			printf("\n");
		}
		printf("\n");
	}
	else
		printf("\n足し引きは計算不可\n\n");

	for (i = 0; i < ya; i++)
	{
		for (j = 0; j < xb; j++)
		{
			printf("%3d", ans3[j][i]);
		}
		printf("\n");
	}
}