#include "rule_2d.h"


c_rule_2d::c_rule_2d(uint16_t rule)
{
    m_rule_type = e_rule_type::twod;
    set_rule(rule);
}

void c_rule_2d::set_rule(uint16_t rule)
{
    return;
}

uint8_t c_rule_2d::get_rule_case(uint8_t left_cell, uint8_t center_cell, uint8_t right_cell) const
{
    return 0;
}

void c_rule_2d::print_rule() const
{
    return;
}