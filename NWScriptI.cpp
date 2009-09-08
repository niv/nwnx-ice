// Generated on Tue Sep 08 21:46:55 +0200 2009 from /home/elven/code/nwnx2-linux/trunk/plugins/ice/build/funcs.nss

#include "NWScriptI.h"
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <stdlib.h>
#include <math.h>

using namespace std;

NWScriptI::NWScriptI() {
  callCounter = 0;
  contextDepth = 0;
  lastEffectId = 0;
  lastIprpId = 0;
  printEvents = false;
}

void NWScriptI::resetPerEventMappings() {
  effectMap.clear();
  iprpMap.clear();
}

void NWScriptI::lock(IceUtil::Mutex& m, const char* name) {
  if (0 == contextDepth)
    throw NWN::NotInContextException();
#ifdef LOCK_DEBUG
  cout << "lock(" << name << ");" << endl;
#endif
#ifndef LOCK_DISABLE
  m.lock();
#endif
}

void NWScriptI::unlock(IceUtil::Mutex& m, const char* name) {
#ifdef LOCK_DEBUG
  cout << "unlock(" << name << ");" << endl;
#endif
#ifndef LOCK_DISABLE
  m.unlock();
#endif
}

void NWScriptI::innerLock(const char* name) {
#ifdef LOCK_DEBUG
  cout << "innerLock()" << endl;
#endif
}

void NWScriptI::innerUnlock(const char* name) {
#ifdef LOCK_DEBUG
  cout << "innerUnlock()" << endl;
#endif
}
long NWScriptI::enum_EffectType_2_long(NWN::EffectType k) {
  if (k == NWN::TemporaryHitpointsEffect) return 9;
  if (k == NWN::ACDecreaseEffect) return 47;
  if (k == NWN::DazedEffect) return 28;
  if (k == NWN::TimestopEffect) return 66;
  if (k == NWN::SwarmEffect) return 76;
  if (k == NWN::ImprovedInvisibilityEffect) return 57;
  if (k == NWN::InvalidEffect) return 0;
  if (k == NWN::AbilityIncreaseEffect) return 38;
  if (k == NWN::MovementSpeedIncreaseEffect) return 48;
  if (k == NWN::StunnedEffect) return 29;
  if (k == NWN::BlindnessEffect) return 67;
  if (k == NWN::TurnResistanceDecreaseEffect) return 77;
  if (k == NWN::AreaOfEffectEffect) return 20;
  if (k == NWN::DarknessEffect) return 58;
  if (k == NWN::DamageResistanceEffect) return 1;
  if (k == NWN::AbilityDecreaseEffect) return 39;
  if (k == NWN::SleepEffect) return 30;
  if (k == NWN::SpellLevelAbsorptionEffect) return 68;
  if (k == NWN::EntangleEffect) return 11;
  if (k == NWN::MovementSpeedDecreaseEffect) return 49;
  if (k == NWN::TurnResistanceIncreaseEffect) return 78;
  if (k == NWN::BeamEffect) return 21;
  if (k == NWN::DispelMagicAllEffect) return 59;
  if (k == NWN::AttackIncreaseEffect) return 40;
  if (k == NWN::PoisonEffect) return 31;
  if (k == NWN::DispelMagicBestEffect) return 69;
  if (k == NWN::InvulnerableEffect) return 12;
  if (k == NWN::SavingThrowIncreaseEffect) return 50;
  if (k == NWN::PetrifyEffect) return 79;
  if (k == NWN::RegenerateEffect) return 3;
  if (k == NWN::AttackDecreaseEffect) return 41;
  if (k == NWN::ElementalShieldEffect) return 60;
  if (k == NWN::DiseaseEffect) return 32;
  if (k == NWN::UltravisionEffect) return 70;
  if (k == NWN::DeafEffect) return 13;
  if (k == NWN::SavingThrowDecreaseEffect) return 51;
  if (k == NWN::CutsceneParalyzeEffect) return 80;
  if (k == NWN::DamageIncreaseEffect) return 42;
  if (k == NWN::CharmedEffect) return 23;
  if (k == NWN::NegativeLevelEffect) return 61;
  if (k == NWN::ResurrectionEffect) return 14;
  if (k == NWN::SpellResistanceIncreaseEffect) return 52;
  if (k == NWN::CurseEffect) return 33;
  if (k == NWN::MissChanceEffect) return 71;
  if (k == NWN::EtherealEffect) return 81;
  if (k == NWN::DamageDecreaseEffect) return 43;
  if (k == NWN::ConfusedEffect) return 24;
  if (k == NWN::PolymorphEffect) return 62;
  if (k == NWN::ImmunityEffect) return 15;
  if (k == NWN::SpellResistanceDecreaseEffect) return 53;
  if (k == NWN::SilenceEffect) return 34;
  if (k == NWN::ConcealmentEffect) return 72;
  if (k == NWN::SpellFailureEffect) return 82;
  if (k == NWN::FrightenedEffect) return 25;
  if (k == NWN::SanctuaryEffect) return 63;
  if (k == NWN::DamageImmunityIncreaseEffect) return 44;
  if (k == NWN::SkillIncreaseEffect) return 54;
  if (k == NWN::TurnedEffect) return 35;
  if (k == NWN::SpellImmunityEffect) return 73;
  if (k == NWN::CutsceneGhostEffect) return 83;
  if (k == NWN::DominatedEffect) return 26;
  if (k == NWN::TrueSeeingEffect) return 64;
  if (k == NWN::DamageReductionEffect) return 7;
  if (k == NWN::DamageImmunityDecreaseEffect) return 45;
  if (k == NWN::HasteEffect) return 36;
  if (k == NWN::VisualEffect) return 74;
  if (k == NWN::EnemyAttackBonusEffect) return 17;
  if (k == NWN::SkillDecreaseEffect) return 55;
  if (k == NWN::CutsceneImmobilizeEffect) return 84;
  if (k == NWN::SeeInvisibleEffect) return 65;
  if (k == NWN::ACIncreaseEffect) return 46;
  if (k == NWN::ParalyzeEffect) return 27;
  if (k == NWN::DisappearAppearEffect) return 75;
  if (k == NWN::SlowEffect) return 37;
  if (k == NWN::ArcaneSpellFailureEffect) return 18;
  if (k == NWN::InvisibilityEffect) return 56;
  throw "omg";
};
NWN::EffectType NWScriptI::enum_long_2_EffectType(long v) {
  if (v == 9) return NWN::TemporaryHitpointsEffect;
  if (v == 47) return NWN::ACDecreaseEffect;
  if (v == 28) return NWN::DazedEffect;
  if (v == 66) return NWN::TimestopEffect;
  if (v == 76) return NWN::SwarmEffect;
  if (v == 57) return NWN::ImprovedInvisibilityEffect;
  if (v == 0) return NWN::InvalidEffect;
  if (v == 38) return NWN::AbilityIncreaseEffect;
  if (v == 48) return NWN::MovementSpeedIncreaseEffect;
  if (v == 29) return NWN::StunnedEffect;
  if (v == 67) return NWN::BlindnessEffect;
  if (v == 77) return NWN::TurnResistanceDecreaseEffect;
  if (v == 20) return NWN::AreaOfEffectEffect;
  if (v == 58) return NWN::DarknessEffect;
  if (v == 1) return NWN::DamageResistanceEffect;
  if (v == 39) return NWN::AbilityDecreaseEffect;
  if (v == 30) return NWN::SleepEffect;
  if (v == 68) return NWN::SpellLevelAbsorptionEffect;
  if (v == 11) return NWN::EntangleEffect;
  if (v == 49) return NWN::MovementSpeedDecreaseEffect;
  if (v == 78) return NWN::TurnResistanceIncreaseEffect;
  if (v == 21) return NWN::BeamEffect;
  if (v == 59) return NWN::DispelMagicAllEffect;
  if (v == 40) return NWN::AttackIncreaseEffect;
  if (v == 31) return NWN::PoisonEffect;
  if (v == 69) return NWN::DispelMagicBestEffect;
  if (v == 12) return NWN::InvulnerableEffect;
  if (v == 50) return NWN::SavingThrowIncreaseEffect;
  if (v == 79) return NWN::PetrifyEffect;
  if (v == 3) return NWN::RegenerateEffect;
  if (v == 41) return NWN::AttackDecreaseEffect;
  if (v == 60) return NWN::ElementalShieldEffect;
  if (v == 32) return NWN::DiseaseEffect;
  if (v == 70) return NWN::UltravisionEffect;
  if (v == 13) return NWN::DeafEffect;
  if (v == 51) return NWN::SavingThrowDecreaseEffect;
  if (v == 80) return NWN::CutsceneParalyzeEffect;
  if (v == 42) return NWN::DamageIncreaseEffect;
  if (v == 23) return NWN::CharmedEffect;
  if (v == 61) return NWN::NegativeLevelEffect;
  if (v == 14) return NWN::ResurrectionEffect;
  if (v == 52) return NWN::SpellResistanceIncreaseEffect;
  if (v == 33) return NWN::CurseEffect;
  if (v == 71) return NWN::MissChanceEffect;
  if (v == 81) return NWN::EtherealEffect;
  if (v == 43) return NWN::DamageDecreaseEffect;
  if (v == 24) return NWN::ConfusedEffect;
  if (v == 62) return NWN::PolymorphEffect;
  if (v == 15) return NWN::ImmunityEffect;
  if (v == 53) return NWN::SpellResistanceDecreaseEffect;
  if (v == 34) return NWN::SilenceEffect;
  if (v == 72) return NWN::ConcealmentEffect;
  if (v == 82) return NWN::SpellFailureEffect;
  if (v == 25) return NWN::FrightenedEffect;
  if (v == 63) return NWN::SanctuaryEffect;
  if (v == 44) return NWN::DamageImmunityIncreaseEffect;
  if (v == 54) return NWN::SkillIncreaseEffect;
  if (v == 35) return NWN::TurnedEffect;
  if (v == 73) return NWN::SpellImmunityEffect;
  if (v == 83) return NWN::CutsceneGhostEffect;
  if (v == 26) return NWN::DominatedEffect;
  if (v == 64) return NWN::TrueSeeingEffect;
  if (v == 7) return NWN::DamageReductionEffect;
  if (v == 45) return NWN::DamageImmunityDecreaseEffect;
  if (v == 36) return NWN::HasteEffect;
  if (v == 74) return NWN::VisualEffect;
  if (v == 17) return NWN::EnemyAttackBonusEffect;
  if (v == 55) return NWN::SkillDecreaseEffect;
  if (v == 84) return NWN::CutsceneImmobilizeEffect;
  if (v == 65) return NWN::SeeInvisibleEffect;
  if (v == 46) return NWN::ACIncreaseEffect;
  if (v == 27) return NWN::ParalyzeEffect;
  if (v == 75) return NWN::DisappearAppearEffect;
  if (v == 37) return NWN::SlowEffect;
  if (v == 18) return NWN::ArcaneSpellFailureEffect;
  if (v == 56) return NWN::InvisibilityEffect;
  printf("Invalid enum value of type EffectType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_Weather_2_long(NWN::Weather k) {
  if (k == NWN::ClearWeather) return 0;
  if (k == NWN::RainWeather) return 1;
  if (k == NWN::InvalidWeather) return -1;
  if (k == NWN::SnowWeather) return 2;
  if (k == NWN::AreaDefaultsWeather) return 3;
  throw "omg";
};
NWN::Weather NWScriptI::enum_long_2_Weather(long v) {
  if (v == 0) return NWN::ClearWeather;
  if (v == 1) return NWN::RainWeather;
  if (v == -1) return NWN::InvalidWeather;
  if (v == 2) return NWN::SnowWeather;
  if (v == 3) return NWN::AreaDefaultsWeather;
  printf("Invalid enum value of type Weather passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_TileSourceLightColor_2_long(NWN::TileSourceLightColor k) {
  if (k == NWN::PaleGreenTileSourceLightColor) return 5;
  if (k == NWN::PalePurpleTileSourceLightColor) return 11;
  if (k == NWN::BlackTileSourceLightColor) return 0;
  if (k == NWN::PaleDarkAquaTileSourceLightColor) return 6;
  if (k == NWN::PaleDarkRedTileSourceLightColor) return 12;
  if (k == NWN::WhiteTileSourceLightColor) return 1;
  if (k == NWN::PaleAquaTileSourceLightColor) return 7;
  if (k == NWN::PaleRedTileSourceLightColor) return 13;
  if (k == NWN::PaleDarkYellowTileSourceLightColor) return 2;
  if (k == NWN::PaleDarkBlueTileSourceLightColor) return 8;
  if (k == NWN::PaleDarkOrangeTileSourceLightColor) return 14;
  if (k == NWN::PaleYellowTileSourceLightColor) return 3;
  if (k == NWN::PaleBlueTileSourceLightColor) return 9;
  if (k == NWN::PaleOrangeTileSourceLightColor) return 15;
  if (k == NWN::PaleDarkGreenTileSourceLightColor) return 4;
  if (k == NWN::PaleDarkPurpleTileSourceLightColor) return 10;
  throw "omg";
};
NWN::TileSourceLightColor NWScriptI::enum_long_2_TileSourceLightColor(long v) {
  if (v == 5) return NWN::PaleGreenTileSourceLightColor;
  if (v == 11) return NWN::PalePurpleTileSourceLightColor;
  if (v == 0) return NWN::BlackTileSourceLightColor;
  if (v == 6) return NWN::PaleDarkAquaTileSourceLightColor;
  if (v == 12) return NWN::PaleDarkRedTileSourceLightColor;
  if (v == 1) return NWN::WhiteTileSourceLightColor;
  if (v == 7) return NWN::PaleAquaTileSourceLightColor;
  if (v == 13) return NWN::PaleRedTileSourceLightColor;
  if (v == 2) return NWN::PaleDarkYellowTileSourceLightColor;
  if (v == 8) return NWN::PaleDarkBlueTileSourceLightColor;
  if (v == 14) return NWN::PaleDarkOrangeTileSourceLightColor;
  if (v == 3) return NWN::PaleYellowTileSourceLightColor;
  if (v == 9) return NWN::PaleBlueTileSourceLightColor;
  if (v == 15) return NWN::PaleOrangeTileSourceLightColor;
  if (v == 4) return NWN::PaleDarkGreenTileSourceLightColor;
  if (v == 10) return NWN::PaleDarkPurpleTileSourceLightColor;
  printf("Invalid enum value of type TileSourceLightColor passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_StandardFaction_2_long(NWN::StandardFaction k) {
  if (k == NWN::Hostile) return 0;
  if (k == NWN::Commoner) return 1;
  if (k == NWN::Merchant) return 2;
  if (k == NWN::Defender) return 3;
  throw "omg";
};
NWN::StandardFaction NWScriptI::enum_long_2_StandardFaction(long v) {
  if (v == 0) return NWN::Hostile;
  if (v == 1) return NWN::Commoner;
  if (v == 2) return NWN::Merchant;
  if (v == 3) return NWN::Defender;
  printf("Invalid enum value of type StandardFaction passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_SavingThrowResult_2_long(NWN::SavingThrowResult k) {
  if (k == NWN::FailedRoll) return 0;
  if (k == NWN::SucceededRoll) return 1;
  if (k == NWN::ImmuneToSaveType) return 3;
  throw "omg";
};
NWN::SavingThrowResult NWScriptI::enum_long_2_SavingThrowResult(long v) {
  if (v == 0) return NWN::FailedRoll;
  if (v == 1) return NWN::SucceededRoll;
  if (v == 3) return NWN::ImmuneToSaveType;
  printf("Invalid enum value of type SavingThrowResult passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_Action_2_long(NWN::Action k) {
  if (k == NWN::AnimalEmpathyAction) return 16;
  if (k == NWN::OpenDoorAction) return 5;
  if (k == NWN::HealAction) return 33;
  if (k == NWN::ExamineTrapAction) return 11;
  if (k == NWN::MoveToPointAction) return 0;
  if (k == NWN::RestAction) return 17;
  if (k == NWN::CloseDoorAction) return 6;
  if (k == NWN::PickpocketAction) return 34;
  if (k == NWN::SetTrapAction) return 12;
  if (k == NWN::PickupItemAction) return 1;
  if (k == NWN::SmiteGoodAction) return 40;
  if (k == NWN::TauntAction) return 18;
  if (k == NWN::DialogObjectAction) return 7;
  if (k == NWN::FollowAction) return 35;
  if (k == NWN::OpenLockAction) return 13;
  if (k == NWN::DropItemAction) return 2;
  if (k == NWN::InvalidAction) return 65535;
  if (k == NWN::KIDamageAction) return 41;
  if (k == NWN::ItemCastSpellAction) return 19;
  if (k == NWN::DisableTrapAction) return 8;
  if (k == NWN::WaitAction) return 36;
  if (k == NWN::LockAction) return 14;
  if (k == NWN::AttackObjectAction) return 3;
  if (k == NWN::CounterSpellAction) return 31;
  if (k == NWN::RecoverTrapAction) return 9;
  if (k == NWN::SitAction) return 37;
  if (k == NWN::UseObjectAction) return 15;
  if (k == NWN::CastSpellAction) return 4;
  if (k == NWN::RandomWalkAction) return 43;
  if (k == NWN::FlagTrapAction) return 10;
  throw "omg";
};
NWN::Action NWScriptI::enum_long_2_Action(long v) {
  if (v == 16) return NWN::AnimalEmpathyAction;
  if (v == 5) return NWN::OpenDoorAction;
  if (v == 33) return NWN::HealAction;
  if (v == 11) return NWN::ExamineTrapAction;
  if (v == 0) return NWN::MoveToPointAction;
  if (v == 17) return NWN::RestAction;
  if (v == 6) return NWN::CloseDoorAction;
  if (v == 34) return NWN::PickpocketAction;
  if (v == 12) return NWN::SetTrapAction;
  if (v == 1) return NWN::PickupItemAction;
  if (v == 40) return NWN::SmiteGoodAction;
  if (v == 18) return NWN::TauntAction;
  if (v == 7) return NWN::DialogObjectAction;
  if (v == 35) return NWN::FollowAction;
  if (v == 13) return NWN::OpenLockAction;
  if (v == 2) return NWN::DropItemAction;
  if (v == 65535) return NWN::InvalidAction;
  if (v == 41) return NWN::KIDamageAction;
  if (v == 19) return NWN::ItemCastSpellAction;
  if (v == 8) return NWN::DisableTrapAction;
  if (v == 36) return NWN::WaitAction;
  if (v == 14) return NWN::LockAction;
  if (v == 3) return NWN::AttackObjectAction;
  if (v == 31) return NWN::CounterSpellAction;
  if (v == 9) return NWN::RecoverTrapAction;
  if (v == 37) return NWN::SitAction;
  if (v == 15) return NWN::UseObjectAction;
  if (v == 4) return NWN::CastSpellAction;
  if (v == 43) return NWN::RandomWalkAction;
  if (v == 10) return NWN::FlagTrapAction;
  printf("Invalid enum value of type Action passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_ACModifyType_2_long(NWN::ACModifyType k) {
  if (k == NWN::ACDodgeBonus) return 0;
  if (k == NWN::ACNaturalBonus) return 1;
  if (k == NWN::ACArmorEnchantmentBonus) return 2;
  if (k == NWN::ACShieldEnchantmentBonus) return 3;
  if (k == NWN::ACDeflectionBonus) return 4;
  throw "omg";
};
NWN::ACModifyType NWScriptI::enum_long_2_ACModifyType(long v) {
  if (v == 0) return NWN::ACDodgeBonus;
  if (v == 1) return NWN::ACNaturalBonus;
  if (v == 2) return NWN::ACArmorEnchantmentBonus;
  if (v == 3) return NWN::ACShieldEnchantmentBonus;
  if (v == 4) return NWN::ACDeflectionBonus;
  printf("Invalid enum value of type ACModifyType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_Gender_2_long(NWN::Gender k) {
  if (k == NWN::MaleGender) return 0;
  if (k == NWN::Female) return 1;
  if (k == NWN::BothGender) return 2;
  if (k == NWN::OtherGender) return 3;
  if (k == NWN::NoneGender) return 4;
  throw "omg";
};
NWN::Gender NWScriptI::enum_long_2_Gender(long v) {
  if (v == 0) return NWN::MaleGender;
  if (v == 1) return NWN::Female;
  if (v == 2) return NWN::BothGender;
  if (v == 3) return NWN::OtherGender;
  if (v == 4) return NWN::NoneGender;
  printf("Invalid enum value of type Gender passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_IPRacialType_2_long(NWN::IPRacialType k) {
  if (k == NWN::ElementalIPRace) return 16;
  if (k == NWN::HalforcIPRace) return 5;
  if (k == NWN::DragonIPRace) return 11;
  if (k == NWN::DwarfIPRace) return 0;
  if (k == NWN::FeyIPRace) return 17;
  if (k == NWN::HumanIPRace) return 6;
  if (k == NWN::ShapechangerIPRace) return 23;
  if (k == NWN::HumanoidGoblinoidIPRace) return 12;
  if (k == NWN::ElfIPRace) return 1;
  if (k == NWN::GiantIPRace) return 18;
  if (k == NWN::AberrationIPRace) return 7;
  if (k == NWN::UndeadIPRace) return 24;
  if (k == NWN::HumanoidMonstrousIPRace) return 13;
  if (k == NWN::GnomeIPRace) return 2;
  if (k == NWN::MagicalBeastIPRace) return 19;
  if (k == NWN::AnimalIPRace) return 8;
  if (k == NWN::VerminIPRace) return 25;
  if (k == NWN::HumanoidOrcIPRace) return 14;
  if (k == NWN::HalflingIPRace) return 3;
  if (k == NWN::OutsiderIPRace) return 20;
  if (k == NWN::BeastIPRace) return 9;
  if (k == NWN::HumanoidReptilianIPRace) return 15;
  if (k == NWN::HalfelfIPRace) return 4;
  if (k == NWN::ConstructIPRace) return 10;
  throw "omg";
};
NWN::IPRacialType NWScriptI::enum_long_2_IPRacialType(long v) {
  if (v == 16) return NWN::ElementalIPRace;
  if (v == 5) return NWN::HalforcIPRace;
  if (v == 11) return NWN::DragonIPRace;
  if (v == 0) return NWN::DwarfIPRace;
  if (v == 17) return NWN::FeyIPRace;
  if (v == 6) return NWN::HumanIPRace;
  if (v == 23) return NWN::ShapechangerIPRace;
  if (v == 12) return NWN::HumanoidGoblinoidIPRace;
  if (v == 1) return NWN::ElfIPRace;
  if (v == 18) return NWN::GiantIPRace;
  if (v == 7) return NWN::AberrationIPRace;
  if (v == 24) return NWN::UndeadIPRace;
  if (v == 13) return NWN::HumanoidMonstrousIPRace;
  if (v == 2) return NWN::GnomeIPRace;
  if (v == 19) return NWN::MagicalBeastIPRace;
  if (v == 8) return NWN::AnimalIPRace;
  if (v == 25) return NWN::VerminIPRace;
  if (v == 14) return NWN::HumanoidOrcIPRace;
  if (v == 3) return NWN::HalflingIPRace;
  if (v == 20) return NWN::OutsiderIPRace;
  if (v == 9) return NWN::BeastIPRace;
  if (v == 15) return NWN::HumanoidReptilianIPRace;
  if (v == 4) return NWN::HalfelfIPRace;
  if (v == 10) return NWN::ConstructIPRace;
  printf("Invalid enum value of type IPRacialType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_PlaceableAction_2_long(NWN::PlaceableAction k) {
  if (k == NWN::UsePlaceable) return 0;
  if (k == NWN::UnlockPlaceable) return 1;
  if (k == NWN::BashPlaceable) return 2;
  if (k == NWN::KnockPlaceable) return 4;
  throw "omg";
};
NWN::PlaceableAction NWScriptI::enum_long_2_PlaceableAction(long v) {
  if (v == 0) return NWN::UsePlaceable;
  if (v == 1) return NWN::UnlockPlaceable;
  if (v == 2) return NWN::BashPlaceable;
  if (v == 4) return NWN::KnockPlaceable;
  printf("Invalid enum value of type PlaceableAction passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_Ability_2_long(NWN::Ability k) {
  if (k == NWN::Charisma) return 5;
  if (k == NWN::Strength) return 0;
  if (k == NWN::Dexterity) return 1;
  if (k == NWN::Constitution) return 2;
  if (k == NWN::Intelligence) return 3;
  if (k == NWN::Wisdom) return 4;
  throw "omg";
};
NWN::Ability NWScriptI::enum_long_2_Ability(long v) {
  if (v == 5) return NWN::Charisma;
  if (v == 0) return NWN::Strength;
  if (v == 1) return NWN::Dexterity;
  if (v == 2) return NWN::Constitution;
  if (v == 3) return NWN::Intelligence;
  if (v == 4) return NWN::Wisdom;
  printf("Invalid enum value of type Ability passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_IPSpellSchool_2_long(NWN::IPSpellSchool k) {
  if (k == NWN::IllusionIPSchool) return 5;
  if (k == NWN::AbjurationIPSchool) return 0;
  if (k == NWN::NecromancyIPSchool) return 6;
  if (k == NWN::ConjurationIPSchool) return 1;
  if (k == NWN::TransmutationIPSchool) return 7;
  if (k == NWN::DivinationIPSchool) return 2;
  if (k == NWN::EnchantmentIPSchool) return 3;
  if (k == NWN::EvocationIPSchool) return 4;
  throw "omg";
};
NWN::IPSpellSchool NWScriptI::enum_long_2_IPSpellSchool(long v) {
  if (v == 5) return NWN::IllusionIPSchool;
  if (v == 0) return NWN::AbjurationIPSchool;
  if (v == 6) return NWN::NecromancyIPSchool;
  if (v == 1) return NWN::ConjurationIPSchool;
  if (v == 7) return NWN::TransmutationIPSchool;
  if (v == 2) return NWN::DivinationIPSchool;
  if (v == 3) return NWN::EnchantmentIPSchool;
  if (v == 4) return NWN::EvocationIPSchool;
  printf("Invalid enum value of type IPSpellSchool passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_IPAlignGroup_2_long(NWN::IPAlignGroup k) {
  if (k == NWN::EvilAlignGroup) return 5;
  if (k == NWN::AllAlignGroup) return 0;
  if (k == NWN::NeutralAlignGroup) return 1;
  if (k == NWN::LawfulAlignGroup) return 2;
  if (k == NWN::ChaoticAlignGroup) return 3;
  if (k == NWN::GoodAlignGroup) return 4;
  throw "omg";
};
NWN::IPAlignGroup NWScriptI::enum_long_2_IPAlignGroup(long v) {
  if (v == 5) return NWN::EvilAlignGroup;
  if (v == 0) return NWN::AllAlignGroup;
  if (v == 1) return NWN::NeutralAlignGroup;
  if (v == 2) return NWN::LawfulAlignGroup;
  if (v == 3) return NWN::ChaoticAlignGroup;
  if (v == 4) return NWN::GoodAlignGroup;
  printf("Invalid enum value of type IPAlignGroup passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_EffectSubType_2_long(NWN::EffectSubType k) {
  if (k == NWN::SupernaturalSubType) return 16;
  if (k == NWN::InvalidSubType) return 0;
  if (k == NWN::ExtraordinarySubType) return 24;
  if (k == NWN::MagicalSubType) return 8;
  throw "omg";
};
NWN::EffectSubType NWScriptI::enum_long_2_EffectSubType(long v) {
  if (v == 16) return NWN::SupernaturalSubType;
  if (v == 0) return NWN::InvalidSubType;
  if (v == 24) return NWN::ExtraordinarySubType;
  if (v == 8) return NWN::MagicalSubType;
  printf("Invalid enum value of type EffectSubType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_TileMainLightColor_2_long(NWN::TileMainLightColor k) {
  if (k == NWN::RedTileMainLightColor) return 27;
  if (k == NWN::PaleDarkBlueTileMainLightColor) return 16;
  if (k == NWN::DarkYellowTileMainLightColor) return 5;
  if (k == NWN::PalePurpleTileMainLightColor) return 22;
  if (k == NWN::GreenTileMainLightColor) return 11;
  if (k == NWN::BlackTileMainLightColor) return 0;
  if (k == NWN::PaleDarkOrangeTileMainLightColor) return 28;
  if (k == NWN::DarkBlueTileMainLightColor) return 17;
  if (k == NWN::PaleYellowTileMainLightColor) return 6;
  if (k == NWN::PurpleTileMainLightColor) return 23;
  if (k == NWN::PaleDarkAquaTileMainLightColor) return 12;
  if (k == NWN::DimWhiteTileMainLightColor) return 1;
  if (k == NWN::DarkOrangeTileMainLightColor) return 29;
  if (k == NWN::PaleBlueTileMainLightColor) return 18;
  if (k == NWN::YellowTileMainLightColor) return 7;
  if (k == NWN::PaleDarkRedTileMainLightColor) return 24;
  if (k == NWN::DarkAquaTileMainLightColor) return 13;
  if (k == NWN::WhiteTileMainLightColor) return 2;
  if (k == NWN::PaleOrangeTileMainLightColor) return 30;
  if (k == NWN::BlueTileMainLightColor) return 19;
  if (k == NWN::PaleDarkGreenTileMainLightColor) return 8;
  if (k == NWN::DarkRedTileMainLightColor) return 25;
  if (k == NWN::PaleAquaTileMainLightColor) return 14;
  if (k == NWN::BrightWhiteTileMainLightColor) return 3;
  if (k == NWN::OrangeTileMainLightColor) return 31;
  if (k == NWN::PaleDarkPurpleTileMainLightColor) return 20;
  if (k == NWN::DarkGreenTileMainLightColor) return 9;
  if (k == NWN::PaleRedTileMainLightColor) return 26;
  if (k == NWN::AquaTileMainLightColor) return 15;
  if (k == NWN::PaleDarkYellowTileMainLightColor) return 4;
  if (k == NWN::DarkPurpleTileMainLightColor) return 21;
  if (k == NWN::PaleGreenTileMainLightColor) return 10;
  throw "omg";
};
NWN::TileMainLightColor NWScriptI::enum_long_2_TileMainLightColor(long v) {
  if (v == 27) return NWN::RedTileMainLightColor;
  if (v == 16) return NWN::PaleDarkBlueTileMainLightColor;
  if (v == 5) return NWN::DarkYellowTileMainLightColor;
  if (v == 22) return NWN::PalePurpleTileMainLightColor;
  if (v == 11) return NWN::GreenTileMainLightColor;
  if (v == 0) return NWN::BlackTileMainLightColor;
  if (v == 28) return NWN::PaleDarkOrangeTileMainLightColor;
  if (v == 17) return NWN::DarkBlueTileMainLightColor;
  if (v == 6) return NWN::PaleYellowTileMainLightColor;
  if (v == 23) return NWN::PurpleTileMainLightColor;
  if (v == 12) return NWN::PaleDarkAquaTileMainLightColor;
  if (v == 1) return NWN::DimWhiteTileMainLightColor;
  if (v == 29) return NWN::DarkOrangeTileMainLightColor;
  if (v == 18) return NWN::PaleBlueTileMainLightColor;
  if (v == 7) return NWN::YellowTileMainLightColor;
  if (v == 24) return NWN::PaleDarkRedTileMainLightColor;
  if (v == 13) return NWN::DarkAquaTileMainLightColor;
  if (v == 2) return NWN::WhiteTileMainLightColor;
  if (v == 30) return NWN::PaleOrangeTileMainLightColor;
  if (v == 19) return NWN::BlueTileMainLightColor;
  if (v == 8) return NWN::PaleDarkGreenTileMainLightColor;
  if (v == 25) return NWN::DarkRedTileMainLightColor;
  if (v == 14) return NWN::PaleAquaTileMainLightColor;
  if (v == 3) return NWN::BrightWhiteTileMainLightColor;
  if (v == 31) return NWN::OrangeTileMainLightColor;
  if (v == 20) return NWN::PaleDarkPurpleTileMainLightColor;
  if (v == 9) return NWN::DarkGreenTileMainLightColor;
  if (v == 26) return NWN::PaleRedTileMainLightColor;
  if (v == 15) return NWN::AquaTileMainLightColor;
  if (v == 4) return NWN::PaleDarkYellowTileMainLightColor;
  if (v == 21) return NWN::DarkPurpleTileMainLightColor;
  if (v == 10) return NWN::PaleGreenTileMainLightColor;
  printf("Invalid enum value of type TileMainLightColor passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_DamagePower_2_long(NWN::DamagePower k) {
  if (k == NWN::PlusFifteenDamage) return 16;
  if (k == NWN::PlusFiveDamage) return 5;
  if (k == NWN::PlusTenDamage) return 11;
  if (k == NWN::NormalDamage) return 0;
  if (k == NWN::PlusSixteenDamage) return 17;
  if (k == NWN::EnergyDamage) return 6;
  if (k == NWN::PlusElevenDamage) return 12;
  if (k == NWN::PlusOneDamage) return 1;
  if (k == NWN::PlusSeventeenDamage) return 18;
  if (k == NWN::PlusSixDamage) return 7;
  if (k == NWN::PlusTwelveDamage) return 13;
  if (k == NWN::PlusTwoDamage) return 2;
  if (k == NWN::PlusEighteenDamage) return 19;
  if (k == NWN::PlusSevenDamage) return 8;
  if (k == NWN::PlusThirteenDamage) return 14;
  if (k == NWN::PlusThreeDamage) return 3;
  if (k == NWN::PlusNinteenDamage) return 20;
  if (k == NWN::PlusEightDamage) return 9;
  if (k == NWN::PlusFourteenDamage) return 15;
  if (k == NWN::PlusFourDamage) return 4;
  if (k == NWN::PlusTwentyDamage) return 21;
  if (k == NWN::PlusNineDamage) return 10;
  throw "omg";
};
NWN::DamagePower NWScriptI::enum_long_2_DamagePower(long v) {
  if (v == 16) return NWN::PlusFifteenDamage;
  if (v == 5) return NWN::PlusFiveDamage;
  if (v == 11) return NWN::PlusTenDamage;
  if (v == 0) return NWN::NormalDamage;
  if (v == 17) return NWN::PlusSixteenDamage;
  if (v == 6) return NWN::EnergyDamage;
  if (v == 12) return NWN::PlusElevenDamage;
  if (v == 1) return NWN::PlusOneDamage;
  if (v == 18) return NWN::PlusSeventeenDamage;
  if (v == 7) return NWN::PlusSixDamage;
  if (v == 13) return NWN::PlusTwelveDamage;
  if (v == 2) return NWN::PlusTwoDamage;
  if (v == 19) return NWN::PlusEighteenDamage;
  if (v == 8) return NWN::PlusSevenDamage;
  if (v == 14) return NWN::PlusThirteenDamage;
  if (v == 3) return NWN::PlusThreeDamage;
  if (v == 20) return NWN::PlusNinteenDamage;
  if (v == 9) return NWN::PlusEightDamage;
  if (v == 15) return NWN::PlusFourteenDamage;
  if (v == 4) return NWN::PlusFourDamage;
  if (v == 21) return NWN::PlusTwentyDamage;
  if (v == 10) return NWN::PlusNineDamage;
  printf("Invalid enum value of type DamagePower passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_DamageType_2_long(NWN::DamageType k) {
  if (k == NWN::AcidDamage) return 16;
  if (k == NWN::ACVsAllDamage) return 4103;
  if (k == NWN::NegativeDamage) return 512;
  if (k == NWN::PositiveDamage) return 1024;
  if (k == NWN::BludgeoningDamage) return 1;
  if (k == NWN::ElectricalDamage) return 128;
  if (k == NWN::SonicDamage) return 2048;
  if (k == NWN::PiercingDamage) return 2;
  if (k == NWN::MagicalDamage) return 8;
  if (k == NWN::FireDamage) return 256;
  if (k == NWN::DivineDamage) return 64;
  if (k == NWN::BaseDamage) return 4096;
  if (k == NWN::SlashingDamage) return 4;
  if (k == NWN::ColdDamage) return 32;
  throw "omg";
};
NWN::DamageType NWScriptI::enum_long_2_DamageType(long v) {
  if (v == 16) return NWN::AcidDamage;
  if (v == 4103) return NWN::ACVsAllDamage;
  if (v == 512) return NWN::NegativeDamage;
  if (v == 1024) return NWN::PositiveDamage;
  if (v == 1) return NWN::BludgeoningDamage;
  if (v == 128) return NWN::ElectricalDamage;
  if (v == 2048) return NWN::SonicDamage;
  if (v == 2) return NWN::PiercingDamage;
  if (v == 8) return NWN::MagicalDamage;
  if (v == 256) return NWN::FireDamage;
  if (v == 64) return NWN::DivineDamage;
  if (v == 4096) return NWN::BaseDamage;
  if (v == 4) return NWN::SlashingDamage;
  if (v == 32) return NWN::ColdDamage;
  printf("Invalid enum value of type DamageType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_SaveType_2_long(NWN::SaveType k) {
  if (k == NWN::GoodSaveType) return 16;
  if (k == NWN::SonicSaveType) return 5;
  if (k == NWN::DeathSaveType) return 11;
  if (k == NWN::AllOrNoneSaveType) return 0;
  if (k == NWN::EvilSaveType) return 17;
  if (k == NWN::AcidSaveType) return 6;
  if (k == NWN::ColdSaveType) return 12;
  if (k == NWN::MindSpellsSaveType) return 1;
  if (k == NWN::LawSaveType) return 18;
  if (k == NWN::FireSaveType) return 7;
  if (k == NWN::DivineSaveType) return 13;
  if (k == NWN::PoisonSaveType) return 2;
  if (k == NWN::ChaosSaveType) return 19;
  if (k == NWN::ElectricitySaveType) return 8;
  if (k == NWN::TrapSaveType) return 14;
  if (k == NWN::DiseaseSaveType) return 3;
  if (k == NWN::PositiveSaveType) return 9;
  if (k == NWN::SpellSaveType) return 15;
  if (k == NWN::FearSaveType) return 4;
  if (k == NWN::NegativeSaveType) return 10;
  throw "omg";
};
NWN::SaveType NWScriptI::enum_long_2_SaveType(long v) {
  if (v == 16) return NWN::GoodSaveType;
  if (v == 5) return NWN::SonicSaveType;
  if (v == 11) return NWN::DeathSaveType;
  if (v == 0) return NWN::AllOrNoneSaveType;
  if (v == 17) return NWN::EvilSaveType;
  if (v == 6) return NWN::AcidSaveType;
  if (v == 12) return NWN::ColdSaveType;
  if (v == 1) return NWN::MindSpellsSaveType;
  if (v == 18) return NWN::LawSaveType;
  if (v == 7) return NWN::FireSaveType;
  if (v == 13) return NWN::DivineSaveType;
  if (v == 2) return NWN::PoisonSaveType;
  if (v == 19) return NWN::ChaosSaveType;
  if (v == 8) return NWN::ElectricitySaveType;
  if (v == 14) return NWN::TrapSaveType;
  if (v == 3) return NWN::DiseaseSaveType;
  if (v == 9) return NWN::PositiveSaveType;
  if (v == 15) return NWN::SpellSaveType;
  if (v == 4) return NWN::FearSaveType;
  if (v == 10) return NWN::NegativeSaveType;
  printf("Invalid enum value of type SaveType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_CombatMode_2_long(NWN::CombatMode k) {
  if (k == NWN::RapidShotCombatMode) return 5;
  if (k == NWN::InvalidCombatMode) return 0;
  if (k == NWN::ExpertiseCombatMode) return 6;
  if (k == NWN::ParryCombatMode) return 1;
  if (k == NWN::ImprovedExpertiseCombatMode) return 7;
  if (k == NWN::PowerAttackCombatMode) return 2;
  if (k == NWN::DefensiveCastingCombatMode) return 8;
  if (k == NWN::ImprovedPowerAttackCombatMode) return 3;
  if (k == NWN::DirtyFightingCombatMode) return 9;
  if (k == NWN::FlurryOfBlowsCombatMode) return 4;
  if (k == NWN::DefensiveStanceCombatMode) return 10;
  throw "omg";
};
NWN::CombatMode NWScriptI::enum_long_2_CombatMode(long v) {
  if (v == 5) return NWN::RapidShotCombatMode;
  if (v == 0) return NWN::InvalidCombatMode;
  if (v == 6) return NWN::ExpertiseCombatMode;
  if (v == 1) return NWN::ParryCombatMode;
  if (v == 7) return NWN::ImprovedExpertiseCombatMode;
  if (v == 2) return NWN::PowerAttackCombatMode;
  if (v == 8) return NWN::DefensiveCastingCombatMode;
  if (v == 3) return NWN::ImprovedPowerAttackCombatMode;
  if (v == 9) return NWN::DirtyFightingCombatMode;
  if (v == 4) return NWN::FlurryOfBlowsCombatMode;
  if (v == 10) return NWN::DefensiveStanceCombatMode;
  printf("Invalid enum value of type CombatMode passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_IPTrapType_2_long(NWN::IPTrapType k) {
  if (k == NWN::FireIPTrap) return 5;
  if (k == NWN::NegativeIPTrap) return 11;
  if (k == NWN::ElectricalIPTrap) return 6;
  if (k == NWN::SpikeIPTrap) return 1;
  if (k == NWN::GasIPTrap) return 7;
  if (k == NWN::HolyIPTrap) return 2;
  if (k == NWN::FrostIPTrap) return 8;
  if (k == NWN::TangleIPTrap) return 3;
  if (k == NWN::AcidSplashIPTrap) return 9;
  if (k == NWN::BlobOfAcidIPTrap) return 4;
  if (k == NWN::SonicIPTrap) return 10;
  throw "omg";
};
NWN::IPTrapType NWScriptI::enum_long_2_IPTrapType(long v) {
  if (v == 5) return NWN::FireIPTrap;
  if (v == 11) return NWN::NegativeIPTrap;
  if (v == 6) return NWN::ElectricalIPTrap;
  if (v == 1) return NWN::SpikeIPTrap;
  if (v == 7) return NWN::GasIPTrap;
  if (v == 2) return NWN::HolyIPTrap;
  if (v == 8) return NWN::FrostIPTrap;
  if (v == 3) return NWN::TangleIPTrap;
  if (v == 9) return NWN::AcidSplashIPTrap;
  if (v == 4) return NWN::BlobOfAcidIPTrap;
  if (v == 10) return NWN::SonicIPTrap;
  printf("Invalid enum value of type IPTrapType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_EffectState_2_long(NWN::EffectState k) {
  if (k == NWN::DazedState) return 5;
  if (k == NWN::StunnedState) return 6;
  if (k == NWN::CharmedState) return 1;
  if (k == NWN::DominatedState) return 7;
  if (k == NWN::ConfusedState) return 2;
  if (k == NWN::ParalyzeState) return 8;
  if (k == NWN::FrightenedState) return 3;
  if (k == NWN::SleepState) return 9;
  if (k == NWN::TurnedState) return 4;
  throw "omg";
};
NWN::EffectState NWScriptI::enum_long_2_EffectState(long v) {
  if (v == 5) return NWN::DazedState;
  if (v == 6) return NWN::StunnedState;
  if (v == 1) return NWN::CharmedState;
  if (v == 7) return NWN::DominatedState;
  if (v == 2) return NWN::ConfusedState;
  if (v == 8) return NWN::ParalyzeState;
  if (v == 3) return NWN::FrightenedState;
  if (v == 9) return NWN::SleepState;
  if (v == 4) return NWN::TurnedState;
  printf("Invalid enum value of type EffectState passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_CreatureSize_2_long(NWN::CreatureSize k) {
  if (k == NWN::HugeSize) return 5;
  if (k == NWN::InvalidSize) return 0;
  if (k == NWN::TinySize) return 1;
  if (k == NWN::SmallSize) return 2;
  if (k == NWN::MediumSize) return 3;
  if (k == NWN::LargeSize) return 4;
  throw "omg";
};
NWN::CreatureSize NWScriptI::enum_long_2_CreatureSize(long v) {
  if (v == 5) return NWN::HugeSize;
  if (v == 0) return NWN::InvalidSize;
  if (v == 1) return NWN::TinySize;
  if (v == 2) return NWN::SmallSize;
  if (v == 3) return NWN::MediumSize;
  if (v == 4) return NWN::LargeSize;
  printf("Invalid enum value of type CreatureSize passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_AssociateCommand_2_long(NWN::AssociateCommand k) {
  if (k == NWN::InventoryCommand) return -19;
  if (k == NWN::UnsummonFamiliarCommand) return -8;
  if (k == NWN::UnpossessFamiliarCommand) return -13;
  if (k == NWN::StandGroundCommand) return -2;
  if (k == NWN::PickLockCommand) return -18;
  if (k == NWN::GuardMasterCommand) return -7;
  if (k == NWN::ToggleSearchCommand) return -23;
  if (k == NWN::ReleaseDominationCommand) return -12;
  if (k == NWN::LeavePartyCommand) return -17;
  if (k == NWN::MasterFailedLockpickCommand) return -6;
  if (k == NWN::ToggleStealthCommand) return -22;
  if (k == NWN::MasterUnderAttackCommand) return -11;
  if (k == NWN::MasterGoingToBeAttackedCommand) return -16;
  if (k == NWN::FollowMasterCommand) return -5;
  if (k == NWN::ToggleCastingCommand) return -21;
  if (k == NWN::UnsummonSummonedCommand) return -10;
  if (k == NWN::MasterAttackedOtherCommand) return -15;
  if (k == NWN::HealMasterCommand) return -4;
  if (k == NWN::DisarmTrapCommand) return -20;
  if (k == NWN::UnsummonAnimalCompanionCommand) return -9;
  if (k == NWN::MasterSawTrapCommand) return -14;
  if (k == NWN::AttackNearestCommand) return -3;
  throw "omg";
};
NWN::AssociateCommand NWScriptI::enum_long_2_AssociateCommand(long v) {
  if (v == -19) return NWN::InventoryCommand;
  if (v == -8) return NWN::UnsummonFamiliarCommand;
  if (v == -13) return NWN::UnpossessFamiliarCommand;
  if (v == -2) return NWN::StandGroundCommand;
  if (v == -18) return NWN::PickLockCommand;
  if (v == -7) return NWN::GuardMasterCommand;
  if (v == -23) return NWN::ToggleSearchCommand;
  if (v == -12) return NWN::ReleaseDominationCommand;
  if (v == -17) return NWN::LeavePartyCommand;
  if (v == -6) return NWN::MasterFailedLockpickCommand;
  if (v == -22) return NWN::ToggleStealthCommand;
  if (v == -11) return NWN::MasterUnderAttackCommand;
  if (v == -16) return NWN::MasterGoingToBeAttackedCommand;
  if (v == -5) return NWN::FollowMasterCommand;
  if (v == -21) return NWN::ToggleCastingCommand;
  if (v == -10) return NWN::UnsummonSummonedCommand;
  if (v == -15) return NWN::MasterAttackedOtherCommand;
  if (v == -4) return NWN::HealMasterCommand;
  if (v == -20) return NWN::DisarmTrapCommand;
  if (v == -9) return NWN::UnsummonAnimalCompanionCommand;
  if (v == -14) return NWN::MasterSawTrapCommand;
  if (v == -3) return NWN::AttackNearestCommand;
  printf("Invalid enum value of type AssociateCommand passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_EffectTrueType_2_long(NWN::EffectTrueType k) {
  if (k == NWN::SwarmEffectType) return 85;
  if (k == NWN::SetStateInternalEffectType) return 9;
  if (k == NWN::InvisibilityEffectType) return 47;
  if (k == NWN::MovementSpeedIncreaseEffectType) return 28;
  if (k == NWN::DefensiveStanceEffectType) return 95;
  if (k == NWN::ConcealmentEffectType) return 76;
  if (k == NWN::DeathEffectType) return 19;
  if (k == NWN::HitpointChangeWhenDyingEffectType) return 57;
  if (k == NWN::InvalidEffectType) return 0;
  if (k == NWN::DamageEffectType) return 38;
  if (k == NWN::VampiricRegenerationEffectType) return 86;
  if (k == NWN::AttackIncreaseEffectType) return 10;
  if (k == NWN::AcIncreaseEffectType) return 48;
  if (k == NWN::MovementSpeedDecreaseEffectType) return 29;
  if (k == NWN::IconEffectType) return 67;
  if (k == NWN::TurnResistanceIncreaseEffectType) return 77;
  if (k == NWN::KnockdownEffectType) return 20;
  if (k == NWN::SetWalkAnimationEffectType) return 58;
  if (k == NWN::HasteEffectType) return 1;
  if (k == NWN::HealEffectType) return 39;
  if (k == NWN::DisarmEffectType) return 87;
  if (k == NWN::VisualEffectType) return 30;
  if (k == NWN::RacialTypeEffectType) return 68;
  if (k == NWN::AttackDecreaseEffectType) return 11;
  if (k == NWN::AcDecreaseEffectType) return 49;
  if (k == NWN::BonusSpellOfLevelEffectType) return 78;
  if (k == NWN::DeafEffectType) return 21;
  if (k == NWN::LimitMovementSpeedEffectType) return 59;
  if (k == NWN::DamageResistanceEffectType) return 2;
  if (k == NWN::LinkEffectType) return 40;
  if (k == NWN::TurnResistanceDecreaseEffectType) return 88;
  if (k == NWN::VisionEffectType) return 69;
  if (k == NWN::AOEEffectType) return 31;
  if (k == NWN::DamageReductionEffectType) return 12;
  if (k == NWN::SpellImmunityEffectType) return 50;
  if (k == NWN::DisappearAppearEffectType) return 79;
  if (k == NWN::SlowEffectType) return 3;
  if (k == NWN::HasteInternalEffectType) return 41;
  if (k == NWN::ImmunityEffectType) return 22;
  if (k == NWN::BlindnessInactiveEffectType) return 89;
  if (k == NWN::SeeInvisibleEffectType) return 70;
  if (k == NWN::BeamEffectType) return 32;
  if (k == NWN::DamageIncreaseEffectType) return 13;
  if (k == NWN::DispelAllMagicEffectType) return 51;
  if (k == NWN::DisappearEffectType) return 80;
  if (k == NWN::ResurrectionEffectType) return 4;
  if (k == NWN::SlowInternalEffectType) return 42;
  if (k == NWN::SetAIStateEffectType) return 23;
  if (k == NWN::DamageShieldEffectType) return 61;
  if (k == NWN::PetrifyEffectType) return 90;
  if (k == NWN::UltravisionEffectType) return 71;
  if (k == NWN::DamageDecreaseEffectType) return 14;
  if (k == NWN::DispelBestMagicEffectType) return 52;
  if (k == NWN::SpellResistanceIncreaseEffectType) return 33;
  if (k == NWN::AppearEffectType) return 81;
  if (k == NWN::EnemyAttackBonusEffectType) return 24;
  if (k == NWN::PolymorphEffectType) return 62;
  if (k == NWN::DiseaseEffectType) return 5;
  if (k == NWN::ItempropertyEffectType) return 91;
  if (k == NWN::TrueSeeingEffectType) return 72;
  if (k == NWN::TemporaryHitpointsEffectType) return 15;
  if (k == NWN::TauntEffectType) return 53;
  if (k == NWN::SpellResistanceDecreaseEffectType) return 34;
  if (k == NWN::NegativeLevelEffectType) return 82;
  if (k == NWN::ArcaneSpellFailureEffectType) return 25;
  if (k == NWN::SanctuaryEffectType) return 63;
  if (k == NWN::SummonCreatureEffectType) return 6;
  if (k == NWN::ModifynumattacksEffectType) return 44;
  if (k == NWN::SpellFailureEffectType) return 92;
  if (k == NWN::BlindnessEffectType) return 73;
  if (k == NWN::LightEffectType) return 54;
  if (k == NWN::PoisonEffectType) return 35;
  if (k == NWN::DamageImmunityIncreaseEffectType) return 16;
  if (k == NWN::BonusFeatEffectType) return 83;
  if (k == NWN::SavingThrowIncreaseEffectType) return 26;
  if (k == NWN::TimestopEffectType) return 64;
  if (k == NWN::RegenerateEffectType) return 7;
  if (k == NWN::CurseEffectType) return 45;
  if (k == NWN::CutsceneGhostEffectType) return 93;
  if (k == NWN::DarknessEffectType) return 74;
  if (k == NWN::AbilityIncreaseEffectType) return 36;
  if (k == NWN::DamageImmunityDecreaseEffectType) return 17;
  if (k == NWN::SkillIncreaseEffectType) return 55;
  if (k == NWN::WoundingEffectType) return 84;
  if (k == NWN::SpellLevelAbsorptionEffectType) return 65;
  if (k == NWN::SetStateEffectType) return 8;
  if (k == NWN::SilenceEffectType) return 46;
  if (k == NWN::SavingThrowDecreaseEffectType) return 27;
  if (k == NWN::CutsceneImmobileEffectType) return 94;
  if (k == NWN::MissChanceEffectType) return 75;
  if (k == NWN::AbilityDecreaseEffectType) return 37;
  if (k == NWN::EntangleEffectType) return 18;
  if (k == NWN::SkillDecreaseEffectType) return 56;
  throw "omg";
};
NWN::EffectTrueType NWScriptI::enum_long_2_EffectTrueType(long v) {
  if (v == 85) return NWN::SwarmEffectType;
  if (v == 9) return NWN::SetStateInternalEffectType;
  if (v == 47) return NWN::InvisibilityEffectType;
  if (v == 28) return NWN::MovementSpeedIncreaseEffectType;
  if (v == 95) return NWN::DefensiveStanceEffectType;
  if (v == 76) return NWN::ConcealmentEffectType;
  if (v == 19) return NWN::DeathEffectType;
  if (v == 57) return NWN::HitpointChangeWhenDyingEffectType;
  if (v == 0) return NWN::InvalidEffectType;
  if (v == 38) return NWN::DamageEffectType;
  if (v == 86) return NWN::VampiricRegenerationEffectType;
  if (v == 10) return NWN::AttackIncreaseEffectType;
  if (v == 48) return NWN::AcIncreaseEffectType;
  if (v == 29) return NWN::MovementSpeedDecreaseEffectType;
  if (v == 67) return NWN::IconEffectType;
  if (v == 77) return NWN::TurnResistanceIncreaseEffectType;
  if (v == 20) return NWN::KnockdownEffectType;
  if (v == 58) return NWN::SetWalkAnimationEffectType;
  if (v == 1) return NWN::HasteEffectType;
  if (v == 39) return NWN::HealEffectType;
  if (v == 87) return NWN::DisarmEffectType;
  if (v == 30) return NWN::VisualEffectType;
  if (v == 68) return NWN::RacialTypeEffectType;
  if (v == 11) return NWN::AttackDecreaseEffectType;
  if (v == 49) return NWN::AcDecreaseEffectType;
  if (v == 78) return NWN::BonusSpellOfLevelEffectType;
  if (v == 21) return NWN::DeafEffectType;
  if (v == 59) return NWN::LimitMovementSpeedEffectType;
  if (v == 2) return NWN::DamageResistanceEffectType;
  if (v == 40) return NWN::LinkEffectType;
  if (v == 88) return NWN::TurnResistanceDecreaseEffectType;
  if (v == 69) return NWN::VisionEffectType;
  if (v == 31) return NWN::AOEEffectType;
  if (v == 12) return NWN::DamageReductionEffectType;
  if (v == 50) return NWN::SpellImmunityEffectType;
  if (v == 79) return NWN::DisappearAppearEffectType;
  if (v == 3) return NWN::SlowEffectType;
  if (v == 41) return NWN::HasteInternalEffectType;
  if (v == 22) return NWN::ImmunityEffectType;
  if (v == 89) return NWN::BlindnessInactiveEffectType;
  if (v == 70) return NWN::SeeInvisibleEffectType;
  if (v == 32) return NWN::BeamEffectType;
  if (v == 13) return NWN::DamageIncreaseEffectType;
  if (v == 51) return NWN::DispelAllMagicEffectType;
  if (v == 80) return NWN::DisappearEffectType;
  if (v == 4) return NWN::ResurrectionEffectType;
  if (v == 42) return NWN::SlowInternalEffectType;
  if (v == 23) return NWN::SetAIStateEffectType;
  if (v == 61) return NWN::DamageShieldEffectType;
  if (v == 90) return NWN::PetrifyEffectType;
  if (v == 71) return NWN::UltravisionEffectType;
  if (v == 14) return NWN::DamageDecreaseEffectType;
  if (v == 52) return NWN::DispelBestMagicEffectType;
  if (v == 33) return NWN::SpellResistanceIncreaseEffectType;
  if (v == 81) return NWN::AppearEffectType;
  if (v == 24) return NWN::EnemyAttackBonusEffectType;
  if (v == 62) return NWN::PolymorphEffectType;
  if (v == 5) return NWN::DiseaseEffectType;
  if (v == 91) return NWN::ItempropertyEffectType;
  if (v == 72) return NWN::TrueSeeingEffectType;
  if (v == 15) return NWN::TemporaryHitpointsEffectType;
  if (v == 53) return NWN::TauntEffectType;
  if (v == 34) return NWN::SpellResistanceDecreaseEffectType;
  if (v == 82) return NWN::NegativeLevelEffectType;
  if (v == 25) return NWN::ArcaneSpellFailureEffectType;
  if (v == 63) return NWN::SanctuaryEffectType;
  if (v == 6) return NWN::SummonCreatureEffectType;
  if (v == 44) return NWN::ModifynumattacksEffectType;
  if (v == 92) return NWN::SpellFailureEffectType;
  if (v == 73) return NWN::BlindnessEffectType;
  if (v == 54) return NWN::LightEffectType;
  if (v == 35) return NWN::PoisonEffectType;
  if (v == 16) return NWN::DamageImmunityIncreaseEffectType;
  if (v == 83) return NWN::BonusFeatEffectType;
  if (v == 26) return NWN::SavingThrowIncreaseEffectType;
  if (v == 64) return NWN::TimestopEffectType;
  if (v == 7) return NWN::RegenerateEffectType;
  if (v == 45) return NWN::CurseEffectType;
  if (v == 93) return NWN::CutsceneGhostEffectType;
  if (v == 74) return NWN::DarknessEffectType;
  if (v == 36) return NWN::AbilityIncreaseEffectType;
  if (v == 17) return NWN::DamageImmunityDecreaseEffectType;
  if (v == 55) return NWN::SkillIncreaseEffectType;
  if (v == 84) return NWN::WoundingEffectType;
  if (v == 65) return NWN::SpellLevelAbsorptionEffectType;
  if (v == 8) return NWN::SetStateEffectType;
  if (v == 46) return NWN::SilenceEffectType;
  if (v == 27) return NWN::SavingThrowDecreaseEffectType;
  if (v == 94) return NWN::CutsceneImmobileEffectType;
  if (v == 75) return NWN::MissChanceEffectType;
  if (v == 37) return NWN::AbilityDecreaseEffectType;
  if (v == 18) return NWN::EntangleEffectType;
  if (v == 56) return NWN::SkillDecreaseEffectType;
  printf("Invalid enum value of type EffectTrueType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_ObjectType_2_long(NWN::ObjectType k) {
  if (k == NWN::AOE) return 16;
  if (k == NWN::InvalidObject) return 0;
  if (k == NWN::Creature) return 1;
  if (k == NWN::Store) return 128;
  if (k == NWN::Item) return 2;
  if (k == NWN::Door) return 8;
  if (k == NWN::Encounter) return 256;
  if (k == NWN::All) return 32767;
  if (k == NWN::Placeable) return 64;
  if (k == NWN::Trigger) return 4;
  if (k == NWN::Waypoint) return 32;
  throw "omg";
};
NWN::ObjectType NWScriptI::enum_long_2_ObjectType(long v) {
  if (v == 16) return NWN::AOE;
  if (v == 0) return NWN::InvalidObject;
  if (v == 1) return NWN::Creature;
  if (v == 128) return NWN::Store;
  if (v == 2) return NWN::Item;
  if (v == 8) return NWN::Door;
  if (v == 256) return NWN::Encounter;
  if (v == 32767) return NWN::All;
  if (v == 64) return NWN::Placeable;
  if (v == 4) return NWN::Trigger;
  if (v == 32) return NWN::Waypoint;
  printf("Invalid enum value of type ObjectType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_DurationType_2_long(NWN::DurationType k) {
  if (k == NWN::Instant) return 0;
  if (k == NWN::Temporary) return 1;
  if (k == NWN::InvalidDuration) return -1;
  if (k == NWN::Permanent) return 2;
  throw "omg";
};
NWN::DurationType NWScriptI::enum_long_2_DurationType(long v) {
  if (v == 0) return NWN::Instant;
  if (v == 1) return NWN::Temporary;
  if (v == -1) return NWN::InvalidDuration;
  if (v == 2) return NWN::Permanent;
  printf("Invalid enum value of type DurationType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_ActionMode_2_long(NWN::ActionMode k) {
  if (k == NWN::CounterspellMode) return 5;
  if (k == NWN::DirtyFightingMode) return 11;
  if (k == NWN::DetectMode) return 0;
  if (k == NWN::FlurryOfBlowsMode) return 6;
  if (k == NWN::StealthMode) return 1;
  if (k == NWN::RapidShotMode) return 7;
  if (k == NWN::ParryMode) return 2;
  if (k == NWN::ExpertiseMode) return 8;
  if (k == NWN::PowerAttackMode) return 3;
  if (k == NWN::ImprovedExpertiseMode) return 9;
  if (k == NWN::ImprovedPowerAttackMode) return 4;
  if (k == NWN::DefensiveCastMode) return 10;
  throw "omg";
};
NWN::ActionMode NWScriptI::enum_long_2_ActionMode(long v) {
  if (v == 5) return NWN::CounterspellMode;
  if (v == 11) return NWN::DirtyFightingMode;
  if (v == 0) return NWN::DetectMode;
  if (v == 6) return NWN::FlurryOfBlowsMode;
  if (v == 1) return NWN::StealthMode;
  if (v == 7) return NWN::RapidShotMode;
  if (v == 2) return NWN::ParryMode;
  if (v == 8) return NWN::ExpertiseMode;
  if (v == 3) return NWN::PowerAttackMode;
  if (v == 9) return NWN::ImprovedExpertiseMode;
  if (v == 4) return NWN::ImprovedPowerAttackMode;
  if (v == 10) return NWN::DefensiveCastMode;
  printf("Invalid enum value of type ActionMode passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_Alignment_2_long(NWN::Alignment k) {
  if (k == NWN::Evil) return 5;
  if (k == NWN::Any) return 0;
  if (k == NWN::Neutral) return 1;
  if (k == NWN::Lawful) return 2;
  if (k == NWN::Chaotic) return 3;
  if (k == NWN::Good) return 4;
  throw "omg";
};
NWN::Alignment NWScriptI::enum_long_2_Alignment(long v) {
  if (v == 5) return NWN::Evil;
  if (v == 0) return NWN::Any;
  if (v == 1) return NWN::Neutral;
  if (v == 2) return NWN::Lawful;
  if (v == 3) return NWN::Chaotic;
  if (v == 4) return NWN::Good;
  printf("Invalid enum value of type Alignment passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_TrapType_2_long(NWN::TrapType k) {
  if (k == NWN::StrongSonicTrap) return 38;
  if (k == NWN::DeadlyGasTrap) return 27;
  if (k == NWN::MinorFireTrap) return 16;
  if (k == NWN::AverageHolyTrap) return 5;
  if (k == NWN::EpicElectricalTrap) return 44;
  if (k == NWN::AverageNegativeTrap) return 33;
  if (k == NWN::StrongElectricalTrap) return 22;
  if (k == NWN::DeadlyTangleTrap) return 11;
  if (k == NWN::MinorSpikeTrap) return 0;
  if (k == NWN::DeadlySonicTrap) return 39;
  if (k == NWN::MinorFrostTrap) return 28;
  if (k == NWN::AverageFireTrap) return 17;
  if (k == NWN::StrongHolyTrap) return 6;
  if (k == NWN::EpicFireTrap) return 45;
  if (k == NWN::StrongNegativeTrap) return 34;
  if (k == NWN::DeadlyElectricalTrap) return 23;
  if (k == NWN::MinorAcidTrap) return 12;
  if (k == NWN::AverageSpikeTrap) return 1;
  if (k == NWN::MinorAcidSplashTrap) return 40;
  if (k == NWN::AverageFrostTrap) return 29;
  if (k == NWN::StrongFireTrap) return 18;
  if (k == NWN::DeadlyHolyTrap) return 7;
  if (k == NWN::EpicFrostTrap) return 46;
  if (k == NWN::DeadlyNegativeTrap) return 35;
  if (k == NWN::MinorGasTrap) return 24;
  if (k == NWN::AverageAcidTrap) return 13;
  if (k == NWN::StrongSpikeTrap) return 2;
  if (k == NWN::AverageAcidSplashTrap) return 41;
  if (k == NWN::StrongFrostTrap) return 30;
  if (k == NWN::DeadlyFireTrap) return 19;
  if (k == NWN::MinorTangleTrap) return 8;
  if (k == NWN::EpicSonicTrap) return 47;
  if (k == NWN::MinorSonicTrap) return 36;
  if (k == NWN::AverageGasTrap) return 25;
  if (k == NWN::StrongAcidTrap) return 14;
  if (k == NWN::DeadlySpikeTrap) return 3;
  if (k == NWN::StrongAcidSplashTrap) return 42;
  if (k == NWN::DeadlyFrostTrap) return 31;
  if (k == NWN::MinorElectricalTrap) return 20;
  if (k == NWN::AverageTangleTrap) return 9;
  if (k == NWN::AverageSonicTrap) return 37;
  if (k == NWN::StrongGasTrap) return 26;
  if (k == NWN::DeadlyAcidTrap) return 15;
  if (k == NWN::MinorHolyTrap) return 4;
  if (k == NWN::DeadlyAcidSplashTrap) return 43;
  if (k == NWN::MinorNegativeTrap) return 32;
  if (k == NWN::AverageElectricalTrap) return 21;
  if (k == NWN::StrongTangleTrap) return 10;
  throw "omg";
};
NWN::TrapType NWScriptI::enum_long_2_TrapType(long v) {
  if (v == 38) return NWN::StrongSonicTrap;
  if (v == 27) return NWN::DeadlyGasTrap;
  if (v == 16) return NWN::MinorFireTrap;
  if (v == 5) return NWN::AverageHolyTrap;
  if (v == 44) return NWN::EpicElectricalTrap;
  if (v == 33) return NWN::AverageNegativeTrap;
  if (v == 22) return NWN::StrongElectricalTrap;
  if (v == 11) return NWN::DeadlyTangleTrap;
  if (v == 0) return NWN::MinorSpikeTrap;
  if (v == 39) return NWN::DeadlySonicTrap;
  if (v == 28) return NWN::MinorFrostTrap;
  if (v == 17) return NWN::AverageFireTrap;
  if (v == 6) return NWN::StrongHolyTrap;
  if (v == 45) return NWN::EpicFireTrap;
  if (v == 34) return NWN::StrongNegativeTrap;
  if (v == 23) return NWN::DeadlyElectricalTrap;
  if (v == 12) return NWN::MinorAcidTrap;
  if (v == 1) return NWN::AverageSpikeTrap;
  if (v == 40) return NWN::MinorAcidSplashTrap;
  if (v == 29) return NWN::AverageFrostTrap;
  if (v == 18) return NWN::StrongFireTrap;
  if (v == 7) return NWN::DeadlyHolyTrap;
  if (v == 46) return NWN::EpicFrostTrap;
  if (v == 35) return NWN::DeadlyNegativeTrap;
  if (v == 24) return NWN::MinorGasTrap;
  if (v == 13) return NWN::AverageAcidTrap;
  if (v == 2) return NWN::StrongSpikeTrap;
  if (v == 41) return NWN::AverageAcidSplashTrap;
  if (v == 30) return NWN::StrongFrostTrap;
  if (v == 19) return NWN::DeadlyFireTrap;
  if (v == 8) return NWN::MinorTangleTrap;
  if (v == 47) return NWN::EpicSonicTrap;
  if (v == 36) return NWN::MinorSonicTrap;
  if (v == 25) return NWN::AverageGasTrap;
  if (v == 14) return NWN::StrongAcidTrap;
  if (v == 3) return NWN::DeadlySpikeTrap;
  if (v == 42) return NWN::StrongAcidSplashTrap;
  if (v == 31) return NWN::DeadlyFrostTrap;
  if (v == 20) return NWN::MinorElectricalTrap;
  if (v == 9) return NWN::AverageTangleTrap;
  if (v == 37) return NWN::AverageSonicTrap;
  if (v == 26) return NWN::StrongGasTrap;
  if (v == 15) return NWN::DeadlyAcidTrap;
  if (v == 4) return NWN::MinorHolyTrap;
  if (v == 43) return NWN::DeadlyAcidSplashTrap;
  if (v == 32) return NWN::MinorNegativeTrap;
  if (v == 21) return NWN::AverageElectricalTrap;
  if (v == 10) return NWN::StrongTangleTrap;
  printf("Invalid enum value of type TrapType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_AttackBonus_2_long(NWN::AttackBonus k) {
  if (k == NWN::MiscBonus) return 0;
  if (k == NWN::OnhandBonus) return 1;
  if (k == NWN::OffhandBonus) return 2;
  throw "omg";
};
NWN::AttackBonus NWScriptI::enum_long_2_AttackBonus(long v) {
  if (v == 0) return NWN::MiscBonus;
  if (v == 1) return NWN::OnhandBonus;
  if (v == 2) return NWN::OffhandBonus;
  printf("Invalid enum value of type AttackBonus passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_IPMiscImmunityType_2_long(NWN::IPMiscImmunityType k) {
  if (k == NWN::FearIPImmunity) return 5;
  if (k == NWN::BackstabIPImmunity) return 0;
  if (k == NWN::KnockdownIPImmunity) return 6;
  if (k == NWN::LevelAbilDrainIPImmunity) return 1;
  if (k == NWN::ParalysisIPImmunity) return 7;
  if (k == NWN::MindSpellsIPImmunity) return 2;
  if (k == NWN::CriticalHitsIPImmunity) return 8;
  if (k == NWN::PoisonIPImmunity) return 3;
  if (k == NWN::DeathMagicIPImmunity) return 9;
  if (k == NWN::DiseaseIPImmunity) return 4;
  throw "omg";
};
NWN::IPMiscImmunityType NWScriptI::enum_long_2_IPMiscImmunityType(long v) {
  if (v == 5) return NWN::FearIPImmunity;
  if (v == 0) return NWN::BackstabIPImmunity;
  if (v == 6) return NWN::KnockdownIPImmunity;
  if (v == 1) return NWN::LevelAbilDrainIPImmunity;
  if (v == 7) return NWN::ParalysisIPImmunity;
  if (v == 2) return NWN::MindSpellsIPImmunity;
  if (v == 8) return NWN::CriticalHitsIPImmunity;
  if (v == 3) return NWN::PoisonIPImmunity;
  if (v == 9) return NWN::DeathMagicIPImmunity;
  if (v == 4) return NWN::DiseaseIPImmunity;
  printf("Invalid enum value of type IPMiscImmunityType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_RacialType_2_long(NWN::RacialType k) {
  if (k == NWN::ElementalRace) return 16;
  if (k == NWN::HalforcRace) return 5;
  if (k == NWN::DragonRace) return 11;
  if (k == NWN::DwarfRace) return 0;
  if (k == NWN::InvalidRace) return 28;
  if (k == NWN::FeyRace) return 17;
  if (k == NWN::HumanRace) return 6;
  if (k == NWN::ShapechangerRace) return 23;
  if (k == NWN::HumanoidGoblinoidRace) return 12;
  if (k == NWN::ElfRace) return 1;
  if (k == NWN::OozeRace) return 29;
  if (k == NWN::GiantRace) return 18;
  if (k == NWN::AberrationRace) return 7;
  if (k == NWN::UndeadRace) return 24;
  if (k == NWN::HumanoidMonstrousRace) return 13;
  if (k == NWN::GnomeRace) return 2;
  if (k == NWN::MagicalBeastRace) return 19;
  if (k == NWN::AnimalRace) return 8;
  if (k == NWN::VerminRace) return 25;
  if (k == NWN::HumanoidOrcRace) return 14;
  if (k == NWN::HalflingRace) return 3;
  if (k == NWN::OutsiderRace) return 20;
  if (k == NWN::BeastRace) return 9;
  if (k == NWN::HumanoidReptilianRace) return 15;
  if (k == NWN::HalfelfRace) return 4;
  if (k == NWN::ConstructRace) return 10;
  throw "omg";
};
NWN::RacialType NWScriptI::enum_long_2_RacialType(long v) {
  if (v == 16) return NWN::ElementalRace;
  if (v == 5) return NWN::HalforcRace;
  if (v == 11) return NWN::DragonRace;
  if (v == 0) return NWN::DwarfRace;
  if (v == 28) return NWN::InvalidRace;
  if (v == 17) return NWN::FeyRace;
  if (v == 6) return NWN::HumanRace;
  if (v == 23) return NWN::ShapechangerRace;
  if (v == 12) return NWN::HumanoidGoblinoidRace;
  if (v == 1) return NWN::ElfRace;
  if (v == 29) return NWN::OozeRace;
  if (v == 18) return NWN::GiantRace;
  if (v == 7) return NWN::AberrationRace;
  if (v == 24) return NWN::UndeadRace;
  if (v == 13) return NWN::HumanoidMonstrousRace;
  if (v == 2) return NWN::GnomeRace;
  if (v == 19) return NWN::MagicalBeastRace;
  if (v == 8) return NWN::AnimalRace;
  if (v == 25) return NWN::VerminRace;
  if (v == 14) return NWN::HumanoidOrcRace;
  if (v == 3) return NWN::HalflingRace;
  if (v == 20) return NWN::OutsiderRace;
  if (v == 9) return NWN::BeastRace;
  if (v == 15) return NWN::HumanoidReptilianRace;
  if (v == 4) return NWN::HalfelfRace;
  if (v == 10) return NWN::ConstructRace;
  printf("Invalid enum value of type RacialType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_TalkVolume_2_long(NWN::TalkVolume k) {
  if (k == NWN::PartyVol) return 5;
  if (k == NWN::TalkVol) return 0;
  if (k == NWN::TellVol) return 6;
  if (k == NWN::WhisperVol) return 1;
  if (k == NWN::ShoutVol) return 2;
  if (k == NWN::SilentTalkVol) return 3;
  if (k == NWN::SilentShoutVol) return 4;
  throw "omg";
};
NWN::TalkVolume NWScriptI::enum_long_2_TalkVolume(long v) {
  if (v == 5) return NWN::PartyVol;
  if (v == 0) return NWN::TalkVol;
  if (v == 6) return NWN::TellVol;
  if (v == 1) return NWN::WhisperVol;
  if (v == 2) return NWN::ShoutVol;
  if (v == 3) return NWN::SilentTalkVol;
  if (v == 4) return NWN::SilentShoutVol;
  printf("Invalid enum value of type TalkVolume passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_AssociateType_2_long(NWN::AssociateType k) {
  if (k == NWN::DominatedAssociate) return 5;
  if (k == NWN::NoAssociate) return 0;
  if (k == NWN::HenchmanAssociate) return 1;
  if (k == NWN::AnimalCompanionAssociate) return 2;
  if (k == NWN::FamiliarAssociate) return 3;
  if (k == NWN::SummonedAssociate) return 4;
  throw "omg";
};
NWN::AssociateType NWScriptI::enum_long_2_AssociateType(long v) {
  if (v == 5) return NWN::DominatedAssociate;
  if (v == 0) return NWN::NoAssociate;
  if (v == 1) return NWN::HenchmanAssociate;
  if (v == 2) return NWN::AnimalCompanionAssociate;
  if (v == 3) return NWN::FamiliarAssociate;
  if (v == 4) return NWN::SummonedAssociate;
  printf("Invalid enum value of type AssociateType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_IPAlignment_2_long(NWN::IPAlignment k) {
  if (k == NWN::NeAlignment) return 5;
  if (k == NWN::LgAlignment) return 0;
  if (k == NWN::CgAlignment) return 6;
  if (k == NWN::LnAlignment) return 1;
  if (k == NWN::CnAlignment) return 7;
  if (k == NWN::LeAlignment) return 2;
  if (k == NWN::CeAlignment) return 8;
  if (k == NWN::NgAlignment) return 3;
  if (k == NWN::TnAlignment) return 4;
  throw "omg";
};
NWN::IPAlignment NWScriptI::enum_long_2_IPAlignment(long v) {
  if (v == 5) return NWN::NeAlignment;
  if (v == 0) return NWN::LgAlignment;
  if (v == 6) return NWN::CgAlignment;
  if (v == 1) return NWN::LnAlignment;
  if (v == 7) return NWN::CnAlignment;
  if (v == 2) return NWN::LeAlignment;
  if (v == 8) return NWN::CeAlignment;
  if (v == 3) return NWN::NgAlignment;
  if (v == 4) return NWN::TnAlignment;
  printf("Invalid enum value of type IPAlignment passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_Button_2_long(NWN::Button k) {
  if (k == NWN::SpellsButton) return 5;
  if (k == NWN::MapButton) return 0;
  if (k == NWN::RestButton) return 6;
  if (k == NWN::InventoryButton) return 1;
  if (k == NWN::PvPButton) return 7;
  if (k == NWN::JournalButton) return 2;
  if (k == NWN::CharacterButton) return 3;
  if (k == NWN::OptionsButton) return 4;
  throw "omg";
};
NWN::Button NWScriptI::enum_long_2_Button(long v) {
  if (v == 5) return NWN::SpellsButton;
  if (v == 0) return NWN::MapButton;
  if (v == 6) return NWN::RestButton;
  if (v == 1) return NWN::InventoryButton;
  if (v == 7) return NWN::PvPButton;
  if (v == 2) return NWN::JournalButton;
  if (v == 3) return NWN::CharacterButton;
  if (v == 4) return NWN::OptionsButton;
  printf("Invalid enum value of type Button passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_SpecialAttack_2_long(NWN::SpecialAttack k) {
  if (k == NWN::ImprovedDisarmSpecialAttack) return 5;
  if (k == NWN::InvalidSpecialAttack) return 0;
  if (k == NWN::KnockdownSpecialAttack) return 6;
  if (k == NWN::CalledShotLegSpecialAttack) return 1;
  if (k == NWN::ImprovedKnockdownSpecialAttack) return 7;
  if (k == NWN::CalledShotArmSpecialAttack) return 2;
  if (k == NWN::StunningFistSpecialAttack) return 8;
  if (k == NWN::SapSpecialAttack) return 3;
  if (k == NWN::FlurryOfBlowsSpecialAttack) return 9;
  if (k == NWN::DisarmSpecialAttack) return 4;
  if (k == NWN::RapidShotSpecialAttack) return 10;
  throw "omg";
};
NWN::SpecialAttack NWScriptI::enum_long_2_SpecialAttack(long v) {
  if (v == 5) return NWN::ImprovedDisarmSpecialAttack;
  if (v == 0) return NWN::InvalidSpecialAttack;
  if (v == 6) return NWN::KnockdownSpecialAttack;
  if (v == 1) return NWN::CalledShotLegSpecialAttack;
  if (v == 7) return NWN::ImprovedKnockdownSpecialAttack;
  if (v == 2) return NWN::CalledShotArmSpecialAttack;
  if (v == 8) return NWN::StunningFistSpecialAttack;
  if (v == 3) return NWN::SapSpecialAttack;
  if (v == 9) return NWN::FlurryOfBlowsSpecialAttack;
  if (v == 4) return NWN::DisarmSpecialAttack;
  if (v == 10) return NWN::RapidShotSpecialAttack;
  printf("Invalid enum value of type SpecialAttack passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_IPDamageType_2_long(NWN::IPDamageType k) {
  if (k == NWN::MagicalIPDamage) return 5;
  if (k == NWN::NegativeIPDamage) return 11;
  if (k == NWN::BludgeoningIPDamage) return 0;
  if (k == NWN::AcidIPDamage) return 6;
  if (k == NWN::PositiveIPDamage) return 12;
  if (k == NWN::PiercingIPDamage) return 1;
  if (k == NWN::ColdIPDamage) return 7;
  if (k == NWN::SonicIPDamage) return 13;
  if (k == NWN::SlashingIPDamage) return 2;
  if (k == NWN::DivineIPDamage) return 8;
  if (k == NWN::SubdualIPDamage) return 3;
  if (k == NWN::ElectricalIPDamage) return 9;
  if (k == NWN::PhysicalIPDamage) return 4;
  if (k == NWN::FireIPDamage) return 10;
  throw "omg";
};
NWN::IPDamageType NWScriptI::enum_long_2_IPDamageType(long v) {
  if (v == 5) return NWN::MagicalIPDamage;
  if (v == 11) return NWN::NegativeIPDamage;
  if (v == 0) return NWN::BludgeoningIPDamage;
  if (v == 6) return NWN::AcidIPDamage;
  if (v == 12) return NWN::PositiveIPDamage;
  if (v == 1) return NWN::PiercingIPDamage;
  if (v == 7) return NWN::ColdIPDamage;
  if (v == 13) return NWN::SonicIPDamage;
  if (v == 2) return NWN::SlashingIPDamage;
  if (v == 8) return NWN::DivineIPDamage;
  if (v == 3) return NWN::SubdualIPDamage;
  if (v == 9) return NWN::ElectricalIPDamage;
  if (v == 4) return NWN::PhysicalIPDamage;
  if (v == 10) return NWN::FireIPDamage;
  printf("Invalid enum value of type IPDamageType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_PhenoType_2_long(NWN::PhenoType k) {
  if (k == NWN::Custom14PhenoType) return 16;
  if (k == NWN::Custom3PhenoType) return 5;
  if (k == NWN::Custom9PhenoType) return 11;
  if (k == NWN::NormalPhenoType) return 0;
  if (k == NWN::Custom15PhenoType) return 17;
  if (k == NWN::Custom4PhenoType) return 6;
  if (k == NWN::Custom10PhenoType) return 12;
  if (k == NWN::Custom16PhenoType) return 18;
  if (k == NWN::Custom5PhenoType) return 7;
  if (k == NWN::Custom11PhenoType) return 13;
  if (k == NWN::BigPhenoType) return 2;
  if (k == NWN::Custom17PhenoType) return 19;
  if (k == NWN::Custom6PhenoType) return 8;
  if (k == NWN::Custom12PhenoType) return 14;
  if (k == NWN::Custom1PhenoType) return 3;
  if (k == NWN::Custom18PhenoType) return 20;
  if (k == NWN::Custom7PhenoType) return 9;
  if (k == NWN::Custom13PhenoType) return 15;
  if (k == NWN::Custom2PhenoType) return 4;
  if (k == NWN::Custom8PhenoType) return 10;
  throw "omg";
};
NWN::PhenoType NWScriptI::enum_long_2_PhenoType(long v) {
  if (v == 16) return NWN::Custom14PhenoType;
  if (v == 5) return NWN::Custom3PhenoType;
  if (v == 11) return NWN::Custom9PhenoType;
  if (v == 0) return NWN::NormalPhenoType;
  if (v == 17) return NWN::Custom15PhenoType;
  if (v == 6) return NWN::Custom4PhenoType;
  if (v == 12) return NWN::Custom10PhenoType;
  if (v == 18) return NWN::Custom16PhenoType;
  if (v == 7) return NWN::Custom5PhenoType;
  if (v == 13) return NWN::Custom11PhenoType;
  if (v == 2) return NWN::BigPhenoType;
  if (v == 19) return NWN::Custom17PhenoType;
  if (v == 8) return NWN::Custom6PhenoType;
  if (v == 14) return NWN::Custom12PhenoType;
  if (v == 3) return NWN::Custom1PhenoType;
  if (v == 20) return NWN::Custom18PhenoType;
  if (v == 9) return NWN::Custom7PhenoType;
  if (v == 15) return NWN::Custom13PhenoType;
  if (v == 4) return NWN::Custom2PhenoType;
  if (v == 10) return NWN::Custom8PhenoType;
  printf("Invalid enum value of type PhenoType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_InventorySlot_2_long(NWN::InventorySlot k) {
  if (k == NWN::CreatureBiteSlot) return 16;
  if (k == NWN::LefthandSlot) return 5;
  if (k == NWN::ArrowsSlot) return 11;
  if (k == NWN::HeadSlot) return 0;
  if (k == NWN::CreatureArmorSlot) return 17;
  if (k == NWN::CloakSlot) return 6;
  if (k == NWN::BulletsSlot) return 12;
  if (k == NWN::ChestSlot) return 1;
  if (k == NWN::LeftringSlot) return 7;
  if (k == NWN::BoltsSlot) return 13;
  if (k == NWN::BootsSlot) return 2;
  if (k == NWN::RightringSlot) return 8;
  if (k == NWN::CreatureLefthandSlot) return 14;
  if (k == NWN::ArmsSlot) return 3;
  if (k == NWN::NeckSlot) return 9;
  if (k == NWN::CreatureRighthandSlot) return 15;
  if (k == NWN::RighthandSlot) return 4;
  if (k == NWN::BeltSlot) return 10;
  throw "omg";
};
NWN::InventorySlot NWScriptI::enum_long_2_InventorySlot(long v) {
  if (v == 16) return NWN::CreatureBiteSlot;
  if (v == 5) return NWN::LefthandSlot;
  if (v == 11) return NWN::ArrowsSlot;
  if (v == 0) return NWN::HeadSlot;
  if (v == 17) return NWN::CreatureArmorSlot;
  if (v == 6) return NWN::CloakSlot;
  if (v == 12) return NWN::BulletsSlot;
  if (v == 1) return NWN::ChestSlot;
  if (v == 7) return NWN::LeftringSlot;
  if (v == 13) return NWN::BoltsSlot;
  if (v == 2) return NWN::BootsSlot;
  if (v == 8) return NWN::RightringSlot;
  if (v == 14) return NWN::CreatureLefthandSlot;
  if (v == 3) return NWN::ArmsSlot;
  if (v == 9) return NWN::NeckSlot;
  if (v == 15) return NWN::CreatureRighthandSlot;
  if (v == 4) return NWN::RighthandSlot;
  if (v == 10) return NWN::BeltSlot;
  printf("Invalid enum value of type InventorySlot passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_DoorAction_2_long(NWN::DoorAction k) {
  if (k == NWN::OpenDoor) return 0;
  if (k == NWN::UnlockDoor) return 1;
  if (k == NWN::BashDoor) return 2;
  if (k == NWN::IgnoreDoor) return 3;
  if (k == NWN::KnockDoor) return 4;
  throw "omg";
};
NWN::DoorAction NWScriptI::enum_long_2_DoorAction(long v) {
  if (v == 0) return NWN::OpenDoor;
  if (v == 1) return NWN::UnlockDoor;
  if (v == 2) return NWN::BashDoor;
  if (v == 3) return NWN::IgnoreDoor;
  if (v == 4) return NWN::KnockDoor;
  printf("Invalid enum value of type DoorAction passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_ProjectilePathType_2_long(NWN::ProjectilePathType k) {
  if (k == NWN::DefaultPath) return 0;
  if (k == NWN::HomingPath) return 1;
  if (k == NWN::BallisticPath) return 2;
  if (k == NWN::HighBallisticPath) return 3;
  if (k == NWN::AcceleratingPath) return 4;
  throw "omg";
};
NWN::ProjectilePathType NWScriptI::enum_long_2_ProjectilePathType(long v) {
  if (v == 0) return NWN::DefaultPath;
  if (v == 1) return NWN::HomingPath;
  if (v == 2) return NWN::BallisticPath;
  if (v == 3) return NWN::HighBallisticPath;
  if (v == 4) return NWN::AcceleratingPath;
  printf("Invalid enum value of type ProjectilePathType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_AILevel_2_long(NWN::AILevel k) {
  if (k == NWN::VeryLowAI) return 0;
  if (k == NWN::LowAI) return 1;
  if (k == NWN::DefaultAI) return -1;
  if (k == NWN::NormalAI) return 2;
  if (k == NWN::HighAI) return 3;
  if (k == NWN::VeryHighAI) return 4;
  throw "omg";
};
NWN::AILevel NWScriptI::enum_long_2_AILevel(long v) {
  if (v == 0) return NWN::VeryLowAI;
  if (v == 1) return NWN::LowAI;
  if (v == -1) return NWN::DefaultAI;
  if (v == 2) return NWN::NormalAI;
  if (v == 3) return NWN::HighAI;
  if (v == 4) return NWN::VeryHighAI;
  printf("Invalid enum value of type AILevel passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_ShapeType_2_long(NWN::ShapeType k) {
  if (k == NWN::SpellCylinderShape) return 0;
  if (k == NWN::ConeShape) return 1;
  if (k == NWN::CubeShape) return 2;
  if (k == NWN::SpellConeShape) return 3;
  if (k == NWN::SphereShape) return 4;
  throw "omg";
};
NWN::ShapeType NWScriptI::enum_long_2_ShapeType(long v) {
  if (v == 0) return NWN::SpellCylinderShape;
  if (v == 1) return NWN::ConeShape;
  if (v == 2) return NWN::CubeShape;
  if (v == 3) return NWN::SpellConeShape;
  if (v == 4) return NWN::SphereShape;
  printf("Invalid enum value of type ShapeType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_AttackResult_2_long(NWN::AttackResult k) {
  if (k == NWN::MissedAttack) return 0;
  if (k == NWN::HitAttack) return 1;
  if (k == NWN::CriticalHitAttack) return 2;
  throw "omg";
};
NWN::AttackResult NWScriptI::enum_long_2_AttackResult(long v) {
  if (v == 0) return NWN::MissedAttack;
  if (v == 1) return NWN::HitAttack;
  if (v == 2) return NWN::CriticalHitAttack;
  printf("Invalid enum value of type AttackResult passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_CreaturePart_2_long(NWN::CreaturePart k) {
  if (k == NWN::RightHandPart) return 16;
  if (k == NWN::RightThighPart) return 5;
  if (k == NWN::LeftForearmPart) return 11;
  if (k == NWN::RightFootPart) return 0;
  if (k == NWN::LeftHandPart) return 17;
  if (k == NWN::PelvisPart) return 6;
  if (k == NWN::RightBicepPart) return 12;
  if (k == NWN::LeftFootPart) return 1;
  if (k == NWN::TorsoPart) return 7;
  if (k == NWN::LeftBicepPart) return 13;
  if (k == NWN::RightShinPart) return 2;
  if (k == NWN::BeltPart) return 8;
  if (k == NWN::RightShoulderPart) return 14;
  if (k == NWN::LeftShinPart) return 3;
  if (k == NWN::HeadPart) return 20;
  if (k == NWN::NeckPart) return 9;
  if (k == NWN::LeftShoulderPart) return 15;
  if (k == NWN::LeftThighPart) return 4;
  if (k == NWN::RightForearmPart) return 10;
  throw "omg";
};
NWN::CreaturePart NWScriptI::enum_long_2_CreaturePart(long v) {
  if (v == 16) return NWN::RightHandPart;
  if (v == 5) return NWN::RightThighPart;
  if (v == 11) return NWN::LeftForearmPart;
  if (v == 0) return NWN::RightFootPart;
  if (v == 17) return NWN::LeftHandPart;
  if (v == 6) return NWN::PelvisPart;
  if (v == 12) return NWN::RightBicepPart;
  if (v == 1) return NWN::LeftFootPart;
  if (v == 7) return NWN::TorsoPart;
  if (v == 13) return NWN::LeftBicepPart;
  if (v == 2) return NWN::RightShinPart;
  if (v == 8) return NWN::BeltPart;
  if (v == 14) return NWN::RightShoulderPart;
  if (v == 3) return NWN::LeftShinPart;
  if (v == 20) return NWN::HeadPart;
  if (v == 9) return NWN::NeckPart;
  if (v == 15) return NWN::LeftShoulderPart;
  if (v == 4) return NWN::LeftThighPart;
  if (v == 10) return NWN::RightForearmPart;
  printf("Invalid enum value of type CreaturePart passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_MetaMagic_2_long(NWN::MetaMagic k) {
  if (k == NWN::SilentMeta) return 16;
  if (k == NWN::NoneMeta) return 0;
  if (k == NWN::EmpowerMeta) return 1;
  if (k == NWN::AnyMeta) return 255;
  if (k == NWN::ExtendMeta) return 2;
  if (k == NWN::QuickenMeta) return 8;
  if (k == NWN::MaximizeMeta) return 4;
  if (k == NWN::StillMeta) return 32;
  throw "omg";
};
NWN::MetaMagic NWScriptI::enum_long_2_MetaMagic(long v) {
  if (v == 16) return NWN::SilentMeta;
  if (v == 0) return NWN::NoneMeta;
  if (v == 1) return NWN::EmpowerMeta;
  if (v == 255) return NWN::AnyMeta;
  if (v == 2) return NWN::ExtendMeta;
  if (v == 8) return NWN::QuickenMeta;
  if (v == 4) return NWN::MaximizeMeta;
  if (v == 32) return NWN::StillMeta;
  printf("Invalid enum value of type MetaMagic passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_SpellSchool_2_long(NWN::SpellSchool k) {
  if (k == NWN::EvocationSchool) return 5;
  if (k == NWN::GeneralSchool) return 0;
  if (k == NWN::IllusionSchool) return 6;
  if (k == NWN::AbjurationSchool) return 1;
  if (k == NWN::NecromancySchool) return 7;
  if (k == NWN::ConjurationSchool) return 2;
  if (k == NWN::TransmutationSchool) return 8;
  if (k == NWN::DivinationSchool) return 3;
  if (k == NWN::EnchantmentSchool) return 4;
  throw "omg";
};
NWN::SpellSchool NWScriptI::enum_long_2_SpellSchool(long v) {
  if (v == 5) return NWN::EvocationSchool;
  if (v == 0) return NWN::GeneralSchool;
  if (v == 6) return NWN::IllusionSchool;
  if (v == 1) return NWN::AbjurationSchool;
  if (v == 7) return NWN::NecromancySchool;
  if (v == 2) return NWN::ConjurationSchool;
  if (v == 8) return NWN::TransmutationSchool;
  if (v == 3) return NWN::DivinationSchool;
  if (v == 4) return NWN::EnchantmentSchool;
  printf("Invalid enum value of type SpellSchool passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_MissChanceType_2_long(NWN::MissChanceType k) {
  if (k == NWN::MissChanceVSAll) return 0;
  if (k == NWN::MissChanceVSRanged) return 1;
  if (k == NWN::MissChanceVSMelee) return 2;
  throw "omg";
};
NWN::MissChanceType NWScriptI::enum_long_2_MissChanceType(long v) {
  if (v == 0) return NWN::MissChanceVSAll;
  if (v == 1) return NWN::MissChanceVSRanged;
  if (v == 2) return NWN::MissChanceVSMelee;
  printf("Invalid enum value of type MissChanceType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
long NWScriptI::enum_ImmunityType_2_long(NWN::ImmunityType k) {
  if (k == NWN::SkillDecreaseImmunity) return 27;
  if (k == NWN::ConfusedImmunity) return 16;
  if (k == NWN::TrapImmunity) return 5;
  if (k == NWN::DamageImmunityDecreaseImmunity) return 22;
  if (k == NWN::SilenceImmunity) return 11;
  if (k == NWN::NoneImmunity) return 0;
  if (k == NWN::KnockdownImmunity) return 28;
  if (k == NWN::CursedImmunity) return 17;
  if (k == NWN::ParalysisImmunity) return 6;
  if (k == NWN::AcDecreaseImmunity) return 23;
  if (k == NWN::StunImmunity) return 12;
  if (k == NWN::MindSpellsImmunity) return 1;
  if (k == NWN::NegativeLevelImmunity) return 29;
  if (k == NWN::DazedImmunity) return 18;
  if (k == NWN::BlindnessImmunity) return 7;
  if (k == NWN::MovementSpeedDecreaseImmunity) return 24;
  if (k == NWN::SleepImmunity) return 13;
  if (k == NWN::PoisonImmunity) return 2;
  if (k == NWN::SneakAttackImmunity) return 30;
  if (k == NWN::AbilityDecreaseImmunity) return 19;
  if (k == NWN::DeafnessImmunity) return 8;
  if (k == NWN::SavingThrowDecreaseImmunity) return 25;
  if (k == NWN::CharmImmunity) return 14;
  if (k == NWN::DiseaseImmunity) return 3;
  if (k == NWN::CriticalHitImmunity) return 31;
  if (k == NWN::AttackDecreaseImmunity) return 20;
  if (k == NWN::SlowImmunity) return 9;
  if (k == NWN::SpellResistanceDecreaseImmunity) return 26;
  if (k == NWN::DominateImmunity) return 15;
  if (k == NWN::FearImmunity) return 4;
  if (k == NWN::DeathImmunity) return 32;
  if (k == NWN::DamageDecreaseImmunity) return 21;
  if (k == NWN::EntangleImmunity) return 10;
  throw "omg";
};
NWN::ImmunityType NWScriptI::enum_long_2_ImmunityType(long v) {
  if (v == 27) return NWN::SkillDecreaseImmunity;
  if (v == 16) return NWN::ConfusedImmunity;
  if (v == 5) return NWN::TrapImmunity;
  if (v == 22) return NWN::DamageImmunityDecreaseImmunity;
  if (v == 11) return NWN::SilenceImmunity;
  if (v == 0) return NWN::NoneImmunity;
  if (v == 28) return NWN::KnockdownImmunity;
  if (v == 17) return NWN::CursedImmunity;
  if (v == 6) return NWN::ParalysisImmunity;
  if (v == 23) return NWN::AcDecreaseImmunity;
  if (v == 12) return NWN::StunImmunity;
  if (v == 1) return NWN::MindSpellsImmunity;
  if (v == 29) return NWN::NegativeLevelImmunity;
  if (v == 18) return NWN::DazedImmunity;
  if (v == 7) return NWN::BlindnessImmunity;
  if (v == 24) return NWN::MovementSpeedDecreaseImmunity;
  if (v == 13) return NWN::SleepImmunity;
  if (v == 2) return NWN::PoisonImmunity;
  if (v == 30) return NWN::SneakAttackImmunity;
  if (v == 19) return NWN::AbilityDecreaseImmunity;
  if (v == 8) return NWN::DeafnessImmunity;
  if (v == 25) return NWN::SavingThrowDecreaseImmunity;
  if (v == 14) return NWN::CharmImmunity;
  if (v == 3) return NWN::DiseaseImmunity;
  if (v == 31) return NWN::CriticalHitImmunity;
  if (v == 20) return NWN::AttackDecreaseImmunity;
  if (v == 9) return NWN::SlowImmunity;
  if (v == 26) return NWN::SpellResistanceDecreaseImmunity;
  if (v == 15) return NWN::DominateImmunity;
  if (v == 4) return NWN::FearImmunity;
  if (v == 32) return NWN::DeathImmunity;
  if (v == 21) return NWN::DamageDecreaseImmunity;
  if (v == 10) return NWN::EntangleImmunity;
  printf("Invalid enum value of type ImmunityType passed: %%d. Cannot continue, and it's your fault!", v); exit(1);
};
Ice::Int NWScriptI::abs(Ice::Int nValue, const Ice::Current& ice) {
  lock(abs_mutex, "abs");
  callCounter += 1;
  StackPushInteger(nValue);

  VM_ExecuteCommand(77, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(abs_mutex, "abs");
  return nRetVal;
};

Ice::Float NWScriptI::acos(Ice::Float fValue, const Ice::Current& ice) {
  lock(acos_mutex, "acos");
  callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(71, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(acos_mutex, "acos");
  return fRetVal;
};

void NWScriptI::actionAttack(const NWN::NWObject& oAttackee, bool bPassive, const Ice::Current& ice) {
  if (oAttackee.id < 0 || oAttackee.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionAttack_mutex, "actionAttack");
  callCounter += 1;
  StackPushInteger(bPassive == true ? 1 : 0);
  StackPushObject(oAttackee.id);

  VM_ExecuteCommand(37, 2);

unlock(actionAttack_mutex, "actionAttack");
  
};

void NWScriptI::actionCastFakeSpellAtLocation(Ice::Int nSpell, const NWN::NWLocation& lTarget, NWN::ProjectilePathType tProjectilePathType, const Ice::Current& ice) {
  if (lTarget.area.id < 0) throw NWN::InvalidObjectException();
  lock(actionCastFakeSpellAtLocation_mutex, "actionCastFakeSpellAtLocation");
  callCounter += 1;
  StackPushInteger(enum_ProjectilePathType_2_long(tProjectilePathType));
  
  
  StackPushFloat(lTarget.facing);
  Vector lTarget_vv;
  lTarget_vv.X = lTarget.x; lTarget_vv.Y = lTarget.y; lTarget_vv.Z = lTarget.z;
  StackPushVector(lTarget_vv);
  StackPushObject(lTarget.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushInteger(nSpell);

  VM_ExecuteCommand(502, 3);

unlock(actionCastFakeSpellAtLocation_mutex, "actionCastFakeSpellAtLocation");
  
};

void NWScriptI::actionCastFakeSpellAtObject(Ice::Int nSpell, const NWN::NWObject& oTarget, NWN::ProjectilePathType tProjectilePathType, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionCastFakeSpellAtObject_mutex, "actionCastFakeSpellAtObject");
  callCounter += 1;
  StackPushInteger(enum_ProjectilePathType_2_long(tProjectilePathType));
  
  StackPushObject(oTarget.id);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(501, 3);

unlock(actionCastFakeSpellAtObject_mutex, "actionCastFakeSpellAtObject");
  
};

void NWScriptI::actionCastSpellAtLocation(Ice::Int nSpell, const NWN::NWLocation& lTargetLocation, NWN::MetaMagic tMetaMagic, bool bCheat, NWN::ProjectilePathType tProjectilePathType, bool bInstantSpell, const Ice::Current& ice) {
  if (lTargetLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(actionCastSpellAtLocation_mutex, "actionCastSpellAtLocation");
  callCounter += 1;
  StackPushInteger(bInstantSpell == true ? 1 : 0);
  StackPushInteger(enum_ProjectilePathType_2_long(tProjectilePathType));
  
  StackPushInteger(bCheat == true ? 1 : 0);
  StackPushInteger(enum_MetaMagic_2_long(tMetaMagic));
  
  
  StackPushFloat(lTargetLocation.facing);
  Vector lTargetLocation_vv;
  lTargetLocation_vv.X = lTargetLocation.x; lTargetLocation_vv.Y = lTargetLocation.y; lTargetLocation_vv.Z = lTargetLocation.z;
  StackPushVector(lTargetLocation_vv);
  StackPushObject(lTargetLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushInteger(nSpell);

  VM_ExecuteCommand(234, 6);

unlock(actionCastSpellAtLocation_mutex, "actionCastSpellAtLocation");
  
};

void NWScriptI::actionCastSpellAtObject(Ice::Int nSpell, const NWN::NWObject& oTarget, NWN::MetaMagic tMetaMagic, bool bCheat, Ice::Int nDomainLevel, NWN::ProjectilePathType tProjectilePathType, bool bInstantSpell, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionCastSpellAtObject_mutex, "actionCastSpellAtObject");
  callCounter += 1;
  StackPushInteger(bInstantSpell == true ? 1 : 0);
  StackPushInteger(enum_ProjectilePathType_2_long(tProjectilePathType));
  
  StackPushInteger(nDomainLevel);
  StackPushInteger(bCheat == true ? 1 : 0);
  StackPushInteger(enum_MetaMagic_2_long(tMetaMagic));
  
  StackPushObject(oTarget.id);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(48, 7);

unlock(actionCastSpellAtObject_mutex, "actionCastSpellAtObject");
  
};

void NWScriptI::actionCloseDoor(const NWN::NWObject& oDoor, const Ice::Current& ice) {
  if (oDoor.id < 0 || oDoor.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionCloseDoor_mutex, "actionCloseDoor");
  callCounter += 1;
  StackPushObject(oDoor.id);

  VM_ExecuteCommand(44, 1);

unlock(actionCloseDoor_mutex, "actionCloseDoor");
  
};

void NWScriptI::actionCounterSpell(const NWN::NWObject& oCounterSpellTarget, const Ice::Current& ice) {
  if (oCounterSpellTarget.id < 0 || oCounterSpellTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionCounterSpell_mutex, "actionCounterSpell");
  callCounter += 1;
  StackPushObject(oCounterSpellTarget.id);

  VM_ExecuteCommand(566, 1);

unlock(actionCounterSpell_mutex, "actionCounterSpell");
  
};

void NWScriptI::actionEquipItem(const NWN::NWObject& oItem, NWN::InventorySlot tInventorySlot, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionEquipItem_mutex, "actionEquipItem");
  callCounter += 1;
  StackPushInteger(enum_InventorySlot_2_long(tInventorySlot));
  
  StackPushObject(oItem.id);

  VM_ExecuteCommand(32, 2);

unlock(actionEquipItem_mutex, "actionEquipItem");
  
};

void NWScriptI::actionEquipMostDamagingMelee(const NWN::NWObject& oVersus, bool bOffHand, const Ice::Current& ice) {
  if (oVersus.id < 0 || oVersus.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionEquipMostDamagingMelee_mutex, "actionEquipMostDamagingMelee");
  callCounter += 1;
  StackPushInteger(bOffHand == true ? 1 : 0);
  StackPushObject(oVersus.id);

  VM_ExecuteCommand(399, 2);

unlock(actionEquipMostDamagingMelee_mutex, "actionEquipMostDamagingMelee");
  
};

void NWScriptI::actionEquipMostDamagingRanged(const NWN::NWObject& oVersus, const Ice::Current& ice) {
  if (oVersus.id < 0 || oVersus.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionEquipMostDamagingRanged_mutex, "actionEquipMostDamagingRanged");
  callCounter += 1;
  StackPushObject(oVersus.id);

  VM_ExecuteCommand(400, 1);

unlock(actionEquipMostDamagingRanged_mutex, "actionEquipMostDamagingRanged");
  
};

void NWScriptI::actionEquipMostEffectiveArmor(const Ice::Current& ice) {
  lock(actionEquipMostEffectiveArmor_mutex, "actionEquipMostEffectiveArmor");
  callCounter += 1;

  VM_ExecuteCommand(404, 0);

unlock(actionEquipMostEffectiveArmor_mutex, "actionEquipMostEffectiveArmor");
  
};

void NWScriptI::actionExamine(const NWN::NWObject& oExamine, const Ice::Current& ice) {
  if (oExamine.id < 0 || oExamine.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionExamine_mutex, "actionExamine");
  callCounter += 1;
  StackPushObject(oExamine.id);

  VM_ExecuteCommand(738, 1);

unlock(actionExamine_mutex, "actionExamine");
  
};

void NWScriptI::actionForceFollowObject(const NWN::NWObject& oFollow, Ice::Float fFollowDistance, const Ice::Current& ice) {
  if (oFollow.id < 0 || oFollow.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionForceFollowObject_mutex, "actionForceFollowObject");
  callCounter += 1;
  StackPushFloat(fFollowDistance);
  StackPushObject(oFollow.id);

  VM_ExecuteCommand(167, 2);

unlock(actionForceFollowObject_mutex, "actionForceFollowObject");
  
};

void NWScriptI::actionForceMoveToLocation(const NWN::NWLocation& lDestination, bool bRun, Ice::Float fTimeout, const Ice::Current& ice) {
  if (lDestination.area.id < 0) throw NWN::InvalidObjectException();
  lock(actionForceMoveToLocation_mutex, "actionForceMoveToLocation");
  callCounter += 1;
  StackPushFloat(fTimeout);
  StackPushInteger(bRun == true ? 1 : 0);
  
  StackPushFloat(lDestination.facing);
  Vector lDestination_vv;
  lDestination_vv.X = lDestination.x; lDestination_vv.Y = lDestination.y; lDestination_vv.Z = lDestination.z;
  StackPushVector(lDestination_vv);
  StackPushObject(lDestination.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(382, 3);

unlock(actionForceMoveToLocation_mutex, "actionForceMoveToLocation");
  
};

void NWScriptI::actionForceMoveToObject(const NWN::NWObject& oMoveTo, bool bRun, Ice::Float fRange, Ice::Float fTimeout, const Ice::Current& ice) {
  if (oMoveTo.id < 0 || oMoveTo.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionForceMoveToObject_mutex, "actionForceMoveToObject");
  callCounter += 1;
  StackPushFloat(fTimeout);
  StackPushFloat(fRange);
  StackPushInteger(bRun == true ? 1 : 0);
  StackPushObject(oMoveTo.id);

  VM_ExecuteCommand(383, 4);

unlock(actionForceMoveToObject_mutex, "actionForceMoveToObject");
  
};

void NWScriptI::actionGiveItem(const NWN::NWObject& oItem, const NWN::NWObject& oGiveTo, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oGiveTo.id < 0 || oGiveTo.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionGiveItem_mutex, "actionGiveItem");
  callCounter += 1;
  StackPushObject(oGiveTo.id);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(135, 2);

unlock(actionGiveItem_mutex, "actionGiveItem");
  
};

void NWScriptI::actionInteractObject(const NWN::NWObject& oPlaceable, const Ice::Current& ice) {
  if (oPlaceable.id < 0 || oPlaceable.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionInteractObject_mutex, "actionInteractObject");
  callCounter += 1;
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(329, 1);

unlock(actionInteractObject_mutex, "actionInteractObject");
  
};

void NWScriptI::actionJumpToLocation(const NWN::NWLocation& lLocation, const Ice::Current& ice) {
  if (lLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(actionJumpToLocation_mutex, "actionJumpToLocation");
  callCounter += 1;
  
  StackPushFloat(lLocation.facing);
  Vector lLocation_vv;
  lLocation_vv.X = lLocation.x; lLocation_vv.Y = lLocation.y; lLocation_vv.Z = lLocation.z;
  StackPushVector(lLocation_vv);
  StackPushObject(lLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(214, 1);

unlock(actionJumpToLocation_mutex, "actionJumpToLocation");
  
};

void NWScriptI::actionJumpToObject(const NWN::NWObject& oToJumpTo, bool bWalkStraightLineToPoint, const Ice::Current& ice) {
  if (oToJumpTo.id < 0 || oToJumpTo.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionJumpToObject_mutex, "actionJumpToObject");
  callCounter += 1;
  StackPushInteger(bWalkStraightLineToPoint == true ? 1 : 0);
  StackPushObject(oToJumpTo.id);

  VM_ExecuteCommand(196, 2);

unlock(actionJumpToObject_mutex, "actionJumpToObject");
  
};

void NWScriptI::actionLockObject(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionLockObject_mutex, "actionLockObject");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(484, 1);

unlock(actionLockObject_mutex, "actionLockObject");
  
};

void NWScriptI::actionMoveAwayFromLocation(const NWN::NWLocation& lMoveAwayFrom, bool bRun, Ice::Float fMoveAwayRange, const Ice::Current& ice) {
  if (lMoveAwayFrom.area.id < 0) throw NWN::InvalidObjectException();
  lock(actionMoveAwayFromLocation_mutex, "actionMoveAwayFromLocation");
  callCounter += 1;
  StackPushFloat(fMoveAwayRange);
  StackPushInteger(bRun == true ? 1 : 0);
  
  StackPushFloat(lMoveAwayFrom.facing);
  Vector lMoveAwayFrom_vv;
  lMoveAwayFrom_vv.X = lMoveAwayFrom.x; lMoveAwayFrom_vv.Y = lMoveAwayFrom.y; lMoveAwayFrom_vv.Z = lMoveAwayFrom.z;
  StackPushVector(lMoveAwayFrom_vv);
  StackPushObject(lMoveAwayFrom.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(360, 3);

unlock(actionMoveAwayFromLocation_mutex, "actionMoveAwayFromLocation");
  
};

void NWScriptI::actionMoveAwayFromObject(const NWN::NWObject& oFleeFrom, bool bRun, Ice::Float fMoveAwayRange, const Ice::Current& ice) {
  if (oFleeFrom.id < 0 || oFleeFrom.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionMoveAwayFromObject_mutex, "actionMoveAwayFromObject");
  callCounter += 1;
  StackPushFloat(fMoveAwayRange);
  StackPushInteger(bRun == true ? 1 : 0);
  StackPushObject(oFleeFrom.id);

  VM_ExecuteCommand(23, 3);

unlock(actionMoveAwayFromObject_mutex, "actionMoveAwayFromObject");
  
};

void NWScriptI::actionMoveToLocation(const NWN::NWLocation& lDestination, bool bRun, const Ice::Current& ice) {
  if (lDestination.area.id < 0) throw NWN::InvalidObjectException();
  lock(actionMoveToLocation_mutex, "actionMoveToLocation");
  callCounter += 1;
  StackPushInteger(bRun == true ? 1 : 0);
  
  StackPushFloat(lDestination.facing);
  Vector lDestination_vv;
  lDestination_vv.X = lDestination.x; lDestination_vv.Y = lDestination.y; lDestination_vv.Z = lDestination.z;
  StackPushVector(lDestination_vv);
  StackPushObject(lDestination.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(21, 2);

unlock(actionMoveToLocation_mutex, "actionMoveToLocation");
  
};

void NWScriptI::actionMoveToObject(const NWN::NWObject& oMoveTo, bool bRun, Ice::Float fRange, const Ice::Current& ice) {
  if (oMoveTo.id < 0 || oMoveTo.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionMoveToObject_mutex, "actionMoveToObject");
  callCounter += 1;
  StackPushFloat(fRange);
  StackPushInteger(bRun == true ? 1 : 0);
  StackPushObject(oMoveTo.id);

  VM_ExecuteCommand(22, 3);

unlock(actionMoveToObject_mutex, "actionMoveToObject");
  
};

void NWScriptI::actionOpenDoor(const NWN::NWObject& oDoor, const Ice::Current& ice) {
  if (oDoor.id < 0 || oDoor.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionOpenDoor_mutex, "actionOpenDoor");
  callCounter += 1;
  StackPushObject(oDoor.id);

  VM_ExecuteCommand(43, 1);

unlock(actionOpenDoor_mutex, "actionOpenDoor");
  
};

void NWScriptI::actionPauseConversation(const Ice::Current& ice) {
  lock(actionPauseConversation_mutex, "actionPauseConversation");
  callCounter += 1;

  VM_ExecuteCommand(205, 0);

unlock(actionPauseConversation_mutex, "actionPauseConversation");
  
};

void NWScriptI::actionPickUpItem(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionPickUpItem_mutex, "actionPickUpItem");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(34, 1);

unlock(actionPickUpItem_mutex, "actionPickUpItem");
  
};

void NWScriptI::actionPlayAnimation(Ice::Int nAnimation, Ice::Float fSpeed, Ice::Float fDurationSeconds, const Ice::Current& ice) {
  lock(actionPlayAnimation_mutex, "actionPlayAnimation");
  callCounter += 1;
  StackPushFloat(fDurationSeconds);
  StackPushFloat(fSpeed);
  StackPushInteger(nAnimation);

  VM_ExecuteCommand(40, 3);

unlock(actionPlayAnimation_mutex, "actionPlayAnimation");
  
};

void NWScriptI::actionPutDownItem(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionPutDownItem_mutex, "actionPutDownItem");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(35, 1);

unlock(actionPutDownItem_mutex, "actionPutDownItem");
  
};

void NWScriptI::actionRandomWalk(const Ice::Current& ice) {
  lock(actionRandomWalk_mutex, "actionRandomWalk");
  callCounter += 1;

  VM_ExecuteCommand(20, 0);

unlock(actionRandomWalk_mutex, "actionRandomWalk");
  
};

void NWScriptI::actionRest(bool bCreatureToEnemyLineOfSightCheck, const Ice::Current& ice) {
  lock(actionRest_mutex, "actionRest");
  callCounter += 1;
  StackPushInteger(bCreatureToEnemyLineOfSightCheck == true ? 1 : 0);

  VM_ExecuteCommand(402, 1);

unlock(actionRest_mutex, "actionRest");
  
};

void NWScriptI::actionResumeConversation(const Ice::Current& ice) {
  lock(actionResumeConversation_mutex, "actionResumeConversation");
  callCounter += 1;

  VM_ExecuteCommand(206, 0);

unlock(actionResumeConversation_mutex, "actionResumeConversation");
  
};

void NWScriptI::actionSit(const NWN::NWObject& oChair, const Ice::Current& ice) {
  if (oChair.id < 0 || oChair.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionSit_mutex, "actionSit");
  callCounter += 1;
  StackPushObject(oChair.id);

  VM_ExecuteCommand(194, 1);

unlock(actionSit_mutex, "actionSit");
  
};

void NWScriptI::actionSpeakString(const std::string& sStringToSpeak, NWN::TalkVolume tTalkVolume, const Ice::Current& ice) {
  lock(actionSpeakString_mutex, "actionSpeakString");
  callCounter += 1;
  StackPushInteger(enum_TalkVolume_2_long(tTalkVolume));
  
  StackPushString(sStringToSpeak.c_str());

  VM_ExecuteCommand(39, 2);

unlock(actionSpeakString_mutex, "actionSpeakString");
  
};

void NWScriptI::actionSpeakStringByStrRef(Ice::Int nStrRef, NWN::TalkVolume tTalkVolume, const Ice::Current& ice) {
  lock(actionSpeakStringByStrRef_mutex, "actionSpeakStringByStrRef");
  callCounter += 1;
  StackPushInteger(enum_TalkVolume_2_long(tTalkVolume));
  
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(240, 2);

unlock(actionSpeakStringByStrRef_mutex, "actionSpeakStringByStrRef");
  
};

void NWScriptI::actionStartConversation(const NWN::NWObject& oObjectToConverseWith, const std::string& sDialogResRef, bool bPrivateConversation, bool bPlayHello, const Ice::Current& ice) {
  if (oObjectToConverseWith.id < 0 || oObjectToConverseWith.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionStartConversation_mutex, "actionStartConversation");
  callCounter += 1;
  StackPushInteger(bPlayHello == true ? 1 : 0);
  StackPushInteger(bPrivateConversation == true ? 1 : 0);
  StackPushString(sDialogResRef.c_str());
  StackPushObject(oObjectToConverseWith.id);

  VM_ExecuteCommand(204, 4);

unlock(actionStartConversation_mutex, "actionStartConversation");
  
};

void NWScriptI::actionTakeItem(const NWN::NWObject& oItem, const NWN::NWObject& oTakeFrom, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oTakeFrom.id < 0 || oTakeFrom.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionTakeItem_mutex, "actionTakeItem");
  callCounter += 1;
  StackPushObject(oTakeFrom.id);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(136, 2);

unlock(actionTakeItem_mutex, "actionTakeItem");
  
};

void NWScriptI::actionUnequipItem(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionUnequipItem_mutex, "actionUnequipItem");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(33, 1);

unlock(actionUnequipItem_mutex, "actionUnequipItem");
  
};

void NWScriptI::actionUnlockObject(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionUnlockObject_mutex, "actionUnlockObject");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(483, 1);

unlock(actionUnlockObject_mutex, "actionUnlockObject");
  
};

void NWScriptI::actionUseFeat(Ice::Int nFeat, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionUseFeat_mutex, "actionUseFeat");
  callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushInteger(nFeat);

  VM_ExecuteCommand(287, 2);

unlock(actionUseFeat_mutex, "actionUseFeat");
  
};

void NWScriptI::actionUseSkill(Ice::Int nSkill, const NWN::NWObject& oTarget, Ice::Int nSubSkill, const NWN::NWObject& oItemUsed, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oItemUsed.id < 0 || oItemUsed.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(actionUseSkill_mutex, "actionUseSkill");
  callCounter += 1;
  StackPushObject(oItemUsed.id);
  StackPushInteger(nSubSkill);
  StackPushObject(oTarget.id);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(288, 4);

unlock(actionUseSkill_mutex, "actionUseSkill");
  
};

void NWScriptI::actionWait(Ice::Float fSeconds, const Ice::Current& ice) {
  lock(actionWait_mutex, "actionWait");
  callCounter += 1;
  StackPushFloat(fSeconds);

  VM_ExecuteCommand(202, 1);

unlock(actionWait_mutex, "actionWait");
  
};

void NWScriptI::activatePortal(const NWN::NWObject& oTarget, const std::string& sIPaddress, const std::string& sPassword, const std::string& sWaypointTag, bool bSeemless, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(activatePortal_mutex, "activatePortal");
  callCounter += 1;
  StackPushInteger(bSeemless == true ? 1 : 0);
  StackPushString(sWaypointTag.c_str());
  StackPushString(sPassword.c_str());
  StackPushString(sIPaddress.c_str());
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(474, 5);

unlock(activatePortal_mutex, "activatePortal");
  
};

void NWScriptI::addHenchman(const NWN::NWObject& oMaster, const NWN::NWObject& oHenchman, const Ice::Current& ice) {
  if (oMaster.id < 0 || oMaster.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oHenchman.id < 0 || oHenchman.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(addHenchman_mutex, "addHenchman");
  callCounter += 1;
  StackPushObject(oHenchman.id);
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(365, 2);

unlock(addHenchman_mutex, "addHenchman");
  
};

void NWScriptI::addItemProperty(NWN::DurationType tDurationType, const NWN::NWItemProperty& ipProperty, const NWN::NWObject& oItem, Ice::Float fDuration, const Ice::Current& ice) {
  if (iprpMap.find(ipProperty.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(addItemProperty_mutex, "addItemProperty");
  callCounter += 1;
  StackPushFloat(fDuration);
  StackPushObject(oItem.id);
  CGameEffect *ipProperty_ptr = iprpMap.find(ipProperty.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, ipProperty_ptr);
  StackPushInteger(enum_DurationType_2_long(tDurationType));
  

  VM_ExecuteCommand(609, 4);

unlock(addItemProperty_mutex, "addItemProperty");
  
};

void NWScriptI::addJournalQuestEntry(const std::string& szPlotID, Ice::Int nState, const NWN::NWObject& oCreature, bool bAllPartyMembers, bool bAllPlayers, bool bAllowOverrideHigher, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(addJournalQuestEntry_mutex, "addJournalQuestEntry");
  callCounter += 1;
  StackPushInteger(bAllowOverrideHigher == true ? 1 : 0);
  StackPushInteger(bAllPlayers == true ? 1 : 0);
  StackPushInteger(bAllPartyMembers == true ? 1 : 0);
  StackPushObject(oCreature.id);
  StackPushInteger(nState);
  StackPushString(szPlotID.c_str());

  VM_ExecuteCommand(367, 6);

unlock(addJournalQuestEntry_mutex, "addJournalQuestEntry");
  
};

void NWScriptI::addToParty(const NWN::NWObject& oPC, const NWN::NWObject& oPartyLeader, const Ice::Current& ice) {
  if (oPC.id < 0 || oPC.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oPartyLeader.id < 0 || oPartyLeader.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(addToParty_mutex, "addToParty");
  callCounter += 1;
  StackPushObject(oPartyLeader.id);
  StackPushObject(oPC.id);

  VM_ExecuteCommand(572, 2);

unlock(addToParty_mutex, "addToParty");
  
};

void NWScriptI::adjustAlignment(const NWN::NWObject& oSubject, NWN::Alignment tAlignment, Ice::Int nShift, bool bAllPartyMembers, const Ice::Current& ice) {
  if (oSubject.id < 0 || oSubject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(adjustAlignment_mutex, "adjustAlignment");
  callCounter += 1;
  StackPushInteger(bAllPartyMembers == true ? 1 : 0);
  StackPushInteger(nShift);
  StackPushInteger(enum_Alignment_2_long(tAlignment));
  
  StackPushObject(oSubject.id);

  VM_ExecuteCommand(201, 4);

unlock(adjustAlignment_mutex, "adjustAlignment");
  
};

void NWScriptI::adjustReputation(const NWN::NWObject& oTarget, const NWN::NWObject& oSourceFactionMember, Ice::Int nAdjustment, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSourceFactionMember.id < 0 || oSourceFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(adjustReputation_mutex, "adjustReputation");
  callCounter += 1;
  StackPushInteger(nAdjustment);
  StackPushObject(oSourceFactionMember.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(209, 3);

unlock(adjustReputation_mutex, "adjustReputation");
  
};

void NWScriptI::ambientSoundChangeDay(const NWN::NWObject& oArea, Ice::Int nTrack, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(ambientSoundChangeDay_mutex, "ambientSoundChangeDay");
  callCounter += 1;
  StackPushInteger(nTrack);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(435, 2);

unlock(ambientSoundChangeDay_mutex, "ambientSoundChangeDay");
  
};

void NWScriptI::ambientSoundChangeNight(const NWN::NWObject& oArea, Ice::Int nTrack, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(ambientSoundChangeNight_mutex, "ambientSoundChangeNight");
  callCounter += 1;
  StackPushInteger(nTrack);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(436, 2);

unlock(ambientSoundChangeNight_mutex, "ambientSoundChangeNight");
  
};

void NWScriptI::ambientSoundPlay(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(ambientSoundPlay_mutex, "ambientSoundPlay");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(433, 1);

unlock(ambientSoundPlay_mutex, "ambientSoundPlay");
  
};

void NWScriptI::ambientSoundSetDayVolume(const NWN::NWObject& oArea, Ice::Int nVolume, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(ambientSoundSetDayVolume_mutex, "ambientSoundSetDayVolume");
  callCounter += 1;
  StackPushInteger(nVolume);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(567, 2);

unlock(ambientSoundSetDayVolume_mutex, "ambientSoundSetDayVolume");
  
};

void NWScriptI::ambientSoundSetNightVolume(const NWN::NWObject& oArea, Ice::Int nVolume, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(ambientSoundSetNightVolume_mutex, "ambientSoundSetNightVolume");
  callCounter += 1;
  StackPushInteger(nVolume);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(568, 2);

unlock(ambientSoundSetNightVolume_mutex, "ambientSoundSetNightVolume");
  
};

void NWScriptI::ambientSoundStop(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(ambientSoundStop_mutex, "ambientSoundStop");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(434, 1);

unlock(ambientSoundStop_mutex, "ambientSoundStop");
  
};

NWN::NWVector NWScriptI::angleToVector(Ice::Float fAngle, const Ice::Current& ice) {
  lock(angleToVector_mutex, "angleToVector");
  callCounter += 1;
  StackPushFloat(fAngle);

  VM_ExecuteCommand(144, 1);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock(angleToVector_mutex, "angleToVector");
  return nv;
};

void NWScriptI::applyEffectAtLocation(NWN::DurationType tDurationType, const NWN::NWEffect& eEffect, const NWN::NWLocation& lLocation, Ice::Float fDuration, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  if (lLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(applyEffectAtLocation_mutex, "applyEffectAtLocation");
  callCounter += 1;
  StackPushFloat(fDuration);
  
  StackPushFloat(lLocation.facing);
  Vector lLocation_vv;
  lLocation_vv.X = lLocation.x; lLocation_vv.Y = lLocation.y; lLocation_vv.Z = lLocation.z;
  StackPushVector(lLocation_vv);
  StackPushObject(lLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
  StackPushInteger(enum_DurationType_2_long(tDurationType));
  

  VM_ExecuteCommand(216, 4);

unlock(applyEffectAtLocation_mutex, "applyEffectAtLocation");
  
};

void NWScriptI::applyEffectToObject(NWN::DurationType tDurationType, const NWN::NWEffect& eEffect, const NWN::NWObject& oTarget, Ice::Float fDuration, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(applyEffectToObject_mutex, "applyEffectToObject");
  callCounter += 1;
  StackPushFloat(fDuration);
  StackPushObject(oTarget.id);
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
  StackPushInteger(enum_DurationType_2_long(tDurationType));
  

  VM_ExecuteCommand(220, 4);

unlock(applyEffectToObject_mutex, "applyEffectToObject");
  
};

Ice::Float NWScriptI::asin(Ice::Float fValue, const Ice::Current& ice) {
  lock(asin_mutex, "asin");
  callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(72, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(asin_mutex, "asin");
  return fRetVal;
};

NWN::NWItemProperty NWScriptI::badBadReplaceMeThisDoesNothing(const Ice::Current& ice) {
  lock(badBadReplaceMeThisDoesNothing_mutex, "badBadReplaceMeThisDoesNothing");
  callCounter += 1;

  VM_ExecuteCommand(676, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(badBadReplaceMeThisDoesNothing_mutex, "badBadReplaceMeThisDoesNothing");
  return e;
};

Ice::Int NWScriptI::beginConversation(const std::string& sResRef, const NWN::NWObject& oObjectToDialog, const Ice::Current& ice) {
  if (oObjectToDialog.id < 0 || oObjectToDialog.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(beginConversation_mutex, "beginConversation");
  callCounter += 1;
  StackPushObject(oObjectToDialog.id);
  StackPushString(sResRef.c_str());

  VM_ExecuteCommand(255, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(beginConversation_mutex, "beginConversation");
  return nRetVal;
};

void NWScriptI::blackScreen(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(blackScreen_mutex, "blackScreen");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(698, 1);

unlock(blackScreen_mutex, "blackScreen");
  
};

void NWScriptI::bootPC(const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(bootPC_mutex, "bootPC");
  callCounter += 1;
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(565, 1);

unlock(bootPC_mutex, "bootPC");
  
};

void NWScriptI::changeFaction(const NWN::NWObject& oObjectToChangeFaction, const NWN::NWObject& oMemberOfFactionToJoin, const Ice::Current& ice) {
  if (oObjectToChangeFaction.id < 0 || oObjectToChangeFaction.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oMemberOfFactionToJoin.id < 0 || oMemberOfFactionToJoin.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(changeFaction_mutex, "changeFaction");
  callCounter += 1;
  StackPushObject(oMemberOfFactionToJoin.id);
  StackPushObject(oObjectToChangeFaction.id);

  VM_ExecuteCommand(173, 2);

unlock(changeFaction_mutex, "changeFaction");
  
};

void NWScriptI::changeToStandardFaction(const NWN::NWObject& oCreatureToChange, NWN::StandardFaction tStandardFaction, const Ice::Current& ice) {
  if (oCreatureToChange.id < 0 || oCreatureToChange.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(changeToStandardFaction_mutex, "changeToStandardFaction");
  callCounter += 1;
  StackPushInteger(enum_StandardFaction_2_long(tStandardFaction));
  
  StackPushObject(oCreatureToChange.id);

  VM_ExecuteCommand(412, 2);

unlock(changeToStandardFaction_mutex, "changeToStandardFaction");
  
};

void NWScriptI::clearAllActions(bool bClearCombatState, const Ice::Current& ice) {
  lock(clearAllActions_mutex, "clearAllActions");
  callCounter += 1;
  StackPushInteger(bClearCombatState == true ? 1 : 0);

  VM_ExecuteCommand(9, 1);

unlock(clearAllActions_mutex, "clearAllActions");
  
};

void NWScriptI::clearPersonalReputation(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(clearPersonalReputation_mutex, "clearPersonalReputation");
  callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(389, 2);

unlock(clearPersonalReputation_mutex, "clearPersonalReputation");
  
};

NWN::NWObject NWScriptI::copyItem(const NWN::NWObject& oItem, const NWN::NWObject& oTargetInventory, bool bCopyVars, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oTargetInventory.id < 0 || oTargetInventory.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(copyItem_mutex, "copyItem");
  callCounter += 1;
  StackPushInteger(bCopyVars == true ? 1 : 0);
  StackPushObject(oTargetInventory.id);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(584, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(copyItem_mutex, "copyItem");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::copyItemAndModify(const NWN::NWObject& oItem, Ice::Int nType, Ice::Int nIndex, Ice::Int nNewValue, bool bCopyVars, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(copyItemAndModify_mutex, "copyItemAndModify");
  callCounter += 1;
  StackPushInteger(bCopyVars == true ? 1 : 0);
  StackPushInteger(nNewValue);
  StackPushInteger(nIndex);
  StackPushInteger(nType);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(731, 5);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(copyItemAndModify_mutex, "copyItemAndModify");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::copyObject(const NWN::NWObject& oSource, const NWN::NWLocation& locLocation, const NWN::NWObject& oOwner, const std::string& sNewTag, const Ice::Current& ice) {
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (locLocation.area.id < 0) throw NWN::InvalidObjectException();
  if (oOwner.id < 0 || oOwner.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(copyObject_mutex, "copyObject");
  callCounter += 1;
  StackPushString(sNewTag.c_str());
  StackPushObject(oOwner.id);
  
  StackPushFloat(locLocation.facing);
  Vector locLocation_vv;
  locLocation_vv.X = locLocation.x; locLocation_vv.Y = locLocation.y; locLocation_vv.Z = locLocation.z;
  StackPushVector(locLocation_vv);
  StackPushObject(locLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushObject(oSource.id);

  VM_ExecuteCommand(600, 4);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(copyObject_mutex, "copyObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Float NWScriptI::cos(Ice::Float fValue, const Ice::Current& ice) {
  lock(cos_mutex, "cos");
  callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(68, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(cos_mutex, "cos");
  return fRetVal;
};

NWN::NWObject NWScriptI::createItemOnObject(const std::string& sItemTemplate, const NWN::NWObject& oTarget, Ice::Int nStackSize, const std::string& sNewTag, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(createItemOnObject_mutex, "createItemOnObject");
  callCounter += 1;
  StackPushString(sNewTag.c_str());
  StackPushInteger(nStackSize);
  StackPushObject(oTarget.id);
  StackPushString(sItemTemplate.c_str());

  VM_ExecuteCommand(31, 4);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(createItemOnObject_mutex, "createItemOnObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::createObject(NWN::ObjectType tObjectType, const std::string& sTemplate, const NWN::NWLocation& lLocation, bool bUseAppearAnimation, const std::string& sNewTag, const Ice::Current& ice) {
  if (lLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(createObject_mutex, "createObject");
  callCounter += 1;
  StackPushString(sNewTag.c_str());
  StackPushInteger(bUseAppearAnimation == true ? 1 : 0);
  
  StackPushFloat(lLocation.facing);
  Vector lLocation_vv;
  lLocation_vv.X = lLocation.x; lLocation_vv.Y = lLocation.y; lLocation_vv.Z = lLocation.z;
  StackPushVector(lLocation_vv);
  StackPushObject(lLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushString(sTemplate.c_str());
  StackPushInteger(enum_ObjectType_2_long(tObjectType));
  

  VM_ExecuteCommand(243, 5);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(createObject_mutex, "createObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::createTrapAtLocation(NWN::TrapType tTrapType, const NWN::NWLocation& lLocation, Ice::Float fSize, const std::string& sTag, NWN::StandardFaction tStandardFaction, const std::string& sOnDisarmScript, const std::string& sOnTrapTriggeredScript, const Ice::Current& ice) {
  if (lLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(createTrapAtLocation_mutex, "createTrapAtLocation");
  callCounter += 1;
  StackPushString(sOnTrapTriggeredScript.c_str());
  StackPushString(sOnDisarmScript.c_str());
  StackPushInteger(enum_StandardFaction_2_long(tStandardFaction));
  
  StackPushString(sTag.c_str());
  StackPushFloat(fSize);
  
  StackPushFloat(lLocation.facing);
  Vector lLocation_vv;
  lLocation_vv.X = lLocation.x; lLocation_vv.Y = lLocation.y; lLocation_vv.Z = lLocation.z;
  StackPushVector(lLocation_vv);
  StackPushObject(lLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushInteger(enum_TrapType_2_long(tTrapType));
  

  VM_ExecuteCommand(809, 7);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(createTrapAtLocation_mutex, "createTrapAtLocation");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

void NWScriptI::createTrapOnObject(NWN::TrapType tTrapType, const NWN::NWObject& oObject, NWN::StandardFaction tStandardFaction, const std::string& sOnDisarmScript, const std::string& sOnTrapTriggeredScript, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(createTrapOnObject_mutex, "createTrapOnObject");
  callCounter += 1;
  StackPushString(sOnTrapTriggeredScript.c_str());
  StackPushString(sOnDisarmScript.c_str());
  StackPushInteger(enum_StandardFaction_2_long(tStandardFaction));
  
  StackPushObject(oObject.id);
  StackPushInteger(enum_TrapType_2_long(tTrapType));
  

  VM_ExecuteCommand(810, 5);

unlock(createTrapOnObject_mutex, "createTrapOnObject");
  
};

Ice::Int NWScriptI::d10(Ice::Int nNumDice, const Ice::Current& ice) {
  lock(d10_mutex, "d10");
  callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(100, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(d10_mutex, "d10");
  return nRetVal;
};

Ice::Int NWScriptI::d100(Ice::Int nNumDice, const Ice::Current& ice) {
  lock(d100_mutex, "d100");
  callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(103, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(d100_mutex, "d100");
  return nRetVal;
};

Ice::Int NWScriptI::d12(Ice::Int nNumDice, const Ice::Current& ice) {
  lock(d12_mutex, "d12");
  callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(101, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(d12_mutex, "d12");
  return nRetVal;
};

Ice::Int NWScriptI::d2(Ice::Int nNumDice, const Ice::Current& ice) {
  lock(d2_mutex, "d2");
  callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(95, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(d2_mutex, "d2");
  return nRetVal;
};

Ice::Int NWScriptI::d20(Ice::Int nNumDice, const Ice::Current& ice) {
  lock(d20_mutex, "d20");
  callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(102, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(d20_mutex, "d20");
  return nRetVal;
};

Ice::Int NWScriptI::d3(Ice::Int nNumDice, const Ice::Current& ice) {
  lock(d3_mutex, "d3");
  callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(96, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(d3_mutex, "d3");
  return nRetVal;
};

Ice::Int NWScriptI::d4(Ice::Int nNumDice, const Ice::Current& ice) {
  lock(d4_mutex, "d4");
  callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(97, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(d4_mutex, "d4");
  return nRetVal;
};

Ice::Int NWScriptI::d6(Ice::Int nNumDice, const Ice::Current& ice) {
  lock(d6_mutex, "d6");
  callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(98, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(d6_mutex, "d6");
  return nRetVal;
};

Ice::Int NWScriptI::d8(Ice::Int nNumDice, const Ice::Current& ice) {
  lock(d8_mutex, "d8");
  callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(99, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(d8_mutex, "d8");
  return nRetVal;
};

void NWScriptI::dayToNight(const NWN::NWObject& oPlayer, Ice::Float fTransitionTime, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(dayToNight_mutex, "dayToNight");
  callCounter += 1;
  StackPushFloat(fTransitionTime);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(750, 2);

unlock(dayToNight_mutex, "dayToNight");
  
};

void NWScriptI::decrementRemainingFeatUses(const NWN::NWObject& oCreature, Ice::Int nFeat, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(decrementRemainingFeatUses_mutex, "decrementRemainingFeatUses");
  callCounter += 1;
  StackPushInteger(nFeat);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(580, 2);

unlock(decrementRemainingFeatUses_mutex, "decrementRemainingFeatUses");
  
};

void NWScriptI::decrementRemainingSpellUses(const NWN::NWObject& oCreature, Ice::Int nSpell, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(decrementRemainingSpellUses_mutex, "decrementRemainingSpellUses");
  callCounter += 1;
  StackPushInteger(nSpell);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(581, 2);

unlock(decrementRemainingSpellUses_mutex, "decrementRemainingSpellUses");
  
};

void NWScriptI::deleteCampaignVariable(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(deleteCampaignVariable_mutex, "deleteCampaignVariable");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(601, 3);

unlock(deleteCampaignVariable_mutex, "deleteCampaignVariable");
  
};

void NWScriptI::deleteLocalFloat(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(deleteLocalFloat_mutex, "deleteLocalFloat");
  callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(266, 2);

unlock(deleteLocalFloat_mutex, "deleteLocalFloat");
  
};

void NWScriptI::deleteLocalInt(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(deleteLocalInt_mutex, "deleteLocalInt");
  callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(265, 2);

unlock(deleteLocalInt_mutex, "deleteLocalInt");
  
};

void NWScriptI::deleteLocalLocation(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(deleteLocalLocation_mutex, "deleteLocalLocation");
  callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(269, 2);

unlock(deleteLocalLocation_mutex, "deleteLocalLocation");
  
};

void NWScriptI::deleteLocalObject(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(deleteLocalObject_mutex, "deleteLocalObject");
  callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(268, 2);

unlock(deleteLocalObject_mutex, "deleteLocalObject");
  
};

void NWScriptI::deleteLocalString(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(deleteLocalString_mutex, "deleteLocalString");
  callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(267, 2);

unlock(deleteLocalString_mutex, "deleteLocalString");
  
};

void NWScriptI::destroyCampaignDatabase(const std::string& sCampaignName, const Ice::Current& ice) {
  lock(destroyCampaignDatabase_mutex, "destroyCampaignDatabase");
  callCounter += 1;
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(594, 1);

unlock(destroyCampaignDatabase_mutex, "destroyCampaignDatabase");
  
};

void NWScriptI::destroyObject(const NWN::NWObject& oDestroy, Ice::Float fDelay, const Ice::Current& ice) {
  if (oDestroy.id < 0 || oDestroy.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(destroyObject_mutex, "destroyObject");
  callCounter += 1;
  StackPushFloat(fDelay);
  StackPushObject(oDestroy.id);

  VM_ExecuteCommand(241, 2);

unlock(destroyObject_mutex, "destroyObject");
  
};

void NWScriptI::doDoorAction(const NWN::NWObject& oTargetDoor, NWN::DoorAction tDoorAction, const Ice::Current& ice) {
  if (oTargetDoor.id < 0 || oTargetDoor.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(doDoorAction_mutex, "doDoorAction");
  callCounter += 1;
  StackPushInteger(enum_DoorAction_2_long(tDoorAction));
  
  StackPushObject(oTargetDoor.id);

  VM_ExecuteCommand(338, 2);

unlock(doDoorAction_mutex, "doDoorAction");
  
};

void NWScriptI::doPlaceableObjectAction(const NWN::NWObject& oPlaceable, NWN::PlaceableAction tPlaceableAction, const Ice::Current& ice) {
  if (oPlaceable.id < 0 || oPlaceable.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(doPlaceableObjectAction_mutex, "doPlaceableObjectAction");
  callCounter += 1;
  StackPushInteger(enum_PlaceableAction_2_long(tPlaceableAction));
  
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(547, 2);

unlock(doPlaceableObjectAction_mutex, "doPlaceableObjectAction");
  
};

void NWScriptI::doSinglePlayerAutoSave(const Ice::Current& ice) {
  lock(doSinglePlayerAutoSave_mutex, "doSinglePlayerAutoSave");
  callCounter += 1;

  VM_ExecuteCommand(512, 0);

unlock(doSinglePlayerAutoSave_mutex, "doSinglePlayerAutoSave");
  
};

void NWScriptI::doWhirlwindAttack(bool bDisplayFeedback, bool bImproved, const Ice::Current& ice) {
  lock(doWhirlwindAttack_mutex, "doWhirlwindAttack");
  callCounter += 1;
  StackPushInteger(bImproved == true ? 1 : 0);
  StackPushInteger(bDisplayFeedback == true ? 1 : 0);

  VM_ExecuteCommand(709, 2);

unlock(doWhirlwindAttack_mutex, "doWhirlwindAttack");
  
};

NWN::NWEffect NWScriptI::effectACDecrease(Ice::Int nValue, NWN::ACModifyType tACModifyType, NWN::DamageType tDamageType, const Ice::Current& ice) {
  lock(effectACDecrease_mutex, "effectACDecrease");
  callCounter += 1;
  StackPushInteger(enum_DamageType_2_long(tDamageType));
  
  StackPushInteger(enum_ACModifyType_2_long(tACModifyType));
  
  StackPushInteger(nValue);

  VM_ExecuteCommand(450, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectACDecrease_mutex, "effectACDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectACIncrease(Ice::Int nValue, NWN::ACModifyType tACModifyType, NWN::DamageType tDamageType, const Ice::Current& ice) {
  lock(effectACIncrease_mutex, "effectACIncrease");
  callCounter += 1;
  StackPushInteger(enum_DamageType_2_long(tDamageType));
  
  StackPushInteger(enum_ACModifyType_2_long(tACModifyType));
  
  StackPushInteger(nValue);

  VM_ExecuteCommand(115, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectACIncrease_mutex, "effectACIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectAbilityDecrease(NWN::Ability tAbility, Ice::Int nModifyBy, const Ice::Current& ice) {
  lock(effectAbilityDecrease_mutex, "effectAbilityDecrease");
  callCounter += 1;
  StackPushInteger(nModifyBy);
  StackPushInteger(enum_Ability_2_long(tAbility));
  

  VM_ExecuteCommand(446, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectAbilityDecrease_mutex, "effectAbilityDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectAbilityIncrease(NWN::Ability tAbility, Ice::Int nModifyBy, const Ice::Current& ice) {
  lock(effectAbilityIncrease_mutex, "effectAbilityIncrease");
  callCounter += 1;
  StackPushInteger(nModifyBy);
  StackPushInteger(enum_Ability_2_long(tAbility));
  

  VM_ExecuteCommand(80, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectAbilityIncrease_mutex, "effectAbilityIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectAppear(Ice::Int nAnimation, const Ice::Current& ice) {
  lock(effectAppear_mutex, "effectAppear");
  callCounter += 1;
  StackPushInteger(nAnimation);

  VM_ExecuteCommand(482, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectAppear_mutex, "effectAppear");
  return e;
};

NWN::NWEffect NWScriptI::effectAreaOfEffect(Ice::Int nAreaEffectId, const std::string& sOnEnterScript, const std::string& sHeartbeatScript, const std::string& sOnExitScript, const Ice::Current& ice) {
  lock(effectAreaOfEffect_mutex, "effectAreaOfEffect");
  callCounter += 1;
  StackPushString(sOnExitScript.c_str());
  StackPushString(sHeartbeatScript.c_str());
  StackPushString(sOnEnterScript.c_str());
  StackPushInteger(nAreaEffectId);

  VM_ExecuteCommand(171, 4);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectAreaOfEffect_mutex, "effectAreaOfEffect");
  return e;
};

NWN::NWEffect NWScriptI::effectAttackDecrease(Ice::Int nPenalty, NWN::AttackBonus tAttackBonus, const Ice::Current& ice) {
  lock(effectAttackDecrease_mutex, "effectAttackDecrease");
  callCounter += 1;
  StackPushInteger(enum_AttackBonus_2_long(tAttackBonus));
  
  StackPushInteger(nPenalty);

  VM_ExecuteCommand(447, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectAttackDecrease_mutex, "effectAttackDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectAttackIncrease(Ice::Int nBonus, NWN::AttackBonus tAttackBonus, const Ice::Current& ice) {
  lock(effectAttackIncrease_mutex, "effectAttackIncrease");
  callCounter += 1;
  StackPushInteger(enum_AttackBonus_2_long(tAttackBonus));
  
  StackPushInteger(nBonus);

  VM_ExecuteCommand(118, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectAttackIncrease_mutex, "effectAttackIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectBeam(Ice::Int nBeamVisualEffect, const NWN::NWObject& oEffector, NWN::CreaturePart tCreaturePart, bool bMissEffect, const Ice::Current& ice) {
  if (oEffector.id < 0 || oEffector.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(effectBeam_mutex, "effectBeam");
  callCounter += 1;
  StackPushInteger(bMissEffect == true ? 1 : 0);
  StackPushInteger(enum_CreaturePart_2_long(tCreaturePart));
  
  StackPushObject(oEffector.id);
  StackPushInteger(nBeamVisualEffect);

  VM_ExecuteCommand(207, 4);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectBeam_mutex, "effectBeam");
  return e;
};

NWN::NWEffect NWScriptI::effectBlindness(const Ice::Current& ice) {
  lock(effectBlindness_mutex, "effectBlindness");
  callCounter += 1;

  VM_ExecuteCommand(468, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectBlindness_mutex, "effectBlindness");
  return e;
};

NWN::NWEffect NWScriptI::effectCharmed(const Ice::Current& ice) {
  lock(effectCharmed_mutex, "effectCharmed");
  callCounter += 1;

  VM_ExecuteCommand(156, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectCharmed_mutex, "effectCharmed");
  return e;
};

NWN::NWEffect NWScriptI::effectConcealment(Ice::Int nPercentage, NWN::MissChanceType tMissChanceType, const Ice::Current& ice) {
  lock(effectConcealment_mutex, "effectConcealment");
  callCounter += 1;
  StackPushInteger(enum_MissChanceType_2_long(tMissChanceType));
  
  StackPushInteger(nPercentage);

  VM_ExecuteCommand(458, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectConcealment_mutex, "effectConcealment");
  return e;
};

NWN::NWEffect NWScriptI::effectConfused(const Ice::Current& ice) {
  lock(effectConfused_mutex, "effectConfused");
  callCounter += 1;

  VM_ExecuteCommand(157, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectConfused_mutex, "effectConfused");
  return e;
};

NWN::NWEffect NWScriptI::effectCurse(Ice::Int nStrMod, Ice::Int nDexMod, Ice::Int nConMod, Ice::Int nIntMod, Ice::Int nWisMod, Ice::Int nChaMod, const Ice::Current& ice) {
  lock(effectCurse_mutex, "effectCurse");
  callCounter += 1;
  StackPushInteger(nChaMod);
  StackPushInteger(nWisMod);
  StackPushInteger(nIntMod);
  StackPushInteger(nConMod);
  StackPushInteger(nDexMod);
  StackPushInteger(nStrMod);

  VM_ExecuteCommand(138, 6);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectCurse_mutex, "effectCurse");
  return e;
};

NWN::NWEffect NWScriptI::effectCutsceneDominated(const Ice::Current& ice) {
  lock(effectCutsceneDominated_mutex, "effectCutsceneDominated");
  callCounter += 1;

  VM_ExecuteCommand(604, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectCutsceneDominated_mutex, "effectCutsceneDominated");
  return e;
};

NWN::NWEffect NWScriptI::effectCutsceneGhost(const Ice::Current& ice) {
  lock(effectCutsceneGhost_mutex, "effectCutsceneGhost");
  callCounter += 1;

  VM_ExecuteCommand(757, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectCutsceneGhost_mutex, "effectCutsceneGhost");
  return e;
};

NWN::NWEffect NWScriptI::effectCutsceneImmobilize(const Ice::Current& ice) {
  lock(effectCutsceneImmobilize_mutex, "effectCutsceneImmobilize");
  callCounter += 1;

  VM_ExecuteCommand(767, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectCutsceneImmobilize_mutex, "effectCutsceneImmobilize");
  return e;
};

NWN::NWEffect NWScriptI::effectCutsceneParalyze(const Ice::Current& ice) {
  lock(effectCutsceneParalyze_mutex, "effectCutsceneParalyze");
  callCounter += 1;

  VM_ExecuteCommand(585, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectCutsceneParalyze_mutex, "effectCutsceneParalyze");
  return e;
};

NWN::NWEffect NWScriptI::effectDamage(Ice::Int nDamageAmount, NWN::DamageType tDamageType, NWN::DamagePower tDamagePower, const Ice::Current& ice) {
  lock(effectDamage_mutex, "effectDamage");
  callCounter += 1;
  StackPushInteger(enum_DamagePower_2_long(tDamagePower));
  
  StackPushInteger(enum_DamageType_2_long(tDamageType));
  
  StackPushInteger(nDamageAmount);

  VM_ExecuteCommand(79, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDamage_mutex, "effectDamage");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageDecrease(Ice::Int nPenalty, NWN::DamageType tDamageType, const Ice::Current& ice) {
  lock(effectDamageDecrease_mutex, "effectDamageDecrease");
  callCounter += 1;
  StackPushInteger(enum_DamageType_2_long(tDamageType));
  
  StackPushInteger(nPenalty);

  VM_ExecuteCommand(448, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDamageDecrease_mutex, "effectDamageDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageImmunityDecrease(NWN::DamageType tDamageType, Ice::Int nPercentImmunity, const Ice::Current& ice) {
  lock(effectDamageImmunityDecrease_mutex, "effectDamageImmunityDecrease");
  callCounter += 1;
  StackPushInteger(nPercentImmunity);
  StackPushInteger(enum_DamageType_2_long(tDamageType));
  

  VM_ExecuteCommand(449, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDamageImmunityDecrease_mutex, "effectDamageImmunityDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageImmunityIncrease(NWN::DamageType tDamageType, Ice::Int nPercentImmunity, const Ice::Current& ice) {
  lock(effectDamageImmunityIncrease_mutex, "effectDamageImmunityIncrease");
  callCounter += 1;
  StackPushInteger(nPercentImmunity);
  StackPushInteger(enum_DamageType_2_long(tDamageType));
  

  VM_ExecuteCommand(275, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDamageImmunityIncrease_mutex, "effectDamageImmunityIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageIncrease(Ice::Int nBonus, NWN::DamageType tDamageType, const Ice::Current& ice) {
  lock(effectDamageIncrease_mutex, "effectDamageIncrease");
  callCounter += 1;
  StackPushInteger(enum_DamageType_2_long(tDamageType));
  
  StackPushInteger(nBonus);

  VM_ExecuteCommand(120, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDamageIncrease_mutex, "effectDamageIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageReduction(Ice::Int nAmount, NWN::DamagePower tDamagePower, Ice::Int nLimit, const Ice::Current& ice) {
  lock(effectDamageReduction_mutex, "effectDamageReduction");
  callCounter += 1;
  StackPushInteger(nLimit);
  StackPushInteger(enum_DamagePower_2_long(tDamagePower));
  
  StackPushInteger(nAmount);

  VM_ExecuteCommand(119, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDamageReduction_mutex, "effectDamageReduction");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageResistance(NWN::DamageType tDamageType, Ice::Int nAmount, Ice::Int nLimit, const Ice::Current& ice) {
  lock(effectDamageResistance_mutex, "effectDamageResistance");
  callCounter += 1;
  StackPushInteger(nLimit);
  StackPushInteger(nAmount);
  StackPushInteger(enum_DamageType_2_long(tDamageType));
  

  VM_ExecuteCommand(81, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDamageResistance_mutex, "effectDamageResistance");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageShield(Ice::Int nDamageAmount, Ice::Int nRandomAmount, NWN::DamageType tDamageType, const Ice::Current& ice) {
  lock(effectDamageShield_mutex, "effectDamageShield");
  callCounter += 1;
  StackPushInteger(enum_DamageType_2_long(tDamageType));
  
  StackPushInteger(nRandomAmount);
  StackPushInteger(nDamageAmount);

  VM_ExecuteCommand(487, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDamageShield_mutex, "effectDamageShield");
  return e;
};

NWN::NWEffect NWScriptI::effectDarkness(const Ice::Current& ice) {
  lock(effectDarkness_mutex, "effectDarkness");
  callCounter += 1;

  VM_ExecuteCommand(459, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDarkness_mutex, "effectDarkness");
  return e;
};

NWN::NWEffect NWScriptI::effectDazed(const Ice::Current& ice) {
  lock(effectDazed_mutex, "effectDazed");
  callCounter += 1;

  VM_ExecuteCommand(160, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDazed_mutex, "effectDazed");
  return e;
};

NWN::NWEffect NWScriptI::effectDeaf(const Ice::Current& ice) {
  lock(effectDeaf_mutex, "effectDeaf");
  callCounter += 1;

  VM_ExecuteCommand(150, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDeaf_mutex, "effectDeaf");
  return e;
};

NWN::NWEffect NWScriptI::effectDeath(bool bSpectacularDeath, bool bDisplayFeedback, const Ice::Current& ice) {
  lock(effectDeath_mutex, "effectDeath");
  callCounter += 1;
  StackPushInteger(bDisplayFeedback == true ? 1 : 0);
  StackPushInteger(bSpectacularDeath == true ? 1 : 0);

  VM_ExecuteCommand(133, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDeath_mutex, "effectDeath");
  return e;
};

NWN::NWEffect NWScriptI::effectDisappear(Ice::Int nAnimation, const Ice::Current& ice) {
  lock(effectDisappear_mutex, "effectDisappear");
  callCounter += 1;
  StackPushInteger(nAnimation);

  VM_ExecuteCommand(481, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDisappear_mutex, "effectDisappear");
  return e;
};

NWN::NWEffect NWScriptI::effectDisappearAppear(const NWN::NWLocation& lLocation, Ice::Int nAnimation, const Ice::Current& ice) {
  if (lLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(effectDisappearAppear_mutex, "effectDisappearAppear");
  callCounter += 1;
  StackPushInteger(nAnimation);
  
  StackPushFloat(lLocation.facing);
  Vector lLocation_vv;
  lLocation_vv.X = lLocation.x; lLocation_vv.Y = lLocation.y; lLocation_vv.Z = lLocation.z;
  StackPushVector(lLocation_vv);
  StackPushObject(lLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(480, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDisappearAppear_mutex, "effectDisappearAppear");
  return e;
};

NWN::NWEffect NWScriptI::effectDisease(Ice::Int nDiseaseType, const Ice::Current& ice) {
  lock(effectDisease_mutex, "effectDisease");
  callCounter += 1;
  StackPushInteger(nDiseaseType);

  VM_ExecuteCommand(251, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDisease_mutex, "effectDisease");
  return e;
};

NWN::NWEffect NWScriptI::effectDispelMagicAll(Ice::Int nCasterLevel, const Ice::Current& ice) {
  lock(effectDispelMagicAll_mutex, "effectDispelMagicAll");
  callCounter += 1;
  StackPushInteger(nCasterLevel);

  VM_ExecuteCommand(460, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDispelMagicAll_mutex, "effectDispelMagicAll");
  return e;
};

NWN::NWEffect NWScriptI::effectDispelMagicBest(Ice::Int nCasterLevel, const Ice::Current& ice) {
  lock(effectDispelMagicBest_mutex, "effectDispelMagicBest");
  callCounter += 1;
  StackPushInteger(nCasterLevel);

  VM_ExecuteCommand(473, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDispelMagicBest_mutex, "effectDispelMagicBest");
  return e;
};

NWN::NWEffect NWScriptI::effectDominated(const Ice::Current& ice) {
  lock(effectDominated_mutex, "effectDominated");
  callCounter += 1;

  VM_ExecuteCommand(159, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectDominated_mutex, "effectDominated");
  return e;
};

NWN::NWEffect NWScriptI::effectEntangle(const Ice::Current& ice) {
  lock(effectEntangle_mutex, "effectEntangle");
  callCounter += 1;

  VM_ExecuteCommand(130, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectEntangle_mutex, "effectEntangle");
  return e;
};

NWN::NWEffect NWScriptI::effectEthereal(const Ice::Current& ice) {
  lock(effectEthereal_mutex, "effectEthereal");
  callCounter += 1;

  VM_ExecuteCommand(711, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectEthereal_mutex, "effectEthereal");
  return e;
};

NWN::NWEffect NWScriptI::effectFrightened(const Ice::Current& ice) {
  lock(effectFrightened_mutex, "effectFrightened");
  callCounter += 1;

  VM_ExecuteCommand(158, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectFrightened_mutex, "effectFrightened");
  return e;
};

NWN::NWEffect NWScriptI::effectHaste(const Ice::Current& ice) {
  lock(effectHaste_mutex, "effectHaste");
  callCounter += 1;

  VM_ExecuteCommand(270, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectHaste_mutex, "effectHaste");
  return e;
};

NWN::NWEffect NWScriptI::effectHeal(Ice::Int nDamageToHeal, const Ice::Current& ice) {
  lock(effectHeal_mutex, "effectHeal");
  callCounter += 1;
  StackPushInteger(nDamageToHeal);

  VM_ExecuteCommand(78, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectHeal_mutex, "effectHeal");
  return e;
};

NWN::NWEffect NWScriptI::effectHitPointChangeWhenDying(Ice::Float fHitPointChangePerRound, const Ice::Current& ice) {
  lock(effectHitPointChangeWhenDying_mutex, "effectHitPointChangeWhenDying");
  callCounter += 1;
  StackPushFloat(fHitPointChangePerRound);

  VM_ExecuteCommand(387, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectHitPointChangeWhenDying_mutex, "effectHitPointChangeWhenDying");
  return e;
};

NWN::NWEffect NWScriptI::effectImmunity(NWN::ImmunityType tImmunityType, const Ice::Current& ice) {
  lock(effectImmunity_mutex, "effectImmunity");
  callCounter += 1;
  StackPushInteger(enum_ImmunityType_2_long(tImmunityType));
  

  VM_ExecuteCommand(273, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectImmunity_mutex, "effectImmunity");
  return e;
};

NWN::NWEffect NWScriptI::effectInvisibility(Ice::Int nInvisibilityType, const Ice::Current& ice) {
  lock(effectInvisibility_mutex, "effectInvisibility");
  callCounter += 1;
  StackPushInteger(nInvisibilityType);

  VM_ExecuteCommand(457, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectInvisibility_mutex, "effectInvisibility");
  return e;
};

NWN::NWEffect NWScriptI::effectKnockdown(const Ice::Current& ice) {
  lock(effectKnockdown_mutex, "effectKnockdown");
  callCounter += 1;

  VM_ExecuteCommand(134, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectKnockdown_mutex, "effectKnockdown");
  return e;
};

NWN::NWEffect NWScriptI::effectLinkEffects(const NWN::NWEffect& eChildEffect, const NWN::NWEffect& eParentEffect, const Ice::Current& ice) {
  if (effectMap.find(eChildEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  if (effectMap.find(eParentEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(effectLinkEffects_mutex, "effectLinkEffects");
  callCounter += 1;
  CGameEffect *eParentEffect_ptr = effectMap.find(eParentEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eParentEffect_ptr);
  CGameEffect *eChildEffect_ptr = effectMap.find(eChildEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eChildEffect_ptr);

  VM_ExecuteCommand(199, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectLinkEffects_mutex, "effectLinkEffects");
  return e;
};

NWN::NWEffect NWScriptI::effectMissChance(Ice::Int nPercentage, NWN::MissChanceType tMissChanceType, const Ice::Current& ice) {
  lock(effectMissChance_mutex, "effectMissChance");
  callCounter += 1;
  StackPushInteger(enum_MissChanceType_2_long(tMissChanceType));
  
  StackPushInteger(nPercentage);

  VM_ExecuteCommand(477, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectMissChance_mutex, "effectMissChance");
  return e;
};

NWN::NWEffect NWScriptI::effectModifyAttacks(Ice::Int nAttacks, const Ice::Current& ice) {
  lock(effectModifyAttacks_mutex, "effectModifyAttacks");
  callCounter += 1;
  StackPushInteger(nAttacks);

  VM_ExecuteCommand(485, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectModifyAttacks_mutex, "effectModifyAttacks");
  return e;
};

NWN::NWEffect NWScriptI::effectMovementSpeedDecrease(Ice::Int nPercentChange, const Ice::Current& ice) {
  lock(effectMovementSpeedDecrease_mutex, "effectMovementSpeedDecrease");
  callCounter += 1;
  StackPushInteger(nPercentChange);

  VM_ExecuteCommand(451, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectMovementSpeedDecrease_mutex, "effectMovementSpeedDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectMovementSpeedIncrease(Ice::Int nPercentChange, const Ice::Current& ice) {
  lock(effectMovementSpeedIncrease_mutex, "effectMovementSpeedIncrease");
  callCounter += 1;
  StackPushInteger(nPercentChange);

  VM_ExecuteCommand(165, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectMovementSpeedIncrease_mutex, "effectMovementSpeedIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectNegativeLevel(Ice::Int nNumLevels, bool bHPBonus, const Ice::Current& ice) {
  lock(effectNegativeLevel_mutex, "effectNegativeLevel");
  callCounter += 1;
  StackPushInteger(bHPBonus == true ? 1 : 0);
  StackPushInteger(nNumLevels);

  VM_ExecuteCommand(462, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectNegativeLevel_mutex, "effectNegativeLevel");
  return e;
};

NWN::NWEffect NWScriptI::effectParalyze(const Ice::Current& ice) {
  lock(effectParalyze_mutex, "effectParalyze");
  callCounter += 1;

  VM_ExecuteCommand(148, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectParalyze_mutex, "effectParalyze");
  return e;
};

NWN::NWEffect NWScriptI::effectPetrify(const Ice::Current& ice) {
  lock(effectPetrify_mutex, "effectPetrify");
  callCounter += 1;

  VM_ExecuteCommand(583, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectPetrify_mutex, "effectPetrify");
  return e;
};

NWN::NWEffect NWScriptI::effectPoison(Ice::Int nPoisonType, const Ice::Current& ice) {
  lock(effectPoison_mutex, "effectPoison");
  callCounter += 1;
  StackPushInteger(nPoisonType);

  VM_ExecuteCommand(250, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectPoison_mutex, "effectPoison");
  return e;
};

NWN::NWEffect NWScriptI::effectPolymorph(Ice::Int nPolymorphSelection, bool bLocked, const Ice::Current& ice) {
  lock(effectPolymorph_mutex, "effectPolymorph");
  callCounter += 1;
  StackPushInteger(bLocked == true ? 1 : 0);
  StackPushInteger(nPolymorphSelection);

  VM_ExecuteCommand(463, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectPolymorph_mutex, "effectPolymorph");
  return e;
};

NWN::NWEffect NWScriptI::effectRegenerate(Ice::Int nAmount, Ice::Float fIntervalSeconds, const Ice::Current& ice) {
  lock(effectRegenerate_mutex, "effectRegenerate");
  callCounter += 1;
  StackPushFloat(fIntervalSeconds);
  StackPushInteger(nAmount);

  VM_ExecuteCommand(164, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectRegenerate_mutex, "effectRegenerate");
  return e;
};

NWN::NWEffect NWScriptI::effectResurrection(const Ice::Current& ice) {
  lock(effectResurrection_mutex, "effectResurrection");
  callCounter += 1;

  VM_ExecuteCommand(82, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectResurrection_mutex, "effectResurrection");
  return e;
};

NWN::NWEffect NWScriptI::effectSanctuary(Ice::Int nDifficultyClass, const Ice::Current& ice) {
  lock(effectSanctuary_mutex, "effectSanctuary");
  callCounter += 1;
  StackPushInteger(nDifficultyClass);

  VM_ExecuteCommand(464, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSanctuary_mutex, "effectSanctuary");
  return e;
};

NWN::NWEffect NWScriptI::effectSavingThrowDecrease(Ice::Int nSave, Ice::Int nValue, NWN::SaveType tSaveType, const Ice::Current& ice) {
  lock(effectSavingThrowDecrease_mutex, "effectSavingThrowDecrease");
  callCounter += 1;
  StackPushInteger(enum_SaveType_2_long(tSaveType));
  
  StackPushInteger(nValue);
  StackPushInteger(nSave);

  VM_ExecuteCommand(452, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSavingThrowDecrease_mutex, "effectSavingThrowDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectSavingThrowIncrease(Ice::Int nSave, Ice::Int nValue, NWN::SaveType tSaveType, const Ice::Current& ice) {
  lock(effectSavingThrowIncrease_mutex, "effectSavingThrowIncrease");
  callCounter += 1;
  StackPushInteger(enum_SaveType_2_long(tSaveType));
  
  StackPushInteger(nValue);
  StackPushInteger(nSave);

  VM_ExecuteCommand(117, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSavingThrowIncrease_mutex, "effectSavingThrowIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectSeeInvisible(const Ice::Current& ice) {
  lock(effectSeeInvisible_mutex, "effectSeeInvisible");
  callCounter += 1;

  VM_ExecuteCommand(466, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSeeInvisible_mutex, "effectSeeInvisible");
  return e;
};

NWN::NWEffect NWScriptI::effectSilence(const Ice::Current& ice) {
  lock(effectSilence_mutex, "effectSilence");
  callCounter += 1;

  VM_ExecuteCommand(252, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSilence_mutex, "effectSilence");
  return e;
};

NWN::NWEffect NWScriptI::effectSkillDecrease(Ice::Int nSkill, Ice::Int nValue, const Ice::Current& ice) {
  lock(effectSkillDecrease_mutex, "effectSkillDecrease");
  callCounter += 1;
  StackPushInteger(nValue);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(453, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSkillDecrease_mutex, "effectSkillDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectSkillIncrease(Ice::Int nSkill, Ice::Int nValue, const Ice::Current& ice) {
  lock(effectSkillIncrease_mutex, "effectSkillIncrease");
  callCounter += 1;
  StackPushInteger(nValue);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(351, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSkillIncrease_mutex, "effectSkillIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectSleep(const Ice::Current& ice) {
  lock(effectSleep_mutex, "effectSleep");
  callCounter += 1;

  VM_ExecuteCommand(154, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSleep_mutex, "effectSleep");
  return e;
};

NWN::NWEffect NWScriptI::effectSlow(const Ice::Current& ice) {
  lock(effectSlow_mutex, "effectSlow");
  callCounter += 1;

  VM_ExecuteCommand(271, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSlow_mutex, "effectSlow");
  return e;
};

NWN::NWEffect NWScriptI::effectSpellFailure(Ice::Int nPercent, NWN::SpellSchool tSpellSchool, const Ice::Current& ice) {
  lock(effectSpellFailure_mutex, "effectSpellFailure");
  callCounter += 1;
  StackPushInteger(enum_SpellSchool_2_long(tSpellSchool));
  
  StackPushInteger(nPercent);

  VM_ExecuteCommand(690, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSpellFailure_mutex, "effectSpellFailure");
  return e;
};

NWN::NWEffect NWScriptI::effectSpellImmunity(Ice::Int nImmunityToSpell, const Ice::Current& ice) {
  lock(effectSpellImmunity_mutex, "effectSpellImmunity");
  callCounter += 1;
  StackPushInteger(nImmunityToSpell);

  VM_ExecuteCommand(149, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSpellImmunity_mutex, "effectSpellImmunity");
  return e;
};

NWN::NWEffect NWScriptI::effectSpellLevelAbsorption(Ice::Int nMaxSpellLevelAbsorbed, Ice::Int nTotalSpellLevelsAbsorbed, NWN::SpellSchool tSpellSchool, const Ice::Current& ice) {
  lock(effectSpellLevelAbsorption_mutex, "effectSpellLevelAbsorption");
  callCounter += 1;
  StackPushInteger(enum_SpellSchool_2_long(tSpellSchool));
  
  StackPushInteger(nTotalSpellLevelsAbsorbed);
  StackPushInteger(nMaxSpellLevelAbsorbed);

  VM_ExecuteCommand(472, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSpellLevelAbsorption_mutex, "effectSpellLevelAbsorption");
  return e;
};

NWN::NWEffect NWScriptI::effectSpellResistanceDecrease(Ice::Int nValue, const Ice::Current& ice) {
  lock(effectSpellResistanceDecrease_mutex, "effectSpellResistanceDecrease");
  callCounter += 1;
  StackPushInteger(nValue);

  VM_ExecuteCommand(454, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSpellResistanceDecrease_mutex, "effectSpellResistanceDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectSpellResistanceIncrease(Ice::Int nValue, const Ice::Current& ice) {
  lock(effectSpellResistanceIncrease_mutex, "effectSpellResistanceIncrease");
  callCounter += 1;
  StackPushInteger(nValue);

  VM_ExecuteCommand(212, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSpellResistanceIncrease_mutex, "effectSpellResistanceIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectStunned(const Ice::Current& ice) {
  lock(effectStunned_mutex, "effectStunned");
  callCounter += 1;

  VM_ExecuteCommand(161, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectStunned_mutex, "effectStunned");
  return e;
};

NWN::NWEffect NWScriptI::effectSummonCreature(const std::string& sCreatureResref, Ice::Int nVisualEffectId, Ice::Float fDelaySeconds, bool bUseAppearAnimation, const Ice::Current& ice) {
  lock(effectSummonCreature_mutex, "effectSummonCreature");
  callCounter += 1;
  StackPushInteger(bUseAppearAnimation == true ? 1 : 0);
  StackPushFloat(fDelaySeconds);
  StackPushInteger(nVisualEffectId);
  StackPushString(sCreatureResref.c_str());

  VM_ExecuteCommand(83, 4);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSummonCreature_mutex, "effectSummonCreature");
  return e;
};

NWN::NWEffect NWScriptI::effectSwarm(bool bLooping, const std::string& sCreatureTemplate1, const std::string& sCreatureTemplate2, const std::string& sCreatureTemplate3, const std::string& sCreatureTemplate4, const Ice::Current& ice) {
  lock(effectSwarm_mutex, "effectSwarm");
  callCounter += 1;
  StackPushString(sCreatureTemplate4.c_str());
  StackPushString(sCreatureTemplate3.c_str());
  StackPushString(sCreatureTemplate2.c_str());
  StackPushString(sCreatureTemplate1.c_str());
  StackPushInteger(bLooping == true ? 1 : 0);

  VM_ExecuteCommand(510, 5);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectSwarm_mutex, "effectSwarm");
  return e;
};

NWN::NWEffect NWScriptI::effectTemporaryHitpoints(Ice::Int nHitPoints, const Ice::Current& ice) {
  lock(effectTemporaryHitpoints_mutex, "effectTemporaryHitpoints");
  callCounter += 1;
  StackPushInteger(nHitPoints);

  VM_ExecuteCommand(314, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectTemporaryHitpoints_mutex, "effectTemporaryHitpoints");
  return e;
};

NWN::NWEffect NWScriptI::effectTimeStop(const Ice::Current& ice) {
  lock(effectTimeStop_mutex, "effectTimeStop");
  callCounter += 1;

  VM_ExecuteCommand(467, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectTimeStop_mutex, "effectTimeStop");
  return e;
};

NWN::NWEffect NWScriptI::effectTrueSeeing(const Ice::Current& ice) {
  lock(effectTrueSeeing_mutex, "effectTrueSeeing");
  callCounter += 1;

  VM_ExecuteCommand(465, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectTrueSeeing_mutex, "effectTrueSeeing");
  return e;
};

NWN::NWEffect NWScriptI::effectTurnResistanceDecrease(Ice::Int nHitDice, const Ice::Current& ice) {
  lock(effectTurnResistanceDecrease_mutex, "effectTurnResistanceDecrease");
  callCounter += 1;
  StackPushInteger(nHitDice);

  VM_ExecuteCommand(552, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectTurnResistanceDecrease_mutex, "effectTurnResistanceDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectTurnResistanceIncrease(Ice::Int nHitDice, const Ice::Current& ice) {
  lock(effectTurnResistanceIncrease_mutex, "effectTurnResistanceIncrease");
  callCounter += 1;
  StackPushInteger(nHitDice);

  VM_ExecuteCommand(553, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectTurnResistanceIncrease_mutex, "effectTurnResistanceIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectTurned(const Ice::Current& ice) {
  lock(effectTurned_mutex, "effectTurned");
  callCounter += 1;

  VM_ExecuteCommand(379, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectTurned_mutex, "effectTurned");
  return e;
};

NWN::NWEffect NWScriptI::effectUltravision(const Ice::Current& ice) {
  lock(effectUltravision_mutex, "effectUltravision");
  callCounter += 1;

  VM_ExecuteCommand(461, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectUltravision_mutex, "effectUltravision");
  return e;
};

NWN::NWEffect NWScriptI::effectVisualEffect(Ice::Int nVisualEffectId, bool bMissEffect, const Ice::Current& ice) {
  lock(effectVisualEffect_mutex, "effectVisualEffect");
  callCounter += 1;
  StackPushInteger(bMissEffect == true ? 1 : 0);
  StackPushInteger(nVisualEffectId);

  VM_ExecuteCommand(180, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(effectVisualEffect_mutex, "effectVisualEffect");
  return e;
};

void NWScriptI::endGame(const std::string& sEndMovie, const Ice::Current& ice) {
  lock(endGame_mutex, "endGame");
  callCounter += 1;
  StackPushString(sEndMovie.c_str());

  VM_ExecuteCommand(564, 1);

unlock(endGame_mutex, "endGame");
  
};

void NWScriptI::executeScript(const std::string& sScript, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(executeScript_mutex, "executeScript");
  callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushString(sScript.c_str());

  VM_ExecuteCommand(8, 2);

unlock(executeScript_mutex, "executeScript");
  
};

void NWScriptI::exploreAreaForPlayer(const NWN::NWObject& oArea, const NWN::NWObject& oPlayer, bool bExplored, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(exploreAreaForPlayer_mutex, "exploreAreaForPlayer");
  callCounter += 1;
  StackPushInteger(bExplored == true ? 1 : 0);
  StackPushObject(oPlayer.id);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(403, 3);

unlock(exploreAreaForPlayer_mutex, "exploreAreaForPlayer");
  
};

void NWScriptI::exportAllCharacters(const Ice::Current& ice) {
  lock(exportAllCharacters_mutex, "exportAllCharacters");
  callCounter += 1;

  VM_ExecuteCommand(557, 0);

unlock(exportAllCharacters_mutex, "exportAllCharacters");
  
};

void NWScriptI::exportSingleCharacter(const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(exportSingleCharacter_mutex, "exportSingleCharacter");
  callCounter += 1;
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(719, 1);

unlock(exportSingleCharacter_mutex, "exportSingleCharacter");
  
};

NWN::NWEffect NWScriptI::extraordinaryEffect(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(extraordinaryEffect_mutex, "extraordinaryEffect");
  callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(114, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(extraordinaryEffect_mutex, "extraordinaryEffect");
  return e;
};

Ice::Float NWScriptI::fabs(Ice::Float fValue, const Ice::Current& ice) {
  lock(fabs_mutex, "fabs");
  callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(67, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(fabs_mutex, "fabs");
  return fRetVal;
};

void NWScriptI::fadeFromBlack(const NWN::NWObject& oCreature, Ice::Float fSpeed, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(fadeFromBlack_mutex, "fadeFromBlack");
  callCounter += 1;
  StackPushFloat(fSpeed);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(695, 2);

unlock(fadeFromBlack_mutex, "fadeFromBlack");
  
};

void NWScriptI::fadeToBlack(const NWN::NWObject& oCreature, Ice::Float fSpeed, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(fadeToBlack_mutex, "fadeToBlack");
  callCounter += 1;
  StackPushFloat(fSpeed);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(696, 2);

unlock(fadeToBlack_mutex, "fadeToBlack");
  
};

Ice::Float NWScriptI::feetToMeters(Ice::Float fFeet, const Ice::Current& ice) {
  lock(feetToMeters_mutex, "feetToMeters");
  callCounter += 1;
  StackPushFloat(fFeet);

  VM_ExecuteCommand(218, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(feetToMeters_mutex, "feetToMeters");
  return fRetVal;
};

Ice::Int NWScriptI::findSubString(const std::string& sString, const std::string& sSubString, Ice::Int nStart, const Ice::Current& ice) {
  lock(findSubString_mutex, "findSubString");
  callCounter += 1;
  StackPushInteger(nStart);
  StackPushString(sSubString.c_str());
  StackPushString(sString.c_str());

  VM_ExecuteCommand(66, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(findSubString_mutex, "findSubString");
  return nRetVal;
};

Ice::Int NWScriptI::floatToInt(Ice::Float fFloat, const Ice::Current& ice) {
  lock(floatToInt_mutex, "floatToInt");
  callCounter += 1;
  StackPushFloat(fFloat);

  VM_ExecuteCommand(231, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(floatToInt_mutex, "floatToInt");
  return nRetVal;
};

std::string NWScriptI::floatToString(Ice::Float fFloat, Ice::Int nWidth, Ice::Int nDecimals, const Ice::Current& ice) {
  lock(floatToString_mutex, "floatToString");
  callCounter += 1;
  StackPushInteger(nDecimals);
  StackPushInteger(nWidth);
  StackPushFloat(fFloat);

  VM_ExecuteCommand(3, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(floatToString_mutex, "floatToString");
  return std::string(sRetVal);
};

void NWScriptI::floatingTextStrRefOnCreature(Ice::Int nStrRefToDisplay, const NWN::NWObject& oCreatureToFloatAbove, bool bBroadcastToFaction, const Ice::Current& ice) {
  if (oCreatureToFloatAbove.id < 0 || oCreatureToFloatAbove.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(floatingTextStrRefOnCreature_mutex, "floatingTextStrRefOnCreature");
  callCounter += 1;
  StackPushInteger(bBroadcastToFaction == true ? 1 : 0);
  StackPushObject(oCreatureToFloatAbove.id);
  StackPushInteger(nStrRefToDisplay);

  VM_ExecuteCommand(525, 3);

unlock(floatingTextStrRefOnCreature_mutex, "floatingTextStrRefOnCreature");
  
};

void NWScriptI::floatingTextStringOnCreature(const std::string& sStringToDisplay, const NWN::NWObject& oCreatureToFloatAbove, bool bBroadcastToFaction, const Ice::Current& ice) {
  if (oCreatureToFloatAbove.id < 0 || oCreatureToFloatAbove.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(floatingTextStringOnCreature_mutex, "floatingTextStringOnCreature");
  callCounter += 1;
  StackPushInteger(bBroadcastToFaction == true ? 1 : 0);
  StackPushObject(oCreatureToFloatAbove.id);
  StackPushString(sStringToDisplay.c_str());

  VM_ExecuteCommand(526, 3);

unlock(floatingTextStringOnCreature_mutex, "floatingTextStringOnCreature");
  
};

void NWScriptI::forceRest(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(forceRest_mutex, "forceRest");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(775, 1);

unlock(forceRest_mutex, "forceRest");
  
};

NWN::SavingThrowResult NWScriptI::fortitudeSave(const NWN::NWObject& oCreature, Ice::Int nDC, NWN::SaveType tSaveType, const NWN::NWObject& oSaveVersus, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSaveVersus.id < 0 || oSaveVersus.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(fortitudeSave_mutex, "fortitudeSave");
  callCounter += 1;
  StackPushObject(oSaveVersus.id);
  StackPushInteger(enum_SaveType_2_long(tSaveType));
  
  StackPushInteger(nDC);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(108, 4);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(fortitudeSave_mutex, "fortitudeSave");
    return enum_long_2_SavingThrowResult(nRetVal);
  
};

std::string NWScriptI::get2DAString(const std::string& s2DA, const std::string& sColumn, Ice::Int nRow, const Ice::Current& ice) {
  lock(get2DAString_mutex, "get2DAString");
  callCounter += 1;
  StackPushInteger(nRow);
  StackPushString(sColumn.c_str());
  StackPushString(s2DA.c_str());

  VM_ExecuteCommand(710, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(get2DAString_mutex, "get2DAString");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getAC(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAC_mutex, "getAC");
  callCounter += 1;
  StackPushInteger(1);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(116, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getAC_mutex, "getAC");
  return nRetVal;
};

NWN::AILevel NWScriptI::getAILevel(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAILevel_mutex, "getAILevel");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(712, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getAILevel_mutex, "getAILevel");
    return enum_long_2_AILevel(nRetVal);
  
};

Ice::Int NWScriptI::getAbilityModifier(NWN::Ability tAbility, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAbilityModifier_mutex, "getAbilityModifier");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(enum_Ability_2_long(tAbility));
  

  VM_ExecuteCommand(331, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getAbilityModifier_mutex, "getAbilityModifier");
  return nRetVal;
};

Ice::Int NWScriptI::getAbilityScore(const NWN::NWObject& oCreature, NWN::Ability tAbility, bool bBaseAbilityScore, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAbilityScore_mutex, "getAbilityScore");
  callCounter += 1;
  StackPushInteger(bBaseAbilityScore == true ? 1 : 0);
  StackPushInteger(enum_Ability_2_long(tAbility));
  
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(139, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getAbilityScore_mutex, "getAbilityScore");
  return nRetVal;
};

bool NWScriptI::getActionMode(const NWN::NWObject& oCreature, NWN::ActionMode tActionMode, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getActionMode_mutex, "getActionMode");
  callCounter += 1;
  StackPushInteger(enum_ActionMode_2_long(tActionMode));
  
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(735, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getActionMode_mutex, "getActionMode");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getAge(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAge_mutex, "getAge");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(495, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getAge_mutex, "getAge");
  return nRetVal;
};

NWN::Alignment NWScriptI::getAlignmentGoodEvil(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAlignmentGoodEvil_mutex, "getAlignmentGoodEvil");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(127, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getAlignmentGoodEvil_mutex, "getAlignmentGoodEvil");
    return enum_long_2_Alignment(nRetVal);
  
};

NWN::Alignment NWScriptI::getAlignmentLawChaos(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAlignmentLawChaos_mutex, "getAlignmentLawChaos");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(126, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getAlignmentLawChaos_mutex, "getAlignmentLawChaos");
    return enum_long_2_Alignment(nRetVal);
  
};

Ice::Int NWScriptI::getAnimalCompanionCreatureType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAnimalCompanionCreatureType_mutex, "getAnimalCompanionCreatureType");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(498, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getAnimalCompanionCreatureType_mutex, "getAnimalCompanionCreatureType");
  return nRetVal;
};

std::string NWScriptI::getAnimalCompanionName(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAnimalCompanionName_mutex, "getAnimalCompanionName");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(500, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getAnimalCompanionName_mutex, "getAnimalCompanionName");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getAppearanceType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAppearanceType_mutex, "getAppearanceType");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(577, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getAppearanceType_mutex, "getAppearanceType");
  return nRetVal;
};

Ice::Int NWScriptI::getArcaneSpellFailure(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getArcaneSpellFailure_mutex, "getArcaneSpellFailure");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(737, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getArcaneSpellFailure_mutex, "getArcaneSpellFailure");
  return nRetVal;
};

NWN::NWObject NWScriptI::getArea(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getArea_mutex, "getArea");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(24, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getArea_mutex, "getArea");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getAreaFromLocation(const NWN::NWLocation& lLocation, const Ice::Current& ice) {
  if (lLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(getAreaFromLocation_mutex, "getAreaFromLocation");
  callCounter += 1;
  
  StackPushFloat(lLocation.facing);
  Vector lLocation_vv;
  lLocation_vv.X = lLocation.x; lLocation_vv.Y = lLocation.y; lLocation_vv.Z = lLocation.z;
  StackPushVector(lLocation_vv);
  StackPushObject(lLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(224, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getAreaFromLocation_mutex, "getAreaFromLocation");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getAreaOfEffectCreator(const NWN::NWObject& oAreaOfEffectObject, const Ice::Current& ice) {
  if (oAreaOfEffectObject.id < 0 || oAreaOfEffectObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAreaOfEffectCreator_mutex, "getAreaOfEffectCreator");
  callCounter += 1;
  StackPushObject(oAreaOfEffectObject.id);

  VM_ExecuteCommand(264, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getAreaOfEffectCreator_mutex, "getAreaOfEffectCreator");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getAreaSize(Ice::Int nAreaDimension, const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAreaSize_mutex, "getAreaSize");
  callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nAreaDimension);

  VM_ExecuteCommand(829, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getAreaSize_mutex, "getAreaSize");
  return nRetVal;
};

NWN::NWObject NWScriptI::getAssociate(NWN::AssociateType tAssociateType, const NWN::NWObject& oMaster, Ice::Int nTh, const Ice::Current& ice) {
  if (oMaster.id < 0 || oMaster.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAssociate_mutex, "getAssociate");
  callCounter += 1;
  StackPushInteger(nTh);
  StackPushObject(oMaster.id);
  StackPushInteger(enum_AssociateType_2_long(tAssociateType));
  

  VM_ExecuteCommand(364, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getAssociate_mutex, "getAssociate");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::AssociateType NWScriptI::getAssociateType(const NWN::NWObject& oAssociate, const Ice::Current& ice) {
  if (oAssociate.id < 0 || oAssociate.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAssociateType_mutex, "getAssociateType");
  callCounter += 1;
  StackPushObject(oAssociate.id);

  VM_ExecuteCommand(748, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getAssociateType_mutex, "getAssociateType");
    return enum_long_2_AssociateType(nRetVal);
  
};

NWN::NWObject NWScriptI::getAttackTarget(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getAttackTarget_mutex, "getAttackTarget");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(316, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getAttackTarget_mutex, "getAttackTarget");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getAttemptedAttackTarget(const Ice::Current& ice) {
  lock(getAttemptedAttackTarget_mutex, "getAttemptedAttackTarget");
  callCounter += 1;

  VM_ExecuteCommand(361, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getAttemptedAttackTarget_mutex, "getAttemptedAttackTarget");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getAttemptedSpellTarget(const Ice::Current& ice) {
  lock(getAttemptedSpellTarget_mutex, "getAttemptedSpellTarget");
  callCounter += 1;

  VM_ExecuteCommand(375, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getAttemptedSpellTarget_mutex, "getAttemptedSpellTarget");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getBaseAttackBonus(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getBaseAttackBonus_mutex, "getBaseAttackBonus");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(699, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getBaseAttackBonus_mutex, "getBaseAttackBonus");
  return nRetVal;
};

Ice::Int NWScriptI::getBaseItemType(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getBaseItemType_mutex, "getBaseItemType");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(397, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getBaseItemType_mutex, "getBaseItemType");
  return nRetVal;
};

NWN::NWObject NWScriptI::getBlockingDoor(const Ice::Current& ice) {
  lock(getBlockingDoor_mutex, "getBlockingDoor");
  callCounter += 1;

  VM_ExecuteCommand(336, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getBlockingDoor_mutex, "getBlockingDoor");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getCalendarDay(const Ice::Current& ice) {
  lock(getCalendarDay_mutex, "getCalendarDay");
  callCounter += 1;

  VM_ExecuteCommand(15, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCalendarDay_mutex, "getCalendarDay");
  return nRetVal;
};

Ice::Int NWScriptI::getCalendarMonth(const Ice::Current& ice) {
  lock(getCalendarMonth_mutex, "getCalendarMonth");
  callCounter += 1;

  VM_ExecuteCommand(14, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCalendarMonth_mutex, "getCalendarMonth");
  return nRetVal;
};

Ice::Int NWScriptI::getCalendarYear(const Ice::Current& ice) {
  lock(getCalendarYear_mutex, "getCalendarYear");
  callCounter += 1;

  VM_ExecuteCommand(13, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCalendarYear_mutex, "getCalendarYear");
  return nRetVal;
};

Ice::Float NWScriptI::getCampaignFloat(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCampaignFloat_mutex, "getCampaignFloat");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(595, 3);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(getCampaignFloat_mutex, "getCampaignFloat");
  return fRetVal;
};

Ice::Int NWScriptI::getCampaignInt(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCampaignInt_mutex, "getCampaignInt");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(596, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCampaignInt_mutex, "getCampaignInt");
  return nRetVal;
};

NWN::NWLocation NWScriptI::getCampaignLocation(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCampaignLocation_mutex, "getCampaignLocation");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(598, 3);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.area.id = pRetVal->AreaID;
  nl.x = pRetVal->X;
  nl.y = pRetVal->Y;
  nl.z = pRetVal->Z;
  nl.facing = atan(pRetVal->OrientationY / pRetVal->OrientationX) * (180 / 3.1415927);
  nl.facing += 180;
  while (nl.facing > 360.0) nl.facing -= 360.0; while (nl.facing < 0.0) nl.facing += 360.0;
  unlock(getCampaignLocation_mutex, "getCampaignLocation");
  return nl;
};

std::string NWScriptI::getCampaignString(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCampaignString_mutex, "getCampaignString");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(599, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getCampaignString_mutex, "getCampaignString");
  return std::string(sRetVal);
};

NWN::NWVector NWScriptI::getCampaignVector(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCampaignVector_mutex, "getCampaignVector");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(597, 3);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock(getCampaignVector_mutex, "getCampaignVector");
  return nv;
};

Ice::Int NWScriptI::getCasterLevel(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCasterLevel_mutex, "getCasterLevel");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(84, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCasterLevel_mutex, "getCasterLevel");
  return nRetVal;
};

Ice::Float NWScriptI::getChallengeRating(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getChallengeRating_mutex, "getChallengeRating");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(494, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(getChallengeRating_mutex, "getChallengeRating");
  return fRetVal;
};

Ice::Int NWScriptI::getClassByPosition(Ice::Int nClassPosition, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getClassByPosition_mutex, "getClassByPosition");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nClassPosition);

  VM_ExecuteCommand(341, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getClassByPosition_mutex, "getClassByPosition");
  return nRetVal;
};

NWN::NWObject NWScriptI::getClickingObject(const Ice::Current& ice) {
  lock(getClickingObject_mutex, "getClickingObject");
  callCounter += 1;

  VM_ExecuteCommand(326, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getClickingObject_mutex, "getClickingObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getColor(const NWN::NWObject& oObject, Ice::Int nColorChannel, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getColor_mutex, "getColor");
  callCounter += 1;
  StackPushInteger(nColorChannel);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(843, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getColor_mutex, "getColor");
  return nRetVal;
};

bool NWScriptI::getCommandable(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCommandable_mutex, "getCommandable");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(163, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCommandable_mutex, "getCommandable");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getCreatureBodyPart(NWN::CreaturePart tCreaturePart, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCreatureBodyPart_mutex, "getCreatureBodyPart");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(enum_CreaturePart_2_long(tCreaturePart));
  

  VM_ExecuteCommand(792, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCreatureBodyPart_mutex, "getCreatureBodyPart");
  return nRetVal;
};

NWN::CreatureSize NWScriptI::getCreatureSize(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCreatureSize_mutex, "getCreatureSize");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(479, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCreatureSize_mutex, "getCreatureSize");
    return enum_long_2_CreatureSize(nRetVal);
  
};

Ice::Int NWScriptI::getCreatureStartingPackage(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCreatureStartingPackage_mutex, "getCreatureStartingPackage");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(766, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCreatureStartingPackage_mutex, "getCreatureStartingPackage");
  return nRetVal;
};

Ice::Int NWScriptI::getCreatureTailType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCreatureTailType_mutex, "getCreatureTailType");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(794, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCreatureTailType_mutex, "getCreatureTailType");
  return nRetVal;
};

Ice::Int NWScriptI::getCreatureWingType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCreatureWingType_mutex, "getCreatureWingType");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(790, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCreatureWingType_mutex, "getCreatureWingType");
  return nRetVal;
};

NWN::Action NWScriptI::getCurrentAction(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCurrentAction_mutex, "getCurrentAction");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(522, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCurrentAction_mutex, "getCurrentAction");
    return enum_long_2_Action(nRetVal);
  
};

Ice::Int NWScriptI::getCurrentHitPoints(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCurrentHitPoints_mutex, "getCurrentHitPoints");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(49, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCurrentHitPoints_mutex, "getCurrentHitPoints");
  return nRetVal;
};

Ice::Float NWScriptI::getCutsceneCameraMoveRate(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCutsceneCameraMoveRate_mutex, "getCutsceneCameraMoveRate");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(742, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(getCutsceneCameraMoveRate_mutex, "getCutsceneCameraMoveRate");
  return fRetVal;
};

bool NWScriptI::getCutsceneMode(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getCutsceneMode_mutex, "getCutsceneMode");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(781, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getCutsceneMode_mutex, "getCutsceneMode");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getDamageDealtByType(NWN::DamageType tDamageType, const Ice::Current& ice) {
  lock(getDamageDealtByType_mutex, "getDamageDealtByType");
  callCounter += 1;
  StackPushInteger(enum_DamageType_2_long(tDamageType));
  

  VM_ExecuteCommand(344, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getDamageDealtByType_mutex, "getDamageDealtByType");
  return nRetVal;
};

Ice::Int NWScriptI::getDefensiveCastingMode(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getDefensiveCastingMode_mutex, "getDefensiveCastingMode");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(576, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getDefensiveCastingMode_mutex, "getDefensiveCastingMode");
  return nRetVal;
};

std::string NWScriptI::getDeity(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getDeity_mutex, "getDeity");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(489, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getDeity_mutex, "getDeity");
  return std::string(sRetVal);
};

std::string NWScriptI::getDescription(const NWN::NWObject& oObject, bool bOriginalDescription, bool bIdentifiedDescription, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getDescription_mutex, "getDescription");
  callCounter += 1;
  StackPushInteger(bIdentifiedDescription == true ? 1 : 0);
  StackPushInteger(bOriginalDescription == true ? 1 : 0);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(836, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getDescription_mutex, "getDescription");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getDetectMode(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getDetectMode_mutex, "getDetectMode");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(575, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getDetectMode_mutex, "getDetectMode");
  return nRetVal;
};

Ice::Float NWScriptI::getDialogSoundLength(Ice::Int nStrRef, const Ice::Current& ice) {
  lock(getDialogSoundLength_mutex, "getDialogSoundLength");
  callCounter += 1;
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(694, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(getDialogSoundLength_mutex, "getDialogSoundLength");
  return fRetVal;
};

Ice::Float NWScriptI::getDistanceBetween(const NWN::NWObject& oObjectA, const NWN::NWObject& oObjectB, const Ice::Current& ice) {
  if (oObjectA.id < 0 || oObjectA.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oObjectB.id < 0 || oObjectB.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getDistanceBetween_mutex, "getDistanceBetween");
  callCounter += 1;
  StackPushObject(oObjectB.id);
  StackPushObject(oObjectA.id);

  VM_ExecuteCommand(151, 2);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(getDistanceBetween_mutex, "getDistanceBetween");
  return fRetVal;
};

Ice::Float NWScriptI::getDistanceBetweenLocations(const NWN::NWLocation& lLocationA, const NWN::NWLocation& lLocationB, const Ice::Current& ice) {
  if (lLocationA.area.id < 0) throw NWN::InvalidObjectException();
  if (lLocationB.area.id < 0) throw NWN::InvalidObjectException();
  lock(getDistanceBetweenLocations_mutex, "getDistanceBetweenLocations");
  callCounter += 1;
  
  StackPushFloat(lLocationB.facing);
  Vector lLocationB_vv;
  lLocationB_vv.X = lLocationB.x; lLocationB_vv.Y = lLocationB.y; lLocationB_vv.Z = lLocationB.z;
  StackPushVector(lLocationB_vv);
  StackPushObject(lLocationB.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  
  StackPushFloat(lLocationA.facing);
  Vector lLocationA_vv;
  lLocationA_vv.X = lLocationA.x; lLocationA_vv.Y = lLocationA.y; lLocationA_vv.Z = lLocationA.z;
  StackPushVector(lLocationA_vv);
  StackPushObject(lLocationA.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(298, 2);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(getDistanceBetweenLocations_mutex, "getDistanceBetweenLocations");
  return fRetVal;
};

Ice::Float NWScriptI::getDistanceToObject(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getDistanceToObject_mutex, "getDistanceToObject");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(41, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(getDistanceToObject_mutex, "getDistanceToObject");
  return fRetVal;
};

bool NWScriptI::getDroppableFlag(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getDroppableFlag_mutex, "getDroppableFlag");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(586, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getDroppableFlag_mutex, "getDroppableFlag");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getEffectCreator(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(getEffectCreator_mutex, "getEffectCreator");
  callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(91, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getEffectCreator_mutex, "getEffectCreator");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::DurationType NWScriptI::getEffectDurationType(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(getEffectDurationType_mutex, "getEffectDurationType");
  callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(89, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getEffectDurationType_mutex, "getEffectDurationType");
    return enum_long_2_DurationType(nRetVal);
  
};

Ice::Int NWScriptI::getEffectSpellId(const NWN::NWEffect& eSpellEffect, const Ice::Current& ice) {
  if (effectMap.find(eSpellEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(getEffectSpellId_mutex, "getEffectSpellId");
  callCounter += 1;
  CGameEffect *eSpellEffect_ptr = effectMap.find(eSpellEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eSpellEffect_ptr);

  VM_ExecuteCommand(305, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getEffectSpellId_mutex, "getEffectSpellId");
  return nRetVal;
};

NWN::EffectSubType NWScriptI::getEffectSubType(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(getEffectSubType_mutex, "getEffectSubType");
  callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(90, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getEffectSubType_mutex, "getEffectSubType");
    return enum_long_2_EffectSubType(nRetVal);
  
};

NWN::EffectType NWScriptI::getEffectType(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(getEffectType_mutex, "getEffectType");
  callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(170, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getEffectType_mutex, "getEffectType");
    return enum_long_2_EffectType(nRetVal);
  
};

Ice::Int NWScriptI::getEncounterActive(const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  if (oEncounter.id < 0 || oEncounter.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getEncounterActive_mutex, "getEncounterActive");
  callCounter += 1;
  StackPushObject(oEncounter.id);

  VM_ExecuteCommand(276, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getEncounterActive_mutex, "getEncounterActive");
  return nRetVal;
};

Ice::Int NWScriptI::getEncounterDifficulty(const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  if (oEncounter.id < 0 || oEncounter.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getEncounterDifficulty_mutex, "getEncounterDifficulty");
  callCounter += 1;
  StackPushObject(oEncounter.id);

  VM_ExecuteCommand(297, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getEncounterDifficulty_mutex, "getEncounterDifficulty");
  return nRetVal;
};

Ice::Int NWScriptI::getEncounterSpawnsCurrent(const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  if (oEncounter.id < 0 || oEncounter.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getEncounterSpawnsCurrent_mutex, "getEncounterSpawnsCurrent");
  callCounter += 1;
  StackPushObject(oEncounter.id);

  VM_ExecuteCommand(280, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getEncounterSpawnsCurrent_mutex, "getEncounterSpawnsCurrent");
  return nRetVal;
};

Ice::Int NWScriptI::getEncounterSpawnsMax(const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  if (oEncounter.id < 0 || oEncounter.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getEncounterSpawnsMax_mutex, "getEncounterSpawnsMax");
  callCounter += 1;
  StackPushObject(oEncounter.id);

  VM_ExecuteCommand(278, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getEncounterSpawnsMax_mutex, "getEncounterSpawnsMax");
  return nRetVal;
};

NWN::NWObject NWScriptI::getEnteringObject(const Ice::Current& ice) {
  lock(getEnteringObject_mutex, "getEnteringObject");
  callCounter += 1;

  VM_ExecuteCommand(25, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getEnteringObject_mutex, "getEnteringObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getExitingObject(const Ice::Current& ice) {
  lock(getExitingObject_mutex, "getExitingObject");
  callCounter += 1;

  VM_ExecuteCommand(26, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getExitingObject_mutex, "getExitingObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Float NWScriptI::getFacing(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFacing_mutex, "getFacing");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(28, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(getFacing_mutex, "getFacing");
  return fRetVal;
};

Ice::Float NWScriptI::getFacingFromLocation(const NWN::NWLocation& lLocation, const Ice::Current& ice) {
  if (lLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(getFacingFromLocation_mutex, "getFacingFromLocation");
  callCounter += 1;
  
  StackPushFloat(lLocation.facing);
  Vector lLocation_vv;
  lLocation_vv.X = lLocation.x; lLocation_vv.Y = lLocation.y; lLocation_vv.Z = lLocation.z;
  StackPushVector(lLocation_vv);
  StackPushObject(lLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(225, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(getFacingFromLocation_mutex, "getFacingFromLocation");
  return fRetVal;
};

Ice::Int NWScriptI::getFactionAverageGoodEvilAlignment(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionAverageGoodEvilAlignment_mutex, "getFactionAverageGoodEvilAlignment");
  callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(187, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFactionAverageGoodEvilAlignment_mutex, "getFactionAverageGoodEvilAlignment");
  return nRetVal;
};

Ice::Int NWScriptI::getFactionAverageLawChaosAlignment(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionAverageLawChaosAlignment_mutex, "getFactionAverageLawChaosAlignment");
  callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(188, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFactionAverageLawChaosAlignment_mutex, "getFactionAverageLawChaosAlignment");
  return nRetVal;
};

Ice::Int NWScriptI::getFactionAverageLevel(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionAverageLevel_mutex, "getFactionAverageLevel");
  callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(189, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFactionAverageLevel_mutex, "getFactionAverageLevel");
  return nRetVal;
};

Ice::Int NWScriptI::getFactionAverageReputation(const NWN::NWObject& oSourceFactionMember, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oSourceFactionMember.id < 0 || oSourceFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionAverageReputation_mutex, "getFactionAverageReputation");
  callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oSourceFactionMember.id);

  VM_ExecuteCommand(186, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFactionAverageReputation_mutex, "getFactionAverageReputation");
  return nRetVal;
};

Ice::Int NWScriptI::getFactionAverageXP(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionAverageXP_mutex, "getFactionAverageXP");
  callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(190, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFactionAverageXP_mutex, "getFactionAverageXP");
  return nRetVal;
};

NWN::NWObject NWScriptI::getFactionBestAC(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionBestAC_mutex, "getFactionBestAC");
  callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(193, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFactionBestAC_mutex, "getFactionBestAC");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getFactionEqual(const NWN::NWObject& oFirstObject, const NWN::NWObject& oSecondObject, const Ice::Current& ice) {
  if (oFirstObject.id < 0 || oFirstObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSecondObject.id < 0 || oSecondObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionEqual_mutex, "getFactionEqual");
  callCounter += 1;
  StackPushObject(oSecondObject.id);
  StackPushObject(oFirstObject.id);

  VM_ExecuteCommand(172, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFactionEqual_mutex, "getFactionEqual");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getFactionGold(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionGold_mutex, "getFactionGold");
  callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(185, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFactionGold_mutex, "getFactionGold");
  return nRetVal;
};

NWN::NWObject NWScriptI::getFactionLeader(const NWN::NWObject& oMemberOfFaction, const Ice::Current& ice) {
  if (oMemberOfFaction.id < 0 || oMemberOfFaction.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionLeader_mutex, "getFactionLeader");
  callCounter += 1;
  StackPushObject(oMemberOfFaction.id);

  VM_ExecuteCommand(562, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFactionLeader_mutex, "getFactionLeader");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFactionLeastDamagedMember(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionLeastDamagedMember_mutex, "getFactionLeastDamagedMember");
  callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(184, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFactionLeastDamagedMember_mutex, "getFactionLeastDamagedMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFactionMostDamagedMember(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionMostDamagedMember_mutex, "getFactionMostDamagedMember");
  callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(183, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFactionMostDamagedMember_mutex, "getFactionMostDamagedMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getFactionMostFrequentClass(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionMostFrequentClass_mutex, "getFactionMostFrequentClass");
  callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(191, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFactionMostFrequentClass_mutex, "getFactionMostFrequentClass");
  return nRetVal;
};

NWN::NWObject NWScriptI::getFactionStrongestMember(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionStrongestMember_mutex, "getFactionStrongestMember");
  callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(182, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFactionStrongestMember_mutex, "getFactionStrongestMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFactionWeakestMember(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionWeakestMember_mutex, "getFactionWeakestMember");
  callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(181, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFactionWeakestMember_mutex, "getFactionWeakestMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFactionWorstAC(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  if (oFactionMember.id < 0 || oFactionMember.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFactionWorstAC_mutex, "getFactionWorstAC");
  callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(192, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFactionWorstAC_mutex, "getFactionWorstAC");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getFamiliarCreatureType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFamiliarCreatureType_mutex, "getFamiliarCreatureType");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(497, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFamiliarCreatureType_mutex, "getFamiliarCreatureType");
  return nRetVal;
};

std::string NWScriptI::getFamiliarName(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFamiliarName_mutex, "getFamiliarName");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(499, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getFamiliarName_mutex, "getFamiliarName");
  return std::string(sRetVal);
};

NWN::NWEffect NWScriptI::getFirstEffect(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFirstEffect_mutex, "getFirstEffect");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(85, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(getFirstEffect_mutex, "getFirstEffect");
  return e;
};

NWN::NWObject NWScriptI::getFirstFactionMember(const NWN::NWObject& oMemberOfFaction, bool bPCOnly, const Ice::Current& ice) {
  if (oMemberOfFaction.id < 0 || oMemberOfFaction.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFirstFactionMember_mutex, "getFirstFactionMember");
  callCounter += 1;
  StackPushInteger(bPCOnly == true ? 1 : 0);
  StackPushObject(oMemberOfFaction.id);

  VM_ExecuteCommand(380, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFirstFactionMember_mutex, "getFirstFactionMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFirstInPersistentObject(const NWN::NWObject& oPersistentObject, Ice::Int nResidentObjectType, Ice::Int nPersistentZone, const Ice::Current& ice) {
  if (oPersistentObject.id < 0 || oPersistentObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFirstInPersistentObject_mutex, "getFirstInPersistentObject");
  callCounter += 1;
  StackPushInteger(nPersistentZone);
  StackPushInteger(nResidentObjectType);
  StackPushObject(oPersistentObject.id);

  VM_ExecuteCommand(262, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFirstInPersistentObject_mutex, "getFirstInPersistentObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFirstItemInInventory(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFirstItemInInventory_mutex, "getFirstItemInInventory");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(339, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFirstItemInInventory_mutex, "getFirstItemInInventory");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWItemProperty NWScriptI::getFirstItemProperty(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFirstItemProperty_mutex, "getFirstItemProperty");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(612, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(getFirstItemProperty_mutex, "getFirstItemProperty");
  return e;
};

NWN::NWObject NWScriptI::getFirstObjectInArea(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFirstObjectInArea_mutex, "getFirstObjectInArea");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(93, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFirstObjectInArea_mutex, "getFirstObjectInArea");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFirstObjectInShape(NWN::ShapeType tShapeType, Ice::Float fSize, const NWN::NWLocation& lTarget, bool bLineOfSight, Ice::Int nObjectFilter, const NWN::NWVector& vOrigin, const Ice::Current& ice) {
  if (lTarget.area.id < 0) throw NWN::InvalidObjectException();
  lock(getFirstObjectInShape_mutex, "getFirstObjectInShape");
  callCounter += 1;
  Vector vvOrigin;
  vvOrigin.X = vOrigin.x; vvOrigin.Y = vOrigin.y; vvOrigin.Z = vOrigin.z;
  StackPushVector(vvOrigin);
  StackPushInteger(nObjectFilter);
  StackPushInteger(bLineOfSight == true ? 1 : 0);
  
  StackPushFloat(lTarget.facing);
  Vector lTarget_vv;
  lTarget_vv.X = lTarget.x; lTarget_vv.Y = lTarget.y; lTarget_vv.Z = lTarget.z;
  StackPushVector(lTarget_vv);
  StackPushObject(lTarget.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushFloat(fSize);
  StackPushInteger(enum_ShapeType_2_long(tShapeType));
  

  VM_ExecuteCommand(128, 6);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFirstObjectInShape_mutex, "getFirstObjectInShape");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFirstPC(const Ice::Current& ice) {
  lock(getFirstPC_mutex, "getFirstPC");
  callCounter += 1;

  VM_ExecuteCommand(548, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getFirstPC_mutex, "getFirstPC");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getFogAmount(Ice::Int nFogType, const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFogAmount_mutex, "getFogAmount");
  callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nFogType);

  VM_ExecuteCommand(785, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFogAmount_mutex, "getFogAmount");
  return nRetVal;
};

Ice::Int NWScriptI::getFogColor(Ice::Int nFogType, const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFogColor_mutex, "getFogColor");
  callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nFogType);

  VM_ExecuteCommand(783, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFogColor_mutex, "getFogColor");
  return nRetVal;
};

Ice::Int NWScriptI::getFootstepType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFootstepType_mutex, "getFootstepType");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(788, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFootstepType_mutex, "getFootstepType");
  return nRetVal;
};

Ice::Int NWScriptI::getFortitudeSavingThrow(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getFortitudeSavingThrow_mutex, "getFortitudeSavingThrow");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(491, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getFortitudeSavingThrow_mutex, "getFortitudeSavingThrow");
  return nRetVal;
};

Ice::Int NWScriptI::getGameDifficulty(const Ice::Current& ice) {
  lock(getGameDifficulty_mutex, "getGameDifficulty");
  callCounter += 1;

  VM_ExecuteCommand(513, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getGameDifficulty_mutex, "getGameDifficulty");
  return nRetVal;
};

NWN::Gender NWScriptI::getGender(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getGender_mutex, "getGender");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(358, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getGender_mutex, "getGender");
    return enum_long_2_Gender(nRetVal);
  
};

NWN::NWObject NWScriptI::getGoingToBeAttackedBy(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getGoingToBeAttackedBy_mutex, "getGoingToBeAttackedBy");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(211, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getGoingToBeAttackedBy_mutex, "getGoingToBeAttackedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getGold(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getGold_mutex, "getGold");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(418, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getGold_mutex, "getGold");
  return nRetVal;
};

Ice::Int NWScriptI::getGoldPieceValue(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getGoldPieceValue_mutex, "getGoldPieceValue");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(311, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getGoldPieceValue_mutex, "getGoldPieceValue");
  return nRetVal;
};

Ice::Int NWScriptI::getGoodEvilValue(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getGoodEvilValue_mutex, "getGoodEvilValue");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(125, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getGoodEvilValue_mutex, "getGoodEvilValue");
  return nRetVal;
};

Ice::Int NWScriptI::getHardness(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getHardness_mutex, "getHardness");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(796, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getHardness_mutex, "getHardness");
  return nRetVal;
};

bool NWScriptI::getHasFeat(Ice::Int nFeat, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getHasFeat_mutex, "getHasFeat");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nFeat);

  VM_ExecuteCommand(285, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getHasFeat_mutex, "getHasFeat");
  return nRetVal != 0;
};

bool NWScriptI::getHasFeatEffect(Ice::Int nFeat, const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getHasFeatEffect_mutex, "getHasFeatEffect");
  callCounter += 1;
  StackPushObject(oObject.id);
  StackPushInteger(nFeat);

  VM_ExecuteCommand(543, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getHasFeatEffect_mutex, "getHasFeatEffect");
  return nRetVal != 0;
};

bool NWScriptI::getHasInventory(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getHasInventory_mutex, "getHasInventory");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(570, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getHasInventory_mutex, "getHasInventory");
  return nRetVal != 0;
};

bool NWScriptI::getHasSkill(Ice::Int nSkill, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getHasSkill_mutex, "getHasSkill");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(286, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getHasSkill_mutex, "getHasSkill");
  return nRetVal != 0;
};

bool NWScriptI::getHasSpell(Ice::Int nSpell, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getHasSpell_mutex, "getHasSpell");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(377, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getHasSpell_mutex, "getHasSpell");
  return nRetVal != 0;
};

bool NWScriptI::getHasSpellEffect(Ice::Int nSpell, const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getHasSpellEffect_mutex, "getHasSpellEffect");
  callCounter += 1;
  StackPushObject(oObject.id);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(304, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getHasSpellEffect_mutex, "getHasSpellEffect");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getHenchman(const NWN::NWObject& oMaster, Ice::Int nNth, const Ice::Current& ice) {
  if (oMaster.id < 0 || oMaster.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getHenchman_mutex, "getHenchman");
  callCounter += 1;
  StackPushInteger(nNth);
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(354, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getHenchman_mutex, "getHenchman");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getHitDice(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getHitDice_mutex, "getHitDice");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(166, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getHitDice_mutex, "getHitDice");
  return nRetVal;
};

bool NWScriptI::getIdentified(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIdentified_mutex, "getIdentified");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(332, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIdentified_mutex, "getIdentified");
  return nRetVal != 0;
};

bool NWScriptI::getImmortal(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getImmortal_mutex, "getImmortal");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(708, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getImmortal_mutex, "getImmortal");
  return nRetVal != 0;
};

bool NWScriptI::getInfiniteFlag(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getInfiniteFlag_mutex, "getInfiniteFlag");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(827, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getInfiniteFlag_mutex, "getInfiniteFlag");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getInventoryDisturbItem(const Ice::Current& ice) {
  lock(getInventoryDisturbItem_mutex, "getInventoryDisturbItem");
  callCounter += 1;

  VM_ExecuteCommand(353, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getInventoryDisturbItem_mutex, "getInventoryDisturbItem");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getInventoryDisturbType(const Ice::Current& ice) {
  lock(getInventoryDisturbType_mutex, "getInventoryDisturbType");
  callCounter += 1;

  VM_ExecuteCommand(352, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getInventoryDisturbType_mutex, "getInventoryDisturbType");
  return nRetVal;
};

bool NWScriptI::getIsAreaAboveGround(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsAreaAboveGround_mutex, "getIsAreaAboveGround");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(726, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsAreaAboveGround_mutex, "getIsAreaAboveGround");
  return nRetVal != 0;
};

bool NWScriptI::getIsAreaInterior(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsAreaInterior_mutex, "getIsAreaInterior");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(716, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsAreaInterior_mutex, "getIsAreaInterior");
  return nRetVal != 0;
};

bool NWScriptI::getIsAreaNatural(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsAreaNatural_mutex, "getIsAreaNatural");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(725, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsAreaNatural_mutex, "getIsAreaNatural");
  return nRetVal != 0;
};

bool NWScriptI::getIsCreatureDisarmable(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsCreatureDisarmable_mutex, "getIsCreatureDisarmable");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(773, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsCreatureDisarmable_mutex, "getIsCreatureDisarmable");
  return nRetVal != 0;
};

bool NWScriptI::getIsDM(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsDM_mutex, "getIsDM");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(420, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsDM_mutex, "getIsDM");
  return nRetVal != 0;
};

bool NWScriptI::getIsDMPossessed(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsDMPossessed_mutex, "getIsDMPossessed");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(723, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsDMPossessed_mutex, "getIsDMPossessed");
  return nRetVal != 0;
};

bool NWScriptI::getIsDawn(const Ice::Current& ice) {
  lock(getIsDawn_mutex, "getIsDawn");
  callCounter += 1;

  VM_ExecuteCommand(407, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsDawn_mutex, "getIsDawn");
  return nRetVal != 0;
};

bool NWScriptI::getIsDay(const Ice::Current& ice) {
  lock(getIsDay_mutex, "getIsDay");
  callCounter += 1;

  VM_ExecuteCommand(405, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsDay_mutex, "getIsDay");
  return nRetVal != 0;
};

bool NWScriptI::getIsDead(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsDead_mutex, "getIsDead");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(140, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsDead_mutex, "getIsDead");
  return nRetVal != 0;
};

bool NWScriptI::getIsDoorActionPossible(const NWN::NWObject& oTargetDoor, NWN::DoorAction tDoorAction, const Ice::Current& ice) {
  if (oTargetDoor.id < 0 || oTargetDoor.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsDoorActionPossible_mutex, "getIsDoorActionPossible");
  callCounter += 1;
  StackPushInteger(enum_DoorAction_2_long(tDoorAction));
  
  StackPushObject(oTargetDoor.id);

  VM_ExecuteCommand(337, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsDoorActionPossible_mutex, "getIsDoorActionPossible");
  return nRetVal != 0;
};

bool NWScriptI::getIsDusk(const Ice::Current& ice) {
  lock(getIsDusk_mutex, "getIsDusk");
  callCounter += 1;

  VM_ExecuteCommand(408, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsDusk_mutex, "getIsDusk");
  return nRetVal != 0;
};

bool NWScriptI::getIsEffectValid(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(getIsEffectValid_mutex, "getIsEffectValid");
  callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(88, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsEffectValid_mutex, "getIsEffectValid");
  return nRetVal != 0;
};

bool NWScriptI::getIsEncounterCreature(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsEncounterCreature_mutex, "getIsEncounterCreature");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(409, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsEncounterCreature_mutex, "getIsEncounterCreature");
  return nRetVal != 0;
};

bool NWScriptI::getIsEnemy(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsEnemy_mutex, "getIsEnemy");
  callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(235, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsEnemy_mutex, "getIsEnemy");
  return nRetVal != 0;
};

bool NWScriptI::getIsFriend(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsFriend_mutex, "getIsFriend");
  callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(236, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsFriend_mutex, "getIsFriend");
  return nRetVal != 0;
};

bool NWScriptI::getIsImmune(const NWN::NWObject& oCreature, NWN::ImmunityType tImmunityType, const NWN::NWObject& oVersus, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oVersus.id < 0 || oVersus.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsImmune_mutex, "getIsImmune");
  callCounter += 1;
  StackPushObject(oVersus.id);
  StackPushInteger(enum_ImmunityType_2_long(tImmunityType));
  
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(274, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsImmune_mutex, "getIsImmune");
  return nRetVal != 0;
};

bool NWScriptI::getIsInCombat(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsInCombat_mutex, "getIsInCombat");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(320, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsInCombat_mutex, "getIsInCombat");
  return nRetVal != 0;
};

bool NWScriptI::getIsInSubArea(const NWN::NWObject& oCreature, const NWN::NWObject& oSubArea, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSubArea.id < 0 || oSubArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsInSubArea_mutex, "getIsInSubArea");
  callCounter += 1;
  StackPushObject(oSubArea.id);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(768, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsInSubArea_mutex, "getIsInSubArea");
  return nRetVal != 0;
};

bool NWScriptI::getIsItemPropertyValid(const NWN::NWItemProperty& ipProperty, const Ice::Current& ice) {
  if (iprpMap.find(ipProperty.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock(getIsItemPropertyValid_mutex, "getIsItemPropertyValid");
  callCounter += 1;
  CGameEffect *ipProperty_ptr = iprpMap.find(ipProperty.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, ipProperty_ptr);

  VM_ExecuteCommand(611, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsItemPropertyValid_mutex, "getIsItemPropertyValid");
  return nRetVal != 0;
};

bool NWScriptI::getIsListening(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsListening_mutex, "getIsListening");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(174, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsListening_mutex, "getIsListening");
  return nRetVal != 0;
};

bool NWScriptI::getIsNeutral(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsNeutral_mutex, "getIsNeutral");
  callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(237, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsNeutral_mutex, "getIsNeutral");
  return nRetVal != 0;
};

bool NWScriptI::getIsNight(const Ice::Current& ice) {
  lock(getIsNight_mutex, "getIsNight");
  callCounter += 1;

  VM_ExecuteCommand(406, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsNight_mutex, "getIsNight");
  return nRetVal != 0;
};

bool NWScriptI::getIsObjectValid(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsObjectValid_mutex, "getIsObjectValid");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(42, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsObjectValid_mutex, "getIsObjectValid");
  return nRetVal != 0;
};

bool NWScriptI::getIsOpen(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsOpen_mutex, "getIsOpen");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(443, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsOpen_mutex, "getIsOpen");
  return nRetVal != 0;
};

bool NWScriptI::getIsPC(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsPC_mutex, "getIsPC");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(217, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsPC_mutex, "getIsPC");
  return nRetVal != 0;
};

bool NWScriptI::getIsPlaceableObjectActionPossible(const NWN::NWObject& oPlaceable, NWN::PlaceableAction tPlaceableAction, const Ice::Current& ice) {
  if (oPlaceable.id < 0 || oPlaceable.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsPlaceableObjectActionPossible_mutex, "getIsPlaceableObjectActionPossible");
  callCounter += 1;
  StackPushInteger(enum_PlaceableAction_2_long(tPlaceableAction));
  
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(546, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsPlaceableObjectActionPossible_mutex, "getIsPlaceableObjectActionPossible");
  return nRetVal != 0;
};

bool NWScriptI::getIsPlayableRacialType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsPlayableRacialType_mutex, "getIsPlayableRacialType");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(312, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsPlayableRacialType_mutex, "getIsPlayableRacialType");
  return nRetVal != 0;
};

bool NWScriptI::getIsPossessedFamiliar(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsPossessedFamiliar_mutex, "getIsPossessedFamiliar");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(714, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsPossessedFamiliar_mutex, "getIsPossessedFamiliar");
  return nRetVal != 0;
};

bool NWScriptI::getIsReactionTypeFriendly(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsReactionTypeFriendly_mutex, "getIsReactionTypeFriendly");
  callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(469, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsReactionTypeFriendly_mutex, "getIsReactionTypeFriendly");
  return nRetVal != 0;
};

bool NWScriptI::getIsReactionTypeHostile(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsReactionTypeHostile_mutex, "getIsReactionTypeHostile");
  callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(471, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsReactionTypeHostile_mutex, "getIsReactionTypeHostile");
  return nRetVal != 0;
};

bool NWScriptI::getIsReactionTypeNeutral(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsReactionTypeNeutral_mutex, "getIsReactionTypeNeutral");
  callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(470, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsReactionTypeNeutral_mutex, "getIsReactionTypeNeutral");
  return nRetVal != 0;
};

bool NWScriptI::getIsResting(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsResting_mutex, "getIsResting");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(505, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsResting_mutex, "getIsResting");
  return nRetVal != 0;
};

bool NWScriptI::getIsSkillSuccessful(const NWN::NWObject& oTarget, Ice::Int nSkill, Ice::Int nDifficulty, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsSkillSuccessful_mutex, "getIsSkillSuccessful");
  callCounter += 1;
  StackPushInteger(nDifficulty);
  StackPushInteger(nSkill);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(689, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsSkillSuccessful_mutex, "getIsSkillSuccessful");
  return nRetVal != 0;
};

bool NWScriptI::getIsTrapped(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsTrapped_mutex, "getIsTrapped");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(551, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsTrapped_mutex, "getIsTrapped");
  return nRetVal != 0;
};

bool NWScriptI::getIsWeaponEffective(const NWN::NWObject& oVersus, bool bOffHand, const Ice::Current& ice) {
  if (oVersus.id < 0 || oVersus.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getIsWeaponEffective_mutex, "getIsWeaponEffective");
  callCounter += 1;
  StackPushInteger(bOffHand == true ? 1 : 0);
  StackPushObject(oVersus.id);

  VM_ExecuteCommand(422, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getIsWeaponEffective_mutex, "getIsWeaponEffective");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getItemACValue(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getItemACValue_mutex, "getItemACValue");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(401, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemACValue_mutex, "getItemACValue");
  return nRetVal;
};

NWN::NWObject NWScriptI::getItemActivated(const Ice::Current& ice) {
  lock(getItemActivated_mutex, "getItemActivated");
  callCounter += 1;

  VM_ExecuteCommand(439, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getItemActivated_mutex, "getItemActivated");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getItemActivatedTarget(const Ice::Current& ice) {
  lock(getItemActivatedTarget_mutex, "getItemActivatedTarget");
  callCounter += 1;

  VM_ExecuteCommand(442, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getItemActivatedTarget_mutex, "getItemActivatedTarget");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWLocation NWScriptI::getItemActivatedTargetLocation(const Ice::Current& ice) {
  lock(getItemActivatedTargetLocation_mutex, "getItemActivatedTargetLocation");
  callCounter += 1;

  VM_ExecuteCommand(441, 0);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.area.id = pRetVal->AreaID;
  nl.x = pRetVal->X;
  nl.y = pRetVal->Y;
  nl.z = pRetVal->Z;
  nl.facing = atan(pRetVal->OrientationY / pRetVal->OrientationX) * (180 / 3.1415927);
  nl.facing += 180;
  while (nl.facing > 360.0) nl.facing -= 360.0; while (nl.facing < 0.0) nl.facing += 360.0;
  unlock(getItemActivatedTargetLocation_mutex, "getItemActivatedTargetLocation");
  return nl;
};

NWN::NWObject NWScriptI::getItemActivator(const Ice::Current& ice) {
  lock(getItemActivator_mutex, "getItemActivator");
  callCounter += 1;

  VM_ExecuteCommand(440, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getItemActivator_mutex, "getItemActivator");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getItemAppearance(const NWN::NWObject& oItem, Ice::Int nType, Ice::Int nIndex, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getItemAppearance_mutex, "getItemAppearance");
  callCounter += 1;
  StackPushInteger(nIndex);
  StackPushInteger(nType);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(732, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemAppearance_mutex, "getItemAppearance");
  return nRetVal;
};

Ice::Int NWScriptI::getItemCharges(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getItemCharges_mutex, "getItemCharges");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(607, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemCharges_mutex, "getItemCharges");
  return nRetVal;
};

bool NWScriptI::getItemCursedFlag(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getItemCursedFlag_mutex, "getItemCursedFlag");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(744, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemCursedFlag_mutex, "getItemCursedFlag");
  return nRetVal != 0;
};

bool NWScriptI::getItemHasItemProperty(const NWN::NWObject& oItem, Ice::Int nProperty, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getItemHasItemProperty_mutex, "getItemHasItemProperty");
  callCounter += 1;
  StackPushInteger(nProperty);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(398, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemHasItemProperty_mutex, "getItemHasItemProperty");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getItemInSlot(NWN::InventorySlot tInventorySlot, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getItemInSlot_mutex, "getItemInSlot");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(enum_InventorySlot_2_long(tInventorySlot));
  

  VM_ExecuteCommand(155, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getItemInSlot_mutex, "getItemInSlot");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getItemPossessedBy(const NWN::NWObject& oCreature, const std::string& sItemTag, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getItemPossessedBy_mutex, "getItemPossessedBy");
  callCounter += 1;
  StackPushString(sItemTag.c_str());
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(30, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getItemPossessedBy_mutex, "getItemPossessedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getItemPossessor(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getItemPossessor_mutex, "getItemPossessor");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(29, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getItemPossessor_mutex, "getItemPossessor");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getItemPropertyCostTable(const NWN::NWItemProperty& iProp, const Ice::Current& ice) {
  if (iprpMap.find(iProp.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock(getItemPropertyCostTable_mutex, "getItemPropertyCostTable");
  callCounter += 1;
  CGameEffect *iProp_ptr = iprpMap.find(iProp.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, iProp_ptr);

  VM_ExecuteCommand(769, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemPropertyCostTable_mutex, "getItemPropertyCostTable");
  return nRetVal;
};

Ice::Int NWScriptI::getItemPropertyCostTableValue(const NWN::NWItemProperty& iProp, const Ice::Current& ice) {
  if (iprpMap.find(iProp.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock(getItemPropertyCostTableValue_mutex, "getItemPropertyCostTableValue");
  callCounter += 1;
  CGameEffect *iProp_ptr = iprpMap.find(iProp.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, iProp_ptr);

  VM_ExecuteCommand(770, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemPropertyCostTableValue_mutex, "getItemPropertyCostTableValue");
  return nRetVal;
};

NWN::DurationType NWScriptI::getItemPropertyDurationType(const NWN::NWItemProperty& ip, const Ice::Current& ice) {
  if (iprpMap.find(ip.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock(getItemPropertyDurationType_mutex, "getItemPropertyDurationType");
  callCounter += 1;
  CGameEffect *ip_ptr = iprpMap.find(ip.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, ip_ptr);

  VM_ExecuteCommand(615, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemPropertyDurationType_mutex, "getItemPropertyDurationType");
    return enum_long_2_DurationType(nRetVal);
  
};

Ice::Int NWScriptI::getItemPropertyParam1(const NWN::NWItemProperty& iProp, const Ice::Current& ice) {
  if (iprpMap.find(iProp.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock(getItemPropertyParam1_mutex, "getItemPropertyParam1");
  callCounter += 1;
  CGameEffect *iProp_ptr = iprpMap.find(iProp.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, iProp_ptr);

  VM_ExecuteCommand(771, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemPropertyParam1_mutex, "getItemPropertyParam1");
  return nRetVal;
};

Ice::Int NWScriptI::getItemPropertyParam1Value(const NWN::NWItemProperty& iProp, const Ice::Current& ice) {
  if (iprpMap.find(iProp.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock(getItemPropertyParam1Value_mutex, "getItemPropertyParam1Value");
  callCounter += 1;
  CGameEffect *iProp_ptr = iprpMap.find(iProp.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, iProp_ptr);

  VM_ExecuteCommand(772, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemPropertyParam1Value_mutex, "getItemPropertyParam1Value");
  return nRetVal;
};

Ice::Int NWScriptI::getItemPropertySubType(const NWN::NWItemProperty& iProperty, const Ice::Current& ice) {
  if (iprpMap.find(iProperty.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock(getItemPropertySubType_mutex, "getItemPropertySubType");
  callCounter += 1;
  CGameEffect *iProperty_ptr = iprpMap.find(iProperty.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, iProperty_ptr);

  VM_ExecuteCommand(734, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemPropertySubType_mutex, "getItemPropertySubType");
  return nRetVal;
};

Ice::Int NWScriptI::getItemPropertyType(const NWN::NWItemProperty& ip, const Ice::Current& ice) {
  if (iprpMap.find(ip.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock(getItemPropertyType_mutex, "getItemPropertyType");
  callCounter += 1;
  CGameEffect *ip_ptr = iprpMap.find(ip.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, ip_ptr);

  VM_ExecuteCommand(614, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemPropertyType_mutex, "getItemPropertyType");
  return nRetVal;
};

Ice::Int NWScriptI::getItemStackSize(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getItemStackSize_mutex, "getItemStackSize");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(605, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getItemStackSize_mutex, "getItemStackSize");
  return nRetVal;
};

Ice::Int NWScriptI::getJournalQuestExperience(const std::string& szPlotID, const Ice::Current& ice) {
  lock(getJournalQuestExperience_mutex, "getJournalQuestExperience");
  callCounter += 1;
  StackPushString(szPlotID.c_str());

  VM_ExecuteCommand(384, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getJournalQuestExperience_mutex, "getJournalQuestExperience");
  return nRetVal;
};

std::string NWScriptI::getKeyRequiredFeedback(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getKeyRequiredFeedback_mutex, "getKeyRequiredFeedback");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(819, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getKeyRequiredFeedback_mutex, "getKeyRequiredFeedback");
  return std::string(sRetVal);
};

NWN::AssociateCommand NWScriptI::getLastAssociateCommand(const NWN::NWObject& oAssociate, const Ice::Current& ice) {
  if (oAssociate.id < 0 || oAssociate.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLastAssociateCommand_mutex, "getLastAssociateCommand");
  callCounter += 1;
  StackPushObject(oAssociate.id);

  VM_ExecuteCommand(321, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLastAssociateCommand_mutex, "getLastAssociateCommand");
    return enum_long_2_AssociateCommand(nRetVal);
  
};

NWN::CombatMode NWScriptI::getLastAttackMode(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLastAttackMode_mutex, "getLastAttackMode");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(318, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLastAttackMode_mutex, "getLastAttackMode");
    return enum_long_2_CombatMode(nRetVal);
  
};

NWN::SpecialAttack NWScriptI::getLastAttackType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLastAttackType_mutex, "getLastAttackType");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(317, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLastAttackType_mutex, "getLastAttackType");
    return enum_long_2_SpecialAttack(nRetVal);
  
};

NWN::NWObject NWScriptI::getLastAttacker(const NWN::NWObject& oAttackee, const Ice::Current& ice) {
  if (oAttackee.id < 0 || oAttackee.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLastAttacker_mutex, "getLastAttacker");
  callCounter += 1;
  StackPushObject(oAttackee.id);

  VM_ExecuteCommand(36, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastAttacker_mutex, "getLastAttacker");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastClosedBy(const Ice::Current& ice) {
  lock(getLastClosedBy_mutex, "getLastClosedBy");
  callCounter += 1;

  VM_ExecuteCommand(260, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastClosedBy_mutex, "getLastClosedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastDamager(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLastDamager_mutex, "getLastDamager");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(346, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastDamager_mutex, "getLastDamager");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastDisarmed(const Ice::Current& ice) {
  lock(getLastDisarmed_mutex, "getLastDisarmed");
  callCounter += 1;

  VM_ExecuteCommand(347, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastDisarmed_mutex, "getLastDisarmed");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastDisturbed(const Ice::Current& ice) {
  lock(getLastDisturbed_mutex, "getLastDisturbed");
  callCounter += 1;

  VM_ExecuteCommand(348, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastDisturbed_mutex, "getLastDisturbed");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastHostileActor(const NWN::NWObject& oVictim, const Ice::Current& ice) {
  if (oVictim.id < 0 || oVictim.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLastHostileActor_mutex, "getLastHostileActor");
  callCounter += 1;
  StackPushObject(oVictim.id);

  VM_ExecuteCommand(556, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastHostileActor_mutex, "getLastHostileActor");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastKiller(const Ice::Current& ice) {
  lock(getLastKiller_mutex, "getLastKiller");
  callCounter += 1;

  VM_ExecuteCommand(437, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastKiller_mutex, "getLastKiller");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastLocked(const Ice::Current& ice) {
  lock(getLastLocked_mutex, "getLastLocked");
  callCounter += 1;

  VM_ExecuteCommand(349, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastLocked_mutex, "getLastLocked");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastOpenedBy(const Ice::Current& ice) {
  lock(getLastOpenedBy_mutex, "getLastOpenedBy");
  callCounter += 1;

  VM_ExecuteCommand(376, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastOpenedBy_mutex, "getLastOpenedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastPCRested(const Ice::Current& ice) {
  lock(getLastPCRested_mutex, "getLastPCRested");
  callCounter += 1;

  VM_ExecuteCommand(506, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastPCRested_mutex, "getLastPCRested");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastPCToCancelCutscene(const Ice::Current& ice) {
  lock(getLastPCToCancelCutscene_mutex, "getLastPCToCancelCutscene");
  callCounter += 1;

  VM_ExecuteCommand(693, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastPCToCancelCutscene_mutex, "getLastPCToCancelCutscene");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastPerceived(const Ice::Current& ice) {
  lock(getLastPerceived_mutex, "getLastPerceived");
  callCounter += 1;

  VM_ExecuteCommand(256, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastPerceived_mutex, "getLastPerceived");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getLastPerceptionHeard(const Ice::Current& ice) {
  lock(getLastPerceptionHeard_mutex, "getLastPerceptionHeard");
  callCounter += 1;

  VM_ExecuteCommand(257, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLastPerceptionHeard_mutex, "getLastPerceptionHeard");
  return nRetVal != 0;
};

bool NWScriptI::getLastPerceptionInaudible(const Ice::Current& ice) {
  lock(getLastPerceptionInaudible_mutex, "getLastPerceptionInaudible");
  callCounter += 1;

  VM_ExecuteCommand(258, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLastPerceptionInaudible_mutex, "getLastPerceptionInaudible");
  return nRetVal != 0;
};

bool NWScriptI::getLastPerceptionSeen(const Ice::Current& ice) {
  lock(getLastPerceptionSeen_mutex, "getLastPerceptionSeen");
  callCounter += 1;

  VM_ExecuteCommand(259, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLastPerceptionSeen_mutex, "getLastPerceptionSeen");
  return nRetVal != 0;
};

bool NWScriptI::getLastPerceptionVanished(const Ice::Current& ice) {
  lock(getLastPerceptionVanished_mutex, "getLastPerceptionVanished");
  callCounter += 1;

  VM_ExecuteCommand(261, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLastPerceptionVanished_mutex, "getLastPerceptionVanished");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getLastPlayerDied(const Ice::Current& ice) {
  lock(getLastPlayerDied_mutex, "getLastPlayerDied");
  callCounter += 1;

  VM_ExecuteCommand(291, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastPlayerDied_mutex, "getLastPlayerDied");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastPlayerDying(const Ice::Current& ice) {
  lock(getLastPlayerDying_mutex, "getLastPlayerDying");
  callCounter += 1;

  VM_ExecuteCommand(410, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastPlayerDying_mutex, "getLastPlayerDying");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastRespawnButtonPresser(const Ice::Current& ice) {
  lock(getLastRespawnButtonPresser_mutex, "getLastRespawnButtonPresser");
  callCounter += 1;

  VM_ExecuteCommand(419, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastRespawnButtonPresser_mutex, "getLastRespawnButtonPresser");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getLastRestEventType(const Ice::Current& ice) {
  lock(getLastRestEventType_mutex, "getLastRestEventType");
  callCounter += 1;

  VM_ExecuteCommand(508, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLastRestEventType_mutex, "getLastRestEventType");
  return nRetVal;
};

NWN::NWObject NWScriptI::getLastSpeaker(const Ice::Current& ice) {
  lock(getLastSpeaker_mutex, "getLastSpeaker");
  callCounter += 1;

  VM_ExecuteCommand(254, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastSpeaker_mutex, "getLastSpeaker");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getLastSpell(const Ice::Current& ice) {
  lock(getLastSpell_mutex, "getLastSpell");
  callCounter += 1;

  VM_ExecuteCommand(246, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLastSpell_mutex, "getLastSpell");
  return nRetVal;
};

Ice::Int NWScriptI::getLastSpellCastClass(const Ice::Current& ice) {
  lock(getLastSpellCastClass_mutex, "getLastSpellCastClass");
  callCounter += 1;

  VM_ExecuteCommand(754, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLastSpellCastClass_mutex, "getLastSpellCastClass");
  return nRetVal;
};

NWN::NWObject NWScriptI::getLastSpellCaster(const Ice::Current& ice) {
  lock(getLastSpellCaster_mutex, "getLastSpellCaster");
  callCounter += 1;

  VM_ExecuteCommand(245, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastSpellCaster_mutex, "getLastSpellCaster");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getLastSpellHarmful(const Ice::Current& ice) {
  lock(getLastSpellHarmful_mutex, "getLastSpellHarmful");
  callCounter += 1;

  VM_ExecuteCommand(423, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLastSpellHarmful_mutex, "getLastSpellHarmful");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getLastTrapDetected(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLastTrapDetected_mutex, "getLastTrapDetected");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(486, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastTrapDetected_mutex, "getLastTrapDetected");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastUnlocked(const Ice::Current& ice) {
  lock(getLastUnlocked_mutex, "getLastUnlocked");
  callCounter += 1;

  VM_ExecuteCommand(350, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastUnlocked_mutex, "getLastUnlocked");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastUsedBy(const Ice::Current& ice) {
  lock(getLastUsedBy_mutex, "getLastUsedBy");
  callCounter += 1;

  VM_ExecuteCommand(330, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastUsedBy_mutex, "getLastUsedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastWeaponUsed(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLastWeaponUsed_mutex, "getLastWeaponUsed");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(328, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLastWeaponUsed_mutex, "getLastWeaponUsed");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getLawChaosValue(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLawChaosValue_mutex, "getLawChaosValue");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(124, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLawChaosValue_mutex, "getLawChaosValue");
  return nRetVal;
};

Ice::Int NWScriptI::getLevelByClass(Ice::Int nClassType, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLevelByClass_mutex, "getLevelByClass");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nClassType);

  VM_ExecuteCommand(343, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLevelByClass_mutex, "getLevelByClass");
  return nRetVal;
};

Ice::Int NWScriptI::getLevelByPosition(Ice::Int nClassPosition, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLevelByPosition_mutex, "getLevelByPosition");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nClassPosition);

  VM_ExecuteCommand(342, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLevelByPosition_mutex, "getLevelByPosition");
  return nRetVal;
};

Ice::Int NWScriptI::getListenPatternNumber(const Ice::Current& ice) {
  lock(getListenPatternNumber_mutex, "getListenPatternNumber");
  callCounter += 1;

  VM_ExecuteCommand(195, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getListenPatternNumber_mutex, "getListenPatternNumber");
  return nRetVal;
};

Ice::Float NWScriptI::getLocalFloat(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLocalFloat_mutex, "getLocalFloat");
  callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(52, 2);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(getLocalFloat_mutex, "getLocalFloat");
  return fRetVal;
};

Ice::Int NWScriptI::getLocalInt(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLocalInt_mutex, "getLocalInt");
  callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(51, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLocalInt_mutex, "getLocalInt");
  return nRetVal;
};

NWN::NWLocation NWScriptI::getLocalLocation(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLocalLocation_mutex, "getLocalLocation");
  callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(153, 2);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.area.id = pRetVal->AreaID;
  nl.x = pRetVal->X;
  nl.y = pRetVal->Y;
  nl.z = pRetVal->Z;
  nl.facing = atan(pRetVal->OrientationY / pRetVal->OrientationX) * (180 / 3.1415927);
  nl.facing += 180;
  while (nl.facing > 360.0) nl.facing -= 360.0; while (nl.facing < 0.0) nl.facing += 360.0;
  unlock(getLocalLocation_mutex, "getLocalLocation");
  return nl;
};

NWN::NWObject NWScriptI::getLocalObject(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLocalObject_mutex, "getLocalObject");
  callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(54, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getLocalObject_mutex, "getLocalObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

std::string NWScriptI::getLocalString(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLocalString_mutex, "getLocalString");
  callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(53, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getLocalString_mutex, "getLocalString");
  return std::string(sRetVal);
};

NWN::NWLocation NWScriptI::getLocation(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLocation_mutex, "getLocation");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(213, 1);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.area.id = pRetVal->AreaID;
  nl.x = pRetVal->X;
  nl.y = pRetVal->Y;
  nl.z = pRetVal->Z;
  nl.facing = atan(pRetVal->OrientationY / pRetVal->OrientationX) * (180 / 3.1415927);
  nl.facing += 180;
  while (nl.facing > 360.0) nl.facing -= 360.0; while (nl.facing < 0.0) nl.facing += 360.0;
  unlock(getLocation_mutex, "getLocation");
  return nl;
};

bool NWScriptI::getLockKeyRequired(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLockKeyRequired_mutex, "getLockKeyRequired");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(537, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLockKeyRequired_mutex, "getLockKeyRequired");
  return nRetVal != 0;
};

std::string NWScriptI::getLockKeyTag(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLockKeyTag_mutex, "getLockKeyTag");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(538, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getLockKeyTag_mutex, "getLockKeyTag");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getLockLockDC(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLockLockDC_mutex, "getLockLockDC");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(541, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLockLockDC_mutex, "getLockLockDC");
  return nRetVal;
};

bool NWScriptI::getLockLockable(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLockLockable_mutex, "getLockLockable");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(539, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLockLockable_mutex, "getLockLockable");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getLockUnlockDC(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLockUnlockDC_mutex, "getLockUnlockDC");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(540, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLockUnlockDC_mutex, "getLockUnlockDC");
  return nRetVal;
};

bool NWScriptI::getLocked(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLocked_mutex, "getLocked");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(325, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLocked_mutex, "getLocked");
  return nRetVal != 0;
};

bool NWScriptI::getLootable(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getLootable_mutex, "getLootable");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(741, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getLootable_mutex, "getLootable");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getMaster(const NWN::NWObject& oAssociate, const Ice::Current& ice) {
  if (oAssociate.id < 0 || oAssociate.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getMaster_mutex, "getMaster");
  callCounter += 1;
  StackPushObject(oAssociate.id);

  VM_ExecuteCommand(319, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getMaster_mutex, "getMaster");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

std::string NWScriptI::getMatchedSubstring(Ice::Int nString, const Ice::Current& ice) {
  lock(getMatchedSubstring_mutex, "getMatchedSubstring");
  callCounter += 1;
  StackPushInteger(nString);

  VM_ExecuteCommand(178, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getMatchedSubstring_mutex, "getMatchedSubstring");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getMatchedSubstringsCount(const Ice::Current& ice) {
  lock(getMatchedSubstringsCount_mutex, "getMatchedSubstringsCount");
  callCounter += 1;

  VM_ExecuteCommand(179, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getMatchedSubstringsCount_mutex, "getMatchedSubstringsCount");
  return nRetVal;
};

Ice::Int NWScriptI::getMaxHenchmen(const Ice::Current& ice) {
  lock(getMaxHenchmen_mutex, "getMaxHenchmen");
  callCounter += 1;

  VM_ExecuteCommand(747, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getMaxHenchmen_mutex, "getMaxHenchmen");
  return nRetVal;
};

Ice::Int NWScriptI::getMaxHitPoints(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getMaxHitPoints_mutex, "getMaxHitPoints");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(50, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getMaxHitPoints_mutex, "getMaxHitPoints");
  return nRetVal;
};

NWN::MetaMagic NWScriptI::getMetaMagicFeat(const Ice::Current& ice) {
  lock(getMetaMagicFeat_mutex, "getMetaMagicFeat");
  callCounter += 1;

  VM_ExecuteCommand(105, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getMetaMagicFeat_mutex, "getMetaMagicFeat");
    return enum_long_2_MetaMagic(nRetVal);
  
};

NWN::NWObject NWScriptI::getModule(const Ice::Current& ice) {
  lock(getModule_mutex, "getModule");
  callCounter += 1;

  VM_ExecuteCommand(242, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getModule_mutex, "getModule");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getModuleItemAcquired(const Ice::Current& ice) {
  lock(getModuleItemAcquired_mutex, "getModuleItemAcquired");
  callCounter += 1;

  VM_ExecuteCommand(282, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getModuleItemAcquired_mutex, "getModuleItemAcquired");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getModuleItemAcquiredBy(const Ice::Current& ice) {
  lock(getModuleItemAcquiredBy_mutex, "getModuleItemAcquiredBy");
  callCounter += 1;

  VM_ExecuteCommand(707, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getModuleItemAcquiredBy_mutex, "getModuleItemAcquiredBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getModuleItemAcquiredFrom(const Ice::Current& ice) {
  lock(getModuleItemAcquiredFrom_mutex, "getModuleItemAcquiredFrom");
  callCounter += 1;

  VM_ExecuteCommand(283, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getModuleItemAcquiredFrom_mutex, "getModuleItemAcquiredFrom");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getModuleItemAcquiredStackSize(const Ice::Current& ice) {
  lock(getModuleItemAcquiredStackSize_mutex, "getModuleItemAcquiredStackSize");
  callCounter += 1;

  VM_ExecuteCommand(579, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getModuleItemAcquiredStackSize_mutex, "getModuleItemAcquiredStackSize");
  return nRetVal;
};

NWN::NWObject NWScriptI::getModuleItemLost(const Ice::Current& ice) {
  lock(getModuleItemLost_mutex, "getModuleItemLost");
  callCounter += 1;

  VM_ExecuteCommand(292, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getModuleItemLost_mutex, "getModuleItemLost");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getModuleItemLostBy(const Ice::Current& ice) {
  lock(getModuleItemLostBy_mutex, "getModuleItemLostBy");
  callCounter += 1;

  VM_ExecuteCommand(293, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getModuleItemLostBy_mutex, "getModuleItemLostBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

std::string NWScriptI::getModuleName(const Ice::Current& ice) {
  lock(getModuleName_mutex, "getModuleName");
  callCounter += 1;

  VM_ExecuteCommand(561, 0);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getModuleName_mutex, "getModuleName");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getModuleXPScale(const Ice::Current& ice) {
  lock(getModuleXPScale_mutex, "getModuleXPScale");
  callCounter += 1;

  VM_ExecuteCommand(817, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getModuleXPScale_mutex, "getModuleXPScale");
  return nRetVal;
};

Ice::Int NWScriptI::getMovementRate(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getMovementRate_mutex, "getMovementRate");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(496, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getMovementRate_mutex, "getMovementRate");
  return nRetVal;
};

std::string NWScriptI::getName(const NWN::NWObject& oObject, bool bOriginalName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getName_mutex, "getName");
  callCounter += 1;
  StackPushInteger(bOriginalName == true ? 1 : 0);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(253, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getName_mutex, "getName");
  return std::string(sRetVal);
};

NWN::NWObject NWScriptI::getNearestCreature(Ice::Int nFirstCriteriaType, Ice::Int nFirstCriteriaValue, const NWN::NWObject& oTarget, Ice::Int nNth, Ice::Int nSecondCriteriaType, Ice::Int nSecondCriteriaValue, Ice::Int nThirdCriteriaType, Ice::Int nThirdCriteriaValue, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getNearestCreature_mutex, "getNearestCreature");
  callCounter += 1;
  StackPushInteger(nThirdCriteriaValue);
  StackPushInteger(nThirdCriteriaType);
  StackPushInteger(nSecondCriteriaValue);
  StackPushInteger(nSecondCriteriaType);
  StackPushInteger(nNth);
  StackPushObject(oTarget.id);
  StackPushInteger(nFirstCriteriaValue);
  StackPushInteger(nFirstCriteriaType);

  VM_ExecuteCommand(38, 8);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNearestCreature_mutex, "getNearestCreature");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNearestCreatureToLocation(Ice::Int nFirstCriteriaType, Ice::Int nFirstCriteriaValue, const NWN::NWLocation& lLocation, Ice::Int nNth, Ice::Int nSecondCriteriaType, Ice::Int nSecondCriteriaValue, Ice::Int nThirdCriteriaType, Ice::Int nThirdCriteriaValue, const Ice::Current& ice) {
  if (lLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(getNearestCreatureToLocation_mutex, "getNearestCreatureToLocation");
  callCounter += 1;
  StackPushInteger(nThirdCriteriaValue);
  StackPushInteger(nThirdCriteriaType);
  StackPushInteger(nSecondCriteriaValue);
  StackPushInteger(nSecondCriteriaType);
  StackPushInteger(nNth);
  
  StackPushFloat(lLocation.facing);
  Vector lLocation_vv;
  lLocation_vv.X = lLocation.x; lLocation_vv.Y = lLocation.y; lLocation_vv.Z = lLocation.z;
  StackPushVector(lLocation_vv);
  StackPushObject(lLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushInteger(nFirstCriteriaValue);
  StackPushInteger(nFirstCriteriaType);

  VM_ExecuteCommand(226, 8);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNearestCreatureToLocation_mutex, "getNearestCreatureToLocation");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNearestObject(NWN::ObjectType tObjectType, const NWN::NWObject& oTarget, Ice::Int nNth, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getNearestObject_mutex, "getNearestObject");
  callCounter += 1;
  StackPushInteger(nNth);
  StackPushObject(oTarget.id);
  StackPushInteger(enum_ObjectType_2_long(tObjectType));
  

  VM_ExecuteCommand(227, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNearestObject_mutex, "getNearestObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNearestObjectByTag(const std::string& sTag, const NWN::NWObject& oTarget, Ice::Int nNth, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getNearestObjectByTag_mutex, "getNearestObjectByTag");
  callCounter += 1;
  StackPushInteger(nNth);
  StackPushObject(oTarget.id);
  StackPushString(sTag.c_str());

  VM_ExecuteCommand(229, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNearestObjectByTag_mutex, "getNearestObjectByTag");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNearestObjectToLocation(NWN::ObjectType tObjectType, const NWN::NWLocation& lLocation, Ice::Int nNth, const Ice::Current& ice) {
  if (lLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(getNearestObjectToLocation_mutex, "getNearestObjectToLocation");
  callCounter += 1;
  StackPushInteger(nNth);
  
  StackPushFloat(lLocation.facing);
  Vector lLocation_vv;
  lLocation_vv.X = lLocation.x; lLocation_vv.Y = lLocation.y; lLocation_vv.Z = lLocation.z;
  StackPushVector(lLocation_vv);
  StackPushObject(lLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushInteger(enum_ObjectType_2_long(tObjectType));
  

  VM_ExecuteCommand(228, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNearestObjectToLocation_mutex, "getNearestObjectToLocation");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNearestTrapToObject(const NWN::NWObject& oTarget, bool bTrapDetected, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getNearestTrapToObject_mutex, "getNearestTrapToObject");
  callCounter += 1;
  StackPushInteger(bTrapDetected == true ? 1 : 0);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(488, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNearestTrapToObject_mutex, "getNearestTrapToObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWEffect NWScriptI::getNextEffect(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getNextEffect_mutex, "getNextEffect");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(86, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(getNextEffect_mutex, "getNextEffect");
  return e;
};

NWN::NWObject NWScriptI::getNextFactionMember(const NWN::NWObject& oMemberOfFaction, bool bPCOnly, const Ice::Current& ice) {
  if (oMemberOfFaction.id < 0 || oMemberOfFaction.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getNextFactionMember_mutex, "getNextFactionMember");
  callCounter += 1;
  StackPushInteger(bPCOnly == true ? 1 : 0);
  StackPushObject(oMemberOfFaction.id);

  VM_ExecuteCommand(381, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNextFactionMember_mutex, "getNextFactionMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNextInPersistentObject(const NWN::NWObject& oPersistentObject, Ice::Int nResidentObjectType, Ice::Int nPersistentZone, const Ice::Current& ice) {
  if (oPersistentObject.id < 0 || oPersistentObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getNextInPersistentObject_mutex, "getNextInPersistentObject");
  callCounter += 1;
  StackPushInteger(nPersistentZone);
  StackPushInteger(nResidentObjectType);
  StackPushObject(oPersistentObject.id);

  VM_ExecuteCommand(263, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNextInPersistentObject_mutex, "getNextInPersistentObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNextItemInInventory(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getNextItemInInventory_mutex, "getNextItemInInventory");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(340, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNextItemInInventory_mutex, "getNextItemInInventory");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWItemProperty NWScriptI::getNextItemProperty(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getNextItemProperty_mutex, "getNextItemProperty");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(613, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(getNextItemProperty_mutex, "getNextItemProperty");
  return e;
};

NWN::NWObject NWScriptI::getNextObjectInArea(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getNextObjectInArea_mutex, "getNextObjectInArea");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(94, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNextObjectInArea_mutex, "getNextObjectInArea");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNextObjectInShape(NWN::ShapeType tShapeType, Ice::Float fSize, const NWN::NWLocation& lTarget, bool bLineOfSight, Ice::Int nObjectFilter, const NWN::NWVector& vOrigin, const Ice::Current& ice) {
  if (lTarget.area.id < 0) throw NWN::InvalidObjectException();
  lock(getNextObjectInShape_mutex, "getNextObjectInShape");
  callCounter += 1;
  Vector vvOrigin;
  vvOrigin.X = vOrigin.x; vvOrigin.Y = vOrigin.y; vvOrigin.Z = vOrigin.z;
  StackPushVector(vvOrigin);
  StackPushInteger(nObjectFilter);
  StackPushInteger(bLineOfSight == true ? 1 : 0);
  
  StackPushFloat(lTarget.facing);
  Vector lTarget_vv;
  lTarget_vv.X = lTarget.x; lTarget_vv.Y = lTarget.y; lTarget_vv.Z = lTarget.z;
  StackPushVector(lTarget_vv);
  StackPushObject(lTarget.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushFloat(fSize);
  StackPushInteger(enum_ShapeType_2_long(tShapeType));
  

  VM_ExecuteCommand(129, 6);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNextObjectInShape_mutex, "getNextObjectInShape");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNextPC(const Ice::Current& ice) {
  lock(getNextPC_mutex, "getNextPC");
  callCounter += 1;

  VM_ExecuteCommand(549, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getNextPC_mutex, "getNextPC");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getNumStackedItems(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getNumStackedItems_mutex, "getNumStackedItems");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(475, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getNumStackedItems_mutex, "getNumStackedItems");
  return nRetVal;
};

NWN::NWObject NWScriptI::getObjectByTag(const std::string& sTag, Ice::Int nNth, const Ice::Current& ice) {
  lock(getObjectByTag_mutex, "getObjectByTag");
  callCounter += 1;
  StackPushInteger(nNth);
  StackPushString(sTag.c_str());

  VM_ExecuteCommand(200, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getObjectByTag_mutex, "getObjectByTag");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getObjectHeard(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getObjectHeard_mutex, "getObjectHeard");
  callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(290, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getObjectHeard_mutex, "getObjectHeard");
  return nRetVal != 0;
};

bool NWScriptI::getObjectSeen(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getObjectSeen_mutex, "getObjectSeen");
  callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(289, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getObjectSeen_mutex, "getObjectSeen");
  return nRetVal != 0;
};

NWN::ObjectType NWScriptI::getObjectType(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getObjectType_mutex, "getObjectType");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(106, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getObjectType_mutex, "getObjectType");
    return enum_long_2_ObjectType(nRetVal);
  
};

std::string NWScriptI::getPCChatMessage(const Ice::Current& ice) {
  lock(getPCChatMessage_mutex, "getPCChatMessage");
  callCounter += 1;

  VM_ExecuteCommand(839, 0);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getPCChatMessage_mutex, "getPCChatMessage");
  return std::string(sRetVal);
};

NWN::NWObject NWScriptI::getPCChatSpeaker(const Ice::Current& ice) {
  lock(getPCChatSpeaker_mutex, "getPCChatSpeaker");
  callCounter += 1;

  VM_ExecuteCommand(838, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getPCChatSpeaker_mutex, "getPCChatSpeaker");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getPCChatVolume(const Ice::Current& ice) {
  lock(getPCChatVolume_mutex, "getPCChatVolume");
  callCounter += 1;

  VM_ExecuteCommand(840, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getPCChatVolume_mutex, "getPCChatVolume");
  return nRetVal;
};

std::string NWScriptI::getPCIPAddress(const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getPCIPAddress_mutex, "getPCIPAddress");
  callCounter += 1;
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(370, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getPCIPAddress_mutex, "getPCIPAddress");
  return std::string(sRetVal);
};

NWN::NWObject NWScriptI::getPCItemLastEquipped(const Ice::Current& ice) {
  lock(getPCItemLastEquipped_mutex, "getPCItemLastEquipped");
  callCounter += 1;

  VM_ExecuteCommand(727, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getPCItemLastEquipped_mutex, "getPCItemLastEquipped");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getPCItemLastEquippedBy(const Ice::Current& ice) {
  lock(getPCItemLastEquippedBy_mutex, "getPCItemLastEquippedBy");
  callCounter += 1;

  VM_ExecuteCommand(728, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getPCItemLastEquippedBy_mutex, "getPCItemLastEquippedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getPCItemLastUnequipped(const Ice::Current& ice) {
  lock(getPCItemLastUnequipped_mutex, "getPCItemLastUnequipped");
  callCounter += 1;

  VM_ExecuteCommand(729, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getPCItemLastUnequipped_mutex, "getPCItemLastUnequipped");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getPCItemLastUnequippedBy(const Ice::Current& ice) {
  lock(getPCItemLastUnequippedBy_mutex, "getPCItemLastUnequippedBy");
  callCounter += 1;

  VM_ExecuteCommand(730, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getPCItemLastUnequippedBy_mutex, "getPCItemLastUnequippedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getPCLevellingUp(const Ice::Current& ice) {
  lock(getPCLevellingUp_mutex, "getPCLevellingUp");
  callCounter += 1;

  VM_ExecuteCommand(542, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getPCLevellingUp_mutex, "getPCLevellingUp");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

std::string NWScriptI::getPCPlayerName(const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getPCPlayerName_mutex, "getPCPlayerName");
  callCounter += 1;
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(371, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getPCPlayerName_mutex, "getPCPlayerName");
  return std::string(sRetVal);
};

std::string NWScriptI::getPCPublicCDKey(const NWN::NWObject& oPlayer, bool bSinglePlayerCDKey, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getPCPublicCDKey_mutex, "getPCPublicCDKey");
  callCounter += 1;
  StackPushInteger(bSinglePlayerCDKey == true ? 1 : 0);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(369, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getPCPublicCDKey_mutex, "getPCPublicCDKey");
  return std::string(sRetVal);
};

NWN::NWObject NWScriptI::getPCSpeaker(const Ice::Current& ice) {
  lock(getPCSpeaker_mutex, "getPCSpeaker");
  callCounter += 1;

  VM_ExecuteCommand(238, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getPCSpeaker_mutex, "getPCSpeaker");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::PhenoType NWScriptI::getPhenoType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getPhenoType_mutex, "getPhenoType");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(778, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getPhenoType_mutex, "getPhenoType");
    return enum_long_2_PhenoType(nRetVal);
  
};

bool NWScriptI::getPickpocketableFlag(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getPickpocketableFlag_mutex, "getPickpocketableFlag");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(786, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getPickpocketableFlag_mutex, "getPickpocketableFlag");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getPlaceableIllumination(const NWN::NWObject& oPlaceable, const Ice::Current& ice) {
  if (oPlaceable.id < 0 || oPlaceable.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getPlaceableIllumination_mutex, "getPlaceableIllumination");
  callCounter += 1;
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(545, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getPlaceableIllumination_mutex, "getPlaceableIllumination");
  return nRetVal;
};

NWN::NWObject NWScriptI::getPlaceableLastClickedBy(const Ice::Current& ice) {
  lock(getPlaceableLastClickedBy_mutex, "getPlaceableLastClickedBy");
  callCounter += 1;

  VM_ExecuteCommand(826, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getPlaceableLastClickedBy_mutex, "getPlaceableLastClickedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getPlotFlag(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getPlotFlag_mutex, "getPlotFlag");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(455, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getPlotFlag_mutex, "getPlotFlag");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getPortraitId(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getPortraitId_mutex, "getPortraitId");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(831, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getPortraitId_mutex, "getPortraitId");
  return nRetVal;
};

std::string NWScriptI::getPortraitResRef(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getPortraitResRef_mutex, "getPortraitResRef");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(833, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getPortraitResRef_mutex, "getPortraitResRef");
  return std::string(sRetVal);
};

NWN::NWVector NWScriptI::getPosition(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getPosition_mutex, "getPosition");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(27, 1);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock(getPosition_mutex, "getPosition");
  return nv;
};

NWN::NWVector NWScriptI::getPositionFromLocation(const NWN::NWLocation& lLocation, const Ice::Current& ice) {
  if (lLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(getPositionFromLocation_mutex, "getPositionFromLocation");
  callCounter += 1;
  
  StackPushFloat(lLocation.facing);
  Vector lLocation_vv;
  lLocation_vv.X = lLocation.x; lLocation_vv.Y = lLocation.y; lLocation_vv.Z = lLocation.z;
  StackPushVector(lLocation_vv);
  StackPushObject(lLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(223, 1);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock(getPositionFromLocation_mutex, "getPositionFromLocation");
  return nv;
};

NWN::RacialType NWScriptI::getRacialType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getRacialType_mutex, "getRacialType");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(107, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getRacialType_mutex, "getRacialType");
    return enum_long_2_RacialType(nRetVal);
  
};

Ice::Int NWScriptI::getReflexAdjustedDamage(Ice::Int nDamage, const NWN::NWObject& oTarget, Ice::Int nDC, NWN::SaveType tSaveType, const NWN::NWObject& oSaveVersus, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSaveVersus.id < 0 || oSaveVersus.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getReflexAdjustedDamage_mutex, "getReflexAdjustedDamage");
  callCounter += 1;
  StackPushObject(oSaveVersus.id);
  StackPushInteger(enum_SaveType_2_long(tSaveType));
  
  StackPushInteger(nDC);
  StackPushObject(oTarget.id);
  StackPushInteger(nDamage);

  VM_ExecuteCommand(299, 5);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getReflexAdjustedDamage_mutex, "getReflexAdjustedDamage");
  return nRetVal;
};

Ice::Int NWScriptI::getReflexSavingThrow(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getReflexSavingThrow_mutex, "getReflexSavingThrow");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(493, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getReflexSavingThrow_mutex, "getReflexSavingThrow");
  return nRetVal;
};

Ice::Int NWScriptI::getReputation(const NWN::NWObject& oSource, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getReputation_mutex, "getReputation");
  callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oSource.id);

  VM_ExecuteCommand(208, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getReputation_mutex, "getReputation");
  return nRetVal;
};

std::string NWScriptI::getResRef(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getResRef_mutex, "getResRef");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(582, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getResRef_mutex, "getResRef");
  return std::string(sRetVal);
};

NWN::NWObject NWScriptI::getSittingCreature(const NWN::NWObject& oChair, const Ice::Current& ice) {
  if (oChair.id < 0 || oChair.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getSittingCreature_mutex, "getSittingCreature");
  callCounter += 1;
  StackPushObject(oChair.id);

  VM_ExecuteCommand(210, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getSittingCreature_mutex, "getSittingCreature");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getSkillRank(Ice::Int nSkill, const NWN::NWObject& oTarget, bool bBaseSkillRank, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getSkillRank_mutex, "getSkillRank");
  callCounter += 1;
  StackPushInteger(bBaseSkillRank == true ? 1 : 0);
  StackPushObject(oTarget.id);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(315, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getSkillRank_mutex, "getSkillRank");
  return nRetVal;
};

Ice::Int NWScriptI::getSkyBox(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getSkyBox_mutex, "getSkyBox");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(782, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getSkyBox_mutex, "getSkyBox");
  return nRetVal;
};

NWN::NWObject NWScriptI::getSpellCastItem(const Ice::Current& ice) {
  lock(getSpellCastItem_mutex, "getSpellCastItem");
  callCounter += 1;

  VM_ExecuteCommand(438, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getSpellCastItem_mutex, "getSpellCastItem");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getSpellId(const Ice::Current& ice) {
  lock(getSpellId_mutex, "getSpellId");
  callCounter += 1;

  VM_ExecuteCommand(248, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getSpellId_mutex, "getSpellId");
  return nRetVal;
};

Ice::Int NWScriptI::getSpellResistance(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getSpellResistance_mutex, "getSpellResistance");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(749, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getSpellResistance_mutex, "getSpellResistance");
  return nRetVal;
};

Ice::Int NWScriptI::getSpellSaveDC(const Ice::Current& ice) {
  lock(getSpellSaveDC_mutex, "getSpellSaveDC");
  callCounter += 1;

  VM_ExecuteCommand(111, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getSpellSaveDC_mutex, "getSpellSaveDC");
  return nRetVal;
};

NWN::NWLocation NWScriptI::getSpellTargetLocation(const Ice::Current& ice) {
  lock(getSpellTargetLocation_mutex, "getSpellTargetLocation");
  callCounter += 1;

  VM_ExecuteCommand(222, 0);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.area.id = pRetVal->AreaID;
  nl.x = pRetVal->X;
  nl.y = pRetVal->Y;
  nl.z = pRetVal->Z;
  nl.facing = atan(pRetVal->OrientationY / pRetVal->OrientationX) * (180 / 3.1415927);
  nl.facing += 180;
  while (nl.facing > 360.0) nl.facing -= 360.0; while (nl.facing < 0.0) nl.facing += 360.0;
  unlock(getSpellTargetLocation_mutex, "getSpellTargetLocation");
  return nl;
};

NWN::NWObject NWScriptI::getSpellTargetObject(const Ice::Current& ice) {
  lock(getSpellTargetObject_mutex, "getSpellTargetObject");
  callCounter += 1;

  VM_ExecuteCommand(47, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getSpellTargetObject_mutex, "getSpellTargetObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getStandardFactionReputation(NWN::StandardFaction tStandardFaction, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getStandardFactionReputation_mutex, "getStandardFactionReputation");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(enum_StandardFaction_2_long(tStandardFaction));
  

  VM_ExecuteCommand(524, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getStandardFactionReputation_mutex, "getStandardFactionReputation");
  return nRetVal;
};

NWN::NWLocation NWScriptI::getStartingLocation(const Ice::Current& ice) {
  lock(getStartingLocation_mutex, "getStartingLocation");
  callCounter += 1;

  VM_ExecuteCommand(411, 0);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.area.id = pRetVal->AreaID;
  nl.x = pRetVal->X;
  nl.y = pRetVal->Y;
  nl.z = pRetVal->Z;
  nl.facing = atan(pRetVal->OrientationY / pRetVal->OrientationX) * (180 / 3.1415927);
  nl.facing += 180;
  while (nl.facing > 360.0) nl.facing -= 360.0; while (nl.facing < 0.0) nl.facing += 360.0;
  unlock(getStartingLocation_mutex, "getStartingLocation");
  return nl;
};

Ice::Int NWScriptI::getStealthMode(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getStealthMode_mutex, "getStealthMode");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(574, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getStealthMode_mutex, "getStealthMode");
  return nRetVal;
};

bool NWScriptI::getStolenFlag(const NWN::NWObject& oStolen, const Ice::Current& ice) {
  if (oStolen.id < 0 || oStolen.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getStolenFlag_mutex, "getStolenFlag");
  callCounter += 1;
  StackPushObject(oStolen.id);

  VM_ExecuteCommand(588, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getStolenFlag_mutex, "getStolenFlag");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getStoreGold(const NWN::NWObject& oidStore, const Ice::Current& ice) {
  if (oidStore.id < 0 || oidStore.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getStoreGold_mutex, "getStoreGold");
  callCounter += 1;
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(759, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getStoreGold_mutex, "getStoreGold");
  return nRetVal;
};

Ice::Int NWScriptI::getStoreIdentifyCost(const NWN::NWObject& oidStore, const Ice::Current& ice) {
  if (oidStore.id < 0 || oidStore.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getStoreIdentifyCost_mutex, "getStoreIdentifyCost");
  callCounter += 1;
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(763, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getStoreIdentifyCost_mutex, "getStoreIdentifyCost");
  return nRetVal;
};

Ice::Int NWScriptI::getStoreMaxBuyPrice(const NWN::NWObject& oidStore, const Ice::Current& ice) {
  if (oidStore.id < 0 || oidStore.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getStoreMaxBuyPrice_mutex, "getStoreMaxBuyPrice");
  callCounter += 1;
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(761, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getStoreMaxBuyPrice_mutex, "getStoreMaxBuyPrice");
  return nRetVal;
};

Ice::Float NWScriptI::getStrRefSoundDuration(Ice::Int nStrRef, const Ice::Current& ice) {
  lock(getStrRefSoundDuration_mutex, "getStrRefSoundDuration");
  callCounter += 1;
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(571, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(getStrRefSoundDuration_mutex, "getStrRefSoundDuration");
  return fRetVal;
};

std::string NWScriptI::getStringByStrRef(Ice::Int nStrRef, NWN::Gender tGender, const Ice::Current& ice) {
  lock(getStringByStrRef_mutex, "getStringByStrRef");
  callCounter += 1;
  StackPushInteger(enum_Gender_2_long(tGender));
  
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(239, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getStringByStrRef_mutex, "getStringByStrRef");
  return std::string(sRetVal);
};

std::string NWScriptI::getStringLeft(const std::string& sString, Ice::Int nCount, const Ice::Current& ice) {
  lock(getStringLeft_mutex, "getStringLeft");
  callCounter += 1;
  StackPushInteger(nCount);
  StackPushString(sString.c_str());

  VM_ExecuteCommand(63, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getStringLeft_mutex, "getStringLeft");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getStringLength(const std::string& sString, const Ice::Current& ice) {
  lock(getStringLength_mutex, "getStringLength");
  callCounter += 1;
  StackPushString(sString.c_str());

  VM_ExecuteCommand(59, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getStringLength_mutex, "getStringLength");
  return nRetVal;
};

std::string NWScriptI::getStringLowerCase(const std::string& sString, const Ice::Current& ice) {
  lock(getStringLowerCase_mutex, "getStringLowerCase");
  callCounter += 1;
  StackPushString(sString.c_str());

  VM_ExecuteCommand(61, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getStringLowerCase_mutex, "getStringLowerCase");
  return std::string(sRetVal);
};

std::string NWScriptI::getStringRight(const std::string& sString, Ice::Int nCount, const Ice::Current& ice) {
  lock(getStringRight_mutex, "getStringRight");
  callCounter += 1;
  StackPushInteger(nCount);
  StackPushString(sString.c_str());

  VM_ExecuteCommand(62, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getStringRight_mutex, "getStringRight");
  return std::string(sRetVal);
};

std::string NWScriptI::getStringUpperCase(const std::string& sString, const Ice::Current& ice) {
  lock(getStringUpperCase_mutex, "getStringUpperCase");
  callCounter += 1;
  StackPushString(sString.c_str());

  VM_ExecuteCommand(60, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getStringUpperCase_mutex, "getStringUpperCase");
  return std::string(sRetVal);
};

std::string NWScriptI::getSubRace(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getSubRace_mutex, "getSubRace");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(490, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getSubRace_mutex, "getSubRace");
  return std::string(sRetVal);
};

std::string NWScriptI::getSubString(const std::string& sString, Ice::Int nStart, Ice::Int nCount, const Ice::Current& ice) {
  lock(getSubString_mutex, "getSubString");
  callCounter += 1;
  StackPushInteger(nCount);
  StackPushInteger(nStart);
  StackPushString(sString.c_str());

  VM_ExecuteCommand(65, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getSubString_mutex, "getSubString");
  return std::string(sRetVal);
};

std::string NWScriptI::getTag(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTag_mutex, "getTag");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(168, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getTag_mutex, "getTag");
  return std::string(sRetVal);
};

NWN::TileMainLightColor NWScriptI::getTileMainLight1Color(const NWN::NWLocation& lTile, const Ice::Current& ice) {
  if (lTile.area.id < 0) throw NWN::InvalidObjectException();
  lock(getTileMainLight1Color_mutex, "getTileMainLight1Color");
  callCounter += 1;
  
  StackPushFloat(lTile.facing);
  Vector lTile_vv;
  lTile_vv.X = lTile.x; lTile_vv.Y = lTile.y; lTile_vv.Z = lTile.z;
  StackPushVector(lTile_vv);
  StackPushObject(lTile.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(517, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTileMainLight1Color_mutex, "getTileMainLight1Color");
    return enum_long_2_TileMainLightColor(nRetVal);
  
};

NWN::TileMainLightColor NWScriptI::getTileMainLight2Color(const NWN::NWLocation& lTile, const Ice::Current& ice) {
  if (lTile.area.id < 0) throw NWN::InvalidObjectException();
  lock(getTileMainLight2Color_mutex, "getTileMainLight2Color");
  callCounter += 1;
  
  StackPushFloat(lTile.facing);
  Vector lTile_vv;
  lTile_vv.X = lTile.x; lTile_vv.Y = lTile.y; lTile_vv.Z = lTile.z;
  StackPushVector(lTile_vv);
  StackPushObject(lTile.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(518, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTileMainLight2Color_mutex, "getTileMainLight2Color");
    return enum_long_2_TileMainLightColor(nRetVal);
  
};

NWN::TileSourceLightColor NWScriptI::getTileSourceLight1Color(const NWN::NWLocation& lTile, const Ice::Current& ice) {
  if (lTile.area.id < 0) throw NWN::InvalidObjectException();
  lock(getTileSourceLight1Color_mutex, "getTileSourceLight1Color");
  callCounter += 1;
  
  StackPushFloat(lTile.facing);
  Vector lTile_vv;
  lTile_vv.X = lTile.x; lTile_vv.Y = lTile.y; lTile_vv.Z = lTile.z;
  StackPushVector(lTile_vv);
  StackPushObject(lTile.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(519, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTileSourceLight1Color_mutex, "getTileSourceLight1Color");
    return enum_long_2_TileSourceLightColor(nRetVal);
  
};

NWN::TileSourceLightColor NWScriptI::getTileSourceLight2Color(const NWN::NWLocation& lTile, const Ice::Current& ice) {
  if (lTile.area.id < 0) throw NWN::InvalidObjectException();
  lock(getTileSourceLight2Color_mutex, "getTileSourceLight2Color");
  callCounter += 1;
  
  StackPushFloat(lTile.facing);
  Vector lTile_vv;
  lTile_vv.X = lTile.x; lTile_vv.Y = lTile.y; lTile_vv.Z = lTile.z;
  StackPushVector(lTile_vv);
  StackPushObject(lTile.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(520, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTileSourceLight2Color_mutex, "getTileSourceLight2Color");
    return enum_long_2_TileSourceLightColor(nRetVal);
  
};

std::string NWScriptI::getTilesetResRef(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTilesetResRef_mutex, "getTilesetResRef");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(814, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getTilesetResRef_mutex, "getTilesetResRef");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getTimeHour(const Ice::Current& ice) {
  lock(getTimeHour_mutex, "getTimeHour");
  callCounter += 1;

  VM_ExecuteCommand(16, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTimeHour_mutex, "getTimeHour");
  return nRetVal;
};

Ice::Int NWScriptI::getTimeMillisecond(const Ice::Current& ice) {
  lock(getTimeMillisecond_mutex, "getTimeMillisecond");
  callCounter += 1;

  VM_ExecuteCommand(19, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTimeMillisecond_mutex, "getTimeMillisecond");
  return nRetVal;
};

Ice::Int NWScriptI::getTimeMinute(const Ice::Current& ice) {
  lock(getTimeMinute_mutex, "getTimeMinute");
  callCounter += 1;

  VM_ExecuteCommand(17, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTimeMinute_mutex, "getTimeMinute");
  return nRetVal;
};

Ice::Int NWScriptI::getTimeSecond(const Ice::Current& ice) {
  lock(getTimeSecond_mutex, "getTimeSecond");
  callCounter += 1;

  VM_ExecuteCommand(18, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTimeSecond_mutex, "getTimeSecond");
  return nRetVal;
};

Ice::Int NWScriptI::getTotalDamageDealt(const Ice::Current& ice) {
  lock(getTotalDamageDealt_mutex, "getTotalDamageDealt");
  callCounter += 1;

  VM_ExecuteCommand(345, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTotalDamageDealt_mutex, "getTotalDamageDealt");
  return nRetVal;
};

NWN::NWObject NWScriptI::getTransitionTarget(const NWN::NWObject& oTransition, const Ice::Current& ice) {
  if (oTransition.id < 0 || oTransition.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTransitionTarget_mutex, "getTransitionTarget");
  callCounter += 1;
  StackPushObject(oTransition.id);

  VM_ExecuteCommand(198, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getTransitionTarget_mutex, "getTransitionTarget");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getTrapActive(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapActive_mutex, "getTrapActive");
  callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(821, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTrapActive_mutex, "getTrapActive");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getTrapBaseType(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapBaseType_mutex, "getTrapBaseType");
  callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(531, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTrapBaseType_mutex, "getTrapBaseType");
  return nRetVal;
};

NWN::NWObject NWScriptI::getTrapCreator(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapCreator_mutex, "getTrapCreator");
  callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(533, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getTrapCreator_mutex, "getTrapCreator");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getTrapDetectDC(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapDetectDC_mutex, "getTrapDetectDC");
  callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(536, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTrapDetectDC_mutex, "getTrapDetectDC");
  return nRetVal;
};

bool NWScriptI::getTrapDetectable(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapDetectable_mutex, "getTrapDetectable");
  callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(528, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTrapDetectable_mutex, "getTrapDetectable");
  return nRetVal != 0;
};

bool NWScriptI::getTrapDetectedBy(const NWN::NWObject& oTrapObject, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapDetectedBy_mutex, "getTrapDetectedBy");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(529, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTrapDetectedBy_mutex, "getTrapDetectedBy");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getTrapDisarmDC(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapDisarmDC_mutex, "getTrapDisarmDC");
  callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(535, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTrapDisarmDC_mutex, "getTrapDisarmDC");
  return nRetVal;
};

bool NWScriptI::getTrapDisarmable(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapDisarmable_mutex, "getTrapDisarmable");
  callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(527, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTrapDisarmable_mutex, "getTrapDisarmable");
  return nRetVal != 0;
};

bool NWScriptI::getTrapFlagged(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapFlagged_mutex, "getTrapFlagged");
  callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(530, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTrapFlagged_mutex, "getTrapFlagged");
  return nRetVal != 0;
};

std::string NWScriptI::getTrapKeyTag(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapKeyTag_mutex, "getTrapKeyTag");
  callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(534, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(getTrapKeyTag_mutex, "getTrapKeyTag");
  return std::string(sRetVal);
};

bool NWScriptI::getTrapOneShot(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapOneShot_mutex, "getTrapOneShot");
  callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(532, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTrapOneShot_mutex, "getTrapOneShot");
  return nRetVal != 0;
};

bool NWScriptI::getTrapRecoverable(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTrapRecoverable_mutex, "getTrapRecoverable");
  callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(815, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTrapRecoverable_mutex, "getTrapRecoverable");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getTurnResistanceHD(const NWN::NWObject& oUndead, const Ice::Current& ice) {
  if (oUndead.id < 0 || oUndead.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getTurnResistanceHD_mutex, "getTurnResistanceHD");
  callCounter += 1;
  StackPushObject(oUndead.id);

  VM_ExecuteCommand(478, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getTurnResistanceHD_mutex, "getTurnResistanceHD");
  return nRetVal;
};

bool NWScriptI::getUseableFlag(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getUseableFlag_mutex, "getUseableFlag");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(587, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getUseableFlag_mutex, "getUseableFlag");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getUserDefinedEventNumber(const Ice::Current& ice) {
  lock(getUserDefinedEventNumber_mutex, "getUserDefinedEventNumber");
  callCounter += 1;

  VM_ExecuteCommand(247, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getUserDefinedEventNumber_mutex, "getUserDefinedEventNumber");
  return nRetVal;
};

NWN::NWObject NWScriptI::getWaypointByTag(const std::string& sWaypointTag, const Ice::Current& ice) {
  lock(getWaypointByTag_mutex, "getWaypointByTag");
  callCounter += 1;
  StackPushString(sWaypointTag.c_str());

  VM_ExecuteCommand(197, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(getWaypointByTag_mutex, "getWaypointByTag");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getWeaponRanged(const NWN::NWObject& oItem, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getWeaponRanged_mutex, "getWeaponRanged");
  callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(511, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getWeaponRanged_mutex, "getWeaponRanged");
  return nRetVal != 0;
};

NWN::Weather NWScriptI::getWeather(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getWeather_mutex, "getWeather");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(724, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getWeather_mutex, "getWeather");
    return enum_long_2_Weather(nRetVal);
  
};

Ice::Int NWScriptI::getWeight(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getWeight_mutex, "getWeight");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(706, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getWeight_mutex, "getWeight");
  return nRetVal;
};

Ice::Int NWScriptI::getWillSavingThrow(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getWillSavingThrow_mutex, "getWillSavingThrow");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(492, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getWillSavingThrow_mutex, "getWillSavingThrow");
  return nRetVal;
};

Ice::Int NWScriptI::getXP(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(getXP_mutex, "getXP");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(395, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(getXP_mutex, "getXP");
  return nRetVal;
};

void NWScriptI::giveGoldToCreature(const NWN::NWObject& oCreature, Ice::Int nGP, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(giveGoldToCreature_mutex, "giveGoldToCreature");
  callCounter += 1;
  StackPushInteger(nGP);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(322, 2);

unlock(giveGoldToCreature_mutex, "giveGoldToCreature");
  
};

void NWScriptI::giveXPToCreature(const NWN::NWObject& oCreature, Ice::Int nXpAmount, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(giveXPToCreature_mutex, "giveXPToCreature");
  callCounter += 1;
  StackPushInteger(nXpAmount);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(393, 2);

unlock(giveXPToCreature_mutex, "giveXPToCreature");
  
};

Ice::Float NWScriptI::hoursToSeconds(Ice::Int nHours, const Ice::Current& ice) {
  lock(hoursToSeconds_mutex, "hoursToSeconds");
  callCounter += 1;
  StackPushInteger(nHours);

  VM_ExecuteCommand(122, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(hoursToSeconds_mutex, "hoursToSeconds");
  return fRetVal;
};

void NWScriptI::incrementRemainingFeatUses(const NWN::NWObject& oCreature, Ice::Int nFeat, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(incrementRemainingFeatUses_mutex, "incrementRemainingFeatUses");
  callCounter += 1;
  StackPushInteger(nFeat);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(718, 2);

unlock(incrementRemainingFeatUses_mutex, "incrementRemainingFeatUses");
  
};

std::string NWScriptI::insertString(const std::string& sDestination, const std::string& sString, Ice::Int nPosition, const Ice::Current& ice) {
  lock(insertString_mutex, "insertString");
  callCounter += 1;
  StackPushInteger(nPosition);
  StackPushString(sString.c_str());
  StackPushString(sDestination.c_str());

  VM_ExecuteCommand(64, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(insertString_mutex, "insertString");
  return std::string(sRetVal);
};

Ice::Float NWScriptI::intToFloat(Ice::Int nInteger, const Ice::Current& ice) {
  lock(intToFloat_mutex, "intToFloat");
  callCounter += 1;
  StackPushInteger(nInteger);

  VM_ExecuteCommand(230, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(intToFloat_mutex, "intToFloat");
  return fRetVal;
};

std::string NWScriptI::intToHexString(Ice::Int nInteger, const Ice::Current& ice) {
  lock(intToHexString_mutex, "intToHexString");
  callCounter += 1;
  StackPushInteger(nInteger);

  VM_ExecuteCommand(396, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(intToHexString_mutex, "intToHexString");
  return std::string(sRetVal);
};

std::string NWScriptI::intToString(Ice::Int nInteger, const Ice::Current& ice) {
  lock(intToString_mutex, "intToString");
  callCounter += 1;
  StackPushInteger(nInteger);

  VM_ExecuteCommand(92, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(intToString_mutex, "intToString");
  return std::string(sRetVal);
};

bool NWScriptI::isInConversation(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(isInConversation_mutex, "isInConversation");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(445, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(isInConversation_mutex, "isInConversation");
  return nRetVal != 0;
};

NWN::NWItemProperty NWScriptI::itemPropertyACBonus(Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyACBonus_mutex, "itemPropertyACBonus");
  callCounter += 1;
  StackPushInteger(nBonus);

  VM_ExecuteCommand(617, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyACBonus_mutex, "itemPropertyACBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyACBonusVsAlign(NWN::IPAlignGroup tIPAlignGroup, Ice::Int nACBonus, const Ice::Current& ice) {
  lock(itemPropertyACBonusVsAlign_mutex, "itemPropertyACBonusVsAlign");
  callCounter += 1;
  StackPushInteger(nACBonus);
  StackPushInteger(enum_IPAlignGroup_2_long(tIPAlignGroup));
  

  VM_ExecuteCommand(618, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyACBonusVsAlign_mutex, "itemPropertyACBonusVsAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyACBonusVsDmgType(NWN::IPDamageType tIPDamageType, Ice::Int nACBonus, const Ice::Current& ice) {
  lock(itemPropertyACBonusVsDmgType_mutex, "itemPropertyACBonusVsDmgType");
  callCounter += 1;
  StackPushInteger(nACBonus);
  StackPushInteger(enum_IPDamageType_2_long(tIPDamageType));
  

  VM_ExecuteCommand(619, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyACBonusVsDmgType_mutex, "itemPropertyACBonusVsDmgType");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyACBonusVsRace(NWN::IPRacialType tIPRacialType, Ice::Int nACBonus, const Ice::Current& ice) {
  lock(itemPropertyACBonusVsRace_mutex, "itemPropertyACBonusVsRace");
  callCounter += 1;
  StackPushInteger(nACBonus);
  StackPushInteger(enum_IPRacialType_2_long(tIPRacialType));
  

  VM_ExecuteCommand(620, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyACBonusVsRace_mutex, "itemPropertyACBonusVsRace");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyACBonusVsSAlign(NWN::Alignment tAlignment, Ice::Int nACBonus, const Ice::Current& ice) {
  lock(itemPropertyACBonusVsSAlign_mutex, "itemPropertyACBonusVsSAlign");
  callCounter += 1;
  StackPushInteger(nACBonus);
  StackPushInteger(enum_Alignment_2_long(tAlignment));
  

  VM_ExecuteCommand(621, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyACBonusVsSAlign_mutex, "itemPropertyACBonusVsSAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAbilityBonus(NWN::Ability tAbility, Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyAbilityBonus_mutex, "itemPropertyAbilityBonus");
  callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(enum_Ability_2_long(tAbility));
  

  VM_ExecuteCommand(616, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyAbilityBonus_mutex, "itemPropertyAbilityBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAdditional(Ice::Int nAdditionalProperty, const Ice::Current& ice) {
  lock(itemPropertyAdditional_mutex, "itemPropertyAdditional");
  callCounter += 1;
  StackPushInteger(nAdditionalProperty);

  VM_ExecuteCommand(847, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyAdditional_mutex, "itemPropertyAdditional");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyArcaneSpellFailure(Ice::Int nModLevel, const Ice::Current& ice) {
  lock(itemPropertyArcaneSpellFailure_mutex, "itemPropertyArcaneSpellFailure");
  callCounter += 1;
  StackPushInteger(nModLevel);

  VM_ExecuteCommand(758, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyArcaneSpellFailure_mutex, "itemPropertyArcaneSpellFailure");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAttackBonus(Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyAttackBonus_mutex, "itemPropertyAttackBonus");
  callCounter += 1;
  StackPushInteger(nBonus);

  VM_ExecuteCommand(666, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyAttackBonus_mutex, "itemPropertyAttackBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAttackBonusVsAlign(NWN::IPAlignGroup tIPAlignGroup, Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyAttackBonusVsAlign_mutex, "itemPropertyAttackBonusVsAlign");
  callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(enum_IPAlignGroup_2_long(tIPAlignGroup));
  

  VM_ExecuteCommand(667, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyAttackBonusVsAlign_mutex, "itemPropertyAttackBonusVsAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAttackBonusVsRace(NWN::IPRacialType tIPRacialType, Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyAttackBonusVsRace_mutex, "itemPropertyAttackBonusVsRace");
  callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(enum_IPRacialType_2_long(tIPRacialType));
  

  VM_ExecuteCommand(668, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyAttackBonusVsRace_mutex, "itemPropertyAttackBonusVsRace");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAttackBonusVsSAlign(NWN::Alignment tAlignment, Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyAttackBonusVsSAlign_mutex, "itemPropertyAttackBonusVsSAlign");
  callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(enum_Alignment_2_long(tAlignment));
  

  VM_ExecuteCommand(669, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyAttackBonusVsSAlign_mutex, "itemPropertyAttackBonusVsSAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAttackPenalty(Ice::Int nPenalty, const Ice::Current& ice) {
  lock(itemPropertyAttackPenalty_mutex, "itemPropertyAttackPenalty");
  callCounter += 1;
  StackPushInteger(nPenalty);

  VM_ExecuteCommand(670, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyAttackPenalty_mutex, "itemPropertyAttackPenalty");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyBonusFeat(Ice::Int nFeat, const Ice::Current& ice) {
  lock(itemPropertyBonusFeat_mutex, "itemPropertyBonusFeat");
  callCounter += 1;
  StackPushInteger(nFeat);

  VM_ExecuteCommand(628, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyBonusFeat_mutex, "itemPropertyBonusFeat");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyBonusLevelSpell(Ice::Int nClass, Ice::Int nSpellLevel, const Ice::Current& ice) {
  lock(itemPropertyBonusLevelSpell_mutex, "itemPropertyBonusLevelSpell");
  callCounter += 1;
  StackPushInteger(nSpellLevel);
  StackPushInteger(nClass);

  VM_ExecuteCommand(629, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyBonusLevelSpell_mutex, "itemPropertyBonusLevelSpell");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyBonusSavingThrow(Ice::Int nBaseSaveType, Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyBonusSavingThrow_mutex, "itemPropertyBonusSavingThrow");
  callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(nBaseSaveType);

  VM_ExecuteCommand(653, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyBonusSavingThrow_mutex, "itemPropertyBonusSavingThrow");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyBonusSavingThrowVsX(Ice::Int nBonusType, Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyBonusSavingThrowVsX_mutex, "itemPropertyBonusSavingThrowVsX");
  callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(nBonusType);

  VM_ExecuteCommand(652, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyBonusSavingThrowVsX_mutex, "itemPropertyBonusSavingThrowVsX");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyBonusSpellResistance(Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyBonusSpellResistance_mutex, "itemPropertyBonusSpellResistance");
  callCounter += 1;
  StackPushInteger(nBonus);

  VM_ExecuteCommand(651, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyBonusSpellResistance_mutex, "itemPropertyBonusSpellResistance");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyCastSpell(Ice::Int nSpell, Ice::Int nNumUses, const Ice::Current& ice) {
  lock(itemPropertyCastSpell_mutex, "itemPropertyCastSpell");
  callCounter += 1;
  StackPushInteger(nNumUses);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(630, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyCastSpell_mutex, "itemPropertyCastSpell");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyContainerReducedWeight(Ice::Int nContainerType, const Ice::Current& ice) {
  lock(itemPropertyContainerReducedWeight_mutex, "itemPropertyContainerReducedWeight");
  callCounter += 1;
  StackPushInteger(nContainerType);

  VM_ExecuteCommand(644, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyContainerReducedWeight_mutex, "itemPropertyContainerReducedWeight");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageBonus(NWN::IPDamageType tIPDamageType, Ice::Int nDamage, const Ice::Current& ice) {
  lock(itemPropertyDamageBonus_mutex, "itemPropertyDamageBonus");
  callCounter += 1;
  StackPushInteger(nDamage);
  StackPushInteger(enum_IPDamageType_2_long(tIPDamageType));
  

  VM_ExecuteCommand(631, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDamageBonus_mutex, "itemPropertyDamageBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageBonusVsAlign(NWN::IPAlignGroup tIPAlignGroup, NWN::IPDamageType tIPDamageType, Ice::Int nDamage, const Ice::Current& ice) {
  lock(itemPropertyDamageBonusVsAlign_mutex, "itemPropertyDamageBonusVsAlign");
  callCounter += 1;
  StackPushInteger(nDamage);
  StackPushInteger(enum_IPDamageType_2_long(tIPDamageType));
  
  StackPushInteger(enum_IPAlignGroup_2_long(tIPAlignGroup));
  

  VM_ExecuteCommand(632, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDamageBonusVsAlign_mutex, "itemPropertyDamageBonusVsAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageBonusVsRace(NWN::IPRacialType tIPRacialType, NWN::IPDamageType tIPDamageType, Ice::Int nDamage, const Ice::Current& ice) {
  lock(itemPropertyDamageBonusVsRace_mutex, "itemPropertyDamageBonusVsRace");
  callCounter += 1;
  StackPushInteger(nDamage);
  StackPushInteger(enum_IPDamageType_2_long(tIPDamageType));
  
  StackPushInteger(enum_IPRacialType_2_long(tIPRacialType));
  

  VM_ExecuteCommand(633, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDamageBonusVsRace_mutex, "itemPropertyDamageBonusVsRace");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageBonusVsSAlign(NWN::Alignment tAlignment, NWN::IPDamageType tIPDamageType, Ice::Int nDamage, const Ice::Current& ice) {
  lock(itemPropertyDamageBonusVsSAlign_mutex, "itemPropertyDamageBonusVsSAlign");
  callCounter += 1;
  StackPushInteger(nDamage);
  StackPushInteger(enum_IPDamageType_2_long(tIPDamageType));
  
  StackPushInteger(enum_Alignment_2_long(tAlignment));
  

  VM_ExecuteCommand(634, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDamageBonusVsSAlign_mutex, "itemPropertyDamageBonusVsSAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageImmunity(NWN::IPDamageType tIPDamageType, Ice::Int nImmuneBonus, const Ice::Current& ice) {
  lock(itemPropertyDamageImmunity_mutex, "itemPropertyDamageImmunity");
  callCounter += 1;
  StackPushInteger(nImmuneBonus);
  StackPushInteger(enum_IPDamageType_2_long(tIPDamageType));
  

  VM_ExecuteCommand(635, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDamageImmunity_mutex, "itemPropertyDamageImmunity");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamagePenalty(Ice::Int nPenalty, const Ice::Current& ice) {
  lock(itemPropertyDamagePenalty_mutex, "itemPropertyDamagePenalty");
  callCounter += 1;
  StackPushInteger(nPenalty);

  VM_ExecuteCommand(636, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDamagePenalty_mutex, "itemPropertyDamagePenalty");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageReduction(Ice::Int nEnhancement, Ice::Int nHPSoak, const Ice::Current& ice) {
  lock(itemPropertyDamageReduction_mutex, "itemPropertyDamageReduction");
  callCounter += 1;
  StackPushInteger(nHPSoak);
  StackPushInteger(nEnhancement);

  VM_ExecuteCommand(637, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDamageReduction_mutex, "itemPropertyDamageReduction");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageResistance(NWN::IPDamageType tIPDamageType, Ice::Int nHPResist, const Ice::Current& ice) {
  lock(itemPropertyDamageResistance_mutex, "itemPropertyDamageResistance");
  callCounter += 1;
  StackPushInteger(nHPResist);
  StackPushInteger(enum_IPDamageType_2_long(tIPDamageType));
  

  VM_ExecuteCommand(638, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDamageResistance_mutex, "itemPropertyDamageResistance");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageVulnerability(NWN::IPDamageType tIPDamageType, Ice::Int nVulnerability, const Ice::Current& ice) {
  lock(itemPropertyDamageVulnerability_mutex, "itemPropertyDamageVulnerability");
  callCounter += 1;
  StackPushInteger(nVulnerability);
  StackPushInteger(enum_IPDamageType_2_long(tIPDamageType));
  

  VM_ExecuteCommand(639, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDamageVulnerability_mutex, "itemPropertyDamageVulnerability");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDarkvision(const Ice::Current& ice) {
  lock(itemPropertyDarkvision_mutex, "itemPropertyDarkvision");
  callCounter += 1;

  VM_ExecuteCommand(640, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDarkvision_mutex, "itemPropertyDarkvision");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDecreaseAC(Ice::Int nModifierType, Ice::Int nPenalty, const Ice::Current& ice) {
  lock(itemPropertyDecreaseAC_mutex, "itemPropertyDecreaseAC");
  callCounter += 1;
  StackPushInteger(nPenalty);
  StackPushInteger(nModifierType);

  VM_ExecuteCommand(642, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDecreaseAC_mutex, "itemPropertyDecreaseAC");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDecreaseAbility(NWN::Ability tAbility, Ice::Int nModifier, const Ice::Current& ice) {
  lock(itemPropertyDecreaseAbility_mutex, "itemPropertyDecreaseAbility");
  callCounter += 1;
  StackPushInteger(nModifier);
  StackPushInteger(enum_Ability_2_long(tAbility));
  

  VM_ExecuteCommand(641, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDecreaseAbility_mutex, "itemPropertyDecreaseAbility");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDecreaseSkill(Ice::Int nSkill, Ice::Int nPenalty, const Ice::Current& ice) {
  lock(itemPropertyDecreaseSkill_mutex, "itemPropertyDecreaseSkill");
  callCounter += 1;
  StackPushInteger(nPenalty);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(643, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyDecreaseSkill_mutex, "itemPropertyDecreaseSkill");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyEnhancementBonus(Ice::Int nEnhancementBonus, const Ice::Current& ice) {
  lock(itemPropertyEnhancementBonus_mutex, "itemPropertyEnhancementBonus");
  callCounter += 1;
  StackPushInteger(nEnhancementBonus);

  VM_ExecuteCommand(622, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyEnhancementBonus_mutex, "itemPropertyEnhancementBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyEnhancementBonusVsAlign(NWN::IPAlignGroup tIPAlignGroup, Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyEnhancementBonusVsAlign_mutex, "itemPropertyEnhancementBonusVsAlign");
  callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(enum_IPAlignGroup_2_long(tIPAlignGroup));
  

  VM_ExecuteCommand(623, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyEnhancementBonusVsAlign_mutex, "itemPropertyEnhancementBonusVsAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyEnhancementBonusVsRace(NWN::IPRacialType tIPRacialType, Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyEnhancementBonusVsRace_mutex, "itemPropertyEnhancementBonusVsRace");
  callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(enum_IPRacialType_2_long(tIPRacialType));
  

  VM_ExecuteCommand(624, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyEnhancementBonusVsRace_mutex, "itemPropertyEnhancementBonusVsRace");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyEnhancementBonusVsSAlign(NWN::Alignment tAlignment, Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertyEnhancementBonusVsSAlign_mutex, "itemPropertyEnhancementBonusVsSAlign");
  callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(enum_Alignment_2_long(tAlignment));
  

  VM_ExecuteCommand(625, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyEnhancementBonusVsSAlign_mutex, "itemPropertyEnhancementBonusVsSAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyEnhancementPenalty(Ice::Int nPenalty, const Ice::Current& ice) {
  lock(itemPropertyEnhancementPenalty_mutex, "itemPropertyEnhancementPenalty");
  callCounter += 1;
  StackPushInteger(nPenalty);

  VM_ExecuteCommand(626, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyEnhancementPenalty_mutex, "itemPropertyEnhancementPenalty");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyExtraMeleeDamageType(NWN::IPDamageType tIPDamageType, const Ice::Current& ice) {
  lock(itemPropertyExtraMeleeDamageType_mutex, "itemPropertyExtraMeleeDamageType");
  callCounter += 1;
  StackPushInteger(enum_IPDamageType_2_long(tIPDamageType));
  

  VM_ExecuteCommand(645, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyExtraMeleeDamageType_mutex, "itemPropertyExtraMeleeDamageType");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyExtraRangeDamageType(NWN::IPDamageType tIPDamageType, const Ice::Current& ice) {
  lock(itemPropertyExtraRangeDamageType_mutex, "itemPropertyExtraRangeDamageType");
  callCounter += 1;
  StackPushInteger(enum_IPDamageType_2_long(tIPDamageType));
  

  VM_ExecuteCommand(646, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyExtraRangeDamageType_mutex, "itemPropertyExtraRangeDamageType");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyFreeAction(const Ice::Current& ice) {
  lock(itemPropertyFreeAction_mutex, "itemPropertyFreeAction");
  callCounter += 1;

  VM_ExecuteCommand(683, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyFreeAction_mutex, "itemPropertyFreeAction");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyHaste(const Ice::Current& ice) {
  lock(itemPropertyHaste_mutex, "itemPropertyHaste");
  callCounter += 1;

  VM_ExecuteCommand(647, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyHaste_mutex, "itemPropertyHaste");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyHealersKit(Ice::Int nModifier, const Ice::Current& ice) {
  lock(itemPropertyHealersKit_mutex, "itemPropertyHealersKit");
  callCounter += 1;
  StackPushInteger(nModifier);

  VM_ExecuteCommand(687, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyHealersKit_mutex, "itemPropertyHealersKit");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyHolyAvenger(const Ice::Current& ice) {
  lock(itemPropertyHolyAvenger_mutex, "itemPropertyHolyAvenger");
  callCounter += 1;

  VM_ExecuteCommand(648, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyHolyAvenger_mutex, "itemPropertyHolyAvenger");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyImmunityMisc(NWN::IPMiscImmunityType tIPMiscImmunityType, const Ice::Current& ice) {
  lock(itemPropertyImmunityMisc_mutex, "itemPropertyImmunityMisc");
  callCounter += 1;
  StackPushInteger(enum_IPMiscImmunityType_2_long(tIPMiscImmunityType));
  

  VM_ExecuteCommand(649, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyImmunityMisc_mutex, "itemPropertyImmunityMisc");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyImmunityToSpellLevel(Ice::Int nLevel, const Ice::Current& ice) {
  lock(itemPropertyImmunityToSpellLevel_mutex, "itemPropertyImmunityToSpellLevel");
  callCounter += 1;
  StackPushInteger(nLevel);

  VM_ExecuteCommand(685, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyImmunityToSpellLevel_mutex, "itemPropertyImmunityToSpellLevel");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyImprovedEvasion(const Ice::Current& ice) {
  lock(itemPropertyImprovedEvasion_mutex, "itemPropertyImprovedEvasion");
  callCounter += 1;

  VM_ExecuteCommand(650, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyImprovedEvasion_mutex, "itemPropertyImprovedEvasion");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyKeen(const Ice::Current& ice) {
  lock(itemPropertyKeen_mutex, "itemPropertyKeen");
  callCounter += 1;

  VM_ExecuteCommand(654, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyKeen_mutex, "itemPropertyKeen");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyLight(Ice::Int nBrightness, Ice::Int nColor, const Ice::Current& ice) {
  lock(itemPropertyLight_mutex, "itemPropertyLight");
  callCounter += 1;
  StackPushInteger(nColor);
  StackPushInteger(nBrightness);

  VM_ExecuteCommand(655, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyLight_mutex, "itemPropertyLight");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyLimitUseByAlign(NWN::IPAlignGroup tIPAlignGroup, const Ice::Current& ice) {
  lock(itemPropertyLimitUseByAlign_mutex, "itemPropertyLimitUseByAlign");
  callCounter += 1;
  StackPushInteger(enum_IPAlignGroup_2_long(tIPAlignGroup));
  

  VM_ExecuteCommand(672, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyLimitUseByAlign_mutex, "itemPropertyLimitUseByAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyLimitUseByClass(Ice::Int nClass, const Ice::Current& ice) {
  lock(itemPropertyLimitUseByClass_mutex, "itemPropertyLimitUseByClass");
  callCounter += 1;
  StackPushInteger(nClass);

  VM_ExecuteCommand(673, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyLimitUseByClass_mutex, "itemPropertyLimitUseByClass");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyLimitUseByRace(NWN::IPRacialType tIPRacialType, const Ice::Current& ice) {
  lock(itemPropertyLimitUseByRace_mutex, "itemPropertyLimitUseByRace");
  callCounter += 1;
  StackPushInteger(enum_IPRacialType_2_long(tIPRacialType));
  

  VM_ExecuteCommand(674, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyLimitUseByRace_mutex, "itemPropertyLimitUseByRace");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyLimitUseBySAlign(NWN::Alignment tAlignment, const Ice::Current& ice) {
  lock(itemPropertyLimitUseBySAlign_mutex, "itemPropertyLimitUseBySAlign");
  callCounter += 1;
  StackPushInteger(enum_Alignment_2_long(tAlignment));
  

  VM_ExecuteCommand(675, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyLimitUseBySAlign_mutex, "itemPropertyLimitUseBySAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyMassiveCritical(Ice::Int nDamage, const Ice::Current& ice) {
  lock(itemPropertyMassiveCritical_mutex, "itemPropertyMassiveCritical");
  callCounter += 1;
  StackPushInteger(nDamage);

  VM_ExecuteCommand(682, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyMassiveCritical_mutex, "itemPropertyMassiveCritical");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyMaterial(Ice::Int nMaterialType, const Ice::Current& ice) {
  lock(itemPropertyMaterial_mutex, "itemPropertyMaterial");
  callCounter += 1;
  StackPushInteger(nMaterialType);

  VM_ExecuteCommand(845, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyMaterial_mutex, "itemPropertyMaterial");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyMaxRangeStrengthMod(Ice::Int nModifier, const Ice::Current& ice) {
  lock(itemPropertyMaxRangeStrengthMod_mutex, "itemPropertyMaxRangeStrengthMod");
  callCounter += 1;
  StackPushInteger(nModifier);

  VM_ExecuteCommand(656, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyMaxRangeStrengthMod_mutex, "itemPropertyMaxRangeStrengthMod");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyMonsterDamage(Ice::Int nDamage, const Ice::Current& ice) {
  lock(itemPropertyMonsterDamage_mutex, "itemPropertyMonsterDamage");
  callCounter += 1;
  StackPushInteger(nDamage);

  VM_ExecuteCommand(684, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyMonsterDamage_mutex, "itemPropertyMonsterDamage");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyNoDamage(const Ice::Current& ice) {
  lock(itemPropertyNoDamage_mutex, "itemPropertyNoDamage");
  callCounter += 1;

  VM_ExecuteCommand(657, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyNoDamage_mutex, "itemPropertyNoDamage");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyOnHitCastSpell(Ice::Int nSpell, Ice::Int nLevel, const Ice::Current& ice) {
  lock(itemPropertyOnHitCastSpell_mutex, "itemPropertyOnHitCastSpell");
  callCounter += 1;
  StackPushInteger(nLevel);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(733, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyOnHitCastSpell_mutex, "itemPropertyOnHitCastSpell");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyOnHitProps(Ice::Int nProperty, Ice::Int nSaveDC, Ice::Int nSpecial, const Ice::Current& ice) {
  lock(itemPropertyOnHitProps_mutex, "itemPropertyOnHitProps");
  callCounter += 1;
  StackPushInteger(nSpecial);
  StackPushInteger(nSaveDC);
  StackPushInteger(nProperty);

  VM_ExecuteCommand(658, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyOnHitProps_mutex, "itemPropertyOnHitProps");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyOnMonsterHitProperties(Ice::Int nProperty, Ice::Int nSpecial, const Ice::Current& ice) {
  lock(itemPropertyOnMonsterHitProperties_mutex, "itemPropertyOnMonsterHitProperties");
  callCounter += 1;
  StackPushInteger(nSpecial);
  StackPushInteger(nProperty);

  VM_ExecuteCommand(680, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyOnMonsterHitProperties_mutex, "itemPropertyOnMonsterHitProperties");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyQuality(Ice::Int nQuality, const Ice::Current& ice) {
  lock(itemPropertyQuality_mutex, "itemPropertyQuality");
  callCounter += 1;
  StackPushInteger(nQuality);

  VM_ExecuteCommand(846, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyQuality_mutex, "itemPropertyQuality");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyReducedSavingThrow(Ice::Int nBonusType, Ice::Int nPenalty, const Ice::Current& ice) {
  lock(itemPropertyReducedSavingThrow_mutex, "itemPropertyReducedSavingThrow");
  callCounter += 1;
  StackPushInteger(nPenalty);
  StackPushInteger(nBonusType);

  VM_ExecuteCommand(660, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyReducedSavingThrow_mutex, "itemPropertyReducedSavingThrow");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyReducedSavingThrowVsX(Ice::Int nBaseSaveType, Ice::Int nPenalty, const Ice::Current& ice) {
  lock(itemPropertyReducedSavingThrowVsX_mutex, "itemPropertyReducedSavingThrowVsX");
  callCounter += 1;
  StackPushInteger(nPenalty);
  StackPushInteger(nBaseSaveType);

  VM_ExecuteCommand(659, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyReducedSavingThrowVsX_mutex, "itemPropertyReducedSavingThrowVsX");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyRegeneration(Ice::Int nRegenAmount, const Ice::Current& ice) {
  lock(itemPropertyRegeneration_mutex, "itemPropertyRegeneration");
  callCounter += 1;
  StackPushInteger(nRegenAmount);

  VM_ExecuteCommand(661, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyRegeneration_mutex, "itemPropertyRegeneration");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertySkillBonus(Ice::Int nSkill, Ice::Int nBonus, const Ice::Current& ice) {
  lock(itemPropertySkillBonus_mutex, "itemPropertySkillBonus");
  callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(662, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertySkillBonus_mutex, "itemPropertySkillBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertySpecialWalk(Ice::Int nWalkType, const Ice::Current& ice) {
  lock(itemPropertySpecialWalk_mutex, "itemPropertySpecialWalk");
  callCounter += 1;
  StackPushInteger(nWalkType);

  VM_ExecuteCommand(686, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertySpecialWalk_mutex, "itemPropertySpecialWalk");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertySpellImmunitySchool(NWN::IPSpellSchool tIPSpellSchool, const Ice::Current& ice) {
  lock(itemPropertySpellImmunitySchool_mutex, "itemPropertySpellImmunitySchool");
  callCounter += 1;
  StackPushInteger(enum_IPSpellSchool_2_long(tIPSpellSchool));
  

  VM_ExecuteCommand(664, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertySpellImmunitySchool_mutex, "itemPropertySpellImmunitySchool");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertySpellImmunitySpecific(Ice::Int nSpell, const Ice::Current& ice) {
  lock(itemPropertySpellImmunitySpecific_mutex, "itemPropertySpellImmunitySpecific");
  callCounter += 1;
  StackPushInteger(nSpell);

  VM_ExecuteCommand(663, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertySpellImmunitySpecific_mutex, "itemPropertySpellImmunitySpecific");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyThievesTools(Ice::Int nModifier, const Ice::Current& ice) {
  lock(itemPropertyThievesTools_mutex, "itemPropertyThievesTools");
  callCounter += 1;
  StackPushInteger(nModifier);

  VM_ExecuteCommand(665, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyThievesTools_mutex, "itemPropertyThievesTools");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyTrap(Ice::Int nTrapLevel, NWN::IPTrapType tIPTrapType, const Ice::Current& ice) {
  lock(itemPropertyTrap_mutex, "itemPropertyTrap");
  callCounter += 1;
  StackPushInteger(enum_IPTrapType_2_long(tIPTrapType));
  
  StackPushInteger(nTrapLevel);

  VM_ExecuteCommand(678, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyTrap_mutex, "itemPropertyTrap");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyTrueSeeing(const Ice::Current& ice) {
  lock(itemPropertyTrueSeeing_mutex, "itemPropertyTrueSeeing");
  callCounter += 1;

  VM_ExecuteCommand(679, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyTrueSeeing_mutex, "itemPropertyTrueSeeing");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyTurnResistance(Ice::Int nModifier, const Ice::Current& ice) {
  lock(itemPropertyTurnResistance_mutex, "itemPropertyTurnResistance");
  callCounter += 1;
  StackPushInteger(nModifier);

  VM_ExecuteCommand(681, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyTurnResistance_mutex, "itemPropertyTurnResistance");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyUnlimitedAmmo(Ice::Int nAmmoDamage, const Ice::Current& ice) {
  lock(itemPropertyUnlimitedAmmo_mutex, "itemPropertyUnlimitedAmmo");
  callCounter += 1;
  StackPushInteger(nAmmoDamage);

  VM_ExecuteCommand(671, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyUnlimitedAmmo_mutex, "itemPropertyUnlimitedAmmo");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyVampiricRegeneration(Ice::Int nRegenAmount, const Ice::Current& ice) {
  lock(itemPropertyVampiricRegeneration_mutex, "itemPropertyVampiricRegeneration");
  callCounter += 1;
  StackPushInteger(nRegenAmount);

  VM_ExecuteCommand(677, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyVampiricRegeneration_mutex, "itemPropertyVampiricRegeneration");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyVisualEffect(Ice::Int nEffect, const Ice::Current& ice) {
  lock(itemPropertyVisualEffect_mutex, "itemPropertyVisualEffect");
  callCounter += 1;
  StackPushInteger(nEffect);

  VM_ExecuteCommand(739, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyVisualEffect_mutex, "itemPropertyVisualEffect");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyWeightIncrease(Ice::Int nWeight, const Ice::Current& ice) {
  lock(itemPropertyWeightIncrease_mutex, "itemPropertyWeightIncrease");
  callCounter += 1;
  StackPushInteger(nWeight);

  VM_ExecuteCommand(688, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyWeightIncrease_mutex, "itemPropertyWeightIncrease");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyWeightReduction(Ice::Int nReduction, const Ice::Current& ice) {
  lock(itemPropertyWeightReduction_mutex, "itemPropertyWeightReduction");
  callCounter += 1;
  StackPushInteger(nReduction);

  VM_ExecuteCommand(627, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  e.tDurationType = getItemPropertyDurationType(e, ice);
  e.tType = getItemPropertyType(e, ice);
  e.tSubType = getItemPropertySubType(e, ice);
  e.tParam1 = getItemPropertyParam1(e, ice);
  e.tParam1Value = getItemPropertyParam1Value(e, ice);
  e.tCostTable = getItemPropertyCostTable(e, ice);
  e.tCostTableValue = getItemPropertyCostTableValue(e, ice);
  NWN::NWObject oCreator; oCreator.id = pRetVal->CreatorId; e.tCreator = oCreator;
  unlock(itemPropertyWeightReduction_mutex, "itemPropertyWeightReduction");
  return e;
};

void NWScriptI::jumpToLocation(const NWN::NWLocation& lDestination, const Ice::Current& ice) {
  if (lDestination.area.id < 0) throw NWN::InvalidObjectException();
  lock(jumpToLocation_mutex, "jumpToLocation");
  callCounter += 1;
  
  StackPushFloat(lDestination.facing);
  Vector lDestination_vv;
  lDestination_vv.X = lDestination.x; lDestination_vv.Y = lDestination.y; lDestination_vv.Z = lDestination.z;
  StackPushVector(lDestination_vv);
  StackPushObject(lDestination.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(313, 1);

unlock(jumpToLocation_mutex, "jumpToLocation");
  
};

void NWScriptI::jumpToObject(const NWN::NWObject& oToJumpTo, bool bWalkStraightLineToPoint, const Ice::Current& ice) {
  if (oToJumpTo.id < 0 || oToJumpTo.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(jumpToObject_mutex, "jumpToObject");
  callCounter += 1;
  StackPushInteger(bWalkStraightLineToPoint == true ? 1 : 0);
  StackPushObject(oToJumpTo.id);

  VM_ExecuteCommand(385, 2);

unlock(jumpToObject_mutex, "jumpToObject");
  
};

Ice::Int NWScriptI::levelUpHenchman(const NWN::NWObject& oCreature, Ice::Int nClass, bool bReadyAllSpells, Ice::Int nPackage, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(levelUpHenchman_mutex, "levelUpHenchman");
  callCounter += 1;
  StackPushInteger(nPackage);
  StackPushInteger(bReadyAllSpells == true ? 1 : 0);
  StackPushInteger(nClass);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(704, 4);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(levelUpHenchman_mutex, "levelUpHenchman");
  return nRetVal;
};

Ice::Int NWScriptI::lineOfSightObject(const NWN::NWObject& oSource, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(lineOfSightObject_mutex, "lineOfSightObject");
  callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oSource.id);

  VM_ExecuteCommand(752, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(lineOfSightObject_mutex, "lineOfSightObject");
  return nRetVal;
};

Ice::Int NWScriptI::lineOfSightVector(const NWN::NWVector& vSource, const NWN::NWVector& vTarget, const Ice::Current& ice) {
  lock(lineOfSightVector_mutex, "lineOfSightVector");
  callCounter += 1;
  Vector vvTarget;
  vvTarget.X = vTarget.x; vvTarget.Y = vTarget.y; vvTarget.Z = vTarget.z;
  StackPushVector(vvTarget);
  Vector vvSource;
  vvSource.X = vSource.x; vvSource.Y = vSource.y; vvSource.Z = vSource.z;
  StackPushVector(vvSource);

  VM_ExecuteCommand(753, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(lineOfSightVector_mutex, "lineOfSightVector");
  return nRetVal;
};

NWN::NWLocation NWScriptI::location(const NWN::NWObject& oArea, const NWN::NWVector& vPosition, Ice::Float fOrientation, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(location_mutex, "location");
  callCounter += 1;
  StackPushFloat(fOrientation);
  Vector vvPosition;
  vvPosition.X = vPosition.x; vvPosition.Y = vPosition.y; vvPosition.Z = vPosition.z;
  StackPushVector(vvPosition);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(215, 3);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.area.id = pRetVal->AreaID;
  nl.x = pRetVal->X;
  nl.y = pRetVal->Y;
  nl.z = pRetVal->Z;
  nl.facing = atan(pRetVal->OrientationY / pRetVal->OrientationX) * (180 / 3.1415927);
  nl.facing += 180;
  while (nl.facing > 360.0) nl.facing -= 360.0; while (nl.facing < 0.0) nl.facing += 360.0;
  unlock(location_mutex, "location");
  return nl;
};

void NWScriptI::lockCameraDirection(const NWN::NWObject& oPlayer, bool bLocked, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(lockCameraDirection_mutex, "lockCameraDirection");
  callCounter += 1;
  StackPushInteger(bLocked == true ? 1 : 0);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(825, 2);

unlock(lockCameraDirection_mutex, "lockCameraDirection");
  
};

void NWScriptI::lockCameraDistance(const NWN::NWObject& oPlayer, bool bLocked, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(lockCameraDistance_mutex, "lockCameraDistance");
  callCounter += 1;
  StackPushInteger(bLocked == true ? 1 : 0);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(824, 2);

unlock(lockCameraDistance_mutex, "lockCameraDistance");
  
};

void NWScriptI::lockCameraPitch(const NWN::NWObject& oPlayer, bool bLocked, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(lockCameraPitch_mutex, "lockCameraPitch");
  callCounter += 1;
  StackPushInteger(bLocked == true ? 1 : 0);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(823, 2);

unlock(lockCameraPitch_mutex, "lockCameraPitch");
  
};

Ice::Float NWScriptI::log(Ice::Float fValue, const Ice::Current& ice) {
  lock(log_mutex, "log");
  callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(74, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(log_mutex, "log");
  return fRetVal;
};

NWN::NWEffect NWScriptI::magicalEffect(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(magicalEffect_mutex, "magicalEffect");
  callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(112, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(magicalEffect_mutex, "magicalEffect");
  return e;
};

void NWScriptI::musicBackgroundChangeDay(const NWN::NWObject& oArea, Ice::Int nTrack, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(musicBackgroundChangeDay_mutex, "musicBackgroundChangeDay");
  callCounter += 1;
  StackPushInteger(nTrack);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(428, 2);

unlock(musicBackgroundChangeDay_mutex, "musicBackgroundChangeDay");
  
};

void NWScriptI::musicBackgroundChangeNight(const NWN::NWObject& oArea, Ice::Int nTrack, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(musicBackgroundChangeNight_mutex, "musicBackgroundChangeNight");
  callCounter += 1;
  StackPushInteger(nTrack);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(429, 2);

unlock(musicBackgroundChangeNight_mutex, "musicBackgroundChangeNight");
  
};

Ice::Int NWScriptI::musicBackgroundGetBattleTrack(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(musicBackgroundGetBattleTrack_mutex, "musicBackgroundGetBattleTrack");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(569, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(musicBackgroundGetBattleTrack_mutex, "musicBackgroundGetBattleTrack");
  return nRetVal;
};

Ice::Int NWScriptI::musicBackgroundGetDayTrack(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(musicBackgroundGetDayTrack_mutex, "musicBackgroundGetDayTrack");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(558, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(musicBackgroundGetDayTrack_mutex, "musicBackgroundGetDayTrack");
  return nRetVal;
};

Ice::Int NWScriptI::musicBackgroundGetNightTrack(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(musicBackgroundGetNightTrack_mutex, "musicBackgroundGetNightTrack");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(559, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(musicBackgroundGetNightTrack_mutex, "musicBackgroundGetNightTrack");
  return nRetVal;
};

void NWScriptI::musicBackgroundPlay(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(musicBackgroundPlay_mutex, "musicBackgroundPlay");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(425, 1);

unlock(musicBackgroundPlay_mutex, "musicBackgroundPlay");
  
};

void NWScriptI::musicBackgroundSetDelay(const NWN::NWObject& oArea, Ice::Int nDelay, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(musicBackgroundSetDelay_mutex, "musicBackgroundSetDelay");
  callCounter += 1;
  StackPushInteger(nDelay);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(427, 2);

unlock(musicBackgroundSetDelay_mutex, "musicBackgroundSetDelay");
  
};

void NWScriptI::musicBackgroundStop(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(musicBackgroundStop_mutex, "musicBackgroundStop");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(426, 1);

unlock(musicBackgroundStop_mutex, "musicBackgroundStop");
  
};

void NWScriptI::musicBattleChange(const NWN::NWObject& oArea, Ice::Int nTrack, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(musicBattleChange_mutex, "musicBattleChange");
  callCounter += 1;
  StackPushInteger(nTrack);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(432, 2);

unlock(musicBattleChange_mutex, "musicBattleChange");
  
};

void NWScriptI::musicBattlePlay(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(musicBattlePlay_mutex, "musicBattlePlay");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(430, 1);

unlock(musicBattlePlay_mutex, "musicBattlePlay");
  
};

void NWScriptI::musicBattleStop(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(musicBattleStop_mutex, "musicBattleStop");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(431, 1);

unlock(musicBattleStop_mutex, "musicBattleStop");
  
};

void NWScriptI::nightToDay(const NWN::NWObject& oPlayer, Ice::Float fTransitionTime, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(nightToDay_mutex, "nightToDay");
  callCounter += 1;
  StackPushFloat(fTransitionTime);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(751, 2);

unlock(nightToDay_mutex, "nightToDay");
  
};

std::string NWScriptI::objectToString(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(objectToString_mutex, "objectToString");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(272, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(objectToString_mutex, "objectToString");
  return std::string(sRetVal);
};

void NWScriptI::openInventory(const NWN::NWObject& oCreature, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(openInventory_mutex, "openInventory");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(701, 2);

unlock(openInventory_mutex, "openInventory");
  
};

void NWScriptI::openStore(const NWN::NWObject& oStore, const NWN::NWObject& oPC, Ice::Int nBonusMarkUp, Ice::Int nBonusMarkDown, const Ice::Current& ice) {
  if (oStore.id < 0 || oStore.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oPC.id < 0 || oPC.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(openStore_mutex, "openStore");
  callCounter += 1;
  StackPushInteger(nBonusMarkDown);
  StackPushInteger(nBonusMarkUp);
  StackPushObject(oPC.id);
  StackPushObject(oStore.id);

  VM_ExecuteCommand(378, 4);

unlock(openStore_mutex, "openStore");
  
};

void NWScriptI::playAnimation(Ice::Int nAnimation, Ice::Float fSpeed, Ice::Float fSeconds, const Ice::Current& ice) {
  lock(playAnimation_mutex, "playAnimation");
  callCounter += 1;
  StackPushFloat(fSeconds);
  StackPushFloat(fSpeed);
  StackPushInteger(nAnimation);

  VM_ExecuteCommand(300, 3);

unlock(playAnimation_mutex, "playAnimation");
  
};

void NWScriptI::playSound(const std::string& sSoundName, const Ice::Current& ice) {
  lock(playSound_mutex, "playSound");
  callCounter += 1;
  StackPushString(sSoundName.c_str());

  VM_ExecuteCommand(46, 1);

unlock(playSound_mutex, "playSound");
  
};

void NWScriptI::playSoundByStrRef(Ice::Int nStrRef, Ice::Int nRunAsAction, const Ice::Current& ice) {
  lock(playSoundByStrRef_mutex, "playSoundByStrRef");
  callCounter += 1;
  StackPushInteger(nRunAsAction);
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(720, 2);

unlock(playSoundByStrRef_mutex, "playSoundByStrRef");
  
};

void NWScriptI::playVoiceChat(Ice::Int nVoiceChatID, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(playVoiceChat_mutex, "playVoiceChat");
  callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushInteger(nVoiceChatID);

  VM_ExecuteCommand(421, 2);

unlock(playVoiceChat_mutex, "playVoiceChat");
  
};

void NWScriptI::popUpDeathGUIPanel(const NWN::NWObject& oPC, bool bRespawnButtonEnabled, bool bWaitForHelpButtonEnabled, Ice::Int nHelpStringReference, const std::string& sHelpString, const Ice::Current& ice) {
  if (oPC.id < 0 || oPC.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(popUpDeathGUIPanel_mutex, "popUpDeathGUIPanel");
  callCounter += 1;
  StackPushString(sHelpString.c_str());
  StackPushInteger(nHelpStringReference);
  StackPushInteger(bWaitForHelpButtonEnabled == true ? 1 : 0);
  StackPushInteger(bRespawnButtonEnabled == true ? 1 : 0);
  StackPushObject(oPC.id);

  VM_ExecuteCommand(554, 5);

unlock(popUpDeathGUIPanel_mutex, "popUpDeathGUIPanel");
  
};

void NWScriptI::popUpGUIPanel(const NWN::NWObject& oPC, Ice::Int nGUIPanel, const Ice::Current& ice) {
  if (oPC.id < 0 || oPC.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(popUpGUIPanel_mutex, "popUpGUIPanel");
  callCounter += 1;
  StackPushInteger(nGUIPanel);
  StackPushObject(oPC.id);

  VM_ExecuteCommand(388, 2);

unlock(popUpGUIPanel_mutex, "popUpGUIPanel");
  
};

Ice::Float NWScriptI::pow(Ice::Float fValue, Ice::Float fExponent, const Ice::Current& ice) {
  lock(pow_mutex, "pow");
  callCounter += 1;
  StackPushFloat(fExponent);
  StackPushFloat(fValue);

  VM_ExecuteCommand(75, 2);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(pow_mutex, "pow");
  return fRetVal;
};

void NWScriptI::printFloat(Ice::Float fFloat, Ice::Int nWidth, Ice::Int nDecimals, const Ice::Current& ice) {
  lock(printFloat_mutex, "printFloat");
  callCounter += 1;
  StackPushInteger(nDecimals);
  StackPushInteger(nWidth);
  StackPushFloat(fFloat);

  VM_ExecuteCommand(2, 3);

unlock(printFloat_mutex, "printFloat");
  
};

void NWScriptI::printInteger(Ice::Int nInteger, const Ice::Current& ice) {
  lock(printInteger_mutex, "printInteger");
  callCounter += 1;
  StackPushInteger(nInteger);

  VM_ExecuteCommand(4, 1);

unlock(printInteger_mutex, "printInteger");
  
};

void NWScriptI::printObject(const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(printObject_mutex, "printObject");
  callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(5, 1);

unlock(printObject_mutex, "printObject");
  
};

void NWScriptI::printString(const std::string& sString, const Ice::Current& ice) {
  lock(printString_mutex, "printString");
  callCounter += 1;
  StackPushString(sString.c_str());

  VM_ExecuteCommand(1, 1);

unlock(printString_mutex, "printString");
  
};

void NWScriptI::printVector(const NWN::NWVector& vVector, bool bPrepend, const Ice::Current& ice) {
  lock(printVector_mutex, "printVector");
  callCounter += 1;
  StackPushInteger(bPrepend == true ? 1 : 0);
  Vector vvVector;
  vvVector.X = vVector.x; vvVector.Y = vVector.y; vvVector.Z = vVector.z;
  StackPushVector(vvVector);

  VM_ExecuteCommand(141, 2);

unlock(printVector_mutex, "printVector");
  
};

Ice::Int NWScriptI::random(Ice::Int nMaxInteger, const Ice::Current& ice) {
  lock(random_mutex, "random");
  callCounter += 1;
  StackPushInteger(nMaxInteger);

  VM_ExecuteCommand(0, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(random_mutex, "random");
  return nRetVal;
};

std::string NWScriptI::randomName(Ice::Int nNameType, const Ice::Current& ice) {
  lock(randomName_mutex, "randomName");
  callCounter += 1;
  StackPushInteger(nNameType);

  VM_ExecuteCommand(249, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock(randomName_mutex, "randomName");
  return std::string(sRetVal);
};

void NWScriptI::recomputeStaticLighting(const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(recomputeStaticLighting_mutex, "recomputeStaticLighting");
  callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(516, 1);

unlock(recomputeStaticLighting_mutex, "recomputeStaticLighting");
  
};

NWN::SavingThrowResult NWScriptI::reflexSave(const NWN::NWObject& oCreature, Ice::Int nDC, NWN::SaveType tSaveType, const NWN::NWObject& oSaveVersus, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSaveVersus.id < 0 || oSaveVersus.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(reflexSave_mutex, "reflexSave");
  callCounter += 1;
  StackPushObject(oSaveVersus.id);
  StackPushInteger(enum_SaveType_2_long(tSaveType));
  
  StackPushInteger(nDC);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(109, 4);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(reflexSave_mutex, "reflexSave");
    return enum_long_2_SavingThrowResult(nRetVal);
  
};

void NWScriptI::removeEffect(const NWN::NWObject& oCreature, const NWN::NWEffect& eEffect, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(removeEffect_mutex, "removeEffect");
  callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(87, 2);

unlock(removeEffect_mutex, "removeEffect");
  
};

void NWScriptI::removeFromParty(const NWN::NWObject& oPC, const Ice::Current& ice) {
  if (oPC.id < 0 || oPC.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(removeFromParty_mutex, "removeFromParty");
  callCounter += 1;
  StackPushObject(oPC.id);

  VM_ExecuteCommand(573, 1);

unlock(removeFromParty_mutex, "removeFromParty");
  
};

void NWScriptI::removeHenchman(const NWN::NWObject& oMaster, const NWN::NWObject& oHenchman, const Ice::Current& ice) {
  if (oMaster.id < 0 || oMaster.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oHenchman.id < 0 || oHenchman.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(removeHenchman_mutex, "removeHenchman");
  callCounter += 1;
  StackPushObject(oHenchman.id);
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(366, 2);

unlock(removeHenchman_mutex, "removeHenchman");
  
};

void NWScriptI::removeItemProperty(const NWN::NWObject& oItem, const NWN::NWItemProperty& ipProperty, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (iprpMap.find(ipProperty.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock(removeItemProperty_mutex, "removeItemProperty");
  callCounter += 1;
  CGameEffect *ipProperty_ptr = iprpMap.find(ipProperty.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_ITEMPROPERTY, ipProperty_ptr);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(610, 2);

unlock(removeItemProperty_mutex, "removeItemProperty");
  
};

void NWScriptI::removeJournalQuestEntry(const std::string& szPlotID, const NWN::NWObject& oCreature, bool bAllPartyMembers, bool bAllPlayers, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(removeJournalQuestEntry_mutex, "removeJournalQuestEntry");
  callCounter += 1;
  StackPushInteger(bAllPlayers == true ? 1 : 0);
  StackPushInteger(bAllPartyMembers == true ? 1 : 0);
  StackPushObject(oCreature.id);
  StackPushString(szPlotID.c_str());

  VM_ExecuteCommand(368, 4);

unlock(removeJournalQuestEntry_mutex, "removeJournalQuestEntry");
  
};

void NWScriptI::removeSummonedAssociate(const NWN::NWObject& oMaster, const NWN::NWObject& oAssociate, const Ice::Current& ice) {
  if (oMaster.id < 0 || oMaster.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oAssociate.id < 0 || oAssociate.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(removeSummonedAssociate_mutex, "removeSummonedAssociate");
  callCounter += 1;
  StackPushObject(oAssociate.id);
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(503, 2);

unlock(removeSummonedAssociate_mutex, "removeSummonedAssociate");
  
};

Ice::Int NWScriptI::resistSpell(const NWN::NWObject& oCaster, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oCaster.id < 0 || oCaster.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(resistSpell_mutex, "resistSpell");
  callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oCaster.id);

  VM_ExecuteCommand(169, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(resistSpell_mutex, "resistSpell");
  return nRetVal;
};

void NWScriptI::restoreBaseAttackBonus(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(restoreBaseAttackBonus_mutex, "restoreBaseAttackBonus");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(756, 1);

unlock(restoreBaseAttackBonus_mutex, "restoreBaseAttackBonus");
  
};

void NWScriptI::restoreCameraFacing(const Ice::Current& ice) {
  lock(restoreCameraFacing_mutex, "restoreCameraFacing");
  callCounter += 1;

  VM_ExecuteCommand(703, 0);

unlock(restoreCameraFacing_mutex, "restoreCameraFacing");
  
};

NWN::NWObject NWScriptI::retrieveCampaignObject(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWLocation& locLocation, const NWN::NWObject& oOwner, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (locLocation.area.id < 0) throw NWN::InvalidObjectException();
  if (oOwner.id < 0 || oOwner.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(retrieveCampaignObject_mutex, "retrieveCampaignObject");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushObject(oOwner.id);
  
  StackPushFloat(locLocation.facing);
  Vector locLocation_vv;
  locLocation_vv.X = locLocation.x; locLocation_vv.Y = locLocation.y; locLocation_vv.Z = locLocation.z;
  StackPushVector(locLocation_vv);
  StackPushObject(locLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(603, 5);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock(retrieveCampaignObject_mutex, "retrieveCampaignObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Float NWScriptI::roundsToSeconds(Ice::Int nRounds, const Ice::Current& ice) {
  lock(roundsToSeconds_mutex, "roundsToSeconds");
  callCounter += 1;
  StackPushInteger(nRounds);

  VM_ExecuteCommand(121, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(roundsToSeconds_mutex, "roundsToSeconds");
  return fRetVal;
};

void NWScriptI::sendMessageToAllDMs(const std::string& szMessage, const Ice::Current& ice) {
  lock(sendMessageToAllDMs_mutex, "sendMessageToAllDMs");
  callCounter += 1;
  StackPushString(szMessage.c_str());

  VM_ExecuteCommand(563, 1);

unlock(sendMessageToAllDMs_mutex, "sendMessageToAllDMs");
  
};

void NWScriptI::sendMessageToPC(const NWN::NWObject& oPlayer, const std::string& szMessage, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(sendMessageToPC_mutex, "sendMessageToPC");
  callCounter += 1;
  StackPushString(szMessage.c_str());
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(374, 2);

unlock(sendMessageToPC_mutex, "sendMessageToPC");
  
};

void NWScriptI::sendMessageToPCByStrRef(const NWN::NWObject& oPlayer, Ice::Int nStrRef, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(sendMessageToPCByStrRef_mutex, "sendMessageToPCByStrRef");
  callCounter += 1;
  StackPushInteger(nStrRef);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(717, 2);

unlock(sendMessageToPCByStrRef_mutex, "sendMessageToPCByStrRef");
  
};

void NWScriptI::setAILevel(const NWN::NWObject& oTarget, NWN::AILevel tAILevel, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setAILevel_mutex, "setAILevel");
  callCounter += 1;
  StackPushInteger(enum_AILevel_2_long(tAILevel));
  
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(713, 2);

unlock(setAILevel_mutex, "setAILevel");
  
};

void NWScriptI::setActionMode(const NWN::NWObject& oCreature, NWN::ActionMode tActionMode, bool bStatus, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setActionMode_mutex, "setActionMode");
  callCounter += 1;
  StackPushInteger(bStatus == true ? 1 : 0);
  StackPushInteger(enum_ActionMode_2_long(tActionMode));
  
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(736, 3);

unlock(setActionMode_mutex, "setActionMode");
  
};

void NWScriptI::setAreaTransitionBMP(Ice::Int nPredefinedAreaTransition, const std::string& sCustomAreaTransitionBMP, const Ice::Current& ice) {
  lock(setAreaTransitionBMP_mutex, "setAreaTransitionBMP");
  callCounter += 1;
  StackPushString(sCustomAreaTransitionBMP.c_str());
  StackPushInteger(nPredefinedAreaTransition);

  VM_ExecuteCommand(203, 2);

unlock(setAreaTransitionBMP_mutex, "setAreaTransitionBMP");
  
};

void NWScriptI::setAssociateListenPatterns(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setAssociateListenPatterns_mutex, "setAssociateListenPatterns");
  callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(327, 1);

unlock(setAssociateListenPatterns_mutex, "setAssociateListenPatterns");
  
};

void NWScriptI::setBaseAttackBonus(Ice::Int nBaseAttackBonus, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setBaseAttackBonus_mutex, "setBaseAttackBonus");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nBaseAttackBonus);

  VM_ExecuteCommand(755, 2);

unlock(setBaseAttackBonus_mutex, "setBaseAttackBonus");
  
};

void NWScriptI::setCalendar(Ice::Int nYear, Ice::Int nMonth, Ice::Int nDay, const Ice::Current& ice) {
  lock(setCalendar_mutex, "setCalendar");
  callCounter += 1;
  StackPushInteger(nDay);
  StackPushInteger(nMonth);
  StackPushInteger(nYear);

  VM_ExecuteCommand(11, 3);

unlock(setCalendar_mutex, "setCalendar");
  
};

void NWScriptI::setCameraFacing(Ice::Float fDirection, Ice::Float fDistance, Ice::Float fPitch, Ice::Int nTransitionType, const Ice::Current& ice) {
  lock(setCameraFacing_mutex, "setCameraFacing");
  callCounter += 1;
  StackPushInteger(nTransitionType);
  StackPushFloat(fPitch);
  StackPushFloat(fDistance);
  StackPushFloat(fDirection);

  VM_ExecuteCommand(45, 4);

unlock(setCameraFacing_mutex, "setCameraFacing");
  
};

void NWScriptI::setCameraHeight(const NWN::NWObject& oPlayer, Ice::Float fHeight, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCameraHeight_mutex, "setCameraHeight");
  callCounter += 1;
  StackPushFloat(fHeight);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(776, 2);

unlock(setCameraHeight_mutex, "setCameraHeight");
  
};

void NWScriptI::setCameraMode(const NWN::NWObject& oPlayer, Ice::Int nCameraMode, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCameraMode_mutex, "setCameraMode");
  callCounter += 1;
  StackPushInteger(nCameraMode);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(504, 2);

unlock(setCameraMode_mutex, "setCameraMode");
  
};

void NWScriptI::setCampaignFloat(const std::string& sCampaignName, const std::string& sVarName, Ice::Float flFloat, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCampaignFloat_mutex, "setCampaignFloat");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushFloat(flFloat);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(589, 4);

unlock(setCampaignFloat_mutex, "setCampaignFloat");
  
};

void NWScriptI::setCampaignInt(const std::string& sCampaignName, const std::string& sVarName, Ice::Int nInt, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCampaignInt_mutex, "setCampaignInt");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushInteger(nInt);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(590, 4);

unlock(setCampaignInt_mutex, "setCampaignInt");
  
};

void NWScriptI::setCampaignLocation(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWLocation& locLocation, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (locLocation.area.id < 0) throw NWN::InvalidObjectException();
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCampaignLocation_mutex, "setCampaignLocation");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  
  StackPushFloat(locLocation.facing);
  Vector locLocation_vv;
  locLocation_vv.X = locLocation.x; locLocation_vv.Y = locLocation.y; locLocation_vv.Z = locLocation.z;
  StackPushVector(locLocation_vv);
  StackPushObject(locLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(592, 4);

unlock(setCampaignLocation_mutex, "setCampaignLocation");
  
};

void NWScriptI::setCampaignString(const std::string& sCampaignName, const std::string& sVarName, const std::string& sString, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCampaignString_mutex, "setCampaignString");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sString.c_str());
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(593, 4);

unlock(setCampaignString_mutex, "setCampaignString");
  
};

void NWScriptI::setCampaignVector(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWVector& vVector, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCampaignVector_mutex, "setCampaignVector");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  Vector vvVector;
  vvVector.X = vVector.x; vvVector.Y = vVector.y; vvVector.Z = vVector.z;
  StackPushVector(vvVector);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(591, 4);

unlock(setCampaignVector_mutex, "setCampaignVector");
  
};

void NWScriptI::setColor(const NWN::NWObject& oObject, Ice::Int nColorChannel, Ice::Int nColorValue, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setColor_mutex, "setColor");
  callCounter += 1;
  StackPushInteger(nColorValue);
  StackPushInteger(nColorChannel);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(844, 3);

unlock(setColor_mutex, "setColor");
  
};

void NWScriptI::setCommandable(bool bCommandable, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCommandable_mutex, "setCommandable");
  callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushInteger(bCommandable == true ? 1 : 0);

  VM_ExecuteCommand(162, 2);

unlock(setCommandable_mutex, "setCommandable");
  
};

void NWScriptI::setCreatureAppearanceType(const NWN::NWObject& oCreature, Ice::Int nAppearanceType, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCreatureAppearanceType_mutex, "setCreatureAppearanceType");
  callCounter += 1;
  StackPushInteger(nAppearanceType);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(765, 2);

unlock(setCreatureAppearanceType_mutex, "setCreatureAppearanceType");
  
};

void NWScriptI::setCreatureBodyPart(NWN::CreaturePart tCreaturePart, Ice::Int nModelNumber, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCreatureBodyPart_mutex, "setCreatureBodyPart");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nModelNumber);
  StackPushInteger(enum_CreaturePart_2_long(tCreaturePart));
  

  VM_ExecuteCommand(793, 3);

unlock(setCreatureBodyPart_mutex, "setCreatureBodyPart");
  
};

void NWScriptI::setCreatureTailType(Ice::Int nTailType, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCreatureTailType_mutex, "setCreatureTailType");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nTailType);

  VM_ExecuteCommand(795, 2);

unlock(setCreatureTailType_mutex, "setCreatureTailType");
  
};

void NWScriptI::setCreatureWingType(Ice::Int nWingType, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCreatureWingType_mutex, "setCreatureWingType");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nWingType);

  VM_ExecuteCommand(791, 2);

unlock(setCreatureWingType_mutex, "setCreatureWingType");
  
};

void NWScriptI::setCustomToken(Ice::Int nCustomTokenNumber, const std::string& sTokenValue, const Ice::Current& ice) {
  lock(setCustomToken_mutex, "setCustomToken");
  callCounter += 1;
  StackPushString(sTokenValue.c_str());
  StackPushInteger(nCustomTokenNumber);

  VM_ExecuteCommand(284, 2);

unlock(setCustomToken_mutex, "setCustomToken");
  
};

void NWScriptI::setCutsceneCameraMoveRate(const NWN::NWObject& oCreature, Ice::Float fRate, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCutsceneCameraMoveRate_mutex, "setCutsceneCameraMoveRate");
  callCounter += 1;
  StackPushFloat(fRate);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(743, 2);

unlock(setCutsceneCameraMoveRate_mutex, "setCutsceneCameraMoveRate");
  
};

void NWScriptI::setCutsceneMode(const NWN::NWObject& oCreature, bool bInCutscene, bool bLeftClickingEnabled, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setCutsceneMode_mutex, "setCutsceneMode");
  callCounter += 1;
  StackPushInteger(bLeftClickingEnabled == true ? 1 : 0);
  StackPushInteger(bInCutscene == true ? 1 : 0);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(692, 3);

unlock(setCutsceneMode_mutex, "setCutsceneMode");
  
};

void NWScriptI::setDeity(const NWN::NWObject& oCreature, const std::string& sDeity, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setDeity_mutex, "setDeity");
  callCounter += 1;
  StackPushString(sDeity.c_str());
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(722, 2);

unlock(setDeity_mutex, "setDeity");
  
};

void NWScriptI::setDescription(const NWN::NWObject& oObject, const std::string& sNewDescription, bool bIdentifiedDescription, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setDescription_mutex, "setDescription");
  callCounter += 1;
  StackPushInteger(bIdentifiedDescription == true ? 1 : 0);
  StackPushString(sNewDescription.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(837, 3);

unlock(setDescription_mutex, "setDescription");
  
};

void NWScriptI::setDroppableFlag(const NWN::NWObject& oItem, bool bDroppable, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setDroppableFlag_mutex, "setDroppableFlag");
  callCounter += 1;
  StackPushInteger(bDroppable == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(705, 2);

unlock(setDroppableFlag_mutex, "setDroppableFlag");
  
};

void NWScriptI::setEncounterActive(bool bNewValue, const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  if (oEncounter.id < 0 || oEncounter.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setEncounterActive_mutex, "setEncounterActive");
  callCounter += 1;
  StackPushObject(oEncounter.id);
  StackPushInteger(bNewValue == true ? 1 : 0);

  VM_ExecuteCommand(277, 2);

unlock(setEncounterActive_mutex, "setEncounterActive");
  
};

void NWScriptI::setEncounterDifficulty(Ice::Int nEncounterDifficulty, const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  if (oEncounter.id < 0 || oEncounter.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setEncounterDifficulty_mutex, "setEncounterDifficulty");
  callCounter += 1;
  StackPushObject(oEncounter.id);
  StackPushInteger(nEncounterDifficulty);

  VM_ExecuteCommand(296, 2);

unlock(setEncounterDifficulty_mutex, "setEncounterDifficulty");
  
};

void NWScriptI::setEncounterSpawnsCurrent(Ice::Int nNewValue, const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  if (oEncounter.id < 0 || oEncounter.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setEncounterSpawnsCurrent_mutex, "setEncounterSpawnsCurrent");
  callCounter += 1;
  StackPushObject(oEncounter.id);
  StackPushInteger(nNewValue);

  VM_ExecuteCommand(281, 2);

unlock(setEncounterSpawnsCurrent_mutex, "setEncounterSpawnsCurrent");
  
};

void NWScriptI::setEncounterSpawnsMax(Ice::Int nNewValue, const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  if (oEncounter.id < 0 || oEncounter.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setEncounterSpawnsMax_mutex, "setEncounterSpawnsMax");
  callCounter += 1;
  StackPushObject(oEncounter.id);
  StackPushInteger(nNewValue);

  VM_ExecuteCommand(279, 2);

unlock(setEncounterSpawnsMax_mutex, "setEncounterSpawnsMax");
  
};

void NWScriptI::setFacing(Ice::Float fDirection, const Ice::Current& ice) {
  lock(setFacing_mutex, "setFacing");
  callCounter += 1;
  StackPushFloat(fDirection);

  VM_ExecuteCommand(10, 1);

unlock(setFacing_mutex, "setFacing");
  
};

void NWScriptI::setFacingPoint(const NWN::NWVector& vTarget, const Ice::Current& ice) {
  lock(setFacingPoint_mutex, "setFacingPoint");
  callCounter += 1;
  Vector vvTarget;
  vvTarget.X = vTarget.x; vvTarget.Y = vTarget.y; vvTarget.Z = vTarget.z;
  StackPushVector(vvTarget);

  VM_ExecuteCommand(143, 1);

unlock(setFacingPoint_mutex, "setFacingPoint");
  
};

void NWScriptI::setFogAmount(Ice::Int nFogType, Ice::Int nFogAmount, const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setFogAmount_mutex, "setFogAmount");
  callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nFogAmount);
  StackPushInteger(nFogType);

  VM_ExecuteCommand(784, 3);

unlock(setFogAmount_mutex, "setFogAmount");
  
};

void NWScriptI::setFogColor(Ice::Int nFogType, Ice::Int nFogColor, const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setFogColor_mutex, "setFogColor");
  callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nFogColor);
  StackPushInteger(nFogType);

  VM_ExecuteCommand(780, 3);

unlock(setFogColor_mutex, "setFogColor");
  
};

void NWScriptI::setFootstepType(Ice::Int nFootstepType, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setFootstepType_mutex, "setFootstepType");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nFootstepType);

  VM_ExecuteCommand(789, 2);

unlock(setFootstepType_mutex, "setFootstepType");
  
};

void NWScriptI::setFortitudeSavingThrow(const NWN::NWObject& oObject, Ice::Int nFortitudeSave, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setFortitudeSavingThrow_mutex, "setFortitudeSavingThrow");
  callCounter += 1;
  StackPushInteger(nFortitudeSave);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(813, 2);

unlock(setFortitudeSavingThrow_mutex, "setFortitudeSavingThrow");
  
};

void NWScriptI::setHardness(Ice::Int nHardness, const NWN::NWObject& oObject, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setHardness_mutex, "setHardness");
  callCounter += 1;
  StackPushObject(oObject.id);
  StackPushInteger(nHardness);

  VM_ExecuteCommand(797, 2);

unlock(setHardness_mutex, "setHardness");
  
};

void NWScriptI::setIdentified(const NWN::NWObject& oItem, bool bIdentified, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setIdentified_mutex, "setIdentified");
  callCounter += 1;
  StackPushInteger(bIdentified == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(333, 2);

unlock(setIdentified_mutex, "setIdentified");
  
};

void NWScriptI::setImmortal(const NWN::NWObject& oCreature, bool bImmortal, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setImmortal_mutex, "setImmortal");
  callCounter += 1;
  StackPushInteger(bImmortal == true ? 1 : 0);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(700, 2);

unlock(setImmortal_mutex, "setImmortal");
  
};

void NWScriptI::setInfiniteFlag(const NWN::NWObject& oItem, bool bInfinite, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setInfiniteFlag_mutex, "setInfiniteFlag");
  callCounter += 1;
  StackPushInteger(bInfinite == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(828, 2);

unlock(setInfiniteFlag_mutex, "setInfiniteFlag");
  
};

void NWScriptI::setIsDestroyable(bool bDestroyable, bool bRaiseable, bool bSelectableWhenDead, const Ice::Current& ice) {
  lock(setIsDestroyable_mutex, "setIsDestroyable");
  callCounter += 1;
  StackPushInteger(bSelectableWhenDead == true ? 1 : 0);
  StackPushInteger(bRaiseable == true ? 1 : 0);
  StackPushInteger(bDestroyable == true ? 1 : 0);

  VM_ExecuteCommand(323, 3);

unlock(setIsDestroyable_mutex, "setIsDestroyable");
  
};

void NWScriptI::setIsTemporaryEnemy(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, bool bDecays, Ice::Float fDurationInSeconds, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setIsTemporaryEnemy_mutex, "setIsTemporaryEnemy");
  callCounter += 1;
  StackPushFloat(fDurationInSeconds);
  StackPushInteger(bDecays == true ? 1 : 0);
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(391, 4);

unlock(setIsTemporaryEnemy_mutex, "setIsTemporaryEnemy");
  
};

void NWScriptI::setIsTemporaryFriend(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, bool bDecays, Ice::Float fDurationInSeconds, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setIsTemporaryFriend_mutex, "setIsTemporaryFriend");
  callCounter += 1;
  StackPushFloat(fDurationInSeconds);
  StackPushInteger(bDecays == true ? 1 : 0);
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(390, 4);

unlock(setIsTemporaryFriend_mutex, "setIsTemporaryFriend");
  
};

void NWScriptI::setIsTemporaryNeutral(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, bool bDecays, Ice::Float fDurationInSeconds, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSource.id < 0 || oSource.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setIsTemporaryNeutral_mutex, "setIsTemporaryNeutral");
  callCounter += 1;
  StackPushFloat(fDurationInSeconds);
  StackPushInteger(bDecays == true ? 1 : 0);
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(392, 4);

unlock(setIsTemporaryNeutral_mutex, "setIsTemporaryNeutral");
  
};

void NWScriptI::setItemCharges(const NWN::NWObject& oItem, Ice::Int nCharges, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setItemCharges_mutex, "setItemCharges");
  callCounter += 1;
  StackPushInteger(nCharges);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(608, 2);

unlock(setItemCharges_mutex, "setItemCharges");
  
};

void NWScriptI::setItemCursedFlag(const NWN::NWObject& oItem, bool bCursed, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setItemCursedFlag_mutex, "setItemCursedFlag");
  callCounter += 1;
  StackPushInteger(bCursed == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(745, 2);

unlock(setItemCursedFlag_mutex, "setItemCursedFlag");
  
};

void NWScriptI::setItemStackSize(const NWN::NWObject& oItem, Ice::Int nSize, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setItemStackSize_mutex, "setItemStackSize");
  callCounter += 1;
  StackPushInteger(nSize);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(606, 2);

unlock(setItemStackSize_mutex, "setItemStackSize");
  
};

void NWScriptI::setKeyRequiredFeedback(const NWN::NWObject& oObject, const std::string& sFeedbackMessage, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setKeyRequiredFeedback_mutex, "setKeyRequiredFeedback");
  callCounter += 1;
  StackPushString(sFeedbackMessage.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(820, 2);

unlock(setKeyRequiredFeedback_mutex, "setKeyRequiredFeedback");
  
};

void NWScriptI::setListenPattern(const NWN::NWObject& oObject, const std::string& sPattern, Ice::Int nNumber, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setListenPattern_mutex, "setListenPattern");
  callCounter += 1;
  StackPushInteger(nNumber);
  StackPushString(sPattern.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(176, 3);

unlock(setListenPattern_mutex, "setListenPattern");
  
};

void NWScriptI::setListening(const NWN::NWObject& oObject, bool bValue, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setListening_mutex, "setListening");
  callCounter += 1;
  StackPushInteger(bValue == true ? 1 : 0);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(175, 2);

unlock(setListening_mutex, "setListening");
  
};

void NWScriptI::setLocalFloat(const NWN::NWObject& oObject, const std::string& sVarName, Ice::Float fValue, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setLocalFloat_mutex, "setLocalFloat");
  callCounter += 1;
  StackPushFloat(fValue);
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(56, 3);

unlock(setLocalFloat_mutex, "setLocalFloat");
  
};

void NWScriptI::setLocalInt(const NWN::NWObject& oObject, const std::string& sVarName, Ice::Int nValue, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setLocalInt_mutex, "setLocalInt");
  callCounter += 1;
  StackPushInteger(nValue);
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(55, 3);

unlock(setLocalInt_mutex, "setLocalInt");
  
};

void NWScriptI::setLocalLocation(const NWN::NWObject& oObject, const std::string& sVarName, const NWN::NWLocation& lValue, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (lValue.area.id < 0) throw NWN::InvalidObjectException();
  lock(setLocalLocation_mutex, "setLocalLocation");
  callCounter += 1;
  
  StackPushFloat(lValue.facing);
  Vector lValue_vv;
  lValue_vv.X = lValue.x; lValue_vv.Y = lValue.y; lValue_vv.Z = lValue.z;
  StackPushVector(lValue_vv);
  StackPushObject(lValue.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(152, 3);

unlock(setLocalLocation_mutex, "setLocalLocation");
  
};

void NWScriptI::setLocalObject(const NWN::NWObject& oObject, const std::string& sVarName, const NWN::NWObject& oValue, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oValue.id < 0 || oValue.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setLocalObject_mutex, "setLocalObject");
  callCounter += 1;
  StackPushObject(oValue.id);
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(58, 3);

unlock(setLocalObject_mutex, "setLocalObject");
  
};

void NWScriptI::setLocalString(const NWN::NWObject& oObject, const std::string& sVarName, const std::string& sValue, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setLocalString_mutex, "setLocalString");
  callCounter += 1;
  StackPushString(sValue.c_str());
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(57, 3);

unlock(setLocalString_mutex, "setLocalString");
  
};

void NWScriptI::setLockKeyRequired(const NWN::NWObject& oObject, bool bKeyRequired, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setLockKeyRequired_mutex, "setLockKeyRequired");
  callCounter += 1;
  StackPushInteger(bKeyRequired == true ? 1 : 0);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(798, 2);

unlock(setLockKeyRequired_mutex, "setLockKeyRequired");
  
};

void NWScriptI::setLockKeyTag(const NWN::NWObject& oObject, const std::string& sNewKeyTag, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setLockKeyTag_mutex, "setLockKeyTag");
  callCounter += 1;
  StackPushString(sNewKeyTag.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(799, 2);

unlock(setLockKeyTag_mutex, "setLockKeyTag");
  
};

void NWScriptI::setLockLockDC(const NWN::NWObject& oObject, Ice::Int nNewLockDC, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setLockLockDC_mutex, "setLockLockDC");
  callCounter += 1;
  StackPushInteger(nNewLockDC);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(802, 2);

unlock(setLockLockDC_mutex, "setLockLockDC");
  
};

void NWScriptI::setLockLockable(const NWN::NWObject& oObject, bool bLockable, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setLockLockable_mutex, "setLockLockable");
  callCounter += 1;
  StackPushInteger(bLockable == true ? 1 : 0);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(800, 2);

unlock(setLockLockable_mutex, "setLockLockable");
  
};

void NWScriptI::setLockUnlockDC(const NWN::NWObject& oObject, Ice::Int nNewUnlockDC, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setLockUnlockDC_mutex, "setLockUnlockDC");
  callCounter += 1;
  StackPushInteger(nNewUnlockDC);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(801, 2);

unlock(setLockUnlockDC_mutex, "setLockUnlockDC");
  
};

void NWScriptI::setLocked(const NWN::NWObject& oTarget, bool bLocked, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setLocked_mutex, "setLocked");
  callCounter += 1;
  StackPushInteger(bLocked == true ? 1 : 0);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(324, 2);

unlock(setLocked_mutex, "setLocked");
  
};

void NWScriptI::setLootable(const NWN::NWObject& oCreature, bool bLootable, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setLootable_mutex, "setLootable");
  callCounter += 1;
  StackPushInteger(bLootable == true ? 1 : 0);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(740, 2);

unlock(setLootable_mutex, "setLootable");
  
};

void NWScriptI::setMapPinEnabled(const NWN::NWObject& oMapPin, bool bEnabled, const Ice::Current& ice) {
  if (oMapPin.id < 0 || oMapPin.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setMapPinEnabled_mutex, "setMapPinEnabled");
  callCounter += 1;
  StackPushInteger(bEnabled == true ? 1 : 0);
  StackPushObject(oMapPin.id);

  VM_ExecuteCommand(386, 2);

unlock(setMapPinEnabled_mutex, "setMapPinEnabled");
  
};

void NWScriptI::setMaxHenchmen(Ice::Int nNumHenchmen, const Ice::Current& ice) {
  lock(setMaxHenchmen_mutex, "setMaxHenchmen");
  callCounter += 1;
  StackPushInteger(nNumHenchmen);

  VM_ExecuteCommand(746, 1);

unlock(setMaxHenchmen_mutex, "setMaxHenchmen");
  
};

void NWScriptI::setModuleXPScale(Ice::Int nXPScale, const Ice::Current& ice) {
  lock(setModuleXPScale_mutex, "setModuleXPScale");
  callCounter += 1;
  StackPushInteger(nXPScale);

  VM_ExecuteCommand(818, 1);

unlock(setModuleXPScale_mutex, "setModuleXPScale");
  
};

void NWScriptI::setName(const NWN::NWObject& oObject, const std::string& sNewName, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setName_mutex, "setName");
  callCounter += 1;
  StackPushString(sNewName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(830, 2);

unlock(setName_mutex, "setName");
  
};

void NWScriptI::setPCChatMessage(const std::string& sNewChatMessage, const Ice::Current& ice) {
  lock(setPCChatMessage_mutex, "setPCChatMessage");
  callCounter += 1;
  StackPushString(sNewChatMessage.c_str());

  VM_ExecuteCommand(841, 1);

unlock(setPCChatMessage_mutex, "setPCChatMessage");
  
};

void NWScriptI::setPCChatVolume(NWN::TalkVolume tTalkVolume, const Ice::Current& ice) {
  lock(setPCChatVolume_mutex, "setPCChatVolume");
  callCounter += 1;
  StackPushInteger(enum_TalkVolume_2_long(tTalkVolume));
  

  VM_ExecuteCommand(842, 1);

unlock(setPCChatVolume_mutex, "setPCChatVolume");
  
};

void NWScriptI::setPCDislike(const NWN::NWObject& oPlayer, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setPCDislike_mutex, "setPCDislike");
  callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(373, 2);

unlock(setPCDislike_mutex, "setPCDislike");
  
};

void NWScriptI::setPCLike(const NWN::NWObject& oPlayer, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setPCLike_mutex, "setPCLike");
  callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(372, 2);

unlock(setPCLike_mutex, "setPCLike");
  
};

void NWScriptI::setPanelButtonFlash(const NWN::NWObject& oPlayer, NWN::Button tButton, bool bEnableFlash, const Ice::Current& ice) {
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setPanelButtonFlash_mutex, "setPanelButtonFlash");
  callCounter += 1;
  StackPushInteger(bEnableFlash == true ? 1 : 0);
  StackPushInteger(enum_Button_2_long(tButton));
  
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(521, 3);

unlock(setPanelButtonFlash_mutex, "setPanelButtonFlash");
  
};

void NWScriptI::setPhenoType(NWN::PhenoType tPhenoType, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setPhenoType_mutex, "setPhenoType");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(enum_PhenoType_2_long(tPhenoType));
  

  VM_ExecuteCommand(779, 2);

unlock(setPhenoType_mutex, "setPhenoType");
  
};

void NWScriptI::setPickpocketableFlag(const NWN::NWObject& oItem, bool bPickpocketable, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setPickpocketableFlag_mutex, "setPickpocketableFlag");
  callCounter += 1;
  StackPushInteger(bPickpocketable == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(787, 2);

unlock(setPickpocketableFlag_mutex, "setPickpocketableFlag");
  
};

void NWScriptI::setPlaceableIllumination(const NWN::NWObject& oPlaceable, bool bIlluminate, const Ice::Current& ice) {
  if (oPlaceable.id < 0 || oPlaceable.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setPlaceableIllumination_mutex, "setPlaceableIllumination");
  callCounter += 1;
  StackPushInteger(bIlluminate == true ? 1 : 0);
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(544, 2);

unlock(setPlaceableIllumination_mutex, "setPlaceableIllumination");
  
};

void NWScriptI::setPlotFlag(const NWN::NWObject& oTarget, bool bPlotFlag, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setPlotFlag_mutex, "setPlotFlag");
  callCounter += 1;
  StackPushInteger(bPlotFlag == true ? 1 : 0);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(456, 2);

unlock(setPlotFlag_mutex, "setPlotFlag");
  
};

void NWScriptI::setPortraitId(const NWN::NWObject& oTarget, Ice::Int nPortraitId, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setPortraitId_mutex, "setPortraitId");
  callCounter += 1;
  StackPushInteger(nPortraitId);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(832, 2);

unlock(setPortraitId_mutex, "setPortraitId");
  
};

void NWScriptI::setPortraitResRef(const NWN::NWObject& oTarget, const std::string& sPortraitResRef, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setPortraitResRef_mutex, "setPortraitResRef");
  callCounter += 1;
  StackPushString(sPortraitResRef.c_str());
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(834, 2);

unlock(setPortraitResRef_mutex, "setPortraitResRef");
  
};

void NWScriptI::setReflexSavingThrow(const NWN::NWObject& oObject, Ice::Int nReflexSave, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setReflexSavingThrow_mutex, "setReflexSavingThrow");
  callCounter += 1;
  StackPushInteger(nReflexSave);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(812, 2);

unlock(setReflexSavingThrow_mutex, "setReflexSavingThrow");
  
};

void NWScriptI::setSkyBox(Ice::Int nSkyBox, const NWN::NWObject& oArea, const Ice::Current& ice) {
  if (oArea.id < 0 || oArea.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setSkyBox_mutex, "setSkyBox");
  callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nSkyBox);

  VM_ExecuteCommand(777, 2);

unlock(setSkyBox_mutex, "setSkyBox");
  
};

void NWScriptI::setStandardFactionReputation(NWN::StandardFaction tStandardFaction, Ice::Int nNewReputation, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setStandardFactionReputation_mutex, "setStandardFactionReputation");
  callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nNewReputation);
  StackPushInteger(enum_StandardFaction_2_long(tStandardFaction));
  

  VM_ExecuteCommand(523, 3);

unlock(setStandardFactionReputation_mutex, "setStandardFactionReputation");
  
};

void NWScriptI::setStolenFlag(const NWN::NWObject& oItem, bool bStolenFlag, const Ice::Current& ice) {
  if (oItem.id < 0 || oItem.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setStolenFlag_mutex, "setStolenFlag");
  callCounter += 1;
  StackPushInteger(bStolenFlag == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(774, 2);

unlock(setStolenFlag_mutex, "setStolenFlag");
  
};

void NWScriptI::setStoreGold(const NWN::NWObject& oidStore, Ice::Int nGold, const Ice::Current& ice) {
  if (oidStore.id < 0 || oidStore.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setStoreGold_mutex, "setStoreGold");
  callCounter += 1;
  StackPushInteger(nGold);
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(760, 2);

unlock(setStoreGold_mutex, "setStoreGold");
  
};

void NWScriptI::setStoreIdentifyCost(const NWN::NWObject& oidStore, Ice::Int nCost, const Ice::Current& ice) {
  if (oidStore.id < 0 || oidStore.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setStoreIdentifyCost_mutex, "setStoreIdentifyCost");
  callCounter += 1;
  StackPushInteger(nCost);
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(764, 2);

unlock(setStoreIdentifyCost_mutex, "setStoreIdentifyCost");
  
};

void NWScriptI::setStoreMaxBuyPrice(const NWN::NWObject& oidStore, Ice::Int nMaxBuy, const Ice::Current& ice) {
  if (oidStore.id < 0 || oidStore.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setStoreMaxBuyPrice_mutex, "setStoreMaxBuyPrice");
  callCounter += 1;
  StackPushInteger(nMaxBuy);
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(762, 2);

unlock(setStoreMaxBuyPrice_mutex, "setStoreMaxBuyPrice");
  
};

void NWScriptI::setSubRace(const NWN::NWObject& oCreature, const std::string& sSubRace, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setSubRace_mutex, "setSubRace");
  callCounter += 1;
  StackPushString(sSubRace.c_str());
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(721, 2);

unlock(setSubRace_mutex, "setSubRace");
  
};

void NWScriptI::setTileMainLightColor(const NWN::NWLocation& lTileLocation, NWN::TileMainLightColor nMainLight1Color, NWN::TileMainLightColor nMainLight2Color, const Ice::Current& ice) {
  if (lTileLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(setTileMainLightColor_mutex, "setTileMainLightColor");
  callCounter += 1;
  StackPushInteger(enum_TileMainLightColor_2_long(nMainLight2Color));
  
  StackPushInteger(enum_TileMainLightColor_2_long(nMainLight1Color));
  
  
  StackPushFloat(lTileLocation.facing);
  Vector lTileLocation_vv;
  lTileLocation_vv.X = lTileLocation.x; lTileLocation_vv.Y = lTileLocation.y; lTileLocation_vv.Z = lTileLocation.z;
  StackPushVector(lTileLocation_vv);
  StackPushObject(lTileLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(514, 3);

unlock(setTileMainLightColor_mutex, "setTileMainLightColor");
  
};

void NWScriptI::setTileSourceLightColor(const NWN::NWLocation& lTileLocation, NWN::TileSourceLightColor nSourceLight1Color, NWN::TileSourceLightColor nSourceLight2Color, const Ice::Current& ice) {
  if (lTileLocation.area.id < 0) throw NWN::InvalidObjectException();
  lock(setTileSourceLightColor_mutex, "setTileSourceLightColor");
  callCounter += 1;
  StackPushInteger(enum_TileSourceLightColor_2_long(nSourceLight2Color));
  
  StackPushInteger(enum_TileSourceLightColor_2_long(nSourceLight1Color));
  
  
  StackPushFloat(lTileLocation.facing);
  Vector lTileLocation_vv;
  lTileLocation_vv.X = lTileLocation.x; lTileLocation_vv.Y = lTileLocation.y; lTileLocation_vv.Z = lTileLocation.z;
  StackPushVector(lTileLocation_vv);
  StackPushObject(lTileLocation.area.id);
  VM_ExecuteCommand(215, 3); // Location(...);
  

  VM_ExecuteCommand(515, 3);

unlock(setTileSourceLightColor_mutex, "setTileSourceLightColor");
  
};

void NWScriptI::setTime(Ice::Int nHour, Ice::Int nMinute, Ice::Int nSecond, Ice::Int nMillisecond, const Ice::Current& ice) {
  lock(setTime_mutex, "setTime");
  callCounter += 1;
  StackPushInteger(nMillisecond);
  StackPushInteger(nSecond);
  StackPushInteger(nMinute);
  StackPushInteger(nHour);

  VM_ExecuteCommand(12, 4);

unlock(setTime_mutex, "setTime");
  
};

void NWScriptI::setTrapActive(const NWN::NWObject& oTrapObject, bool bActive, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setTrapActive_mutex, "setTrapActive");
  callCounter += 1;
  StackPushInteger(bActive == true ? 1 : 0);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(822, 2);

unlock(setTrapActive_mutex, "setTrapActive");
  
};

void NWScriptI::setTrapDetectDC(const NWN::NWObject& oTrapObject, Ice::Int nDetectDC, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setTrapDetectDC_mutex, "setTrapDetectDC");
  callCounter += 1;
  StackPushInteger(nDetectDC);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(808, 2);

unlock(setTrapDetectDC_mutex, "setTrapDetectDC");
  
};

void NWScriptI::setTrapDetectable(const NWN::NWObject& oTrapObject, bool bDetectable, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setTrapDetectable_mutex, "setTrapDetectable");
  callCounter += 1;
  StackPushInteger(bDetectable == true ? 1 : 0);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(804, 2);

unlock(setTrapDetectable_mutex, "setTrapDetectable");
  
};

Ice::Int NWScriptI::setTrapDetectedBy(const NWN::NWObject& oTrap, const NWN::NWObject& oDetector, bool bDetected, const Ice::Current& ice) {
  if (oTrap.id < 0 || oTrap.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oDetector.id < 0 || oDetector.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setTrapDetectedBy_mutex, "setTrapDetectedBy");
  callCounter += 1;
  StackPushInteger(bDetected == true ? 1 : 0);
  StackPushObject(oDetector.id);
  StackPushObject(oTrap.id);

  VM_ExecuteCommand(550, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(setTrapDetectedBy_mutex, "setTrapDetectedBy");
  return nRetVal;
};

void NWScriptI::setTrapDisabled(const NWN::NWObject& oTrap, const Ice::Current& ice) {
  if (oTrap.id < 0 || oTrap.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setTrapDisabled_mutex, "setTrapDisabled");
  callCounter += 1;
  StackPushObject(oTrap.id);

  VM_ExecuteCommand(555, 1);

unlock(setTrapDisabled_mutex, "setTrapDisabled");
  
};

void NWScriptI::setTrapDisarmDC(const NWN::NWObject& oTrapObject, Ice::Int nDisarmDC, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setTrapDisarmDC_mutex, "setTrapDisarmDC");
  callCounter += 1;
  StackPushInteger(nDisarmDC);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(807, 2);

unlock(setTrapDisarmDC_mutex, "setTrapDisarmDC");
  
};

void NWScriptI::setTrapDisarmable(const NWN::NWObject& oTrapObject, bool bDisarmable, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setTrapDisarmable_mutex, "setTrapDisarmable");
  callCounter += 1;
  StackPushInteger(bDisarmable == true ? 1 : 0);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(803, 2);

unlock(setTrapDisarmable_mutex, "setTrapDisarmable");
  
};

void NWScriptI::setTrapKeyTag(const NWN::NWObject& oTrapObject, const std::string& sKeyTag, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setTrapKeyTag_mutex, "setTrapKeyTag");
  callCounter += 1;
  StackPushString(sKeyTag.c_str());
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(806, 2);

unlock(setTrapKeyTag_mutex, "setTrapKeyTag");
  
};

void NWScriptI::setTrapOneShot(const NWN::NWObject& oTrapObject, bool bOneShot, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setTrapOneShot_mutex, "setTrapOneShot");
  callCounter += 1;
  StackPushInteger(bOneShot == true ? 1 : 0);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(805, 2);

unlock(setTrapOneShot_mutex, "setTrapOneShot");
  
};

void NWScriptI::setTrapRecoverable(const NWN::NWObject& oTrapObject, bool bRecoverable, const Ice::Current& ice) {
  if (oTrapObject.id < 0 || oTrapObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setTrapRecoverable_mutex, "setTrapRecoverable");
  callCounter += 1;
  StackPushInteger(bRecoverable == true ? 1 : 0);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(816, 2);

unlock(setTrapRecoverable_mutex, "setTrapRecoverable");
  
};

void NWScriptI::setUseableFlag(const NWN::NWObject& oPlaceable, bool bUseableFlag, const Ice::Current& ice) {
  if (oPlaceable.id < 0 || oPlaceable.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setUseableFlag_mutex, "setUseableFlag");
  callCounter += 1;
  StackPushInteger(bUseableFlag == true ? 1 : 0);
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(835, 2);

unlock(setUseableFlag_mutex, "setUseableFlag");
  
};

void NWScriptI::setWeather(const NWN::NWObject& oTarget, NWN::Weather tWeather, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setWeather_mutex, "setWeather");
  callCounter += 1;
  StackPushInteger(enum_Weather_2_long(tWeather));
  
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(507, 2);

unlock(setWeather_mutex, "setWeather");
  
};

void NWScriptI::setWillSavingThrow(const NWN::NWObject& oObject, Ice::Int nWillSave, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setWillSavingThrow_mutex, "setWillSavingThrow");
  callCounter += 1;
  StackPushInteger(nWillSave);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(811, 2);

unlock(setWillSavingThrow_mutex, "setWillSavingThrow");
  
};

void NWScriptI::setXP(const NWN::NWObject& oCreature, Ice::Int nXpAmount, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(setXP_mutex, "setXP");
  callCounter += 1;
  StackPushInteger(nXpAmount);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(394, 2);

unlock(setXP_mutex, "setXP");
  
};

Ice::Float NWScriptI::sin(Ice::Float fValue, const Ice::Current& ice) {
  lock(sin_mutex, "sin");
  callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(69, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(sin_mutex, "sin");
  return fRetVal;
};

void NWScriptI::soundObjectPlay(const NWN::NWObject& oSound, const Ice::Current& ice) {
  if (oSound.id < 0 || oSound.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(soundObjectPlay_mutex, "soundObjectPlay");
  callCounter += 1;
  StackPushObject(oSound.id);

  VM_ExecuteCommand(413, 1);

unlock(soundObjectPlay_mutex, "soundObjectPlay");
  
};

void NWScriptI::soundObjectSetPosition(const NWN::NWObject& oSound, const NWN::NWVector& vPosition, const Ice::Current& ice) {
  if (oSound.id < 0 || oSound.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(soundObjectSetPosition_mutex, "soundObjectSetPosition");
  callCounter += 1;
  Vector vvPosition;
  vvPosition.X = vPosition.x; vvPosition.Y = vPosition.y; vvPosition.Z = vPosition.z;
  StackPushVector(vvPosition);
  StackPushObject(oSound.id);

  VM_ExecuteCommand(416, 2);

unlock(soundObjectSetPosition_mutex, "soundObjectSetPosition");
  
};

void NWScriptI::soundObjectSetVolume(const NWN::NWObject& oSound, Ice::Int nVolume, const Ice::Current& ice) {
  if (oSound.id < 0 || oSound.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(soundObjectSetVolume_mutex, "soundObjectSetVolume");
  callCounter += 1;
  StackPushInteger(nVolume);
  StackPushObject(oSound.id);

  VM_ExecuteCommand(415, 2);

unlock(soundObjectSetVolume_mutex, "soundObjectSetVolume");
  
};

void NWScriptI::soundObjectStop(const NWN::NWObject& oSound, const Ice::Current& ice) {
  if (oSound.id < 0 || oSound.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(soundObjectStop_mutex, "soundObjectStop");
  callCounter += 1;
  StackPushObject(oSound.id);

  VM_ExecuteCommand(414, 1);

unlock(soundObjectStop_mutex, "soundObjectStop");
  
};

void NWScriptI::spawnScriptDebugger(const Ice::Current& ice) {
  lock(spawnScriptDebugger_mutex, "spawnScriptDebugger");
  callCounter += 1;

  VM_ExecuteCommand(578, 0);

unlock(spawnScriptDebugger_mutex, "spawnScriptDebugger");
  
};

void NWScriptI::speakOneLinerConversation(const std::string& sDialogResRef, const NWN::NWObject& oTokenTarget, const Ice::Current& ice) {
  if (oTokenTarget.id < 0 || oTokenTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(speakOneLinerConversation_mutex, "speakOneLinerConversation");
  callCounter += 1;
  StackPushObject(oTokenTarget.id);
  StackPushString(sDialogResRef.c_str());

  VM_ExecuteCommand(417, 2);

unlock(speakOneLinerConversation_mutex, "speakOneLinerConversation");
  
};

void NWScriptI::speakString(const std::string& sStringToSpeak, NWN::TalkVolume tTalkVolume, const Ice::Current& ice) {
  lock(speakString_mutex, "speakString");
  callCounter += 1;
  StackPushInteger(enum_TalkVolume_2_long(tTalkVolume));
  
  StackPushString(sStringToSpeak.c_str());

  VM_ExecuteCommand(221, 2);

unlock(speakString_mutex, "speakString");
  
};

void NWScriptI::speakStringByStrRef(Ice::Int nStrRef, NWN::TalkVolume tTalkVolume, const Ice::Current& ice) {
  lock(speakStringByStrRef_mutex, "speakStringByStrRef");
  callCounter += 1;
  StackPushInteger(enum_TalkVolume_2_long(tTalkVolume));
  
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(691, 2);

unlock(speakStringByStrRef_mutex, "speakStringByStrRef");
  
};

Ice::Float NWScriptI::sqrt(Ice::Float fValue, const Ice::Current& ice) {
  lock(sqrt_mutex, "sqrt");
  callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(76, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(sqrt_mutex, "sqrt");
  return fRetVal;
};

void NWScriptI::startNewModule(const std::string& sModuleName, const Ice::Current& ice) {
  lock(startNewModule_mutex, "startNewModule");
  callCounter += 1;
  StackPushString(sModuleName.c_str());

  VM_ExecuteCommand(509, 1);

unlock(startNewModule_mutex, "startNewModule");
  
};

void NWScriptI::stopFade(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(stopFade_mutex, "stopFade");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(697, 1);

unlock(stopFade_mutex, "stopFade");
  
};

void NWScriptI::storeCameraFacing(const Ice::Current& ice) {
  lock(storeCameraFacing_mutex, "storeCameraFacing");
  callCounter += 1;

  VM_ExecuteCommand(702, 0);

unlock(storeCameraFacing_mutex, "storeCameraFacing");
  
};

Ice::Int NWScriptI::storeCampaignObject(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oObject, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  if (oObject.id < 0 || oObject.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oPlayer.id < 0 || oPlayer.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(storeCampaignObject_mutex, "storeCampaignObject");
  callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushObject(oObject.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(602, 4);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(storeCampaignObject_mutex, "storeCampaignObject");
  return nRetVal;
};

Ice::Float NWScriptI::stringToFloat(const std::string& sNumber, const Ice::Current& ice) {
  lock(stringToFloat_mutex, "stringToFloat");
  callCounter += 1;
  StackPushString(sNumber.c_str());

  VM_ExecuteCommand(233, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(stringToFloat_mutex, "stringToFloat");
  return fRetVal;
};

Ice::Int NWScriptI::stringToInt(const std::string& sNumber, const Ice::Current& ice) {
  lock(stringToInt_mutex, "stringToInt");
  callCounter += 1;
  StackPushString(sNumber.c_str());

  VM_ExecuteCommand(232, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(stringToInt_mutex, "stringToInt");
  return nRetVal;
};

void NWScriptI::summonAnimalCompanion(const NWN::NWObject& oMaster, const Ice::Current& ice) {
  if (oMaster.id < 0 || oMaster.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(summonAnimalCompanion_mutex, "summonAnimalCompanion");
  callCounter += 1;
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(334, 1);

unlock(summonAnimalCompanion_mutex, "summonAnimalCompanion");
  
};

void NWScriptI::summonFamiliar(const NWN::NWObject& oMaster, const Ice::Current& ice) {
  if (oMaster.id < 0 || oMaster.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(summonFamiliar_mutex, "summonFamiliar");
  callCounter += 1;
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(335, 1);

unlock(summonFamiliar_mutex, "summonFamiliar");
  
};

NWN::NWEffect NWScriptI::supernaturalEffect(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(supernaturalEffect_mutex, "supernaturalEffect");
  callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(113, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(supernaturalEffect_mutex, "supernaturalEffect");
  return e;
};

void NWScriptI::surrenderToEnemies(const Ice::Current& ice) {
  lock(surrenderToEnemies_mutex, "surrenderToEnemies");
  callCounter += 1;

  VM_ExecuteCommand(476, 0);

unlock(surrenderToEnemies_mutex, "surrenderToEnemies");
  
};

void NWScriptI::takeGoldFromCreature(Ice::Int nAmount, const NWN::NWObject& oCreatureToTakeFrom, bool bDestroy, const Ice::Current& ice) {
  if (oCreatureToTakeFrom.id < 0 || oCreatureToTakeFrom.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(takeGoldFromCreature_mutex, "takeGoldFromCreature");
  callCounter += 1;
  StackPushInteger(bDestroy == true ? 1 : 0);
  StackPushObject(oCreatureToTakeFrom.id);
  StackPushInteger(nAmount);

  VM_ExecuteCommand(444, 3);

unlock(takeGoldFromCreature_mutex, "takeGoldFromCreature");
  
};

Ice::Float NWScriptI::tan(Ice::Float fValue, const Ice::Current& ice) {
  lock(tan_mutex, "tan");
  callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(70, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(tan_mutex, "tan");
  return fRetVal;
};

Ice::Int NWScriptI::testStringAgainstPattern(const std::string& sPattern, const std::string& sStringToTest, const Ice::Current& ice) {
  lock(testStringAgainstPattern_mutex, "testStringAgainstPattern");
  callCounter += 1;
  StackPushString(sStringToTest.c_str());
  StackPushString(sPattern.c_str());

  VM_ExecuteCommand(177, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(testStringAgainstPattern_mutex, "testStringAgainstPattern");
  return nRetVal;
};

NWN::AttackResult NWScriptI::touchAttackMelee(const NWN::NWObject& oTarget, bool bDisplayFeedback, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(touchAttackMelee_mutex, "touchAttackMelee");
  callCounter += 1;
  StackPushInteger(bDisplayFeedback == true ? 1 : 0);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(146, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(touchAttackMelee_mutex, "touchAttackMelee");
    return enum_long_2_AttackResult(nRetVal);
  
};

NWN::AttackResult NWScriptI::touchAttackRanged(const NWN::NWObject& oTarget, bool bDisplayFeedback, const Ice::Current& ice) {
  if (oTarget.id < 0 || oTarget.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(touchAttackRanged_mutex, "touchAttackRanged");
  callCounter += 1;
  StackPushInteger(bDisplayFeedback == true ? 1 : 0);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(147, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(touchAttackRanged_mutex, "touchAttackRanged");
    return enum_long_2_AttackResult(nRetVal);
  
};

Ice::Float NWScriptI::turnsToSeconds(Ice::Int nTurns, const Ice::Current& ice) {
  lock(turnsToSeconds_mutex, "turnsToSeconds");
  callCounter += 1;
  StackPushInteger(nTurns);

  VM_ExecuteCommand(123, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(turnsToSeconds_mutex, "turnsToSeconds");
  return fRetVal;
};

void NWScriptI::unpossessFamiliar(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(unpossessFamiliar_mutex, "unpossessFamiliar");
  callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(715, 1);

unlock(unpossessFamiliar_mutex, "unpossessFamiliar");
  
};

NWN::NWVector NWScriptI::vector(Ice::Float x, Ice::Float y, Ice::Float z, const Ice::Current& ice) {
  lock(vector_mutex, "vector");
  callCounter += 1;
  StackPushFloat(z);
  StackPushFloat(y);
  StackPushFloat(x);

  VM_ExecuteCommand(142, 3);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock(vector_mutex, "vector");
  return nv;
};

Ice::Float NWScriptI::vectorMagnitude(const NWN::NWVector& vVector, const Ice::Current& ice) {
  lock(vectorMagnitude_mutex, "vectorMagnitude");
  callCounter += 1;
  Vector vvVector;
  vvVector.X = vVector.x; vvVector.Y = vVector.y; vvVector.Z = vVector.z;
  StackPushVector(vvVector);

  VM_ExecuteCommand(104, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(vectorMagnitude_mutex, "vectorMagnitude");
  return fRetVal;
};

NWN::NWVector NWScriptI::vectorNormalize(const NWN::NWVector& vVector, const Ice::Current& ice) {
  lock(vectorNormalize_mutex, "vectorNormalize");
  callCounter += 1;
  Vector vvVector;
  vvVector.X = vVector.x; vvVector.Y = vVector.y; vvVector.Z = vVector.z;
  StackPushVector(vvVector);

  VM_ExecuteCommand(137, 1);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock(vectorNormalize_mutex, "vectorNormalize");
  return nv;
};

Ice::Float NWScriptI::vectorToAngle(const NWN::NWVector& vVector, const Ice::Current& ice) {
  lock(vectorToAngle_mutex, "vectorToAngle");
  callCounter += 1;
  Vector vvVector;
  vvVector.X = vVector.x; vvVector.Y = vVector.y; vvVector.Z = vVector.z;
  StackPushVector(vvVector);

  VM_ExecuteCommand(145, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(vectorToAngle_mutex, "vectorToAngle");
  return fRetVal;
};

NWN::NWEffect NWScriptI::versusAlignmentEffect(const NWN::NWEffect& eEffect, Ice::Int nLawChaos, Ice::Int nGoodEvil, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(versusAlignmentEffect_mutex, "versusAlignmentEffect");
  callCounter += 1;
  StackPushInteger(nGoodEvil);
  StackPushInteger(nLawChaos);
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(355, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(versusAlignmentEffect_mutex, "versusAlignmentEffect");
  return e;
};

NWN::NWEffect NWScriptI::versusRacialTypeEffect(const NWN::NWEffect& eEffect, NWN::RacialType tRacialType, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(versusRacialTypeEffect_mutex, "versusRacialTypeEffect");
  callCounter += 1;
  StackPushInteger(enum_RacialType_2_long(tRacialType));
  
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(356, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(versusRacialTypeEffect_mutex, "versusRacialTypeEffect");
  return e;
};

NWN::NWEffect NWScriptI::versusTrapEffect(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
  if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock(versusTrapEffect_mutex, "versusTrapEffect");
  callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(357, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWEffect e;
  for (iter = effectMap.begin(); iter != effectMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { effectMap[lastEffectId] = pRetVal; id = lastEffectId; lastEffectId += 1; }
  e.id = id;
  e.tDurationType = getEffectDurationType(e, ice);
  e.tType = getEffectType(e, ice);
  e.tTrueType = enum_long_2_EffectTrueType(pRetVal->Type);
  e.tSubType = getEffectSubType(e, ice);
  e.tCreator = getEffectCreator(e, ice);
  e.tSpellId = getEffectSpellId(e, ice);
  unlock(versusTrapEffect_mutex, "versusTrapEffect");
  return e;
};

NWN::SavingThrowResult NWScriptI::willSave(const NWN::NWObject& oCreature, Ice::Int nDC, NWN::SaveType tSaveType, const NWN::NWObject& oSaveVersus, const Ice::Current& ice) {
  if (oCreature.id < 0 || oCreature.id > 0xffffffff) throw NWN::InvalidObjectException();
  if (oSaveVersus.id < 0 || oSaveVersus.id > 0xffffffff) throw NWN::InvalidObjectException();
  lock(willSave_mutex, "willSave");
  callCounter += 1;
  StackPushObject(oSaveVersus.id);
  StackPushInteger(enum_SaveType_2_long(tSaveType));
  
  StackPushInteger(nDC);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(110, 4);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock(willSave_mutex, "willSave");
    return enum_long_2_SavingThrowResult(nRetVal);
  
};

void NWScriptI::writeTimestampedLogEntry(const std::string& sLogEntry, const Ice::Current& ice) {
  lock(writeTimestampedLogEntry_mutex, "writeTimestampedLogEntry");
  callCounter += 1;
  StackPushString(sLogEntry.c_str());

  VM_ExecuteCommand(560, 1);

unlock(writeTimestampedLogEntry_mutex, "writeTimestampedLogEntry");
  
};

Ice::Float NWScriptI::yardsToMeters(Ice::Float fYards, const Ice::Current& ice) {
  lock(yardsToMeters_mutex, "yardsToMeters");
  callCounter += 1;
  StackPushFloat(fYards);

  VM_ExecuteCommand(219, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock(yardsToMeters_mutex, "yardsToMeters");
  return fRetVal;
};


void NWScriptI::setDebugLogging(bool what, const Ice::Current& ice) {
  printEvents = what;
};

Ice::Long NWScriptI::getInstructionCount(const Ice::Current& ice) {
  return callCounter;
};

NWN::NWObjectSeq NWScriptI::allPCs(const Ice::Current& ice) {
  NWN::NWObjectSeq p;
  innerLock("allPCs");
  NWN::NWObject pc = getFirstPC(ice);
  while (getIsObjectValid(pc, ice)) {
    p.push_back(pc);
    pc = getNextPC(ice);
  }
  innerUnlock("allPCs");
  return p;
};

NWN::NWEffectSeq NWScriptI::allEffects(const NWN::NWObject& o, const Ice::Current& ice) {
  NWN::NWEffectSeq p;
  innerLock("allEffects");
  NWN::NWEffect e = getFirstEffect(o, ice);
  while (getIsEffectValid(e, ice)) {
    p.push_back(e);
    e = getNextEffect(o, ice);
  }
  innerUnlock("allEffects");
  return p;
};

NWN::NWObjectSeq NWScriptI::allInArea(const NWN::NWObject& area, const Ice::Current& ice) {
  NWN::NWObjectSeq p;
  innerLock("allInArea");
  NWN::NWObject pc = getFirstObjectInArea(area, ice);
  while (getIsObjectValid(pc, ice)) {
    p.push_back(pc);
    pc = getNextObjectInArea(area, ice);
  }
  innerUnlock("allInArea");
  return p;
};

NWN::NWObjectSeq NWScriptI::allByTag(const std::string& tag, const Ice::Current& ice) {
  NWN::NWObjectSeq p;
  innerLock("allByTag");
  int i = 0;
  NWN::NWObject pc = getObjectByTag(tag, i, ice);
  while (getIsObjectValid(pc, ice)) {
    p.push_back(pc);
    i++;
    pc = getObjectByTag(tag, i, ice);
  }
  innerUnlock("allByTag");
  return p;
};


NWN::NWObjectSeq NWScriptI::allInFaction(const NWN::NWObject& memberOf, bool bPCOnly, const Ice::Current& ice) {
  NWN::NWObjectSeq p;
  innerLock("allInFaction");
  NWN::NWObject pc = getFirstFactionMember(memberOf, bPCOnly, ice);
  while (getIsObjectValid(pc, ice)) {
    p.push_back(pc);
    pc = getNextFactionMember(memberOf, bPCOnly, ice);
  }
  innerUnlock("allInFaction");
  return p;
};


NWN::NWObjectSeq NWScriptI::allInShape(NWN::ShapeType shape, Ice::Float size,
    const NWN::NWLocation& location, bool lineOfSight, NWN::ObjectType objType,
    const NWN::NWVector& origin, const Ice::Current& ice) {
  NWN::NWObjectSeq p;
  innerLock("allInShape");
  int ot = enum_ObjectType_2_long(objType);
  NWN::NWObject o = getFirstObjectInShape(shape, size, location, lineOfSight,
    ot, origin, ice);
  while (getIsObjectValid(o, ice)) {
    p.push_back(o);
    o = getNextObjectInShape(shape, size, location, lineOfSight, ot, origin, ice);
  }
  innerUnlock("allInShape");
  return p;
};


NWN::NWObjectSeq NWScriptI::allInInventory(const NWN::NWObject& cr, const Ice::Current& ice) {
  NWN::NWObjectSeq p;
  NWN::NWObject i;
  innerLock("allInInventory");
  i = getFirstItemInInventory(cr, ice);
  while (getIsObjectValid(i, ice)) {
    p.push_back(i);
    i = getNextItemInInventory(cr, ice);
  }
  innerUnlock("allInInventory");
  return p;
};

NWN::NWCreatureEquipped NWScriptI::allEquipped(const NWN::NWObject& cr, const Ice::Current& ice) {
  NWN::NWCreatureEquipped r;
  NWN::NWObject i;
  NWN::NWObjectSeq p;
  innerLock("allEquipped");

  i = getItemInSlot(NWN::CreatureBiteSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.CreatureBiteSlot = i;
i = getItemInSlot(NWN::LefthandSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.LefthandSlot = i;
i = getItemInSlot(NWN::ArrowsSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.ArrowsSlot = i;
i = getItemInSlot(NWN::HeadSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.HeadSlot = i;
i = getItemInSlot(NWN::CreatureArmorSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.CreatureArmorSlot = i;
i = getItemInSlot(NWN::CloakSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.CloakSlot = i;
i = getItemInSlot(NWN::BulletsSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.BulletsSlot = i;
i = getItemInSlot(NWN::ChestSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.ChestSlot = i;
i = getItemInSlot(NWN::LeftringSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.LeftringSlot = i;
i = getItemInSlot(NWN::BoltsSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.BoltsSlot = i;
i = getItemInSlot(NWN::BootsSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.BootsSlot = i;
i = getItemInSlot(NWN::RightringSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.RightringSlot = i;
i = getItemInSlot(NWN::CreatureLefthandSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.CreatureLefthandSlot = i;
i = getItemInSlot(NWN::ArmsSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.ArmsSlot = i;
i = getItemInSlot(NWN::NeckSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.NeckSlot = i;
i = getItemInSlot(NWN::CreatureRighthandSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.CreatureRighthandSlot = i;
i = getItemInSlot(NWN::RighthandSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.RighthandSlot = i;
i = getItemInSlot(NWN::BeltSlot, cr, ice);
if (getIsObjectValid(i, ice)) p.push_back(i);
r.BeltSlot = i;
  innerUnlock("allEquipped");

  r.all = p;
  return r;
};

NWN::NWItemPropertySeq NWScriptI::allItemProperties(const NWN::NWObject& item, const Ice::Current& ice) {
  NWN::NWItemPropertySeq p;
  innerLock("allIP");
  NWN::NWItemProperty ip = getFirstItemProperty(item, ice);
  while (getIsItemPropertyValid(ip, ice)) {
    p.push_back(ip);
    ip = getNextItemProperty(item, ice);
  }
  innerUnlock("allIP");
  return p;
};


bool NWScriptI::getEffectIconShown(const NWN::NWEffect& eff, const Ice::Current& ice) {
  if (effectMap.find(eff.id) == effectMap.end())
    throw NWN::InvalidEffectException();
  CGameEffect *eff_ptr = effectMap.find(eff.id)->second;
  return eff_ptr->IsIconShown == 1;
};

void NWScriptI::setEffectIconShown(const NWN::NWEffect& eff, bool shown, const Ice::Current& ice) {
  if (effectMap.find(eff.id) == effectMap.end())
    throw NWN::InvalidEffectException();
  CGameEffect *eff_ptr = effectMap.find(eff.id)->second;
  eff_ptr->IsIconShown = shown ? 1 : 0;
};
bool NWScriptI::getEffectExposed(const NWN::NWEffect& eff, const Ice::Current& ice) {
  if (effectMap.find(eff.id) == effectMap.end())
    throw NWN::InvalidEffectException();
  CGameEffect *eff_ptr = effectMap.find(eff.id)->second;
  return eff_ptr->IsExposed == 1;
};

void NWScriptI::setEffectExposed(const NWN::NWEffect& eff, bool shown, const Ice::Current& ice) {
  if (effectMap.find(eff.id) == effectMap.end())
    throw NWN::InvalidEffectException();
  CGameEffect *eff_ptr = effectMap.find(eff.id)->second;
  eff_ptr->IsExposed = shown ? 1 : 0;
};

int NWScriptI::getEffectInteger(const NWN::NWEffect& eff, Ice::Int idx, const Ice::Current& ice) {
  if (idx < 0 || idx > 15)
    throw NWN::InvalidArgumentException("index not in 0 <= idx < 16");

  if (effectMap.find(eff.id) == effectMap.end())
    throw NWN::InvalidEffectException();
  CGameEffect *eff_ptr = effectMap.find(eff.id)->second;

  return eff_ptr->IntList[idx];
};
void NWScriptI::setEffectInteger(const NWN::NWEffect& eff, Ice::Int idx, Ice::Int value, const Ice::Current& ice) {
  if (idx < 0 || idx > 15)
    throw NWN::InvalidArgumentException("index not in 0 <= idx < 16");

  if (effectMap.find(eff.id) == effectMap.end())
    throw NWN::InvalidEffectException();
  CGameEffect *eff_ptr = effectMap.find(eff.id)->second;

  eff_ptr->IntList[idx] = value;
};

int NWScriptI::getItemPropertyInteger(const NWN::NWItemProperty& eff, Ice::Int idx, const Ice::Current& ice) {
  if (idx < 0 || idx > 15)
    throw NWN::InvalidArgumentException("index not in 0 <= idx < 16");

  if (iprpMap.find(eff.id) == iprpMap.end())
    throw NWN::InvalidItemPropertyException();
  CGameEffect *eff_ptr = iprpMap.find(eff.id)->second;

  return eff_ptr->IntList[idx];
};
void NWScriptI::setItemPropertyInteger(const NWN::NWItemProperty& eff, Ice::Int idx, Ice::Int value, const Ice::Current& ice) {
  if (idx < 0 || idx > 15)
    throw NWN::InvalidArgumentException("index not in 0 <= idx < 16");

  if (iprpMap.find(eff.id) == iprpMap.end())
    throw NWN::InvalidItemPropertyException();
  CGameEffect *eff_ptr = iprpMap.find(eff.id)->second;

  eff_ptr->IntList[idx] = value;
};

Ice::Float NWScriptI::getEffectDuration(const NWN::NWEffect& eff, const Ice::Current& ice) {
  if (effectMap.find(eff.id) == effectMap.end())
    throw NWN::InvalidEffectException();
  CGameEffect *eff_ptr = effectMap.find(eff.id)->second;

  return eff_ptr->Duration;
};
Ice::Float NWScriptI::getItemPropertyDuration(const NWN::NWItemProperty& eff, const Ice::Current& ice) {
  if (iprpMap.find(eff.id) == iprpMap.end())
    throw NWN::InvalidEffectException();
  CGameEffect *eff_ptr = iprpMap.find(eff.id)->second;

  return eff_ptr->Duration;
};

void NWScriptI::setEffectTrueType(const NWN::NWEffect& eff, NWN::EffectTrueType t, const Ice::Current& ice) {
  if (effectMap.find(eff.id) == effectMap.end())
    throw NWN::InvalidEffectException();
  CGameEffect *eff_ptr = effectMap.find(eff.id)->second;

  eff_ptr->Type = enum_EffectTrueType_2_long(t);
};

