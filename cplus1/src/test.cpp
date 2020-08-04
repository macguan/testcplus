#include <iostream>
using namespace std;
int add(int num1, int num2);
int main(){

int x, y, z;


std::cout<<"Hello World"<<std::endl;

std::cout<<"Please enter a first integer:\n";
std::cin>>x;
std::cout<<"Please enter a second integer:\n";
std::cin>>y;
//x = 1;
//y = 2;
z = add(x,y);
std::cout<<"result is:\n";
cout << z << endl;
}
int add(int num1, int num2){
	return num1+num2;
}
