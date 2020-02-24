#include"RSA.h"
#include<time.h>
#include<iostream>
#include<math.h>
#include<fstream>

void RSA::ecrept(const char* filename, const char* fileout)//�������ļ�������ļ���
{
	std::ifstream fin(filename, std::ifstream::binary);//���������ļ������� // ���ն����ƴ�
	std::ofstream fout(fileout, std::ofstream::binary);//��������ļ�������
	if (!fin.is_open())//j����ļ��Ƿ�򿪳ɹ�
	{
		perror("input file open failed");//��û�򿪣�˵������
		return;
	}

	char* buffer = new char[NUMBER];//������������ڽ��ռ���ǰ������
	DataType *bufferOut = new DataType[NUMBER];//������������ڽ��ռ��ܺ������

	while (!fin.eof())
	{
		fin.read(buffer, NUMBER);//��ȡ���ݣ����ֽ�Ϊ��λ��
		int curNum = fin.gcount();//��ȡ���һ������ȡ���������ԣ���ȡ����(�ֽ�)��С��Ϊ��λ��
		for (int i = 0; i < curNum; i++)
		{
			bufferOut[i] = ecrept((DataType)buffer[i], m_key.m_ekey, m_key.m_pkey);//�����ݣ�datatypeΪ��λ�����м���
		}
		fout.write((char*)bufferOut, curNum * sizeof(DataType));//д
	}

	delete[]buffer;
	delete[]bufferOut;

	fin.close();
	fout.close();

}

void RSA::decrept(const char* filename, const char* fileout)//���ļ����н���
{
	std::ifstream fin(filename, std::ifstream::binary);//�����������ļ�����
	std::ofstream fout(fileout, std::ofstream::binary);//����������ļ�����
	if (!fin.is_open())
	{
		perror("file open failed");
		return;
	}

	DataType *buffer = new DataType[NUMBER];//���ܻ�����(����)
	char *bufferOut = new char[NUMBER];//���������

	while (!fin.eof())
	{
		fin.read((char*)buffer, NUMBER * sizeof(DataType));//��ȡ����
		int num = fin.gcount();//��ȡ���ݵĸ��������ֽ�Ϊ��λ��
		num /= sizeof(DataType);//�ĵ��������˼���
		for (int i = 0; i < num; i++)
		{
			bufferOut[i] = decrept(buffer[i], m_key.m_dkey, m_key.m_pkey);//�����ݽ��н���
		}
		fout.write(bufferOut, num);//���
	}

	delete[]buffer;
	delete[]bufferOut;

	fout.close();
	fin.close();
}

void RSA::getKeys()
{
	DataType prime1 = getPrime();
	DataType prime2 = getPrime();
	while (prime1 == prime2)
	{
		prime2 = getPrime();
	}
	
	DataType orla = getOrla(prime1, prime2);
	m_key.m_pkey = getPkey(prime1, prime2);
	m_key.m_ekey = getEkey(orla);
	m_key.m_dkey = getDkey(orla, m_key.m_ekey);
}

DataType RSA::getPrime()//��������
{
	srand(time(nullptr));
	DataType prime;
	while (1)
	{
		prime = rand() % 100 + 2;
		if(isPrime(prime))
			break;
	}
	return prime;
}

bool RSA::isPrime(DataType data)//�ж��Ƿ�Ϊ����
{
	for (int i = 2; i <= sqrt(data); i++)
	{
		if (data%i == 0)
			return false;
	}
	return true;
}

DataType RSA::getPkey(DataType prime1, DataType prime2)//��n
{
	return prime1 * prime2;
}

DataType RSA::getOrla(DataType prime1, DataType prime2)//��ŷ��
{
	return(prime1 - 1)*(prime2 - 1);
}

DataType RSA::getEkey(DataType orla)//��e//������Կ
{
	srand(time(nullptr));
	DataType ekey;
	while (1)
	{
		ekey = rand() % orla;
		if (ekey > 1 && getGcd(ekey, orla) == 1)
			return ekey;
	}
}

DataType RSA::getDkey(DataType orla, DataType ekey)//��d//������Կ
{
	DataType dkey = orla / ekey;
	while (1)
	{
		if ((ekey*dkey) % orla == 1)
			return dkey;
		dkey++;
	}

}

DataType RSA::getGcd(DataType data1, DataType data2)//�����Լ��,ŷ������㷨
{
	int tmp;
	while (1)
	{
		tmp = data1 % data2;


		if (tmp == 0)
		{
			return data2;
		}
		data1 = data2;
		data2 = tmp;
	}
}

DataType RSA::ecrept(DataType data, DataType ekey, DataType pkey)//����(ͬ�ඨ��+��������)
{
	DataType Ai = data;
	DataType msgE = 1;

	while (ekey)
	{
		if (ekey & 1)
			msgE = (msgE*Ai) % pkey;
		ekey >>= 1;//ȡ���ڵ�λ
		Ai = (Ai*Ai) % pkey;//�����һλAi�Ĵ�С
	}
	return msgE;
}

DataType RSA::decrept(DataType data, DataType dkey, DataType pkey)//����
{
	return ecrept(data, dkey, pkey);
}
