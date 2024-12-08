Those files are the first "parallel computing" implementations that we saw during the course. They should be executed on the VM given during the course.

## hello.cpp :
1) mpicxx --std=c++23 -o helloMPI hello.cpp [COMPILE]
2) mpiexec -np 2 ./helloMPI [RUN]

