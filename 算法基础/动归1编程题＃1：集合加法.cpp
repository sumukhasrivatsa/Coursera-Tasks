//#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;

int pairofs(int num, int *arr, int len, int sum)//ĳ�����ֺ�ĳһ������Ԫ�� �ܹ���Եĸ���
{
	int count = 0;
	for (; len > 0; len--)
	{
		if (arr[len - 1] + num == sum)
			count++;
	}
	return count;
}



int main()
{
	int n;
	cin >> n;

	for (; n > 0; n--) //n������
	{
		int sum, alen, blen, A[10000], B[10000], res = 0;
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		cin >> sum;//�������ݵ�һ��
		cin >> alen;
		for (int i = 0; i < alen; i++)
		{
			cin >> A[i];
		}
		cin >> blen;//�������ݵ�����
		for (int i = 0; i < blen; i++)
		{
			cin >> B[i];
		}

		for (int i = 0; i < alen; i++)//����Ϊ���ˡ��͵���
		{
			res += pairofs(A[i], B, blen, sum);
		}
		cout << res << endl;
	}

	//	system("pause");
	return 0;
}