CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
OBJECTS = main.o observer.o subject.o assistant.o cell.o container.o row.o col.o box.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a4q4

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}
	
-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
