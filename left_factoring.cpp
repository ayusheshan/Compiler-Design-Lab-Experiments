#include <iostream>
#include <string.h>
using namespace std;
int main()
{
char input[100];
string s[100];
string alpha = "";
string gamma = "";
string beta = "";
int i = 0;
cout << "Enter the production: ";
cin >> input;
int flag = 0;
char *l, *r, *temp;
l = strtok(input, "->");
r = strtok(NULL, "->");
temp = strtok(r, "|");
while(temp)
{
	s[i++] = temp;
	temp = strtok(NULL, "|");
}
for(int j = 1; j < i; j++) // getting gamma
{
	if(s[j][0] != s[0][0])
	{
		gamma += "|";
		gamma += s[j];
		s[j] = "";
	}
}

for(int k= 0 ; k < s[0].length(); k++)
{
char x1 = s[0][k];
if(flag == 1)
break;
for(int j = 1; j < i && s[j] != ""; j++)
{
	char x = s[j][k];
	if(x1 != x)
	{
		flag = 1;
		break;
	}
	s[j][k] = '-';
	s[0][k] = '-';
}
if(flag == 0)
alpha += x1;
}
bool epsi = true;
for(int j = 0; j < i && s[j] != ""; j++)
{
	if(beta != "")
	beta += "|";
	
	for(int k = 0; k < s[j].length(); k++)
	if(s[j][k] != '-')
	{
		beta+= s[j][k];
		epsi = false;
	}
}
if(epsi == true)
beta += 'E';
/*cout <<"GAMMA: "<< gamma << endl;
cout <<"ALPHA: "<< alpha<<endl;
cout <<"BETA: "<< beta << endl;*/
cout << "Productions after left factoring:"<<endl;
cout << l << "->" << alpha<<l<<"'"<<gamma<<endl;
cout << l << "'" <<"->"<< beta;
return 0;
}

