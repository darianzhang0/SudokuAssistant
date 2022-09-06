#ifndef CELL_H_
#define CELL_H_
#include "container.h"
#include "observer.h"
#include "subject.h"
class Container; // added
class Cell : public Observer, public Subject {
    int value;
    Container *row;
    Container *col;
    Container *box;
    // You may add any fields or private helpers you
    // see fit, so long as you are still implementing
    // the observer pattern.
public: // DELETE THIS PUBLIC
    int canBe[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
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

    // added methods
    void setRow(Container *);
    void setCol(Container *);
    void setBox(Container *);

    int getRow(int);
    int getCol(int);
    int getBox(int);

    friend class Container;
    friend class Row;
    friend class Col;
    friend class Box;
};

#endif
