#include <array>
#include <stdint.h>

/*
bin - simple binary rule
tct - three color totallistic rule
*/
enum class e_rule_type {bin, tct};

class c_rule
{
    public:
        void set_rule(uint8_t r_0, uint8_t r_1,
                      uint8_t r_2, uint8_t r_3,
                      uint8_t r_4, uint8_t r_5,
                      uint8_t r_6, uint8_t r_7);
        void set_rule_type(e_rule_type rule_type);
        uint8_t get_rule_case(uint8_t rule_case) const;
        void print_rule() const;
    private:
        std::array<uint8_t, 8> m_rule;
        e_rule_type m_rule_type;
        void print_cell(bool full) const;
};