#include <stdio.h>
#include <opencv2/core/mat.hpp>

int main()
{
    /* Create the world */
    cv::Mat world = cv::Mat::zeros(100, 100, CV_8UC1);
    
    /* Printouts */
    printf("\nStarting cellular automata\n");
    printf("World size: %d, %d\n", world.cols, world.rows);
    printf("\n");
}