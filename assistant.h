#ifndef ASSISTANT_H_
#define ASSISTANT_H_
#include <vector>
#include <iostream>
#include "cell.h"
#include "container.h"

class Assistant {
    // All the Cells in the Sudoku puzzle. It is suggested your assistant
    // be the owner of these cells.
    std::vector<std::vector<Cell*>> cells;
    // The rows, columns, and boxes of your Sudoku puzzle.
    // The assistant should own these.
    std::vector<Container*> rows;
    std::vector<Container*> cols;
    std::vector<Container*> boxes;
  public:
    // Default constructor, should set up a grid and attach all observers
    // to their subjects
    Assistant();
    ~Assistant();

    // The input operator reads in characters and assigns values to the cells
    // in the grid starting at the top left cell of the grid and reading left
    // to right, top to bottom. So the first 9 non-whitespace characters read
    // are the values of the first row, the next 9 non-whitespace characters
    // are the values of the second row, and so on. If a digit character is
    // read that value is assigned to the cell whose value is currently being
    // read in, when a cell's value is set in this way it should notify its
    // observers so that they may react. If a non-digit character is read
    // then that cell initially has no value in the puzzle, and is left
    // "unset". We suggest you use some specific number to represent a cell
    // that is not yet set, so you can check if a cell is not set yet in your
    // program. Since the reading in of cells values notifies its observers,
    // which will eventually lead to cascading of notifies, once a puzzle is
    // finished being read in the Assistants work should already be completely
    // done, and all the cells that could have been filled by the Assistant
    // are already filled in. As always, you must match the sample executable
    // in behaviour.
    friend std::istream& operator>>(std::istream &, Assistant &);
    // Outputs the Sudoku puzzle, with formatting consistent with the sample
    // executable.
    friend std::ostream& operator<<(std::ostream &, const Assistant &);
};


#endif
