#include <iostream>
using namespace std;


class Account
{
public:
	Account() : balance(0)
	{}

	Account(double _balance) : balance(_balance)
	{}

	double getBalance()
	{
		return balance;
	}

	double credit(double _credit)
	{
		balance += _credit;
		return balance;
	}

	void debit();

	void menu();

	~Account();

private:
	double balance;
	double commision;
};

void  menu(double _bill) 
{
	Account Dmitry(_bill);
	char num;
	cout << "What woulde you like? Please enter number." << endl;
	cout << "1. Credit.\n2. Debit.\n3. Quite." << endl;
	cin >> num;
	switch (num) {
	case 1:
		int putMoney;
		cout << "How much do you want to put money into the account?" << endl;
		cin >> putMoney;
		cout << "Your current account balance is - " << credit(putMoney) << "$" << endl;
		menu();
	case 2:
		double withdrawMoney;
		cout << "How much do you want to withdraw money from the account?" << endl;
		cin >> withdrawMoney;
		if (withdrawMoney > getBalance())
		{
			cout << "The requested amount exceeds the account balance." << endl;
			menu();
		}
		else 
			cout << "Your current account balance is - " << debit(withdrawMoney) << "$" << endl;
		return;
	case 3:
		return;
	default:
		cout << "Your choice is incorrect. Please enter the number again." << endl;
		menu();
	}
}


int main() {
	double bill;

	cout << "Please enter the opening balance of the account." << endl;
	cin >> bill;
	menu(bill);

	return 0;
}


//Account::Account(double openingBalance) {
//	if (openingBalance >= 0) {
//		Balance = openingBalance;
//		cout << "Your the opening balance is - " << openingBalance << "$" << endl;
//	}
//	else {
//		cout << "Opening balance was invalid." << endl;
//		Balance = 0;
//	}
//	menu();
//}
//
//void Account::getBalance() {
//	cout << "Your current account balance is - " << Balance << "$" << endl;
//}
//
//void Account::credit() {
//	int putMoney;
//	cout << "How much do you want to put money into the account?" << endl;
//	cin >> putMoney;
//	Balance += putMoney;
//	getBalance();
//	menu();
//	return;
//}
//
//void Account::debit() {
//	double withdrawMoney;
//	cout << "How much do you want to withdraw money from the account?" << endl;
//	cin >> withdrawMoney;
//	if (withdrawMoney > Balance)
//		cout << "The requested amount exceeds the account balance." << endl;
//	else Balance -= withdrawMoney;
//	getBalance();
//	menu();
//	return;
//}
//
//
//
//Account::~Account() {
//	cout << "\nSee you next time!" << endl;
//}
//
//Account_Sberbank::Account_Sberbank(double openBalance) :Account(openBalance)
//{
//	if (openBalance >= 0) {
//		balance = openBalance;
//		cout << "Your the opening balance is - " << openBalance << "$" << endl;
//	}
//	else {
//		cout << "Opening balance was invalid." << endl;
//		balance = 0;
//	}
//}
//
//void Account_Sberbank::deposit()
//{
//	double dep;
//	cout << "How much do you want to make deposit?" << endl;
//	cin >> dep;
//	if (dep > balance)
//		cout << "You have insufficient funds. Try again." << endl;
//	else
//	{
//		balance -= dep;
//		Deposit = dep;
//		getBalance();
//		getDeposit();
//	}
//	menuSber();
//	return;
//}
//
//void Account_Sberbank::getDeposit()
//{
//	cout << "Your deposit will be through: "
//		<< "\nFirst year " << Deposit * 1, 1
//		<< "\nsSecond year " << Deposit * 1, 1 ^ 2
//		<< "\nThrird year " << Deposit * 1, 1 ^ 3
//		<< "\nFourth year " << Deposit * 1, 1 ^ 4
//		<< "\nFith year " << Deposit * 1, 1 ^ 5 << endl;
//}
//
//void Account_Sberbank::menuSber()
//{
//	char num;
//	cout << "Woulde you like? Please enter number." << endl;
//	cout << "1. Credit.\n2. Debit.\n3. Deposit.\n0. Quite." << endl;
//	cin >> num;
//	switch (num) {
//	case 1:
//		credit();
//		return;
//	case 2:
//		debit();
//		return;
//	case 3:
//		deposit();
//		return;
//	case 0:
//		return;
//	default:
//		cout << "Your choice is incorrect. Please enter the number again." << endl;
//		menuSber();
//	}
//}