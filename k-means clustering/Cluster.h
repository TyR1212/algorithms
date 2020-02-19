//Ty Rozell
//This is the header file for the KCluster class

#include <vector>

using namespace std;

#ifndef KCLUSTER_H
#define KCLUSTER_H

class Point
{
    private:
        int id;              //point id
        float x;             //x location
        float y;             //y location
        int assignedCluster; //cluster id that the point is assigned to
        
    public:
        Point(int id, float x, float y);
        int getID() const;
        float getX() const;
        float getY() const;
        int getAssigned() const;
        void setID(int);
        void setX(float);
        void setY(float);
        void setAssigned(int);
};

class Cluster
{
    private:
        int ID;                      //stores ID of cluster
        int closestPoint;            //stores closest point to the centroid
        double centroidX, centroidY; //stores the centroid x and y positions
        vector<Point*> assignedPoints; //vector of Point pointers, this will point to the original Points vector from step 1

    public:
        //constructor
        Cluster(int, Point);

        //set functions
        void setXY(double, double);
        void setClosestPoint(int);
        void addAssignedPoint(Point*);

        //get functions
        vector<Point*> getAssignedPoints() const;
        int getClosestPoint() const;
        int getNumPoints() const;
        int getClusterID() const;
        double getPointX(int) const;
        double getPointY(int) const;
        double getCentroidX() const;
        double getCentroidY() const;
};

#endif