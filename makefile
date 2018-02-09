CXX = g++
CXXFLAGS += -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = inputValidate.o menu.o main.o

SRCS = inputValidate.cpp menu.cpp main.cpp

HEADERS = inputValidate.hpp menu.hpp
lab9: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o lab9

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} -c ${SRCS}

clean:
	rm *.o lab9
