#pragma once

#include <opencv2/core/mat.hpp>
#include <array>

enum class e_visu {gray, col};

struct s_color
{
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
};

class c_visualizer
{
    public:
        /*!
            \brief Create a visualization image <visuals> for input world state <world>
            \param world State of the world after running the cellular automata
            \param visuals Output visualization image based on world state
            \note The result (grayscale or RGB visualization) will depend on mode selected by <set_mode>
        */
        void visualize(const cv::Mat &world, cv::Mat &visuals) const;
        
        /*!
            \brief
            Select the mode of operation.
            \param mode Operation mode (grayscale or RGB)
        */
        void set_mode(e_visu mode);
        
        /*!
            \brief
            Add mapping between world values and output RGB color
            \param val world value
            \param color corresponding output RGB color
            \note Valid ONLY for RGB mode 
        */
        void add_color_mapping(uint8_t val, s_color color);
        
        /*!
            \brief
            Add mapping between world values and output grayscale value
            \param val world value
            \param color corresponding output grayscale color
            \note Valid ONLY for grayscale mode 
        */
        void add_gray_mapping(uint8_t val, uint8_t grayscale);
    private:
        /*!
            \brief
            Create a visualization image <visuals> for input world state <world>.
            The result is a grayscale visualization
            \param world State of the world after running the cellular automata
            \param visuals Output visualization image (grayscale) based on world state
        */
        void visualize_gray(const cv::Mat &world, cv::Mat &visuals) const;
        
        /*!
            \brief
            Create a visualization image <visuals> for input world state <world>.
            The result is a RGB visualization
            \param world State of the world after running the cellular automata
            \param visuals Output visualization image (RGB) based on world state
        */
        void visualize_col(const cv::Mat &world, cv::Mat &visuals) const;
  
        /* Member variables */
        e_visu m_mode = e_visu::gray;
        std::array<uint8_t, 256> m_gray_map;
        std::array<s_color, 256> m_color_map;
};