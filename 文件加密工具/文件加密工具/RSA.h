/*
	文件加密工具
	基础：1：使用欧拉函数和欧拉定理为数学基础
		  2：

	过程  1：得到两个互质的数 a b（均为质数）
		  2：令n = a * b
		  3：计算n的欧拉公式OL(n)
		  4：得到一个随机质数e( 1 < e < OL(n)),e与OL(n)互质
		  5：求出e的模反元素d ed%OL(n) == 1;
		  6：即得公钥(e,n);私钥(d,n);
*/

#pragma once

typedef long DataType;

struct Key//密钥结构
{
	DataType m_ekey;//公钥
	DataType m_dkey;//私钥
	DataType m_pkey;
};

class RSA
{
	Key m_key;
public:
	DataType ecrept(DataType data, DataType ekey, DataType pkey);//加密
	DataType decrept(DataType data, DataType dkey, DataType pkey);//解密

	Key getallkey()
	{
		return m_key;
	}

	DataType getPrime();//产生素数
	bool isPrime(DataType data);//判断是否为素数
	DataType getPkey(DataType prime1, DataType prime2);//求n
	DataType getOrla(DataType prime1, DataType prime2);//求欧拉
	DataType getEkey(DataType orla);//求e
	DataType getDkey(DataType orla, DataType ekey);//求d
	DataType getGcd(DataType data1, DataType data2);//求最大公约数

	void getKeys();
		
};