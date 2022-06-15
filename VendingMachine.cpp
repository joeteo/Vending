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
		cout << "�߸��� �ݾ��� �����ϼ̽��ϴ�." << endl;
		Sleep(500);
		return false;
	}
	MyMoney = money;
	return true;
}

int vendingMachine::takeMoney(void) {
	int money;
	system("cls");
	cout << "����� ���Ǳ�==================================" << endl;
	cout << "���� �������ּ���: ";
	cin >> money;
	return money;
}

bool vendingMachine::sale() {

	// �ܾ��� ����� �� ���������� ���� ��� �ٷ� ��ȯ
	if (MyMoney < MinPrice) {		
		cout << endl << "���ᰡ ���ɴϴ�." << endl;
		cout << "��ȯ������ �����Ͻ� ����� �Ž������� ����������." << endl;
		cout << "[ �Ž�����: " << MyMoney << "�� ]" << endl;
		system("pause");
		return 1;
	}
	
	system("cls");
	cout << "[ ����ݾ�: " << MyMoney << "�� ]" << endl;

	int select = 0;

	for (int i = 0; i < DRINKNUM; i++) {

		printf("%d. %-10s %15d\n", i + 1, drink[i].name, drink[i].price);

	}
	cout << "----------------------------------------------" << endl << endl;
	printf("������ ������� �������ּ���: _ (���Ḧ �������� -1�� �������ּ���)\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
	cin >> select;

	// ����ڰ� -1 ������ ��� ���� �ܾ� ��ȯ
	if (select == -1) {
		cout << "��ȯ������ �����Ͻ� ����� �Ž������� ����������." << endl;
		cout << "[ �Ž�����: " << MyMoney << "�� ]" << endl << endl;
		system("pause");
		return 1;
	}

	if (select <= 0 || select > DRINKNUM) {
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		Sleep(500);
		return 0;
	}

	// ������ ������ ��� ���ų� �ܾ��� ������ ��찡 �ƴ϶�� �����ܾ׿��� �������� ���� �����ϰ� ��� ���ҽ�Ŵ
	if (MyMoney - drink[select - 1].price < 0) {
		cout << endl;
		cout << "�ܾ��� �����Ͽ� �ش���ǰ�� ������ �� �����ϴ�. " << endl;
	}
	else if (drink[select - 1].stock <= 0) {
		cout << endl;
		cout << "��� �����Ͽ� �ش���ǰ�� ������ �� �����ϴ�. " << endl;
	}
	else {
		MyMoney -= drink[select - 1].price;
		drink[select - 1].stock--;		
	}

	return 0;

}

