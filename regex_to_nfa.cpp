#include <iostream>
using namespace std;
int main()
{
   string s;
	cin >> s;
	cout << endl;
	char arr[8][8]; // 8 is the maximum number of nodes required
	for(int  i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
                arr[i][j] = '0';
	int r = 0;
	int l = s.length();
	if( l <= 3) // checking if re is a,a+, a*, a|b or a.b 
		r = 0;
	else
		r = 1;
	int flag = 0;
	for(int i = 0; i < s.length(); i++)
	switch(s[i])  //  switch case for various symbols like *,+,.,|
	{
		case '|':
			flag = 1;// means that re contained '|'
			arr[r+1][r+2] = s[r];
			arr[r+3][r+4] = s[r+2];
			arr[r][r+1] = 'E';
			arr[r][r+3] = 'E';
			arr[r+2][r+5] = 'E';
			arr[r+4][r+5] = 'E';
			break;
		case '.':
			arr[r][r+1] = s[r];
			arr[r+1][r+2] = s[r + 2];
			break;
		case '*':
			if( l == 2)// re of the type a+ or a*
			{
				arr[r][r+1] = 'E';
				arr[r+1][r+2] = s[r];
				arr[r+2][r+3] = 'E';
				arr[r+2][r+1] = 'E';
				arr[r][r+3] = 'E';
			}
			else if(flag == 1)// re had '|'
			{
				arr[0][r] = 'E';
				arr[r+5][r+6] = 'E';
				arr[r+5][r] = 'E';
				arr[0][r+6] = 'E';
				
			}
			else if( flag == 0)// re did not have '|'
			{
				arr[0][r] = 'E';
				arr[r+2][r+3] = 'E';
				arr[r+2][r] = 'E';
				arr[0][r+3] = 'E';
			}
			break;
		case '+':
			if( l == 2) // re of the type a+ or a*
			{
				arr[r][r+1] = s[r];
				arr[r+1][r] = 'E';
			}
			else if( flag == 1)// re had '|'
			{
				arr[0][r] = 'E';
				arr[r+5][r+6] = 'E';
				arr[r+5][r] = 'E';
			}
			else if( flag == 0)// re did not have '|'
			{
				arr[0][r] = 'E';
				arr[r+2][r+3] = 'E';
				arr[r+2][r] = 'E';
			}
			
			break;
	}
	if( l == 1) // if re is just 'a'
		arr[0][1] = s[0];
		cout <<"    ";
		for(int i = 0; i < 8; i++)
		cout << i<<" ";
		cout << "\n\n";
		for(int  i = 0; i < 8; i++) // printing the 2D matrix
			{cout << i<<"   ";
			for(int j = 0; j < 8; j++)
			cout << arr[i][j]<<" ";
			cout << endl;
			}
}
