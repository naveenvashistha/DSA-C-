#include<bits/stdc++.h>
using namespace std;

class bank{
	float balance;
	float rate;
	static int count;
	public:
	bank(){
		cout << "Balance: ";
		cin >> balance;
		cout << "Rate: ";
		cin >> rate;
		count++;
	}
	~bank(){
		cout << "Object destroyed" << endl;
		count--;
	}
	void deposit(int x){
		balance += x;
	}
	void withdrawal(int x){
		if(balance - x < 0){
			cout << "Not enough balance" << endl;
			return;
		}
		balance -= x;
	}
	void compoundInt(float time){
		float amount = balance * pow((1 + rate / 100), time);
		cout << "Compund interest: " << amount - balance << endl;
		balance = amount;
	}
	void display(){
		cout << balance << endl;
	}
};

int bank::count = 0;

int main()
{
	int ch;
	bank customer;
	while(true){
		cout << "1. deposit" << endl;
		cout << "2. withdrawal" << endl;
		cout << "3. compound Interest" << endl;
		cout << "4. display" << endl;
				
		cout << "Enter choice: ";
		cin >> ch;
		
		switch(ch){
			case 1:
			int b;
			cout << "Enter balance: ";
			cin >> b;
			customer.deposit(b);
			break;
			
			case 2:
			int bal;
			cout << "enter balance: ";
			cin >> bal;
			customer.withdrawal(bal);
			break;
			
			case 3:
			float time;
			cout << "enter time: ";
			cin >> time;
			customer.compoundInt(time);
			break;
			
			case 4:
			customer.display();
			break;
			
			default:
			cout << "wrong choice" << endl;
			return -1;
		}		
	}
}
