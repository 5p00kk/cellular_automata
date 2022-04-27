#pragma once

#include "rule_i.h"

/* 
    TODO
    For now this cant inherit from rule interface 
    as methods use different types for cont
*/
class c_rule_2d
{
    public:
        c_rule_2d(uint16_t rule);
        void set_rule(uint16_t rule);
        uint8_t get_rule_case(uint8_t left_cell, uint8_t center_cell, uint8_t right_cell) const;
        void print_rule() const;
    private:
        e_rule_type m_rule_type;
};