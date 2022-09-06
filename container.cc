#include <vector>
#include "observer.h"
#include "subject.h"
#include "cell.h"
#include "container.h"

using namespace std;

Container::Container(vector<Cell*> cells) : contained{cells} {}

Container::~Container() {} 

