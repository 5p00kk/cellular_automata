#include "rule_i.h"

class c_rule_bin: public i_rule
{
    public:
        c_rule_bin(uint16_t rule_number);
        void set_rule(uint16_t rule_number) override;
        uint8_t get_rule_case(uint8_t left_cell, uint8_t center_cell, uint8_t right_cell) const override;
        void print_rule() const override;
    private:
        void print_cell(bool full) const;
};