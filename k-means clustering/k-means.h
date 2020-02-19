//Ty Rozell
//This is the header file for k-means

#include <iostream>
#include <vector>
#include <cmath>
#include "Cluster.h"

using namespace std;

#ifndef KMEANS_H
#define KMEANS_H

//function prototypes
vector<Cluster> kmeans(vector<Point>&, const vector<int>&);

#endif