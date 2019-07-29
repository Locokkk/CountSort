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
	//ͳ�Ƹ�������ԭ�����ֵ��Ϊ����������±꣬C[0]=2��ʾA�е�Ԫ��Ϊ0����������C[1]=0,��ʾA������û��ֵΪ1��Ԫ�أ�
	for (i = 0;i < n;++i)
	{
		counta[a[i]-min]++;//a[i]-min�ǽ�������ʷ�Χ����ֵ��Χ��������0-range��
	}
	//����
	int index = 0;
	for (i = 0;i < range;++i) //������������
	{
		while (counta[i]--) //ĳ�������ִ���
		{
			a[index++] = i + min; //���±괦������Ӧ��ԭ����,i����ֵ��+min��Ӧ�����a[i]-min������ֵ��ԭ
		}
	}
	free(counta);
}