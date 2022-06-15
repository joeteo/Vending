#ifndef __MAIN_H__
#define __MAIN_H__

#include "VendingMachine.h"

enum class Status {
	SELECTMACHINE,
	MONEYINPUT,
	SALE,
};

bool SelectVender(vendingMachine& vender1, vendingMachine& vender2, vendingMachine& selected);

#endif
