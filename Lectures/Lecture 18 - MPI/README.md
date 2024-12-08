Those files are the first "parallel computing" implementations that we saw during the course. They should be executed on the VM given during the course.

## hello.cpp :
1) mpicxx --std=c++23 -o helloMPI hello.cpp [COMPILE]
2) mpiexec -np 2 ./helloMPI [RUN]

## trapezoidal_rule :
cd inside the folder and :
1) mpicxx -o reduce --std=c++11 with_io.cc quadrature.cc bcast.cc reduce.cc [COMPILE]
2) mpiexec -np 4 -oversubscribe reduce
3) Enter lower bound / upper bound / number of trapezoids

PS : the number after "-np" corresponds to the number of cores.
PSS : "-oversubscribe" is needed if there are not enough cores avaiable (I guess it uses previously used cores).
