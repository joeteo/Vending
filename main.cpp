#include <iostream>
#include "main.h"
#include "VendingMachine.h"
#include <windows.h>

using namespace std;

int main(void) {

	vendingMachine vender1("콜라",700,"사이다",800,"맥콜",900,"환타",1100);
	vendingMachine vender2("밀크티", 900, "우롱티", 600, "솔의눈", 1200, "우유", 800);

	vendingMachine& Selected = vender1;

	Status salestatus = Status::SELECTMACHINE; // enum class
	
	while (1) {
		if (salestatus == Status::SELECTMACHINE) {
			if (SelectVender(vender1, vender2, Selected)) {	// 자판기 1, 2 중 선택
				Selected.chkMinPrice();	// 최저가 확인
				salestatus = Status::MONEYINPUT;
			}		
		}
		else if (salestatus == Status::MONEYINPUT) {
			if (Selected.SetMoney(Selected.takeMoney())) {	// 돈 입력받음
				salestatus = Status::SALE;
			}
		}
		else if (salestatus == Status::SALE) {
			if (Selected.sale()) {							// 판매중
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
		cout << ">> 자판기를 선택해 주세요" << endl;
		cout << "자판기1 : ";
		vender1.showList();
		cout << "자판기2 : ";
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
			cout << "다시 선택해 주세요." << endl;
			Sleep(500);
			return false;
		}
	}
}