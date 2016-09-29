#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

short N;
short paint[17][17];
short wall[17][17];
bool Paint;
bool canPaint()//���ݵ�һ�е�wall��paint���Ƴ������еĽ����Ȼ�����һ���Ƿ����Ҫ��
{
	for (int i = 2; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			paint[i][j] = (wall[i - 1][j] + paint[i - 1][j] + paint[i - 1][j - 1] + paint[i - 1][j + 1] + paint[i - 2][j] + 1) % 2;
		}
	for (int j = 1; j <= N; j++) //��n��
		if ((wall[N][j] + paint[N][j] + paint[N][j - 1] + paint[N][j + 1] + paint[N - 1][j]) % 2 == 0)
			return false;
	Paint = true;
	return true;
}
int numPaint()//ͳ��ǽ��paint�ĸ���
{
	int num = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (paint[i][j] == 1) num++;
	return num;
}


int main() {
	int testNum = 0;
	cin >> testNum;
	while (testNum-- > 0)
	{
		Paint = false;
		memset(paint, 0, sizeof(paint));
		memset(wall, 0, sizeof(wall));
		cin >> N;

		char temp;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
			{
				cin >> temp;
				if (temp == 'w') wall[i][j] = 0;
				else wall[i][j] = 1;
			}
		//��ʼ��wall��paint
		int min = 1000000;
		while (paint[1][N + 1] != 1)
		{
			if (canPaint() == true && numPaint() <= min)
				min = numPaint();
			paint[1][1]++;
			int j = 1;
			while (paint[1][j] > 1)
			{
				paint[1][j] = 0;
				j++;
				paint[1][j]++;
			}
		}
		if (Paint == false) cout << "inf" << endl;
		else cout << min << endl;
	}

	return 0;
}


