// Author: Abinav Bukkaraya
// ID: 0951030
// Brute Force Implementation of Convex Hull Problem

#include <stdio.h>

#define NUM_AXES 2
#define TRUE 1
#define FALSE 0

double getSideOfPoint(double a, double b, double c, double x, double y) {
    return (a*x) + (b*y) - c;
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


int bruteConvexHull(double points[][2], int size) {
    int validPairs[size][2];
    int totalPairs = 0;

    int totalSegmentsEvaluated = 0;

    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            // Compute Coefficients
            // a = y_2 - y_1
            // b = x_1 - x_2
            // c = x_1 * y_2 - x_2 * y_1
            double previousSide = 0;
            double currentSide = 0;

            int isValidPair = TRUE;

            double a = points[j][1] - points[i][1];
            double b = points[i][0] - points[j][0];
            double c = (points[i][0] * points[j][1]) - (points[i][1] * points[j][0]);


            for(int k = 0; k < size; k++) {
                // Don't need to check for current points
                if (k == i || k == j) {
                    continue;
                }

                currentSide = getSideOfPoint(a, b, c, points[k][0], points[k][1]);

                if (!isSameSign(currentSide, previousSide)) {
                    isValidPair = FALSE;
                    break;
                } 

                previousSide = currentSide;
            }

            if (isValidPair) {
                
                printf("a: %f, b: %f, c: %f\n", a, b, c);
                printf("X1: %f, Y1: %f\n", points[i][0], points[i][1]);
                printf("X2: %f, Y2: %f\n", points[j][0], points[j][1]);
                totalPairs++;
            }

            totalSegmentsEvaluated++;
        }
    }
}


int main() {
    int size = 2;
    double points[8][2] = {{0, 0}, {4, 4}};
    
    // {{0, 3}, {1, 1}, {2, 2}, {4, 4},
    //                 {0, 0}, {1, 2}, {3, 1}, {3, 3}};


    bruteConvexHull(points, size);

    return 0;
}