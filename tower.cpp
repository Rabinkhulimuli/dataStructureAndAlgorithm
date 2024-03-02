#include <iostream>
using namespace std;

void tower(int num,char from,char to,char aux){
	if (num==0){
		return;
	}
	cout<<"begening"<<endl;
	tower(num-1,from,aux,to);
	cout<<"moving "<<num<<" from "<<from<<" to "<<to<<endl;
	cout<<"new Line"<<endl;
	tower(num-1,aux,to,from);
}
int fe(int num){
	if (num <=1){
		return num;
	}
	return fe(num-1)+fe(num-2);
}
int facto(int n){
	if (n <=1){
		return n;
	}
	return facto(n-1)*n;
}
int gcd(int a,int b){
	if (b==0){
		return a;
	}
	return gcd(b,a%b);
}
int main(){
	int ch,num1,num2;
	char ch1,ch2,ch3;
	while(1){
		cout<<"choose the option below"<<endl;
		cout<<"1.GCD 2.Factorial 3.Febonacchi 4.tower of hanoi 5.Quit"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"enter two number to find GCD"<<endl;
				cin>>num1>>num2;
				gcd(num1,num2);
				break;
			case 2:
				cout<<"enter the number to find factorial"<<endl;
				cin>>num1;
				facto(num1);
				break;
			case 3:
				cout<<"enter a number to find febonacchi"<<endl;
				cin>>num1;
				fe(num1);
				break;
			case 4:
				cout<<"enter a number then 3 character "<<endl;
				cin>>num1>>ch1>>ch2>>ch3;
				tower(num1,ch1,ch2,ch3);
				break;
			case 5:
				return 0;
				break;
			default:
				cout<<"enter a valid choice"<<endl;
				break;
		}

	}
	return 0;
}