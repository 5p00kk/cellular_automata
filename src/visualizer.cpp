#include "visualizer.h"

void c_visualizer::visualize(const cv::Mat &world, cv::Mat &visuals) const
{
    if(m_mode == e_visu::bw)
    {
        visualize_bw(world, visuals);
    }
    else if(m_mode == e_visu::col)
    {
        visualize_col(world, visuals);
    }
}

void c_visualizer::visualize_bw(const cv::Mat &world, cv::Mat &visuals) const
{
    /* Allocate correct mat if needed */
    if(visuals.rows != world.rows ||
       visuals.cols != world.cols ||
       visuals.type() != CV_8UC1)
    {
        visuals.create(world.rows, world.cols, CV_8UC1);
    }

    for(int row = 0; row < world.rows; row++)
    {
        for(int col = 0; col < world.cols; col++)
        {
            visuals.at<uint8_t>(row,col) = m_bw_map[world.at<uint8_t>(row,col)];
        }
    }
}

void c_visualizer::visualize_col(const cv::Mat &world, cv::Mat &visuals) const
{
    /* placeholder */
}

void c_visualizer::set_mode(e_visu mode)
{
    m_mode = mode;
}

void c_visualizer::add_color_mapping(uint8_t val, s_color color)
{
    m_color_map[val] = color;
}

void c_visualizer::add_bw_mapping(uint8_t val, uint8_t bw)
{
    m_bw_map[val] = bw;
}