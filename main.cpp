#include <stdio.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>

void print_cell(bool full)
{
    const char cell_val = full ? 'x':'o';
    printf("%c", cell_val);
}

void print_rule(const std::array<uint8_t, 8> &rule)
{
    printf("\nCurrent rule:\n");
    for (const auto& elem : rule)
    {
        /* get index */
        auto i = &elem - &rule[0];
        print_cell(i&0x04);
        print_cell(i&0x02);
        print_cell(i&0x01);
        printf(" -> ");
        print_cell(elem&0x01);
        printf("\n");
    }
    printf("\n");
}


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
    1 -> 0
    2 -> 0
    3 -> 0
    4 -> 0
    5 -> 1
    6 -> 1
    7 -> 1
    */
    std::array<uint8_t, 8> rule = {1,0,0,0,0,1,1,1};
    print_rule(rule);

    for(int row = 0; row < world.rows-10; row++)
    {
        for(int col = 0; col < world.cols; col++)
        {
            world.at<char>(row,col) = 255;
        }
    }

    printf("Saving image\n");
    cv::imwrite("output.png", world);

    printf("\n");
}