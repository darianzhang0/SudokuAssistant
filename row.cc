#include <vector>
#include "container.h"
#include "row.h"
#include "observer.h"
#include "subject.h"
#include "cell.h"

using namespace std;

Row::Row(std::vector<Cell*> cells) : Container{cells} {
	for (int i = 0; i < 9; ++i) {
		contained[i]->attach(this);
		contained[i]->setRow(this);
	}
}

Row::~Row() { }

void Row::notify() {
	notifyObservers();
	for (int i = 0; i < 9; ++i) {
		int sum = 0;
		for (int j = 0; j < 9; ++j) {
			sum += contained[j]->canBe[i];
		}
		if (sum == 1) {
			for (int j = 0; j < 9; ++j) {
				if (contained[j]->canBe[i] == 1) {
					contained[j]->setValue(i + 1);
					break;
				}
			}
		}
	}
}
/*
void Row::notify() {
	notifyObservers();
	int empty = 0;
	int cellEmpty[9] = {0};
	for (int i = 0; i < 9; ++i) {
		if (contained[i]->getValue() == -1) {
			++empty;
			cellEmpty[i] = 1;
		}
	}
	for (int i = 0; i < 9; ++i) {
		int exists = 0;
		int emptyCell;
		for (int j = 0; j < 9; ++j) {
			if (cellEmpty[j] == 1) {
				bool is_cell_empty = true;
				for (int k = 0; k < 9; ++k) {
					if ((contained[j]->getCol(k) == i + 1) || (contained[j]->getBox(k) == i + 1)) {
						++exists;
						is_cell_empty = false;
						break;
					} 
				}
				if (is_cell_empty == true) {
					emptyCell = j;
				}
			}
		}
		if (exists == empty - 1) {
			contained[emptyCell]->setValue(i + 1);
		}
	}
}

*/







