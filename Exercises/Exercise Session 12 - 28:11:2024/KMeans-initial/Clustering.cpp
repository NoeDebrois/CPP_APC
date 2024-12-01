#include <iostream>
#include <random>

#include "Clustering.h"

Clustering::Clustering (unsigned int dimensions, unsigned int n_points,
                        unsigned int k_cluster, unsigned int max_iterations)
  : p (dimensions), n (n_points), k (k_cluster), max_it (max_iterations)
{
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution (0.0, MAX_COORD);

  std::vector<Point *> all_pointers_points;

  for (unsigned i = 0; i < n; ++i)
    {
      //Generate n random points
      // Generate random coordinates
      std::vector<double> coords;


      for (unsigned j = 0; j < p; ++j)
        coords.push_back (distribution (generator));


      // Generate a new Point
      points.push_back (coords);
      labels.push_back (0); // assign every point to class 0
      all_pointers_points.push_back(& points[i]);  // store current point address
    }

  const std::vector<double> origin (p, 0);

  // Create and intialize centroids to origin
  for (unsigned i = 0; i < k; ++i)
    centers.push_back (origin);

  // Assign all points to cluster 0
  clusters.push_back(all_pointers_points);

  // Create and initialize other clusters to nulls
  for (unsigned i = 1; i < k; ++i)
    clusters.push_back ({nullptr});
}

void
Clustering::print (void) const
{
  // Print points and labels
  for (std::size_t i = 0; i < points.size (); ++i)
    {
      points[i].print ();
      std::cout << " : ";
      std::cout << labels[i];
      std::cout << std::endl;
    }
}

void
Clustering::calc_cluster (void)
{
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution (0, k - 1);

  //Randomly initialize labels
  /* Your code goes here */
  int random_int  = distribution (generator);

  bool term_cond = false;
  unsigned i;

  for (i = 0; i < max_it && ! term_cond; ++i)
    {
      /* Your code goes here */

      // update clusters according to new labels
      /* Your code goes here */

      // update centroids


      // assign points to new centroids

      term_cond = /* Your code goes here */
    }

  std::cout << "Number of iterations: " << i << std::endl;
  std::cout << "Final result!" << std::endl;
  print_labels ();
  std::cout << std::endl;
}

unsigned int
Clustering::min_dist_index (const Point & point) const
{
  int min_dist_ind = 0;
  double min_dist = point.distance (centers[0]);

  for (std::size_t i = 1; i < centers.size (); ++i)
    {
      const double dist = point.distance (centers[i]);
      if (dist < min_dist)
        {
          min_dist = dist;
          min_dist_ind = i;
        }
    }

  return min_dist_ind;
}

void
Clustering::print_labels (void) const
{
  for (auto it = labels.begin (); it != labels.end (); ++it)
    {
      std::cout << *it << " ";
    }
}

void
Clustering::print_centers (void) const
{
  std::cout << "Centers size: ";
  std::cout << centers.size ();
  std::cout << std::endl;

  for (std::size_t i = 0; i < centers.size (); ++i)
    centers[i].print ();
}

void
Clustering::print_clusters (void) const
{
    /* Your code goes here */
}
