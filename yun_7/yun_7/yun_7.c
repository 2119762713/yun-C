#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>



//===========================================================
//===========================================================
//===========================================================
//void test(int (*p)[5],int x,int y)
//{
//	int i = 0;
//	for (i=0;i<x;i++)
//	{
//		int j = 0;
//		for (j=0;j<y;j++)
//		{
//			printf("%d ",*(*(p+i)+j));
//		}
//		printf("\n");
//	}
//}
//void main()
//{
//	int arr[3][5] = { {1,2,3,},{2,3,4},{3,4,5}};
//	test(arr,3,5);
//}
//===========================================================
////��������ָ��
//void main()
//{
//	char* arr[10];
//	char* (*p)[10] = &arr;
//}
//===========================================================
////����ָ��
//void main()
//{
//	int* p = NULL; //p������ָ��-ָ�����ε�ָ��--���Դ�����εĵ�ַ
//	char* pc = NULL;//pa���ַ�ָ��-ָ���ַ���ָ��--���Դ���ַ��ĵ�ַ
//	int arr[10] = { 0 };//����ָ��-ָ�������ָ��--���Դ������ĵ�ַ
//	int(*p)[10] = &arr;
//	//�����p��������ָ��
//  //��ӡprintf("%d "��(*pa)[i]);
//}