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
    /* placeholder */
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
    m_color_map.insert(std::pair<uint8_t, s_color>(val, color));
}

void c_visualizer::add_bw_mapping(uint8_t val, uint8_t bw)
{
    m_bw_map.insert(std::pair<uint8_t, uint8_t>(val, bw));
}