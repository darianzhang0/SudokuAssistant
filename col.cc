#include <vector>
#include "container.h"
#include "col.h"
#include "observer.h"
#include "subject.h"
#include "cell.h"

using namespace std;

Col::Col(std::vector<Cell*> cells) : Container{cells} {
	for (int i = 0; i < 9; ++i) {
		contained[i]->attach(this);
		contained[i]->setCol(this);
	}
}

Col::~Col() { }

void Col::notify() {
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

