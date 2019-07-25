#ifndef _ADDRES_H_
#define _ADDRES_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

enum Option
{
	EXIT,
	ADD,
	SEARCH,
	DEI,
	SHOW,
	CLEAR,
	SORT,
	CONTAC,
	SAVE,
	LOAD
};


#define MAX_NAME 20
#define MAX_ADDR 15
#define MAX_TELE 13
#define MAX_SEX   3

#define MAX_NUMPERSON 100


typedef struct Personlnfo
{
	char name[MAX_NAME];
	short age;
	char tele[MAX_TELE];
	char addr [MAX_ADDR];
	char sex[MAX_SEX];
}Personlnfo;

typedef struct Contact
{
	//struct Personlnfo per[MAX_NUMPERSON];
	Personlnfo *per;
	int usedSize;//被使用的个数
	int capticty;//容量
}Contact;

void InitContact(Contact *pCon);
void AddContact(Contact *pCon);
int SearchContact(Contact *pCon);
void DelContact(Contact *pCon);
void ShowContact(Contact *pCon);
void SortCantact(Contact *pCon);
static int CheckFULL(Contact *pCon);
void savecontact(Contact *pCon);
void loadcontact(Contact *pCon);


#endif 