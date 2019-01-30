//���һ����������������Ԫ�أ�����������������Ԫ��֮����ͬ����Ƹ�����Ϊ�Ȳ����С�
//
//���磬��������Ϊ�Ȳ����� :
//1, 3, 5, 7, 9
//7, 7, 7, 7
//3, -1, -5, -9
//�������в��ǵȲ����С�
//1, 1, 2, 5, 7
//
//���� A ���� N ��������������0��ʼ������ A ��һ�������黮��Ϊ����(P, Q)��P �� Q ������������ 0 <= P<Q<N ��
//��������������������������(P, Q)Ϊ�Ȳ����飺
//Ԫ�� A[P], A[p + 1], ..., A[Q - 1], A[Q] �ǵȲ�ġ����� P + 1 < Q ��
//����Ҫ�������� A ������Ϊ�Ȳ�����������������
//
//ʾ�� :
//
//A = [1, 2, 3, 4]
//
//���� : 3, A ���������ӵȲ����� : [1, 2, 3], [2, 3, 4] �Լ�����[1, 2, 3, 4]��
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

int numberOfArithmeticSlices(int* A, int ASize) {
	int dp = 0;                 //����
	int sum = 0;                //�ܵ����������
	int d1 = A[1] - A[0];       //��ֵ
	for (int i = 2; i < ASize; ++i)
	{
		int d2 = A[i] - A[i - 1];
		if (d2 == d1)
		{
			sum += (++dp);
		}

		else
		{

			dp = 0;
		}
		d1 = d2;
	}
	return sum;
}

int main()
{
	int num[] = { 2, 4, 6, 8, 10 };
	int len = sizeof(num) / sizeof(len);
	int a = numberOfArithmeticSlices(num, len);
	printf("%d\n", a);
	system("pause");
	return 0;
}