//Ty Rozell
//This is the function definition file for k-means

#include "k-means.h"

//helper functions
double getDistance(Point, Cluster);
double getDistance(Point, Point);
void updateXY(const vector<Point>&, vector<Cluster>&);

//main k-means clustering function
vector<Cluster> kmeans(vector<Point> &points, const vector<int>& startPoints)
{
    //Declare variables
    vector<Cluster> clusters; //stores clusters for current trial
    Point *closest;           //temporarily stores the closest point to a centroid
    bool changed = true;      //condition variable for a while loop

    //Populate clusters vector
    for (int i=0; i < startPoints.size(); i++)
        clusters.push_back(Cluster(i, points[startPoints[i]]));   //add new cluster

    //Clustering loop
    while(changed)    //loop until no point is reassigned
    {
        changed = false;
        
        for (auto &point : points)   //go through every point
        {
            for (const auto &cluster : clusters)   //go through every cluster
            {
                //assign point to a cluster if it is closer to it than its current assinged cluster
                if (point.getAssigned() != cluster.getClusterID() && getDistance(point, clusters[point.getAssigned()]) > 
                    getDistance(point, cluster))
                {
                    point.setAssigned(cluster.getClusterID()); //update point assignment
                    changed = true;     //point got reassigned, repeat while loop
                }
                //in case of a tie, assign point to the cluster with the smaller ID
                else if (point.getAssigned() != cluster.getClusterID() && getDistance(point, clusters[point.getAssigned()]) == 
                    getDistance(point, cluster) && point.getAssigned() > cluster.getClusterID())
                {
                    point.setAssigned(cluster.getClusterID());
                    changed = true;
                }
            }
        }
        updateXY(points, clusters);   //update all of the clusters' centroids
    }

    //Populate the assigned points vector for each cluster
    for (auto &point : points)
        clusters[point.getAssigned()].addAssignedPoint(&point);   //push point address to corresponding cluster

    //Calculate closest point to the centroid of each cluster
    for (auto &cluster : clusters)
    {
        closest = cluster.getAssignedPoints()[0];    //initialize the closest point
        for (const auto &point : cluster.getAssignedPoints())
        {
            if (getDistance(*point, cluster) < getDistance(*closest, cluster))
                closest = point;    //found a closer point
        }
        cluster.setClosestPoint(closest->getID());   //store the closest point's ID
    }

    return clusters;    //done clustering
}

//finds the distance between a point and a centroid using Euclidean distance
double getDistance(Point point, Cluster cluster)
{
    return sqrt(pow(point.getX() - cluster.getCentroidX(), 2) + pow(point.getY() - cluster.getCentroidY(), 2));
}

//calculates new centroid x and y positions based on changes in point assignment
void updateXY(const vector<Point> &points, vector<Cluster> &clusters)
{
    double avgX, avgY;  //stores average x and y values
    int numAssigned;    //stores number of points that are assigned to a cluster

    for (auto &cluster : clusters)
    {
        avgX = 0;
        avgY = 0;
        numAssigned = 0;
        for (const auto &point : points)
        {
            //add up all points' x and y values that are assigned to the cluster
            if (point.getAssigned() == cluster.getClusterID())
            {
                avgX += point.getX();
                avgY += point.getY();
                numAssigned++;
            }
        }
        //find average x and y
        avgX /= numAssigned;
        avgY /= numAssigned;
        cluster.setXY(avgX, avgY);   //store new positions
    }
}