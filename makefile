CXX = g++
CXXFLAGS = -Wall -g -std=c++11 -lncurses
SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)
EXEC = TerminalInvaders

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
