#ifndef _ROW_H_
#define _ROW_H_

#include <vector>
#include "container.h"
#include "cell.h"

class Row : public Container {
	
	public:
	Row(std::vector<Cell*>);
	~Row();
	void notify() override;
};

#endif
