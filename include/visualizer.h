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
        void visualize(const cv::Mat &world, cv::Mat &visuals) const;
        void set_mode(e_visu mode);
        void add_color_mapping(uint8_t val, s_color color);
        void add_gray_mapping(uint8_t val, uint8_t grayscale);
    private:
        void visualize_gray(const cv::Mat &world, cv::Mat &visuals) const;
        void visualize_col(const cv::Mat &world, cv::Mat &visuals) const;
        e_visu m_mode = e_visu::gray;
        std::array<uint8_t, 256> m_gray_map;
        std::array<s_color, 256> m_color_map;
};