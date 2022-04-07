#include "rule.h"

#include <stdio.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>

int main()
{
    /* Create the world */
    cv::Mat world = cv::Mat::ones(501, 1001, CV_8UC1) * 255;
    world.at<uint8_t>(0, 500) = 0;

    /* Printouts */
    printf("\nStarting cellular automata\n");
    printf("World size: %d, %d\n", world.cols, world.rows);

   
    /* Define a rule */
    /* 
    For 3 cells into 1 type of rules, a full rule can be encoded as 
    a single 8bit int.
    */
    /*
    Rule 30
    0 -> 1
    1 -> 1
    2 -> 1
    3 -> 0
    4 -> 0
    5 -> 0
    6 -> 0
    7 -> 1
    */

    c_rule rule;
    rule.set_rule(1,1,1,0,1,0,0,1);
    rule.set_rule_type(e_rule_type::bin);
    rule.print_rule();
    
    printf("Applying rules\n");

    /* Go row by row and apply rules */
    for(int row = 0; row < world.rows; row++)
    {
        /* 1 to world.cols-1 to avoid reading from outside of the edge 
           as col is the central pixel of 3 */
        for(int col = 1; col < world.cols-1; col++)
        {
            /* Reached the last row */
            if(row+1 > world.rows-1) break;
            
            uint8_t left_cell = world.at<uint8_t>(row,col-1);
            uint8_t central_cell = world.at<uint8_t>(row,col);
            uint8_t right_cell = world.at<uint8_t>(row,col+1);
           
            uint8_t rule_idx = ((right_cell   & 0x01) * 1) +  
                               ((central_cell & 0x01) * 2) +
                               ((left_cell    & 0x01) * 4);
            
            /* Apply the rule */
            world.at<uint8_t>(row+1,col) = rule.get_rule_case(rule_idx)*255;
        }
    }

    printf("Saving image\n");
    cv::imwrite("output.png", world);

    printf("\n");
}