#include "rule_2d.h"
#include "visualizer.h"

#include <stdio.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>

int main()
{
    /* Simulation constants */
    const uint16_t iterations = 100;

    /* Create the world */
    uint8_t current_world = 0;
    cv::Mat world[2];
    world[0] = cv::Mat::zeros(800, 800, CV_8UC1);
    world[1] = cv::Mat::zeros(800, 800, CV_8UC1);
    world[current_world].at<uint8_t>(400, 400) = 1;

    /* Printouts */
    printf("\nStarting cellular automata\n");
    printf("World size: %d, %d\n", world[0].cols, world[0].rows);

    /* Define a rule */
    c_rule_2d rule(30);
    rule.print_rule();
    
    // /* Apply the rule line by line */
    // printf("Applying the rule\n");
    // for(int row = 0; row < world.rows; row++)
    // {
    //     /* 1 to world.cols-1 to avoid reading from outside of the edge 
    //        as col is the central pixel of 3 */
    //     for(int col = 1; col < world.cols-1; col++)
    //     {
    //         /* Reached the last row */
    //         if(row+1 > world.rows-1) break;
           
    //         uint8_t left_cell = world.at<uint8_t>(row,col-1);
    //         uint8_t center_cell = world.at<uint8_t>(row,col);
    //         uint8_t right_cell = world.at<uint8_t>(row,col+1);
            
    //         /* Apply the rule */
    //         world.at<uint8_t>(row+1,col) = rule.get_rule_case(left_cell, center_cell, right_cell);
    //     }
    // }

    /* Visualize */
    /* 
        Full cells have value 1 
        Empty cells have value 0
        Visualization step makes sure a proper output image is generated
        to follow Wolfram's convention full - black, empty - white
    */
    printf("Visualizing output\n");
    cv::Mat world_visu;
    c_visualizer visualizer;
    visualizer.set_mode(e_visu::gray);
    visualizer.add_gray_mapping(0, 255);
    visualizer.add_gray_mapping(1, 0);
    visualizer.visualize(world[0], world_visu);

    /* Save output */
    printf("Saving image\n");
    cv::imwrite("output.png", world_visu);
}