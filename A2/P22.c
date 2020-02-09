// Author: Abinav Bukkaraya
// ID: 0951030
// Assignment 2
// Quickhull Implementation of Convex Hull Problem

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <string.h>

#define NUM_AXES 2
#define TRUE 1
#define FALSE 0


typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    double a;
    double b;
    double c;
} LineValues;

Point hullPoints[100000];
int numHullPoints = 0;

void printPoint(Point p);
double getSideOfPoint(LineValues l, Point p);
LineValues getLineFromPoints(Point p1, Point p2);
double getDistanceFromLine(LineValues l, Point p);
int addToConvexHullPoints(Point p);
void printSortedPoints();


int isSameSign(double a, double b) {
    if (a == 0 || b == 0) {
        return TRUE;
    }

    if (a >= 0 && b >= 0) {
        return TRUE;
    } else if (a < 0 && b < 0) {
        return TRUE;
    }

    return FALSE;
}


int quickConvexHull(Point points[], Point a, Point b, int size) {
    if(size == 0) {
        return 0;
    }

    int numPoints;

    double maxDistance = -1;
    Point pointWithMaxDist;
    int maxDistIndex = 0;
    double currentDistance = 0.0;

    LineValues l = getLineFromPoints(a, b);

    for (int i = 0; i < size; i++) {
        currentDistance = getDistanceFromLine(l, points[i]);
        
        if(currentDistance > maxDistance) {
            maxDistance = currentDistance;
            pointWithMaxDist = points[i];
            maxDistIndex = i;
        }
    }

    addToConvexHullPoints(pointWithMaxDist);

    LineValues linePA = getLineFromPoints(a, pointWithMaxDist);
    LineValues lineBP = getLineFromPoints(pointWithMaxDist, b);

    double sideOfB = getSideOfPoint(linePA, b);
    double sideOfA = getSideOfPoint(lineBP, a);

    Point setA[size];
    int setASize = 0;

    Point setB[size];
    int setBSize = 0;

    for (int i = 0; i < size; i++) {
        double pointSideFromPA = getSideOfPoint(linePA, points[i]);
        double pointSideFromBP = getSideOfPoint(lineBP, points[i]);

        if (!isSameSign(sideOfB, pointSideFromPA)) {
            setA[setASize] = points[i];
            setASize++;
        }

        if (!isSameSign(sideOfA, pointSideFromBP)) {
            setB[setBSize] = points[i];
            setBSize++;
        }

    }

    if(size > 0) {
        numPoints += quickConvexHull(setA, a, pointWithMaxDist, setASize);
        numPoints += quickConvexHull(setB, pointWithMaxDist, b, setBSize);
    }

    return 0;
}

int getConvexHull(Point points[], int size) {
    Point minPoint = points[0];
    Point maxPoint = points[0];
    int minPointIndex = 0;
    int maxPointIndex = 0;

    // Get points with maximum and minimum X value
    for (int i = 0; i < size; i++) {
        if (points[i].x < minPoint.x) {
            minPoint = points[i];
            minPointIndex = i;
        }

        if (points[i].x > maxPoint.x) {
            maxPoint = points[i];
            maxPointIndex = i;
        }
    }

    Point rightSide[size];
    Point leftSide[size];

    int j = 0;
    int k = 0;

    LineValues l = getLineFromPoints(minPoint, maxPoint);

    addToConvexHullPoints(maxPoint);
    addToConvexHullPoints(minPoint);

    for (int i = 0; i < size; i++) {
        double pointSide = getSideOfPoint(l, points[i]);

        if(i == maxPointIndex || i == minPointIndex) {
            continue;
        }

        if(pointSide >= 0) {
            rightSide[j] = points[i];
            j++;
        } else {
            leftSide[k] = points[i];
            k++;
        }
    }

    quickConvexHull(rightSide, minPoint, maxPoint, j);
    quickConvexHull(leftSide, maxPoint, minPoint, k);

    return 0;
}


int main(int argc, char *argv[]) {
    char line[256];
    FILE *fp;
    int numPoints = 0;
    double numA = 0;
    double numB = 0;
    struct timeval startTime,endTime;
    char fileName[256] = "data2.txt";

    if (argc > 1) {
        strcpy(fileName, argv[1]);
    }

    printf("Using file: %s\n", fileName);

    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Could not open file, please try again.\n");
        return 0;
    }

    while (fgets(line, sizeof(line), fp)) {
        if(line[0] == '\n') {
            continue;
        }

        numPoints++;
    }

    printf("Number of Points: %d\n", numPoints);
    Point points[numPoints];

    int result = 0;
    int i = 0;
    Point p;

    fseek(fp, 0, SEEK_SET);

    while(fscanf(fp, "%lf %lf", &numA, &numB) == 2) {
        p.x = numA;
        p.y = numB;

        points[i] = p;
        i++;
    }

    gettimeofday(&startTime, NULL);

    getConvexHull(points, numPoints);

    gettimeofday(&endTime, NULL);

    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);
    printf("Number of Points in Convex Hull: %d\n", numHullPoints);
    printSortedPoints();

    return 0;
}

void printPoint(Point p) {
    printf("P(%f, %f)\n", p.x, p.y);
}


double getSideOfPoint(LineValues l, Point p) {
    return (l.a * p.x) + (l.b * p.y) - l.c;
}


LineValues getLineFromPoints(Point p1, Point p2) {
    LineValues l;

    // a = y_2 - y_1
    // b = x_1 - x_2
    // c = x_1 * y_2 - x_2 * y_1

    l.a = p2.y - p1.y;
    l.b = p1.x - p2.x;
    l.c = (p1.x * p2.y) - (p1.y * p2.x);

    return l;
}

double getDistanceFromLine(LineValues l, Point p) {
    double num = abs((l.a * p.x) + (l.b * p.y) - l.c);
    double denom = sqrt((l.a * l.a) + (l.b * l.b));

    return num/denom;
}


int addToConvexHullPoints(Point p) {
    int pointAlreadyPresent = FALSE;
    for (int i = 0; i < numHullPoints; i++) {
        if(fabs(hullPoints[i].x - p.x) < 0.0001 &&
            fabs(hullPoints[i].y - p.y) < 0.0001) {
                pointAlreadyPresent = TRUE;
            }
    }

    if (!pointAlreadyPresent) {
        hullPoints[numHullPoints] = p;
        numHullPoints++;
    }
}

void printSortedPoints() {
    for(int i = 0; i < numHullPoints; i++) {
        for(int j = 0; j < numHullPoints; j++) {
            Point temp;
            if (hullPoints[i].x < hullPoints[j].x) {
                temp = hullPoints[j];
                hullPoints[j] = hullPoints[i];
                hullPoints[i] = temp;
            }
        }
    }

    printf("Convex Hull Points Are:\n");

    for (int i = 0; i < numHullPoints; i++) {
        printPoint(hullPoints[i]);
    }
}