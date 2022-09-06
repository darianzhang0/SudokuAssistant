#include <vector>
#include "container.h"
#include "box.h"
#include "observer.h"
#include "subject.h"
#include "cell.h"

using namespace std;

Box::Box(std::vector<Cell*> cells) : Container{cells} {
	for (int i = 0; i < 9; ++i) {
		contained[i]->attach(this);
		contained[i]->setBox(this);
	}
}

Box::~Box() { } // ?

void Box::notify() {
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



