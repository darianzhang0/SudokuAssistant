#ifndef _BOX_H_
#define _BOX_H_

#include <vector>
#include "container.h"

class Box : public Container {
	
	public:
	Box(std::vector<Cell*>);
	~Box();
	void notify() override;
};

#endif
