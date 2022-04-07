#include "rule_bin.h"

c_rule_bin::c_rule_bin(uint16_t rule_number)
{
    m_rule_type = e_rule_type::bin;
    set_rule(rule_number);
}

void c_rule_bin::set_rule(uint16_t rule_number)
{
    for(int i=0;i<8;i++)
    {
        m_rule[i] = rule_number%2;
        rule_number /= 2;
    }
}

uint8_t c_rule_bin::get_rule_case(uint8_t left_cell, uint8_t center_cell, uint8_t right_cell) const
{
    if(left_cell > 1 || center_cell > 1 || right_cell > 1)
    {
        printf("ERROR: Incorrect cell value\n");
        return 0xFF;
    }
    else
    {
        uint8_t case_idx = (right_cell * 1)   +
                           (center_cell * 2) +
                           (left_cell * 4);
        return m_rule[case_idx];
    }

}

void c_rule_bin::print_rule() const
{
    printf("\nCurrent rule (binary rule):\n");
    printf("o - empty cell, x - full cell\n");

    for (const auto& elem : m_rule)
    {
        /* get index */
        auto i = &elem - &m_rule[0];
        printf("case %ld: ", i);
        print_cell(i&0x04);
        print_cell(i&0x02);
        print_cell(i&0x01);
        printf(" -> ");
        print_cell(elem&0x01);
        printf("\n");
    }
    printf("\n");
}

void c_rule_bin::print_cell(bool full) const
{
    const char cell_val = full ? 'x':'o';
    printf("%c", cell_val);
}
