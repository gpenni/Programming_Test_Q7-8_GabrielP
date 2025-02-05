// Programming Test (Q7-8) - Gabriel Penninger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Bezier.h"
#include <vector>

int main() {
    // Define control points
    std::vector<Vector3> controlPoints = {
        Vector3(1, 0, 1),
        Vector3(0, 2, 5),
        Vector3(-2, 3, 7),
        Vector3(-5, 5, 3),
        Vector3(-6, 8, 1),
        Vector3(-9, 8, -1)
    };

    // Edge case: No points
    if (controlPoints.empty()) {
        std::cerr << "No control points provided. Exiting.\n";
        return 1;
    }

    // Edge case: Only one point
    if (controlPoints.size() == 1) {
        std::cout << "Single control point: ";
        controlPoints[0].print();
        std::cout << std::endl;
        return 0;
    }

    // Compute and print Bezier points
    std::cout << "Bezier Curve Points:\n";

    for (float t = 0; t <= 1.0f; t += 0.1f) {
        Vector3 result = bezierInterpolation(controlPoints, t);
        std::cout << "t = " << t << " -> ";
        result.print();
        std::cout << std::endl;
    }

    // Ensure final point is included separately
    Vector3 finalPoint = bezierInterpolation(controlPoints, 1.0f);
    std::cout << "t = 1 -> ";
    finalPoint.print();
    std::cout << std::endl;

    // Visualize the Bezier curve on the console
    plotBezierCurve(controlPoints);

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
