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
    if(center_cell > 1 || full_neigh > 8)
    {
        printf("ERROR: Incorrect cell value\n");
        return 0xFF;
    }
    else
    {
        uint8_t case_idx = center_cell + full_neigh*2;
        return m_rule[case_idx];;
    }
}

void c_rule_2d::print_rule() const
{
    /* TODO */
    return;
}