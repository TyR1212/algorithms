//Ty Rozell
//This is the function definition file for the Cluster class

#include "Cluster.h"

//constructor for Cluster
Cluster::Cluster(int setID, Point startPoint)
{
    ID = setID;
    centroidX = startPoint.getX();
    centroidY = startPoint.getY();
}

//set new centroid x and y
void Cluster::setXY(double newX, double newY)
{
    centroidX = newX;
    centroidY = newY;
}

//set closest point
void Cluster::setClosestPoint(int pointID)
{
    closestPoint = pointID;
}

//add a point to the assigned points vector
void Cluster::addAssignedPoint(Point *pointAddress)
{
    assignedPoints.push_back(pointAddress);
}

//gets the assigned points address vector
vector<Point*> Cluster::getAssignedPoints() const
{
    return assignedPoints;
}

//gets the ID of the closest point
int Cluster::getClosestPoint() const
{
    return closestPoint;
}

//get the number of points assinged to the cluster
int Cluster::getNumPoints() const
{
    return assignedPoints.size();
}

//get the ID of a cluster
int Cluster::getClusterID() const
{
    return ID;
}

//get individual point's x value
double Cluster::getPointX(int i) const
{
    return assignedPoints[i]->getX();
}

//get individual point's y value
double Cluster::getPointY(int i) const
{
    return assignedPoints[i]->getY();
}

//get cluster centroid's x value
double Cluster::getCentroidX() const
{
    return centroidX;
}

//get cluster centroid's y value
double Cluster::getCentroidY() const
{
    return centroidY;
}

Point::Point(int ID, float X, float Y)	//constructor
{
	id = ID; x = X; y = Y; assignedCluster = 0;
}

//Point class's get and set functions
int Point::getID() const { return id; }	//get functions
float Point::getX() const { return x; }
float Point::getY() const { return y; }
int Point::getAssigned() const { return assignedCluster; }

void Point::setID(int ID) { id = ID; }	//set functions
void Point::setX(float X) { x = X; }
void Point::setY(float Y) { y = Y; }
void Point::setAssigned(int assign) { assignedCluster = assign; }