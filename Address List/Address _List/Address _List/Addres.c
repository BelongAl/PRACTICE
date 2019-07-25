#define	_CRT_SECURE_NO_WARNINGS

#include "Addres.h"

void loadcontact(Contact *pCon)//������ϵ��
{
	FILE *pf1 = fopen("E:\\Addrest_list.txt", "rb");
	assert(pf1 != NULL);
	while ((fread(&pCon->per[pCon->usedSize].name, sizeof(pCon->per[pCon->usedSize].name), 1, pf1))>0)
	{
		fread(&pCon->per[pCon->usedSize].sex, sizeof(pCon->per[pCon->usedSize].sex), 1, pf1);
		fread(&pCon->per[pCon->usedSize].age, sizeof(pCon->per[pCon->usedSize].age), 1, pf1);
		fread(&pCon->per[pCon->usedSize].addr, sizeof(pCon->per[pCon->usedSize].addr), 1, pf1);
		fread(&pCon->per[pCon->usedSize].tele, sizeof(pCon->per[pCon->usedSize].tele), 1, pf1);
		(pCon -> usedSize)++;
	}
	fclose(pf1);
	pf1 = NULL;
	printf("���سɹ�\n");
}

void InitContact(Contact *pCon)//��ʼ��
{
	assert(pCon != NULL);
	pCon->usedSize = 0;
	pCon->capticty = MAX_NUMPERSON;
	pCon->per = (Personlnfo*)malloc(sizeof(Personlnfo)*pCon->capticty);
	memset(pCon->per,0,sizeof(Personlnfo)*pCon->capticty);
	void LoadContact(Contact *pCon);
}

static int CheckFULL(Contact *pCon)
{
	if (pCon->usedSize == pCon->capticty)
	{
		Personlnfo *ptr = (Personlnfo*)realloc(pCon->per,sizeof(Personlnfo)*pCon->capticty*2);//����
		if (ptr != NULL)
		{
			pCon->per = ptr;
			pCon-> capticty = 2;
			printf("���ݳɹ�\n");
			return 1;
		}
		else if (ptr == NULL)
		{
			return 0;
		}
	}
	return 1;
}

void AddContact(Contact *pCon)//����
{
	assert(pCon != NULL);
	int ret = CheckFULL(pCon);
	if (ret == 0)
	{
		printf("����ʧ��\n");
	}
	printf(" ������������");
	scanf("%s", pCon->per[pCon->usedSize].name);
	printf(" �������Ա�");
	scanf("%s", pCon->per[pCon->usedSize].sex);
	printf(" ���������䣺");
	scanf("%d", &(pCon->per[pCon->usedSize].age));
	printf(" �������ַ��");
	scanf("%s", pCon->per[pCon->usedSize].addr);
	printf(" ������绰��");
	scanf("%s", pCon->per[pCon->usedSize].tele);
	pCon->usedSize++;
}

int SearchContact(Contact *pCon)//����
{
	assert(pCon != NULL);
	int i = 0;
	if (pCon->usedSize == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return -1;
	}
	printf(" ������������");
	char name[10] = "0";
	scanf("%s", &name);
	for (i = 0; i < pCon->usedSize; i++)
	{
		if (strcmp(pCon->per[i].name, name) == 0)
		{
			return i ;
		}
	}
	printf("û�д���ϵ��");
	return -1;
}

void DelContact(Contact *pCon)//ɾ��
{
	assert(pCon != NULL);
	int index = SearchContact(pCon);
	if (index == -1)
	{
		printf("���޴���\n");
		return;
	}
	int i = 0;
	for (i = index; i < pCon->usedSize-1 ; i++)
	{
		pCon->per[i] = pCon->per[i + 1];
	}
	printf("ɾ���ɹ�\n");
}

void ShowContact(Contact *pCon)//չʾ
{
	assert(pCon != NULL);
	int i = 0;
	printf("%-10s %-10s %-10s %-15s %-15s\n", "����", "�Ա�", "����", "��ַ", "�绰");
	for (i = 0; i < pCon->usedSize ; i++)
	{
		printf("%-10s %-10s %-10d", pCon->per[i].name, pCon->per[i].sex, pCon->per[i].age);
		printf("%-15s", pCon->per[i].addr);
		printf("%-15s", pCon->per[i].tele);
		printf("\n");
	}
}

void ClearContact(Contact *pCon)//��ʽ��
{
	assert(pCon != NULL);
	pCon->usedSize = 0;
	memset(pCon->per, 0, sizeof(pCon->per));
	printf("������");
}

void SortContact(Contact *pCon)//����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pCon->usedSize - 1; i++)
	{
		for (j = 0; j < pCon->usedSize - 1 - i; j++)
		{
			if ((strcmp(pCon->per[j].name, pCon->per[j + 1].name))>0)
			{
				Personlnfo tmp;
				tmp = pCon->per[j];
				pCon->per[j] = pCon->per[j + 1];
				pCon->per[j + 1] = tmp;
			}
		}
	}
	printf("����ɹ�\n");
}

void savecontact(Contact *pCon)//����
{
	FILE *pf2 = fopen("E:\\Addrest_list.txt", "wb");
	assert(pf2 != NULL);
	while ((pCon->usedSize) --)
	{
		fwrite(&pCon->per[pCon->usedSize].name, sizeof(pCon->per[pCon->usedSize].name), 1, pf2);
		fwrite(&pCon->per[pCon->usedSize].sex, sizeof(pCon->per[pCon->usedSize].sex), 1, pf2);
		fwrite(&pCon->per[pCon->usedSize].age, sizeof(pCon->per[pCon->usedSize].age), 1, pf2);
		fwrite(&pCon->per[pCon->usedSize].addr, sizeof(pCon->per[pCon->usedSize].addr), 1, pf2);
		fwrite(&pCon->per[pCon->usedSize].tele, sizeof(pCon->per[pCon->usedSize].tele), 1, pf2);
	}
	fclose(pf2);
	pf2 = NULL;
	printf("����ɹ�\n");
}
