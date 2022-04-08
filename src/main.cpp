#include "rule_bin.h"
#include "rule_tct.h"

#include <stdio.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>

int main()
{
    /* Create the world */
    cv::Mat world = cv::Mat::zeros(501, 1001, CV_8UC1);
    cv::Mat world_visu = cv::Mat::zeros(501, 1001, CV_8UC1);
    world.at<uint8_t>(0, 500) = 1;

    /* Printouts */
    printf("\nStarting cellular automata\n");
    printf("World size: %d, %d\n", world.cols, world.rows);

    /* Define a rule */
    c_rule_bin rule(30);
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
           
            uint8_t left_cell = world.at<uint8_t>(row,col-1);
            uint8_t center_cell = world.at<uint8_t>(row,col);
            uint8_t right_cell = world.at<uint8_t>(row,col+1);
            
            /* Apply the rule */
            world.at<uint8_t>(row+1,col) = rule.get_rule_case(left_cell, center_cell, right_cell);
        }
    }

    /* Visualize */
    /* 
        Full cells have value 1 
        Empty cells have value 0
        Visualization step makes sure a proper output image is generated
        to follow Wolfram's convention full - black, empty - white
    */
    printf("Visualizing output\n");
    for(int row = 0; row < world.rows; row++)
    {
        for(int col = 0; col < world.cols; col++)
        {
            if(world.at<uint8_t>(row,col) == 0)
            {
                world_visu.at<uint8_t>(row,col) = 255;
            }
            else
            {
                world_visu.at<uint8_t>(row,col) = 0;
            }
        }
    }

    /* Save output */
    printf("Saving image\n");
    cv::imwrite("output.png", world_visu);

    printf("\n");
}