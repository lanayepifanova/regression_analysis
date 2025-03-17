// regression.cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

std::pair<double, double> linearRegression(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() != y.size() || x.empty()) {
        return {NAN, NAN}; // Return NaN for invalid input
    }

    int n = x.size();

    double sumX = std::accumulate(x.begin(), x.end(), 0.0);
    double sumY = std::accumulate(y.begin(), y.end(), 0.0);
    double sumXY = 0.0;
    double sumX2 = 0.0;

    for (int i = 0; i < n; ++i) {
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double meanX = sumX / n;
    double meanY = sumY / n;

    double numerator = sumXY - n * meanX * meanY;
    double denominator = sumX2 - n * meanX * meanX;

    if (denominator == 0) {
      return {NAN, NAN}; // Return NaN if denominator is zero (perfect vertical line)
    }

    double slope = numerator / denominator;
    double intercept = meanY - slope * meanX;

    return {slope, intercept};
}

int main() {
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::vector<double> y = {2, 3, 5, 6, 8};

    std::pair<double, double> result = linearRegression(x, y);

    if (std::isnan(result.first) || std::isnan(result.second)) {
        std::cerr << "Error: Regression failed. Check input data.\n";
    } else {
        std::cout << "Slope (m): " << result.first << std::endl;
        std::cout << "Intercept (b): " << result.second << std::endl;
    }

    return 0;
}
