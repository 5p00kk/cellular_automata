#include "visualizer.h"

/*!
    \brief Create a visualization image <visuals> for input world state <world>
    \param world State of the world after running the cellular automata
    \param visuals Output visualization image based on world state
    \note The result (grayscale or RGB visualization) will depend on mode selected by <set_mode>
*/
void c_visualizer::visualize(const cv::Mat &world, cv::Mat &visuals) const
{
    if(m_mode == e_visu::gray)
    {
        visualize_gray(world, visuals);
    }
    else if(m_mode == e_visu::col)
    {
        visualize_col(world, visuals);
    }
}


/*!
    \brief
    Create a visualization image <visuals> for input world state <world>.
    The result is a grayscale visualization
    \param world State of the world after running the cellular automata
    \param visuals Output visualization image (grayscale) based on world state
*/
void c_visualizer::visualize_gray(const cv::Mat &world, cv::Mat &visuals) const
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
            visuals.at<uint8_t>(row,col) = m_gray_map[world.at<uint8_t>(row,col)];
        }
    }
}


/*!
    \brief
    Create a visualization image <visuals> for input world state <world>.
    The result is a RGB visualization
    \param world State of the world after running the cellular automata
    \param visuals Output visualization image (RGB) based on world state
*/
void c_visualizer::visualize_col(const cv::Mat &world, cv::Mat &visuals) const
{
    /* Allocate correct mat if needed */
    if(visuals.rows != world.rows ||
       visuals.cols != world.cols ||
       visuals.type() != CV_8UC3)
    {
        visuals.create(world.rows, world.cols, CV_8UC3);
    }

    for(int row = 0; row < world.rows; row++)
    {
        for(int col = 0; col < world.cols; col++)
        {
            s_color color = m_color_map[world.at<uint8_t>(row,col)];
            visuals.at<cv::Vec3b>(row,col)[0] = color.b;
            visuals.at<cv::Vec3b>(row,col)[1] = color.g;
            visuals.at<cv::Vec3b>(row,col)[2] = color.r;
        }
    }
}


/*!
    \brief
    Select the mode of operation.
    \param mode Operation mode (grayscale or RGB)
*/
void c_visualizer::set_mode(e_visu mode)
{
    m_mode = mode;
}


/*!
    \brief
    Add mapping between world values and output RGB color
    \param val world value
    \param color corresponding output RGB color
    \note Valid ONLY for RGB mode 
*/
void c_visualizer::add_color_mapping(uint8_t val, s_color color)
{
    m_color_map[val] = color;
}


/*!
    \brief
    Add mapping between world values and output grayscale value
    \param val world value
    \param color corresponding output grayscale color
    \note Valid ONLY for grayscale mode 
*/
void c_visualizer::add_gray_mapping(uint8_t val, uint8_t grayscale)
{
    m_gray_map[val] = grayscale;
}