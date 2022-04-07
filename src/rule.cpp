#include "rule.h"

void c_rule::set_rule(uint8_t r_0, uint8_t r_1,
                      uint8_t r_2, uint8_t r_3,
                      uint8_t r_4, uint8_t r_5,
                      uint8_t r_6, uint8_t r_7)
{
    m_rule[0] = r_0;
    m_rule[1] = r_1;
    m_rule[2] = r_2;
    m_rule[3] = r_3;
    m_rule[4] = r_4;
    m_rule[5] = r_5;
    m_rule[6] = r_6;
    m_rule[7] = r_7;
}

uint8_t c_rule::get_rule_case(uint8_t rule_case) const
{
    if(rule_case >= m_rule.size())
    {
        printf("ERROR: Incorrect rule case");
        return 0xFF;
    }
    else
    {
        return m_rule[rule_case];
    }

}

void c_rule::set_rule_type(e_rule_type rule_type)
{
    m_rule_type = rule_type;
}

void c_rule::print_rule() const
{
    printf("\nCurrent rule:\n");

    for (const auto& elem : m_rule)
    {
        /* get index */
        auto i = &elem - &m_rule[0];
        print_cell(i&0x04);
        print_cell(i&0x02);
        print_cell(i&0x01);
        printf(" -> ");
        print_cell(elem&0x01);
        printf("\n");
    }
    printf("\n");
}

void c_rule::print_cell(bool full) const
{
    const char cell_val = full ? 'x':'o';
    printf("%c", cell_val);
}
