// Author: Abinav Bukkaraya
// ID: 0951030
// Brute Force Implementation of Convex Hull Problem

#include <stdio.h>
#include <sys/time.h>
#include <math.h>
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


void addToConvexHullPoints(Point p);
void printPoint(Point p);
void printSortedPoints();


Point hullPoints[100000];
int numHullPoints = 0;

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


void bruteConvexHull(Point points[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            // Compute Coefficients
            // a = y_2 - y_1
            // b = x_1 - x_2
            // c = x_1 * y_2 - x_2 * y_1
            double previousSide = 0;
            double currentSide = 0;

            int isValidPair = TRUE;

            LineValues l = getLineFromPoints(points[i], points[j]);

            for(int k = 0; k < size; k++) {
                // Don't need to check for current points
                if (k == i || k == j) {
                    continue;
                }

                currentSide = getSideOfPoint(l, points[k]);

                if (!isSameSign(currentSide, previousSide)) {
                    isValidPair = FALSE;
                    break;
                }

                previousSide = currentSide;
            }

            if (isValidPair) {
                addToConvexHullPoints(points[i]);
                addToConvexHullPoints(points[j]);
            }
        }
    }
}


int main(int argc, char *argv[]) {
    char line[256];
    FILE *fp;
    int numPoints = 0;
    double numA = 0;
    double numB = 0;
    struct timeval startTime, endTime;

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

    bruteConvexHull(points, numPoints);

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

void addToConvexHullPoints(Point p) {
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