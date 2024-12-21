CXX = mpicxx
MPIEXEC = mpiexec
MPIFLAGS = -np 2
DIFF ?= diff
CXXFLAGS += -Wall -std=c++11

EXE = evaluate_by_column
OBJS = main.o dense_matrix.o evaluate_by_column.o

TIC = date +%s.%N

main.o: dense_matrix.hpp evaluate_by_column.hpp
dense_matrix.o: dense_matrix.hpp
evaluate_by_column.o: dense_matrix.hpp

.DEFAULT_GOAL = all
.PHONY: all build clean distclean

all: build

build: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) $^ $(OUTPUT_OPTION)



clean:
	$(RM) $(OBJS)
	$(RM) $(EXE)


distclean: clean
	$(RM) *~
