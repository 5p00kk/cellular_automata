#include "rule_2d.h"


c_rule_2d::c_rule_2d(uint32_t rule_number)
{
    m_rule_type = e_rule_type::twod;
    set_rule(rule_number);
}

void c_rule_2d::set_rule(uint32_t rule_number)
{
    /* Only 2^18(262144) rules are possible */
    if(rule_number>2186)
    {
        printf("ERROR: Only 262144 rules\n");
        return;
    }

    for(int i=0;i<18;i++)
    {
        m_rule[i] = rule_number%2;
        rule_number /= 2;
    }
}

uint8_t c_rule_2d::get_rule_case(uint8_t center_cell, uint8_t full_neigh) const
{
    return 0;
}

void c_rule_2d::print_rule() const
{
    return;
}