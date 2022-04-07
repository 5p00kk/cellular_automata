#include "rule_tct.h"

c_rule_tct::c_rule_tct(uint16_t rule_number)
{
    m_rule_type = e_rule_type::tct;
    set_rule(rule_number);
}

void c_rule_tct::set_rule(uint16_t rule_number)
{
    /* TODO check if numbe rtoo large */
    for(int i=0;i<8;i++)
    {
        m_rule[i] = rule_number%3;
        rule_number /= 3;
    }
}

uint8_t c_rule_tct::get_rule_case(uint8_t left_cell, uint8_t center_cell, uint8_t right_cell) const
{
    if(left_cell > 2 || center_cell > 2 || right_cell > 2)
    {
        printf("ERROR: Incorrect cell value\n");
        return 0xFF;
    }
    else
    {
        uint8_t case_idx = right_cell + center_cell + left_cell;
        return m_rule[case_idx];
    }

}

void c_rule_tct::print_rule() const
{
    printf("\nCurrent rule (tri color totalistic):\n");
    printf("o - empty cell, x - full cell\n");

    printf("empty (0)\n");
    for (const auto& elem : m_rule)
    {
        /* get index */
        auto i = &elem - &m_rule[0];
        printf("case %ld: ", i);
        printf("avg cell fullness: %f ", (float)i*(1.0/3.0));
        printf(" -> %d\n", elem);
     }
    printf("full (2)\n");
}