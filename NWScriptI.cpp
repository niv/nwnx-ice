// Generated on Fri Aug 14 13:43:27 +0200 2009 from /home/elven/code/nwnx2-linux/trunk/plugins/ice/build/funcs.nss

#include "NWScriptI.h"
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;

NWScriptI::NWScriptI() {
  callCounter = 0;
  lockingEnabled = true;
  inContext = false;
  lastEffectId = 0; lastIprpId = 0;
}

void NWScriptI::resetPerEventMappings() {
  effectMap.clear();
  iprpMap.clear();
}

void NWScriptI::lock(const char* name) {
  if (!inContext)
    throw NWN::NotInContextException();
  
  mutex.lock();
}

void NWScriptI::unlock(const char* name) {
  
  mutex.unlock();
}

void NWScriptI::innerLock(const char* name) {
  
}

void NWScriptI::innerUnlock(const char* name) {
  
}

Ice::Int NWScriptI::abs(Ice::Int nValue, const Ice::Current& ice) {
  lock("abs"); callCounter += 1;
  StackPushInteger(nValue);

  VM_ExecuteCommand(77, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("abs");
  return nRetVal;
};

Ice::Double NWScriptI::acos(Ice::Double fValue, const Ice::Current& ice) {
  lock("acos"); callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(71, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("acos");
  return fRetVal;
};

void NWScriptI::actionAttack(const NWN::NWObject& oAttackee, bool bPassive, const Ice::Current& ice) {
  lock("actionAttack"); callCounter += 1;
  StackPushInteger(bPassive == true ? 1 : 0);
  StackPushObject(oAttackee.id);

  VM_ExecuteCommand(37, 2);

unlock("actionAttack");
  
};

void NWScriptI::actionCastFakeSpellAtLocation(Ice::Int nSpell, const NWN::NWLocation& lTarget, NWN::ProjectilePathType tProjectilePathType, const Ice::Current& ice) {
  lock("actionCastFakeSpellAtLocation"); callCounter += 1;
  if (tProjectilePathType == NWN::DefaultPath) StackPushInteger(0);
   else if (tProjectilePathType == NWN::HomingPath) StackPushInteger(1);
   else if (tProjectilePathType == NWN::BallisticPath) StackPushInteger(2);
   else if (tProjectilePathType == NWN::HighBallisticPath) StackPushInteger(3);
   else if (tProjectilePathType == NWN::AcceleratingPath) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  CScriptLocation *lTarget_ptr;
  lTarget_ptr->X = lTarget.x;
  lTarget_ptr->Y = lTarget.y;
  lTarget_ptr->Z = lTarget.z;
  lTarget_ptr->OrientationX = lTarget.orientationX;
  lTarget_ptr->OrientationY = lTarget.orientationY;
  lTarget_ptr->OrientationZ = lTarget.orientationZ;
  lTarget_ptr->AreaID = lTarget.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTarget_ptr);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(502, 3);

unlock("actionCastFakeSpellAtLocation");
  
};

void NWScriptI::actionCastFakeSpellAtObject(Ice::Int nSpell, const NWN::NWObject& oTarget, NWN::ProjectilePathType tProjectilePathType, const Ice::Current& ice) {
  lock("actionCastFakeSpellAtObject"); callCounter += 1;
  if (tProjectilePathType == NWN::DefaultPath) StackPushInteger(0);
   else if (tProjectilePathType == NWN::HomingPath) StackPushInteger(1);
   else if (tProjectilePathType == NWN::BallisticPath) StackPushInteger(2);
   else if (tProjectilePathType == NWN::HighBallisticPath) StackPushInteger(3);
   else if (tProjectilePathType == NWN::AcceleratingPath) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oTarget.id);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(501, 3);

unlock("actionCastFakeSpellAtObject");
  
};

void NWScriptI::actionCastSpellAtLocation(Ice::Int nSpell, const NWN::NWLocation& lTargetLocation, NWN::MetaMagic tMetaMagic, bool bCheat, NWN::ProjectilePathType tProjectilePathType, bool bInstantSpell, const Ice::Current& ice) {
  lock("actionCastSpellAtLocation"); callCounter += 1;
  StackPushInteger(bInstantSpell == true ? 1 : 0);
  if (tProjectilePathType == NWN::DefaultPath) StackPushInteger(0);
   else if (tProjectilePathType == NWN::HomingPath) StackPushInteger(1);
   else if (tProjectilePathType == NWN::BallisticPath) StackPushInteger(2);
   else if (tProjectilePathType == NWN::HighBallisticPath) StackPushInteger(3);
   else if (tProjectilePathType == NWN::AcceleratingPath) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushInteger(bCheat == true ? 1 : 0);
  if (tMetaMagic == NWN::SilentMeta) StackPushInteger(16);
   else if (tMetaMagic == NWN::NoneMeta) StackPushInteger(0);
   else if (tMetaMagic == NWN::EmpowerMeta) StackPushInteger(1);
   else if (tMetaMagic == NWN::AnyMeta) StackPushInteger(255);
   else if (tMetaMagic == NWN::ExtendMeta) StackPushInteger(2);
   else if (tMetaMagic == NWN::QuickenMeta) StackPushInteger(8);
   else if (tMetaMagic == NWN::MaximizeMeta) StackPushInteger(4);
   else if (tMetaMagic == NWN::StillMeta) StackPushInteger(32);
   else throw "fail: invalid struct value passed, internal API error";
  CScriptLocation *lTargetLocation_ptr;
  lTargetLocation_ptr->X = lTargetLocation.x;
  lTargetLocation_ptr->Y = lTargetLocation.y;
  lTargetLocation_ptr->Z = lTargetLocation.z;
  lTargetLocation_ptr->OrientationX = lTargetLocation.orientationX;
  lTargetLocation_ptr->OrientationY = lTargetLocation.orientationY;
  lTargetLocation_ptr->OrientationZ = lTargetLocation.orientationZ;
  lTargetLocation_ptr->AreaID = lTargetLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTargetLocation_ptr);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(234, 6);

unlock("actionCastSpellAtLocation");
  
};

void NWScriptI::actionCastSpellAtObject(Ice::Int nSpell, const NWN::NWObject& oTarget, NWN::MetaMagic tMetaMagic, bool bCheat, Ice::Int nDomainLevel, NWN::ProjectilePathType tProjectilePathType, bool bInstantSpell, const Ice::Current& ice) {
  lock("actionCastSpellAtObject"); callCounter += 1;
  StackPushInteger(bInstantSpell == true ? 1 : 0);
  if (tProjectilePathType == NWN::DefaultPath) StackPushInteger(0);
   else if (tProjectilePathType == NWN::HomingPath) StackPushInteger(1);
   else if (tProjectilePathType == NWN::BallisticPath) StackPushInteger(2);
   else if (tProjectilePathType == NWN::HighBallisticPath) StackPushInteger(3);
   else if (tProjectilePathType == NWN::AcceleratingPath) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushInteger(nDomainLevel);
  StackPushInteger(bCheat == true ? 1 : 0);
  if (tMetaMagic == NWN::SilentMeta) StackPushInteger(16);
   else if (tMetaMagic == NWN::NoneMeta) StackPushInteger(0);
   else if (tMetaMagic == NWN::EmpowerMeta) StackPushInteger(1);
   else if (tMetaMagic == NWN::AnyMeta) StackPushInteger(255);
   else if (tMetaMagic == NWN::ExtendMeta) StackPushInteger(2);
   else if (tMetaMagic == NWN::QuickenMeta) StackPushInteger(8);
   else if (tMetaMagic == NWN::MaximizeMeta) StackPushInteger(4);
   else if (tMetaMagic == NWN::StillMeta) StackPushInteger(32);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oTarget.id);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(48, 7);

unlock("actionCastSpellAtObject");
  
};

void NWScriptI::actionCloseDoor(const NWN::NWObject& oDoor, const Ice::Current& ice) {
  lock("actionCloseDoor"); callCounter += 1;
  StackPushObject(oDoor.id);

  VM_ExecuteCommand(44, 1);

unlock("actionCloseDoor");
  
};

void NWScriptI::actionCounterSpell(const NWN::NWObject& oCounterSpellTarget, const Ice::Current& ice) {
  lock("actionCounterSpell"); callCounter += 1;
  StackPushObject(oCounterSpellTarget.id);

  VM_ExecuteCommand(566, 1);

unlock("actionCounterSpell");
  
};

void NWScriptI::actionEquipItem(const NWN::NWObject& oItem, NWN::InventorySlot tInventorySlot, const Ice::Current& ice) {
  lock("actionEquipItem"); callCounter += 1;
  if (tInventorySlot == NWN::CreatureBiteSlot) StackPushInteger(16);
   else if (tInventorySlot == NWN::LefthandSlot) StackPushInteger(5);
   else if (tInventorySlot == NWN::ArrowsSlot) StackPushInteger(11);
   else if (tInventorySlot == NWN::HeadSlot) StackPushInteger(0);
   else if (tInventorySlot == NWN::CreatureArmorSlot) StackPushInteger(17);
   else if (tInventorySlot == NWN::CloakSlot) StackPushInteger(6);
   else if (tInventorySlot == NWN::BulletsSlot) StackPushInteger(12);
   else if (tInventorySlot == NWN::ChestSlot) StackPushInteger(1);
   else if (tInventorySlot == NWN::LeftringSlot) StackPushInteger(7);
   else if (tInventorySlot == NWN::BoltsSlot) StackPushInteger(13);
   else if (tInventorySlot == NWN::BootsSlot) StackPushInteger(2);
   else if (tInventorySlot == NWN::RightringSlot) StackPushInteger(8);
   else if (tInventorySlot == NWN::CreatureLefthandSlot) StackPushInteger(14);
   else if (tInventorySlot == NWN::ArmsSlot) StackPushInteger(3);
   else if (tInventorySlot == NWN::NeckSlot) StackPushInteger(9);
   else if (tInventorySlot == NWN::CreatureRighthandSlot) StackPushInteger(15);
   else if (tInventorySlot == NWN::RighthandSlot) StackPushInteger(4);
   else if (tInventorySlot == NWN::BeltSlot) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oItem.id);

  VM_ExecuteCommand(32, 2);

unlock("actionEquipItem");
  
};

void NWScriptI::actionEquipMostDamagingMelee(const NWN::NWObject& oVersus, bool bOffHand, const Ice::Current& ice) {
  lock("actionEquipMostDamagingMelee"); callCounter += 1;
  StackPushInteger(bOffHand == true ? 1 : 0);
  StackPushObject(oVersus.id);

  VM_ExecuteCommand(399, 2);

unlock("actionEquipMostDamagingMelee");
  
};

void NWScriptI::actionEquipMostDamagingRanged(const NWN::NWObject& oVersus, const Ice::Current& ice) {
  lock("actionEquipMostDamagingRanged"); callCounter += 1;
  StackPushObject(oVersus.id);

  VM_ExecuteCommand(400, 1);

unlock("actionEquipMostDamagingRanged");
  
};

void NWScriptI::actionEquipMostEffectiveArmor(const Ice::Current& ice) {
  lock("actionEquipMostEffectiveArmor"); callCounter += 1;

  VM_ExecuteCommand(404, 0);

unlock("actionEquipMostEffectiveArmor");
  
};

void NWScriptI::actionExamine(const NWN::NWObject& oExamine, const Ice::Current& ice) {
  lock("actionExamine"); callCounter += 1;
  StackPushObject(oExamine.id);

  VM_ExecuteCommand(738, 1);

unlock("actionExamine");
  
};

void NWScriptI::actionForceFollowObject(const NWN::NWObject& oFollow, Ice::Double fFollowDistance, const Ice::Current& ice) {
  lock("actionForceFollowObject"); callCounter += 1;
  StackPushFloat(fFollowDistance);
  StackPushObject(oFollow.id);

  VM_ExecuteCommand(167, 2);

unlock("actionForceFollowObject");
  
};

void NWScriptI::actionForceMoveToLocation(const NWN::NWLocation& lDestination, bool bRun, Ice::Double fTimeout, const Ice::Current& ice) {
  lock("actionForceMoveToLocation"); callCounter += 1;
  StackPushFloat(fTimeout);
  StackPushInteger(bRun == true ? 1 : 0);
  CScriptLocation *lDestination_ptr;
  lDestination_ptr->X = lDestination.x;
  lDestination_ptr->Y = lDestination.y;
  lDestination_ptr->Z = lDestination.z;
  lDestination_ptr->OrientationX = lDestination.orientationX;
  lDestination_ptr->OrientationY = lDestination.orientationY;
  lDestination_ptr->OrientationZ = lDestination.orientationZ;
  lDestination_ptr->AreaID = lDestination.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lDestination_ptr);

  VM_ExecuteCommand(382, 3);

unlock("actionForceMoveToLocation");
  
};

void NWScriptI::actionForceMoveToObject(const NWN::NWObject& oMoveTo, bool bRun, Ice::Double fRange, Ice::Double fTimeout, const Ice::Current& ice) {
  lock("actionForceMoveToObject"); callCounter += 1;
  StackPushFloat(fTimeout);
  StackPushFloat(fRange);
  StackPushInteger(bRun == true ? 1 : 0);
  StackPushObject(oMoveTo.id);

  VM_ExecuteCommand(383, 4);

unlock("actionForceMoveToObject");
  
};

void NWScriptI::actionGiveItem(const NWN::NWObject& oItem, const NWN::NWObject& oGiveTo, const Ice::Current& ice) {
  lock("actionGiveItem"); callCounter += 1;
  StackPushObject(oGiveTo.id);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(135, 2);

unlock("actionGiveItem");
  
};

void NWScriptI::actionInteractObject(const NWN::NWObject& oPlaceable, const Ice::Current& ice) {
  lock("actionInteractObject"); callCounter += 1;
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(329, 1);

unlock("actionInteractObject");
  
};

void NWScriptI::actionJumpToLocation(const NWN::NWLocation& lLocation, const Ice::Current& ice) {
  lock("actionJumpToLocation"); callCounter += 1;
  CScriptLocation *lLocation_ptr;
  lLocation_ptr->X = lLocation.x;
  lLocation_ptr->Y = lLocation.y;
  lLocation_ptr->Z = lLocation.z;
  lLocation_ptr->OrientationX = lLocation.orientationX;
  lLocation_ptr->OrientationY = lLocation.orientationY;
  lLocation_ptr->OrientationZ = lLocation.orientationZ;
  lLocation_ptr->AreaID = lLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);

  VM_ExecuteCommand(214, 1);

unlock("actionJumpToLocation");
  
};

void NWScriptI::actionJumpToObject(const NWN::NWObject& oToJumpTo, bool bWalkStraightLineToPoint, const Ice::Current& ice) {
  lock("actionJumpToObject"); callCounter += 1;
  StackPushInteger(bWalkStraightLineToPoint == true ? 1 : 0);
  StackPushObject(oToJumpTo.id);

  VM_ExecuteCommand(196, 2);

unlock("actionJumpToObject");
  
};

void NWScriptI::actionLockObject(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("actionLockObject"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(484, 1);

unlock("actionLockObject");
  
};

void NWScriptI::actionMoveAwayFromLocation(const NWN::NWLocation& lMoveAwayFrom, bool bRun, Ice::Double fMoveAwayRange, const Ice::Current& ice) {
  lock("actionMoveAwayFromLocation"); callCounter += 1;
  StackPushFloat(fMoveAwayRange);
  StackPushInteger(bRun == true ? 1 : 0);
  CScriptLocation *lMoveAwayFrom_ptr;
  lMoveAwayFrom_ptr->X = lMoveAwayFrom.x;
  lMoveAwayFrom_ptr->Y = lMoveAwayFrom.y;
  lMoveAwayFrom_ptr->Z = lMoveAwayFrom.z;
  lMoveAwayFrom_ptr->OrientationX = lMoveAwayFrom.orientationX;
  lMoveAwayFrom_ptr->OrientationY = lMoveAwayFrom.orientationY;
  lMoveAwayFrom_ptr->OrientationZ = lMoveAwayFrom.orientationZ;
  lMoveAwayFrom_ptr->AreaID = lMoveAwayFrom.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lMoveAwayFrom_ptr);

  VM_ExecuteCommand(360, 3);

unlock("actionMoveAwayFromLocation");
  
};

void NWScriptI::actionMoveAwayFromObject(const NWN::NWObject& oFleeFrom, bool bRun, Ice::Double fMoveAwayRange, const Ice::Current& ice) {
  lock("actionMoveAwayFromObject"); callCounter += 1;
  StackPushFloat(fMoveAwayRange);
  StackPushInteger(bRun == true ? 1 : 0);
  StackPushObject(oFleeFrom.id);

  VM_ExecuteCommand(23, 3);

unlock("actionMoveAwayFromObject");
  
};

void NWScriptI::actionMoveToLocation(const NWN::NWLocation& lDestination, bool bRun, const Ice::Current& ice) {
  lock("actionMoveToLocation"); callCounter += 1;
  StackPushInteger(bRun == true ? 1 : 0);
  CScriptLocation *lDestination_ptr;
  lDestination_ptr->X = lDestination.x;
  lDestination_ptr->Y = lDestination.y;
  lDestination_ptr->Z = lDestination.z;
  lDestination_ptr->OrientationX = lDestination.orientationX;
  lDestination_ptr->OrientationY = lDestination.orientationY;
  lDestination_ptr->OrientationZ = lDestination.orientationZ;
  lDestination_ptr->AreaID = lDestination.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lDestination_ptr);

  VM_ExecuteCommand(21, 2);

unlock("actionMoveToLocation");
  
};

void NWScriptI::actionMoveToObject(const NWN::NWObject& oMoveTo, bool bRun, Ice::Double fRange, const Ice::Current& ice) {
  lock("actionMoveToObject"); callCounter += 1;
  StackPushFloat(fRange);
  StackPushInteger(bRun == true ? 1 : 0);
  StackPushObject(oMoveTo.id);

  VM_ExecuteCommand(22, 3);

unlock("actionMoveToObject");
  
};

void NWScriptI::actionOpenDoor(const NWN::NWObject& oDoor, const Ice::Current& ice) {
  lock("actionOpenDoor"); callCounter += 1;
  StackPushObject(oDoor.id);

  VM_ExecuteCommand(43, 1);

unlock("actionOpenDoor");
  
};

void NWScriptI::actionPauseConversation(const Ice::Current& ice) {
  lock("actionPauseConversation"); callCounter += 1;

  VM_ExecuteCommand(205, 0);

unlock("actionPauseConversation");
  
};

