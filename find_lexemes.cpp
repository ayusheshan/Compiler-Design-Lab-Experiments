#include <iostream>
#include <fstream>
using namespace std;
bool not_repeated(string arr[], int n, string x)
{
	for(int i = 0; i < n; i++)
		if( arr[i] == x)
			return false;
	return true;
}
int main()
{
ifstream file;
file.open("C:\\Users\\Ayush\\Desktop\\test.txt");
string data;
string op[100];
int o = 0;
string key[100];
int k = 0;
string var[100];
int v = 0;
string cons[100];
int c = 0;

    std::string line;
    while (getline(file, line)) {
        data = line.c_str();
        data += ' ';
        string x = "";
        string keywords[16] = {"main","void","return","if","printf","scanf","int","float", "else","for","switch","break","continue","while"
		, "do","case"};
        
        for(int i = 0; i < data.length(); i++)
        {
        	
        	char ch = data[i];
        	if(ch == ' '|| ch == ',' || ch == '(' || ch == ')' || ch == ';' || ch == '&'|| ch == '|'|| ch == '{'|| ch=='}' || ch==':')
        	{
        		if( x.length() == 0)
        			continue;
        		int flag = 0;
        		for(int i = 0; i < 16; i++)
        		if( x == keywords[i])
        			{
        				if(not_repeated(key,k,x))
							key[k++] = x;
						flag = 1;
						x = "";
						break;
					}
				if ( flag == 1)
					continue;
				if(x[0]=='+'|| x[0] == '-'|| x[0] == '*' || x[0] == '/' || x[0] == '='|| x[0] =='<'|| x[0] =='>')
					{
						if(not_repeated(op,o,x))
							op[o++]= x;
						x = "";
						continue;
					}
				for(int i = 0; i < x.length(); i++)
					if( !isdigit(x[i]) )
						flag = 1;
				if( flag == 1 && x[0] != '"' && not_repeated(var,v,x) && !isdigit(x[0]) && x[0] != '_')
					var[v++] = x;
				else if(flag == 0 && x[0] != '"' && not_repeated(cons,c,x))
					cons[c++] = x;
        		x = "";
			}
			else
			{
			x += ch;
			}
		}
    }

file.close();
cout << "Keywords are: " << endl;
for(int i = 0; i < k; i++)
	cout << key[i] << " ";
	
cout << "\n\n" << "Operators are: "<< endl;
for(int i = 0; i < o; i++)
	cout << op[i] << " ";
	
cout << "\n\n" << "Variables are: "<< endl;
for(int i = 0; i < v; i++)
	cout << var[i] << " ";
	
cout << "\n\n" << "Constants are: " << endl;
for(int i = 0; i < c; i++)
	cout << cons[i] << " ";
	
return 0;
}
