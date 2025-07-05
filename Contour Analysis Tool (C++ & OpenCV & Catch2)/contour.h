#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

/**
 * @brief A class containing functions for contour analysis
 */
class Contour {
public:

    /**
    * @brief Checks whether the given contour is closed
    * @param contour A vector of contour points
    * @return True if the contour is closed, false otherwise
    * @throws std::invalid_argument if the contour is empty or has only one point
    */
    static bool isClosed(const std::vector<cv::Point>& contour);

    /**
    * @brief Calculates the center point of the contour
    * @param contour A vector of contour points
    * @return The center point of the contour
    * @throws std::invalid_argument if the contour is empty
    */
    static cv::Point centerPoint(const std::vector<cv::Point>& contour);

    /**
    * @brief Calculates the area of the contour
    * @param contour A vector of contour points
    * @return The area of the contour
    * @throws std::invalid_argument if the contour is empty or has only one point
    */
    static double area(const std::vector<cv::Point>& contour);

    /**
    * @brief Calculates the perimeter (arc length) of the contour
    * @param contour A vector of contour points
    * @return The perimeter of the contour
    * @throws std::invalid_argument if the contour is empty or has only one point
    */
    static double perimeter(const std::vector<cv::Point>& contour);
};

