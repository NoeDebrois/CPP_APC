# Eigenvalue Computation: Power Iteration Methods

This repository contains my solution to **Assignment 1** for the Advanced Programming Challenge 2024. The task focuses on implementing and testing three numerical methods to compute eigenvalues of matrices using iterative techniques: **Power Iteration**, **Inverse Power Iteration**, and **Shift Inverse Power Iteration**.

## Overview

### Objective
Develop methods to approximate specific eigenvalues and their corresponding eigenvectors for a given square matrix. The provided framework includes utility functions for matrix operations, and the assignment involves completing key algorithmic implementations.

### Methods Implemented
1. **Power Iteration**: Computes the dominant eigenvalue (largest in magnitude) and its eigenvector.
2. **Inverse Power Iteration**: Approximates the eigenvalue of the smallest magnitude.
3. **Shift Inverse Power Iteration**: Targets the eigenvalue closest to a user-specified value, leveraging a shift in the matrix.

## Implementation Details

The following files were completed as part of the assignment:
- `power_iteration.cpp`: Implements the basic Power Iteration method.
- `inverse_power_iteration.cpp`: Implements the Inverse Power Iteration method using LU factorization.
- `shift_inverse_power_iteration.cpp`: Extends the Inverse Power Iteration method to compute eigenvalues near a specified shift.

### Key Algorithm Concepts
1. Iterative updates of vectors and eigenvalue estimates:
   - Dominant eigenvalue approximation via successive matrix-vector multiplications.
   - Error bounded by the ratio of eigenvalues.
2. LU Factorization:
   - Used for solving systems efficiently in the Inverse Power Iteration methods.
3. Convergence Criteria:
   - Algorithm stops when both the **residual** and **increment** fall below a set tolerance (e.g., \(10^{-6}\)).

## Testing

The solution is validated on three provided test matrices (`input_10.txt`, `input_20.txt`, `input_30.txt`). The correctness of the implementations is verified by comparing results with expected eigenvalues. Additional test cases will be used for final evaluation.
