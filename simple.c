
	int diffofsums(int f, int g, int h, int i,int j)
	{
		int result;

		result = (f + g) - (h + i+j);

		return result;
	}

	int main(void)
	{
		int y;

		y = diffofsums(2, 3, 4, 5,6);

		return 0;
	}