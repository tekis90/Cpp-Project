#define CATCH_CONFIG_MAIN
#include <vector>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "contour.h"
#include "catch.hpp"

TEST_CASE("Closed contour test", "[contour]") {
    std::vector<cv::Point> square = {
        {0,0}, {0,10}, {10,10}, {10,0}, {0,0}
    };
    REQUIRE(Contour::isClosed(square) == true);

    std::vector<cv::Point> openContour = {
        {0,0}, {0,10}, {10,10}, {10,0}
    };
    REQUIRE_FALSE(Contour::isClosed(openContour));

    REQUIRE_THROWS_AS(
        Contour::isClosed(std::vector<cv::Point>{}), // Empty contour
        std::invalid_argument
    );
}

TEST_CASE("Center point test", "[contour]") {
    std::vector<cv::Point> triangle = {
        {0, 0}, {10, 0}, {5, 10}
    };
    auto center = Contour::centerPoint(triangle);
    REQUIRE(center.x > 0);
    REQUIRE(center.y > 0);
}
