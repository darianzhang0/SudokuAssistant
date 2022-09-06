# SudokuAssistant
A Sudoku Assistant which fills in all immediately solvable numbers. Immediately solvable numbers mean a number is the only one in the Row, Column and Box the Cell is contianed in that can hold that number.

The assistant is written in C++ and implements the **Observer Pattern** where Cells and Containers both act as **Observer** and **Subjects**. Cells observe the Containers (a block of 9 cells so the Rows, Columns, and Boxes) they reside in and Containers observe Cells residing in them.

The assistant takes in input representing a sudoku board where '-' represents an empty space. An example input below.
```
--- -75 46- 
-7- -94 --5 
--- -3- -91 

-8- 76- --2 
--2 --- 3-- 
3-- -12 -4- 

8-- -4- --- 
7-- 58- -3- 
-15 3-- ---
```
The output would be:
```
29- -75 463
-73 -94 --5
54- 23- 791

-8- 763 --2
-62 45- 3--
357 -12 -4-

83- -4- ---
72- 58- -3-
-15 32- ---
```
The below input:
```
--- -75 46- 
-7- -94 -25 
--- -3- --1 

-8- 76- --2 
--2 --- 3-- 
3-- -12 -4- 

8-- -4- --- 
7-- 58- -3- 
-15 3-- --- 
```
Would result in the below output:
```
291 875 463
673 194 825
548 236 791

984 763 512
162 458 379
357 912 648

839 641 257
726 589 134
415 327 986
```
