#ifndef _COL_H_
#define _COL_H_

#include <vector>
#include "container.h"

class Col : public Container {
	
	public:
	Col(std::vector<Cell*>);
	~Col();
	void notify() override;
};

#endif
