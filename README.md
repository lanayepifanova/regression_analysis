# Simple Linear Regression in C++

This repository contains a simple C++ implementation of linear regression.

## Usage

1.  **Compile:**
    ```bash
    g++ regression.cpp -o regression
    ```
2.  **Run:**
    ```bash
    ./regression
    ```

The program will output the slope (m) and intercept (b) of the linear regression line.

## Functionality

The `linearRegression` function takes two `std::vector<double>` arguments, `x` and `y`, representing the input data points. It returns a `std::pair<double, double>` containing the slope and intercept of the best-fit line.

```cpp
std::pair<double, double> linearRegression(const std::vector<double>& x, const std::vector<double>& y);
