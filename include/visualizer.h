#pragma once

#include <opencv2/core/mat.hpp>
#include <map>

enum class e_visu {bw, col};

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
        void add_bw_mapping(uint8_t val, uint8_t bw);
    private:
        void visualize_bw(const cv::Mat &world, cv::Mat &visuals) const;
        void visualize_col(const cv::Mat &world, cv::Mat &visuals) const;
        e_visu m_mode = e_visu::bw;
        std::map<uint8_t, uint8_t> m_bw_map{};
        std::map<uint8_t, s_color> m_color_map{};
};