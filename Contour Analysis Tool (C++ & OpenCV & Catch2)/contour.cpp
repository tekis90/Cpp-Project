#include <vector>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "contour.h"

bool Contour::isClosed(const std::vector<cv::Point>& contour) {
    if (contour.empty()) {
        throw std::invalid_argument("Contour cannot be empty.");
    }
    if (contour.size() == 1) {
        throw std::invalid_argument("Single-point contour has zero area.");
    }
    if (cv::contourArea(contour) > 0 && contour.front() == contour.back()) {
        std::cerr << "isClosed() -- Closed" << std::endl;
        return true;
    }
    std::cerr << "isClosed() -- Open" << std::endl;
    return false;
}

cv::Point Contour::centerPoint(const std::vector<cv::Point>& contour) {
    if (contour.empty()) {
        throw std::invalid_argument("Contour cannot be empty.");
    }
    cv::Moments m = cv::moments(contour);
    if (m.m00 == 0) return cv::Point(0, 0);
    return cv::Point(static_cast<int>(m.m10 / m.m00), static_cast<int>(m.m01 / m.m00));
}

double Contour::area(const std::vector<cv::Point>& contour) {
    if (contour.empty()) {
        throw std::invalid_argument("Contour cannot be empty.");
    }
    if (contour.size() == 1) {
        throw std::invalid_argument("Single-point contour has zero area.");
    }
    return cv::contourArea(contour);
}

double Contour::perimeter(const std::vector<cv::Point>& contour) {
    if (contour.empty()) {
        throw std::invalid_argument("Contour cannot be empty.");
    }
    if (contour.size() == 1) {
        throw std::invalid_argument("Single-point contour has no length.");
    }
    return cv::arcLength(contour, true);
}
