#include <iostream>
#include <random>
#include <mpi.h>
#include <string>


double square(double x);  // return x*x

double dboard(unsigned darts, unsigned seed);  // implement Pi approximation through darts random sampling

double approximate_pi(unsigned long iterations, unsigned darts);

int main(int argc, char *argv[]) 
{
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc == 3)
    {
        // get number of iterations and darts from command-line
        unsigned iterations = std::stoul(argv[1]);
        unsigned darts = std::stoul(argv[2]);
        
        // compute local number of iterations
        const unsigned long local_n = iterations / size;
        // initialize local seed
        unsigned local_seed = rank * local_n;

        // compute local sum
        double local_sum = 0.;
        for (unsigned i = 1; i <= local_n; ++i)
            local_sum += dboard(darts, local_seed++);

        // communication
        double sum = 0.;
        MPI_Reduce(&local_sum, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

        if (rank == 0)
        {
            double approx_pi = sum / iterations;
            std::cout << "Pi approximation " << approx_pi << std::endl;
        }
    }
    else
        std::cout << "Error, two arguments expected " << std::endl;

    MPI_Finalize();

    return 0;
}

double square(double x)
{
    return x*x;
}

double dboard(unsigned darts, unsigned seed){
    double x_coord,       // x coordinate, between -1 and 1
            y_coord,      // y coordinate, between -1 and 1
            pi;           // pi approximation
    unsigned score;       // number of darts that hit circle

    std::default_random_engine generator(seed); // random engine generator
    std::uniform_real_distribution<double> distribution (-1.0,1.0); // callable object for random number generation

    score = 0;

    for (unsigned n = 1; n <= darts; ++n){
        /* generate random numbers for x and y coordinates */
        x_coord = distribution(generator);
        y_coord = distribution(generator);

        /* if dart lands in circle, increment score */
        if ((square(x_coord) + square(y_coord)) <= 1.0)
            ++score;
    }

    // calculate pi
    pi = 4.0 * static_cast<double>(score)/ static_cast<double>(darts);
    return pi;
}
