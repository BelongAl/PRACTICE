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

void biginttest1()
{
	BigInt bi;
	std::string num1("12345");
	std::string num2("92845");
	std::cout << 12345 + 92845 << std::endl;
	std::cout << bi.add("12345", "92845") << std::endl;

	std::cout << 10001 - 9999 << std::endl;
	std::cout << bi.sub("10001", "9999") << std::endl;

	std::cout << 999 * 999 << std::endl;
	std::cout << bi.mul("999", "999") << std::endl;

}

int main()
{
	biginttest1();

	system("pause");
	return 0;
}