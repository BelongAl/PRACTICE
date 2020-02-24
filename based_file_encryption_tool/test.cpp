#include"RSA.h"
#include<iostream>
#include<fstream>
#include"bigint.h"


/*void RSAtest1()
{
	RSA rs;
	rs.getKeys();
	Key key = rs.getallkey();
	DataType socurcenumber = 16;
	DataType edata = rs.ecrept(socurcenumber, key.m_ekey, key.m_pkey);
	DataType ddata = rs.decrept(edata, key.m_dkey, key.m_pkey);

	std::cout << socurcenumber << " " << edata << " " << ddata << std::endl;
}

void RSAtest2()
{
	RSA rs;

	rs.ecrept("test.txt", "ecrept.txt");//¼ÓÃÜ
	rs.decrept("ecrept.txt", "decrept.txt");//½âÃÜ

}*/

using namespace std;

void biginttest1()
{
	BigInt b1("12345");
	BigInt b2("25");

	cout << "************* + *************" << endl;
	cout << "b1:" << b1 << "+ b2:" << b2 <<endl;
	cout << 12345 + 25 << endl;
	cout << b1 + b2 << endl;

	cout << "************* - *************" << endl;
	cout << "b1:" << b1 << "- b2:" << b2 << endl;
	cout << 12345 - 25 << endl;
	cout << b1 - b2 << endl;

	cout << "************* * *************" << endl;
	cout << "b1:" << b1 << "* b2:" << b2 << endl;
	cout << 12345 * 25 << endl;
	cout << b1 * b2 << endl;

	cout << "************* / *************" << endl;
	cout << "b1:" << b1 << "/ b2:" << b2 << endl;
	cout << 12345 / 25 << endl;
	cout << b1 / b2 << endl;

	cout << "************* % *************" << endl;
	cout << "b1:" << b1 << "% b2:" << b2 << endl;
	cout << 12345 % 25 << endl;
	cout << b1 % b2 << endl;
}


int main()
{
	biginttest1();

	system("pause");
	return 0;
}