#include "Centroid.h"

void Centroid::update_coords(std::vector<Point *> const & ps)
{
    /* MY CODE */
    std::vector<double> new_coords(x.size(), 0.0); // cf base class Point, where x is a protected member.
    // x is a vector of double, so we can use its size to initialize our new coordinates.

    for (size_t i = 0; i < ps.size(); i++){ // For each point i
        for (size_t j = 0; j < x.size(); j++){ // For each coordinate j
            new_coords[j] += ps[i]->get_coord(j); // Add the coordinate j of the point i
        }
    }

    for (size_t j = 0; j < new_coords.size(); j++) {
        new_coords[j] /= ps.size(); // Compute the mean by dividing by the nb of points.
    }

    // Update the centroid's coordinates :
    // x = new_coords; // O(Nb of dimensions)... -> slow. [WARNING]
    swap(x, new_coords); // O(1) !!
}