#pragma once

#include "rule_i.h"

/* 
    TODO
    For now this cant inherit from rule interface 
    as methods use different types for cont
*/
class c_rule_cont
{
    public:
        c_rule_cont(float add_value);
        void set_rule(float add_value);
        float get_rule_case(float left_cell, float center_cell, float right_cell) const;
        void print_rule() const;
};