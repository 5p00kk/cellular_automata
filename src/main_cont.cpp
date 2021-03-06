#include "rule_cont.h"

#include <stdio.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <time.h>

int main()
{
    std::srand((unsigned)time(NULL));

    /* Create the world */
    cv::Mat world = cv::Mat::zeros(800, 800, CV_32FC1);
    /* Random initalizaiton of the first row */
    for(int i=1; i<800; i++)
    {
        float value = ((float)std::rand())/RAND_MAX;
        printf("value: %f\n", value);
        world.at<float>(0, i) = value;
    }

    /* Printouts */
    printf("\nStarting cellular automata\n");
    printf("World size: %d, %d\n", world.cols, world.rows);

    /* Define a rule */
    c_rule_cont rule(0.9);
    rule.print_rule();

    /* Apply the rule line by line */
    printf("Applying the rule\n");
    for(int row = 0; row < world.rows; row++)
    {
        /* 1 to world.cols-1 to avoid reading from outside of the edge 
           as col is the central pixel of 3 */
        for(int col = 1; col < world.cols-1; col++)
        {
            /* Reached the last row */
            if(row+1 > world.rows-1) break;
           
            float left_cell = world.at<float>(row,col-1);
            float center_cell = world.at<float>(row,col);
            float right_cell = world.at<float>(row,col+1);
            
            /* Apply the rule */
            world.at<float>(row+1,col) = rule.get_rule_case(left_cell, center_cell, right_cell);
        }
    }

    /* Save output */
    printf("Saving image\n");
    cv::imwrite("output.png", world*255.0);
}