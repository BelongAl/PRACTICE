#include"RSA.h"
#include<iostream>

int main()
{
	RSA rs;
	rs.getKeys();
	Key key = rs.getallkey();
	DataType socurcenumber = 8;
	DataType edata = rs.ecrept(socurcenumber, key.m_ekey, key.m_pkey);
	DataType ddata = rs.decrept(edata, key.m_dkey, key.m_pkey);

	std::cout << socurcenumber << " " << edata << " " << ddata << std::endl;

	system("pause");
	return 0;
}