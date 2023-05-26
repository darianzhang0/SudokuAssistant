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
	for (int i = 0; i < 9; ++i) {
		int sum = 0;
		for (int j = 0; j < 9; ++j) {
			sum += contained[j]->canBe[i];
		}
		if (sum == 1) {
			for (int j = 0; j < 9; ++j) {
				if (contained[j]->canBe[i] == 1) {
					contained[j]->setValue(i + 1);
					notifyObservers();
					break;
				}
			}
		}
	}
}
