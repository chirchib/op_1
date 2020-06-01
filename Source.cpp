#include <iostream>
using namespace std;


class Account
{
public:
	Account() : balance(0)
	{}

	Account(double _balance) : balance(_balance)
	{
		if (_balance < 0)
			balance = 0;
	}

	double getBalance()
	{
		return balance;
	}

	double credit(double _credit)
	{
		return balance += _credit;
	}

	double debit(double _debit)
	{
		return balance -= _debit;
	}

	~Account()
	{
		cout << "\nSee you next time!" << endl;
	}

private:
	double balance;
};

void menu(double _bill)
{
	Account Dmitry(_bill);
	int num;
	cout << "What woulde you like? Please enter number." << endl;
	cout << "1. Credit.\n2. Debit.\n3. Quite." << endl;
	cin >> num;
	switch (num) {
	case 1:
		double putMoney;
		cout << "How much do you want to put money into the account?" << endl;
		cin >> putMoney;
		cout << "Your current account balance is - " << Dmitry.credit(putMoney) << "$" << endl;
		menu(Dmitry.getBalance());
		break;
	case 2:
		double withdrawMoney;
		cout << "How much do you want to withdraw money from the account?" << endl;
		cin >> withdrawMoney;
		if (withdrawMoney > Dmitry.getBalance())
		{
			cout << "The requested amount exceeds the account balance." << endl;
			menu(Dmitry.getBalance());
		}
		else
			cout << "Your current account balance is - " << Dmitry.debit(withdrawMoney) << "$" << endl;
		menu(Dmitry.getBalance());
		break;
	case 3:
		break;
	default:
		cout << "Your choice is incorrect. Please enter the number again." << endl;
		menu(Dmitry.getBalance());
		break;
	}
}


int main()
{
	double bill;

	cout << "Please enter the opening balance of the account." << endl;
	cin >> bill;
	menu(bill);

	return 0;
}
