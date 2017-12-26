#ifndef SHAMAN_H
#define SHAMAN_H

#include "Class.h"

class Shaman: public Class {
public:
    std::string get_name() const override;
    int get_strength_modifier() const override;
    int get_agility_modifier() const override;
    int get_stamina_modifier() const override;
    int get_intellect_modifier() const override;
    int get_spirit_modifier() const override;
    void rotation() const override;

protected:
private:
};

#endif // SHAMAN_H
