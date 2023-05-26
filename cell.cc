#include <iostream>
#include <vector>
#include <string>

#include "container.h"
#include "cell.h"
#include "observer.h"
#include "subject.h"
using namespace std;

Cell::Cell() : value{-1} {}

void Cell::notify() {
	int cannotBe = 0;
	for (int i = 0; i < 9; ++i) {
		if (canBe[i] == 0) {
			++cannotBe;
		}
	}
	if (cannotBe == 8) {
		int num;
		for (int i = 0; i < 9; ++i) {
			if (canBe[i] == 1) {
				num = i + 1;
				break;
			}
		}
		setValue(num);	
	}
}

void Cell::setValue(int n) {
	value = n;
	for (int i = 0; i < 9; ++i) {
		canBe[i] = 0;
	}

	int changedRow[9] = {0};
	int changedCol[9] = {0};
	int changedBox[9] = {0};
	for (int i = 0; i < 9; ++i) {
		if (row->contained[i]->canBe[value - 1] == 1) {
			row->contained[i]->canBe[value - 1] = 0;
			changedRow[i] = 1;
		}
		if (col->contained[i]->canBe[value - 1] == 1) {
                	col->contained[i]->canBe[value - 1] = 0;
			changedCol[i] = 1;
		}
		if (box->contained[i]->canBe[value - 1] == 1) {
                	box->contained[i]->canBe[value - 1] = 0;
			changedBox[i] = 1;
		}
	}
	for (int i = 0; i < 9; ++i) {
		if (changedRow[i] == 1) {
			row->contained[i]->notifyObservers();
		}
		if (changedCol[i] == 1) {
			col->contained[i]->notifyObservers();
		}
		if (changedBox[i] == 1) {
			box->contained[i]->notifyObservers();
		}
	}
//	notifyObservers();
}

int Cell::getValue() {
	return value;
}

void Cell::setRow(Container *r) {
	row = r;
	row->attach(this);
}

void Cell::setCol(Container *c) {
	col = c;
	col->attach(this);
}

void Cell::setBox(Container *b) {
	box = b;
	box->attach(this);
}

int Cell::getCol(int i) {
	return col->contained[i]->getValue();
}

int Cell::getRow(int i) {
	return row->contained[i]->getValue();
}

int Cell::getBox(int i) {
	return box->contained[i]->getValue();
}
