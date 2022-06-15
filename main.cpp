#include <iostream>
#include "main.h"
#include "VendingMachine.h"
#include <windows.h>

using namespace std;

int main(void) {

	vendingMachine vender1("�ݶ�",700,"���̴�",800,"����",900,"ȯŸ",1100);
	vendingMachine vender2("��ũƼ", 900, "���Ƽ", 600, "���Ǵ�", 1200, "����", 800);

	vendingMachine& Selected = vender1;

	Status salestatus = Status::SELECTMACHINE; // enum class
	
	while (1) {
		if (salestatus == Status::SELECTMACHINE) {
			if (SelectVender(vender1, vender2, Selected)) {	// ���Ǳ� 1, 2 �� ����
				Selected.chkMinPrice();	// ������ Ȯ��
				salestatus = Status::MONEYINPUT;
			}		
		}
		else if (salestatus == Status::MONEYINPUT) {
			if (Selected.SetMoney(Selected.takeMoney())) {	// �� �Է¹���
				salestatus = Status::SALE;
			}
		}
		else if (salestatus == Status::SALE) {
			if (Selected.sale()) {							// �Ǹ���
				salestatus = Status::SELECTMACHINE;
			}
		}
	}
	return 0;
}



bool SelectVender(vendingMachine& vender1, vendingMachine& vender2, vendingMachine& selected) {

	while (1) {
		int select;
		system("cls");
		cout << ">> ���Ǳ⸦ ������ �ּ���" << endl;
		cout << "���Ǳ�1 : ";
		vender1.showList();
		cout << "���Ǳ�2 : ";
		vender2.showList();
		cout << "[_]\b\b";
		cin >> select;
		if (select == 1) {
			selected = vender1;
			return true;
		}
		else if (select == 2) {
			selected = vender2;
			return true;
		}
		else {				
			cout << "�ٽ� ������ �ּ���." << endl;
			Sleep(500);
			return false;
		}
	}
}