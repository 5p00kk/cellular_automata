#include "rule_bin.h"

c_rule_bin::c_rule_bin(uint16_t rule_number)
{
    m_rule_type = e_rule_type::bin;
    set_rule(rule_number);
}

void c_rule_bin::set_rule(uint16_t rule_number)
{
    for(int i=7;i>=0;i--)
    {
        m_rule[i] = rule_number%2;
        rule_number /= 2;
    }

    /* A bit of hack here as in Wolfram's book 0 is white */
    for(int i=0;i<8;i++)
    {
        if(m_rule[i] == 0)
            m_rule[i] = 1;
        else
            m_rule[i] = 0;
    }
}

uint8_t c_rule_bin::get_rule_case(uint8_t rule_case) const
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

void c_rule_bin::print_rule() const
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

void c_rule_bin::print_cell(bool full) const
{
    const char cell_val = full ? 'x':'o';
    printf("%c", cell_val);
}
