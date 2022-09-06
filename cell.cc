#include <iostream>
#include <vector>
#include <string>

#include "container.h"
#include "cell.h"
#include "observer.h"
#include "subject.h"
using namespace std;

/*
class Cell : public Observer, public Subject {
    int value;
    Container *row;
    Container *col;
    Container *box;
    // You may add any fields or private helpers you
    // see fit, so long as you are still implementing
    // the observer pattern.
  public:
    Cell();
    virtual void notify() override;
    // Suggested helper function, sets the value of this cell
    // and notifies observers.
    void setValue(int);
    // Suggested helper function, returns the value of this
    // cell.
    int getValue();
    // You may add any public helpers/getters/setters you
    // see fit, so long as you are still implementing
    // the observer pattern.
    void setRow(Container *);
    void setCol(Container *);
    void setBox(Container *);
}; */

Cell::Cell() : value{-1} {}

void Cell::notify() {
/*	int includedNums[9] = {0};
	int n;
	for (int i = 0; i < 9; ++i) {
		n = row->contained[i]->getValue();
		if (n != -1) {
			includedNums[n - 1] = 1;
		}
		n = col->contained[i]->getValue();
		if (n != -1) {
                        includedNums[n - 1] = 1;
                }
		n = box->contained[i]->getValue();
                if (n != -1) {
                        includedNums[n - 1] = 1;
                }   
		cerr << " included num check";
	}
	int sum = 0;
	for (int i = 0; i < 9; ++i) {
		sum += includedNums[i];
	}
	if (sum == 8) {
		int num;
		for (int i = 0; i < 9; ++i) {
			if (includedNums[i] == 0) {
				num = i + 1;
				break;
			}
		}
		setValue(num);
	} */
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
	//	value = num;
// start	for (int i = 0; i < 9; ++i) {
/*			row->contained[i]->canBe[value - 1] = 0;
			col->contained[i]->canBe[value - 1] = 0;
			box->contained[i]->canBe[value - 1] = 0;
			canBe[i] = 0;
		}
		row->notifyObservers();
		col->notifyObservers();
		box->notifyObservers();
	
		for (int i = 0; i < 9; ++i) {
			row->contained[i]->notifyObservers();
			col->contained[i]->notifyObservers();
			box->contained[i]->notifyObservers();
// end		}*/
//		notifyObservers();
//		notify();
	}
}

void Cell::setValue(int i) {
	value = i;
	
//	int counter = 0;
//	if (value == 2) {
//		++counter;
//	}	
//	if (i != -1) {
	for (int i = 0; i < 9; ++i) {
		canBe[i] = 0;
	}

	int changedRow[9];
	int changedCol[9];
	int changedBox[9];
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
//	}
//	row->notifyObservers();
//	col->notifyObservers();
//	box->notifyObservers();
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
//	notify();
//	cout << counter << endl;
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
