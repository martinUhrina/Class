#include<iostream>
using namespace std;

int main(){
	
int x,*p,y;
p=&x;
*p = 2;
x = *p*3;
p=&y;
*p = x/2;
cout<<x;
return 0;
}
