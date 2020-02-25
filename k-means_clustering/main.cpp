//Ty Rozell

#include <iostream>
#include <vector>
#include "k-means.h"
#include "Cluster.h"

void getSampleData(vector<Point>&);

using namespace std;

int main()
{
    vector<Point> points;               //stores the points
    vector<int> startPoints = {1, 3};   //stores id's of the starting points for clustering
                                        //here, there are 2 startpoints meaning that there will be 2 clusters
    vector<Cluster> clusters;           //stores the clusters
    
    getSampleData(points);

    //call k-means clustering function
    clusters = kmeans(points, startPoints);

    //output results of clustering
    cout << endl << "For k-means clustering: " << endl; //print heading
    for (const auto &cluster : clusters)
    {
        cout << "Cluster " << cluster.getClusterID() + 1 << " contains " << cluster.getNumPoints()
             << " points and the point " << cluster.getClosestPoint() << " is the closest to its centroid." << endl
             << " Assigned points: ";
             for (const auto point : points)
                if (point.getAssigned() == cluster.getClusterID())
                    cout << point.getID() << ' ';
        cout << endl;
    }
}

void getSampleData(vector<Point>& points)
{
    points.push_back(Point(0, 34, 25));
    points.push_back(Point(1, 2, 53));
    points.push_back(Point(2, 52, 27));
    points.push_back(Point(3, 19, 43));
    points.push_back(Point(4, 0, 45));
    points.push_back(Point(5, 8, 74));
    points.push_back(Point(6, 64, 43));
    points.push_back(Point(7, 0, 81));
    points.push_back(Point(8, 74, 58));
    points.push_back(Point(9, 14, 17));
}