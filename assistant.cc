#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "assistant.h"
#include "cell.h"
#include "container.h"
#include "row.h"
#include "col.h"
#include "box.h"
#include "observer.h"
#include "subject.h"

using namespace std;

/*
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
    // done, and all the cells that could have been filled m the Assistant
    // are already filled in. As always, you must match the sample executable
    // in behaviour.
    friend std::istream& operator>>(std::istream &, Assistant &);
    // Outputs the Sudoku puzzle, with formatting consistent with the sample
    // executable.
    friend std::ostream& operator<<(std::ostream &, const Assistant &);
}; */

Assistant::Assistant() {
	// initialize cells
	for (int i = 0; i < 9; ++i) {
		vector<Cell *> v;
		for (int j = 0; j < 9; ++j) {
			v.emplace_back(new Cell());
		}
		cells.emplace_back(v);
	}
	
	// initialize rows
	for (int i = 0; i < 9; ++i) {
		vector<Cell*> v;
                for (int j = 0; j < 9; ++j) {
                        v.emplace_back(cells[i][j]);
                }   
                rows.emplace_back(new Row(v));
	}
	
	// initialize cols
	for (int i = 0; i < 9; ++i) {
		vector<Cell*> v;
		for (int j = 0; j < 9; ++j) {
			v.emplace_back(cells[j][i]);
		}
		cols.emplace_back(new Col(v));
	}

	// initialize boxes
	for (int i = 0; i < 9; i = i + 3) {
        	for (int j = 0; j < 9; j = j + 3) {
			vector<Cell*> v;
            		for (int n = (i / 3) * 3; n < (i / 3) * 3 + 3; n++) {
                		for (int m = (j / 3) * 3; m < (j / 3) * 3 + 3; m++) {
                    			v.emplace_back(cells[n][m]);
                		}
            		}
			boxes.emplace_back(new Box(v));
        	}
    	}
}

Assistant::~Assistant() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			delete cells[i][j];
		}
	}
	for (int i = 0; i < 9; ++i) {
		delete rows[i];
		delete cols[i];
		delete boxes[i];
	}
}

istream& operator>>(istream &in, Assistant &a) {
	char c;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (!(in >> c)) {
				return in;
			}
			if (c != '-') {
				int n = c - '0';
				a.cells[i][j]->setValue(n);
//			} else {
//				a.cells[i][j]->setValue(-1);
			}
//			cerr << a.cells[0][0]->getValue() << ' ';
			for (int i = 0; i < 9; ++i) {
				for (int j = 0; j < 9; ++j) {
					int n = a.cells[i][j]->getValue();
					if (n == -1) {
//						cout << '-';
					} else {
//						cout << n;
					}
					if (j == 2 || j == 5) {
//						cout << ' ';
					}
				}
//				cout << endl;
				if (i == 2 || i == 5) {
//						cout << endl;
				}
			}
			if (i == 8) {
				int i = 0;
				int j = 0; 
				for (int n = (i / 3) * 3; n < (i / 3) * 3 + 3; n++) {
					for (int m = (j / 3) * 3; m < (j / 3) * 3 + 3; m++) {
//						cout << a.cells[n][m]->getValue() << ':';
						for (int i = 0; i < 9; ++i) {
//							cerr << a.cells[n][m]->canBe[i] << ' ';
						}
//						cerr << endl;
					}   
				}
			}
//			cerr << "------" << endl;
		}
//		cerr << endl;
	}
	return in;
}

ostream& operator<<(ostream &out, const Assistant &a) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int n = a.cells[i][j]->getValue();
			if (n == -1) {
				cout << '-';
			} else {
				cout << n;
			}
			if (j == 2 || j == 5) {
				cout << ' ';
			}
		}
		cout << endl;
		if (i == 2 || i == 5) {
			cout << endl;
		}
	}
	int i = 0;
	int j = 0; 
	for (int n = (i / 3) * 3; n < (i / 3) * 3 + 3; n++) {
		for (int m = (j / 3) * 3; m < (j / 3) * 3 + 3; m++) {
//			cout << a.cells[n][m]->getValue() << ':';
			for (int i = 0; i < 9; ++i) {
//				cerr << a.cells[n][m]->canBe[i] << ' ';
			}
//			cerr << endl;
		}   
	}   
	/*
	for (int i = 0; i < 9; ++i) {
		cout << a.cells[0][0]->row->contained[i]->getValue() << ' ';
	}
	cout << endl;
	for (int i = 0; i < 9; ++i) {
                cout << a.cells[0][0]->col->contained[i]->getValue() << ' ';
        }  
	cout << endl;
	for (int i = 0; i < 9; ++i) {
                cout << a.cells[0][0]->box->contained[i]->getValue() << ' ';
        }  
	cout << endl; */
	return out;
}





