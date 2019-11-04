#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, const char* argv[])//main函数可以递归  执行方法 内容
{
	if (argc != 3)
	{
		return -1;
	}
	ifstream ifs(argv[1], ifstream::binary);
	ofstream ofs(argv[2], ofstream::binary);

	char c[1024];

	while (!ifs.eof())
	{
		ifs.read(c,1024);
		ofs.write(c,1024);
	}

	ifs.close();
	ofs.close();
	system("pause");
	return 0;
}