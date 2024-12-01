#ifndef CLUSTERING_H_
#define CLUSTERING_H_

#include <vector>

#include "Centroid.h"
#include "Point.h"

class Clustering
{
  /* Your code goes here */  f_labels_type ;
  /* Your code goes here */  centers_type;
  /* Your code goes here */  clusters_type;

  Clustering (const Clustering & c) = delete;
  Clustering & operator=(const Clustering & c) = delete;
  
  static constexpr double MAX_COORD = 1000.0;

  std::vector<Point> points;
  f_labels_type labels; //label function
  unsigned int p; //number of dimensions
  unsigned int n; //number of points
  unsigned int k; //number of clusters

  centers_type centers;
  clusters_type clusters;

  unsigned int max_it; //maximum number of iterations

  unsigned int
  min_dist_index (const Point  & point) const; //returns the index of the centroid closest to point

  void
  print_labels (void) const;
  void
  print_centers (void) const;
  void
  print_clusters (void) const;

public:
  Clustering (unsigned int dimensions, unsigned int n_points,
              unsigned int k_cluster, unsigned int max_iterations);

  void
  print (void) const;
  void
  calc_cluster (void);
};

#endif /* CLUSTERING_H_ */
