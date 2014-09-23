#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string RadixNotation(unsigned int number, unsigned int radix);

int main(int argc, char** argv)
{
	if(argc < 2) return -1;
	unsigned int radix;
	sscanf(argv[1], "%u", &radix);
	if(radix <2 || radix > 36) return -1;
	for(int i=2; i<argc; i++)
	{
		unsigned int number;
		sscanf(argv[i], "%u", &number);
		cout << RadixNotation(number, radix) << endl;
	}
	return 0;
}

string RadixNotation(unsigned int number, unsigned int radix)
{
	string temp;
	int i=-1;
	while(number > 0)
	{
		int remainder = number%radix;
		if(remainder >9) remainder = remainder-10+'a';
		else		remainder = remainder +'0';
		temp += (char)remainder;
		number /= radix;
		i++;
	}
	string res;
	for(int j=i;j>=0;j--)
	{
		res += temp[j];
	}
	return res;
}
