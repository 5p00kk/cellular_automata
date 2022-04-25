#include "rule_cont.h"

c_rule_cont::c_rule_cont(float add_value)
{
    m_rule_type = e_rule_type::cont;
    set_rule(add_value);
}

void c_rule_cont::set_rule(float add_value)
{
    m_add_value = add_value;
}

float c_rule_cont::get_rule_case(float left_cell, float center_cell, float right_cell) const
{
    float avg = right_cell + center_cell + left_cell;
    float sum = avg+m_add_value;
    float fract = (sum - floor(sum));
    return fract;
}

void c_rule_cont::print_rule() const
{
    printf("\nCurrent rule (continuous):\n");
    printf("f(l,c,r)=fract(avg(l+c+r)+%f)\n", m_add_value);
}