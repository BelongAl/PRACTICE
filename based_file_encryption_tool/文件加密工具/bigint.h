#pragma once
#include<string>
#include<utility>//pair的头文件

class BigInt
{
	std::string m_number;

public:
	BigInt(const std::string&num)
	{

	}
	BigInt(const int num)
	{

	}
	BigInt() = default;

	std::string add(std::string num1, std::string num2);//+
	std::string sub(std::string num1, std::string num2);//-
	std::string mul(std::string num1, std::string num2);//*
	std::pair<std::string, std::string> dev(std::string num1, std::string num2);///

};