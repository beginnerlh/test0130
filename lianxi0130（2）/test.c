//����һ���ǿ����飬���ش������е������������������ڣ��򷵻���������������Ҫ���㷨ʱ�临�Ӷȱ�����O(n)��
//
//ʾ�� 1:
//���� : [3, 2, 1]
//��� : 1
//���� : ����������� 1.
//
//ʾ�� 2 :
//���� : [1, 2]
//��� : 2
//���� : ���������������, ���Է��������� 2 .
//
//ʾ�� 3 :
//���� : [2, 2, 3, 1]
//��� : 1
//���� : ע�⣬Ҫ�󷵻ص������������ָ��������Ψһ���ֵ�����
//			��������ֵΪ2���������Ƕ��ŵڶ���

//��������Ϊ 2n ������, ��������ǽ���Щ���ֳ� n ��, ����(a1, b1), (a2, b2), ..., (an, bn) ��ʹ�ô�1 �� n �� min(ai, bi) �ܺ����
//
//ʾ�� 1:
//
//���� : [1, 4, 3, 2]
//
//��� : 4
// ���� : n ���� 2, ����ܺ�Ϊ 4 = min(1, 2) + min(3, 4).
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
int thirdMax(int* nums, int numsSize) {
	long first = LONG_MIN;
	long second = LONG_MIN;
	long third = LONG_MIN;
	int i = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > first)
		{
			first = nums[i];
		}
	}
	
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > second && nums[i] != first)
		{
			second = nums[i];
		}
	}

	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] > third && nums[i] != first && nums[i] != second)
		{
			third = nums[i];
		}
	}
	
	if (third != LONG_MIN)
	{
		return third;
	}
	  return first;
}

int arrayPairSum(int* nums, int numsSize) {
	int sum = 0;
	for (int i = 0; i < numsSize - 1; i++){
		for (int j = 0; j < numsSize - i - 1; j++){
			if (nums[j] > nums[j + 1]){
				int t = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = t;
			}
		}
	}
	for (int k = 0; k < numsSize; k += 2){
		sum += nums[k];
	}
	return sum;
}

int main()
{
	int num[] = { 4, 2, 3, 1 };
	int len = sizeof(num) / sizeof(int);
	//int a = thirdMax(num, len);
	int a = arrayPairSum(num, len);
	printf("%d\n", a);
	system("pause");
	return 0;
}