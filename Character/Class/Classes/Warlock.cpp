
#include "Warlock.h"

std::string Warlock::get_name(void) const {
    return "Warlock";
}

int Warlock::get_strength_modifier(void) const {
    return 0;
}

int Warlock::get_agility_modifier(void) const {
    return 0;
}

int Warlock::get_stamina_modifier(void) const {
    return 1;
}

int Warlock::get_intellect_modifier(void) const {
    return 2;
}

int Warlock::get_spirit_modifier(void) const {
    return 2;
}

void Warlock::rotation() const {
    return;
}
