#pragma once

#include <array>
#include <stdint.h>

/*
bin - simple binary rule
tct - three color totallistic rule
cont - continuous rule
*/
enum class e_rule_type {bin, tct, cont};

class i_rule
{
    public:
        virtual void set_rule(uint16_t rule_number) = 0;
        virtual uint8_t get_rule_case(uint8_t left_cell, uint8_t center_cell, uint8_t right_cell) const = 0;
        virtual void print_rule() const = 0;
    protected:
        std::array<uint8_t, 8> m_rule;
        e_rule_type m_rule_type;
};