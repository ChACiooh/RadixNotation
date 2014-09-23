#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv)
{
	if(argc<2)	return -1;
	int operand;	char operator_;
	sscanf(argv[1], "%d", &operand);
	sscanf(argv[2], "%c", &operator_);
	if(operator_ != '+' && operator_ != '-' && operator_ != '*' && operator_ != '/')	return 0;
	for(int i=3;i<argc;i+=2)
	{
		int num;
		sscanf(argv[i], "%d", &num);
		switch(operator_)
		{
			case '+':
				operand += num;
				break;
			case '-':
				operand -= num;
				break;
			case '*':
				operand *= num;
				break;
			case '/':
				operand /= num;
				break;
		}
		sscanf(argv[i+1], "%c", &operator_);
		if(operator_ == '=')	break;
	}
	cout << operand << endl;
	return 0;
}
