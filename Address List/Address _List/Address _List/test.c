#define	_CRT_SECURE_NO_WARNINGS

#include "Addres.h"



void menu()
{
	printf("****** 1.add   ******** 2.search *****\n");
	printf("****** 3.dei   ******** 4.show   *****\n");
	printf("****** 5.clear ******** 6.sort   *****\n");
	printf("****** 0.exit  ******** 8.save   *****\n");
	printf("*********************** 9.load   *****\n");
}
void Start()
{
	int input = 0;
	int ret = 0;
	int i = 0;
	//初始化通讯录 数组 usedSize
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请输入操作数");
		scanf("%d", &input);
		switch (input)
		{
			case ADD:
				AddContact(&con);
				break;
			case SEARCH:
				ret = SearchContact(&con);
				if (ret != -1)
				{
					printf("%-10s %-10s %-10s %-15s %-15s\n", "姓名", "性别", "年龄", "地址", "电话");
					printf("%-10s %-10s %-10d %-15s %-15s", con.per[ret].name, con.per[ret].sex, con.per[ret].age, con.per[ret].addr, con.per[ret].tele);
					printf("\n");
				}
				break;
			case DEI:
				DelContact(&con);
				break;
			case SHOW:
				ShowContact(&con);
				break;
			case CLEAR:
				ClearContact(&con);
				break;
			case SORT:
				SortContact(&con);
				break;
			case SAVE:
				savecontact(&con);
				break;
			case LOAD:
				loadcontact(&con);
				break;
		}
	} while (input);
}
int main()
{
	Start();
	system("pause");
	return 0;
}






