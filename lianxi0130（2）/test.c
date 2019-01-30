//给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
//
//示例 1:
//输入 : [3, 2, 1]
//输出 : 1
//解释 : 第三大的数是 1.
//
//示例 2 :
//输入 : [1, 2]
//输出 : 2
//解释 : 第三大的数不存在, 所以返回最大的数 2 .
//
//示例 3 :
//输入 : [2, 2, 3, 1]
//输出 : 1
//解释 : 注意，要求返回第三大的数，是指第三大且唯一出现的数。
//			存在两个值为2的数，它们都排第二。

//给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如(a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。
//
//示例 1:
//
//输入 : [1, 4, 3, 2]
//
//输出 : 4
// 解释 : n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
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