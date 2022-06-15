#pragma once

#define DRINKNUM 4
#define MAXSTOCK 4

struct _DRINK {
	const char* name;
	int price;
	int stock;
};

class vendingMachine
{
private:
	_DRINK drink[DRINKNUM];
	int MyMoney;
	int MinPrice;

public:
	vendingMachine(const char* name1, int price1, const char* name2, int price2, const char* name3, int price3, const char* name4, int price4);
	void showList();
	void chkMinPrice();
	int GetMoney() const;
	bool SetMoney(int money);
	int takeMoney();
	bool sale();

};



