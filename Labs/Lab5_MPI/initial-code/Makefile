CXX = mpicxx
MPIEXEC = mpiexec
MPIFLAGS = -np 2
DIFF ?= diff
CXXFLAGS += -Wall -std=c++11

EXE = power_method
OBJS = main.o matrix.o dense_matrix.o power_method.o

TIC = date +%s.%N

main.o: dense_matrix.hpp matrix.hpp power_method.hpp
dense_matrix.o: dense_matrix.hpp matrix.hpp
matrix.o: matrix.hpp
power_method.o: dense_matrix.hpp matrix.hpp

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
