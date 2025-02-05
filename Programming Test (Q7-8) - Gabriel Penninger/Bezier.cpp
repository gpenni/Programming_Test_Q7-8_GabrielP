#include "Bezier.h"

// Bezier interpolation using De Casteljau’s algorithm
Vector3 bezierInterpolation(const std::vector<Vector3>& points, float t) {
    if (points.empty()) {
        std::cerr << "Error: No control points provided.\n";
        return Vector3();
    }

    if (points.size() == 1) {
        return points[0]; // If only one point, return it
    }

    int n = points.size() - 1;
    std::vector<Vector3> temp = points;

    // Perform De Casteljau’s Algorithm
    for (int r = 1; r <= n; ++r) {
        for (int i = 0; i <= n - r; ++i) {
            temp[i] = temp[i] * (1 - t) + temp[i + 1] * t;
        }
    }

    return temp[0]; // Return the final interpolated point
}

void plotBezierCurve(const std::vector<Vector3>& controlPoints) {
    const int width = 60;
    const int height = 30;
    char grid[height][width];

    // Initialize grid with spaces
    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x)
            grid[y][x] = ' ';

    // Find min and max x and y to normalize scaling
    float minX = controlPoints[0].x, maxX = controlPoints[0].x;
    float minY = controlPoints[0].y, maxY = controlPoints[0].y;
    for (const auto& point : controlPoints) {
        minX = std::min(minX, point.x);
        maxX = std::max(maxX, point.x);
        minY = std::min(minY, point.y);
        maxY = std::max(maxY, point.y);
    }

    // Scale function with clamping
    auto scale = [&](float val, float min, float max, int size) {
        return std::max(0, std::min(size - 1, static_cast<int>(((val - min) / (max - min)) * (size - 1))));
        };

    // Plot Bezier curve
    for (float t = 0; t <= 1.0f; t += 0.01f) {  // Smaller step for smoother curve
        Vector3 point = bezierInterpolation(controlPoints, t);
        int x = scale(point.x, minX, maxX, width);
        int y = scale(point.y, minY, maxY, height);

        if (grid[height - 1 - y][x] != 'C')  // Ensure control points remain visible
            grid[height - 1 - y][x] = '*';  // Curve points are '*'
    }

    // Display the grid
    std::cout << "\nBezier Curve Visualization:\n";
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << grid[y][x];
        }
        std::cout << std::endl;
    }
}