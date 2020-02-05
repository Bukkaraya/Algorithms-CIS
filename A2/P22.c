// Author: Abinav Bukkaraya
// ID: 0951030
// Brute Force Implementation of Convex Hull Problem

#include <stdio.h>

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


void printPoint(Point p);
double getSideOfPoint(LineValues l, Point p);
LineValues getLineFromPoints(Point p1, Point p2);
double getDistanceFromLine(LineValues l, Point p);

int quickConvexHull() {
    return 0;
}

int getConvexHull(Point points[], int size) {
    Point minPoint = points[0];
    Point maxPoint = points[0];
    
    // Get points with maximum and minimum X value
    for (int i = 0; i < size; i++) {
        if (points[i].x < minPoint.x) {
            minPoint = points[i];
        }

        if (points[i].x > maxPoint.x) {
            maxPoint = points[i];
        }
    }

    printPoint(minPoint);
    printPoint(maxPoint);
    
    Point rightSide[size];
    Point leftSide[size];

    int j = 0;
    int k = 0;

    LineValues l = getLineFromPoints(minPoint, maxPoint);

    for (int i = 0; i < size; i++) {
        double pointSide = getSideOfPoint(l, points[i]);

        if(pointSide == 0) {
            continue;
        }

        if(pointSide > 0) {
            rightSide[j] = points[i];
            j++;
        } else {
            leftSide[k] = points[i];
            k++;
        }
    }
    
    printf("J: %d, K: %d\n", j, k);

    return 0;
}


int main() {
    int size = 8;
    Point points[8] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                    {0, 0}, {1, 2}, {3, 1}, {3, 3}};


    getConvexHull(points, size);

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

