#include "VendingMachine.h"
#include <iostream>
#include <windows.h>

using namespace std;

vendingMachine::vendingMachine(const char* name1, int price1, const char* name2, int price2, const char* name3, int price3, const char* name4, int price4)
	: MyMoney(0), MinPrice(9999)
{
	drink[0].name = name1;
	drink[0].price = price1;
	drink[1].name = name2;
	drink[1].price = price2;
	drink[2].name = name3;
	drink[2].price = price3;
	drink[3].name = name4;
	drink[3].price = price4;

	for (int i = 0; i < DRINKNUM; i++) {
		drink[i].stock = MAXSTOCK;
	}
}

void vendingMachine::showList(void) {
	cout << drink[0].name << " " << drink[0].price << "," << drink[1].name << " " << drink[1].price << ","
		<< drink[2].name << " " << drink[2].price << "," << drink[3].name << " " << drink[3].price << endl;
}


void vendingMachine::chkMinPrice(void) {
	int min = drink[0].price;
	for (int i = 0; i < DRINKNUM; i++) {
		min = (drink[i].price < min) ? drink[i].price : min;
	}
	MinPrice= min;
}

int vendingMachine::GetMoney() const {
	return MyMoney;
}
bool vendingMachine::SetMoney(int money) {
	if (money < 0 || money > 10000) {
		cout << "잘못된 금액을 투입하셨습니다." << endl;
		Sleep(500);
		return false;
	}
	MyMoney = money;
	return true;
}

int vendingMachine::takeMoney(void) {
	int money;
	system("cls");
	cout << "음료수 자판기==================================" << endl;
	cout << "돈을 투입해주세요: ";
	cin >> money;
	return money;
}

bool vendingMachine::sale() {

	// 잔액이 음료수 중 최저가보다 작은 경우 바로 반환
	if (MyMoney < MinPrice) {		
		cout << endl << "음료가 나옵니다." << endl;
		cout << "반환구에서 구입하신 음료와 거스름돈을 가져가세요." << endl;
		cout << "[ 거스름돈: " << MyMoney << "원 ]" << endl;
		system("pause");
		return 1;
	}
	
	system("cls");
	cout << "[ 현재금액: " << MyMoney << "원 ]" << endl;

	int select = 0;

	for (int i = 0; i < DRINKNUM; i++) {

		printf("%d. %-10s %15d\n", i + 1, drink[i].name, drink[i].price);

	}
	cout << "----------------------------------------------" << endl << endl;
	printf("구입할 음료수를 선택해주세요: _ (음료를 꺼내려면 -1을 선택해주세요)\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	cin >> select;

	// 사용자가 -1 선택한 경우 현재 잔액 반환
	if (select == -1) {
		cout << "반환구에서 구입하신 음료와 거스름돈을 가져가세요." << endl;
		cout << "[ 거스름돈: " << MyMoney << "원 ]" << endl << endl;
		system("pause");
		return 1;
	}

	if (select <= 0 || select > DRINKNUM) {
		cout << "잘못 입력하셨습니다." << endl;
		Sleep(500);
		return 0;
	}

	// 선택한 음료의 재고가 없거나 잔액이 부족한 경우가 아니라면 현재잔액에서 선택음료 가격 차감하고 재고 감소시킴
	if (MyMoney - drink[select - 1].price < 0) {
		cout << endl;
		cout << "잔액이 부족하여 해당제품은 구입할 수 없습니다. " << endl;
	}
	else if (drink[select - 1].stock <= 0) {
		cout << endl;
		cout << "재고가 부족하여 해당제품은 구입할 수 없습니다. " << endl;
	}
	else {
		MyMoney -= drink[select - 1].price;
		drink[select - 1].stock--;		
	}

	return 0;

}

