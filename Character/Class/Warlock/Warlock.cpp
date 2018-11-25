#include "Warlock.h"

#include "CharacterStats.h"
#include "EnabledBuffs.h"
#include "EnabledProcs.h"
#include "Equipment.h"
#include "Mana.h"
#include "WarlockSpells.h"
#include "Weapon.h"

Warlock::Warlock(Race* race, EquipmentDb *equipment_db, SimSettings *sim_settings) :
    Character(race, sim_settings) {
    available_races.append("Gnome");
    available_races.append("Human");
    available_races.append("Orc");
    available_races.append("Undead");

    this->cstats = new CharacterStats(this, equipment_db);

    this->warlock_spells = new WarlockSpells(this);
    this->spells = dynamic_cast<Spells*>(warlock_spells);

    this->mana = new class Mana(this);
    this->resource = this->mana;
}

Warlock::~Warlock()
{
    cstats->get_equipment()->unequip_all();
    enabled_buffs->clear_all();
    enabled_procs->clear_all();

    delete cstats;
    delete warlock_spells;
    delete mana;
}

QString Warlock::get_name() const {
    return "Warlock";
}

QString Warlock::get_class_color() const {
    return "#9482C9";
}

int Warlock::get_strength_modifier() const {
    return 0;
}

int Warlock::get_agility_modifier() const {
    return 0;
}

int Warlock::get_stamina_modifier() const {
    return 1;
}

int Warlock::get_intellect_modifier() const {
    return 2;
}

int Warlock::get_spirit_modifier() const {
    return 2;
}

double Warlock::get_agi_needed_for_one_percent_phys_crit() const {
    return std::numeric_limits<double>::max();
}

double Warlock::get_int_needed_for_one_percent_spell_crit() const {
    return 60.6;
}

int Warlock::get_ap_per_strength() const {
    return 1;
}

int Warlock::get_ap_per_agi() const {
    return 1;
}

double Warlock::global_cooldown() const {
    return 1.5;
}

void Warlock::initialize_talents() {

}

unsigned Warlock::get_resource_level(const ResourceType) const {
    return mana->current;
}

int Warlock::get_highest_possible_armor_type() const {
    return ArmorTypes::CLOTH;
}

QVector<int> Warlock::get_weapon_proficiencies_for_slot(const int slot) const {
    switch (slot) {
    case EquipmentSlot::MAINHAND:
        return QVector<int>({WeaponTypes::DAGGER, WeaponTypes::SWORD, WeaponTypes::STAFF});
    case EquipmentSlot::OFFHAND:
        return QVector<int>({WeaponTypes::CASTER_OFFHAND});
    case EquipmentSlot::RANGED:
        return QVector<int>({WeaponTypes::WAND});
    default:
        assert(false);
        return QVector<int>();
    }
}

void Warlock::reset_class_specific() {

}
