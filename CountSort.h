#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
void CountSort(int *a, int n)
{
	int max = a[0];
	int min = a[0];
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int range = max - min+1;
	int *counta =(int*) malloc(sizeof(int)*range);
	memset(counta, 0, sizeof(int)*range);
	//统计个数（将原数组的值作为辅助数组的下标，C[0]=2表示A中的元素为0的有两个，C[1]=0,表示A数组中没有值为1的元素）
	for (i = 0;i < n;++i)
	{
		counta[a[i]-min]++;//a[i]-min是将数组访问范围（数值范围）控制在0-range内
	}
	//排序
	int index = 0;
	for (i = 0;i < range;++i) //遍历辅助数组
	{
		while (counta[i]--) //某个数出现次数
		{
			a[index++] = i + min; //将下标处的数对应回原数组,i是数值，+min对应上面的a[i]-min，将数值还原
		}
	}
	free(counta);
}