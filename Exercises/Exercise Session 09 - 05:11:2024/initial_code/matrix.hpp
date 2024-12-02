#ifndef MATRIX_H_
#define MATRIX_H_

// The two children (block_matrix & dense_matrix) store the data in a very different way :
// - block_matrix stores blocks ;
// - dense_matrix stores a vector.
// That's why we cannot store the data in the base class.
// Instead we can store the number of rows and the number of columns in the base class since
// all the children will store it the same way.

class Matrix
{
protected: // We don't want users to be accessing n_rows and n_cols freely, but we'll need them
    // in the children classes.
        unsigned n_rows = 0;
        unsigned n_cols = 0;

    public:
        Matrix (unsigned rows, unsigned cols); // Constructor

        // We want to distinguish two versions of this :
        // "Matrix A;" ;
        // - One is a getter-like version : "d = A(i, j);" ;
        // - The other is a setter-like versio : "A(i, j) = 7;".
                // - This one should return a reference because otherwise we would set a value to
                // a copy which will be then lost (when out of scope).
        // We need overloading : so we need to change at least either the type or parameter(s) or
        // the number of parameter(s). But us, we don't want to change the number of arguments.
        // BUT REMEMBER : we can overload a class method even without changing the parameters but
        // by implementing a "const" and a non "const" methods. This is exactly what we do here.
        virtual double operator () (unsigned i, unsigned j) const = 0; // const : WE DON'T WANT TO MODIFY THE MATRIX.
        virtual double& operator () (unsigned i, unsigned j)  = 0; // Virtual since we don't know
        // what's the actual implementation at the moment. We don't know how the data is stored.

        // This is exactly what is done in std::vector class :
        // std::vector<T>
        // T operator[] (unsigned i) const; --> a = v[8]
        // T operator[] (unsigned i); --> v[8] = 6

        // Those are getters so for sure they won't modify the matrix :
        unsigned get_n_cols() const;
        unsigned get_n_rows() const;

        // Virtual default destructor :
        virtual ~Matrix() = default;
};

#endif /* MATRIX_H_ */
