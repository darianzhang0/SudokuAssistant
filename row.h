#ifndef _ROW_H_
#define _ROW_H_

#include <vector>
#include "container.h"
#include "cell.h"

/*
class Container : public Subject, public Observer {
    std::vector<Cell*> contained;
  public:
    virtual void notify() override;
    Container(std::vector<Cell*>);
    virtual ~Container();
    // You may add additional helper functions, public or private.
    // But you must ensure you are still implementing the observer pattern.
};

class Comic: public Book {
  std::string hero;
 public:
  Comic(const std::string &title, const std::string &author, int numPages, const std::string &hero);
  bool isItHeavy() const override;
  std::string getHero() const;

  bool favourite() const override;
}; */

class Row : public Container {
	
	public:
	Row(std::vector<Cell*>);
	~Row();
	void notify() override;
};

#endif