void NWScriptI::actionPickUpItem(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("actionPickUpItem"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(34, 1);

unlock("actionPickUpItem");
  
};

void NWScriptI::actionPlayAnimation(Ice::Int nAnimation, Ice::Double fSpeed, Ice::Double fDurationSeconds, const Ice::Current& ice) {
  lock("actionPlayAnimation"); callCounter += 1;
  StackPushFloat(fDurationSeconds);
  StackPushFloat(fSpeed);
  StackPushInteger(nAnimation);

  VM_ExecuteCommand(40, 3);

unlock("actionPlayAnimation");
  
};

void NWScriptI::actionPutDownItem(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("actionPutDownItem"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(35, 1);

unlock("actionPutDownItem");
  
};

void NWScriptI::actionRandomWalk(const Ice::Current& ice) {
  lock("actionRandomWalk"); callCounter += 1;

  VM_ExecuteCommand(20, 0);

unlock("actionRandomWalk");
  
};

void NWScriptI::actionRest(bool bCreatureToEnemyLineOfSightCheck, const Ice::Current& ice) {
  lock("actionRest"); callCounter += 1;
  StackPushInteger(bCreatureToEnemyLineOfSightCheck == true ? 1 : 0);

  VM_ExecuteCommand(402, 1);

unlock("actionRest");
  
};

void NWScriptI::actionResumeConversation(const Ice::Current& ice) {
  lock("actionResumeConversation"); callCounter += 1;

  VM_ExecuteCommand(206, 0);

unlock("actionResumeConversation");
  
};

void NWScriptI::actionSit(const NWN::NWObject& oChair, const Ice::Current& ice) {
  lock("actionSit"); callCounter += 1;
  StackPushObject(oChair.id);

  VM_ExecuteCommand(194, 1);

unlock("actionSit");
  
};

void NWScriptI::actionSpeakString(const std::string& sStringToSpeak, NWN::TalkVolume tTalkVolume, const Ice::Current& ice) {
  lock("actionSpeakString"); callCounter += 1;
  if (tTalkVolume == NWN::PartyVol) StackPushInteger(5);
   else if (tTalkVolume == NWN::TalkVol) StackPushInteger(0);
   else if (tTalkVolume == NWN::TellVol) StackPushInteger(6);
   else if (tTalkVolume == NWN::WhisperVol) StackPushInteger(1);
   else if (tTalkVolume == NWN::ShoutVol) StackPushInteger(2);
   else if (tTalkVolume == NWN::SilentTalkVol) StackPushInteger(3);
   else if (tTalkVolume == NWN::SilentShoutVol) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushString(sStringToSpeak.c_str());

  VM_ExecuteCommand(39, 2);

unlock("actionSpeakString");
  
};

void NWScriptI::actionSpeakStringByStrRef(Ice::Int nStrRef, NWN::TalkVolume tTalkVolume, const Ice::Current& ice) {
  lock("actionSpeakStringByStrRef"); callCounter += 1;
  if (tTalkVolume == NWN::PartyVol) StackPushInteger(5);
   else if (tTalkVolume == NWN::TalkVol) StackPushInteger(0);
   else if (tTalkVolume == NWN::TellVol) StackPushInteger(6);
   else if (tTalkVolume == NWN::WhisperVol) StackPushInteger(1);
   else if (tTalkVolume == NWN::ShoutVol) StackPushInteger(2);
   else if (tTalkVolume == NWN::SilentTalkVol) StackPushInteger(3);
   else if (tTalkVolume == NWN::SilentShoutVol) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(240, 2);

unlock("actionSpeakStringByStrRef");
  
};

void NWScriptI::actionStartConversation(const NWN::NWObject& oObjectToConverseWith, const std::string& sDialogResRef, bool bPrivateConversation, bool bPlayHello, const Ice::Current& ice) {
  lock("actionStartConversation"); callCounter += 1;
  StackPushInteger(bPlayHello == true ? 1 : 0);
  StackPushInteger(bPrivateConversation == true ? 1 : 0);
  StackPushString(sDialogResRef.c_str());
  StackPushObject(oObjectToConverseWith.id);

  VM_ExecuteCommand(204, 4);

unlock("actionStartConversation");
  
};

void NWScriptI::actionTakeItem(const NWN::NWObject& oItem, const NWN::NWObject& oTakeFrom, const Ice::Current& ice) {
  lock("actionTakeItem"); callCounter += 1;
  StackPushObject(oTakeFrom.id);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(136, 2);

unlock("actionTakeItem");
  
};

void NWScriptI::actionUnequipItem(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("actionUnequipItem"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(33, 1);

unlock("actionUnequipItem");
  
};

void NWScriptI::actionUnlockObject(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("actionUnlockObject"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(483, 1);

unlock("actionUnlockObject");
  
};

void NWScriptI::actionUseFeat(Ice::Int nFeat, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("actionUseFeat"); callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushInteger(nFeat);

  VM_ExecuteCommand(287, 2);

unlock("actionUseFeat");
  
};

void NWScriptI::actionUseSkill(Ice::Int nSkill, const NWN::NWObject& oTarget, Ice::Int nSubSkill, const NWN::NWObject& oItemUsed, const Ice::Current& ice) {
  lock("actionUseSkill"); callCounter += 1;
  StackPushObject(oItemUsed.id);
  StackPushInteger(nSubSkill);
  StackPushObject(oTarget.id);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(288, 4);

unlock("actionUseSkill");
  
};

void NWScriptI::actionWait(Ice::Double fSeconds, const Ice::Current& ice) {
  lock("actionWait"); callCounter += 1;
  StackPushFloat(fSeconds);

  VM_ExecuteCommand(202, 1);

unlock("actionWait");
  
};

void NWScriptI::activatePortal(const NWN::NWObject& oTarget, const std::string& sIPaddress, const std::string& sPassword, const std::string& sWaypointTag, bool bSeemless, const Ice::Current& ice) {
  lock("activatePortal"); callCounter += 1;
  StackPushInteger(bSeemless == true ? 1 : 0);
  StackPushString(sWaypointTag.c_str());
  StackPushString(sPassword.c_str());
  StackPushString(sIPaddress.c_str());
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(474, 5);

unlock("activatePortal");
  
};

void NWScriptI::addHenchman(const NWN::NWObject& oMaster, const NWN::NWObject& oHenchman, const Ice::Current& ice) {
  lock("addHenchman"); callCounter += 1;
  StackPushObject(oHenchman.id);
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(365, 2);

unlock("addHenchman");
  
};

void NWScriptI::addItemProperty(NWN::DurationType tDurationType, const NWN::NWItemProperty& ipProperty, const NWN::NWObject& oItem, Ice::Double fDuration, const Ice::Current& ice) {
if (iprpMap.find(ipProperty.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock("addItemProperty"); callCounter += 1;
  StackPushFloat(fDuration);
  StackPushObject(oItem.id);
  CGameEffect *ipProperty_ptr = iprpMap.find(ipProperty.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, ipProperty_ptr);
  if (tDurationType == NWN::Instant) StackPushInteger(0);
   else if (tDurationType == NWN::Temporary) StackPushInteger(1);
   else if (tDurationType == NWN::Permanent) StackPushInteger(2);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(609, 4);

unlock("addItemProperty");
  
};

void NWScriptI::addJournalQuestEntry(const std::string& szPlotID, Ice::Int nState, const NWN::NWObject& oCreature, bool bAllPartyMembers, bool bAllPlayers, bool bAllowOverrideHigher, const Ice::Current& ice) {
  lock("addJournalQuestEntry"); callCounter += 1;
  StackPushInteger(bAllowOverrideHigher == true ? 1 : 0);
  StackPushInteger(bAllPlayers == true ? 1 : 0);
  StackPushInteger(bAllPartyMembers == true ? 1 : 0);
  StackPushObject(oCreature.id);
  StackPushInteger(nState);
  StackPushString(szPlotID.c_str());

  VM_ExecuteCommand(367, 6);

unlock("addJournalQuestEntry");
  
};

void NWScriptI::addToParty(const NWN::NWObject& oPC, const NWN::NWObject& oPartyLeader, const Ice::Current& ice) {
  lock("addToParty"); callCounter += 1;
  StackPushObject(oPartyLeader.id);
  StackPushObject(oPC.id);

  VM_ExecuteCommand(572, 2);

unlock("addToParty");
  
};

void NWScriptI::adjustAlignment(const NWN::NWObject& oSubject, Ice::Int nAlignment, Ice::Int nShift, bool bAllPartyMembers, const Ice::Current& ice) {
  lock("adjustAlignment"); callCounter += 1;
  StackPushInteger(bAllPartyMembers == true ? 1 : 0);
  StackPushInteger(nShift);
  StackPushInteger(nAlignment);
  StackPushObject(oSubject.id);

  VM_ExecuteCommand(201, 4);

unlock("adjustAlignment");
  
};

void NWScriptI::adjustReputation(const NWN::NWObject& oTarget, const NWN::NWObject& oSourceFactionMember, Ice::Int nAdjustment, const Ice::Current& ice) {
  lock("adjustReputation"); callCounter += 1;
  StackPushInteger(nAdjustment);
  StackPushObject(oSourceFactionMember.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(209, 3);

unlock("adjustReputation");
  
};

void NWScriptI::ambientSoundChangeDay(const NWN::NWObject& oArea, Ice::Int nTrack, const Ice::Current& ice) {
  lock("ambientSoundChangeDay"); callCounter += 1;
  StackPushInteger(nTrack);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(435, 2);

unlock("ambientSoundChangeDay");
  
};

void NWScriptI::ambientSoundChangeNight(const NWN::NWObject& oArea, Ice::Int nTrack, const Ice::Current& ice) {
  lock("ambientSoundChangeNight"); callCounter += 1;
  StackPushInteger(nTrack);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(436, 2);

unlock("ambientSoundChangeNight");
  
};

void NWScriptI::ambientSoundPlay(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("ambientSoundPlay"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(433, 1);

unlock("ambientSoundPlay");
  
};

void NWScriptI::ambientSoundSetDayVolume(const NWN::NWObject& oArea, Ice::Int nVolume, const Ice::Current& ice) {
  lock("ambientSoundSetDayVolume"); callCounter += 1;
  StackPushInteger(nVolume);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(567, 2);

unlock("ambientSoundSetDayVolume");
  
};

void NWScriptI::ambientSoundSetNightVolume(const NWN::NWObject& oArea, Ice::Int nVolume, const Ice::Current& ice) {
  lock("ambientSoundSetNightVolume"); callCounter += 1;
  StackPushInteger(nVolume);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(568, 2);

unlock("ambientSoundSetNightVolume");
  
};

void NWScriptI::ambientSoundStop(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("ambientSoundStop"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(434, 1);

unlock("ambientSoundStop");
  
};

NWN::NWVector NWScriptI::angleToVector(Ice::Double fAngle, const Ice::Current& ice) {
  lock("angleToVector"); callCounter += 1;
  StackPushFloat(fAngle);

  VM_ExecuteCommand(144, 1);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock("angleToVector");
  return nv;
};

void NWScriptI::applyEffectAtLocation(NWN::DurationType tDurationType, const NWN::NWEffect& eEffect, const NWN::NWLocation& lLocation, Ice::Double fDuration, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("applyEffectAtLocation"); callCounter += 1;
  StackPushFloat(fDuration);
  CScriptLocation *lLocation_ptr;
  lLocation_ptr->X = lLocation.x;
  lLocation_ptr->Y = lLocation.y;
  lLocation_ptr->Z = lLocation.z;
  lLocation_ptr->OrientationX = lLocation.orientationX;
  lLocation_ptr->OrientationY = lLocation.orientationY;
  lLocation_ptr->OrientationZ = lLocation.orientationZ;
  lLocation_ptr->AreaID = lLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
  if (tDurationType == NWN::Instant) StackPushInteger(0);
   else if (tDurationType == NWN::Temporary) StackPushInteger(1);
   else if (tDurationType == NWN::Permanent) StackPushInteger(2);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(216, 4);

unlock("applyEffectAtLocation");
  
};

void NWScriptI::applyEffectToObject(NWN::DurationType tDurationType, const NWN::NWEffect& eEffect, const NWN::NWObject& oTarget, Ice::Double fDuration, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("applyEffectToObject"); callCounter += 1;
  StackPushFloat(fDuration);
  StackPushObject(oTarget.id);
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
  if (tDurationType == NWN::Instant) StackPushInteger(0);
   else if (tDurationType == NWN::Temporary) StackPushInteger(1);
   else if (tDurationType == NWN::Permanent) StackPushInteger(2);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(220, 4);

unlock("applyEffectToObject");
  
};

Ice::Double NWScriptI::asin(Ice::Double fValue, const Ice::Current& ice) {
  lock("asin"); callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(72, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("asin");
  return fRetVal;
};

Ice::Double NWScriptI::atan(Ice::Double fValue, const Ice::Current& ice) {
  lock("atan"); callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(73, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("atan");
  return fRetVal;
};

NWN::NWItemProperty NWScriptI::badBadReplaceMeThisDoesNothing(const Ice::Current& ice) {
  lock("badBadReplaceMeThisDoesNothing"); callCounter += 1;

  VM_ExecuteCommand(676, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("badBadReplaceMeThisDoesNothing");
  return e;
};

Ice::Int NWScriptI::beginConversation(const std::string& sResRef, const NWN::NWObject& oObjectToDialog, const Ice::Current& ice) {
  lock("beginConversation"); callCounter += 1;
  StackPushObject(oObjectToDialog.id);
  StackPushString(sResRef.c_str());

  VM_ExecuteCommand(255, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("beginConversation");
  return nRetVal;
};

void NWScriptI::blackScreen(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("blackScreen"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(698, 1);

unlock("blackScreen");
  
};

void NWScriptI::bootPC(const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("bootPC"); callCounter += 1;
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(565, 1);

unlock("bootPC");
  
};

void NWScriptI::changeFaction(const NWN::NWObject& oObjectToChangeFaction, const NWN::NWObject& oMemberOfFactionToJoin, const Ice::Current& ice) {
  lock("changeFaction"); callCounter += 1;
  StackPushObject(oMemberOfFactionToJoin.id);
  StackPushObject(oObjectToChangeFaction.id);

  VM_ExecuteCommand(173, 2);

unlock("changeFaction");
  
};

void NWScriptI::changeToStandardFaction(const NWN::NWObject& oCreatureToChange, NWN::StandardFaction tStandardFaction, const Ice::Current& ice) {
  lock("changeToStandardFaction"); callCounter += 1;
  if (tStandardFaction == NWN::Hostile) StackPushInteger(0);
   else if (tStandardFaction == NWN::Commoner) StackPushInteger(1);
   else if (tStandardFaction == NWN::Merchant) StackPushInteger(2);
   else if (tStandardFaction == NWN::Defender) StackPushInteger(3);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oCreatureToChange.id);

  VM_ExecuteCommand(412, 2);

unlock("changeToStandardFaction");
  
};

void NWScriptI::clearAllActions(bool bClearCombatState, const Ice::Current& ice) {
  lock("clearAllActions"); callCounter += 1;
  StackPushInteger(bClearCombatState == true ? 1 : 0);

  VM_ExecuteCommand(9, 1);

unlock("clearAllActions");
  
};

void NWScriptI::clearPersonalReputation(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  lock("clearPersonalReputation"); callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(389, 2);

unlock("clearPersonalReputation");
  
};

NWN::NWObject NWScriptI::copyItem(const NWN::NWObject& oItem, const NWN::NWObject& oTargetInventory, bool bCopyVars, const Ice::Current& ice) {
  lock("copyItem"); callCounter += 1;
  StackPushInteger(bCopyVars == true ? 1 : 0);
  StackPushObject(oTargetInventory.id);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(584, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("copyItem");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::copyItemAndModify(const NWN::NWObject& oItem, Ice::Int nType, Ice::Int nIndex, Ice::Int nNewValue, bool bCopyVars, const Ice::Current& ice) {
  lock("copyItemAndModify"); callCounter += 1;
  StackPushInteger(bCopyVars == true ? 1 : 0);
  StackPushInteger(nNewValue);
  StackPushInteger(nIndex);
  StackPushInteger(nType);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(731, 5);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("copyItemAndModify");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::copyObject(const NWN::NWObject& oSource, const NWN::NWLocation& locLocation, const NWN::NWObject& oOwner, const std::string& sNewTag, const Ice::Current& ice) {
  lock("copyObject"); callCounter += 1;
  StackPushString(sNewTag.c_str());
  StackPushObject(oOwner.id);
  CScriptLocation *locLocation_ptr;
  locLocation_ptr->X = locLocation.x;
  locLocation_ptr->Y = locLocation.y;
  locLocation_ptr->Z = locLocation.z;
  locLocation_ptr->OrientationX = locLocation.orientationX;
  locLocation_ptr->OrientationY = locLocation.orientationY;
  locLocation_ptr->OrientationZ = locLocation.orientationZ;
  locLocation_ptr->AreaID = locLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, locLocation_ptr);
  StackPushObject(oSource.id);

  VM_ExecuteCommand(600, 4);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("copyObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Double NWScriptI::cos(Ice::Double fValue, const Ice::Current& ice) {
  lock("cos"); callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(68, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("cos");
  return fRetVal;
};

NWN::NWObject NWScriptI::createItemOnObject(const std::string& sItemTemplate, const NWN::NWObject& oTarget, Ice::Int nStackSize, const std::string& sNewTag, const Ice::Current& ice) {
  lock("createItemOnObject"); callCounter += 1;
  StackPushString(sNewTag.c_str());
  StackPushInteger(nStackSize);
  StackPushObject(oTarget.id);
  StackPushString(sItemTemplate.c_str());

  VM_ExecuteCommand(31, 4);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("createItemOnObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::createObject(NWN::ObjectType tObjectType, const std::string& sTemplate, const NWN::NWLocation& lLocation, bool bUseAppearAnimation, const std::string& sNewTag, const Ice::Current& ice) {
  lock("createObject"); callCounter += 1;
  StackPushString(sNewTag.c_str());
  StackPushInteger(bUseAppearAnimation == true ? 1 : 0);
  CScriptLocation *lLocation_ptr;
  lLocation_ptr->X = lLocation.x;
  lLocation_ptr->Y = lLocation.y;
  lLocation_ptr->Z = lLocation.z;
  lLocation_ptr->OrientationX = lLocation.orientationX;
  lLocation_ptr->OrientationY = lLocation.orientationY;
  lLocation_ptr->OrientationZ = lLocation.orientationZ;
  lLocation_ptr->AreaID = lLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
  StackPushString(sTemplate.c_str());
  if (tObjectType == NWN::AOE) StackPushInteger(16);
   else if (tObjectType == NWN::InvalidObject) StackPushInteger(0);
   else if (tObjectType == NWN::Creature) StackPushInteger(1);
   else if (tObjectType == NWN::Store) StackPushInteger(128);
   else if (tObjectType == NWN::Item) StackPushInteger(2);
   else if (tObjectType == NWN::Door) StackPushInteger(8);
   else if (tObjectType == NWN::Encounter) StackPushInteger(256);
   else if (tObjectType == NWN::All) StackPushInteger(32767);
   else if (tObjectType == NWN::Placeable) StackPushInteger(64);
   else if (tObjectType == NWN::Trigger) StackPushInteger(4);
   else if (tObjectType == NWN::Waypoint) StackPushInteger(32);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(243, 5);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("createObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::createTrapAtLocation(Ice::Int nTrapType, const NWN::NWLocation& lLocation, Ice::Double fSize, const std::string& sTag, NWN::StandardFaction tStandardFaction, const std::string& sOnDisarmScript, const std::string& sOnTrapTriggeredScript, const Ice::Current& ice) {
  lock("createTrapAtLocation"); callCounter += 1;
  StackPushString(sOnTrapTriggeredScript.c_str());
  StackPushString(sOnDisarmScript.c_str());
  if (tStandardFaction == NWN::Hostile) StackPushInteger(0);
   else if (tStandardFaction == NWN::Commoner) StackPushInteger(1);
   else if (tStandardFaction == NWN::Merchant) StackPushInteger(2);
   else if (tStandardFaction == NWN::Defender) StackPushInteger(3);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushString(sTag.c_str());
  StackPushFloat(fSize);
  CScriptLocation *lLocation_ptr;
  lLocation_ptr->X = lLocation.x;
  lLocation_ptr->Y = lLocation.y;
  lLocation_ptr->Z = lLocation.z;
  lLocation_ptr->OrientationX = lLocation.orientationX;
  lLocation_ptr->OrientationY = lLocation.orientationY;
  lLocation_ptr->OrientationZ = lLocation.orientationZ;
  lLocation_ptr->AreaID = lLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
  StackPushInteger(nTrapType);

  VM_ExecuteCommand(809, 7);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("createTrapAtLocation");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

void NWScriptI::createTrapOnObject(Ice::Int nTrapType, const NWN::NWObject& oObject, NWN::StandardFaction tStandardFaction, const std::string& sOnDisarmScript, const std::string& sOnTrapTriggeredScript, const Ice::Current& ice) {
  lock("createTrapOnObject"); callCounter += 1;
  StackPushString(sOnTrapTriggeredScript.c_str());
  StackPushString(sOnDisarmScript.c_str());
  if (tStandardFaction == NWN::Hostile) StackPushInteger(0);
   else if (tStandardFaction == NWN::Commoner) StackPushInteger(1);
   else if (tStandardFaction == NWN::Merchant) StackPushInteger(2);
   else if (tStandardFaction == NWN::Defender) StackPushInteger(3);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oObject.id);
  StackPushInteger(nTrapType);

  VM_ExecuteCommand(810, 5);

unlock("createTrapOnObject");
  
};

Ice::Int NWScriptI::d10(Ice::Int nNumDice, const Ice::Current& ice) {
  lock("d10"); callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(100, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("d10");
  return nRetVal;
};

Ice::Int NWScriptI::d100(Ice::Int nNumDice, const Ice::Current& ice) {
  lock("d100"); callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(103, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("d100");
  return nRetVal;
};

Ice::Int NWScriptI::d12(Ice::Int nNumDice, const Ice::Current& ice) {
  lock("d12"); callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(101, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("d12");
  return nRetVal;
};

Ice::Int NWScriptI::d2(Ice::Int nNumDice, const Ice::Current& ice) {
  lock("d2"); callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(95, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("d2");
  return nRetVal;
};

Ice::Int NWScriptI::d20(Ice::Int nNumDice, const Ice::Current& ice) {
  lock("d20"); callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(102, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("d20");
  return nRetVal;
};

Ice::Int NWScriptI::d3(Ice::Int nNumDice, const Ice::Current& ice) {
  lock("d3"); callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(96, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("d3");
  return nRetVal;
};

Ice::Int NWScriptI::d4(Ice::Int nNumDice, const Ice::Current& ice) {
  lock("d4"); callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(97, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("d4");
  return nRetVal;
};

Ice::Int NWScriptI::d6(Ice::Int nNumDice, const Ice::Current& ice) {
  lock("d6"); callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(98, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("d6");
  return nRetVal;
};

Ice::Int NWScriptI::d8(Ice::Int nNumDice, const Ice::Current& ice) {
  lock("d8"); callCounter += 1;
  StackPushInteger(nNumDice);

  VM_ExecuteCommand(99, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("d8");
  return nRetVal;
};

void NWScriptI::dayToNight(const NWN::NWObject& oPlayer, Ice::Double fTransitionTime, const Ice::Current& ice) {
  lock("dayToNight"); callCounter += 1;
  StackPushFloat(fTransitionTime);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(750, 2);

unlock("dayToNight");
  
};

void NWScriptI::decrementRemainingFeatUses(const NWN::NWObject& oCreature, Ice::Int nFeat, const Ice::Current& ice) {
  lock("decrementRemainingFeatUses"); callCounter += 1;
  StackPushInteger(nFeat);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(580, 2);

unlock("decrementRemainingFeatUses");
  
};

void NWScriptI::decrementRemainingSpellUses(const NWN::NWObject& oCreature, Ice::Int nSpell, const Ice::Current& ice) {
  lock("decrementRemainingSpellUses"); callCounter += 1;
  StackPushInteger(nSpell);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(581, 2);

unlock("decrementRemainingSpellUses");
  
};

void NWScriptI::deleteCampaignVariable(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("deleteCampaignVariable"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(601, 3);

unlock("deleteCampaignVariable");
  
};

void NWScriptI::deleteLocalFloat(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  lock("deleteLocalFloat"); callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(266, 2);

unlock("deleteLocalFloat");
  
};

void NWScriptI::deleteLocalInt(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  lock("deleteLocalInt"); callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(265, 2);

unlock("deleteLocalInt");
  
};

void NWScriptI::deleteLocalLocation(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  lock("deleteLocalLocation"); callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(269, 2);

unlock("deleteLocalLocation");
  
};

void NWScriptI::deleteLocalObject(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  lock("deleteLocalObject"); callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(268, 2);

unlock("deleteLocalObject");
  
};

void NWScriptI::deleteLocalString(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  lock("deleteLocalString"); callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(267, 2);

unlock("deleteLocalString");
  
};

void NWScriptI::destroyCampaignDatabase(const std::string& sCampaignName, const Ice::Current& ice) {
  lock("destroyCampaignDatabase"); callCounter += 1;
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(594, 1);

unlock("destroyCampaignDatabase");
  
};

void NWScriptI::destroyObject(const NWN::NWObject& oDestroy, Ice::Double fDelay, const Ice::Current& ice) {
  lock("destroyObject"); callCounter += 1;
  StackPushFloat(fDelay);
  StackPushObject(oDestroy.id);

  VM_ExecuteCommand(241, 2);

unlock("destroyObject");
  
};

void NWScriptI::doDoorAction(const NWN::NWObject& oTargetDoor, NWN::DoorAction tDoorAction, const Ice::Current& ice) {
  lock("doDoorAction"); callCounter += 1;
  if (tDoorAction == NWN::OpenDoor) StackPushInteger(0);
   else if (tDoorAction == NWN::UnlockDoor) StackPushInteger(1);
   else if (tDoorAction == NWN::BashDoor) StackPushInteger(2);
   else if (tDoorAction == NWN::IgnoreDoor) StackPushInteger(3);
   else if (tDoorAction == NWN::KnockDoor) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oTargetDoor.id);

  VM_ExecuteCommand(338, 2);

unlock("doDoorAction");
  
};

void NWScriptI::doPlaceableObjectAction(const NWN::NWObject& oPlaceable, NWN::PlaceableAction tPlaceableAction, const Ice::Current& ice) {
  lock("doPlaceableObjectAction"); callCounter += 1;
  if (tPlaceableAction == NWN::UsePlaceable) StackPushInteger(0);
   else if (tPlaceableAction == NWN::UnlockPlaceable) StackPushInteger(1);
   else if (tPlaceableAction == NWN::BashPlaceable) StackPushInteger(2);
   else if (tPlaceableAction == NWN::KnockPlaceable) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(547, 2);

unlock("doPlaceableObjectAction");
  
};

void NWScriptI::doSinglePlayerAutoSave(const Ice::Current& ice) {
  lock("doSinglePlayerAutoSave"); callCounter += 1;

  VM_ExecuteCommand(512, 0);

unlock("doSinglePlayerAutoSave");
  
};

void NWScriptI::doWhirlwindAttack(bool bDisplayFeedback, bool bImproved, const Ice::Current& ice) {
  lock("doWhirlwindAttack"); callCounter += 1;
  StackPushInteger(bImproved == true ? 1 : 0);
  StackPushInteger(bDisplayFeedback == true ? 1 : 0);

  VM_ExecuteCommand(709, 2);

unlock("doWhirlwindAttack");
  
};

NWN::NWEffect NWScriptI::effectACDecrease(Ice::Int nValue, Ice::Int nModifyType, Ice::Int nDamageType, const Ice::Current& ice) {
  lock("effectACDecrease"); callCounter += 1;
  StackPushInteger(nDamageType);
  StackPushInteger(nModifyType);
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
  unlock("effectACDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectACIncrease(Ice::Int nValue, Ice::Int nModifyType, Ice::Int nDamageType, const Ice::Current& ice) {
  lock("effectACIncrease"); callCounter += 1;
  StackPushInteger(nDamageType);
  StackPushInteger(nModifyType);
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
  unlock("effectACIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectAbilityDecrease(NWN::Ability tAbility, Ice::Int nModifyBy, const Ice::Current& ice) {
  lock("effectAbilityDecrease"); callCounter += 1;
  StackPushInteger(nModifyBy);
  if (tAbility == NWN::Charisma) StackPushInteger(5);
   else if (tAbility == NWN::Strength) StackPushInteger(0);
   else if (tAbility == NWN::Dexterity) StackPushInteger(1);
   else if (tAbility == NWN::Constitution) StackPushInteger(2);
   else if (tAbility == NWN::Intelligence) StackPushInteger(3);
   else if (tAbility == NWN::Wisdom) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";

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
  unlock("effectAbilityDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectAbilityIncrease(NWN::Ability tAbility, Ice::Int nModifyBy, const Ice::Current& ice) {
  lock("effectAbilityIncrease"); callCounter += 1;
  StackPushInteger(nModifyBy);
  if (tAbility == NWN::Charisma) StackPushInteger(5);
   else if (tAbility == NWN::Strength) StackPushInteger(0);
   else if (tAbility == NWN::Dexterity) StackPushInteger(1);
   else if (tAbility == NWN::Constitution) StackPushInteger(2);
   else if (tAbility == NWN::Intelligence) StackPushInteger(3);
   else if (tAbility == NWN::Wisdom) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";

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
  unlock("effectAbilityIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectAppear(Ice::Int nAnimation, const Ice::Current& ice) {
  lock("effectAppear"); callCounter += 1;
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
  unlock("effectAppear");
  return e;
};

NWN::NWEffect NWScriptI::effectAreaOfEffect(Ice::Int nAreaEffectId, const std::string& sOnEnterScript, const std::string& sHeartbeatScript, const std::string& sOnExitScript, const Ice::Current& ice) {
  lock("effectAreaOfEffect"); callCounter += 1;
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
  unlock("effectAreaOfEffect");
  return e;
};

NWN::NWEffect NWScriptI::effectAttackDecrease(Ice::Int nPenalty, Ice::Int nModifierType, const Ice::Current& ice) {
  lock("effectAttackDecrease"); callCounter += 1;
  StackPushInteger(nModifierType);
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
  unlock("effectAttackDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectAttackIncrease(Ice::Int nBonus, Ice::Int nModifierType, const Ice::Current& ice) {
  lock("effectAttackIncrease"); callCounter += 1;
  StackPushInteger(nModifierType);
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
  unlock("effectAttackIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectBeam(Ice::Int nBeamVisualEffect, const NWN::NWObject& oEffector, Ice::Int nBodyPart, bool bMissEffect, const Ice::Current& ice) {
  lock("effectBeam"); callCounter += 1;
  StackPushInteger(bMissEffect == true ? 1 : 0);
  StackPushInteger(nBodyPart);
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
  unlock("effectBeam");
  return e;
};

NWN::NWEffect NWScriptI::effectBlindness(const Ice::Current& ice) {
  lock("effectBlindness"); callCounter += 1;

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
  unlock("effectBlindness");
  return e;
};

NWN::NWEffect NWScriptI::effectCharmed(const Ice::Current& ice) {
  lock("effectCharmed"); callCounter += 1;

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
  unlock("effectCharmed");
  return e;
};

NWN::NWEffect NWScriptI::effectConcealment(Ice::Int nPercentage, Ice::Int nMissType, const Ice::Current& ice) {
  lock("effectConcealment"); callCounter += 1;
  StackPushInteger(nMissType);
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
  unlock("effectConcealment");
  return e;
};

NWN::NWEffect NWScriptI::effectConfused(const Ice::Current& ice) {
  lock("effectConfused"); callCounter += 1;

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
  unlock("effectConfused");
  return e;
};

NWN::NWEffect NWScriptI::effectCurse(Ice::Int nStrMod, Ice::Int nDexMod, Ice::Int nConMod, Ice::Int nIntMod, Ice::Int nWisMod, Ice::Int nChaMod, const Ice::Current& ice) {
  lock("effectCurse"); callCounter += 1;
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
  unlock("effectCurse");
  return e;
};

NWN::NWEffect NWScriptI::effectCutsceneDominated(const Ice::Current& ice) {
  lock("effectCutsceneDominated"); callCounter += 1;

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
  unlock("effectCutsceneDominated");
  return e;
};

NWN::NWEffect NWScriptI::effectCutsceneGhost(const Ice::Current& ice) {
  lock("effectCutsceneGhost"); callCounter += 1;

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
  unlock("effectCutsceneGhost");
  return e;
};

NWN::NWEffect NWScriptI::effectCutsceneImmobilize(const Ice::Current& ice) {
  lock("effectCutsceneImmobilize"); callCounter += 1;

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
  unlock("effectCutsceneImmobilize");
  return e;
};

NWN::NWEffect NWScriptI::effectCutsceneParalyze(const Ice::Current& ice) {
  lock("effectCutsceneParalyze"); callCounter += 1;

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
  unlock("effectCutsceneParalyze");
  return e;
};

NWN::NWEffect NWScriptI::effectDamage(Ice::Int nDamageAmount, Ice::Int nDamageType, Ice::Int nDamagePower, const Ice::Current& ice) {
  lock("effectDamage"); callCounter += 1;
  StackPushInteger(nDamagePower);
  StackPushInteger(nDamageType);
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
  unlock("effectDamage");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageDecrease(Ice::Int nPenalty, Ice::Int nDamageType, const Ice::Current& ice) {
  lock("effectDamageDecrease"); callCounter += 1;
  StackPushInteger(nDamageType);
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
  unlock("effectDamageDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageImmunityDecrease(Ice::Int nDamageType, Ice::Int nPercentImmunity, const Ice::Current& ice) {
  lock("effectDamageImmunityDecrease"); callCounter += 1;
  StackPushInteger(nPercentImmunity);
  StackPushInteger(nDamageType);

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
  unlock("effectDamageImmunityDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageImmunityIncrease(Ice::Int nDamageType, Ice::Int nPercentImmunity, const Ice::Current& ice) {
  lock("effectDamageImmunityIncrease"); callCounter += 1;
  StackPushInteger(nPercentImmunity);
  StackPushInteger(nDamageType);

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
  unlock("effectDamageImmunityIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageIncrease(Ice::Int nBonus, Ice::Int nDamageType, const Ice::Current& ice) {
  lock("effectDamageIncrease"); callCounter += 1;
  StackPushInteger(nDamageType);
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
  unlock("effectDamageIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageReduction(Ice::Int nAmount, Ice::Int nDamagePower, Ice::Int nLimit, const Ice::Current& ice) {
  lock("effectDamageReduction"); callCounter += 1;
  StackPushInteger(nLimit);
  StackPushInteger(nDamagePower);
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
  unlock("effectDamageReduction");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageResistance(Ice::Int nDamageType, Ice::Int nAmount, Ice::Int nLimit, const Ice::Current& ice) {
  lock("effectDamageResistance"); callCounter += 1;
  StackPushInteger(nLimit);
  StackPushInteger(nAmount);
  StackPushInteger(nDamageType);

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
  unlock("effectDamageResistance");
  return e;
};

NWN::NWEffect NWScriptI::effectDamageShield(Ice::Int nDamageAmount, Ice::Int nRandomAmount, Ice::Int nDamageType, const Ice::Current& ice) {
  lock("effectDamageShield"); callCounter += 1;
  StackPushInteger(nDamageType);
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
  unlock("effectDamageShield");
  return e;
};

NWN::NWEffect NWScriptI::effectDarkness(const Ice::Current& ice) {
  lock("effectDarkness"); callCounter += 1;

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
  unlock("effectDarkness");
  return e;
};

NWN::NWEffect NWScriptI::effectDazed(const Ice::Current& ice) {
  lock("effectDazed"); callCounter += 1;

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
  unlock("effectDazed");
  return e;
};

NWN::NWEffect NWScriptI::effectDeaf(const Ice::Current& ice) {
  lock("effectDeaf"); callCounter += 1;

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
  unlock("effectDeaf");
  return e;
};

NWN::NWEffect NWScriptI::effectDeath(bool bSpectacularDeath, bool bDisplayFeedback, const Ice::Current& ice) {
  lock("effectDeath"); callCounter += 1;
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
  unlock("effectDeath");
  return e;
};

NWN::NWEffect NWScriptI::effectDisappear(Ice::Int nAnimation, const Ice::Current& ice) {
  lock("effectDisappear"); callCounter += 1;
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
  unlock("effectDisappear");
  return e;
};

NWN::NWEffect NWScriptI::effectDisappearAppear(const NWN::NWLocation& lLocation, Ice::Int nAnimation, const Ice::Current& ice) {
  lock("effectDisappearAppear"); callCounter += 1;
  StackPushInteger(nAnimation);
  CScriptLocation *lLocation_ptr;
  lLocation_ptr->X = lLocation.x;
  lLocation_ptr->Y = lLocation.y;
  lLocation_ptr->Z = lLocation.z;
  lLocation_ptr->OrientationX = lLocation.orientationX;
  lLocation_ptr->OrientationY = lLocation.orientationY;
  lLocation_ptr->OrientationZ = lLocation.orientationZ;
  lLocation_ptr->AreaID = lLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);

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
  unlock("effectDisappearAppear");
  return e;
};

NWN::NWEffect NWScriptI::effectDisease(Ice::Int nDiseaseType, const Ice::Current& ice) {
  lock("effectDisease"); callCounter += 1;
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
  unlock("effectDisease");
  return e;
};

NWN::NWEffect NWScriptI::effectDispelMagicAll(Ice::Int nCasterLevel, const Ice::Current& ice) {
  lock("effectDispelMagicAll"); callCounter += 1;
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
  unlock("effectDispelMagicAll");
  return e;
};

NWN::NWEffect NWScriptI::effectDispelMagicBest(Ice::Int nCasterLevel, const Ice::Current& ice) {
  lock("effectDispelMagicBest"); callCounter += 1;
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
  unlock("effectDispelMagicBest");
  return e;
};

NWN::NWEffect NWScriptI::effectDominated(const Ice::Current& ice) {
  lock("effectDominated"); callCounter += 1;

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
  unlock("effectDominated");
  return e;
};

NWN::NWEffect NWScriptI::effectEntangle(const Ice::Current& ice) {
  lock("effectEntangle"); callCounter += 1;

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
  unlock("effectEntangle");
  return e;
};

NWN::NWEffect NWScriptI::effectEthereal(const Ice::Current& ice) {
  lock("effectEthereal"); callCounter += 1;

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
  unlock("effectEthereal");
  return e;
};

NWN::NWEffect NWScriptI::effectFrightened(const Ice::Current& ice) {
  lock("effectFrightened"); callCounter += 1;

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
  unlock("effectFrightened");
  return e;
};

NWN::NWEffect NWScriptI::effectHaste(const Ice::Current& ice) {
  lock("effectHaste"); callCounter += 1;

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
  unlock("effectHaste");
  return e;
};

NWN::NWEffect NWScriptI::effectHeal(Ice::Int nDamageToHeal, const Ice::Current& ice) {
  lock("effectHeal"); callCounter += 1;
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
  unlock("effectHeal");
  return e;
};

NWN::NWEffect NWScriptI::effectHitPointChangeWhenDying(Ice::Double fHitPointChangePerRound, const Ice::Current& ice) {
  lock("effectHitPointChangeWhenDying"); callCounter += 1;
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
  unlock("effectHitPointChangeWhenDying");
  return e;
};

NWN::NWEffect NWScriptI::effectImmunity(Ice::Int nImmunityType, const Ice::Current& ice) {
  lock("effectImmunity"); callCounter += 1;
  StackPushInteger(nImmunityType);

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
  unlock("effectImmunity");
  return e;
};

NWN::NWEffect NWScriptI::effectInvisibility(Ice::Int nInvisibilityType, const Ice::Current& ice) {
  lock("effectInvisibility"); callCounter += 1;
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
  unlock("effectInvisibility");
  return e;
};

NWN::NWEffect NWScriptI::effectKnockdown(const Ice::Current& ice) {
  lock("effectKnockdown"); callCounter += 1;

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
  unlock("effectKnockdown");
  return e;
};

NWN::NWEffect NWScriptI::effectLinkEffects(const NWN::NWEffect& eChildEffect, const NWN::NWEffect& eParentEffect, const Ice::Current& ice) {
if (effectMap.find(eChildEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
if (effectMap.find(eParentEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("effectLinkEffects"); callCounter += 1;
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
  unlock("effectLinkEffects");
  return e;
};

NWN::NWEffect NWScriptI::effectMissChance(Ice::Int nPercentage, Ice::Int nMissChanceType, const Ice::Current& ice) {
  lock("effectMissChance"); callCounter += 1;
  StackPushInteger(nMissChanceType);
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
  unlock("effectMissChance");
  return e;
};

NWN::NWEffect NWScriptI::effectModifyAttacks(Ice::Int nAttacks, const Ice::Current& ice) {
  lock("effectModifyAttacks"); callCounter += 1;
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
  unlock("effectModifyAttacks");
  return e;
};

NWN::NWEffect NWScriptI::effectMovementSpeedDecrease(Ice::Int nPercentChange, const Ice::Current& ice) {
  lock("effectMovementSpeedDecrease"); callCounter += 1;
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
  unlock("effectMovementSpeedDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectMovementSpeedIncrease(Ice::Int nPercentChange, const Ice::Current& ice) {
  lock("effectMovementSpeedIncrease"); callCounter += 1;
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
  unlock("effectMovementSpeedIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectNegativeLevel(Ice::Int nNumLevels, bool bHPBonus, const Ice::Current& ice) {
  lock("effectNegativeLevel"); callCounter += 1;
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
  unlock("effectNegativeLevel");
  return e;
};

NWN::NWEffect NWScriptI::effectParalyze(const Ice::Current& ice) {
  lock("effectParalyze"); callCounter += 1;

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
  unlock("effectParalyze");
  return e;
};

NWN::NWEffect NWScriptI::effectPetrify(const Ice::Current& ice) {
  lock("effectPetrify"); callCounter += 1;

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
  unlock("effectPetrify");
  return e;
};

NWN::NWEffect NWScriptI::effectPoison(Ice::Int nPoisonType, const Ice::Current& ice) {
  lock("effectPoison"); callCounter += 1;
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
  unlock("effectPoison");
  return e;
};

NWN::NWEffect NWScriptI::effectPolymorph(Ice::Int nPolymorphSelection, bool bLocked, const Ice::Current& ice) {
  lock("effectPolymorph"); callCounter += 1;
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
  unlock("effectPolymorph");
  return e;
};

NWN::NWEffect NWScriptI::effectRegenerate(Ice::Int nAmount, Ice::Double fIntervalSeconds, const Ice::Current& ice) {
  lock("effectRegenerate"); callCounter += 1;
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
  unlock("effectRegenerate");
  return e;
};

NWN::NWEffect NWScriptI::effectResurrection(const Ice::Current& ice) {
  lock("effectResurrection"); callCounter += 1;

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
  unlock("effectResurrection");
  return e;
};

NWN::NWEffect NWScriptI::effectSanctuary(Ice::Int nDifficultyClass, const Ice::Current& ice) {
  lock("effectSanctuary"); callCounter += 1;
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
  unlock("effectSanctuary");
  return e;
};

NWN::NWEffect NWScriptI::effectSavingThrowDecrease(Ice::Int nSave, Ice::Int nValue, NWN::SaveType tSaveType, const Ice::Current& ice) {
  lock("effectSavingThrowDecrease"); callCounter += 1;
  if (tSaveType == NWN::GoodSaveType) StackPushInteger(16);
   else if (tSaveType == NWN::SonicSaveType) StackPushInteger(5);
   else if (tSaveType == NWN::DeathSaveType) StackPushInteger(11);
   else if (tSaveType == NWN::AllOrNoneSaveType) StackPushInteger(0);
   else if (tSaveType == NWN::EvilSaveType) StackPushInteger(17);
   else if (tSaveType == NWN::AcidSaveType) StackPushInteger(6);
   else if (tSaveType == NWN::ColdSaveType) StackPushInteger(12);
   else if (tSaveType == NWN::MindSpellsSaveType) StackPushInteger(1);
   else if (tSaveType == NWN::LawSaveType) StackPushInteger(18);
   else if (tSaveType == NWN::FireSaveType) StackPushInteger(7);
   else if (tSaveType == NWN::DivineSaveType) StackPushInteger(13);
   else if (tSaveType == NWN::PoisonSaveType) StackPushInteger(2);
   else if (tSaveType == NWN::ChaosSaveType) StackPushInteger(19);
   else if (tSaveType == NWN::ElectricitySaveType) StackPushInteger(8);
   else if (tSaveType == NWN::TrapSaveType) StackPushInteger(14);
   else if (tSaveType == NWN::DiseaseSaveType) StackPushInteger(3);
   else if (tSaveType == NWN::PositiveSaveType) StackPushInteger(9);
   else if (tSaveType == NWN::SpellSaveType) StackPushInteger(15);
   else if (tSaveType == NWN::FearSaveType) StackPushInteger(4);
   else if (tSaveType == NWN::NegativeSaveType) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
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
  unlock("effectSavingThrowDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectSavingThrowIncrease(Ice::Int nSave, Ice::Int nValue, NWN::SaveType tSaveType, const Ice::Current& ice) {
  lock("effectSavingThrowIncrease"); callCounter += 1;
  if (tSaveType == NWN::GoodSaveType) StackPushInteger(16);
   else if (tSaveType == NWN::SonicSaveType) StackPushInteger(5);
   else if (tSaveType == NWN::DeathSaveType) StackPushInteger(11);
   else if (tSaveType == NWN::AllOrNoneSaveType) StackPushInteger(0);
   else if (tSaveType == NWN::EvilSaveType) StackPushInteger(17);
   else if (tSaveType == NWN::AcidSaveType) StackPushInteger(6);
   else if (tSaveType == NWN::ColdSaveType) StackPushInteger(12);
   else if (tSaveType == NWN::MindSpellsSaveType) StackPushInteger(1);
   else if (tSaveType == NWN::LawSaveType) StackPushInteger(18);
   else if (tSaveType == NWN::FireSaveType) StackPushInteger(7);
   else if (tSaveType == NWN::DivineSaveType) StackPushInteger(13);
   else if (tSaveType == NWN::PoisonSaveType) StackPushInteger(2);
   else if (tSaveType == NWN::ChaosSaveType) StackPushInteger(19);
   else if (tSaveType == NWN::ElectricitySaveType) StackPushInteger(8);
   else if (tSaveType == NWN::TrapSaveType) StackPushInteger(14);
   else if (tSaveType == NWN::DiseaseSaveType) StackPushInteger(3);
   else if (tSaveType == NWN::PositiveSaveType) StackPushInteger(9);
   else if (tSaveType == NWN::SpellSaveType) StackPushInteger(15);
   else if (tSaveType == NWN::FearSaveType) StackPushInteger(4);
   else if (tSaveType == NWN::NegativeSaveType) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
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
  unlock("effectSavingThrowIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectSeeInvisible(const Ice::Current& ice) {
  lock("effectSeeInvisible"); callCounter += 1;

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
  unlock("effectSeeInvisible");
  return e;
};

NWN::NWEffect NWScriptI::effectSilence(const Ice::Current& ice) {
  lock("effectSilence"); callCounter += 1;

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
  unlock("effectSilence");
  return e;
};

NWN::NWEffect NWScriptI::effectSkillDecrease(Ice::Int nSkill, Ice::Int nValue, const Ice::Current& ice) {
  lock("effectSkillDecrease"); callCounter += 1;
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
  unlock("effectSkillDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectSkillIncrease(Ice::Int nSkill, Ice::Int nValue, const Ice::Current& ice) {
  lock("effectSkillIncrease"); callCounter += 1;
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
  unlock("effectSkillIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectSleep(const Ice::Current& ice) {
  lock("effectSleep"); callCounter += 1;

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
  unlock("effectSleep");
  return e;
};

NWN::NWEffect NWScriptI::effectSlow(const Ice::Current& ice) {
  lock("effectSlow"); callCounter += 1;

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
  unlock("effectSlow");
  return e;
};

NWN::NWEffect NWScriptI::effectSpellFailure(Ice::Int nPercent, Ice::Int nSpellSchool, const Ice::Current& ice) {
  lock("effectSpellFailure"); callCounter += 1;
  StackPushInteger(nSpellSchool);
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
  unlock("effectSpellFailure");
  return e;
};

NWN::NWEffect NWScriptI::effectSpellImmunity(Ice::Int nImmunityToSpell, const Ice::Current& ice) {
  lock("effectSpellImmunity"); callCounter += 1;
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
  unlock("effectSpellImmunity");
  return e;
};

NWN::NWEffect NWScriptI::effectSpellLevelAbsorption(Ice::Int nMaxSpellLevelAbsorbed, Ice::Int nTotalSpellLevelsAbsorbed, Ice::Int nSpellSchool, const Ice::Current& ice) {
  lock("effectSpellLevelAbsorption"); callCounter += 1;
  StackPushInteger(nSpellSchool);
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
  unlock("effectSpellLevelAbsorption");
  return e;
};

NWN::NWEffect NWScriptI::effectSpellResistanceDecrease(Ice::Int nValue, const Ice::Current& ice) {
  lock("effectSpellResistanceDecrease"); callCounter += 1;
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
  unlock("effectSpellResistanceDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectSpellResistanceIncrease(Ice::Int nValue, const Ice::Current& ice) {
  lock("effectSpellResistanceIncrease"); callCounter += 1;
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
  unlock("effectSpellResistanceIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectStunned(const Ice::Current& ice) {
  lock("effectStunned"); callCounter += 1;

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
  unlock("effectStunned");
  return e;
};

NWN::NWEffect NWScriptI::effectSummonCreature(const std::string& sCreatureResref, Ice::Int nVisualEffectId, Ice::Double fDelaySeconds, bool bUseAppearAnimation, const Ice::Current& ice) {
  lock("effectSummonCreature"); callCounter += 1;
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
  unlock("effectSummonCreature");
  return e;
};

NWN::NWEffect NWScriptI::effectSwarm(Ice::Int nLooping, const std::string& sCreatureTemplate1, const std::string& sCreatureTemplate2, const std::string& sCreatureTemplate3, const std::string& sCreatureTemplate4, const Ice::Current& ice) {
  lock("effectSwarm"); callCounter += 1;
  StackPushString(sCreatureTemplate4.c_str());
  StackPushString(sCreatureTemplate3.c_str());
  StackPushString(sCreatureTemplate2.c_str());
  StackPushString(sCreatureTemplate1.c_str());
  StackPushInteger(nLooping);

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
  unlock("effectSwarm");
  return e;
};

NWN::NWEffect NWScriptI::effectTemporaryHitpoints(Ice::Int nHitPoints, const Ice::Current& ice) {
  lock("effectTemporaryHitpoints"); callCounter += 1;
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
  unlock("effectTemporaryHitpoints");
  return e;
};

NWN::NWEffect NWScriptI::effectTimeStop(const Ice::Current& ice) {
  lock("effectTimeStop"); callCounter += 1;

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
  unlock("effectTimeStop");
  return e;
};

NWN::NWEffect NWScriptI::effectTrueSeeing(const Ice::Current& ice) {
  lock("effectTrueSeeing"); callCounter += 1;

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
  unlock("effectTrueSeeing");
  return e;
};

NWN::NWEffect NWScriptI::effectTurnResistanceDecrease(Ice::Int nHitDice, const Ice::Current& ice) {
  lock("effectTurnResistanceDecrease"); callCounter += 1;
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
  unlock("effectTurnResistanceDecrease");
  return e;
};

NWN::NWEffect NWScriptI::effectTurnResistanceIncrease(Ice::Int nHitDice, const Ice::Current& ice) {
  lock("effectTurnResistanceIncrease"); callCounter += 1;
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
  unlock("effectTurnResistanceIncrease");
  return e;
};

NWN::NWEffect NWScriptI::effectTurned(const Ice::Current& ice) {
  lock("effectTurned"); callCounter += 1;

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
  unlock("effectTurned");
  return e;
};

NWN::NWEffect NWScriptI::effectUltravision(const Ice::Current& ice) {
  lock("effectUltravision"); callCounter += 1;

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
  unlock("effectUltravision");
  return e;
};

NWN::NWEffect NWScriptI::effectVisualEffect(Ice::Int nVisualEffectId, bool bMissEffect, const Ice::Current& ice) {
  lock("effectVisualEffect"); callCounter += 1;
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
  unlock("effectVisualEffect");
  return e;
};

void NWScriptI::endGame(const std::string& sEndMovie, const Ice::Current& ice) {
  lock("endGame"); callCounter += 1;
  StackPushString(sEndMovie.c_str());

  VM_ExecuteCommand(564, 1);

unlock("endGame");
  
};

void NWScriptI::executeScript(const std::string& sScript, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("executeScript"); callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushString(sScript.c_str());

  VM_ExecuteCommand(8, 2);

unlock("executeScript");
  
};

void NWScriptI::exploreAreaForPlayer(const NWN::NWObject& oArea, const NWN::NWObject& oPlayer, bool bExplored, const Ice::Current& ice) {
  lock("exploreAreaForPlayer"); callCounter += 1;
  StackPushInteger(bExplored == true ? 1 : 0);
  StackPushObject(oPlayer.id);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(403, 3);

unlock("exploreAreaForPlayer");
  
};

void NWScriptI::exportAllCharacters(const Ice::Current& ice) {
  lock("exportAllCharacters"); callCounter += 1;

  VM_ExecuteCommand(557, 0);

unlock("exportAllCharacters");
  
};

void NWScriptI::exportSingleCharacter(const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("exportSingleCharacter"); callCounter += 1;
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(719, 1);

unlock("exportSingleCharacter");
  
};

NWN::NWEffect NWScriptI::extraordinaryEffect(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("extraordinaryEffect"); callCounter += 1;
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
  unlock("extraordinaryEffect");
  return e;
};

Ice::Double NWScriptI::fabs(Ice::Double fValue, const Ice::Current& ice) {
  lock("fabs"); callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(67, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("fabs");
  return fRetVal;
};

void NWScriptI::fadeFromBlack(const NWN::NWObject& oCreature, Ice::Double fSpeed, const Ice::Current& ice) {
  lock("fadeFromBlack"); callCounter += 1;
  StackPushFloat(fSpeed);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(695, 2);

unlock("fadeFromBlack");
  
};

void NWScriptI::fadeToBlack(const NWN::NWObject& oCreature, Ice::Double fSpeed, const Ice::Current& ice) {
  lock("fadeToBlack"); callCounter += 1;
  StackPushFloat(fSpeed);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(696, 2);

unlock("fadeToBlack");
  
};

Ice::Double NWScriptI::feetToMeters(Ice::Double fFeet, const Ice::Current& ice) {
  lock("feetToMeters"); callCounter += 1;
  StackPushFloat(fFeet);

  VM_ExecuteCommand(218, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("feetToMeters");
  return fRetVal;
};

Ice::Int NWScriptI::findSubString(const std::string& sString, const std::string& sSubString, Ice::Int nStart, const Ice::Current& ice) {
  lock("findSubString"); callCounter += 1;
  StackPushInteger(nStart);
  StackPushString(sSubString.c_str());
  StackPushString(sString.c_str());

  VM_ExecuteCommand(66, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("findSubString");
  return nRetVal;
};

Ice::Int NWScriptI::floatToInt(Ice::Double fFloat, const Ice::Current& ice) {
  lock("floatToInt"); callCounter += 1;
  StackPushFloat(fFloat);

  VM_ExecuteCommand(231, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("floatToInt");
  return nRetVal;
};

std::string NWScriptI::floatToString(Ice::Double fFloat, Ice::Int nWidth, Ice::Int nDecimals, const Ice::Current& ice) {
  lock("floatToString"); callCounter += 1;
  StackPushInteger(nDecimals);
  StackPushInteger(nWidth);
  StackPushFloat(fFloat);

  VM_ExecuteCommand(3, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("floatToString");
  return std::string(sRetVal);
};

void NWScriptI::floatingTextStrRefOnCreature(Ice::Int nStrRefToDisplay, const NWN::NWObject& oCreatureToFloatAbove, bool bBroadcastToFaction, const Ice::Current& ice) {
  lock("floatingTextStrRefOnCreature"); callCounter += 1;
  StackPushInteger(bBroadcastToFaction == true ? 1 : 0);
  StackPushObject(oCreatureToFloatAbove.id);
  StackPushInteger(nStrRefToDisplay);

  VM_ExecuteCommand(525, 3);

unlock("floatingTextStrRefOnCreature");
  
};

void NWScriptI::floatingTextStringOnCreature(const std::string& sStringToDisplay, const NWN::NWObject& oCreatureToFloatAbove, bool bBroadcastToFaction, const Ice::Current& ice) {
  lock("floatingTextStringOnCreature"); callCounter += 1;
  StackPushInteger(bBroadcastToFaction == true ? 1 : 0);
  StackPushObject(oCreatureToFloatAbove.id);
  StackPushString(sStringToDisplay.c_str());

  VM_ExecuteCommand(526, 3);

unlock("floatingTextStringOnCreature");
  
};

void NWScriptI::forceRest(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("forceRest"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(775, 1);

unlock("forceRest");
  
};

NWN::SavingThrowResult NWScriptI::fortitudeSave(const NWN::NWObject& oCreature, Ice::Int nDC, NWN::SaveType tSaveType, const NWN::NWObject& oSaveVersus, const Ice::Current& ice) {
  lock("fortitudeSave"); callCounter += 1;
  StackPushObject(oSaveVersus.id);
  if (tSaveType == NWN::GoodSaveType) StackPushInteger(16);
   else if (tSaveType == NWN::SonicSaveType) StackPushInteger(5);
   else if (tSaveType == NWN::DeathSaveType) StackPushInteger(11);
   else if (tSaveType == NWN::AllOrNoneSaveType) StackPushInteger(0);
   else if (tSaveType == NWN::EvilSaveType) StackPushInteger(17);
   else if (tSaveType == NWN::AcidSaveType) StackPushInteger(6);
   else if (tSaveType == NWN::ColdSaveType) StackPushInteger(12);
   else if (tSaveType == NWN::MindSpellsSaveType) StackPushInteger(1);
   else if (tSaveType == NWN::LawSaveType) StackPushInteger(18);
   else if (tSaveType == NWN::FireSaveType) StackPushInteger(7);
   else if (tSaveType == NWN::DivineSaveType) StackPushInteger(13);
   else if (tSaveType == NWN::PoisonSaveType) StackPushInteger(2);
   else if (tSaveType == NWN::ChaosSaveType) StackPushInteger(19);
   else if (tSaveType == NWN::ElectricitySaveType) StackPushInteger(8);
   else if (tSaveType == NWN::TrapSaveType) StackPushInteger(14);
   else if (tSaveType == NWN::DiseaseSaveType) StackPushInteger(3);
   else if (tSaveType == NWN::PositiveSaveType) StackPushInteger(9);
   else if (tSaveType == NWN::SpellSaveType) StackPushInteger(15);
   else if (tSaveType == NWN::FearSaveType) StackPushInteger(4);
   else if (tSaveType == NWN::NegativeSaveType) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushInteger(nDC);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(108, 4);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("fortitudeSave");
  if (nRetVal == 0) return NWN::FailedRoll;
  if (nRetVal == 1) return NWN::SucceededRoll;
  if (nRetVal == 3) return NWN::ImmuneToSaveType;
  throw "Error: Unmapped enum return type";
};

std::string NWScriptI::get2DAString(const std::string& s2DA, const std::string& sColumn, Ice::Int nRow, const Ice::Current& ice) {
  lock("get2DAString"); callCounter += 1;
  StackPushInteger(nRow);
  StackPushString(sColumn.c_str());
  StackPushString(s2DA.c_str());

  VM_ExecuteCommand(710, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("get2DAString");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getAC(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getAC"); callCounter += 1;
  StackPushInteger(1);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(116, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getAC");
  return nRetVal;
};

Ice::Int NWScriptI::getAILevel(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getAILevel"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(712, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getAILevel");
  return nRetVal;
};

Ice::Int NWScriptI::getAbilityModifier(NWN::Ability tAbility, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getAbilityModifier"); callCounter += 1;
  StackPushObject(oCreature.id);
  if (tAbility == NWN::Charisma) StackPushInteger(5);
   else if (tAbility == NWN::Strength) StackPushInteger(0);
   else if (tAbility == NWN::Dexterity) StackPushInteger(1);
   else if (tAbility == NWN::Constitution) StackPushInteger(2);
   else if (tAbility == NWN::Intelligence) StackPushInteger(3);
   else if (tAbility == NWN::Wisdom) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(331, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getAbilityModifier");
  return nRetVal;
};

Ice::Int NWScriptI::getAbilityScore(const NWN::NWObject& oCreature, NWN::Ability tAbility, bool bBaseAbilityScore, const Ice::Current& ice) {
  lock("getAbilityScore"); callCounter += 1;
  StackPushInteger(bBaseAbilityScore == true ? 1 : 0);
  if (tAbility == NWN::Charisma) StackPushInteger(5);
   else if (tAbility == NWN::Strength) StackPushInteger(0);
   else if (tAbility == NWN::Dexterity) StackPushInteger(1);
   else if (tAbility == NWN::Constitution) StackPushInteger(2);
   else if (tAbility == NWN::Intelligence) StackPushInteger(3);
   else if (tAbility == NWN::Wisdom) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(139, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getAbilityScore");
  return nRetVal;
};

bool NWScriptI::getActionMode(const NWN::NWObject& oCreature, NWN::ActionMode tActionMode, const Ice::Current& ice) {
  lock("getActionMode"); callCounter += 1;
  if (tActionMode == NWN::CounterspellMode) StackPushInteger(5);
   else if (tActionMode == NWN::DirtyFightingMode) StackPushInteger(11);
   else if (tActionMode == NWN::DetectMode) StackPushInteger(0);
   else if (tActionMode == NWN::FlurryOfBlowsMode) StackPushInteger(6);
   else if (tActionMode == NWN::StealthMode) StackPushInteger(1);
   else if (tActionMode == NWN::RapidShotMode) StackPushInteger(7);
   else if (tActionMode == NWN::ParryMode) StackPushInteger(2);
   else if (tActionMode == NWN::ExpertiseMode) StackPushInteger(8);
   else if (tActionMode == NWN::PowerAttackMode) StackPushInteger(3);
   else if (tActionMode == NWN::ImprovedExpertiseMode) StackPushInteger(9);
   else if (tActionMode == NWN::ImprovedPowerAttackMode) StackPushInteger(4);
   else if (tActionMode == NWN::DefensiveCastMode) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(735, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getActionMode");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getAge(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getAge"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(495, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getAge");
  return nRetVal;
};

Ice::Int NWScriptI::getAlignmentGoodEvil(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getAlignmentGoodEvil"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(127, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getAlignmentGoodEvil");
  return nRetVal;
};

Ice::Int NWScriptI::getAlignmentLawChaos(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getAlignmentLawChaos"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(126, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getAlignmentLawChaos");
  return nRetVal;
};

Ice::Int NWScriptI::getAnimalCompanionCreatureType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getAnimalCompanionCreatureType"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(498, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getAnimalCompanionCreatureType");
  return nRetVal;
};

std::string NWScriptI::getAnimalCompanionName(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getAnimalCompanionName"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(500, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getAnimalCompanionName");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getAppearanceType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getAppearanceType"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(577, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getAppearanceType");
  return nRetVal;
};

Ice::Int NWScriptI::getArcaneSpellFailure(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getArcaneSpellFailure"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(737, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getArcaneSpellFailure");
  return nRetVal;
};

NWN::NWObject NWScriptI::getArea(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getArea"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(24, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getArea");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getAreaFromLocation(const NWN::NWLocation& lLocation, const Ice::Current& ice) {
  lock("getAreaFromLocation"); callCounter += 1;
  CScriptLocation *lLocation_ptr;
  lLocation_ptr->X = lLocation.x;
  lLocation_ptr->Y = lLocation.y;
  lLocation_ptr->Z = lLocation.z;
  lLocation_ptr->OrientationX = lLocation.orientationX;
  lLocation_ptr->OrientationY = lLocation.orientationY;
  lLocation_ptr->OrientationZ = lLocation.orientationZ;
  lLocation_ptr->AreaID = lLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);

  VM_ExecuteCommand(224, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getAreaFromLocation");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getAreaOfEffectCreator(const NWN::NWObject& oAreaOfEffectObject, const Ice::Current& ice) {
  lock("getAreaOfEffectCreator"); callCounter += 1;
  StackPushObject(oAreaOfEffectObject.id);

  VM_ExecuteCommand(264, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getAreaOfEffectCreator");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getAreaSize(Ice::Int nAreaDimension, const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("getAreaSize"); callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nAreaDimension);

  VM_ExecuteCommand(829, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getAreaSize");
  return nRetVal;
};

NWN::NWObject NWScriptI::getAssociate(NWN::AssociateType tAssociateType, const NWN::NWObject& oMaster, Ice::Int nTh, const Ice::Current& ice) {
  lock("getAssociate"); callCounter += 1;
  StackPushInteger(nTh);
  StackPushObject(oMaster.id);
  if (tAssociateType == NWN::DominatedAssociate) StackPushInteger(5);
   else if (tAssociateType == NWN::NoAssociate) StackPushInteger(0);
   else if (tAssociateType == NWN::HenchmanAssociate) StackPushInteger(1);
   else if (tAssociateType == NWN::AnimalCompanionAssociate) StackPushInteger(2);
   else if (tAssociateType == NWN::FamiliarAssociate) StackPushInteger(3);
   else if (tAssociateType == NWN::SummonedAssociate) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(364, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getAssociate");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::AssociateType NWScriptI::getAssociateType(const NWN::NWObject& oAssociate, const Ice::Current& ice) {
  lock("getAssociateType"); callCounter += 1;
  StackPushObject(oAssociate.id);

  VM_ExecuteCommand(748, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getAssociateType");
  if (nRetVal == 5) return NWN::DominatedAssociate;
  if (nRetVal == 0) return NWN::NoAssociate;
  if (nRetVal == 1) return NWN::HenchmanAssociate;
  if (nRetVal == 2) return NWN::AnimalCompanionAssociate;
  if (nRetVal == 3) return NWN::FamiliarAssociate;
  if (nRetVal == 4) return NWN::SummonedAssociate;
  throw "Error: Unmapped enum return type";
};

NWN::NWObject NWScriptI::getAttackTarget(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getAttackTarget"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(316, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getAttackTarget");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getAttemptedAttackTarget(const Ice::Current& ice) {
  lock("getAttemptedAttackTarget"); callCounter += 1;

  VM_ExecuteCommand(361, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getAttemptedAttackTarget");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getAttemptedSpellTarget(const Ice::Current& ice) {
  lock("getAttemptedSpellTarget"); callCounter += 1;

  VM_ExecuteCommand(375, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getAttemptedSpellTarget");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getBaseAttackBonus(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getBaseAttackBonus"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(699, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getBaseAttackBonus");
  return nRetVal;
};

Ice::Int NWScriptI::getBaseItemType(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getBaseItemType"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(397, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getBaseItemType");
  return nRetVal;
};

NWN::NWObject NWScriptI::getBlockingDoor(const Ice::Current& ice) {
  lock("getBlockingDoor"); callCounter += 1;

  VM_ExecuteCommand(336, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getBlockingDoor");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getCalendarDay(const Ice::Current& ice) {
  lock("getCalendarDay"); callCounter += 1;

  VM_ExecuteCommand(15, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCalendarDay");
  return nRetVal;
};

Ice::Int NWScriptI::getCalendarMonth(const Ice::Current& ice) {
  lock("getCalendarMonth"); callCounter += 1;

  VM_ExecuteCommand(14, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCalendarMonth");
  return nRetVal;
};

Ice::Int NWScriptI::getCalendarYear(const Ice::Current& ice) {
  lock("getCalendarYear"); callCounter += 1;

  VM_ExecuteCommand(13, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCalendarYear");
  return nRetVal;
};

Ice::Double NWScriptI::getCampaignFloat(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("getCampaignFloat"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(595, 3);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("getCampaignFloat");
  return fRetVal;
};

Ice::Int NWScriptI::getCampaignInt(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("getCampaignInt"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(596, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCampaignInt");
  return nRetVal;
};

NWN::NWLocation NWScriptI::getCampaignLocation(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("getCampaignLocation"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(598, 3);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.x = pRetVal->X;
  nl.y = pRetVal->X;
  nl.z = pRetVal->X;
  nl.orientationX = pRetVal->OrientationX;
  nl.orientationY = pRetVal->OrientationY;
  nl.orientationZ = pRetVal->OrientationZ;
  nl.area.id = pRetVal->AreaID;
  unlock("getCampaignLocation");
  return nl;
};

std::string NWScriptI::getCampaignString(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("getCampaignString"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(599, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getCampaignString");
  return std::string(sRetVal);
};

NWN::NWVector NWScriptI::getCampaignVector(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("getCampaignVector"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(597, 3);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock("getCampaignVector");
  return nv;
};

Ice::Int NWScriptI::getCasterLevel(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getCasterLevel"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(84, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCasterLevel");
  return nRetVal;
};

Ice::Double NWScriptI::getChallengeRating(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getChallengeRating"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(494, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("getChallengeRating");
  return fRetVal;
};

Ice::Int NWScriptI::getClassByPosition(Ice::Int nClassPosition, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getClassByPosition"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nClassPosition);

  VM_ExecuteCommand(341, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getClassByPosition");
  return nRetVal;
};

NWN::NWObject NWScriptI::getClickingObject(const Ice::Current& ice) {
  lock("getClickingObject"); callCounter += 1;

  VM_ExecuteCommand(326, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getClickingObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getColor(const NWN::NWObject& oObject, Ice::Int nColorChannel, const Ice::Current& ice) {
  lock("getColor"); callCounter += 1;
  StackPushInteger(nColorChannel);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(843, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getColor");
  return nRetVal;
};

bool NWScriptI::getCommandable(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getCommandable"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(163, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCommandable");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getCreatureBodyPart(Ice::Int nPart, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getCreatureBodyPart"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nPart);

  VM_ExecuteCommand(792, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCreatureBodyPart");
  return nRetVal;
};

NWN::CreatureSize NWScriptI::getCreatureSize(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getCreatureSize"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(479, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCreatureSize");
  if (nRetVal == 5) return NWN::HugeSize;
  if (nRetVal == 0) return NWN::InvalidSize;
  if (nRetVal == 1) return NWN::TinySize;
  if (nRetVal == 2) return NWN::SmallSize;
  if (nRetVal == 3) return NWN::MediumSize;
  if (nRetVal == 4) return NWN::LargeSize;
  throw "Error: Unmapped enum return type";
};

Ice::Int NWScriptI::getCreatureStartingPackage(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getCreatureStartingPackage"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(766, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCreatureStartingPackage");
  return nRetVal;
};

Ice::Int NWScriptI::getCreatureTailType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getCreatureTailType"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(794, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCreatureTailType");
  return nRetVal;
};

Ice::Int NWScriptI::getCreatureWingType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getCreatureWingType"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(790, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCreatureWingType");
  return nRetVal;
};

NWN::Action NWScriptI::getCurrentAction(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getCurrentAction"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(522, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCurrentAction");
  if (nRetVal == 16) return NWN::AnimalEmpathyAction;
  if (nRetVal == 5) return NWN::OpenDoorAction;
  if (nRetVal == 33) return NWN::HealAction;
  if (nRetVal == 11) return NWN::ExamineTrapAction;
  if (nRetVal == 0) return NWN::MoveToPointAction;
  if (nRetVal == 17) return NWN::RestAction;
  if (nRetVal == 6) return NWN::CloseDoorAction;
  if (nRetVal == 34) return NWN::PickpocketAction;
  if (nRetVal == 12) return NWN::SetTrapAction;
  if (nRetVal == 1) return NWN::PickupItemAction;
  if (nRetVal == 40) return NWN::SmiteGoodAction;
  if (nRetVal == 18) return NWN::TauntAction;
  if (nRetVal == 7) return NWN::DialogObjectAction;
  if (nRetVal == 35) return NWN::FollowAction;
  if (nRetVal == 13) return NWN::OpenLockAction;
  if (nRetVal == 2) return NWN::DropItemAction;
  if (nRetVal == 65535) return NWN::InvalidAction;
  if (nRetVal == 41) return NWN::KIDamageAction;
  if (nRetVal == 19) return NWN::ItemCastSpellAction;
  if (nRetVal == 8) return NWN::DisableTrapAction;
  if (nRetVal == 14) return NWN::LockAction;
  if (nRetVal == 3) return NWN::AttackObjectAction;
  if (nRetVal == 31) return NWN::CounterSpellAction;
  if (nRetVal == 9) return NWN::RecoverTrapAction;
  if (nRetVal == 37) return NWN::SitAction;
  if (nRetVal == 15) return NWN::UseObjectAction;
  if (nRetVal == 4) return NWN::CastSpellAction;
  if (nRetVal == 43) return NWN::RandomWalkAction;
  if (nRetVal == 10) return NWN::FlagTrapAction;
  throw "Error: Unmapped enum return type";
};

Ice::Int NWScriptI::getCurrentHitPoints(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getCurrentHitPoints"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(49, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCurrentHitPoints");
  return nRetVal;
};

Ice::Double NWScriptI::getCutsceneCameraMoveRate(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getCutsceneCameraMoveRate"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(742, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("getCutsceneCameraMoveRate");
  return fRetVal;
};

bool NWScriptI::getCutsceneMode(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getCutsceneMode"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(781, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getCutsceneMode");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getDamageDealtByType(Ice::Int nDamageType, const Ice::Current& ice) {
  lock("getDamageDealtByType"); callCounter += 1;
  StackPushInteger(nDamageType);

  VM_ExecuteCommand(344, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getDamageDealtByType");
  return nRetVal;
};

Ice::Int NWScriptI::getDefensiveCastingMode(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getDefensiveCastingMode"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(576, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getDefensiveCastingMode");
  return nRetVal;
};

std::string NWScriptI::getDeity(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getDeity"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(489, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getDeity");
  return std::string(sRetVal);
};

std::string NWScriptI::getDescription(const NWN::NWObject& oObject, bool bOriginalDescription, bool bIdentifiedDescription, const Ice::Current& ice) {
  lock("getDescription"); callCounter += 1;
  StackPushInteger(bIdentifiedDescription == true ? 1 : 0);
  StackPushInteger(bOriginalDescription == true ? 1 : 0);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(836, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getDescription");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getDetectMode(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getDetectMode"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(575, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getDetectMode");
  return nRetVal;
};

Ice::Double NWScriptI::getDialogSoundLength(Ice::Int nStrRef, const Ice::Current& ice) {
  lock("getDialogSoundLength"); callCounter += 1;
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(694, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("getDialogSoundLength");
  return fRetVal;
};

Ice::Double NWScriptI::getDistanceBetween(const NWN::NWObject& oObjectA, const NWN::NWObject& oObjectB, const Ice::Current& ice) {
  lock("getDistanceBetween"); callCounter += 1;
  StackPushObject(oObjectB.id);
  StackPushObject(oObjectA.id);

  VM_ExecuteCommand(151, 2);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("getDistanceBetween");
  return fRetVal;
};

Ice::Double NWScriptI::getDistanceBetweenLocations(const NWN::NWLocation& lLocationA, const NWN::NWLocation& lLocationB, const Ice::Current& ice) {
  lock("getDistanceBetweenLocations"); callCounter += 1;
  CScriptLocation *lLocationB_ptr;
  lLocationB_ptr->X = lLocationB.x;
  lLocationB_ptr->Y = lLocationB.y;
  lLocationB_ptr->Z = lLocationB.z;
  lLocationB_ptr->OrientationX = lLocationB.orientationX;
  lLocationB_ptr->OrientationY = lLocationB.orientationY;
  lLocationB_ptr->OrientationZ = lLocationB.orientationZ;
  lLocationB_ptr->AreaID = lLocationB.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocationB_ptr);
  CScriptLocation *lLocationA_ptr;
  lLocationA_ptr->X = lLocationA.x;
  lLocationA_ptr->Y = lLocationA.y;
  lLocationA_ptr->Z = lLocationA.z;
  lLocationA_ptr->OrientationX = lLocationA.orientationX;
  lLocationA_ptr->OrientationY = lLocationA.orientationY;
  lLocationA_ptr->OrientationZ = lLocationA.orientationZ;
  lLocationA_ptr->AreaID = lLocationA.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocationA_ptr);

  VM_ExecuteCommand(298, 2);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("getDistanceBetweenLocations");
  return fRetVal;
};

Ice::Double NWScriptI::getDistanceToObject(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getDistanceToObject"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(41, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("getDistanceToObject");
  return fRetVal;
};

bool NWScriptI::getDroppableFlag(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getDroppableFlag"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(586, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getDroppableFlag");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getEffectCreator(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("getEffectCreator"); callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(91, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getEffectCreator");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::DurationType NWScriptI::getEffectDurationType(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("getEffectDurationType"); callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(89, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getEffectDurationType");
  if (nRetVal == 0) return NWN::Instant;
  if (nRetVal == 1) return NWN::Temporary;
  if (nRetVal == 2) return NWN::Permanent;
  throw "Error: Unmapped enum return type";
};

Ice::Int NWScriptI::getEffectSpellId(const NWN::NWEffect& eSpellEffect, const Ice::Current& ice) {
if (effectMap.find(eSpellEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("getEffectSpellId"); callCounter += 1;
  CGameEffect *eSpellEffect_ptr = effectMap.find(eSpellEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eSpellEffect_ptr);

  VM_ExecuteCommand(305, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getEffectSpellId");
  return nRetVal;
};

NWN::EffectSubType NWScriptI::getEffectSubType(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("getEffectSubType"); callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(90, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getEffectSubType");
  if (nRetVal == 16) return NWN::SupernaturalSubType;
  if (nRetVal == 24) return NWN::ExtraordinarySubType;
  if (nRetVal == 8) return NWN::MagicalSubType;
  throw "Error: Unmapped enum return type";
};

NWN::EffectType NWScriptI::getEffectType(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("getEffectType"); callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(170, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getEffectType");
  if (nRetVal == 9) return NWN::TemporaryHitpointsEffect;
  if (nRetVal == 47) return NWN::ACDecreaseEffect;
  if (nRetVal == 28) return NWN::DazedEffect;
  if (nRetVal == 66) return NWN::TimestopEffect;
  if (nRetVal == 76) return NWN::SwarmEffect;
  if (nRetVal == 57) return NWN::ImprovedInvisibilityEffect;
  if (nRetVal == 0) return NWN::InvalidEffect;
  if (nRetVal == 38) return NWN::AbilityIncreaseEffect;
  if (nRetVal == 48) return NWN::MovementSpeedIncreaseEffect;
  if (nRetVal == 29) return NWN::StunnedEffect;
  if (nRetVal == 67) return NWN::BlindnessEffect;
  if (nRetVal == 77) return NWN::TurnResistanceDecreaseEffect;
  if (nRetVal == 20) return NWN::AreaOfEffectEffect;
  if (nRetVal == 58) return NWN::DarknessEffect;
  if (nRetVal == 1) return NWN::DamageResistanceEffect;
  if (nRetVal == 39) return NWN::AbilityDecreaseEffect;
  if (nRetVal == 30) return NWN::SleepEffect;
  if (nRetVal == 68) return NWN::SpellLevelAbsorptionEffect;
  if (nRetVal == 11) return NWN::EntangleEffect;
  if (nRetVal == 49) return NWN::MovementSpeedDecreaseEffect;
  if (nRetVal == 78) return NWN::TurnResistanceIncreaseEffect;
  if (nRetVal == 21) return NWN::BeamEffect;
  if (nRetVal == 59) return NWN::DispelMagicAllEffect;
  if (nRetVal == 40) return NWN::AttackIncreaseEffect;
  if (nRetVal == 31) return NWN::PoisonEffect;
  if (nRetVal == 69) return NWN::DispelMagicBestEffect;
  if (nRetVal == 12) return NWN::InvulnerableEffect;
  if (nRetVal == 50) return NWN::SavingThrowIncreaseEffect;
  if (nRetVal == 79) return NWN::PetrifyEffect;
  if (nRetVal == 3) return NWN::RegenerateEffect;
  if (nRetVal == 41) return NWN::AttackDecreaseEffect;
  if (nRetVal == 60) return NWN::ElementalShieldEffect;
  if (nRetVal == 32) return NWN::DiseaseEffect;
  if (nRetVal == 70) return NWN::UltravisionEffect;
  if (nRetVal == 13) return NWN::DeafEffect;
  if (nRetVal == 51) return NWN::SavingThrowDecreaseEffect;
  if (nRetVal == 80) return NWN::CutsceneParalyzeEffect;
  if (nRetVal == 42) return NWN::DamageIncreaseEffect;
  if (nRetVal == 23) return NWN::CharmedEffect;
  if (nRetVal == 61) return NWN::NegativeLevelEffect;
  if (nRetVal == 14) return NWN::ResurrectionEffect;
  if (nRetVal == 52) return NWN::SpellResistanceIncreaseEffect;
  if (nRetVal == 33) return NWN::CurseEffect;
  if (nRetVal == 71) return NWN::MissChanceEffect;
  if (nRetVal == 81) return NWN::EtherealEffect;
  if (nRetVal == 43) return NWN::DamageDecreaseEffect;
  if (nRetVal == 24) return NWN::ConfusedEffect;
  if (nRetVal == 62) return NWN::PolymorphEffect;
  if (nRetVal == 15) return NWN::ImmunityEffect;
  if (nRetVal == 53) return NWN::SpellResistanceDecreaseEffect;
  if (nRetVal == 34) return NWN::SilenceEffect;
  if (nRetVal == 72) return NWN::ConcealmentEffect;
  if (nRetVal == 82) return NWN::SpellFailureEffect;
  if (nRetVal == 25) return NWN::FrightenedEffect;
  if (nRetVal == 63) return NWN::SanctuaryEffect;
  if (nRetVal == 44) return NWN::DamageImmunityIncreaseEffect;
  if (nRetVal == 54) return NWN::SkillIncreaseEffect;
  if (nRetVal == 35) return NWN::TurnedEffect;
  if (nRetVal == 73) return NWN::SpellImmunityEffect;
  if (nRetVal == 83) return NWN::CutsceneGhostEffect;
  if (nRetVal == 26) return NWN::DominatedEffect;
  if (nRetVal == 64) return NWN::TrueSeeingEffect;
  if (nRetVal == 7) return NWN::DamageReductionEffect;
  if (nRetVal == 45) return NWN::DamageImmunityDecreaseEffect;
  if (nRetVal == 36) return NWN::HasteEffect;
  if (nRetVal == 74) return NWN::VisualEffect;
  if (nRetVal == 17) return NWN::EnemyAttackBonusEffect;
  if (nRetVal == 55) return NWN::SkillDecreaseEffect;
  if (nRetVal == 84) return NWN::CutsceneImmobilizeEffect;
  if (nRetVal == 65) return NWN::SeeInvisibleEffect;
  if (nRetVal == 46) return NWN::ACIncreaseEffect;
  if (nRetVal == 27) return NWN::ParalyzeEffect;
  if (nRetVal == 75) return NWN::DisappearAppearEffect;
  if (nRetVal == 37) return NWN::SlowEffect;
  if (nRetVal == 18) return NWN::ArcaneSpellFailureEffect;
  if (nRetVal == 56) return NWN::InvisibilityEffect;
  throw "Error: Unmapped enum return type";
};

Ice::Int NWScriptI::getEncounterActive(const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  lock("getEncounterActive"); callCounter += 1;
  StackPushObject(oEncounter.id);

  VM_ExecuteCommand(276, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getEncounterActive");
  return nRetVal;
};

Ice::Int NWScriptI::getEncounterDifficulty(const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  lock("getEncounterDifficulty"); callCounter += 1;
  StackPushObject(oEncounter.id);

  VM_ExecuteCommand(297, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getEncounterDifficulty");
  return nRetVal;
};

Ice::Int NWScriptI::getEncounterSpawnsCurrent(const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  lock("getEncounterSpawnsCurrent"); callCounter += 1;
  StackPushObject(oEncounter.id);

  VM_ExecuteCommand(280, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getEncounterSpawnsCurrent");
  return nRetVal;
};

Ice::Int NWScriptI::getEncounterSpawnsMax(const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  lock("getEncounterSpawnsMax"); callCounter += 1;
  StackPushObject(oEncounter.id);

  VM_ExecuteCommand(278, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getEncounterSpawnsMax");
  return nRetVal;
};

NWN::NWObject NWScriptI::getEnteringObject(const Ice::Current& ice) {
  lock("getEnteringObject"); callCounter += 1;

  VM_ExecuteCommand(25, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getEnteringObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getExitingObject(const Ice::Current& ice) {
  lock("getExitingObject"); callCounter += 1;

  VM_ExecuteCommand(26, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getExitingObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Double NWScriptI::getFacing(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getFacing"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(28, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("getFacing");
  return fRetVal;
};

Ice::Double NWScriptI::getFacingFromLocation(const NWN::NWLocation& lLocation, const Ice::Current& ice) {
  lock("getFacingFromLocation"); callCounter += 1;
  CScriptLocation *lLocation_ptr;
  lLocation_ptr->X = lLocation.x;
  lLocation_ptr->Y = lLocation.y;
  lLocation_ptr->Z = lLocation.z;
  lLocation_ptr->OrientationX = lLocation.orientationX;
  lLocation_ptr->OrientationY = lLocation.orientationY;
  lLocation_ptr->OrientationZ = lLocation.orientationZ;
  lLocation_ptr->AreaID = lLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);

  VM_ExecuteCommand(225, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("getFacingFromLocation");
  return fRetVal;
};

Ice::Int NWScriptI::getFactionAverageGoodEvilAlignment(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  lock("getFactionAverageGoodEvilAlignment"); callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(187, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFactionAverageGoodEvilAlignment");
  return nRetVal;
};

Ice::Int NWScriptI::getFactionAverageLawChaosAlignment(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  lock("getFactionAverageLawChaosAlignment"); callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(188, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFactionAverageLawChaosAlignment");
  return nRetVal;
};

Ice::Int NWScriptI::getFactionAverageLevel(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  lock("getFactionAverageLevel"); callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(189, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFactionAverageLevel");
  return nRetVal;
};

Ice::Int NWScriptI::getFactionAverageReputation(const NWN::NWObject& oSourceFactionMember, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getFactionAverageReputation"); callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oSourceFactionMember.id);

  VM_ExecuteCommand(186, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFactionAverageReputation");
  return nRetVal;
};

Ice::Int NWScriptI::getFactionAverageXP(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  lock("getFactionAverageXP"); callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(190, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFactionAverageXP");
  return nRetVal;
};

NWN::NWObject NWScriptI::getFactionBestAC(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  lock("getFactionBestAC"); callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(193, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFactionBestAC");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getFactionEqual(const NWN::NWObject& oFirstObject, const NWN::NWObject& oSecondObject, const Ice::Current& ice) {
  lock("getFactionEqual"); callCounter += 1;
  StackPushObject(oSecondObject.id);
  StackPushObject(oFirstObject.id);

  VM_ExecuteCommand(172, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFactionEqual");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getFactionGold(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  lock("getFactionGold"); callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(185, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFactionGold");
  return nRetVal;
};

NWN::NWObject NWScriptI::getFactionLeader(const NWN::NWObject& oMemberOfFaction, const Ice::Current& ice) {
  lock("getFactionLeader"); callCounter += 1;
  StackPushObject(oMemberOfFaction.id);

  VM_ExecuteCommand(562, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFactionLeader");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFactionLeastDamagedMember(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  lock("getFactionLeastDamagedMember"); callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(184, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFactionLeastDamagedMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFactionMostDamagedMember(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  lock("getFactionMostDamagedMember"); callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(183, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFactionMostDamagedMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getFactionMostFrequentClass(const NWN::NWObject& oFactionMember, const Ice::Current& ice) {
  lock("getFactionMostFrequentClass"); callCounter += 1;
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(191, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFactionMostFrequentClass");
  return nRetVal;
};

NWN::NWObject NWScriptI::getFactionStrongestMember(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  lock("getFactionStrongestMember"); callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(182, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFactionStrongestMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFactionWeakestMember(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  lock("getFactionWeakestMember"); callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(181, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFactionWeakestMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFactionWorstAC(const NWN::NWObject& oFactionMember, bool bMustBeVisible, const Ice::Current& ice) {
  lock("getFactionWorstAC"); callCounter += 1;
  StackPushInteger(bMustBeVisible == true ? 1 : 0);
  StackPushObject(oFactionMember.id);

  VM_ExecuteCommand(192, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFactionWorstAC");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getFamiliarCreatureType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getFamiliarCreatureType"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(497, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFamiliarCreatureType");
  return nRetVal;
};

std::string NWScriptI::getFamiliarName(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getFamiliarName"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(499, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getFamiliarName");
  return std::string(sRetVal);
};

NWN::NWEffect NWScriptI::getFirstEffect(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getFirstEffect"); callCounter += 1;
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
  unlock("getFirstEffect");
  return e;
};

NWN::NWObject NWScriptI::getFirstFactionMember(const NWN::NWObject& oMemberOfFaction, bool bPCOnly, const Ice::Current& ice) {
  lock("getFirstFactionMember"); callCounter += 1;
  StackPushInteger(bPCOnly == true ? 1 : 0);
  StackPushObject(oMemberOfFaction.id);

  VM_ExecuteCommand(380, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFirstFactionMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFirstInPersistentObject(const NWN::NWObject& oPersistentObject, Ice::Int nResidentObjectType, Ice::Int nPersistentZone, const Ice::Current& ice) {
  lock("getFirstInPersistentObject"); callCounter += 1;
  StackPushInteger(nPersistentZone);
  StackPushInteger(nResidentObjectType);
  StackPushObject(oPersistentObject.id);

  VM_ExecuteCommand(262, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFirstInPersistentObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFirstItemInInventory(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getFirstItemInInventory"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(339, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFirstItemInInventory");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWItemProperty NWScriptI::getFirstItemProperty(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getFirstItemProperty"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(612, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("getFirstItemProperty");
  return e;
};

NWN::NWObject NWScriptI::getFirstObjectInArea(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("getFirstObjectInArea"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(93, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFirstObjectInArea");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFirstObjectInShape(NWN::ShapeType tShapeType, Ice::Double fSize, const NWN::NWLocation& lTarget, bool bLineOfSight, Ice::Int nObjectFilter, const NWN::NWVector& vOrigin, const Ice::Current& ice) {
  lock("getFirstObjectInShape"); callCounter += 1;
  Vector vvOrigin;
  vvOrigin.X = vOrigin.x; vvOrigin.Y = vOrigin.y; vvOrigin.Z = vOrigin.z;
  StackPushVector(vvOrigin);
  StackPushInteger(nObjectFilter);
  StackPushInteger(bLineOfSight == true ? 1 : 0);
  CScriptLocation *lTarget_ptr;
  lTarget_ptr->X = lTarget.x;
  lTarget_ptr->Y = lTarget.y;
  lTarget_ptr->Z = lTarget.z;
  lTarget_ptr->OrientationX = lTarget.orientationX;
  lTarget_ptr->OrientationY = lTarget.orientationY;
  lTarget_ptr->OrientationZ = lTarget.orientationZ;
  lTarget_ptr->AreaID = lTarget.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTarget_ptr);
  StackPushFloat(fSize);
  if (tShapeType == NWN::SpellCylinderShape) StackPushInteger(0);
   else if (tShapeType == NWN::ConeShape) StackPushInteger(1);
   else if (tShapeType == NWN::CubeShape) StackPushInteger(2);
   else if (tShapeType == NWN::SpellConeShape) StackPushInteger(3);
   else if (tShapeType == NWN::SphereShape) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(128, 6);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFirstObjectInShape");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getFirstPC(const Ice::Current& ice) {
  lock("getFirstPC"); callCounter += 1;

  VM_ExecuteCommand(548, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getFirstPC");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getFogAmount(Ice::Int nFogType, const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("getFogAmount"); callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nFogType);

  VM_ExecuteCommand(785, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFogAmount");
  return nRetVal;
};

Ice::Int NWScriptI::getFogColor(Ice::Int nFogType, const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("getFogColor"); callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nFogType);

  VM_ExecuteCommand(783, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFogColor");
  return nRetVal;
};

Ice::Int NWScriptI::getFootstepType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getFootstepType"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(788, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFootstepType");
  return nRetVal;
};

Ice::Int NWScriptI::getFortitudeSavingThrow(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getFortitudeSavingThrow"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(491, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getFortitudeSavingThrow");
  return nRetVal;
};

Ice::Int NWScriptI::getGameDifficulty(const Ice::Current& ice) {
  lock("getGameDifficulty"); callCounter += 1;

  VM_ExecuteCommand(513, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getGameDifficulty");
  return nRetVal;
};

NWN::Gender NWScriptI::getGender(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getGender"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(358, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getGender");
  if (nRetVal == 0) return NWN::MaleGender;
  if (nRetVal == 1) return NWN::Female;
  if (nRetVal == 2) return NWN::BothGender;
  if (nRetVal == 3) return NWN::OtherGender;
  if (nRetVal == 4) return NWN::NoneGender;
  throw "Error: Unmapped enum return type";
};

NWN::NWObject NWScriptI::getGoingToBeAttackedBy(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getGoingToBeAttackedBy"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(211, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getGoingToBeAttackedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getGold(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getGold"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(418, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getGold");
  return nRetVal;
};

Ice::Int NWScriptI::getGoldPieceValue(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getGoldPieceValue"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(311, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getGoldPieceValue");
  return nRetVal;
};

Ice::Int NWScriptI::getGoodEvilValue(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getGoodEvilValue"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(125, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getGoodEvilValue");
  return nRetVal;
};

Ice::Int NWScriptI::getHardness(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getHardness"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(796, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getHardness");
  return nRetVal;
};

bool NWScriptI::getHasFeat(Ice::Int nFeat, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getHasFeat"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nFeat);

  VM_ExecuteCommand(285, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getHasFeat");
  return nRetVal != 0;
};

bool NWScriptI::getHasFeatEffect(Ice::Int nFeat, const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getHasFeatEffect"); callCounter += 1;
  StackPushObject(oObject.id);
  StackPushInteger(nFeat);

  VM_ExecuteCommand(543, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getHasFeatEffect");
  return nRetVal != 0;
};

bool NWScriptI::getHasInventory(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getHasInventory"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(570, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getHasInventory");
  return nRetVal != 0;
};

bool NWScriptI::getHasSkill(Ice::Int nSkill, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getHasSkill"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(286, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getHasSkill");
  return nRetVal != 0;
};

bool NWScriptI::getHasSpell(Ice::Int nSpell, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getHasSpell"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(377, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getHasSpell");
  return nRetVal != 0;
};

bool NWScriptI::getHasSpellEffect(Ice::Int nSpell, const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getHasSpellEffect"); callCounter += 1;
  StackPushObject(oObject.id);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(304, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getHasSpellEffect");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getHenchman(const NWN::NWObject& oMaster, Ice::Int nNth, const Ice::Current& ice) {
  lock("getHenchman"); callCounter += 1;
  StackPushInteger(nNth);
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(354, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getHenchman");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getHitDice(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getHitDice"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(166, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getHitDice");
  return nRetVal;
};

bool NWScriptI::getIdentified(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getIdentified"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(332, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIdentified");
  return nRetVal != 0;
};

bool NWScriptI::getImmortal(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getImmortal"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(708, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getImmortal");
  return nRetVal != 0;
};

bool NWScriptI::getInfiniteFlag(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getInfiniteFlag"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(827, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getInfiniteFlag");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getInventoryDisturbItem(const Ice::Current& ice) {
  lock("getInventoryDisturbItem"); callCounter += 1;

  VM_ExecuteCommand(353, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getInventoryDisturbItem");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getInventoryDisturbType(const Ice::Current& ice) {
  lock("getInventoryDisturbType"); callCounter += 1;

  VM_ExecuteCommand(352, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getInventoryDisturbType");
  return nRetVal;
};

bool NWScriptI::getIsAreaAboveGround(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("getIsAreaAboveGround"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(726, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsAreaAboveGround");
  return nRetVal != 0;
};

bool NWScriptI::getIsAreaInterior(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("getIsAreaInterior"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(716, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsAreaInterior");
  return nRetVal != 0;
};

bool NWScriptI::getIsAreaNatural(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("getIsAreaNatural"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(725, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsAreaNatural");
  return nRetVal != 0;
};

bool NWScriptI::getIsCreatureDisarmable(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getIsCreatureDisarmable"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(773, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsCreatureDisarmable");
  return nRetVal != 0;
};

bool NWScriptI::getIsDM(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getIsDM"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(420, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsDM");
  return nRetVal != 0;
};

bool NWScriptI::getIsDMPossessed(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getIsDMPossessed"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(723, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsDMPossessed");
  return nRetVal != 0;
};

bool NWScriptI::getIsDawn(const Ice::Current& ice) {
  lock("getIsDawn"); callCounter += 1;

  VM_ExecuteCommand(407, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsDawn");
  return nRetVal != 0;
};

bool NWScriptI::getIsDay(const Ice::Current& ice) {
  lock("getIsDay"); callCounter += 1;

  VM_ExecuteCommand(405, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsDay");
  return nRetVal != 0;
};

bool NWScriptI::getIsDead(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getIsDead"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(140, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsDead");
  return nRetVal != 0;
};

bool NWScriptI::getIsDoorActionPossible(const NWN::NWObject& oTargetDoor, NWN::DoorAction tDoorAction, const Ice::Current& ice) {
  lock("getIsDoorActionPossible"); callCounter += 1;
  if (tDoorAction == NWN::OpenDoor) StackPushInteger(0);
   else if (tDoorAction == NWN::UnlockDoor) StackPushInteger(1);
   else if (tDoorAction == NWN::BashDoor) StackPushInteger(2);
   else if (tDoorAction == NWN::IgnoreDoor) StackPushInteger(3);
   else if (tDoorAction == NWN::KnockDoor) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oTargetDoor.id);

  VM_ExecuteCommand(337, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsDoorActionPossible");
  return nRetVal != 0;
};

bool NWScriptI::getIsDusk(const Ice::Current& ice) {
  lock("getIsDusk"); callCounter += 1;

  VM_ExecuteCommand(408, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsDusk");
  return nRetVal != 0;
};

bool NWScriptI::getIsEffectValid(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("getIsEffectValid"); callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);

  VM_ExecuteCommand(88, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsEffectValid");
  return nRetVal != 0;
};

bool NWScriptI::getIsEncounterCreature(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getIsEncounterCreature"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(409, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsEncounterCreature");
  return nRetVal != 0;
};

bool NWScriptI::getIsEnemy(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  lock("getIsEnemy"); callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(235, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsEnemy");
  return nRetVal != 0;
};

bool NWScriptI::getIsFriend(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  lock("getIsFriend"); callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(236, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsFriend");
  return nRetVal != 0;
};

bool NWScriptI::getIsImmune(const NWN::NWObject& oCreature, Ice::Int nImmunityType, const NWN::NWObject& oVersus, const Ice::Current& ice) {
  lock("getIsImmune"); callCounter += 1;
  StackPushObject(oVersus.id);
  StackPushInteger(nImmunityType);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(274, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsImmune");
  return nRetVal != 0;
};

bool NWScriptI::getIsInCombat(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getIsInCombat"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(320, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsInCombat");
  return nRetVal != 0;
};

bool NWScriptI::getIsInSubArea(const NWN::NWObject& oCreature, const NWN::NWObject& oSubArea, const Ice::Current& ice) {
  lock("getIsInSubArea"); callCounter += 1;
  StackPushObject(oSubArea.id);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(768, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsInSubArea");
  return nRetVal != 0;
};

bool NWScriptI::getIsItemPropertyValid(const NWN::NWItemProperty& ipProperty, const Ice::Current& ice) {
if (iprpMap.find(ipProperty.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock("getIsItemPropertyValid"); callCounter += 1;
  CGameEffect *ipProperty_ptr = iprpMap.find(ipProperty.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, ipProperty_ptr);

  VM_ExecuteCommand(611, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsItemPropertyValid");
  return nRetVal != 0;
};

bool NWScriptI::getIsListening(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getIsListening"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(174, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsListening");
  return nRetVal != 0;
};

bool NWScriptI::getIsNeutral(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  lock("getIsNeutral"); callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(237, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsNeutral");
  return nRetVal != 0;
};

bool NWScriptI::getIsNight(const Ice::Current& ice) {
  lock("getIsNight"); callCounter += 1;

  VM_ExecuteCommand(406, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsNight");
  return nRetVal != 0;
};

bool NWScriptI::getIsObjectValid(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getIsObjectValid"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(42, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsObjectValid");
  return nRetVal != 0;
};

bool NWScriptI::getIsOpen(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getIsOpen"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(443, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsOpen");
  return nRetVal != 0;
};

bool NWScriptI::getIsPC(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getIsPC"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(217, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsPC");
  return nRetVal != 0;
};

bool NWScriptI::getIsPlaceableObjectActionPossible(const NWN::NWObject& oPlaceable, NWN::PlaceableAction tPlaceableAction, const Ice::Current& ice) {
  lock("getIsPlaceableObjectActionPossible"); callCounter += 1;
  if (tPlaceableAction == NWN::UsePlaceable) StackPushInteger(0);
   else if (tPlaceableAction == NWN::UnlockPlaceable) StackPushInteger(1);
   else if (tPlaceableAction == NWN::BashPlaceable) StackPushInteger(2);
   else if (tPlaceableAction == NWN::KnockPlaceable) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(546, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsPlaceableObjectActionPossible");
  return nRetVal != 0;
};

bool NWScriptI::getIsPlayableRacialType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getIsPlayableRacialType"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(312, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsPlayableRacialType");
  return nRetVal != 0;
};

bool NWScriptI::getIsPossessedFamiliar(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getIsPossessedFamiliar"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(714, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsPossessedFamiliar");
  return nRetVal != 0;
};

bool NWScriptI::getIsReactionTypeFriendly(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  lock("getIsReactionTypeFriendly"); callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(469, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsReactionTypeFriendly");
  return nRetVal != 0;
};

bool NWScriptI::getIsReactionTypeHostile(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  lock("getIsReactionTypeHostile"); callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(471, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsReactionTypeHostile");
  return nRetVal != 0;
};

bool NWScriptI::getIsReactionTypeNeutral(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  lock("getIsReactionTypeNeutral"); callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(470, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsReactionTypeNeutral");
  return nRetVal != 0;
};

bool NWScriptI::getIsResting(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getIsResting"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(505, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsResting");
  return nRetVal != 0;
};

bool NWScriptI::getIsSkillSuccessful(const NWN::NWObject& oTarget, Ice::Int nSkill, Ice::Int nDifficulty, const Ice::Current& ice) {
  lock("getIsSkillSuccessful"); callCounter += 1;
  StackPushInteger(nDifficulty);
  StackPushInteger(nSkill);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(689, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsSkillSuccessful");
  return nRetVal != 0;
};

bool NWScriptI::getIsTrapped(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getIsTrapped"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(551, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsTrapped");
  return nRetVal != 0;
};

bool NWScriptI::getIsWeaponEffective(const NWN::NWObject& oVersus, bool bOffHand, const Ice::Current& ice) {
  lock("getIsWeaponEffective"); callCounter += 1;
  StackPushInteger(bOffHand == true ? 1 : 0);
  StackPushObject(oVersus.id);

  VM_ExecuteCommand(422, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getIsWeaponEffective");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getItemACValue(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getItemACValue"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(401, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemACValue");
  return nRetVal;
};

NWN::NWObject NWScriptI::getItemActivated(const Ice::Current& ice) {
  lock("getItemActivated"); callCounter += 1;

  VM_ExecuteCommand(439, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getItemActivated");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getItemActivatedTarget(const Ice::Current& ice) {
  lock("getItemActivatedTarget"); callCounter += 1;

  VM_ExecuteCommand(442, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getItemActivatedTarget");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWLocation NWScriptI::getItemActivatedTargetLocation(const Ice::Current& ice) {
  lock("getItemActivatedTargetLocation"); callCounter += 1;

  VM_ExecuteCommand(441, 0);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.x = pRetVal->X;
  nl.y = pRetVal->X;
  nl.z = pRetVal->X;
  nl.orientationX = pRetVal->OrientationX;
  nl.orientationY = pRetVal->OrientationY;
  nl.orientationZ = pRetVal->OrientationZ;
  nl.area.id = pRetVal->AreaID;
  unlock("getItemActivatedTargetLocation");
  return nl;
};

NWN::NWObject NWScriptI::getItemActivator(const Ice::Current& ice) {
  lock("getItemActivator"); callCounter += 1;

  VM_ExecuteCommand(440, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getItemActivator");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getItemAppearance(const NWN::NWObject& oItem, Ice::Int nType, Ice::Int nIndex, const Ice::Current& ice) {
  lock("getItemAppearance"); callCounter += 1;
  StackPushInteger(nIndex);
  StackPushInteger(nType);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(732, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemAppearance");
  return nRetVal;
};

Ice::Int NWScriptI::getItemCharges(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getItemCharges"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(607, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemCharges");
  return nRetVal;
};

bool NWScriptI::getItemCursedFlag(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getItemCursedFlag"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(744, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemCursedFlag");
  return nRetVal != 0;
};

bool NWScriptI::getItemHasItemProperty(const NWN::NWObject& oItem, Ice::Int nProperty, const Ice::Current& ice) {
  lock("getItemHasItemProperty"); callCounter += 1;
  StackPushInteger(nProperty);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(398, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemHasItemProperty");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getItemInSlot(NWN::InventorySlot tInventorySlot, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getItemInSlot"); callCounter += 1;
  StackPushObject(oCreature.id);
  if (tInventorySlot == NWN::CreatureBiteSlot) StackPushInteger(16);
   else if (tInventorySlot == NWN::LefthandSlot) StackPushInteger(5);
   else if (tInventorySlot == NWN::ArrowsSlot) StackPushInteger(11);
   else if (tInventorySlot == NWN::HeadSlot) StackPushInteger(0);
   else if (tInventorySlot == NWN::CreatureArmorSlot) StackPushInteger(17);
   else if (tInventorySlot == NWN::CloakSlot) StackPushInteger(6);
   else if (tInventorySlot == NWN::BulletsSlot) StackPushInteger(12);
   else if (tInventorySlot == NWN::ChestSlot) StackPushInteger(1);
   else if (tInventorySlot == NWN::LeftringSlot) StackPushInteger(7);
   else if (tInventorySlot == NWN::BoltsSlot) StackPushInteger(13);
   else if (tInventorySlot == NWN::BootsSlot) StackPushInteger(2);
   else if (tInventorySlot == NWN::RightringSlot) StackPushInteger(8);
   else if (tInventorySlot == NWN::CreatureLefthandSlot) StackPushInteger(14);
   else if (tInventorySlot == NWN::ArmsSlot) StackPushInteger(3);
   else if (tInventorySlot == NWN::NeckSlot) StackPushInteger(9);
   else if (tInventorySlot == NWN::CreatureRighthandSlot) StackPushInteger(15);
   else if (tInventorySlot == NWN::RighthandSlot) StackPushInteger(4);
   else if (tInventorySlot == NWN::BeltSlot) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(155, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getItemInSlot");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getItemPossessedBy(const NWN::NWObject& oCreature, const std::string& sItemTag, const Ice::Current& ice) {
  lock("getItemPossessedBy"); callCounter += 1;
  StackPushString(sItemTag.c_str());
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(30, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getItemPossessedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getItemPossessor(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getItemPossessor"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(29, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getItemPossessor");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getItemPropertyCostTable(const NWN::NWItemProperty& iProp, const Ice::Current& ice) {
if (iprpMap.find(iProp.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock("getItemPropertyCostTable"); callCounter += 1;
  CGameEffect *iProp_ptr = iprpMap.find(iProp.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, iProp_ptr);

  VM_ExecuteCommand(769, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemPropertyCostTable");
  return nRetVal;
};

Ice::Int NWScriptI::getItemPropertyCostTableValue(const NWN::NWItemProperty& iProp, const Ice::Current& ice) {
if (iprpMap.find(iProp.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock("getItemPropertyCostTableValue"); callCounter += 1;
  CGameEffect *iProp_ptr = iprpMap.find(iProp.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, iProp_ptr);

  VM_ExecuteCommand(770, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemPropertyCostTableValue");
  return nRetVal;
};

NWN::DurationType NWScriptI::getItemPropertyDurationType(const NWN::NWItemProperty& ip, const Ice::Current& ice) {
if (iprpMap.find(ip.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock("getItemPropertyDurationType"); callCounter += 1;
  CGameEffect *ip_ptr = iprpMap.find(ip.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, ip_ptr);

  VM_ExecuteCommand(615, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemPropertyDurationType");
  if (nRetVal == 0) return NWN::Instant;
  if (nRetVal == 1) return NWN::Temporary;
  if (nRetVal == 2) return NWN::Permanent;
  throw "Error: Unmapped enum return type";
};

Ice::Int NWScriptI::getItemPropertyParam1(const NWN::NWItemProperty& iProp, const Ice::Current& ice) {
if (iprpMap.find(iProp.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock("getItemPropertyParam1"); callCounter += 1;
  CGameEffect *iProp_ptr = iprpMap.find(iProp.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, iProp_ptr);

  VM_ExecuteCommand(771, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemPropertyParam1");
  return nRetVal;
};

Ice::Int NWScriptI::getItemPropertyParam1Value(const NWN::NWItemProperty& iProp, const Ice::Current& ice) {
if (iprpMap.find(iProp.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock("getItemPropertyParam1Value"); callCounter += 1;
  CGameEffect *iProp_ptr = iprpMap.find(iProp.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, iProp_ptr);

  VM_ExecuteCommand(772, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemPropertyParam1Value");
  return nRetVal;
};

Ice::Int NWScriptI::getItemPropertySubType(const NWN::NWItemProperty& iProperty, const Ice::Current& ice) {
if (iprpMap.find(iProperty.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock("getItemPropertySubType"); callCounter += 1;
  CGameEffect *iProperty_ptr = iprpMap.find(iProperty.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, iProperty_ptr);

  VM_ExecuteCommand(734, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemPropertySubType");
  return nRetVal;
};

Ice::Int NWScriptI::getItemPropertyType(const NWN::NWItemProperty& ip, const Ice::Current& ice) {
if (iprpMap.find(ip.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock("getItemPropertyType"); callCounter += 1;
  CGameEffect *ip_ptr = iprpMap.find(ip.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, ip_ptr);

  VM_ExecuteCommand(614, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemPropertyType");
  return nRetVal;
};

Ice::Int NWScriptI::getItemStackSize(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getItemStackSize"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(605, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getItemStackSize");
  return nRetVal;
};

Ice::Int NWScriptI::getJournalQuestExperience(const std::string& szPlotID, const Ice::Current& ice) {
  lock("getJournalQuestExperience"); callCounter += 1;
  StackPushString(szPlotID.c_str());

  VM_ExecuteCommand(384, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getJournalQuestExperience");
  return nRetVal;
};

std::string NWScriptI::getKeyRequiredFeedback(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getKeyRequiredFeedback"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(819, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getKeyRequiredFeedback");
  return std::string(sRetVal);
};

NWN::AssociateCommand NWScriptI::getLastAssociateCommand(const NWN::NWObject& oAssociate, const Ice::Current& ice) {
  lock("getLastAssociateCommand"); callCounter += 1;
  StackPushObject(oAssociate.id);

  VM_ExecuteCommand(321, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLastAssociateCommand");
  if (nRetVal == -19) return NWN::InventoryCommand;
  if (nRetVal == -8) return NWN::UnsummonFamiliarCommand;
  if (nRetVal == -13) return NWN::UnpossessFamiliarCommand;
  if (nRetVal == -2) return NWN::StandGroundCommand;
  if (nRetVal == -18) return NWN::PickLockCommand;
  if (nRetVal == -7) return NWN::GuardMasterCommand;
  if (nRetVal == -23) return NWN::ToggleSearchCommand;
  if (nRetVal == -12) return NWN::ReleaseDominationCommand;
  if (nRetVal == -17) return NWN::LeavePartyCommand;
  if (nRetVal == -6) return NWN::MasterFailedLockpickCommand;
  if (nRetVal == -22) return NWN::ToggleStealthCommand;
  if (nRetVal == -11) return NWN::MasterUnderAttackCommand;
  if (nRetVal == -16) return NWN::MasterGoingToBeAttackedCommand;
  if (nRetVal == -5) return NWN::FollowMasterCommand;
  if (nRetVal == -21) return NWN::ToggleCastingCommand;
  if (nRetVal == -10) return NWN::UnsummonSummonedCommand;
  if (nRetVal == -15) return NWN::MasterAttackedOtherCommand;
  if (nRetVal == -4) return NWN::HealMasterCommand;
  if (nRetVal == -20) return NWN::DisarmTrapCommand;
  if (nRetVal == -9) return NWN::UnsummonAnimalCompanionCommand;
  if (nRetVal == -14) return NWN::MasterSawTrapCommand;
  if (nRetVal == -3) return NWN::AttackNearestCommand;
  throw "Error: Unmapped enum return type";
};

NWN::CombatMode NWScriptI::getLastAttackMode(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getLastAttackMode"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(318, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLastAttackMode");
  if (nRetVal == 5) return NWN::RapidShotCombatMode;
  if (nRetVal == 0) return NWN::InvalidCombatMode;
  if (nRetVal == 6) return NWN::ExpertiseCombatMode;
  if (nRetVal == 1) return NWN::ParryCombatMode;
  if (nRetVal == 7) return NWN::ImprovedExpertiseCombatMode;
  if (nRetVal == 2) return NWN::PowerAttackCombatMode;
  if (nRetVal == 8) return NWN::DefensiveCastingCombatMode;
  if (nRetVal == 3) return NWN::ImprovedPowerAttackCombatMode;
  if (nRetVal == 9) return NWN::DirtyFightingCombatMode;
  if (nRetVal == 4) return NWN::FlurryOfBlowsCombatMode;
  if (nRetVal == 10) return NWN::DefensiveStanceCombatMode;
  throw "Error: Unmapped enum return type";
};

NWN::SpecialAttack NWScriptI::getLastAttackType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getLastAttackType"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(317, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLastAttackType");
  if (nRetVal == 5) return NWN::ImprovedDisarmSpecialAttack;
  if (nRetVal == 0) return NWN::InvalidSpecialAttack;
  if (nRetVal == 6) return NWN::KnockdownSpecialAttack;
  if (nRetVal == 1) return NWN::CalledShotLegSpecialAttack;
  if (nRetVal == 7) return NWN::ImprovedKnockdownSpecialAttack;
  if (nRetVal == 2) return NWN::CalledShotArmSpecialAttack;
  if (nRetVal == 8) return NWN::StunningFistSpecialAttack;
  if (nRetVal == 3) return NWN::SapSpecialAttack;
  if (nRetVal == 9) return NWN::FlurryOfBlowsSpecialAttack;
  if (nRetVal == 4) return NWN::DisarmSpecialAttack;
  if (nRetVal == 10) return NWN::RapidShotSpecialAttack;
  throw "Error: Unmapped enum return type";
};

NWN::NWObject NWScriptI::getLastAttacker(const NWN::NWObject& oAttackee, const Ice::Current& ice) {
  lock("getLastAttacker"); callCounter += 1;
  StackPushObject(oAttackee.id);

  VM_ExecuteCommand(36, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastAttacker");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastClosedBy(const Ice::Current& ice) {
  lock("getLastClosedBy"); callCounter += 1;

  VM_ExecuteCommand(260, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastClosedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastDamager(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getLastDamager"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(346, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastDamager");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastDisarmed(const Ice::Current& ice) {
  lock("getLastDisarmed"); callCounter += 1;

  VM_ExecuteCommand(347, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastDisarmed");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastDisturbed(const Ice::Current& ice) {
  lock("getLastDisturbed"); callCounter += 1;

  VM_ExecuteCommand(348, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastDisturbed");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastHostileActor(const NWN::NWObject& oVictim, const Ice::Current& ice) {
  lock("getLastHostileActor"); callCounter += 1;
  StackPushObject(oVictim.id);

  VM_ExecuteCommand(556, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastHostileActor");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastKiller(const Ice::Current& ice) {
  lock("getLastKiller"); callCounter += 1;

  VM_ExecuteCommand(437, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastKiller");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastLocked(const Ice::Current& ice) {
  lock("getLastLocked"); callCounter += 1;

  VM_ExecuteCommand(349, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastLocked");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastOpenedBy(const Ice::Current& ice) {
  lock("getLastOpenedBy"); callCounter += 1;

  VM_ExecuteCommand(376, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastOpenedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastPCRested(const Ice::Current& ice) {
  lock("getLastPCRested"); callCounter += 1;

  VM_ExecuteCommand(506, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastPCRested");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastPCToCancelCutscene(const Ice::Current& ice) {
  lock("getLastPCToCancelCutscene"); callCounter += 1;

  VM_ExecuteCommand(693, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastPCToCancelCutscene");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastPerceived(const Ice::Current& ice) {
  lock("getLastPerceived"); callCounter += 1;

  VM_ExecuteCommand(256, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastPerceived");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getLastPerceptionHeard(const Ice::Current& ice) {
  lock("getLastPerceptionHeard"); callCounter += 1;

  VM_ExecuteCommand(257, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLastPerceptionHeard");
  return nRetVal != 0;
};

bool NWScriptI::getLastPerceptionInaudible(const Ice::Current& ice) {
  lock("getLastPerceptionInaudible"); callCounter += 1;

  VM_ExecuteCommand(258, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLastPerceptionInaudible");
  return nRetVal != 0;
};

bool NWScriptI::getLastPerceptionSeen(const Ice::Current& ice) {
  lock("getLastPerceptionSeen"); callCounter += 1;

  VM_ExecuteCommand(259, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLastPerceptionSeen");
  return nRetVal != 0;
};

bool NWScriptI::getLastPerceptionVanished(const Ice::Current& ice) {
  lock("getLastPerceptionVanished"); callCounter += 1;

  VM_ExecuteCommand(261, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLastPerceptionVanished");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getLastPlayerDied(const Ice::Current& ice) {
  lock("getLastPlayerDied"); callCounter += 1;

  VM_ExecuteCommand(291, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastPlayerDied");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastPlayerDying(const Ice::Current& ice) {
  lock("getLastPlayerDying"); callCounter += 1;

  VM_ExecuteCommand(410, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastPlayerDying");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastRespawnButtonPresser(const Ice::Current& ice) {
  lock("getLastRespawnButtonPresser"); callCounter += 1;

  VM_ExecuteCommand(419, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastRespawnButtonPresser");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getLastRestEventType(const Ice::Current& ice) {
  lock("getLastRestEventType"); callCounter += 1;

  VM_ExecuteCommand(508, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLastRestEventType");
  return nRetVal;
};

NWN::NWObject NWScriptI::getLastSpeaker(const Ice::Current& ice) {
  lock("getLastSpeaker"); callCounter += 1;

  VM_ExecuteCommand(254, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastSpeaker");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getLastSpell(const Ice::Current& ice) {
  lock("getLastSpell"); callCounter += 1;

  VM_ExecuteCommand(246, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLastSpell");
  return nRetVal;
};

Ice::Int NWScriptI::getLastSpellCastClass(const Ice::Current& ice) {
  lock("getLastSpellCastClass"); callCounter += 1;

  VM_ExecuteCommand(754, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLastSpellCastClass");
  return nRetVal;
};

NWN::NWObject NWScriptI::getLastSpellCaster(const Ice::Current& ice) {
  lock("getLastSpellCaster"); callCounter += 1;

  VM_ExecuteCommand(245, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastSpellCaster");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getLastSpellHarmful(const Ice::Current& ice) {
  lock("getLastSpellHarmful"); callCounter += 1;

  VM_ExecuteCommand(423, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLastSpellHarmful");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getLastTrapDetected(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getLastTrapDetected"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(486, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastTrapDetected");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastUnlocked(const Ice::Current& ice) {
  lock("getLastUnlocked"); callCounter += 1;

  VM_ExecuteCommand(350, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastUnlocked");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastUsedBy(const Ice::Current& ice) {
  lock("getLastUsedBy"); callCounter += 1;

  VM_ExecuteCommand(330, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastUsedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getLastWeaponUsed(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getLastWeaponUsed"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(328, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLastWeaponUsed");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getLawChaosValue(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getLawChaosValue"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(124, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLawChaosValue");
  return nRetVal;
};

Ice::Int NWScriptI::getLevelByClass(Ice::Int nClassType, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getLevelByClass"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nClassType);

  VM_ExecuteCommand(343, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLevelByClass");
  return nRetVal;
};

Ice::Int NWScriptI::getLevelByPosition(Ice::Int nClassPosition, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getLevelByPosition"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nClassPosition);

  VM_ExecuteCommand(342, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLevelByPosition");
  return nRetVal;
};

Ice::Int NWScriptI::getListenPatternNumber(const Ice::Current& ice) {
  lock("getListenPatternNumber"); callCounter += 1;

  VM_ExecuteCommand(195, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getListenPatternNumber");
  return nRetVal;
};

Ice::Double NWScriptI::getLocalFloat(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  lock("getLocalFloat"); callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(52, 2);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("getLocalFloat");
  return fRetVal;
};

Ice::Int NWScriptI::getLocalInt(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  lock("getLocalInt"); callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(51, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLocalInt");
  return nRetVal;
};

NWN::NWLocation NWScriptI::getLocalLocation(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  lock("getLocalLocation"); callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(153, 2);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.x = pRetVal->X;
  nl.y = pRetVal->X;
  nl.z = pRetVal->X;
  nl.orientationX = pRetVal->OrientationX;
  nl.orientationY = pRetVal->OrientationY;
  nl.orientationZ = pRetVal->OrientationZ;
  nl.area.id = pRetVal->AreaID;
  unlock("getLocalLocation");
  return nl;
};

NWN::NWObject NWScriptI::getLocalObject(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  lock("getLocalObject"); callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(54, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getLocalObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

std::string NWScriptI::getLocalString(const NWN::NWObject& oObject, const std::string& sVarName, const Ice::Current& ice) {
  lock("getLocalString"); callCounter += 1;
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(53, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getLocalString");
  return std::string(sRetVal);
};

NWN::NWLocation NWScriptI::getLocation(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getLocation"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(213, 1);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.x = pRetVal->X;
  nl.y = pRetVal->X;
  nl.z = pRetVal->X;
  nl.orientationX = pRetVal->OrientationX;
  nl.orientationY = pRetVal->OrientationY;
  nl.orientationZ = pRetVal->OrientationZ;
  nl.area.id = pRetVal->AreaID;
  unlock("getLocation");
  return nl;
};

bool NWScriptI::getLockKeyRequired(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getLockKeyRequired"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(537, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLockKeyRequired");
  return nRetVal != 0;
};

std::string NWScriptI::getLockKeyTag(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getLockKeyTag"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(538, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getLockKeyTag");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getLockLockDC(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getLockLockDC"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(541, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLockLockDC");
  return nRetVal;
};

bool NWScriptI::getLockLockable(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getLockLockable"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(539, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLockLockable");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getLockUnlockDC(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getLockUnlockDC"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(540, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLockUnlockDC");
  return nRetVal;
};

bool NWScriptI::getLocked(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getLocked"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(325, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLocked");
  return nRetVal != 0;
};

bool NWScriptI::getLootable(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getLootable"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(741, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getLootable");
  return nRetVal != 0;
};

NWN::NWObject NWScriptI::getMaster(const NWN::NWObject& oAssociate, const Ice::Current& ice) {
  lock("getMaster"); callCounter += 1;
  StackPushObject(oAssociate.id);

  VM_ExecuteCommand(319, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getMaster");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

std::string NWScriptI::getMatchedSubstring(Ice::Int nString, const Ice::Current& ice) {
  lock("getMatchedSubstring"); callCounter += 1;
  StackPushInteger(nString);

  VM_ExecuteCommand(178, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getMatchedSubstring");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getMatchedSubstringsCount(const Ice::Current& ice) {
  lock("getMatchedSubstringsCount"); callCounter += 1;

  VM_ExecuteCommand(179, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getMatchedSubstringsCount");
  return nRetVal;
};

Ice::Int NWScriptI::getMaxHenchmen(const Ice::Current& ice) {
  lock("getMaxHenchmen"); callCounter += 1;

  VM_ExecuteCommand(747, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getMaxHenchmen");
  return nRetVal;
};

Ice::Int NWScriptI::getMaxHitPoints(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getMaxHitPoints"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(50, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getMaxHitPoints");
  return nRetVal;
};

NWN::MetaMagic NWScriptI::getMetaMagicFeat(const Ice::Current& ice) {
  lock("getMetaMagicFeat"); callCounter += 1;

  VM_ExecuteCommand(105, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getMetaMagicFeat");
  if (nRetVal == 16) return NWN::SilentMeta;
  if (nRetVal == 0) return NWN::NoneMeta;
  if (nRetVal == 1) return NWN::EmpowerMeta;
  if (nRetVal == 255) return NWN::AnyMeta;
  if (nRetVal == 2) return NWN::ExtendMeta;
  if (nRetVal == 8) return NWN::QuickenMeta;
  if (nRetVal == 4) return NWN::MaximizeMeta;
  if (nRetVal == 32) return NWN::StillMeta;
  throw "Error: Unmapped enum return type";
};

NWN::NWObject NWScriptI::getModule(const Ice::Current& ice) {
  lock("getModule"); callCounter += 1;

  VM_ExecuteCommand(242, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getModule");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getModuleItemAcquired(const Ice::Current& ice) {
  lock("getModuleItemAcquired"); callCounter += 1;

  VM_ExecuteCommand(282, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getModuleItemAcquired");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getModuleItemAcquiredBy(const Ice::Current& ice) {
  lock("getModuleItemAcquiredBy"); callCounter += 1;

  VM_ExecuteCommand(707, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getModuleItemAcquiredBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getModuleItemAcquiredFrom(const Ice::Current& ice) {
  lock("getModuleItemAcquiredFrom"); callCounter += 1;

  VM_ExecuteCommand(283, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getModuleItemAcquiredFrom");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getModuleItemAcquiredStackSize(const Ice::Current& ice) {
  lock("getModuleItemAcquiredStackSize"); callCounter += 1;

  VM_ExecuteCommand(579, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getModuleItemAcquiredStackSize");
  return nRetVal;
};

NWN::NWObject NWScriptI::getModuleItemLost(const Ice::Current& ice) {
  lock("getModuleItemLost"); callCounter += 1;

  VM_ExecuteCommand(292, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getModuleItemLost");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getModuleItemLostBy(const Ice::Current& ice) {
  lock("getModuleItemLostBy"); callCounter += 1;

  VM_ExecuteCommand(293, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getModuleItemLostBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

std::string NWScriptI::getModuleName(const Ice::Current& ice) {
  lock("getModuleName"); callCounter += 1;

  VM_ExecuteCommand(561, 0);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getModuleName");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getModuleXPScale(const Ice::Current& ice) {
  lock("getModuleXPScale"); callCounter += 1;

  VM_ExecuteCommand(817, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getModuleXPScale");
  return nRetVal;
};

Ice::Int NWScriptI::getMovementRate(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getMovementRate"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(496, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getMovementRate");
  return nRetVal;
};

std::string NWScriptI::getName(const NWN::NWObject& oObject, bool bOriginalName, const Ice::Current& ice) {
  lock("getName"); callCounter += 1;
  StackPushInteger(bOriginalName == true ? 1 : 0);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(253, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getName");
  return std::string(sRetVal);
};

NWN::NWObject NWScriptI::getNearestCreature(Ice::Int nFirstCriteriaType, Ice::Int nFirstCriteriaValue, const NWN::NWObject& oTarget, Ice::Int nNth, Ice::Int nSecondCriteriaType, Ice::Int nSecondCriteriaValue, Ice::Int nThirdCriteriaType, Ice::Int nThirdCriteriaValue, const Ice::Current& ice) {
  lock("getNearestCreature"); callCounter += 1;
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
  unlock("getNearestCreature");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNearestCreatureToLocation(Ice::Int nFirstCriteriaType, Ice::Int nFirstCriteriaValue, const NWN::NWLocation& lLocation, Ice::Int nNth, Ice::Int nSecondCriteriaType, Ice::Int nSecondCriteriaValue, Ice::Int nThirdCriteriaType, Ice::Int nThirdCriteriaValue, const Ice::Current& ice) {
  lock("getNearestCreatureToLocation"); callCounter += 1;
  StackPushInteger(nThirdCriteriaValue);
  StackPushInteger(nThirdCriteriaType);
  StackPushInteger(nSecondCriteriaValue);
  StackPushInteger(nSecondCriteriaType);
  StackPushInteger(nNth);
  CScriptLocation *lLocation_ptr;
  lLocation_ptr->X = lLocation.x;
  lLocation_ptr->Y = lLocation.y;
  lLocation_ptr->Z = lLocation.z;
  lLocation_ptr->OrientationX = lLocation.orientationX;
  lLocation_ptr->OrientationY = lLocation.orientationY;
  lLocation_ptr->OrientationZ = lLocation.orientationZ;
  lLocation_ptr->AreaID = lLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
  StackPushInteger(nFirstCriteriaValue);
  StackPushInteger(nFirstCriteriaType);

  VM_ExecuteCommand(226, 8);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getNearestCreatureToLocation");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNearestObject(NWN::ObjectType tObjectType, const NWN::NWObject& oTarget, Ice::Int nNth, const Ice::Current& ice) {
  lock("getNearestObject"); callCounter += 1;
  StackPushInteger(nNth);
  StackPushObject(oTarget.id);
  if (tObjectType == NWN::AOE) StackPushInteger(16);
   else if (tObjectType == NWN::InvalidObject) StackPushInteger(0);
   else if (tObjectType == NWN::Creature) StackPushInteger(1);
   else if (tObjectType == NWN::Store) StackPushInteger(128);
   else if (tObjectType == NWN::Item) StackPushInteger(2);
   else if (tObjectType == NWN::Door) StackPushInteger(8);
   else if (tObjectType == NWN::Encounter) StackPushInteger(256);
   else if (tObjectType == NWN::All) StackPushInteger(32767);
   else if (tObjectType == NWN::Placeable) StackPushInteger(64);
   else if (tObjectType == NWN::Trigger) StackPushInteger(4);
   else if (tObjectType == NWN::Waypoint) StackPushInteger(32);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(227, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getNearestObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNearestObjectByTag(const std::string& sTag, const NWN::NWObject& oTarget, Ice::Int nNth, const Ice::Current& ice) {
  lock("getNearestObjectByTag"); callCounter += 1;
  StackPushInteger(nNth);
  StackPushObject(oTarget.id);
  StackPushString(sTag.c_str());

  VM_ExecuteCommand(229, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getNearestObjectByTag");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNearestObjectToLocation(NWN::ObjectType tObjectType, const NWN::NWLocation& lLocation, Ice::Int nNth, const Ice::Current& ice) {
  lock("getNearestObjectToLocation"); callCounter += 1;
  StackPushInteger(nNth);
  CScriptLocation *lLocation_ptr;
  lLocation_ptr->X = lLocation.x;
  lLocation_ptr->Y = lLocation.y;
  lLocation_ptr->Z = lLocation.z;
  lLocation_ptr->OrientationX = lLocation.orientationX;
  lLocation_ptr->OrientationY = lLocation.orientationY;
  lLocation_ptr->OrientationZ = lLocation.orientationZ;
  lLocation_ptr->AreaID = lLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);
  if (tObjectType == NWN::AOE) StackPushInteger(16);
   else if (tObjectType == NWN::InvalidObject) StackPushInteger(0);
   else if (tObjectType == NWN::Creature) StackPushInteger(1);
   else if (tObjectType == NWN::Store) StackPushInteger(128);
   else if (tObjectType == NWN::Item) StackPushInteger(2);
   else if (tObjectType == NWN::Door) StackPushInteger(8);
   else if (tObjectType == NWN::Encounter) StackPushInteger(256);
   else if (tObjectType == NWN::All) StackPushInteger(32767);
   else if (tObjectType == NWN::Placeable) StackPushInteger(64);
   else if (tObjectType == NWN::Trigger) StackPushInteger(4);
   else if (tObjectType == NWN::Waypoint) StackPushInteger(32);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(228, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getNearestObjectToLocation");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNearestTrapToObject(const NWN::NWObject& oTarget, bool bTrapDetected, const Ice::Current& ice) {
  lock("getNearestTrapToObject"); callCounter += 1;
  StackPushInteger(bTrapDetected == true ? 1 : 0);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(488, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getNearestTrapToObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWEffect NWScriptI::getNextEffect(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getNextEffect"); callCounter += 1;
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
  unlock("getNextEffect");
  return e;
};

NWN::NWObject NWScriptI::getNextFactionMember(const NWN::NWObject& oMemberOfFaction, bool bPCOnly, const Ice::Current& ice) {
  lock("getNextFactionMember"); callCounter += 1;
  StackPushInteger(bPCOnly == true ? 1 : 0);
  StackPushObject(oMemberOfFaction.id);

  VM_ExecuteCommand(381, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getNextFactionMember");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNextInPersistentObject(const NWN::NWObject& oPersistentObject, Ice::Int nResidentObjectType, Ice::Int nPersistentZone, const Ice::Current& ice) {
  lock("getNextInPersistentObject"); callCounter += 1;
  StackPushInteger(nPersistentZone);
  StackPushInteger(nResidentObjectType);
  StackPushObject(oPersistentObject.id);

  VM_ExecuteCommand(263, 3);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getNextInPersistentObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNextItemInInventory(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getNextItemInInventory"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(340, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getNextItemInInventory");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWItemProperty NWScriptI::getNextItemProperty(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getNextItemProperty"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(613, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("getNextItemProperty");
  return e;
};

NWN::NWObject NWScriptI::getNextObjectInArea(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("getNextObjectInArea"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(94, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getNextObjectInArea");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNextObjectInShape(NWN::ShapeType tShapeType, Ice::Double fSize, const NWN::NWLocation& lTarget, bool bLineOfSight, Ice::Int nObjectFilter, const NWN::NWVector& vOrigin, const Ice::Current& ice) {
  lock("getNextObjectInShape"); callCounter += 1;
  Vector vvOrigin;
  vvOrigin.X = vOrigin.x; vvOrigin.Y = vOrigin.y; vvOrigin.Z = vOrigin.z;
  StackPushVector(vvOrigin);
  StackPushInteger(nObjectFilter);
  StackPushInteger(bLineOfSight == true ? 1 : 0);
  CScriptLocation *lTarget_ptr;
  lTarget_ptr->X = lTarget.x;
  lTarget_ptr->Y = lTarget.y;
  lTarget_ptr->Z = lTarget.z;
  lTarget_ptr->OrientationX = lTarget.orientationX;
  lTarget_ptr->OrientationY = lTarget.orientationY;
  lTarget_ptr->OrientationZ = lTarget.orientationZ;
  lTarget_ptr->AreaID = lTarget.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTarget_ptr);
  StackPushFloat(fSize);
  if (tShapeType == NWN::SpellCylinderShape) StackPushInteger(0);
   else if (tShapeType == NWN::ConeShape) StackPushInteger(1);
   else if (tShapeType == NWN::CubeShape) StackPushInteger(2);
   else if (tShapeType == NWN::SpellConeShape) StackPushInteger(3);
   else if (tShapeType == NWN::SphereShape) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(129, 6);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getNextObjectInShape");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getNextPC(const Ice::Current& ice) {
  lock("getNextPC"); callCounter += 1;

  VM_ExecuteCommand(549, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getNextPC");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getNumStackedItems(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getNumStackedItems"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(475, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getNumStackedItems");
  return nRetVal;
};

NWN::NWObject NWScriptI::getObjectByTag(const std::string& sTag, Ice::Int nNth, const Ice::Current& ice) {
  lock("getObjectByTag"); callCounter += 1;
  StackPushInteger(nNth);
  StackPushString(sTag.c_str());

  VM_ExecuteCommand(200, 2);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getObjectByTag");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getObjectHeard(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  lock("getObjectHeard"); callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(290, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getObjectHeard");
  return nRetVal != 0;
};

bool NWScriptI::getObjectSeen(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, const Ice::Current& ice) {
  lock("getObjectSeen"); callCounter += 1;
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(289, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getObjectSeen");
  return nRetVal != 0;
};

NWN::ObjectType NWScriptI::getObjectType(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getObjectType"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(106, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getObjectType");
  if (nRetVal == 16) return NWN::AOE;
  if (nRetVal == 0) return NWN::InvalidObject;
  if (nRetVal == 1) return NWN::Creature;
  if (nRetVal == 128) return NWN::Store;
  if (nRetVal == 2) return NWN::Item;
  if (nRetVal == 8) return NWN::Door;
  if (nRetVal == 256) return NWN::Encounter;
  if (nRetVal == 32767) return NWN::All;
  if (nRetVal == 64) return NWN::Placeable;
  if (nRetVal == 4) return NWN::Trigger;
  if (nRetVal == 32) return NWN::Waypoint;
  throw "Error: Unmapped enum return type";
};

std::string NWScriptI::getPCChatMessage(const Ice::Current& ice) {
  lock("getPCChatMessage"); callCounter += 1;

  VM_ExecuteCommand(839, 0);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getPCChatMessage");
  return std::string(sRetVal);
};

NWN::NWObject NWScriptI::getPCChatSpeaker(const Ice::Current& ice) {
  lock("getPCChatSpeaker"); callCounter += 1;

  VM_ExecuteCommand(838, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getPCChatSpeaker");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getPCChatVolume(const Ice::Current& ice) {
  lock("getPCChatVolume"); callCounter += 1;

  VM_ExecuteCommand(840, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getPCChatVolume");
  return nRetVal;
};

std::string NWScriptI::getPCIPAddress(const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("getPCIPAddress"); callCounter += 1;
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(370, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getPCIPAddress");
  return std::string(sRetVal);
};

NWN::NWObject NWScriptI::getPCItemLastEquipped(const Ice::Current& ice) {
  lock("getPCItemLastEquipped"); callCounter += 1;

  VM_ExecuteCommand(727, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getPCItemLastEquipped");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getPCItemLastEquippedBy(const Ice::Current& ice) {
  lock("getPCItemLastEquippedBy"); callCounter += 1;

  VM_ExecuteCommand(728, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getPCItemLastEquippedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getPCItemLastUnequipped(const Ice::Current& ice) {
  lock("getPCItemLastUnequipped"); callCounter += 1;

  VM_ExecuteCommand(729, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getPCItemLastUnequipped");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getPCItemLastUnequippedBy(const Ice::Current& ice) {
  lock("getPCItemLastUnequippedBy"); callCounter += 1;

  VM_ExecuteCommand(730, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getPCItemLastUnequippedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::NWObject NWScriptI::getPCLevellingUp(const Ice::Current& ice) {
  lock("getPCLevellingUp"); callCounter += 1;

  VM_ExecuteCommand(542, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getPCLevellingUp");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

std::string NWScriptI::getPCPlayerName(const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("getPCPlayerName"); callCounter += 1;
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(371, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getPCPlayerName");
  return std::string(sRetVal);
};

std::string NWScriptI::getPCPublicCDKey(const NWN::NWObject& oPlayer, bool bSinglePlayerCDKey, const Ice::Current& ice) {
  lock("getPCPublicCDKey"); callCounter += 1;
  StackPushInteger(bSinglePlayerCDKey == true ? 1 : 0);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(369, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getPCPublicCDKey");
  return std::string(sRetVal);
};

NWN::NWObject NWScriptI::getPCSpeaker(const Ice::Current& ice) {
  lock("getPCSpeaker"); callCounter += 1;

  VM_ExecuteCommand(238, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getPCSpeaker");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

NWN::PhenoType NWScriptI::getPhenoType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getPhenoType"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(778, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getPhenoType");
  if (nRetVal == 16) return NWN::Custom14PhenoType;
  if (nRetVal == 5) return NWN::Custom3PhenoType;
  if (nRetVal == 11) return NWN::Custom9PhenoType;
  if (nRetVal == 0) return NWN::NormalPhenoType;
  if (nRetVal == 17) return NWN::Custom15PhenoType;
  if (nRetVal == 6) return NWN::Custom4PhenoType;
  if (nRetVal == 12) return NWN::Custom10PhenoType;
  if (nRetVal == 18) return NWN::Custom16PhenoType;
  if (nRetVal == 7) return NWN::Custom5PhenoType;
  if (nRetVal == 13) return NWN::Custom11PhenoType;
  if (nRetVal == 2) return NWN::BigPhenoType;
  if (nRetVal == 19) return NWN::Custom17PhenoType;
  if (nRetVal == 8) return NWN::Custom6PhenoType;
  if (nRetVal == 14) return NWN::Custom12PhenoType;
  if (nRetVal == 3) return NWN::Custom1PhenoType;
  if (nRetVal == 20) return NWN::Custom18PhenoType;
  if (nRetVal == 9) return NWN::Custom7PhenoType;
  if (nRetVal == 15) return NWN::Custom13PhenoType;
  if (nRetVal == 4) return NWN::Custom2PhenoType;
  if (nRetVal == 10) return NWN::Custom8PhenoType;
  throw "Error: Unmapped enum return type";
};

bool NWScriptI::getPickpocketableFlag(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getPickpocketableFlag"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(786, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getPickpocketableFlag");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getPlaceableIllumination(const NWN::NWObject& oPlaceable, const Ice::Current& ice) {
  lock("getPlaceableIllumination"); callCounter += 1;
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(545, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getPlaceableIllumination");
  return nRetVal;
};

NWN::NWObject NWScriptI::getPlaceableLastClickedBy(const Ice::Current& ice) {
  lock("getPlaceableLastClickedBy"); callCounter += 1;

  VM_ExecuteCommand(826, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getPlaceableLastClickedBy");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getPlotFlag(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getPlotFlag"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(455, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getPlotFlag");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getPortraitId(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getPortraitId"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(831, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getPortraitId");
  return nRetVal;
};

std::string NWScriptI::getPortraitResRef(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getPortraitResRef"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(833, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getPortraitResRef");
  return std::string(sRetVal);
};

NWN::NWVector NWScriptI::getPosition(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getPosition"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(27, 1);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock("getPosition");
  return nv;
};

NWN::NWVector NWScriptI::getPositionFromLocation(const NWN::NWLocation& lLocation, const Ice::Current& ice) {
  lock("getPositionFromLocation"); callCounter += 1;
  CScriptLocation *lLocation_ptr;
  lLocation_ptr->X = lLocation.x;
  lLocation_ptr->Y = lLocation.y;
  lLocation_ptr->Z = lLocation.z;
  lLocation_ptr->OrientationX = lLocation.orientationX;
  lLocation_ptr->OrientationY = lLocation.orientationY;
  lLocation_ptr->OrientationZ = lLocation.orientationZ;
  lLocation_ptr->AreaID = lLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lLocation_ptr);

  VM_ExecuteCommand(223, 1);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock("getPositionFromLocation");
  return nv;
};

NWN::RacialType NWScriptI::getRacialType(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getRacialType"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(107, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getRacialType");
  if (nRetVal == 16) return NWN::ElementalRace;
  if (nRetVal == 5) return NWN::HalforcRace;
  if (nRetVal == 11) return NWN::DragonRace;
  if (nRetVal == 0) return NWN::DwarfRace;
  if (nRetVal == 28) return NWN::InvalidRace;
  if (nRetVal == 17) return NWN::FeyRace;
  if (nRetVal == 6) return NWN::HumanRace;
  if (nRetVal == 23) return NWN::ShapechangerRace;
  if (nRetVal == 12) return NWN::HumanoidGoblinoidRace;
  if (nRetVal == 1) return NWN::ElfRace;
  if (nRetVal == 29) return NWN::OozeRace;
  if (nRetVal == 18) return NWN::GiantRace;
  if (nRetVal == 7) return NWN::AberrationRace;
  if (nRetVal == 24) return NWN::UndeadRace;
  if (nRetVal == 13) return NWN::HumanoidMonstrousRace;
  if (nRetVal == 2) return NWN::GnomeRace;
  if (nRetVal == 19) return NWN::MagicalBeastRace;
  if (nRetVal == 8) return NWN::AnimalRace;
  if (nRetVal == 25) return NWN::VerminRace;
  if (nRetVal == 14) return NWN::HumanoidOrcRace;
  if (nRetVal == 3) return NWN::HalflingRace;
  if (nRetVal == 20) return NWN::OutsiderRace;
  if (nRetVal == 9) return NWN::BeastRace;
  if (nRetVal == 15) return NWN::HumanoidReptilianRace;
  if (nRetVal == 4) return NWN::HalfelfRace;
  if (nRetVal == 10) return NWN::ConstructRace;
  throw "Error: Unmapped enum return type";
};

Ice::Int NWScriptI::getReflexAdjustedDamage(Ice::Int nDamage, const NWN::NWObject& oTarget, Ice::Int nDC, NWN::SaveType tSaveType, const NWN::NWObject& oSaveVersus, const Ice::Current& ice) {
  lock("getReflexAdjustedDamage"); callCounter += 1;
  StackPushObject(oSaveVersus.id);
  if (tSaveType == NWN::GoodSaveType) StackPushInteger(16);
   else if (tSaveType == NWN::SonicSaveType) StackPushInteger(5);
   else if (tSaveType == NWN::DeathSaveType) StackPushInteger(11);
   else if (tSaveType == NWN::AllOrNoneSaveType) StackPushInteger(0);
   else if (tSaveType == NWN::EvilSaveType) StackPushInteger(17);
   else if (tSaveType == NWN::AcidSaveType) StackPushInteger(6);
   else if (tSaveType == NWN::ColdSaveType) StackPushInteger(12);
   else if (tSaveType == NWN::MindSpellsSaveType) StackPushInteger(1);
   else if (tSaveType == NWN::LawSaveType) StackPushInteger(18);
   else if (tSaveType == NWN::FireSaveType) StackPushInteger(7);
   else if (tSaveType == NWN::DivineSaveType) StackPushInteger(13);
   else if (tSaveType == NWN::PoisonSaveType) StackPushInteger(2);
   else if (tSaveType == NWN::ChaosSaveType) StackPushInteger(19);
   else if (tSaveType == NWN::ElectricitySaveType) StackPushInteger(8);
   else if (tSaveType == NWN::TrapSaveType) StackPushInteger(14);
   else if (tSaveType == NWN::DiseaseSaveType) StackPushInteger(3);
   else if (tSaveType == NWN::PositiveSaveType) StackPushInteger(9);
   else if (tSaveType == NWN::SpellSaveType) StackPushInteger(15);
   else if (tSaveType == NWN::FearSaveType) StackPushInteger(4);
   else if (tSaveType == NWN::NegativeSaveType) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushInteger(nDC);
  StackPushObject(oTarget.id);
  StackPushInteger(nDamage);

  VM_ExecuteCommand(299, 5);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getReflexAdjustedDamage");
  return nRetVal;
};

Ice::Int NWScriptI::getReflexSavingThrow(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getReflexSavingThrow"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(493, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getReflexSavingThrow");
  return nRetVal;
};

Ice::Int NWScriptI::getReputation(const NWN::NWObject& oSource, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getReputation"); callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oSource.id);

  VM_ExecuteCommand(208, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getReputation");
  return nRetVal;
};

std::string NWScriptI::getResRef(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getResRef"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(582, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getResRef");
  return std::string(sRetVal);
};

NWN::NWObject NWScriptI::getSittingCreature(const NWN::NWObject& oChair, const Ice::Current& ice) {
  lock("getSittingCreature"); callCounter += 1;
  StackPushObject(oChair.id);

  VM_ExecuteCommand(210, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getSittingCreature");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getSkillRank(Ice::Int nSkill, const NWN::NWObject& oTarget, bool bBaseSkillRank, const Ice::Current& ice) {
  lock("getSkillRank"); callCounter += 1;
  StackPushInteger(bBaseSkillRank == true ? 1 : 0);
  StackPushObject(oTarget.id);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(315, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getSkillRank");
  return nRetVal;
};

Ice::Int NWScriptI::getSkyBox(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("getSkyBox"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(782, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getSkyBox");
  return nRetVal;
};

NWN::NWObject NWScriptI::getSpellCastItem(const Ice::Current& ice) {
  lock("getSpellCastItem"); callCounter += 1;

  VM_ExecuteCommand(438, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getSpellCastItem");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getSpellId(const Ice::Current& ice) {
  lock("getSpellId"); callCounter += 1;

  VM_ExecuteCommand(248, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getSpellId");
  return nRetVal;
};

Ice::Int NWScriptI::getSpellResistance(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getSpellResistance"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(749, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getSpellResistance");
  return nRetVal;
};

Ice::Int NWScriptI::getSpellSaveDC(const Ice::Current& ice) {
  lock("getSpellSaveDC"); callCounter += 1;

  VM_ExecuteCommand(111, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getSpellSaveDC");
  return nRetVal;
};

NWN::NWLocation NWScriptI::getSpellTargetLocation(const Ice::Current& ice) {
  lock("getSpellTargetLocation"); callCounter += 1;

  VM_ExecuteCommand(222, 0);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.x = pRetVal->X;
  nl.y = pRetVal->X;
  nl.z = pRetVal->X;
  nl.orientationX = pRetVal->OrientationX;
  nl.orientationY = pRetVal->OrientationY;
  nl.orientationZ = pRetVal->OrientationZ;
  nl.area.id = pRetVal->AreaID;
  unlock("getSpellTargetLocation");
  return nl;
};

NWN::NWObject NWScriptI::getSpellTargetObject(const Ice::Current& ice) {
  lock("getSpellTargetObject"); callCounter += 1;

  VM_ExecuteCommand(47, 0);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getSpellTargetObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getStandardFactionReputation(NWN::StandardFaction tStandardFaction, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getStandardFactionReputation"); callCounter += 1;
  StackPushObject(oCreature.id);
  if (tStandardFaction == NWN::Hostile) StackPushInteger(0);
   else if (tStandardFaction == NWN::Commoner) StackPushInteger(1);
   else if (tStandardFaction == NWN::Merchant) StackPushInteger(2);
   else if (tStandardFaction == NWN::Defender) StackPushInteger(3);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(524, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getStandardFactionReputation");
  return nRetVal;
};

NWN::NWLocation NWScriptI::getStartingLocation(const Ice::Current& ice) {
  lock("getStartingLocation"); callCounter += 1;

  VM_ExecuteCommand(411, 0);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.x = pRetVal->X;
  nl.y = pRetVal->X;
  nl.z = pRetVal->X;
  nl.orientationX = pRetVal->OrientationX;
  nl.orientationY = pRetVal->OrientationY;
  nl.orientationZ = pRetVal->OrientationZ;
  nl.area.id = pRetVal->AreaID;
  unlock("getStartingLocation");
  return nl;
};

Ice::Int NWScriptI::getStealthMode(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getStealthMode"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(574, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getStealthMode");
  return nRetVal;
};

bool NWScriptI::getStolenFlag(const NWN::NWObject& oStolen, const Ice::Current& ice) {
  lock("getStolenFlag"); callCounter += 1;
  StackPushObject(oStolen.id);

  VM_ExecuteCommand(588, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getStolenFlag");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getStoreGold(const NWN::NWObject& oidStore, const Ice::Current& ice) {
  lock("getStoreGold"); callCounter += 1;
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(759, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getStoreGold");
  return nRetVal;
};

Ice::Int NWScriptI::getStoreIdentifyCost(const NWN::NWObject& oidStore, const Ice::Current& ice) {
  lock("getStoreIdentifyCost"); callCounter += 1;
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(763, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getStoreIdentifyCost");
  return nRetVal;
};

Ice::Int NWScriptI::getStoreMaxBuyPrice(const NWN::NWObject& oidStore, const Ice::Current& ice) {
  lock("getStoreMaxBuyPrice"); callCounter += 1;
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(761, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getStoreMaxBuyPrice");
  return nRetVal;
};

Ice::Double NWScriptI::getStrRefSoundDuration(Ice::Int nStrRef, const Ice::Current& ice) {
  lock("getStrRefSoundDuration"); callCounter += 1;
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(571, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("getStrRefSoundDuration");
  return fRetVal;
};

std::string NWScriptI::getStringByStrRef(Ice::Int nStrRef, NWN::Gender tGender, const Ice::Current& ice) {
  lock("getStringByStrRef"); callCounter += 1;
  if (tGender == NWN::MaleGender) StackPushInteger(0);
   else if (tGender == NWN::Female) StackPushInteger(1);
   else if (tGender == NWN::BothGender) StackPushInteger(2);
   else if (tGender == NWN::OtherGender) StackPushInteger(3);
   else if (tGender == NWN::NoneGender) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(239, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getStringByStrRef");
  return std::string(sRetVal);
};

std::string NWScriptI::getStringLeft(const std::string& sString, Ice::Int nCount, const Ice::Current& ice) {
  lock("getStringLeft"); callCounter += 1;
  StackPushInteger(nCount);
  StackPushString(sString.c_str());

  VM_ExecuteCommand(63, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getStringLeft");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getStringLength(const std::string& sString, const Ice::Current& ice) {
  lock("getStringLength"); callCounter += 1;
  StackPushString(sString.c_str());

  VM_ExecuteCommand(59, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getStringLength");
  return nRetVal;
};

std::string NWScriptI::getStringLowerCase(const std::string& sString, const Ice::Current& ice) {
  lock("getStringLowerCase"); callCounter += 1;
  StackPushString(sString.c_str());

  VM_ExecuteCommand(61, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getStringLowerCase");
  return std::string(sRetVal);
};

std::string NWScriptI::getStringRight(const std::string& sString, Ice::Int nCount, const Ice::Current& ice) {
  lock("getStringRight"); callCounter += 1;
  StackPushInteger(nCount);
  StackPushString(sString.c_str());

  VM_ExecuteCommand(62, 2);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getStringRight");
  return std::string(sRetVal);
};

std::string NWScriptI::getStringUpperCase(const std::string& sString, const Ice::Current& ice) {
  lock("getStringUpperCase"); callCounter += 1;
  StackPushString(sString.c_str());

  VM_ExecuteCommand(60, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getStringUpperCase");
  return std::string(sRetVal);
};

std::string NWScriptI::getSubRace(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getSubRace"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(490, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getSubRace");
  return std::string(sRetVal);
};

std::string NWScriptI::getSubString(const std::string& sString, Ice::Int nStart, Ice::Int nCount, const Ice::Current& ice) {
  lock("getSubString"); callCounter += 1;
  StackPushInteger(nCount);
  StackPushInteger(nStart);
  StackPushString(sString.c_str());

  VM_ExecuteCommand(65, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getSubString");
  return std::string(sRetVal);
};

std::string NWScriptI::getTag(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getTag"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(168, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getTag");
  return std::string(sRetVal);
};

NWN::TileMainLightColor NWScriptI::getTileMainLight1Color(const NWN::NWLocation& lTile, const Ice::Current& ice) {
  lock("getTileMainLight1Color"); callCounter += 1;
  CScriptLocation *lTile_ptr;
  lTile_ptr->X = lTile.x;
  lTile_ptr->Y = lTile.y;
  lTile_ptr->Z = lTile.z;
  lTile_ptr->OrientationX = lTile.orientationX;
  lTile_ptr->OrientationY = lTile.orientationY;
  lTile_ptr->OrientationZ = lTile.orientationZ;
  lTile_ptr->AreaID = lTile.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile_ptr);

  VM_ExecuteCommand(517, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTileMainLight1Color");
  if (nRetVal == 27) return NWN::RedTileMainLightColor;
  if (nRetVal == 16) return NWN::PaleDarkBlueTileMainLightColor;
  if (nRetVal == 5) return NWN::DarkYellowTileMainLightColor;
  if (nRetVal == 22) return NWN::PalePurpleTileMainLightColor;
  if (nRetVal == 11) return NWN::GreenTileMainLightColor;
  if (nRetVal == 0) return NWN::BlackTileMainLightColor;
  if (nRetVal == 28) return NWN::PaleDarkOrangeTileMainLightColor;
  if (nRetVal == 17) return NWN::DarkBlueTileMainLightColor;
  if (nRetVal == 6) return NWN::PaleYellowTileMainLightColor;
  if (nRetVal == 23) return NWN::PurpleTileMainLightColor;
  if (nRetVal == 12) return NWN::PaleDarkAquaTileMainLightColor;
  if (nRetVal == 1) return NWN::DimWhiteTileMainLightColor;
  if (nRetVal == 29) return NWN::DarkOrangeTileMainLightColor;
  if (nRetVal == 18) return NWN::PaleBlueTileMainLightColor;
  if (nRetVal == 7) return NWN::YellowTileMainLightColor;
  if (nRetVal == 24) return NWN::PaleDarkRedTileMainLightColor;
  if (nRetVal == 13) return NWN::DarkAquaTileMainLightColor;
  if (nRetVal == 2) return NWN::WhiteTileMainLightColor;
  if (nRetVal == 30) return NWN::PaleOrangeTileMainLightColor;
  if (nRetVal == 19) return NWN::BlueTileMainLightColor;
  if (nRetVal == 8) return NWN::PaleDarkGreenTileMainLightColor;
  if (nRetVal == 25) return NWN::DarkRedTileMainLightColor;
  if (nRetVal == 14) return NWN::PaleAquaTileMainLightColor;
  if (nRetVal == 3) return NWN::BrightWhiteTileMainLightColor;
  if (nRetVal == 31) return NWN::OrangeTileMainLightColor;
  if (nRetVal == 20) return NWN::PaleDarkPurpleTileMainLightColor;
  if (nRetVal == 9) return NWN::DarkGreenTileMainLightColor;
  if (nRetVal == 26) return NWN::PaleRedTileMainLightColor;
  if (nRetVal == 15) return NWN::AquaTileMainLightColor;
  if (nRetVal == 4) return NWN::PaleDarkYellowTileMainLightColor;
  if (nRetVal == 21) return NWN::DarkPurpleTileMainLightColor;
  if (nRetVal == 10) return NWN::PaleGreenTileMainLightColor;
  throw "Error: Unmapped enum return type";
};

NWN::TileMainLightColor NWScriptI::getTileMainLight2Color(const NWN::NWLocation& lTile, const Ice::Current& ice) {
  lock("getTileMainLight2Color"); callCounter += 1;
  CScriptLocation *lTile_ptr;
  lTile_ptr->X = lTile.x;
  lTile_ptr->Y = lTile.y;
  lTile_ptr->Z = lTile.z;
  lTile_ptr->OrientationX = lTile.orientationX;
  lTile_ptr->OrientationY = lTile.orientationY;
  lTile_ptr->OrientationZ = lTile.orientationZ;
  lTile_ptr->AreaID = lTile.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile_ptr);

  VM_ExecuteCommand(518, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTileMainLight2Color");
  if (nRetVal == 27) return NWN::RedTileMainLightColor;
  if (nRetVal == 16) return NWN::PaleDarkBlueTileMainLightColor;
  if (nRetVal == 5) return NWN::DarkYellowTileMainLightColor;
  if (nRetVal == 22) return NWN::PalePurpleTileMainLightColor;
  if (nRetVal == 11) return NWN::GreenTileMainLightColor;
  if (nRetVal == 0) return NWN::BlackTileMainLightColor;
  if (nRetVal == 28) return NWN::PaleDarkOrangeTileMainLightColor;
  if (nRetVal == 17) return NWN::DarkBlueTileMainLightColor;
  if (nRetVal == 6) return NWN::PaleYellowTileMainLightColor;
  if (nRetVal == 23) return NWN::PurpleTileMainLightColor;
  if (nRetVal == 12) return NWN::PaleDarkAquaTileMainLightColor;
  if (nRetVal == 1) return NWN::DimWhiteTileMainLightColor;
  if (nRetVal == 29) return NWN::DarkOrangeTileMainLightColor;
  if (nRetVal == 18) return NWN::PaleBlueTileMainLightColor;
  if (nRetVal == 7) return NWN::YellowTileMainLightColor;
  if (nRetVal == 24) return NWN::PaleDarkRedTileMainLightColor;
  if (nRetVal == 13) return NWN::DarkAquaTileMainLightColor;
  if (nRetVal == 2) return NWN::WhiteTileMainLightColor;
  if (nRetVal == 30) return NWN::PaleOrangeTileMainLightColor;
  if (nRetVal == 19) return NWN::BlueTileMainLightColor;
  if (nRetVal == 8) return NWN::PaleDarkGreenTileMainLightColor;
  if (nRetVal == 25) return NWN::DarkRedTileMainLightColor;
  if (nRetVal == 14) return NWN::PaleAquaTileMainLightColor;
  if (nRetVal == 3) return NWN::BrightWhiteTileMainLightColor;
  if (nRetVal == 31) return NWN::OrangeTileMainLightColor;
  if (nRetVal == 20) return NWN::PaleDarkPurpleTileMainLightColor;
  if (nRetVal == 9) return NWN::DarkGreenTileMainLightColor;
  if (nRetVal == 26) return NWN::PaleRedTileMainLightColor;
  if (nRetVal == 15) return NWN::AquaTileMainLightColor;
  if (nRetVal == 4) return NWN::PaleDarkYellowTileMainLightColor;
  if (nRetVal == 21) return NWN::DarkPurpleTileMainLightColor;
  if (nRetVal == 10) return NWN::PaleGreenTileMainLightColor;
  throw "Error: Unmapped enum return type";
};

NWN::TileSourceLightColor NWScriptI::getTileSourceLight1Color(const NWN::NWLocation& lTile, const Ice::Current& ice) {
  lock("getTileSourceLight1Color"); callCounter += 1;
  CScriptLocation *lTile_ptr;
  lTile_ptr->X = lTile.x;
  lTile_ptr->Y = lTile.y;
  lTile_ptr->Z = lTile.z;
  lTile_ptr->OrientationX = lTile.orientationX;
  lTile_ptr->OrientationY = lTile.orientationY;
  lTile_ptr->OrientationZ = lTile.orientationZ;
  lTile_ptr->AreaID = lTile.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile_ptr);

  VM_ExecuteCommand(519, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTileSourceLight1Color");
  if (nRetVal == 5) return NWN::PaleGreenTileSourceLightColor;
  if (nRetVal == 11) return NWN::PalePurpleTileSourceLightColor;
  if (nRetVal == 0) return NWN::BlackTileSourceLightColor;
  if (nRetVal == 6) return NWN::PaleDarkAquaTileSourceLightColor;
  if (nRetVal == 12) return NWN::PaleDarkRedTileSourceLightColor;
  if (nRetVal == 1) return NWN::WhiteTileSourceLightColor;
  if (nRetVal == 7) return NWN::PaleAquaTileSourceLightColor;
  if (nRetVal == 13) return NWN::PaleRedTileSourceLightColor;
  if (nRetVal == 2) return NWN::PaleDarkYellowTileSourceLightColor;
  if (nRetVal == 8) return NWN::PaleDarkBlueTileSourceLightColor;
  if (nRetVal == 14) return NWN::PaleDarkOrangeTileSourceLightColor;
  if (nRetVal == 3) return NWN::PaleYellowTileSourceLightColor;
  if (nRetVal == 9) return NWN::PaleBlueTileSourceLightColor;
  if (nRetVal == 15) return NWN::PaleOrangeTileSourceLightColor;
  if (nRetVal == 4) return NWN::PaleDarkGreenTileSourceLightColor;
  if (nRetVal == 10) return NWN::PaleDarkPurpleTileSourceLightColor;
  throw "Error: Unmapped enum return type";
};

NWN::TileSourceLightColor NWScriptI::getTileSourceLight2Color(const NWN::NWLocation& lTile, const Ice::Current& ice) {
  lock("getTileSourceLight2Color"); callCounter += 1;
  CScriptLocation *lTile_ptr;
  lTile_ptr->X = lTile.x;
  lTile_ptr->Y = lTile.y;
  lTile_ptr->Z = lTile.z;
  lTile_ptr->OrientationX = lTile.orientationX;
  lTile_ptr->OrientationY = lTile.orientationY;
  lTile_ptr->OrientationZ = lTile.orientationZ;
  lTile_ptr->AreaID = lTile.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTile_ptr);

  VM_ExecuteCommand(520, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTileSourceLight2Color");
  if (nRetVal == 5) return NWN::PaleGreenTileSourceLightColor;
  if (nRetVal == 11) return NWN::PalePurpleTileSourceLightColor;
  if (nRetVal == 0) return NWN::BlackTileSourceLightColor;
  if (nRetVal == 6) return NWN::PaleDarkAquaTileSourceLightColor;
  if (nRetVal == 12) return NWN::PaleDarkRedTileSourceLightColor;
  if (nRetVal == 1) return NWN::WhiteTileSourceLightColor;
  if (nRetVal == 7) return NWN::PaleAquaTileSourceLightColor;
  if (nRetVal == 13) return NWN::PaleRedTileSourceLightColor;
  if (nRetVal == 2) return NWN::PaleDarkYellowTileSourceLightColor;
  if (nRetVal == 8) return NWN::PaleDarkBlueTileSourceLightColor;
  if (nRetVal == 14) return NWN::PaleDarkOrangeTileSourceLightColor;
  if (nRetVal == 3) return NWN::PaleYellowTileSourceLightColor;
  if (nRetVal == 9) return NWN::PaleBlueTileSourceLightColor;
  if (nRetVal == 15) return NWN::PaleOrangeTileSourceLightColor;
  if (nRetVal == 4) return NWN::PaleDarkGreenTileSourceLightColor;
  if (nRetVal == 10) return NWN::PaleDarkPurpleTileSourceLightColor;
  throw "Error: Unmapped enum return type";
};

std::string NWScriptI::getTilesetResRef(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("getTilesetResRef"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(814, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getTilesetResRef");
  return std::string(sRetVal);
};

Ice::Int NWScriptI::getTimeHour(const Ice::Current& ice) {
  lock("getTimeHour"); callCounter += 1;

  VM_ExecuteCommand(16, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTimeHour");
  return nRetVal;
};

Ice::Int NWScriptI::getTimeMillisecond(const Ice::Current& ice) {
  lock("getTimeMillisecond"); callCounter += 1;

  VM_ExecuteCommand(19, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTimeMillisecond");
  return nRetVal;
};

Ice::Int NWScriptI::getTimeMinute(const Ice::Current& ice) {
  lock("getTimeMinute"); callCounter += 1;

  VM_ExecuteCommand(17, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTimeMinute");
  return nRetVal;
};

Ice::Int NWScriptI::getTimeSecond(const Ice::Current& ice) {
  lock("getTimeSecond"); callCounter += 1;

  VM_ExecuteCommand(18, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTimeSecond");
  return nRetVal;
};

Ice::Int NWScriptI::getTotalDamageDealt(const Ice::Current& ice) {
  lock("getTotalDamageDealt"); callCounter += 1;

  VM_ExecuteCommand(345, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTotalDamageDealt");
  return nRetVal;
};

NWN::NWObject NWScriptI::getTransitionTarget(const NWN::NWObject& oTransition, const Ice::Current& ice) {
  lock("getTransitionTarget"); callCounter += 1;
  StackPushObject(oTransition.id);

  VM_ExecuteCommand(198, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getTransitionTarget");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getTrapActive(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  lock("getTrapActive"); callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(821, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTrapActive");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getTrapBaseType(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  lock("getTrapBaseType"); callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(531, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTrapBaseType");
  return nRetVal;
};

NWN::NWObject NWScriptI::getTrapCreator(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  lock("getTrapCreator"); callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(533, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getTrapCreator");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Int NWScriptI::getTrapDetectDC(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  lock("getTrapDetectDC"); callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(536, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTrapDetectDC");
  return nRetVal;
};

bool NWScriptI::getTrapDetectable(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  lock("getTrapDetectable"); callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(528, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTrapDetectable");
  return nRetVal != 0;
};

bool NWScriptI::getTrapDetectedBy(const NWN::NWObject& oTrapObject, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getTrapDetectedBy"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(529, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTrapDetectedBy");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getTrapDisarmDC(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  lock("getTrapDisarmDC"); callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(535, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTrapDisarmDC");
  return nRetVal;
};

bool NWScriptI::getTrapDisarmable(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  lock("getTrapDisarmable"); callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(527, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTrapDisarmable");
  return nRetVal != 0;
};

bool NWScriptI::getTrapFlagged(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  lock("getTrapFlagged"); callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(530, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTrapFlagged");
  return nRetVal != 0;
};

std::string NWScriptI::getTrapKeyTag(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  lock("getTrapKeyTag"); callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(534, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("getTrapKeyTag");
  return std::string(sRetVal);
};

bool NWScriptI::getTrapOneShot(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  lock("getTrapOneShot"); callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(532, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTrapOneShot");
  return nRetVal != 0;
};

bool NWScriptI::getTrapRecoverable(const NWN::NWObject& oTrapObject, const Ice::Current& ice) {
  lock("getTrapRecoverable"); callCounter += 1;
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(815, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTrapRecoverable");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getTurnResistanceHD(const NWN::NWObject& oUndead, const Ice::Current& ice) {
  lock("getTurnResistanceHD"); callCounter += 1;
  StackPushObject(oUndead.id);

  VM_ExecuteCommand(478, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getTurnResistanceHD");
  return nRetVal;
};

bool NWScriptI::getUseableFlag(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("getUseableFlag"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(587, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getUseableFlag");
  return nRetVal != 0;
};

Ice::Int NWScriptI::getUserDefinedEventNumber(const Ice::Current& ice) {
  lock("getUserDefinedEventNumber"); callCounter += 1;

  VM_ExecuteCommand(247, 0);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getUserDefinedEventNumber");
  return nRetVal;
};

NWN::NWObject NWScriptI::getWaypointByTag(const std::string& sWaypointTag, const Ice::Current& ice) {
  lock("getWaypointByTag"); callCounter += 1;
  StackPushString(sWaypointTag.c_str());

  VM_ExecuteCommand(197, 1);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("getWaypointByTag");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

bool NWScriptI::getWeaponRanged(const NWN::NWObject& oItem, const Ice::Current& ice) {
  lock("getWeaponRanged"); callCounter += 1;
  StackPushObject(oItem.id);

  VM_ExecuteCommand(511, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getWeaponRanged");
  return nRetVal != 0;
};

NWN::Weather NWScriptI::getWeather(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("getWeather"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(724, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getWeather");
  if (nRetVal == 0) return NWN::ClearWeather;
  if (nRetVal == 1) return NWN::RainWeather;
  if (nRetVal == -1) return NWN::InvalidWeather;
  if (nRetVal == 2) return NWN::SnowWeather;
  if (nRetVal == 3) return NWN::AreaDefaultsWeather;
  throw "Error: Unmapped enum return type";
};

Ice::Int NWScriptI::getWeight(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getWeight"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(706, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getWeight");
  return nRetVal;
};

Ice::Int NWScriptI::getWillSavingThrow(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("getWillSavingThrow"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(492, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getWillSavingThrow");
  return nRetVal;
};

Ice::Int NWScriptI::getXP(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("getXP"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(395, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("getXP");
  return nRetVal;
};

void NWScriptI::giveGoldToCreature(const NWN::NWObject& oCreature, Ice::Int nGP, const Ice::Current& ice) {
  lock("giveGoldToCreature"); callCounter += 1;
  StackPushInteger(nGP);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(322, 2);

unlock("giveGoldToCreature");
  
};

void NWScriptI::giveXPToCreature(const NWN::NWObject& oCreature, Ice::Int nXpAmount, const Ice::Current& ice) {
  lock("giveXPToCreature"); callCounter += 1;
  StackPushInteger(nXpAmount);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(393, 2);

unlock("giveXPToCreature");
  
};

Ice::Double NWScriptI::hoursToSeconds(Ice::Int nHours, const Ice::Current& ice) {
  lock("hoursToSeconds"); callCounter += 1;
  StackPushInteger(nHours);

  VM_ExecuteCommand(122, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("hoursToSeconds");
  return fRetVal;
};

void NWScriptI::incrementRemainingFeatUses(const NWN::NWObject& oCreature, Ice::Int nFeat, const Ice::Current& ice) {
  lock("incrementRemainingFeatUses"); callCounter += 1;
  StackPushInteger(nFeat);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(718, 2);

unlock("incrementRemainingFeatUses");
  
};

std::string NWScriptI::insertString(const std::string& sDestination, const std::string& sString, Ice::Int nPosition, const Ice::Current& ice) {
  lock("insertString"); callCounter += 1;
  StackPushInteger(nPosition);
  StackPushString(sString.c_str());
  StackPushString(sDestination.c_str());

  VM_ExecuteCommand(64, 3);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("insertString");
  return std::string(sRetVal);
};

Ice::Double NWScriptI::intToFloat(Ice::Int nInteger, const Ice::Current& ice) {
  lock("intToFloat"); callCounter += 1;
  StackPushInteger(nInteger);

  VM_ExecuteCommand(230, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("intToFloat");
  return fRetVal;
};

std::string NWScriptI::intToHexString(Ice::Int nInteger, const Ice::Current& ice) {
  lock("intToHexString"); callCounter += 1;
  StackPushInteger(nInteger);

  VM_ExecuteCommand(396, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("intToHexString");
  return std::string(sRetVal);
};

std::string NWScriptI::intToString(Ice::Int nInteger, const Ice::Current& ice) {
  lock("intToString"); callCounter += 1;
  StackPushInteger(nInteger);

  VM_ExecuteCommand(92, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("intToString");
  return std::string(sRetVal);
};

bool NWScriptI::isInConversation(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("isInConversation"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(445, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("isInConversation");
  return nRetVal != 0;
};

NWN::NWItemProperty NWScriptI::itemPropertyACBonus(Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyACBonus"); callCounter += 1;
  StackPushInteger(nBonus);

  VM_ExecuteCommand(617, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyACBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyACBonusVsAlign(Ice::Int nAlignGroup, Ice::Int nACBonus, const Ice::Current& ice) {
  lock("itemPropertyACBonusVsAlign"); callCounter += 1;
  StackPushInteger(nACBonus);
  StackPushInteger(nAlignGroup);

  VM_ExecuteCommand(618, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyACBonusVsAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyACBonusVsDmgType(Ice::Int nDamageType, Ice::Int nACBonus, const Ice::Current& ice) {
  lock("itemPropertyACBonusVsDmgType"); callCounter += 1;
  StackPushInteger(nACBonus);
  StackPushInteger(nDamageType);

  VM_ExecuteCommand(619, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyACBonusVsDmgType");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyACBonusVsRace(NWN::IPRacialType tIPRacialType, Ice::Int nACBonus, const Ice::Current& ice) {
  lock("itemPropertyACBonusVsRace"); callCounter += 1;
  StackPushInteger(nACBonus);
  if (tIPRacialType == NWN::ElementalIPRace) StackPushInteger(16);
   else if (tIPRacialType == NWN::HalforcIPRace) StackPushInteger(5);
   else if (tIPRacialType == NWN::DragonIPRace) StackPushInteger(11);
   else if (tIPRacialType == NWN::DwarfIPRace) StackPushInteger(0);
   else if (tIPRacialType == NWN::FeyIPRace) StackPushInteger(17);
   else if (tIPRacialType == NWN::HumanIPRace) StackPushInteger(6);
   else if (tIPRacialType == NWN::ShapechangerIPRace) StackPushInteger(23);
   else if (tIPRacialType == NWN::HumanoidGoblinoidIPRace) StackPushInteger(12);
   else if (tIPRacialType == NWN::ElfIPRace) StackPushInteger(1);
   else if (tIPRacialType == NWN::GiantIPRace) StackPushInteger(18);
   else if (tIPRacialType == NWN::AberrationIPRace) StackPushInteger(7);
   else if (tIPRacialType == NWN::UndeadIPRace) StackPushInteger(24);
   else if (tIPRacialType == NWN::HumanoidMonstrousIPRace) StackPushInteger(13);
   else if (tIPRacialType == NWN::GnomeIPRace) StackPushInteger(2);
   else if (tIPRacialType == NWN::MagicalBeastIPRace) StackPushInteger(19);
   else if (tIPRacialType == NWN::AnimalIPRace) StackPushInteger(8);
   else if (tIPRacialType == NWN::VerminIPRace) StackPushInteger(25);
   else if (tIPRacialType == NWN::HumanoidOrcIPRace) StackPushInteger(14);
   else if (tIPRacialType == NWN::HalflingIPRace) StackPushInteger(3);
   else if (tIPRacialType == NWN::OutsiderIPRace) StackPushInteger(20);
   else if (tIPRacialType == NWN::BeastIPRace) StackPushInteger(9);
   else if (tIPRacialType == NWN::HumanoidReptilianIPRace) StackPushInteger(15);
   else if (tIPRacialType == NWN::HalfelfIPRace) StackPushInteger(4);
   else if (tIPRacialType == NWN::ConstructIPRace) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(620, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyACBonusVsRace");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyACBonusVsSAlign(Ice::Int nAlign, Ice::Int nACBonus, const Ice::Current& ice) {
  lock("itemPropertyACBonusVsSAlign"); callCounter += 1;
  StackPushInteger(nACBonus);
  StackPushInteger(nAlign);

  VM_ExecuteCommand(621, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyACBonusVsSAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAbilityBonus(NWN::Ability tAbility, Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyAbilityBonus"); callCounter += 1;
  StackPushInteger(nBonus);
  if (tAbility == NWN::Charisma) StackPushInteger(5);
   else if (tAbility == NWN::Strength) StackPushInteger(0);
   else if (tAbility == NWN::Dexterity) StackPushInteger(1);
   else if (tAbility == NWN::Constitution) StackPushInteger(2);
   else if (tAbility == NWN::Intelligence) StackPushInteger(3);
   else if (tAbility == NWN::Wisdom) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(616, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyAbilityBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAdditional(Ice::Int nAdditionalProperty, const Ice::Current& ice) {
  lock("itemPropertyAdditional"); callCounter += 1;
  StackPushInteger(nAdditionalProperty);

  VM_ExecuteCommand(847, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyAdditional");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyArcaneSpellFailure(Ice::Int nModLevel, const Ice::Current& ice) {
  lock("itemPropertyArcaneSpellFailure"); callCounter += 1;
  StackPushInteger(nModLevel);

  VM_ExecuteCommand(758, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyArcaneSpellFailure");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAttackBonus(Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyAttackBonus"); callCounter += 1;
  StackPushInteger(nBonus);

  VM_ExecuteCommand(666, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyAttackBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAttackBonusVsAlign(Ice::Int nAlignGroup, Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyAttackBonusVsAlign"); callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(nAlignGroup);

  VM_ExecuteCommand(667, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyAttackBonusVsAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAttackBonusVsRace(NWN::IPRacialType tIPRacialType, Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyAttackBonusVsRace"); callCounter += 1;
  StackPushInteger(nBonus);
  if (tIPRacialType == NWN::ElementalIPRace) StackPushInteger(16);
   else if (tIPRacialType == NWN::HalforcIPRace) StackPushInteger(5);
   else if (tIPRacialType == NWN::DragonIPRace) StackPushInteger(11);
   else if (tIPRacialType == NWN::DwarfIPRace) StackPushInteger(0);
   else if (tIPRacialType == NWN::FeyIPRace) StackPushInteger(17);
   else if (tIPRacialType == NWN::HumanIPRace) StackPushInteger(6);
   else if (tIPRacialType == NWN::ShapechangerIPRace) StackPushInteger(23);
   else if (tIPRacialType == NWN::HumanoidGoblinoidIPRace) StackPushInteger(12);
   else if (tIPRacialType == NWN::ElfIPRace) StackPushInteger(1);
   else if (tIPRacialType == NWN::GiantIPRace) StackPushInteger(18);
   else if (tIPRacialType == NWN::AberrationIPRace) StackPushInteger(7);
   else if (tIPRacialType == NWN::UndeadIPRace) StackPushInteger(24);
   else if (tIPRacialType == NWN::HumanoidMonstrousIPRace) StackPushInteger(13);
   else if (tIPRacialType == NWN::GnomeIPRace) StackPushInteger(2);
   else if (tIPRacialType == NWN::MagicalBeastIPRace) StackPushInteger(19);
   else if (tIPRacialType == NWN::AnimalIPRace) StackPushInteger(8);
   else if (tIPRacialType == NWN::VerminIPRace) StackPushInteger(25);
   else if (tIPRacialType == NWN::HumanoidOrcIPRace) StackPushInteger(14);
   else if (tIPRacialType == NWN::HalflingIPRace) StackPushInteger(3);
   else if (tIPRacialType == NWN::OutsiderIPRace) StackPushInteger(20);
   else if (tIPRacialType == NWN::BeastIPRace) StackPushInteger(9);
   else if (tIPRacialType == NWN::HumanoidReptilianIPRace) StackPushInteger(15);
   else if (tIPRacialType == NWN::HalfelfIPRace) StackPushInteger(4);
   else if (tIPRacialType == NWN::ConstructIPRace) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(668, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyAttackBonusVsRace");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAttackBonusVsSAlign(Ice::Int nAlignment, Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyAttackBonusVsSAlign"); callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(nAlignment);

  VM_ExecuteCommand(669, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyAttackBonusVsSAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyAttackPenalty(Ice::Int nPenalty, const Ice::Current& ice) {
  lock("itemPropertyAttackPenalty"); callCounter += 1;
  StackPushInteger(nPenalty);

  VM_ExecuteCommand(670, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyAttackPenalty");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyBonusFeat(Ice::Int nFeat, const Ice::Current& ice) {
  lock("itemPropertyBonusFeat"); callCounter += 1;
  StackPushInteger(nFeat);

  VM_ExecuteCommand(628, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyBonusFeat");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyBonusLevelSpell(Ice::Int nClass, Ice::Int nSpellLevel, const Ice::Current& ice) {
  lock("itemPropertyBonusLevelSpell"); callCounter += 1;
  StackPushInteger(nSpellLevel);
  StackPushInteger(nClass);

  VM_ExecuteCommand(629, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyBonusLevelSpell");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyBonusSavingThrow(Ice::Int nBaseSaveType, Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyBonusSavingThrow"); callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(nBaseSaveType);

  VM_ExecuteCommand(653, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyBonusSavingThrow");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyBonusSavingThrowVsX(Ice::Int nBonusType, Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyBonusSavingThrowVsX"); callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(nBonusType);

  VM_ExecuteCommand(652, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyBonusSavingThrowVsX");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyBonusSpellResistance(Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyBonusSpellResistance"); callCounter += 1;
  StackPushInteger(nBonus);

  VM_ExecuteCommand(651, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyBonusSpellResistance");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyCastSpell(Ice::Int nSpell, Ice::Int nNumUses, const Ice::Current& ice) {
  lock("itemPropertyCastSpell"); callCounter += 1;
  StackPushInteger(nNumUses);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(630, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyCastSpell");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyContainerReducedWeight(Ice::Int nContainerType, const Ice::Current& ice) {
  lock("itemPropertyContainerReducedWeight"); callCounter += 1;
  StackPushInteger(nContainerType);

  VM_ExecuteCommand(644, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyContainerReducedWeight");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageBonus(Ice::Int nDamageType, Ice::Int nDamage, const Ice::Current& ice) {
  lock("itemPropertyDamageBonus"); callCounter += 1;
  StackPushInteger(nDamage);
  StackPushInteger(nDamageType);

  VM_ExecuteCommand(631, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDamageBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageBonusVsAlign(Ice::Int nAlignGroup, Ice::Int nDamageType, Ice::Int nDamage, const Ice::Current& ice) {
  lock("itemPropertyDamageBonusVsAlign"); callCounter += 1;
  StackPushInteger(nDamage);
  StackPushInteger(nDamageType);
  StackPushInteger(nAlignGroup);

  VM_ExecuteCommand(632, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDamageBonusVsAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageBonusVsRace(NWN::IPRacialType tIPRacialType, Ice::Int nDamageType, Ice::Int nDamage, const Ice::Current& ice) {
  lock("itemPropertyDamageBonusVsRace"); callCounter += 1;
  StackPushInteger(nDamage);
  StackPushInteger(nDamageType);
  if (tIPRacialType == NWN::ElementalIPRace) StackPushInteger(16);
   else if (tIPRacialType == NWN::HalforcIPRace) StackPushInteger(5);
   else if (tIPRacialType == NWN::DragonIPRace) StackPushInteger(11);
   else if (tIPRacialType == NWN::DwarfIPRace) StackPushInteger(0);
   else if (tIPRacialType == NWN::FeyIPRace) StackPushInteger(17);
   else if (tIPRacialType == NWN::HumanIPRace) StackPushInteger(6);
   else if (tIPRacialType == NWN::ShapechangerIPRace) StackPushInteger(23);
   else if (tIPRacialType == NWN::HumanoidGoblinoidIPRace) StackPushInteger(12);
   else if (tIPRacialType == NWN::ElfIPRace) StackPushInteger(1);
   else if (tIPRacialType == NWN::GiantIPRace) StackPushInteger(18);
   else if (tIPRacialType == NWN::AberrationIPRace) StackPushInteger(7);
   else if (tIPRacialType == NWN::UndeadIPRace) StackPushInteger(24);
   else if (tIPRacialType == NWN::HumanoidMonstrousIPRace) StackPushInteger(13);
   else if (tIPRacialType == NWN::GnomeIPRace) StackPushInteger(2);
   else if (tIPRacialType == NWN::MagicalBeastIPRace) StackPushInteger(19);
   else if (tIPRacialType == NWN::AnimalIPRace) StackPushInteger(8);
   else if (tIPRacialType == NWN::VerminIPRace) StackPushInteger(25);
   else if (tIPRacialType == NWN::HumanoidOrcIPRace) StackPushInteger(14);
   else if (tIPRacialType == NWN::HalflingIPRace) StackPushInteger(3);
   else if (tIPRacialType == NWN::OutsiderIPRace) StackPushInteger(20);
   else if (tIPRacialType == NWN::BeastIPRace) StackPushInteger(9);
   else if (tIPRacialType == NWN::HumanoidReptilianIPRace) StackPushInteger(15);
   else if (tIPRacialType == NWN::HalfelfIPRace) StackPushInteger(4);
   else if (tIPRacialType == NWN::ConstructIPRace) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(633, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDamageBonusVsRace");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageBonusVsSAlign(Ice::Int nAlign, Ice::Int nDamageType, Ice::Int nDamage, const Ice::Current& ice) {
  lock("itemPropertyDamageBonusVsSAlign"); callCounter += 1;
  StackPushInteger(nDamage);
  StackPushInteger(nDamageType);
  StackPushInteger(nAlign);

  VM_ExecuteCommand(634, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDamageBonusVsSAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageImmunity(Ice::Int nDamageType, Ice::Int nImmuneBonus, const Ice::Current& ice) {
  lock("itemPropertyDamageImmunity"); callCounter += 1;
  StackPushInteger(nImmuneBonus);
  StackPushInteger(nDamageType);

  VM_ExecuteCommand(635, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDamageImmunity");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamagePenalty(Ice::Int nPenalty, const Ice::Current& ice) {
  lock("itemPropertyDamagePenalty"); callCounter += 1;
  StackPushInteger(nPenalty);

  VM_ExecuteCommand(636, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDamagePenalty");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageReduction(Ice::Int nEnhancement, Ice::Int nHPSoak, const Ice::Current& ice) {
  lock("itemPropertyDamageReduction"); callCounter += 1;
  StackPushInteger(nHPSoak);
  StackPushInteger(nEnhancement);

  VM_ExecuteCommand(637, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDamageReduction");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageResistance(Ice::Int nDamageType, Ice::Int nHPResist, const Ice::Current& ice) {
  lock("itemPropertyDamageResistance"); callCounter += 1;
  StackPushInteger(nHPResist);
  StackPushInteger(nDamageType);

  VM_ExecuteCommand(638, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDamageResistance");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDamageVulnerability(Ice::Int nDamageType, Ice::Int nVulnerability, const Ice::Current& ice) {
  lock("itemPropertyDamageVulnerability"); callCounter += 1;
  StackPushInteger(nVulnerability);
  StackPushInteger(nDamageType);

  VM_ExecuteCommand(639, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDamageVulnerability");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDarkvision(const Ice::Current& ice) {
  lock("itemPropertyDarkvision"); callCounter += 1;

  VM_ExecuteCommand(640, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDarkvision");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDecreaseAC(Ice::Int nModifierType, Ice::Int nPenalty, const Ice::Current& ice) {
  lock("itemPropertyDecreaseAC"); callCounter += 1;
  StackPushInteger(nPenalty);
  StackPushInteger(nModifierType);

  VM_ExecuteCommand(642, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDecreaseAC");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDecreaseAbility(NWN::Ability tAbility, Ice::Int nModifier, const Ice::Current& ice) {
  lock("itemPropertyDecreaseAbility"); callCounter += 1;
  StackPushInteger(nModifier);
  if (tAbility == NWN::Charisma) StackPushInteger(5);
   else if (tAbility == NWN::Strength) StackPushInteger(0);
   else if (tAbility == NWN::Dexterity) StackPushInteger(1);
   else if (tAbility == NWN::Constitution) StackPushInteger(2);
   else if (tAbility == NWN::Intelligence) StackPushInteger(3);
   else if (tAbility == NWN::Wisdom) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(641, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDecreaseAbility");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyDecreaseSkill(Ice::Int nSkill, Ice::Int nPenalty, const Ice::Current& ice) {
  lock("itemPropertyDecreaseSkill"); callCounter += 1;
  StackPushInteger(nPenalty);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(643, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyDecreaseSkill");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyEnhancementBonus(Ice::Int nEnhancementBonus, const Ice::Current& ice) {
  lock("itemPropertyEnhancementBonus"); callCounter += 1;
  StackPushInteger(nEnhancementBonus);

  VM_ExecuteCommand(622, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyEnhancementBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyEnhancementBonusVsAlign(Ice::Int nAlignGroup, Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyEnhancementBonusVsAlign"); callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(nAlignGroup);

  VM_ExecuteCommand(623, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyEnhancementBonusVsAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyEnhancementBonusVsRace(NWN::IPRacialType tIPRacialType, Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyEnhancementBonusVsRace"); callCounter += 1;
  StackPushInteger(nBonus);
  if (tIPRacialType == NWN::ElementalIPRace) StackPushInteger(16);
   else if (tIPRacialType == NWN::HalforcIPRace) StackPushInteger(5);
   else if (tIPRacialType == NWN::DragonIPRace) StackPushInteger(11);
   else if (tIPRacialType == NWN::DwarfIPRace) StackPushInteger(0);
   else if (tIPRacialType == NWN::FeyIPRace) StackPushInteger(17);
   else if (tIPRacialType == NWN::HumanIPRace) StackPushInteger(6);
   else if (tIPRacialType == NWN::ShapechangerIPRace) StackPushInteger(23);
   else if (tIPRacialType == NWN::HumanoidGoblinoidIPRace) StackPushInteger(12);
   else if (tIPRacialType == NWN::ElfIPRace) StackPushInteger(1);
   else if (tIPRacialType == NWN::GiantIPRace) StackPushInteger(18);
   else if (tIPRacialType == NWN::AberrationIPRace) StackPushInteger(7);
   else if (tIPRacialType == NWN::UndeadIPRace) StackPushInteger(24);
   else if (tIPRacialType == NWN::HumanoidMonstrousIPRace) StackPushInteger(13);
   else if (tIPRacialType == NWN::GnomeIPRace) StackPushInteger(2);
   else if (tIPRacialType == NWN::MagicalBeastIPRace) StackPushInteger(19);
   else if (tIPRacialType == NWN::AnimalIPRace) StackPushInteger(8);
   else if (tIPRacialType == NWN::VerminIPRace) StackPushInteger(25);
   else if (tIPRacialType == NWN::HumanoidOrcIPRace) StackPushInteger(14);
   else if (tIPRacialType == NWN::HalflingIPRace) StackPushInteger(3);
   else if (tIPRacialType == NWN::OutsiderIPRace) StackPushInteger(20);
   else if (tIPRacialType == NWN::BeastIPRace) StackPushInteger(9);
   else if (tIPRacialType == NWN::HumanoidReptilianIPRace) StackPushInteger(15);
   else if (tIPRacialType == NWN::HalfelfIPRace) StackPushInteger(4);
   else if (tIPRacialType == NWN::ConstructIPRace) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(624, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyEnhancementBonusVsRace");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyEnhancementBonusVsSAlign(Ice::Int nAlign, Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertyEnhancementBonusVsSAlign"); callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(nAlign);

  VM_ExecuteCommand(625, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyEnhancementBonusVsSAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyEnhancementPenalty(Ice::Int nPenalty, const Ice::Current& ice) {
  lock("itemPropertyEnhancementPenalty"); callCounter += 1;
  StackPushInteger(nPenalty);

  VM_ExecuteCommand(626, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyEnhancementPenalty");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyExtraMeleeDamageType(Ice::Int nDamageType, const Ice::Current& ice) {
  lock("itemPropertyExtraMeleeDamageType"); callCounter += 1;
  StackPushInteger(nDamageType);

  VM_ExecuteCommand(645, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyExtraMeleeDamageType");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyExtraRangeDamageType(Ice::Int nDamageType, const Ice::Current& ice) {
  lock("itemPropertyExtraRangeDamageType"); callCounter += 1;
  StackPushInteger(nDamageType);

  VM_ExecuteCommand(646, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyExtraRangeDamageType");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyFreeAction(const Ice::Current& ice) {
  lock("itemPropertyFreeAction"); callCounter += 1;

  VM_ExecuteCommand(683, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyFreeAction");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyHaste(const Ice::Current& ice) {
  lock("itemPropertyHaste"); callCounter += 1;

  VM_ExecuteCommand(647, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyHaste");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyHealersKit(Ice::Int nModifier, const Ice::Current& ice) {
  lock("itemPropertyHealersKit"); callCounter += 1;
  StackPushInteger(nModifier);

  VM_ExecuteCommand(687, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyHealersKit");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyHolyAvenger(const Ice::Current& ice) {
  lock("itemPropertyHolyAvenger"); callCounter += 1;

  VM_ExecuteCommand(648, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyHolyAvenger");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyImmunityMisc(Ice::Int nImmunityType, const Ice::Current& ice) {
  lock("itemPropertyImmunityMisc"); callCounter += 1;
  StackPushInteger(nImmunityType);

  VM_ExecuteCommand(649, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyImmunityMisc");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyImmunityToSpellLevel(Ice::Int nLevel, const Ice::Current& ice) {
  lock("itemPropertyImmunityToSpellLevel"); callCounter += 1;
  StackPushInteger(nLevel);

  VM_ExecuteCommand(685, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyImmunityToSpellLevel");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyImprovedEvasion(const Ice::Current& ice) {
  lock("itemPropertyImprovedEvasion"); callCounter += 1;

  VM_ExecuteCommand(650, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyImprovedEvasion");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyKeen(const Ice::Current& ice) {
  lock("itemPropertyKeen"); callCounter += 1;

  VM_ExecuteCommand(654, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyKeen");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyLight(Ice::Int nBrightness, Ice::Int nColor, const Ice::Current& ice) {
  lock("itemPropertyLight"); callCounter += 1;
  StackPushInteger(nColor);
  StackPushInteger(nBrightness);

  VM_ExecuteCommand(655, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyLight");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyLimitUseByAlign(Ice::Int nAlignGroup, const Ice::Current& ice) {
  lock("itemPropertyLimitUseByAlign"); callCounter += 1;
  StackPushInteger(nAlignGroup);

  VM_ExecuteCommand(672, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyLimitUseByAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyLimitUseByClass(Ice::Int nClass, const Ice::Current& ice) {
  lock("itemPropertyLimitUseByClass"); callCounter += 1;
  StackPushInteger(nClass);

  VM_ExecuteCommand(673, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyLimitUseByClass");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyLimitUseByRace(NWN::IPRacialType tIPRacialType, const Ice::Current& ice) {
  lock("itemPropertyLimitUseByRace"); callCounter += 1;
  if (tIPRacialType == NWN::ElementalIPRace) StackPushInteger(16);
   else if (tIPRacialType == NWN::HalforcIPRace) StackPushInteger(5);
   else if (tIPRacialType == NWN::DragonIPRace) StackPushInteger(11);
   else if (tIPRacialType == NWN::DwarfIPRace) StackPushInteger(0);
   else if (tIPRacialType == NWN::FeyIPRace) StackPushInteger(17);
   else if (tIPRacialType == NWN::HumanIPRace) StackPushInteger(6);
   else if (tIPRacialType == NWN::ShapechangerIPRace) StackPushInteger(23);
   else if (tIPRacialType == NWN::HumanoidGoblinoidIPRace) StackPushInteger(12);
   else if (tIPRacialType == NWN::ElfIPRace) StackPushInteger(1);
   else if (tIPRacialType == NWN::GiantIPRace) StackPushInteger(18);
   else if (tIPRacialType == NWN::AberrationIPRace) StackPushInteger(7);
   else if (tIPRacialType == NWN::UndeadIPRace) StackPushInteger(24);
   else if (tIPRacialType == NWN::HumanoidMonstrousIPRace) StackPushInteger(13);
   else if (tIPRacialType == NWN::GnomeIPRace) StackPushInteger(2);
   else if (tIPRacialType == NWN::MagicalBeastIPRace) StackPushInteger(19);
   else if (tIPRacialType == NWN::AnimalIPRace) StackPushInteger(8);
   else if (tIPRacialType == NWN::VerminIPRace) StackPushInteger(25);
   else if (tIPRacialType == NWN::HumanoidOrcIPRace) StackPushInteger(14);
   else if (tIPRacialType == NWN::HalflingIPRace) StackPushInteger(3);
   else if (tIPRacialType == NWN::OutsiderIPRace) StackPushInteger(20);
   else if (tIPRacialType == NWN::BeastIPRace) StackPushInteger(9);
   else if (tIPRacialType == NWN::HumanoidReptilianIPRace) StackPushInteger(15);
   else if (tIPRacialType == NWN::HalfelfIPRace) StackPushInteger(4);
   else if (tIPRacialType == NWN::ConstructIPRace) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(674, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyLimitUseByRace");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyLimitUseBySAlign(Ice::Int nAlignment, const Ice::Current& ice) {
  lock("itemPropertyLimitUseBySAlign"); callCounter += 1;
  StackPushInteger(nAlignment);

  VM_ExecuteCommand(675, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyLimitUseBySAlign");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyMassiveCritical(Ice::Int nDamage, const Ice::Current& ice) {
  lock("itemPropertyMassiveCritical"); callCounter += 1;
  StackPushInteger(nDamage);

  VM_ExecuteCommand(682, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyMassiveCritical");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyMaterial(Ice::Int nMaterialType, const Ice::Current& ice) {
  lock("itemPropertyMaterial"); callCounter += 1;
  StackPushInteger(nMaterialType);

  VM_ExecuteCommand(845, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyMaterial");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyMaxRangeStrengthMod(Ice::Int nModifier, const Ice::Current& ice) {
  lock("itemPropertyMaxRangeStrengthMod"); callCounter += 1;
  StackPushInteger(nModifier);

  VM_ExecuteCommand(656, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyMaxRangeStrengthMod");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyMonsterDamage(Ice::Int nDamage, const Ice::Current& ice) {
  lock("itemPropertyMonsterDamage"); callCounter += 1;
  StackPushInteger(nDamage);

  VM_ExecuteCommand(684, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyMonsterDamage");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyNoDamage(const Ice::Current& ice) {
  lock("itemPropertyNoDamage"); callCounter += 1;

  VM_ExecuteCommand(657, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyNoDamage");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyOnHitCastSpell(Ice::Int nSpell, Ice::Int nLevel, const Ice::Current& ice) {
  lock("itemPropertyOnHitCastSpell"); callCounter += 1;
  StackPushInteger(nLevel);
  StackPushInteger(nSpell);

  VM_ExecuteCommand(733, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyOnHitCastSpell");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyOnHitProps(Ice::Int nProperty, Ice::Int nSaveDC, Ice::Int nSpecial, const Ice::Current& ice) {
  lock("itemPropertyOnHitProps"); callCounter += 1;
  StackPushInteger(nSpecial);
  StackPushInteger(nSaveDC);
  StackPushInteger(nProperty);

  VM_ExecuteCommand(658, 3);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyOnHitProps");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyOnMonsterHitProperties(Ice::Int nProperty, Ice::Int nSpecial, const Ice::Current& ice) {
  lock("itemPropertyOnMonsterHitProperties"); callCounter += 1;
  StackPushInteger(nSpecial);
  StackPushInteger(nProperty);

  VM_ExecuteCommand(680, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyOnMonsterHitProperties");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyQuality(Ice::Int nQuality, const Ice::Current& ice) {
  lock("itemPropertyQuality"); callCounter += 1;
  StackPushInteger(nQuality);

  VM_ExecuteCommand(846, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyQuality");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyReducedSavingThrow(Ice::Int nBonusType, Ice::Int nPenalty, const Ice::Current& ice) {
  lock("itemPropertyReducedSavingThrow"); callCounter += 1;
  StackPushInteger(nPenalty);
  StackPushInteger(nBonusType);

  VM_ExecuteCommand(660, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyReducedSavingThrow");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyReducedSavingThrowVsX(Ice::Int nBaseSaveType, Ice::Int nPenalty, const Ice::Current& ice) {
  lock("itemPropertyReducedSavingThrowVsX"); callCounter += 1;
  StackPushInteger(nPenalty);
  StackPushInteger(nBaseSaveType);

  VM_ExecuteCommand(659, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyReducedSavingThrowVsX");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyRegeneration(Ice::Int nRegenAmount, const Ice::Current& ice) {
  lock("itemPropertyRegeneration"); callCounter += 1;
  StackPushInteger(nRegenAmount);

  VM_ExecuteCommand(661, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyRegeneration");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertySkillBonus(Ice::Int nSkill, Ice::Int nBonus, const Ice::Current& ice) {
  lock("itemPropertySkillBonus"); callCounter += 1;
  StackPushInteger(nBonus);
  StackPushInteger(nSkill);

  VM_ExecuteCommand(662, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertySkillBonus");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertySpecialWalk(Ice::Int nWalkType, const Ice::Current& ice) {
  lock("itemPropertySpecialWalk"); callCounter += 1;
  StackPushInteger(nWalkType);

  VM_ExecuteCommand(686, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertySpecialWalk");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertySpellImmunitySchool(Ice::Int nSchool, const Ice::Current& ice) {
  lock("itemPropertySpellImmunitySchool"); callCounter += 1;
  StackPushInteger(nSchool);

  VM_ExecuteCommand(664, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertySpellImmunitySchool");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertySpellImmunitySpecific(Ice::Int nSpell, const Ice::Current& ice) {
  lock("itemPropertySpellImmunitySpecific"); callCounter += 1;
  StackPushInteger(nSpell);

  VM_ExecuteCommand(663, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertySpellImmunitySpecific");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyThievesTools(Ice::Int nModifier, const Ice::Current& ice) {
  lock("itemPropertyThievesTools"); callCounter += 1;
  StackPushInteger(nModifier);

  VM_ExecuteCommand(665, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyThievesTools");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyTrap(Ice::Int nTrapLevel, Ice::Int nTrapType, const Ice::Current& ice) {
  lock("itemPropertyTrap"); callCounter += 1;
  StackPushInteger(nTrapType);
  StackPushInteger(nTrapLevel);

  VM_ExecuteCommand(678, 2);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyTrap");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyTrueSeeing(const Ice::Current& ice) {
  lock("itemPropertyTrueSeeing"); callCounter += 1;

  VM_ExecuteCommand(679, 0);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyTrueSeeing");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyTurnResistance(Ice::Int nModifier, const Ice::Current& ice) {
  lock("itemPropertyTurnResistance"); callCounter += 1;
  StackPushInteger(nModifier);

  VM_ExecuteCommand(681, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyTurnResistance");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyUnlimitedAmmo(Ice::Int nAmmoDamage, const Ice::Current& ice) {
  lock("itemPropertyUnlimitedAmmo"); callCounter += 1;
  StackPushInteger(nAmmoDamage);

  VM_ExecuteCommand(671, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyUnlimitedAmmo");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyVampiricRegeneration(Ice::Int nRegenAmount, const Ice::Current& ice) {
  lock("itemPropertyVampiricRegeneration"); callCounter += 1;
  StackPushInteger(nRegenAmount);

  VM_ExecuteCommand(677, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyVampiricRegeneration");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyVisualEffect(Ice::Int nEffect, const Ice::Current& ice) {
  lock("itemPropertyVisualEffect"); callCounter += 1;
  StackPushInteger(nEffect);

  VM_ExecuteCommand(739, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyVisualEffect");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyWeightIncrease(Ice::Int nWeight, const Ice::Current& ice) {
  lock("itemPropertyWeightIncrease"); callCounter += 1;
  StackPushInteger(nWeight);

  VM_ExecuteCommand(688, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyWeightIncrease");
  return e;
};

NWN::NWItemProperty NWScriptI::itemPropertyWeightReduction(Ice::Int nReduction, const Ice::Current& ice) {
  lock("itemPropertyWeightReduction"); callCounter += 1;
  StackPushInteger(nReduction);

  VM_ExecuteCommand(627, 1);

  CGameEffect *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_EFFECT, (void **) &pRetVal);
  long id = -1;
  map<long,CGameEffect*>::iterator iter;
  NWN::NWItemProperty e;
  for (iter = iprpMap.begin(); iter != iprpMap.end(); ++iter)
    if (iter->second == pRetVal) { id = iter->first; break; }
  if (id == -1)
    { iprpMap[lastIprpId] = pRetVal; id = lastIprpId; lastIprpId += 1; }
  e.id = id;
  unlock("itemPropertyWeightReduction");
  return e;
};

void NWScriptI::jumpToLocation(const NWN::NWLocation& lDestination, const Ice::Current& ice) {
  lock("jumpToLocation"); callCounter += 1;
  CScriptLocation *lDestination_ptr;
  lDestination_ptr->X = lDestination.x;
  lDestination_ptr->Y = lDestination.y;
  lDestination_ptr->Z = lDestination.z;
  lDestination_ptr->OrientationX = lDestination.orientationX;
  lDestination_ptr->OrientationY = lDestination.orientationY;
  lDestination_ptr->OrientationZ = lDestination.orientationZ;
  lDestination_ptr->AreaID = lDestination.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lDestination_ptr);

  VM_ExecuteCommand(313, 1);

unlock("jumpToLocation");
  
};

void NWScriptI::jumpToObject(const NWN::NWObject& oToJumpTo, bool bWalkStraightLineToPoint, const Ice::Current& ice) {
  lock("jumpToObject"); callCounter += 1;
  StackPushInteger(bWalkStraightLineToPoint == true ? 1 : 0);
  StackPushObject(oToJumpTo.id);

  VM_ExecuteCommand(385, 2);

unlock("jumpToObject");
  
};

Ice::Int NWScriptI::levelUpHenchman(const NWN::NWObject& oCreature, Ice::Int nClass, bool bReadyAllSpells, Ice::Int nPackage, const Ice::Current& ice) {
  lock("levelUpHenchman"); callCounter += 1;
  StackPushInteger(nPackage);
  StackPushInteger(bReadyAllSpells == true ? 1 : 0);
  StackPushInteger(nClass);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(704, 4);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("levelUpHenchman");
  return nRetVal;
};

Ice::Int NWScriptI::lineOfSightObject(const NWN::NWObject& oSource, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("lineOfSightObject"); callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oSource.id);

  VM_ExecuteCommand(752, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("lineOfSightObject");
  return nRetVal;
};

Ice::Int NWScriptI::lineOfSightVector(const NWN::NWVector& vSource, const NWN::NWVector& vTarget, const Ice::Current& ice) {
  lock("lineOfSightVector"); callCounter += 1;
  Vector vvTarget;
  vvTarget.X = vTarget.x; vvTarget.Y = vTarget.y; vvTarget.Z = vTarget.z;
  StackPushVector(vvTarget);
  Vector vvSource;
  vvSource.X = vSource.x; vvSource.Y = vSource.y; vvSource.Z = vSource.z;
  StackPushVector(vvSource);

  VM_ExecuteCommand(753, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("lineOfSightVector");
  return nRetVal;
};

NWN::NWLocation NWScriptI::location(const NWN::NWObject& oArea, const NWN::NWVector& vPosition, Ice::Double fOrientation, const Ice::Current& ice) {
  lock("location"); callCounter += 1;
  StackPushFloat(fOrientation);
  Vector vvPosition;
  vvPosition.X = vPosition.x; vvPosition.Y = vPosition.y; vvPosition.Z = vPosition.z;
  StackPushVector(vvPosition);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(215, 3);

  CScriptLocation *pRetVal;
  StackPopEngineStructure(ENGINE_STRUCTURE_LOCATION, (void **) &pRetVal);
  NWN::NWLocation nl;
  nl.x = pRetVal->X;
  nl.y = pRetVal->X;
  nl.z = pRetVal->X;
  nl.orientationX = pRetVal->OrientationX;
  nl.orientationY = pRetVal->OrientationY;
  nl.orientationZ = pRetVal->OrientationZ;
  nl.area.id = pRetVal->AreaID;
  unlock("location");
  return nl;
};

void NWScriptI::lockCameraDirection(const NWN::NWObject& oPlayer, bool bLocked, const Ice::Current& ice) {
  lock("lockCameraDirection"); callCounter += 1;
  StackPushInteger(bLocked == true ? 1 : 0);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(825, 2);

unlock("lockCameraDirection");
  
};

void NWScriptI::lockCameraDistance(const NWN::NWObject& oPlayer, bool bLocked, const Ice::Current& ice) {
  lock("lockCameraDistance"); callCounter += 1;
  StackPushInteger(bLocked == true ? 1 : 0);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(824, 2);

unlock("lockCameraDistance");
  
};

void NWScriptI::lockCameraPitch(const NWN::NWObject& oPlayer, bool bLocked, const Ice::Current& ice) {
  lock("lockCameraPitch"); callCounter += 1;
  StackPushInteger(bLocked == true ? 1 : 0);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(823, 2);

unlock("lockCameraPitch");
  
};

Ice::Double NWScriptI::log(Ice::Double fValue, const Ice::Current& ice) {
  lock("log"); callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(74, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("log");
  return fRetVal;
};

NWN::NWEffect NWScriptI::magicalEffect(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("magicalEffect"); callCounter += 1;
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
  unlock("magicalEffect");
  return e;
};

void NWScriptI::musicBackgroundChangeDay(const NWN::NWObject& oArea, Ice::Int nTrack, const Ice::Current& ice) {
  lock("musicBackgroundChangeDay"); callCounter += 1;
  StackPushInteger(nTrack);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(428, 2);

unlock("musicBackgroundChangeDay");
  
};

void NWScriptI::musicBackgroundChangeNight(const NWN::NWObject& oArea, Ice::Int nTrack, const Ice::Current& ice) {
  lock("musicBackgroundChangeNight"); callCounter += 1;
  StackPushInteger(nTrack);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(429, 2);

unlock("musicBackgroundChangeNight");
  
};

Ice::Int NWScriptI::musicBackgroundGetBattleTrack(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("musicBackgroundGetBattleTrack"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(569, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("musicBackgroundGetBattleTrack");
  return nRetVal;
};

Ice::Int NWScriptI::musicBackgroundGetDayTrack(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("musicBackgroundGetDayTrack"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(558, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("musicBackgroundGetDayTrack");
  return nRetVal;
};

Ice::Int NWScriptI::musicBackgroundGetNightTrack(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("musicBackgroundGetNightTrack"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(559, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("musicBackgroundGetNightTrack");
  return nRetVal;
};

void NWScriptI::musicBackgroundPlay(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("musicBackgroundPlay"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(425, 1);

unlock("musicBackgroundPlay");
  
};

void NWScriptI::musicBackgroundSetDelay(const NWN::NWObject& oArea, Ice::Int nDelay, const Ice::Current& ice) {
  lock("musicBackgroundSetDelay"); callCounter += 1;
  StackPushInteger(nDelay);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(427, 2);

unlock("musicBackgroundSetDelay");
  
};

void NWScriptI::musicBackgroundStop(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("musicBackgroundStop"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(426, 1);

unlock("musicBackgroundStop");
  
};

void NWScriptI::musicBattleChange(const NWN::NWObject& oArea, Ice::Int nTrack, const Ice::Current& ice) {
  lock("musicBattleChange"); callCounter += 1;
  StackPushInteger(nTrack);
  StackPushObject(oArea.id);

  VM_ExecuteCommand(432, 2);

unlock("musicBattleChange");
  
};

void NWScriptI::musicBattlePlay(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("musicBattlePlay"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(430, 1);

unlock("musicBattlePlay");
  
};

void NWScriptI::musicBattleStop(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("musicBattleStop"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(431, 1);

unlock("musicBattleStop");
  
};

void NWScriptI::nightToDay(const NWN::NWObject& oPlayer, Ice::Double fTransitionTime, const Ice::Current& ice) {
  lock("nightToDay"); callCounter += 1;
  StackPushFloat(fTransitionTime);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(751, 2);

unlock("nightToDay");
  
};

std::string NWScriptI::objectToString(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("objectToString"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(272, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("objectToString");
  return std::string(sRetVal);
};

void NWScriptI::openInventory(const NWN::NWObject& oCreature, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("openInventory"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(701, 2);

unlock("openInventory");
  
};

void NWScriptI::openStore(const NWN::NWObject& oStore, const NWN::NWObject& oPC, Ice::Int nBonusMarkUp, Ice::Int nBonusMarkDown, const Ice::Current& ice) {
  lock("openStore"); callCounter += 1;
  StackPushInteger(nBonusMarkDown);
  StackPushInteger(nBonusMarkUp);
  StackPushObject(oPC.id);
  StackPushObject(oStore.id);

  VM_ExecuteCommand(378, 4);

unlock("openStore");
  
};

void NWScriptI::playAnimation(Ice::Int nAnimation, Ice::Double fSpeed, Ice::Double fSeconds, const Ice::Current& ice) {
  lock("playAnimation"); callCounter += 1;
  StackPushFloat(fSeconds);
  StackPushFloat(fSpeed);
  StackPushInteger(nAnimation);

  VM_ExecuteCommand(300, 3);

unlock("playAnimation");
  
};

void NWScriptI::playSound(const std::string& sSoundName, const Ice::Current& ice) {
  lock("playSound"); callCounter += 1;
  StackPushString(sSoundName.c_str());

  VM_ExecuteCommand(46, 1);

unlock("playSound");
  
};

void NWScriptI::playSoundByStrRef(Ice::Int nStrRef, Ice::Int nRunAsAction, const Ice::Current& ice) {
  lock("playSoundByStrRef"); callCounter += 1;
  StackPushInteger(nRunAsAction);
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(720, 2);

unlock("playSoundByStrRef");
  
};

void NWScriptI::playVoiceChat(Ice::Int nVoiceChatID, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("playVoiceChat"); callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushInteger(nVoiceChatID);

  VM_ExecuteCommand(421, 2);

unlock("playVoiceChat");
  
};

void NWScriptI::popUpDeathGUIPanel(const NWN::NWObject& oPC, bool bRespawnButtonEnabled, bool bWaitForHelpButtonEnabled, Ice::Int nHelpStringReference, const std::string& sHelpString, const Ice::Current& ice) {
  lock("popUpDeathGUIPanel"); callCounter += 1;
  StackPushString(sHelpString.c_str());
  StackPushInteger(nHelpStringReference);
  StackPushInteger(bWaitForHelpButtonEnabled == true ? 1 : 0);
  StackPushInteger(bRespawnButtonEnabled == true ? 1 : 0);
  StackPushObject(oPC.id);

  VM_ExecuteCommand(554, 5);

unlock("popUpDeathGUIPanel");
  
};

void NWScriptI::popUpGUIPanel(const NWN::NWObject& oPC, Ice::Int nGUIPanel, const Ice::Current& ice) {
  lock("popUpGUIPanel"); callCounter += 1;
  StackPushInteger(nGUIPanel);
  StackPushObject(oPC.id);

  VM_ExecuteCommand(388, 2);

unlock("popUpGUIPanel");
  
};

Ice::Double NWScriptI::pow(Ice::Double fValue, Ice::Double fExponent, const Ice::Current& ice) {
  lock("pow"); callCounter += 1;
  StackPushFloat(fExponent);
  StackPushFloat(fValue);

  VM_ExecuteCommand(75, 2);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("pow");
  return fRetVal;
};

void NWScriptI::printFloat(Ice::Double fFloat, Ice::Int nWidth, Ice::Int nDecimals, const Ice::Current& ice) {
  lock("printFloat"); callCounter += 1;
  StackPushInteger(nDecimals);
  StackPushInteger(nWidth);
  StackPushFloat(fFloat);

  VM_ExecuteCommand(2, 3);

unlock("printFloat");
  
};

void NWScriptI::printInteger(Ice::Int nInteger, const Ice::Current& ice) {
  lock("printInteger"); callCounter += 1;
  StackPushInteger(nInteger);

  VM_ExecuteCommand(4, 1);

unlock("printInteger");
  
};

void NWScriptI::printObject(const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("printObject"); callCounter += 1;
  StackPushObject(oObject.id);

  VM_ExecuteCommand(5, 1);

unlock("printObject");
  
};

void NWScriptI::printString(const std::string& sString, const Ice::Current& ice) {
  lock("printString"); callCounter += 1;
  StackPushString(sString.c_str());

  VM_ExecuteCommand(1, 1);

unlock("printString");
  
};

void NWScriptI::printVector(const NWN::NWVector& vVector, bool bPrepend, const Ice::Current& ice) {
  lock("printVector"); callCounter += 1;
  StackPushInteger(bPrepend == true ? 1 : 0);
  Vector vvVector;
  vvVector.X = vVector.x; vvVector.Y = vVector.y; vvVector.Z = vVector.z;
  StackPushVector(vvVector);

  VM_ExecuteCommand(141, 2);

unlock("printVector");
  
};

Ice::Int NWScriptI::random(Ice::Int nMaxInteger, const Ice::Current& ice) {
  lock("random"); callCounter += 1;
  StackPushInteger(nMaxInteger);

  VM_ExecuteCommand(0, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("random");
  return nRetVal;
};

std::string NWScriptI::randomName(Ice::Int nNameType, const Ice::Current& ice) {
  lock("randomName"); callCounter += 1;
  StackPushInteger(nNameType);

  VM_ExecuteCommand(249, 1);

  char* sRetVal;
  StackPopString(&sRetVal);
  unlock("randomName");
  return std::string(sRetVal);
};

void NWScriptI::recomputeStaticLighting(const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("recomputeStaticLighting"); callCounter += 1;
  StackPushObject(oArea.id);

  VM_ExecuteCommand(516, 1);

unlock("recomputeStaticLighting");
  
};

NWN::SavingThrowResult NWScriptI::reflexSave(const NWN::NWObject& oCreature, Ice::Int nDC, NWN::SaveType tSaveType, const NWN::NWObject& oSaveVersus, const Ice::Current& ice) {
  lock("reflexSave"); callCounter += 1;
  StackPushObject(oSaveVersus.id);
  if (tSaveType == NWN::GoodSaveType) StackPushInteger(16);
   else if (tSaveType == NWN::SonicSaveType) StackPushInteger(5);
   else if (tSaveType == NWN::DeathSaveType) StackPushInteger(11);
   else if (tSaveType == NWN::AllOrNoneSaveType) StackPushInteger(0);
   else if (tSaveType == NWN::EvilSaveType) StackPushInteger(17);
   else if (tSaveType == NWN::AcidSaveType) StackPushInteger(6);
   else if (tSaveType == NWN::ColdSaveType) StackPushInteger(12);
   else if (tSaveType == NWN::MindSpellsSaveType) StackPushInteger(1);
   else if (tSaveType == NWN::LawSaveType) StackPushInteger(18);
   else if (tSaveType == NWN::FireSaveType) StackPushInteger(7);
   else if (tSaveType == NWN::DivineSaveType) StackPushInteger(13);
   else if (tSaveType == NWN::PoisonSaveType) StackPushInteger(2);
   else if (tSaveType == NWN::ChaosSaveType) StackPushInteger(19);
   else if (tSaveType == NWN::ElectricitySaveType) StackPushInteger(8);
   else if (tSaveType == NWN::TrapSaveType) StackPushInteger(14);
   else if (tSaveType == NWN::DiseaseSaveType) StackPushInteger(3);
   else if (tSaveType == NWN::PositiveSaveType) StackPushInteger(9);
   else if (tSaveType == NWN::SpellSaveType) StackPushInteger(15);
   else if (tSaveType == NWN::FearSaveType) StackPushInteger(4);
   else if (tSaveType == NWN::NegativeSaveType) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushInteger(nDC);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(109, 4);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("reflexSave");
  if (nRetVal == 0) return NWN::FailedRoll;
  if (nRetVal == 1) return NWN::SucceededRoll;
  if (nRetVal == 3) return NWN::ImmuneToSaveType;
  throw "Error: Unmapped enum return type";
};

void NWScriptI::removeEffect(const NWN::NWObject& oCreature, const NWN::NWEffect& eEffect, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("removeEffect"); callCounter += 1;
  CGameEffect *eEffect_ptr = effectMap.find(eEffect.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, eEffect_ptr);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(87, 2);

unlock("removeEffect");
  
};

void NWScriptI::removeFromParty(const NWN::NWObject& oPC, const Ice::Current& ice) {
  lock("removeFromParty"); callCounter += 1;
  StackPushObject(oPC.id);

  VM_ExecuteCommand(573, 1);

unlock("removeFromParty");
  
};

void NWScriptI::removeHenchman(const NWN::NWObject& oMaster, const NWN::NWObject& oHenchman, const Ice::Current& ice) {
  lock("removeHenchman"); callCounter += 1;
  StackPushObject(oHenchman.id);
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(366, 2);

unlock("removeHenchman");
  
};

void NWScriptI::removeItemProperty(const NWN::NWObject& oItem, const NWN::NWItemProperty& ipProperty, const Ice::Current& ice) {
if (iprpMap.find(ipProperty.id) == iprpMap.end()) throw NWN::InvalidItemPropertyException();
  
  lock("removeItemProperty"); callCounter += 1;
  CGameEffect *ipProperty_ptr = iprpMap.find(ipProperty.id)->second;
  StackPushEngineStructure(ENGINE_STRUCTURE_EFFECT, ipProperty_ptr);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(610, 2);

unlock("removeItemProperty");
  
};

void NWScriptI::removeJournalQuestEntry(const std::string& szPlotID, const NWN::NWObject& oCreature, bool bAllPartyMembers, bool bAllPlayers, const Ice::Current& ice) {
  lock("removeJournalQuestEntry"); callCounter += 1;
  StackPushInteger(bAllPlayers == true ? 1 : 0);
  StackPushInteger(bAllPartyMembers == true ? 1 : 0);
  StackPushObject(oCreature.id);
  StackPushString(szPlotID.c_str());

  VM_ExecuteCommand(368, 4);

unlock("removeJournalQuestEntry");
  
};

void NWScriptI::removeSummonedAssociate(const NWN::NWObject& oMaster, const NWN::NWObject& oAssociate, const Ice::Current& ice) {
  lock("removeSummonedAssociate"); callCounter += 1;
  StackPushObject(oAssociate.id);
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(503, 2);

unlock("removeSummonedAssociate");
  
};

Ice::Int NWScriptI::resistSpell(const NWN::NWObject& oCaster, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("resistSpell"); callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oCaster.id);

  VM_ExecuteCommand(169, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("resistSpell");
  return nRetVal;
};

void NWScriptI::restoreBaseAttackBonus(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("restoreBaseAttackBonus"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(756, 1);

unlock("restoreBaseAttackBonus");
  
};

void NWScriptI::restoreCameraFacing(const Ice::Current& ice) {
  lock("restoreCameraFacing"); callCounter += 1;

  VM_ExecuteCommand(703, 0);

unlock("restoreCameraFacing");
  
};

NWN::NWObject NWScriptI::retrieveCampaignObject(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWLocation& locLocation, const NWN::NWObject& oOwner, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("retrieveCampaignObject"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushObject(oOwner.id);
  CScriptLocation *locLocation_ptr;
  locLocation_ptr->X = locLocation.x;
  locLocation_ptr->Y = locLocation.y;
  locLocation_ptr->Z = locLocation.z;
  locLocation_ptr->OrientationX = locLocation.orientationX;
  locLocation_ptr->OrientationY = locLocation.orientationY;
  locLocation_ptr->OrientationZ = locLocation.orientationZ;
  locLocation_ptr->AreaID = locLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, locLocation_ptr);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(603, 5);

  dword lRetVal;
  StackPopObject(&lRetVal);
  unlock("retrieveCampaignObject");
  NWN::NWObject no;
  no.id = lRetVal;
  return no;
};

Ice::Double NWScriptI::roundsToSeconds(Ice::Int nRounds, const Ice::Current& ice) {
  lock("roundsToSeconds"); callCounter += 1;
  StackPushInteger(nRounds);

  VM_ExecuteCommand(121, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("roundsToSeconds");
  return fRetVal;
};

void NWScriptI::sendMessageToAllDMs(const std::string& szMessage, const Ice::Current& ice) {
  lock("sendMessageToAllDMs"); callCounter += 1;
  StackPushString(szMessage.c_str());

  VM_ExecuteCommand(563, 1);

unlock("sendMessageToAllDMs");
  
};

void NWScriptI::sendMessageToPC(const NWN::NWObject& oPlayer, const std::string& szMessage, const Ice::Current& ice) {
  lock("sendMessageToPC"); callCounter += 1;
  StackPushString(szMessage.c_str());
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(374, 2);

unlock("sendMessageToPC");
  
};

void NWScriptI::sendMessageToPCByStrRef(const NWN::NWObject& oPlayer, Ice::Int nStrRef, const Ice::Current& ice) {
  lock("sendMessageToPCByStrRef"); callCounter += 1;
  StackPushInteger(nStrRef);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(717, 2);

unlock("sendMessageToPCByStrRef");
  
};

void NWScriptI::setAILevel(const NWN::NWObject& oTarget, Ice::Int nAILevel, const Ice::Current& ice) {
  lock("setAILevel"); callCounter += 1;
  StackPushInteger(nAILevel);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(713, 2);

unlock("setAILevel");
  
};

void NWScriptI::setActionMode(const NWN::NWObject& oCreature, Ice::Int nMode, Ice::Int nStatus, const Ice::Current& ice) {
  lock("setActionMode"); callCounter += 1;
  StackPushInteger(nStatus);
  StackPushInteger(nMode);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(736, 3);

unlock("setActionMode");
  
};

void NWScriptI::setAreaTransitionBMP(Ice::Int nPredefinedAreaTransition, const std::string& sCustomAreaTransitionBMP, const Ice::Current& ice) {
  lock("setAreaTransitionBMP"); callCounter += 1;
  StackPushString(sCustomAreaTransitionBMP.c_str());
  StackPushInteger(nPredefinedAreaTransition);

  VM_ExecuteCommand(203, 2);

unlock("setAreaTransitionBMP");
  
};

void NWScriptI::setAssociateListenPatterns(const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("setAssociateListenPatterns"); callCounter += 1;
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(327, 1);

unlock("setAssociateListenPatterns");
  
};

void NWScriptI::setBaseAttackBonus(Ice::Int nBaseAttackBonus, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("setBaseAttackBonus"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nBaseAttackBonus);

  VM_ExecuteCommand(755, 2);

unlock("setBaseAttackBonus");
  
};

void NWScriptI::setCalendar(Ice::Int nYear, Ice::Int nMonth, Ice::Int nDay, const Ice::Current& ice) {
  lock("setCalendar"); callCounter += 1;
  StackPushInteger(nDay);
  StackPushInteger(nMonth);
  StackPushInteger(nYear);

  VM_ExecuteCommand(11, 3);

unlock("setCalendar");
  
};

void NWScriptI::setCameraFacing(Ice::Double fDirection, Ice::Double fDistance, Ice::Double fPitch, Ice::Int nTransitionType, const Ice::Current& ice) {
  lock("setCameraFacing"); callCounter += 1;
  StackPushInteger(nTransitionType);
  StackPushFloat(fPitch);
  StackPushFloat(fDistance);
  StackPushFloat(fDirection);

  VM_ExecuteCommand(45, 4);

unlock("setCameraFacing");
  
};

void NWScriptI::setCameraHeight(const NWN::NWObject& oPlayer, Ice::Double fHeight, const Ice::Current& ice) {
  lock("setCameraHeight"); callCounter += 1;
  StackPushFloat(fHeight);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(776, 2);

unlock("setCameraHeight");
  
};

void NWScriptI::setCameraMode(const NWN::NWObject& oPlayer, Ice::Int nCameraMode, const Ice::Current& ice) {
  lock("setCameraMode"); callCounter += 1;
  StackPushInteger(nCameraMode);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(504, 2);

unlock("setCameraMode");
  
};

void NWScriptI::setCampaignFloat(const std::string& sCampaignName, const std::string& sVarName, Ice::Double flFloat, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("setCampaignFloat"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushFloat(flFloat);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(589, 4);

unlock("setCampaignFloat");
  
};

void NWScriptI::setCampaignInt(const std::string& sCampaignName, const std::string& sVarName, Ice::Int nInt, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("setCampaignInt"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushInteger(nInt);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(590, 4);

unlock("setCampaignInt");
  
};

void NWScriptI::setCampaignLocation(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWLocation& locLocation, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("setCampaignLocation"); callCounter += 1;
  StackPushObject(oPlayer.id);
  CScriptLocation *locLocation_ptr;
  locLocation_ptr->X = locLocation.x;
  locLocation_ptr->Y = locLocation.y;
  locLocation_ptr->Z = locLocation.z;
  locLocation_ptr->OrientationX = locLocation.orientationX;
  locLocation_ptr->OrientationY = locLocation.orientationY;
  locLocation_ptr->OrientationZ = locLocation.orientationZ;
  locLocation_ptr->AreaID = locLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, locLocation_ptr);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(592, 4);

unlock("setCampaignLocation");
  
};

void NWScriptI::setCampaignString(const std::string& sCampaignName, const std::string& sVarName, const std::string& sString, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("setCampaignString"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushString(sString.c_str());
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(593, 4);

unlock("setCampaignString");
  
};

void NWScriptI::setCampaignVector(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWVector& vVector, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("setCampaignVector"); callCounter += 1;
  StackPushObject(oPlayer.id);
  Vector vvVector;
  vvVector.X = vVector.x; vvVector.Y = vVector.y; vvVector.Z = vVector.z;
  StackPushVector(vvVector);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(591, 4);

unlock("setCampaignVector");
  
};

void NWScriptI::setColor(const NWN::NWObject& oObject, Ice::Int nColorChannel, Ice::Int nColorValue, const Ice::Current& ice) {
  lock("setColor"); callCounter += 1;
  StackPushInteger(nColorValue);
  StackPushInteger(nColorChannel);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(844, 3);

unlock("setColor");
  
};

void NWScriptI::setCommandable(bool bCommandable, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("setCommandable"); callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushInteger(bCommandable == true ? 1 : 0);

  VM_ExecuteCommand(162, 2);

unlock("setCommandable");
  
};

void NWScriptI::setCreatureAppearanceType(const NWN::NWObject& oCreature, Ice::Int nAppearanceType, const Ice::Current& ice) {
  lock("setCreatureAppearanceType"); callCounter += 1;
  StackPushInteger(nAppearanceType);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(765, 2);

unlock("setCreatureAppearanceType");
  
};

void NWScriptI::setCreatureBodyPart(Ice::Int nPart, Ice::Int nModelNumber, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("setCreatureBodyPart"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nModelNumber);
  StackPushInteger(nPart);

  VM_ExecuteCommand(793, 3);

unlock("setCreatureBodyPart");
  
};

void NWScriptI::setCreatureTailType(Ice::Int nTailType, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("setCreatureTailType"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nTailType);

  VM_ExecuteCommand(795, 2);

unlock("setCreatureTailType");
  
};

void NWScriptI::setCreatureWingType(Ice::Int nWingType, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("setCreatureWingType"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nWingType);

  VM_ExecuteCommand(791, 2);

unlock("setCreatureWingType");
  
};

void NWScriptI::setCustomToken(Ice::Int nCustomTokenNumber, const std::string& sTokenValue, const Ice::Current& ice) {
  lock("setCustomToken"); callCounter += 1;
  StackPushString(sTokenValue.c_str());
  StackPushInteger(nCustomTokenNumber);

  VM_ExecuteCommand(284, 2);

unlock("setCustomToken");
  
};

void NWScriptI::setCutsceneCameraMoveRate(const NWN::NWObject& oCreature, Ice::Double fRate, const Ice::Current& ice) {
  lock("setCutsceneCameraMoveRate"); callCounter += 1;
  StackPushFloat(fRate);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(743, 2);

unlock("setCutsceneCameraMoveRate");
  
};

void NWScriptI::setCutsceneMode(const NWN::NWObject& oCreature, bool bInCutscene, bool bLeftClickingEnabled, const Ice::Current& ice) {
  lock("setCutsceneMode"); callCounter += 1;
  StackPushInteger(bLeftClickingEnabled == true ? 1 : 0);
  StackPushInteger(bInCutscene == true ? 1 : 0);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(692, 3);

unlock("setCutsceneMode");
  
};

void NWScriptI::setDeity(const NWN::NWObject& oCreature, const std::string& sDeity, const Ice::Current& ice) {
  lock("setDeity"); callCounter += 1;
  StackPushString(sDeity.c_str());
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(722, 2);

unlock("setDeity");
  
};

void NWScriptI::setDescription(const NWN::NWObject& oObject, const std::string& sNewDescription, bool bIdentifiedDescription, const Ice::Current& ice) {
  lock("setDescription"); callCounter += 1;
  StackPushInteger(bIdentifiedDescription == true ? 1 : 0);
  StackPushString(sNewDescription.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(837, 3);

unlock("setDescription");
  
};

void NWScriptI::setDroppableFlag(const NWN::NWObject& oItem, bool bDroppable, const Ice::Current& ice) {
  lock("setDroppableFlag"); callCounter += 1;
  StackPushInteger(bDroppable == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(705, 2);

unlock("setDroppableFlag");
  
};

void NWScriptI::setEncounterActive(bool bNewValue, const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  lock("setEncounterActive"); callCounter += 1;
  StackPushObject(oEncounter.id);
  StackPushInteger(bNewValue == true ? 1 : 0);

  VM_ExecuteCommand(277, 2);

unlock("setEncounterActive");
  
};

void NWScriptI::setEncounterDifficulty(Ice::Int nEncounterDifficulty, const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  lock("setEncounterDifficulty"); callCounter += 1;
  StackPushObject(oEncounter.id);
  StackPushInteger(nEncounterDifficulty);

  VM_ExecuteCommand(296, 2);

unlock("setEncounterDifficulty");
  
};

void NWScriptI::setEncounterSpawnsCurrent(Ice::Int nNewValue, const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  lock("setEncounterSpawnsCurrent"); callCounter += 1;
  StackPushObject(oEncounter.id);
  StackPushInteger(nNewValue);

  VM_ExecuteCommand(281, 2);

unlock("setEncounterSpawnsCurrent");
  
};

void NWScriptI::setEncounterSpawnsMax(Ice::Int nNewValue, const NWN::NWObject& oEncounter, const Ice::Current& ice) {
  lock("setEncounterSpawnsMax"); callCounter += 1;
  StackPushObject(oEncounter.id);
  StackPushInteger(nNewValue);

  VM_ExecuteCommand(279, 2);

unlock("setEncounterSpawnsMax");
  
};

void NWScriptI::setFacing(Ice::Double fDirection, const Ice::Current& ice) {
  lock("setFacing"); callCounter += 1;
  StackPushFloat(fDirection);

  VM_ExecuteCommand(10, 1);

unlock("setFacing");
  
};

void NWScriptI::setFacingPoint(const NWN::NWVector& vTarget, const Ice::Current& ice) {
  lock("setFacingPoint"); callCounter += 1;
  Vector vvTarget;
  vvTarget.X = vTarget.x; vvTarget.Y = vTarget.y; vvTarget.Z = vTarget.z;
  StackPushVector(vvTarget);

  VM_ExecuteCommand(143, 1);

unlock("setFacingPoint");
  
};

void NWScriptI::setFogAmount(Ice::Int nFogType, Ice::Int nFogAmount, const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("setFogAmount"); callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nFogAmount);
  StackPushInteger(nFogType);

  VM_ExecuteCommand(784, 3);

unlock("setFogAmount");
  
};

void NWScriptI::setFogColor(Ice::Int nFogType, Ice::Int nFogColor, const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("setFogColor"); callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nFogColor);
  StackPushInteger(nFogType);

  VM_ExecuteCommand(780, 3);

unlock("setFogColor");
  
};

void NWScriptI::setFootstepType(Ice::Int nFootstepType, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("setFootstepType"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nFootstepType);

  VM_ExecuteCommand(789, 2);

unlock("setFootstepType");
  
};

void NWScriptI::setFortitudeSavingThrow(const NWN::NWObject& oObject, Ice::Int nFortitudeSave, const Ice::Current& ice) {
  lock("setFortitudeSavingThrow"); callCounter += 1;
  StackPushInteger(nFortitudeSave);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(813, 2);

unlock("setFortitudeSavingThrow");
  
};

void NWScriptI::setHardness(Ice::Int nHardness, const NWN::NWObject& oObject, const Ice::Current& ice) {
  lock("setHardness"); callCounter += 1;
  StackPushObject(oObject.id);
  StackPushInteger(nHardness);

  VM_ExecuteCommand(797, 2);

unlock("setHardness");
  
};

void NWScriptI::setIdentified(const NWN::NWObject& oItem, bool bIdentified, const Ice::Current& ice) {
  lock("setIdentified"); callCounter += 1;
  StackPushInteger(bIdentified == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(333, 2);

unlock("setIdentified");
  
};

void NWScriptI::setImmortal(const NWN::NWObject& oCreature, bool bImmortal, const Ice::Current& ice) {
  lock("setImmortal"); callCounter += 1;
  StackPushInteger(bImmortal == true ? 1 : 0);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(700, 2);

unlock("setImmortal");
  
};

void NWScriptI::setInfiniteFlag(const NWN::NWObject& oItem, bool bInfinite, const Ice::Current& ice) {
  lock("setInfiniteFlag"); callCounter += 1;
  StackPushInteger(bInfinite == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(828, 2);

unlock("setInfiniteFlag");
  
};

void NWScriptI::setIsDestroyable(bool bDestroyable, bool bRaiseable, bool bSelectableWhenDead, const Ice::Current& ice) {
  lock("setIsDestroyable"); callCounter += 1;
  StackPushInteger(bSelectableWhenDead == true ? 1 : 0);
  StackPushInteger(bRaiseable == true ? 1 : 0);
  StackPushInteger(bDestroyable == true ? 1 : 0);

  VM_ExecuteCommand(323, 3);

unlock("setIsDestroyable");
  
};

void NWScriptI::setIsTemporaryEnemy(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, bool bDecays, Ice::Double fDurationInSeconds, const Ice::Current& ice) {
  lock("setIsTemporaryEnemy"); callCounter += 1;
  StackPushFloat(fDurationInSeconds);
  StackPushInteger(bDecays == true ? 1 : 0);
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(391, 4);

unlock("setIsTemporaryEnemy");
  
};

void NWScriptI::setIsTemporaryFriend(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, bool bDecays, Ice::Double fDurationInSeconds, const Ice::Current& ice) {
  lock("setIsTemporaryFriend"); callCounter += 1;
  StackPushFloat(fDurationInSeconds);
  StackPushInteger(bDecays == true ? 1 : 0);
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(390, 4);

unlock("setIsTemporaryFriend");
  
};

void NWScriptI::setIsTemporaryNeutral(const NWN::NWObject& oTarget, const NWN::NWObject& oSource, bool bDecays, Ice::Double fDurationInSeconds, const Ice::Current& ice) {
  lock("setIsTemporaryNeutral"); callCounter += 1;
  StackPushFloat(fDurationInSeconds);
  StackPushInteger(bDecays == true ? 1 : 0);
  StackPushObject(oSource.id);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(392, 4);

unlock("setIsTemporaryNeutral");
  
};

void NWScriptI::setItemCharges(const NWN::NWObject& oItem, Ice::Int nCharges, const Ice::Current& ice) {
  lock("setItemCharges"); callCounter += 1;
  StackPushInteger(nCharges);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(608, 2);

unlock("setItemCharges");
  
};

void NWScriptI::setItemCursedFlag(const NWN::NWObject& oItem, bool bCursed, const Ice::Current& ice) {
  lock("setItemCursedFlag"); callCounter += 1;
  StackPushInteger(bCursed == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(745, 2);

unlock("setItemCursedFlag");
  
};

void NWScriptI::setItemStackSize(const NWN::NWObject& oItem, Ice::Int nSize, const Ice::Current& ice) {
  lock("setItemStackSize"); callCounter += 1;
  StackPushInteger(nSize);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(606, 2);

unlock("setItemStackSize");
  
};

void NWScriptI::setKeyRequiredFeedback(const NWN::NWObject& oObject, const std::string& sFeedbackMessage, const Ice::Current& ice) {
  lock("setKeyRequiredFeedback"); callCounter += 1;
  StackPushString(sFeedbackMessage.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(820, 2);

unlock("setKeyRequiredFeedback");
  
};

void NWScriptI::setListenPattern(const NWN::NWObject& oObject, const std::string& sPattern, Ice::Int nNumber, const Ice::Current& ice) {
  lock("setListenPattern"); callCounter += 1;
  StackPushInteger(nNumber);
  StackPushString(sPattern.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(176, 3);

unlock("setListenPattern");
  
};

void NWScriptI::setListening(const NWN::NWObject& oObject, bool bValue, const Ice::Current& ice) {
  lock("setListening"); callCounter += 1;
  StackPushInteger(bValue == true ? 1 : 0);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(175, 2);

unlock("setListening");
  
};

void NWScriptI::setLocalFloat(const NWN::NWObject& oObject, const std::string& sVarName, Ice::Double fValue, const Ice::Current& ice) {
  lock("setLocalFloat"); callCounter += 1;
  StackPushFloat(fValue);
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(56, 3);

unlock("setLocalFloat");
  
};

void NWScriptI::setLocalInt(const NWN::NWObject& oObject, const std::string& sVarName, Ice::Int nValue, const Ice::Current& ice) {
  lock("setLocalInt"); callCounter += 1;
  StackPushInteger(nValue);
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(55, 3);

unlock("setLocalInt");
  
};

void NWScriptI::setLocalLocation(const NWN::NWObject& oObject, const std::string& sVarName, const NWN::NWLocation& lValue, const Ice::Current& ice) {
  lock("setLocalLocation"); callCounter += 1;
  CScriptLocation *lValue_ptr;
  lValue_ptr->X = lValue.x;
  lValue_ptr->Y = lValue.y;
  lValue_ptr->Z = lValue.z;
  lValue_ptr->OrientationX = lValue.orientationX;
  lValue_ptr->OrientationY = lValue.orientationY;
  lValue_ptr->OrientationZ = lValue.orientationZ;
  lValue_ptr->AreaID = lValue.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lValue_ptr);
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(152, 3);

unlock("setLocalLocation");
  
};

void NWScriptI::setLocalObject(const NWN::NWObject& oObject, const std::string& sVarName, const NWN::NWObject& oValue, const Ice::Current& ice) {
  lock("setLocalObject"); callCounter += 1;
  StackPushObject(oValue.id);
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(58, 3);

unlock("setLocalObject");
  
};

void NWScriptI::setLocalString(const NWN::NWObject& oObject, const std::string& sVarName, const std::string& sValue, const Ice::Current& ice) {
  lock("setLocalString"); callCounter += 1;
  StackPushString(sValue.c_str());
  StackPushString(sVarName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(57, 3);

unlock("setLocalString");
  
};

void NWScriptI::setLockKeyRequired(const NWN::NWObject& oObject, bool bKeyRequired, const Ice::Current& ice) {
  lock("setLockKeyRequired"); callCounter += 1;
  StackPushInteger(bKeyRequired == true ? 1 : 0);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(798, 2);

unlock("setLockKeyRequired");
  
};

void NWScriptI::setLockKeyTag(const NWN::NWObject& oObject, const std::string& sNewKeyTag, const Ice::Current& ice) {
  lock("setLockKeyTag"); callCounter += 1;
  StackPushString(sNewKeyTag.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(799, 2);

unlock("setLockKeyTag");
  
};

void NWScriptI::setLockLockDC(const NWN::NWObject& oObject, Ice::Int nNewLockDC, const Ice::Current& ice) {
  lock("setLockLockDC"); callCounter += 1;
  StackPushInteger(nNewLockDC);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(802, 2);

unlock("setLockLockDC");
  
};

void NWScriptI::setLockLockable(const NWN::NWObject& oObject, bool bLockable, const Ice::Current& ice) {
  lock("setLockLockable"); callCounter += 1;
  StackPushInteger(bLockable == true ? 1 : 0);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(800, 2);

unlock("setLockLockable");
  
};

void NWScriptI::setLockUnlockDC(const NWN::NWObject& oObject, Ice::Int nNewUnlockDC, const Ice::Current& ice) {
  lock("setLockUnlockDC"); callCounter += 1;
  StackPushInteger(nNewUnlockDC);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(801, 2);

unlock("setLockUnlockDC");
  
};

void NWScriptI::setLocked(const NWN::NWObject& oTarget, bool bLocked, const Ice::Current& ice) {
  lock("setLocked"); callCounter += 1;
  StackPushInteger(bLocked == true ? 1 : 0);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(324, 2);

unlock("setLocked");
  
};

void NWScriptI::setLootable(const NWN::NWObject& oCreature, bool bLootable, const Ice::Current& ice) {
  lock("setLootable"); callCounter += 1;
  StackPushInteger(bLootable == true ? 1 : 0);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(740, 2);

unlock("setLootable");
  
};

void NWScriptI::setMapPinEnabled(const NWN::NWObject& oMapPin, bool bEnabled, const Ice::Current& ice) {
  lock("setMapPinEnabled"); callCounter += 1;
  StackPushInteger(bEnabled == true ? 1 : 0);
  StackPushObject(oMapPin.id);

  VM_ExecuteCommand(386, 2);

unlock("setMapPinEnabled");
  
};

void NWScriptI::setMaxHenchmen(Ice::Int nNumHenchmen, const Ice::Current& ice) {
  lock("setMaxHenchmen"); callCounter += 1;
  StackPushInteger(nNumHenchmen);

  VM_ExecuteCommand(746, 1);

unlock("setMaxHenchmen");
  
};

void NWScriptI::setModuleXPScale(Ice::Int nXPScale, const Ice::Current& ice) {
  lock("setModuleXPScale"); callCounter += 1;
  StackPushInteger(nXPScale);

  VM_ExecuteCommand(818, 1);

unlock("setModuleXPScale");
  
};

void NWScriptI::setName(const NWN::NWObject& oObject, const std::string& sNewName, const Ice::Current& ice) {
  lock("setName"); callCounter += 1;
  StackPushString(sNewName.c_str());
  StackPushObject(oObject.id);

  VM_ExecuteCommand(830, 2);

unlock("setName");
  
};

void NWScriptI::setPCChatMessage(const std::string& sNewChatMessage, const Ice::Current& ice) {
  lock("setPCChatMessage"); callCounter += 1;
  StackPushString(sNewChatMessage.c_str());

  VM_ExecuteCommand(841, 1);

unlock("setPCChatMessage");
  
};

void NWScriptI::setPCChatVolume(NWN::TalkVolume tTalkVolume, const Ice::Current& ice) {
  lock("setPCChatVolume"); callCounter += 1;
  if (tTalkVolume == NWN::PartyVol) StackPushInteger(5);
   else if (tTalkVolume == NWN::TalkVol) StackPushInteger(0);
   else if (tTalkVolume == NWN::TellVol) StackPushInteger(6);
   else if (tTalkVolume == NWN::WhisperVol) StackPushInteger(1);
   else if (tTalkVolume == NWN::ShoutVol) StackPushInteger(2);
   else if (tTalkVolume == NWN::SilentTalkVol) StackPushInteger(3);
   else if (tTalkVolume == NWN::SilentShoutVol) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(842, 1);

unlock("setPCChatVolume");
  
};

void NWScriptI::setPCDislike(const NWN::NWObject& oPlayer, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("setPCDislike"); callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(373, 2);

unlock("setPCDislike");
  
};

void NWScriptI::setPCLike(const NWN::NWObject& oPlayer, const NWN::NWObject& oTarget, const Ice::Current& ice) {
  lock("setPCLike"); callCounter += 1;
  StackPushObject(oTarget.id);
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(372, 2);

unlock("setPCLike");
  
};

void NWScriptI::setPanelButtonFlash(const NWN::NWObject& oPlayer, NWN::Button tButton, bool bEnableFlash, const Ice::Current& ice) {
  lock("setPanelButtonFlash"); callCounter += 1;
  StackPushInteger(bEnableFlash == true ? 1 : 0);
  if (tButton == NWN::SpellsButton) StackPushInteger(5);
   else if (tButton == NWN::MapButton) StackPushInteger(0);
   else if (tButton == NWN::RestButton) StackPushInteger(6);
   else if (tButton == NWN::InventoryButton) StackPushInteger(1);
   else if (tButton == NWN::PvPButton) StackPushInteger(7);
   else if (tButton == NWN::JournalButton) StackPushInteger(2);
   else if (tButton == NWN::CharacterButton) StackPushInteger(3);
   else if (tButton == NWN::OptionsButton) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oPlayer.id);

  VM_ExecuteCommand(521, 3);

unlock("setPanelButtonFlash");
  
};

void NWScriptI::setPhenoType(NWN::PhenoType tPhenoType, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("setPhenoType"); callCounter += 1;
  StackPushObject(oCreature.id);
  if (tPhenoType == NWN::Custom14PhenoType) StackPushInteger(16);
   else if (tPhenoType == NWN::Custom3PhenoType) StackPushInteger(5);
   else if (tPhenoType == NWN::Custom9PhenoType) StackPushInteger(11);
   else if (tPhenoType == NWN::NormalPhenoType) StackPushInteger(0);
   else if (tPhenoType == NWN::Custom15PhenoType) StackPushInteger(17);
   else if (tPhenoType == NWN::Custom4PhenoType) StackPushInteger(6);
   else if (tPhenoType == NWN::Custom10PhenoType) StackPushInteger(12);
   else if (tPhenoType == NWN::Custom16PhenoType) StackPushInteger(18);
   else if (tPhenoType == NWN::Custom5PhenoType) StackPushInteger(7);
   else if (tPhenoType == NWN::Custom11PhenoType) StackPushInteger(13);
   else if (tPhenoType == NWN::BigPhenoType) StackPushInteger(2);
   else if (tPhenoType == NWN::Custom17PhenoType) StackPushInteger(19);
   else if (tPhenoType == NWN::Custom6PhenoType) StackPushInteger(8);
   else if (tPhenoType == NWN::Custom12PhenoType) StackPushInteger(14);
   else if (tPhenoType == NWN::Custom1PhenoType) StackPushInteger(3);
   else if (tPhenoType == NWN::Custom18PhenoType) StackPushInteger(20);
   else if (tPhenoType == NWN::Custom7PhenoType) StackPushInteger(9);
   else if (tPhenoType == NWN::Custom13PhenoType) StackPushInteger(15);
   else if (tPhenoType == NWN::Custom2PhenoType) StackPushInteger(4);
   else if (tPhenoType == NWN::Custom8PhenoType) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(779, 2);

unlock("setPhenoType");
  
};

void NWScriptI::setPickpocketableFlag(const NWN::NWObject& oItem, bool bPickpocketable, const Ice::Current& ice) {
  lock("setPickpocketableFlag"); callCounter += 1;
  StackPushInteger(bPickpocketable == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(787, 2);

unlock("setPickpocketableFlag");
  
};

void NWScriptI::setPlaceableIllumination(const NWN::NWObject& oPlaceable, bool bIlluminate, const Ice::Current& ice) {
  lock("setPlaceableIllumination"); callCounter += 1;
  StackPushInteger(bIlluminate == true ? 1 : 0);
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(544, 2);

unlock("setPlaceableIllumination");
  
};

void NWScriptI::setPlotFlag(const NWN::NWObject& oTarget, bool bPlotFlag, const Ice::Current& ice) {
  lock("setPlotFlag"); callCounter += 1;
  StackPushInteger(bPlotFlag == true ? 1 : 0);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(456, 2);

unlock("setPlotFlag");
  
};

void NWScriptI::setPortraitId(const NWN::NWObject& oTarget, Ice::Int nPortraitId, const Ice::Current& ice) {
  lock("setPortraitId"); callCounter += 1;
  StackPushInteger(nPortraitId);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(832, 2);

unlock("setPortraitId");
  
};

void NWScriptI::setPortraitResRef(const NWN::NWObject& oTarget, const std::string& sPortraitResRef, const Ice::Current& ice) {
  lock("setPortraitResRef"); callCounter += 1;
  StackPushString(sPortraitResRef.c_str());
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(834, 2);

unlock("setPortraitResRef");
  
};

void NWScriptI::setReflexSavingThrow(const NWN::NWObject& oObject, Ice::Int nReflexSave, const Ice::Current& ice) {
  lock("setReflexSavingThrow"); callCounter += 1;
  StackPushInteger(nReflexSave);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(812, 2);

unlock("setReflexSavingThrow");
  
};

void NWScriptI::setSkyBox(Ice::Int nSkyBox, const NWN::NWObject& oArea, const Ice::Current& ice) {
  lock("setSkyBox"); callCounter += 1;
  StackPushObject(oArea.id);
  StackPushInteger(nSkyBox);

  VM_ExecuteCommand(777, 2);

unlock("setSkyBox");
  
};

void NWScriptI::setStandardFactionReputation(NWN::StandardFaction tStandardFaction, Ice::Int nNewReputation, const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("setStandardFactionReputation"); callCounter += 1;
  StackPushObject(oCreature.id);
  StackPushInteger(nNewReputation);
  if (tStandardFaction == NWN::Hostile) StackPushInteger(0);
   else if (tStandardFaction == NWN::Commoner) StackPushInteger(1);
   else if (tStandardFaction == NWN::Merchant) StackPushInteger(2);
   else if (tStandardFaction == NWN::Defender) StackPushInteger(3);
   else throw "fail: invalid struct value passed, internal API error";

  VM_ExecuteCommand(523, 3);

unlock("setStandardFactionReputation");
  
};

void NWScriptI::setStolenFlag(const NWN::NWObject& oItem, bool bStolenFlag, const Ice::Current& ice) {
  lock("setStolenFlag"); callCounter += 1;
  StackPushInteger(bStolenFlag == true ? 1 : 0);
  StackPushObject(oItem.id);

  VM_ExecuteCommand(774, 2);

unlock("setStolenFlag");
  
};

void NWScriptI::setStoreGold(const NWN::NWObject& oidStore, Ice::Int nGold, const Ice::Current& ice) {
  lock("setStoreGold"); callCounter += 1;
  StackPushInteger(nGold);
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(760, 2);

unlock("setStoreGold");
  
};

void NWScriptI::setStoreIdentifyCost(const NWN::NWObject& oidStore, Ice::Int nCost, const Ice::Current& ice) {
  lock("setStoreIdentifyCost"); callCounter += 1;
  StackPushInteger(nCost);
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(764, 2);

unlock("setStoreIdentifyCost");
  
};

void NWScriptI::setStoreMaxBuyPrice(const NWN::NWObject& oidStore, Ice::Int nMaxBuy, const Ice::Current& ice) {
  lock("setStoreMaxBuyPrice"); callCounter += 1;
  StackPushInteger(nMaxBuy);
  StackPushObject(oidStore.id);

  VM_ExecuteCommand(762, 2);

unlock("setStoreMaxBuyPrice");
  
};

void NWScriptI::setSubRace(const NWN::NWObject& oCreature, const std::string& sSubRace, const Ice::Current& ice) {
  lock("setSubRace"); callCounter += 1;
  StackPushString(sSubRace.c_str());
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(721, 2);

unlock("setSubRace");
  
};

void NWScriptI::setTileMainLightColor(const NWN::NWLocation& lTileLocation, NWN::TileMainLightColor nMainLight1Color, NWN::TileMainLightColor nMainLight2Color, const Ice::Current& ice) {
  lock("setTileMainLightColor"); callCounter += 1;
  if (nMainLight2Color == NWN::RedTileMainLightColor) StackPushInteger(27);
   else if (nMainLight2Color == NWN::PaleDarkBlueTileMainLightColor) StackPushInteger(16);
   else if (nMainLight2Color == NWN::DarkYellowTileMainLightColor) StackPushInteger(5);
   else if (nMainLight2Color == NWN::PalePurpleTileMainLightColor) StackPushInteger(22);
   else if (nMainLight2Color == NWN::GreenTileMainLightColor) StackPushInteger(11);
   else if (nMainLight2Color == NWN::BlackTileMainLightColor) StackPushInteger(0);
   else if (nMainLight2Color == NWN::PaleDarkOrangeTileMainLightColor) StackPushInteger(28);
   else if (nMainLight2Color == NWN::DarkBlueTileMainLightColor) StackPushInteger(17);
   else if (nMainLight2Color == NWN::PaleYellowTileMainLightColor) StackPushInteger(6);
   else if (nMainLight2Color == NWN::PurpleTileMainLightColor) StackPushInteger(23);
   else if (nMainLight2Color == NWN::PaleDarkAquaTileMainLightColor) StackPushInteger(12);
   else if (nMainLight2Color == NWN::DimWhiteTileMainLightColor) StackPushInteger(1);
   else if (nMainLight2Color == NWN::DarkOrangeTileMainLightColor) StackPushInteger(29);
   else if (nMainLight2Color == NWN::PaleBlueTileMainLightColor) StackPushInteger(18);
   else if (nMainLight2Color == NWN::YellowTileMainLightColor) StackPushInteger(7);
   else if (nMainLight2Color == NWN::PaleDarkRedTileMainLightColor) StackPushInteger(24);
   else if (nMainLight2Color == NWN::DarkAquaTileMainLightColor) StackPushInteger(13);
   else if (nMainLight2Color == NWN::WhiteTileMainLightColor) StackPushInteger(2);
   else if (nMainLight2Color == NWN::PaleOrangeTileMainLightColor) StackPushInteger(30);
   else if (nMainLight2Color == NWN::BlueTileMainLightColor) StackPushInteger(19);
   else if (nMainLight2Color == NWN::PaleDarkGreenTileMainLightColor) StackPushInteger(8);
   else if (nMainLight2Color == NWN::DarkRedTileMainLightColor) StackPushInteger(25);
   else if (nMainLight2Color == NWN::PaleAquaTileMainLightColor) StackPushInteger(14);
   else if (nMainLight2Color == NWN::BrightWhiteTileMainLightColor) StackPushInteger(3);
   else if (nMainLight2Color == NWN::OrangeTileMainLightColor) StackPushInteger(31);
   else if (nMainLight2Color == NWN::PaleDarkPurpleTileMainLightColor) StackPushInteger(20);
   else if (nMainLight2Color == NWN::DarkGreenTileMainLightColor) StackPushInteger(9);
   else if (nMainLight2Color == NWN::PaleRedTileMainLightColor) StackPushInteger(26);
   else if (nMainLight2Color == NWN::AquaTileMainLightColor) StackPushInteger(15);
   else if (nMainLight2Color == NWN::PaleDarkYellowTileMainLightColor) StackPushInteger(4);
   else if (nMainLight2Color == NWN::DarkPurpleTileMainLightColor) StackPushInteger(21);
   else if (nMainLight2Color == NWN::PaleGreenTileMainLightColor) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
  if (nMainLight1Color == NWN::RedTileMainLightColor) StackPushInteger(27);
   else if (nMainLight1Color == NWN::PaleDarkBlueTileMainLightColor) StackPushInteger(16);
   else if (nMainLight1Color == NWN::DarkYellowTileMainLightColor) StackPushInteger(5);
   else if (nMainLight1Color == NWN::PalePurpleTileMainLightColor) StackPushInteger(22);
   else if (nMainLight1Color == NWN::GreenTileMainLightColor) StackPushInteger(11);
   else if (nMainLight1Color == NWN::BlackTileMainLightColor) StackPushInteger(0);
   else if (nMainLight1Color == NWN::PaleDarkOrangeTileMainLightColor) StackPushInteger(28);
   else if (nMainLight1Color == NWN::DarkBlueTileMainLightColor) StackPushInteger(17);
   else if (nMainLight1Color == NWN::PaleYellowTileMainLightColor) StackPushInteger(6);
   else if (nMainLight1Color == NWN::PurpleTileMainLightColor) StackPushInteger(23);
   else if (nMainLight1Color == NWN::PaleDarkAquaTileMainLightColor) StackPushInteger(12);
   else if (nMainLight1Color == NWN::DimWhiteTileMainLightColor) StackPushInteger(1);
   else if (nMainLight1Color == NWN::DarkOrangeTileMainLightColor) StackPushInteger(29);
   else if (nMainLight1Color == NWN::PaleBlueTileMainLightColor) StackPushInteger(18);
   else if (nMainLight1Color == NWN::YellowTileMainLightColor) StackPushInteger(7);
   else if (nMainLight1Color == NWN::PaleDarkRedTileMainLightColor) StackPushInteger(24);
   else if (nMainLight1Color == NWN::DarkAquaTileMainLightColor) StackPushInteger(13);
   else if (nMainLight1Color == NWN::WhiteTileMainLightColor) StackPushInteger(2);
   else if (nMainLight1Color == NWN::PaleOrangeTileMainLightColor) StackPushInteger(30);
   else if (nMainLight1Color == NWN::BlueTileMainLightColor) StackPushInteger(19);
   else if (nMainLight1Color == NWN::PaleDarkGreenTileMainLightColor) StackPushInteger(8);
   else if (nMainLight1Color == NWN::DarkRedTileMainLightColor) StackPushInteger(25);
   else if (nMainLight1Color == NWN::PaleAquaTileMainLightColor) StackPushInteger(14);
   else if (nMainLight1Color == NWN::BrightWhiteTileMainLightColor) StackPushInteger(3);
   else if (nMainLight1Color == NWN::OrangeTileMainLightColor) StackPushInteger(31);
   else if (nMainLight1Color == NWN::PaleDarkPurpleTileMainLightColor) StackPushInteger(20);
   else if (nMainLight1Color == NWN::DarkGreenTileMainLightColor) StackPushInteger(9);
   else if (nMainLight1Color == NWN::PaleRedTileMainLightColor) StackPushInteger(26);
   else if (nMainLight1Color == NWN::AquaTileMainLightColor) StackPushInteger(15);
   else if (nMainLight1Color == NWN::PaleDarkYellowTileMainLightColor) StackPushInteger(4);
   else if (nMainLight1Color == NWN::DarkPurpleTileMainLightColor) StackPushInteger(21);
   else if (nMainLight1Color == NWN::PaleGreenTileMainLightColor) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
  CScriptLocation *lTileLocation_ptr;
  lTileLocation_ptr->X = lTileLocation.x;
  lTileLocation_ptr->Y = lTileLocation.y;
  lTileLocation_ptr->Z = lTileLocation.z;
  lTileLocation_ptr->OrientationX = lTileLocation.orientationX;
  lTileLocation_ptr->OrientationY = lTileLocation.orientationY;
  lTileLocation_ptr->OrientationZ = lTileLocation.orientationZ;
  lTileLocation_ptr->AreaID = lTileLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTileLocation_ptr);

  VM_ExecuteCommand(514, 3);

unlock("setTileMainLightColor");
  
};

void NWScriptI::setTileSourceLightColor(const NWN::NWLocation& lTileLocation, NWN::TileSourceLightColor nSourceLight1Color, NWN::TileSourceLightColor nSourceLight2Color, const Ice::Current& ice) {
  lock("setTileSourceLightColor"); callCounter += 1;
  if (nSourceLight2Color == NWN::PaleGreenTileSourceLightColor) StackPushInteger(5);
   else if (nSourceLight2Color == NWN::PalePurpleTileSourceLightColor) StackPushInteger(11);
   else if (nSourceLight2Color == NWN::BlackTileSourceLightColor) StackPushInteger(0);
   else if (nSourceLight2Color == NWN::PaleDarkAquaTileSourceLightColor) StackPushInteger(6);
   else if (nSourceLight2Color == NWN::PaleDarkRedTileSourceLightColor) StackPushInteger(12);
   else if (nSourceLight2Color == NWN::WhiteTileSourceLightColor) StackPushInteger(1);
   else if (nSourceLight2Color == NWN::PaleAquaTileSourceLightColor) StackPushInteger(7);
   else if (nSourceLight2Color == NWN::PaleRedTileSourceLightColor) StackPushInteger(13);
   else if (nSourceLight2Color == NWN::PaleDarkYellowTileSourceLightColor) StackPushInteger(2);
   else if (nSourceLight2Color == NWN::PaleDarkBlueTileSourceLightColor) StackPushInteger(8);
   else if (nSourceLight2Color == NWN::PaleDarkOrangeTileSourceLightColor) StackPushInteger(14);
   else if (nSourceLight2Color == NWN::PaleYellowTileSourceLightColor) StackPushInteger(3);
   else if (nSourceLight2Color == NWN::PaleBlueTileSourceLightColor) StackPushInteger(9);
   else if (nSourceLight2Color == NWN::PaleOrangeTileSourceLightColor) StackPushInteger(15);
   else if (nSourceLight2Color == NWN::PaleDarkGreenTileSourceLightColor) StackPushInteger(4);
   else if (nSourceLight2Color == NWN::PaleDarkPurpleTileSourceLightColor) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
  if (nSourceLight1Color == NWN::PaleGreenTileSourceLightColor) StackPushInteger(5);
   else if (nSourceLight1Color == NWN::PalePurpleTileSourceLightColor) StackPushInteger(11);
   else if (nSourceLight1Color == NWN::BlackTileSourceLightColor) StackPushInteger(0);
   else if (nSourceLight1Color == NWN::PaleDarkAquaTileSourceLightColor) StackPushInteger(6);
   else if (nSourceLight1Color == NWN::PaleDarkRedTileSourceLightColor) StackPushInteger(12);
   else if (nSourceLight1Color == NWN::WhiteTileSourceLightColor) StackPushInteger(1);
   else if (nSourceLight1Color == NWN::PaleAquaTileSourceLightColor) StackPushInteger(7);
   else if (nSourceLight1Color == NWN::PaleRedTileSourceLightColor) StackPushInteger(13);
   else if (nSourceLight1Color == NWN::PaleDarkYellowTileSourceLightColor) StackPushInteger(2);
   else if (nSourceLight1Color == NWN::PaleDarkBlueTileSourceLightColor) StackPushInteger(8);
   else if (nSourceLight1Color == NWN::PaleDarkOrangeTileSourceLightColor) StackPushInteger(14);
   else if (nSourceLight1Color == NWN::PaleYellowTileSourceLightColor) StackPushInteger(3);
   else if (nSourceLight1Color == NWN::PaleBlueTileSourceLightColor) StackPushInteger(9);
   else if (nSourceLight1Color == NWN::PaleOrangeTileSourceLightColor) StackPushInteger(15);
   else if (nSourceLight1Color == NWN::PaleDarkGreenTileSourceLightColor) StackPushInteger(4);
   else if (nSourceLight1Color == NWN::PaleDarkPurpleTileSourceLightColor) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
  CScriptLocation *lTileLocation_ptr;
  lTileLocation_ptr->X = lTileLocation.x;
  lTileLocation_ptr->Y = lTileLocation.y;
  lTileLocation_ptr->Z = lTileLocation.z;
  lTileLocation_ptr->OrientationX = lTileLocation.orientationX;
  lTileLocation_ptr->OrientationY = lTileLocation.orientationY;
  lTileLocation_ptr->OrientationZ = lTileLocation.orientationZ;
  lTileLocation_ptr->AreaID = lTileLocation.area.id;
  StackPushEngineStructure(ENGINE_STRUCTURE_LOCATION, lTileLocation_ptr);

  VM_ExecuteCommand(515, 3);

unlock("setTileSourceLightColor");
  
};

void NWScriptI::setTime(Ice::Int nHour, Ice::Int nMinute, Ice::Int nSecond, Ice::Int nMillisecond, const Ice::Current& ice) {
  lock("setTime"); callCounter += 1;
  StackPushInteger(nMillisecond);
  StackPushInteger(nSecond);
  StackPushInteger(nMinute);
  StackPushInteger(nHour);

  VM_ExecuteCommand(12, 4);

unlock("setTime");
  
};

void NWScriptI::setTrapActive(const NWN::NWObject& oTrapObject, bool bActive, const Ice::Current& ice) {
  lock("setTrapActive"); callCounter += 1;
  StackPushInteger(bActive == true ? 1 : 0);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(822, 2);

unlock("setTrapActive");
  
};

void NWScriptI::setTrapDetectDC(const NWN::NWObject& oTrapObject, Ice::Int nDetectDC, const Ice::Current& ice) {
  lock("setTrapDetectDC"); callCounter += 1;
  StackPushInteger(nDetectDC);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(808, 2);

unlock("setTrapDetectDC");
  
};

void NWScriptI::setTrapDetectable(const NWN::NWObject& oTrapObject, bool bDetectable, const Ice::Current& ice) {
  lock("setTrapDetectable"); callCounter += 1;
  StackPushInteger(bDetectable == true ? 1 : 0);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(804, 2);

unlock("setTrapDetectable");
  
};

Ice::Int NWScriptI::setTrapDetectedBy(const NWN::NWObject& oTrap, const NWN::NWObject& oDetector, bool bDetected, const Ice::Current& ice) {
  lock("setTrapDetectedBy"); callCounter += 1;
  StackPushInteger(bDetected == true ? 1 : 0);
  StackPushObject(oDetector.id);
  StackPushObject(oTrap.id);

  VM_ExecuteCommand(550, 3);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("setTrapDetectedBy");
  return nRetVal;
};

void NWScriptI::setTrapDisabled(const NWN::NWObject& oTrap, const Ice::Current& ice) {
  lock("setTrapDisabled"); callCounter += 1;
  StackPushObject(oTrap.id);

  VM_ExecuteCommand(555, 1);

unlock("setTrapDisabled");
  
};

void NWScriptI::setTrapDisarmDC(const NWN::NWObject& oTrapObject, Ice::Int nDisarmDC, const Ice::Current& ice) {
  lock("setTrapDisarmDC"); callCounter += 1;
  StackPushInteger(nDisarmDC);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(807, 2);

unlock("setTrapDisarmDC");
  
};

void NWScriptI::setTrapDisarmable(const NWN::NWObject& oTrapObject, bool bDisarmable, const Ice::Current& ice) {
  lock("setTrapDisarmable"); callCounter += 1;
  StackPushInteger(bDisarmable == true ? 1 : 0);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(803, 2);

unlock("setTrapDisarmable");
  
};

void NWScriptI::setTrapKeyTag(const NWN::NWObject& oTrapObject, const std::string& sKeyTag, const Ice::Current& ice) {
  lock("setTrapKeyTag"); callCounter += 1;
  StackPushString(sKeyTag.c_str());
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(806, 2);

unlock("setTrapKeyTag");
  
};

void NWScriptI::setTrapOneShot(const NWN::NWObject& oTrapObject, bool bOneShot, const Ice::Current& ice) {
  lock("setTrapOneShot"); callCounter += 1;
  StackPushInteger(bOneShot == true ? 1 : 0);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(805, 2);

unlock("setTrapOneShot");
  
};

void NWScriptI::setTrapRecoverable(const NWN::NWObject& oTrapObject, bool bRecoverable, const Ice::Current& ice) {
  lock("setTrapRecoverable"); callCounter += 1;
  StackPushInteger(bRecoverable == true ? 1 : 0);
  StackPushObject(oTrapObject.id);

  VM_ExecuteCommand(816, 2);

unlock("setTrapRecoverable");
  
};

void NWScriptI::setUseableFlag(const NWN::NWObject& oPlaceable, bool bUseableFlag, const Ice::Current& ice) {
  lock("setUseableFlag"); callCounter += 1;
  StackPushInteger(bUseableFlag == true ? 1 : 0);
  StackPushObject(oPlaceable.id);

  VM_ExecuteCommand(835, 2);

unlock("setUseableFlag");
  
};

void NWScriptI::setWeather(const NWN::NWObject& oTarget, NWN::Weather tWeather, const Ice::Current& ice) {
  lock("setWeather"); callCounter += 1;
  if (tWeather == NWN::ClearWeather) StackPushInteger(0);
   else if (tWeather == NWN::RainWeather) StackPushInteger(1);
   else if (tWeather == NWN::InvalidWeather) StackPushInteger(-1);
   else if (tWeather == NWN::SnowWeather) StackPushInteger(2);
   else if (tWeather == NWN::AreaDefaultsWeather) StackPushInteger(3);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(507, 2);

unlock("setWeather");
  
};

void NWScriptI::setWillSavingThrow(const NWN::NWObject& oObject, Ice::Int nWillSave, const Ice::Current& ice) {
  lock("setWillSavingThrow"); callCounter += 1;
  StackPushInteger(nWillSave);
  StackPushObject(oObject.id);

  VM_ExecuteCommand(811, 2);

unlock("setWillSavingThrow");
  
};

void NWScriptI::setXP(const NWN::NWObject& oCreature, Ice::Int nXpAmount, const Ice::Current& ice) {
  lock("setXP"); callCounter += 1;
  StackPushInteger(nXpAmount);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(394, 2);

unlock("setXP");
  
};

Ice::Double NWScriptI::sin(Ice::Double fValue, const Ice::Current& ice) {
  lock("sin"); callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(69, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("sin");
  return fRetVal;
};

void NWScriptI::soundObjectPlay(const NWN::NWObject& oSound, const Ice::Current& ice) {
  lock("soundObjectPlay"); callCounter += 1;
  StackPushObject(oSound.id);

  VM_ExecuteCommand(413, 1);

unlock("soundObjectPlay");
  
};

void NWScriptI::soundObjectSetPosition(const NWN::NWObject& oSound, const NWN::NWVector& vPosition, const Ice::Current& ice) {
  lock("soundObjectSetPosition"); callCounter += 1;
  Vector vvPosition;
  vvPosition.X = vPosition.x; vvPosition.Y = vPosition.y; vvPosition.Z = vPosition.z;
  StackPushVector(vvPosition);
  StackPushObject(oSound.id);

  VM_ExecuteCommand(416, 2);

unlock("soundObjectSetPosition");
  
};

void NWScriptI::soundObjectSetVolume(const NWN::NWObject& oSound, Ice::Int nVolume, const Ice::Current& ice) {
  lock("soundObjectSetVolume"); callCounter += 1;
  StackPushInteger(nVolume);
  StackPushObject(oSound.id);

  VM_ExecuteCommand(415, 2);

unlock("soundObjectSetVolume");
  
};

void NWScriptI::soundObjectStop(const NWN::NWObject& oSound, const Ice::Current& ice) {
  lock("soundObjectStop"); callCounter += 1;
  StackPushObject(oSound.id);

  VM_ExecuteCommand(414, 1);

unlock("soundObjectStop");
  
};

void NWScriptI::spawnScriptDebugger(const Ice::Current& ice) {
  lock("spawnScriptDebugger"); callCounter += 1;

  VM_ExecuteCommand(578, 0);

unlock("spawnScriptDebugger");
  
};

void NWScriptI::speakOneLinerConversation(const std::string& sDialogResRef, const NWN::NWObject& oTokenTarget, const Ice::Current& ice) {
  lock("speakOneLinerConversation"); callCounter += 1;
  StackPushObject(oTokenTarget.id);
  StackPushString(sDialogResRef.c_str());

  VM_ExecuteCommand(417, 2);

unlock("speakOneLinerConversation");
  
};

void NWScriptI::speakString(const std::string& sStringToSpeak, NWN::TalkVolume tTalkVolume, const Ice::Current& ice) {
  lock("speakString"); callCounter += 1;
  if (tTalkVolume == NWN::PartyVol) StackPushInteger(5);
   else if (tTalkVolume == NWN::TalkVol) StackPushInteger(0);
   else if (tTalkVolume == NWN::TellVol) StackPushInteger(6);
   else if (tTalkVolume == NWN::WhisperVol) StackPushInteger(1);
   else if (tTalkVolume == NWN::ShoutVol) StackPushInteger(2);
   else if (tTalkVolume == NWN::SilentTalkVol) StackPushInteger(3);
   else if (tTalkVolume == NWN::SilentShoutVol) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushString(sStringToSpeak.c_str());

  VM_ExecuteCommand(221, 2);

unlock("speakString");
  
};

void NWScriptI::speakStringByStrRef(Ice::Int nStrRef, NWN::TalkVolume tTalkVolume, const Ice::Current& ice) {
  lock("speakStringByStrRef"); callCounter += 1;
  if (tTalkVolume == NWN::PartyVol) StackPushInteger(5);
   else if (tTalkVolume == NWN::TalkVol) StackPushInteger(0);
   else if (tTalkVolume == NWN::TellVol) StackPushInteger(6);
   else if (tTalkVolume == NWN::WhisperVol) StackPushInteger(1);
   else if (tTalkVolume == NWN::ShoutVol) StackPushInteger(2);
   else if (tTalkVolume == NWN::SilentTalkVol) StackPushInteger(3);
   else if (tTalkVolume == NWN::SilentShoutVol) StackPushInteger(4);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushInteger(nStrRef);

  VM_ExecuteCommand(691, 2);

unlock("speakStringByStrRef");
  
};

Ice::Double NWScriptI::sqrt(Ice::Double fValue, const Ice::Current& ice) {
  lock("sqrt"); callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(76, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("sqrt");
  return fRetVal;
};

void NWScriptI::startNewModule(const std::string& sModuleName, const Ice::Current& ice) {
  lock("startNewModule"); callCounter += 1;
  StackPushString(sModuleName.c_str());

  VM_ExecuteCommand(509, 1);

unlock("startNewModule");
  
};

void NWScriptI::stopFade(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("stopFade"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(697, 1);

unlock("stopFade");
  
};

void NWScriptI::storeCameraFacing(const Ice::Current& ice) {
  lock("storeCameraFacing"); callCounter += 1;

  VM_ExecuteCommand(702, 0);

unlock("storeCameraFacing");
  
};

Ice::Int NWScriptI::storeCampaignObject(const std::string& sCampaignName, const std::string& sVarName, const NWN::NWObject& oObject, const NWN::NWObject& oPlayer, const Ice::Current& ice) {
  lock("storeCampaignObject"); callCounter += 1;
  StackPushObject(oPlayer.id);
  StackPushObject(oObject.id);
  StackPushString(sVarName.c_str());
  StackPushString(sCampaignName.c_str());

  VM_ExecuteCommand(602, 4);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("storeCampaignObject");
  return nRetVal;
};

Ice::Double NWScriptI::stringToFloat(const std::string& sNumber, const Ice::Current& ice) {
  lock("stringToFloat"); callCounter += 1;
  StackPushString(sNumber.c_str());

  VM_ExecuteCommand(233, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("stringToFloat");
  return fRetVal;
};

Ice::Int NWScriptI::stringToInt(const std::string& sNumber, const Ice::Current& ice) {
  lock("stringToInt"); callCounter += 1;
  StackPushString(sNumber.c_str());

  VM_ExecuteCommand(232, 1);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("stringToInt");
  return nRetVal;
};

void NWScriptI::summonAnimalCompanion(const NWN::NWObject& oMaster, const Ice::Current& ice) {
  lock("summonAnimalCompanion"); callCounter += 1;
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(334, 1);

unlock("summonAnimalCompanion");
  
};

void NWScriptI::summonFamiliar(const NWN::NWObject& oMaster, const Ice::Current& ice) {
  lock("summonFamiliar"); callCounter += 1;
  StackPushObject(oMaster.id);

  VM_ExecuteCommand(335, 1);

unlock("summonFamiliar");
  
};

NWN::NWEffect NWScriptI::supernaturalEffect(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("supernaturalEffect"); callCounter += 1;
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
  unlock("supernaturalEffect");
  return e;
};

void NWScriptI::surrenderToEnemies(const Ice::Current& ice) {
  lock("surrenderToEnemies"); callCounter += 1;

  VM_ExecuteCommand(476, 0);

unlock("surrenderToEnemies");
  
};

void NWScriptI::takeGoldFromCreature(Ice::Int nAmount, const NWN::NWObject& oCreatureToTakeFrom, bool bDestroy, const Ice::Current& ice) {
  lock("takeGoldFromCreature"); callCounter += 1;
  StackPushInteger(bDestroy == true ? 1 : 0);
  StackPushObject(oCreatureToTakeFrom.id);
  StackPushInteger(nAmount);

  VM_ExecuteCommand(444, 3);

unlock("takeGoldFromCreature");
  
};

Ice::Double NWScriptI::tan(Ice::Double fValue, const Ice::Current& ice) {
  lock("tan"); callCounter += 1;
  StackPushFloat(fValue);

  VM_ExecuteCommand(70, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("tan");
  return fRetVal;
};

Ice::Int NWScriptI::testStringAgainstPattern(const std::string& sPattern, const std::string& sStringToTest, const Ice::Current& ice) {
  lock("testStringAgainstPattern"); callCounter += 1;
  StackPushString(sStringToTest.c_str());
  StackPushString(sPattern.c_str());

  VM_ExecuteCommand(177, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("testStringAgainstPattern");
  return nRetVal;
};

NWN::AttackResult NWScriptI::touchAttackMelee(const NWN::NWObject& oTarget, bool bDisplayFeedback, const Ice::Current& ice) {
  lock("touchAttackMelee"); callCounter += 1;
  StackPushInteger(bDisplayFeedback == true ? 1 : 0);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(146, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("touchAttackMelee");
  if (nRetVal == 0) return NWN::MissedAttack;
  if (nRetVal == 1) return NWN::HitAttack;
  if (nRetVal == 2) return NWN::CriticalHitAttack;
  throw "Error: Unmapped enum return type";
};

NWN::AttackResult NWScriptI::touchAttackRanged(const NWN::NWObject& oTarget, bool bDisplayFeedback, const Ice::Current& ice) {
  lock("touchAttackRanged"); callCounter += 1;
  StackPushInteger(bDisplayFeedback == true ? 1 : 0);
  StackPushObject(oTarget.id);

  VM_ExecuteCommand(147, 2);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("touchAttackRanged");
  if (nRetVal == 0) return NWN::MissedAttack;
  if (nRetVal == 1) return NWN::HitAttack;
  if (nRetVal == 2) return NWN::CriticalHitAttack;
  throw "Error: Unmapped enum return type";
};

Ice::Double NWScriptI::turnsToSeconds(Ice::Int nTurns, const Ice::Current& ice) {
  lock("turnsToSeconds"); callCounter += 1;
  StackPushInteger(nTurns);

  VM_ExecuteCommand(123, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("turnsToSeconds");
  return fRetVal;
};

void NWScriptI::unpossessFamiliar(const NWN::NWObject& oCreature, const Ice::Current& ice) {
  lock("unpossessFamiliar"); callCounter += 1;
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(715, 1);

unlock("unpossessFamiliar");
  
};

NWN::NWVector NWScriptI::vector(Ice::Double x, Ice::Double y, Ice::Double z, const Ice::Current& ice) {
  lock("vector"); callCounter += 1;
  StackPushFloat(z);
  StackPushFloat(y);
  StackPushFloat(x);

  VM_ExecuteCommand(142, 3);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock("vector");
  return nv;
};

Ice::Double NWScriptI::vectorMagnitude(const NWN::NWVector& vVector, const Ice::Current& ice) {
  lock("vectorMagnitude"); callCounter += 1;
  Vector vvVector;
  vvVector.X = vVector.x; vvVector.Y = vVector.y; vvVector.Z = vVector.z;
  StackPushVector(vvVector);

  VM_ExecuteCommand(104, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("vectorMagnitude");
  return fRetVal;
};

NWN::NWVector NWScriptI::vectorNormalize(const NWN::NWVector& vVector, const Ice::Current& ice) {
  lock("vectorNormalize"); callCounter += 1;
  Vector vvVector;
  vvVector.X = vVector.x; vvVector.Y = vVector.y; vvVector.Z = vVector.z;
  StackPushVector(vvVector);

  VM_ExecuteCommand(137, 1);

  Vector vRetVal;
  StackPopVector(&vRetVal);
  NWN::NWVector nv;
  nv.x = vRetVal.X; nv.y = vRetVal.Y; nv.z = vRetVal.Z;
  unlock("vectorNormalize");
  return nv;
};

Ice::Double NWScriptI::vectorToAngle(const NWN::NWVector& vVector, const Ice::Current& ice) {
  lock("vectorToAngle"); callCounter += 1;
  Vector vvVector;
  vvVector.X = vVector.x; vvVector.Y = vVector.y; vvVector.Z = vVector.z;
  StackPushVector(vvVector);

  VM_ExecuteCommand(145, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("vectorToAngle");
  return fRetVal;
};

NWN::NWEffect NWScriptI::versusAlignmentEffect(const NWN::NWEffect& eEffect, Ice::Int nLawChaos, Ice::Int nGoodEvil, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("versusAlignmentEffect"); callCounter += 1;
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
  unlock("versusAlignmentEffect");
  return e;
};

NWN::NWEffect NWScriptI::versusRacialTypeEffect(const NWN::NWEffect& eEffect, NWN::RacialType tRacialType, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("versusRacialTypeEffect"); callCounter += 1;
  if (tRacialType == NWN::ElementalRace) StackPushInteger(16);
   else if (tRacialType == NWN::HalforcRace) StackPushInteger(5);
   else if (tRacialType == NWN::DragonRace) StackPushInteger(11);
   else if (tRacialType == NWN::DwarfRace) StackPushInteger(0);
   else if (tRacialType == NWN::InvalidRace) StackPushInteger(28);
   else if (tRacialType == NWN::FeyRace) StackPushInteger(17);
   else if (tRacialType == NWN::HumanRace) StackPushInteger(6);
   else if (tRacialType == NWN::ShapechangerRace) StackPushInteger(23);
   else if (tRacialType == NWN::HumanoidGoblinoidRace) StackPushInteger(12);
   else if (tRacialType == NWN::ElfRace) StackPushInteger(1);
   else if (tRacialType == NWN::OozeRace) StackPushInteger(29);
   else if (tRacialType == NWN::GiantRace) StackPushInteger(18);
   else if (tRacialType == NWN::AberrationRace) StackPushInteger(7);
   else if (tRacialType == NWN::UndeadRace) StackPushInteger(24);
   else if (tRacialType == NWN::HumanoidMonstrousRace) StackPushInteger(13);
   else if (tRacialType == NWN::GnomeRace) StackPushInteger(2);
   else if (tRacialType == NWN::MagicalBeastRace) StackPushInteger(19);
   else if (tRacialType == NWN::AnimalRace) StackPushInteger(8);
   else if (tRacialType == NWN::VerminRace) StackPushInteger(25);
   else if (tRacialType == NWN::HumanoidOrcRace) StackPushInteger(14);
   else if (tRacialType == NWN::HalflingRace) StackPushInteger(3);
   else if (tRacialType == NWN::OutsiderRace) StackPushInteger(20);
   else if (tRacialType == NWN::BeastRace) StackPushInteger(9);
   else if (tRacialType == NWN::HumanoidReptilianRace) StackPushInteger(15);
   else if (tRacialType == NWN::HalfelfRace) StackPushInteger(4);
   else if (tRacialType == NWN::ConstructRace) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
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
  unlock("versusRacialTypeEffect");
  return e;
};

NWN::NWEffect NWScriptI::versusTrapEffect(const NWN::NWEffect& eEffect, const Ice::Current& ice) {
if (effectMap.find(eEffect.id) == effectMap.end()) throw NWN::InvalidEffectException();
  
  lock("versusTrapEffect"); callCounter += 1;
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
  unlock("versusTrapEffect");
  return e;
};

NWN::SavingThrowResult NWScriptI::willSave(const NWN::NWObject& oCreature, Ice::Int nDC, NWN::SaveType tSaveType, const NWN::NWObject& oSaveVersus, const Ice::Current& ice) {
  lock("willSave"); callCounter += 1;
  StackPushObject(oSaveVersus.id);
  if (tSaveType == NWN::GoodSaveType) StackPushInteger(16);
   else if (tSaveType == NWN::SonicSaveType) StackPushInteger(5);
   else if (tSaveType == NWN::DeathSaveType) StackPushInteger(11);
   else if (tSaveType == NWN::AllOrNoneSaveType) StackPushInteger(0);
   else if (tSaveType == NWN::EvilSaveType) StackPushInteger(17);
   else if (tSaveType == NWN::AcidSaveType) StackPushInteger(6);
   else if (tSaveType == NWN::ColdSaveType) StackPushInteger(12);
   else if (tSaveType == NWN::MindSpellsSaveType) StackPushInteger(1);
   else if (tSaveType == NWN::LawSaveType) StackPushInteger(18);
   else if (tSaveType == NWN::FireSaveType) StackPushInteger(7);
   else if (tSaveType == NWN::DivineSaveType) StackPushInteger(13);
   else if (tSaveType == NWN::PoisonSaveType) StackPushInteger(2);
   else if (tSaveType == NWN::ChaosSaveType) StackPushInteger(19);
   else if (tSaveType == NWN::ElectricitySaveType) StackPushInteger(8);
   else if (tSaveType == NWN::TrapSaveType) StackPushInteger(14);
   else if (tSaveType == NWN::DiseaseSaveType) StackPushInteger(3);
   else if (tSaveType == NWN::PositiveSaveType) StackPushInteger(9);
   else if (tSaveType == NWN::SpellSaveType) StackPushInteger(15);
   else if (tSaveType == NWN::FearSaveType) StackPushInteger(4);
   else if (tSaveType == NWN::NegativeSaveType) StackPushInteger(10);
   else throw "fail: invalid struct value passed, internal API error";
  StackPushInteger(nDC);
  StackPushObject(oCreature.id);

  VM_ExecuteCommand(110, 4);

  int nRetVal;
  StackPopInteger(&nRetVal);
  unlock("willSave");
  if (nRetVal == 0) return NWN::FailedRoll;
  if (nRetVal == 1) return NWN::SucceededRoll;
  if (nRetVal == 3) return NWN::ImmuneToSaveType;
  throw "Error: Unmapped enum return type";
};

void NWScriptI::writeTimestampedLogEntry(const std::string& sLogEntry, const Ice::Current& ice) {
  lock("writeTimestampedLogEntry"); callCounter += 1;
  StackPushString(sLogEntry.c_str());

  VM_ExecuteCommand(560, 1);

unlock("writeTimestampedLogEntry");
  
};

Ice::Double NWScriptI::yardsToMeters(Ice::Double fYards, const Ice::Current& ice) {
  lock("yardsToMeters"); callCounter += 1;
  StackPushFloat(fYards);

  VM_ExecuteCommand(219, 1);

  float fRetVal;
  StackPopFloat(&fRetVal);
  unlock("yardsToMeters");
  return fRetVal;
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


NWN::NWObjectSeq NWScriptI::allInShape(NWN::ShapeType shape, Ice::Double size,
    const NWN::NWLocation& location, bool lineOfSight, NWN::ObjectType objType,
    const NWN::NWVector& origin, const Ice::Current& ice) {
  NWN::NWObjectSeq p;
  innerLock("allInShape");
  NWN::NWObject o = getFirstObjectInShape(shape, size, location, lineOfSight,
    objType, origin, ice);
  while (getIsObjectValid(o, ice)) {
    p.push_back(o);
    o = getNextObjectInShape(shape, size, location, lineOfSight, objType, origin, ice);
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
