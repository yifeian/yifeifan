#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;

//���Ա��˳��洢�ṹ
typedef struct Sqlist_T
{
	ElemType Data[MAXSIZE];
	int length;
}Sqlist;

//��ȡһ��Ԫ��
Status GetElem(Sqlist L, int i, ElemType *e)
{
	if(L.length == 0 || i < 1 || i > L.length)
		return ERROR;
	*e = L.Data[i - 1];
	return OK;
}
//����һ��Ԫ��
Status ListInsert(Sqlist *L, int i, ElemType e)
{
	int k;
	//�ж��Ƿ�����
	if(L->length == MAXSIZE)
	{
		printf("list if full");
		return ERROR;
	}
	if(i < 1 || i > MAXSIZE+1)
	{
		return ERROR;
	}
	
	for(k = L->length - 1;k > i-1; k--)
	{
		L->Data[k+1] = L->Data[k];
	}
	L->Data[i-1] = e;
	L->length++;
	return OK;
}

//ɾ��һ��Ԫ��
Status ListDelete(Sqlist *L, int i)
{
	int k;
	if(L->length == 0 || i < 1)
		return ERROR;
	for(k=i; L->length > k; k++)
	{
		L->Data[k - 1] = L->Data[k];
	}
	L->length--;

	return OK;
}

void test_list_array(Sqlist *l)
{
	int i,j;
	int data = 8;
	l->length = 0;
	for(i = 0; i < 5; i++)
	{
		l->Data[i] = i + 1;
		l->length++;
	}
	j = ListInsert(l,3,data);


}
void main(void)
{
	Sqlist *l;
	test_list_array(l);
}




