// Generated on Sun Aug 30 12:51:48 +0200 2009 from /home/elven/code/nwnx2-linux/trunk/plugins/ice/build/funcs.nss

// Not exported:
//   getFirstEffect getFirstFactionMember getFirstItemInInventory getFirstItemProperty getFirstInPersistentObject getFirstObjectInArea getFirstObjectInShape getFirstPC
//   getNextEffect getNextFactionMember getNextInPersistentObject getNextItemInInventory getNextItemProperty getNextObjectInArea getNextObjectInShape getNextPC
//   abs acos asin atan cos fabs log pow
//   random sin sqrt tan d2 d3 d4 d6
//   d8 d10 d12 d20 d100 yardsToMeters feetToMeters getSubString
//   getStringUpperCase getStringRight getStringLowerCase getStringLength getStringLeft findSubString insertString testStringAgainstPattern
//   intToHexString intToString intToFloat floatToString floatToInt stringToFloat stringToInt printFloat
//   printInteger printObject printString printVector objectToString getFacingFromLocation getAreaFromLocation getPositionFromLocation
//   spawnScriptDebugger location vector

module NWN {
  enum EffectType { InvalidEffect, DamageResistanceEffect, RegenerateEffect, DamageReductionEffect, TemporaryHitpointsEffect, EntangleEffect, InvulnerableEffect, DeafEffect, ResurrectionEffect, ImmunityEffect, EnemyAttackBonusEffect, ArcaneSpellFailureEffect, AreaOfEffectEffect, BeamEffect, CharmedEffect, ConfusedEffect, FrightenedEffect, DominatedEffect, ParalyzeEffect, DazedEffect, StunnedEffect, SleepEffect, PoisonEffect, DiseaseEffect, CurseEffect, SilenceEffect, TurnedEffect, HasteEffect, SlowEffect, AbilityIncreaseEffect, AbilityDecreaseEffect, AttackIncreaseEffect, AttackDecreaseEffect, DamageIncreaseEffect, DamageDecreaseEffect, DamageImmunityIncreaseEffect, DamageImmunityDecreaseEffect, ACIncreaseEffect, ACDecreaseEffect, MovementSpeedIncreaseEffect, MovementSpeedDecreaseEffect, SavingThrowIncreaseEffect, SavingThrowDecreaseEffect, SpellResistanceIncreaseEffect, SpellResistanceDecreaseEffect, SkillIncreaseEffect, SkillDecreaseEffect, InvisibilityEffect, ImprovedInvisibilityEffect, DarknessEffect, DispelMagicAllEffect, ElementalShieldEffect, NegativeLevelEffect, PolymorphEffect, SanctuaryEffect, TrueSeeingEffect, SeeInvisibleEffect, TimestopEffect, BlindnessEffect, SpellLevelAbsorptionEffect, DispelMagicBestEffect, UltravisionEffect, MissChanceEffect, ConcealmentEffect, SpellImmunityEffect, VisualEffect, DisappearAppearEffect, SwarmEffect, TurnResistanceDecreaseEffect, TurnResistanceIncreaseEffect, PetrifyEffect, CutsceneParalyzeEffect, EtherealEffect, SpellFailureEffect, CutsceneGhostEffect, CutsceneImmobilizeEffect };
  enum Weather { InvalidWeather, ClearWeather, RainWeather, SnowWeather, AreaDefaultsWeather };
  enum TileSourceLightColor { BlackTileSourceLightColor, WhiteTileSourceLightColor, PaleDarkYellowTileSourceLightColor, PaleYellowTileSourceLightColor, PaleDarkGreenTileSourceLightColor, PaleGreenTileSourceLightColor, PaleDarkAquaTileSourceLightColor, PaleAquaTileSourceLightColor, PaleDarkBlueTileSourceLightColor, PaleBlueTileSourceLightColor, PaleDarkPurpleTileSourceLightColor, PalePurpleTileSourceLightColor, PaleDarkRedTileSourceLightColor, PaleRedTileSourceLightColor, PaleDarkOrangeTileSourceLightColor, PaleOrangeTileSourceLightColor };
  enum StandardFaction { Hostile, Commoner, Merchant, Defender };
  enum SavingThrowResult { FailedRoll, SucceededRoll, ImmuneToSaveType };
  enum Action { MoveToPointAction, PickupItemAction, DropItemAction, AttackObjectAction, CastSpellAction, OpenDoorAction, CloseDoorAction, DialogObjectAction, DisableTrapAction, RecoverTrapAction, FlagTrapAction, ExamineTrapAction, SetTrapAction, OpenLockAction, LockAction, UseObjectAction, AnimalEmpathyAction, RestAction, TauntAction, ItemCastSpellAction, CounterSpellAction, HealAction, PickpocketAction, FollowAction, SitAction, SmiteGoodAction, KIDamageAction, RandomWalkAction, InvalidAction };
  enum ACModifyType { ACDodgeBonus, ACNaturalBonus, ACArmorEnchantmentBonus, ACShieldEnchantmentBonus, ACDeflectionBonus };
  enum Gender { MaleGender, Female, BothGender, OtherGender, NoneGender };
  enum IPRacialType { DwarfIPRace, ElfIPRace, GnomeIPRace, HalflingIPRace, HalfelfIPRace, HalforcIPRace, HumanIPRace, AberrationIPRace, AnimalIPRace, BeastIPRace, ConstructIPRace, DragonIPRace, HumanoidGoblinoidIPRace, HumanoidMonstrousIPRace, HumanoidOrcIPRace, HumanoidReptilianIPRace, ElementalIPRace, FeyIPRace, GiantIPRace, MagicalBeastIPRace, OutsiderIPRace, ShapechangerIPRace, UndeadIPRace, VerminIPRace };
  enum PlaceableAction { UsePlaceable, UnlockPlaceable, BashPlaceable, KnockPlaceable };
  enum Ability { Strength, Dexterity, Constitution, Intelligence, Wisdom, Charisma };
  enum IPSpellSchool { AbjurationIPSchool, ConjurationIPSchool, DivinationIPSchool, EnchantmentIPSchool, EvocationIPSchool, IllusionIPSchool, NecromancyIPSchool, TransmutationIPSchool };
  enum IPAlignGroup { AllAlignGroup, NeutralAlignGroup, LawfulAlignGroup, ChaoticAlignGroup, GoodAlignGroup, EvilAlignGroup };
  enum EffectSubType { InvalidSubType, MagicalSubType, SupernaturalSubType, ExtraordinarySubType };
  enum TileMainLightColor { BlackTileMainLightColor, DimWhiteTileMainLightColor, WhiteTileMainLightColor, BrightWhiteTileMainLightColor, PaleDarkYellowTileMainLightColor, DarkYellowTileMainLightColor, PaleYellowTileMainLightColor, YellowTileMainLightColor, PaleDarkGreenTileMainLightColor, DarkGreenTileMainLightColor, PaleGreenTileMainLightColor, GreenTileMainLightColor, PaleDarkAquaTileMainLightColor, DarkAquaTileMainLightColor, PaleAquaTileMainLightColor, AquaTileMainLightColor, PaleDarkBlueTileMainLightColor, DarkBlueTileMainLightColor, PaleBlueTileMainLightColor, BlueTileMainLightColor, PaleDarkPurpleTileMainLightColor, DarkPurpleTileMainLightColor, PalePurpleTileMainLightColor, PurpleTileMainLightColor, PaleDarkRedTileMainLightColor, DarkRedTileMainLightColor, PaleRedTileMainLightColor, RedTileMainLightColor, PaleDarkOrangeTileMainLightColor, DarkOrangeTileMainLightColor, PaleOrangeTileMainLightColor, OrangeTileMainLightColor };
  enum DamagePower { NormalDamage, PlusOneDamage, PlusTwoDamage, PlusThreeDamage, PlusFourDamage, PlusFiveDamage, EnergyDamage, PlusSixDamage, PlusSevenDamage, PlusEightDamage, PlusNineDamage, PlusTenDamage, PlusElevenDamage, PlusTwelveDamage, PlusThirteenDamage, PlusFourteenDamage, PlusFifteenDamage, PlusSixteenDamage, PlusSeventeenDamage, PlusEighteenDamage, PlusNinteenDamage, PlusTwentyDamage };
  enum DamageType { BludgeoningDamage, PiercingDamage, SlashingDamage, MagicalDamage, AcidDamage, ColdDamage, DivineDamage, ElectricalDamage, FireDamage, NegativeDamage, PositiveDamage, SonicDamage, BaseDamage, ACVsAllDamage };
  enum SaveType { AllOrNoneSaveType, MindSpellsSaveType, PoisonSaveType, DiseaseSaveType, FearSaveType, SonicSaveType, AcidSaveType, FireSaveType, ElectricitySaveType, PositiveSaveType, NegativeSaveType, DeathSaveType, ColdSaveType, DivineSaveType, TrapSaveType, SpellSaveType, GoodSaveType, EvilSaveType, LawSaveType, ChaosSaveType };
  enum CombatMode { InvalidCombatMode, ParryCombatMode, PowerAttackCombatMode, ImprovedPowerAttackCombatMode, FlurryOfBlowsCombatMode, RapidShotCombatMode, ExpertiseCombatMode, ImprovedExpertiseCombatMode, DefensiveCastingCombatMode, DirtyFightingCombatMode, DefensiveStanceCombatMode };
  enum IPTrapType { SpikeIPTrap, HolyIPTrap, TangleIPTrap, BlobOfAcidIPTrap, FireIPTrap, ElectricalIPTrap, GasIPTrap, FrostIPTrap, AcidSplashIPTrap, SonicIPTrap, NegativeIPTrap };
  enum CreatureSize { InvalidSize, TinySize, SmallSize, MediumSize, LargeSize, HugeSize };
  enum AssociateCommand { ToggleSearchCommand, ToggleStealthCommand, ToggleCastingCommand, DisarmTrapCommand, InventoryCommand, PickLockCommand, LeavePartyCommand, MasterGoingToBeAttackedCommand, MasterAttackedOtherCommand, MasterSawTrapCommand, UnpossessFamiliarCommand, ReleaseDominationCommand, MasterUnderAttackCommand, UnsummonSummonedCommand, UnsummonAnimalCompanionCommand, UnsummonFamiliarCommand, GuardMasterCommand, MasterFailedLockpickCommand, FollowMasterCommand, HealMasterCommand, AttackNearestCommand, StandGroundCommand };
  enum ObjectType { InvalidObject, Creature, Item, Trigger, Door, AOE, Waypoint, Placeable, Store, Encounter, All };
  enum DurationType { Instant, Temporary, Permanent };
  enum ActionMode { DetectMode, StealthMode, ParryMode, PowerAttackMode, ImprovedPowerAttackMode, CounterspellMode, FlurryOfBlowsMode, RapidShotMode, ExpertiseMode, ImprovedExpertiseMode, DefensiveCastMode, DirtyFightingMode };
  enum Alignment { Any, Neutral, Lawful, Chaotic, Good, Evil };
  enum TrapType { MinorSpikeTrap, AverageSpikeTrap, StrongSpikeTrap, DeadlySpikeTrap, MinorHolyTrap, AverageHolyTrap, StrongHolyTrap, DeadlyHolyTrap, MinorTangleTrap, AverageTangleTrap, StrongTangleTrap, DeadlyTangleTrap, MinorAcidTrap, AverageAcidTrap, StrongAcidTrap, DeadlyAcidTrap, MinorFireTrap, AverageFireTrap, StrongFireTrap, DeadlyFireTrap, MinorElectricalTrap, AverageElectricalTrap, StrongElectricalTrap, DeadlyElectricalTrap, MinorGasTrap, AverageGasTrap, StrongGasTrap, DeadlyGasTrap, MinorFrostTrap, AverageFrostTrap, StrongFrostTrap, DeadlyFrostTrap, MinorNegativeTrap, AverageNegativeTrap, StrongNegativeTrap, DeadlyNegativeTrap, MinorSonicTrap, AverageSonicTrap, StrongSonicTrap, DeadlySonicTrap, MinorAcidSplashTrap, AverageAcidSplashTrap, StrongAcidSplashTrap, DeadlyAcidSplashTrap, EpicElectricalTrap, EpicFireTrap, EpicFrostTrap, EpicSonicTrap };
  enum AttackBonus { MiscBonus, OnhandBonus, OffhandBonus };
  enum IPMiscImmunityType { BackstabIPImmunity, LevelAbilDrainIPImmunity, MindSpellsIPImmunity, PoisonIPImmunity, DiseaseIPImmunity, FearIPImmunity, KnockdownIPImmunity, ParalysisIPImmunity, CriticalHitsIPImmunity, DeathMagicIPImmunity };
  enum RacialType { DwarfRace, ElfRace, GnomeRace, HalflingRace, HalfelfRace, HalforcRace, HumanRace, AberrationRace, AnimalRace, BeastRace, ConstructRace, DragonRace, HumanoidGoblinoidRace, HumanoidMonstrousRace, HumanoidOrcRace, HumanoidReptilianRace, ElementalRace, FeyRace, GiantRace, MagicalBeastRace, OutsiderRace, ShapechangerRace, UndeadRace, VerminRace, InvalidRace, OozeRace };
  enum TalkVolume { TalkVol, WhisperVol, ShoutVol, SilentTalkVol, SilentShoutVol, PartyVol, TellVol };
  enum AssociateType { NoAssociate, HenchmanAssociate, AnimalCompanionAssociate, FamiliarAssociate, SummonedAssociate, DominatedAssociate };
  enum IPAlignment { LgAlignment, LnAlignment, LeAlignment, NgAlignment, TnAlignment, NeAlignment, CgAlignment, CnAlignment, CeAlignment };
  enum Button { MapButton, InventoryButton, JournalButton, CharacterButton, OptionsButton, SpellsButton, RestButton, PvPButton };
  enum SpecialAttack { InvalidSpecialAttack, CalledShotLegSpecialAttack, CalledShotArmSpecialAttack, SapSpecialAttack, DisarmSpecialAttack, ImprovedDisarmSpecialAttack, KnockdownSpecialAttack, ImprovedKnockdownSpecialAttack, StunningFistSpecialAttack, FlurryOfBlowsSpecialAttack, RapidShotSpecialAttack };
  enum IPDamageType { BludgeoningIPDamage, PiercingIPDamage, SlashingIPDamage, SubdualIPDamage, PhysicalIPDamage, MagicalIPDamage, AcidIPDamage, ColdIPDamage, DivineIPDamage, ElectricalIPDamage, FireIPDamage, NegativeIPDamage, PositiveIPDamage, SonicIPDamage };
  enum PhenoType { NormalPhenoType, BigPhenoType, Custom1PhenoType, Custom2PhenoType, Custom3PhenoType, Custom4PhenoType, Custom5PhenoType, Custom6PhenoType, Custom7PhenoType, Custom8PhenoType, Custom9PhenoType, Custom10PhenoType, Custom11PhenoType, Custom12PhenoType, Custom13PhenoType, Custom14PhenoType, Custom15PhenoType, Custom16PhenoType, Custom17PhenoType, Custom18PhenoType };
  enum InventorySlot { HeadSlot, ChestSlot, BootsSlot, ArmsSlot, RighthandSlot, LefthandSlot, CloakSlot, LeftringSlot, RightringSlot, NeckSlot, BeltSlot, ArrowsSlot, BulletsSlot, BoltsSlot, CreatureLefthandSlot, CreatureRighthandSlot, CreatureBiteSlot, CreatureArmorSlot };
  enum DoorAction { OpenDoor, UnlockDoor, BashDoor, IgnoreDoor, KnockDoor };
  enum ProjectilePathType { DefaultPath, HomingPath, BallisticPath, HighBallisticPath, AcceleratingPath };
  enum AILevel { DefaultAI, VeryLowAI, LowAI, NormalAI, HighAI, VeryHighAI };
  enum ShapeType { SpellCylinderShape, ConeShape, CubeShape, SpellConeShape, SphereShape };
  enum AttackResult { MissedAttack, HitAttack, CriticalHitAttack };
  enum CreaturePart { RightFootPart, LeftFootPart, RightShinPart, LeftShinPart, LeftThighPart, RightThighPart, PelvisPart, TorsoPart, BeltPart, NeckPart, RightForearmPart, LeftForearmPart, RightBicepPart, LeftBicepPart, RightShoulderPart, LeftShoulderPart, RightHandPart, LeftHandPart, HeadPart };
  enum MetaMagic { NoneMeta, EmpowerMeta, ExtendMeta, MaximizeMeta, QuickenMeta, SilentMeta, StillMeta, AnyMeta };
  enum SpellSchool { GeneralSchool, AbjurationSchool, ConjurationSchool, DivinationSchool, EnchantmentSchool, EvocationSchool, IllusionSchool, NecromancySchool, TransmutationSchool };
  enum MissChanceType { MissChanceVSAll, MissChanceVSRanged, MissChanceVSMelee };
  enum ImmunityType { NoneImmunity, MindSpellsImmunity, PoisonImmunity, DiseaseImmunity, FearImmunity, TrapImmunity, ParalysisImmunity, BlindnessImmunity, DeafnessImmunity, SlowImmunity, EntangleImmunity, SilenceImmunity, StunImmunity, SleepImmunity, CharmImmunity, DominateImmunity, ConfusedImmunity, CursedImmunity, DazedImmunity, AbilityDecreaseImmunity, AttackDecreaseImmunity, DamageDecreaseImmunity, DamageImmunityDecreaseImmunity, AcDecreaseImmunity, MovementSpeedDecreaseImmunity, SavingThrowDecreaseImmunity, SpellResistanceDecreaseImmunity, SkillDecreaseImmunity, KnockdownImmunity, NegativeLevelImmunity, SneakAttackImmunity, CriticalHitImmunity, DeathImmunity };

  sequence<int> IntSeq;

  /**
    Will be raised to you when you're trying to call
    a NWScript function outside of NWScript context.
    Only ever call NWScript functions while you have
    event context (e.g., you're inside event(...))
  **/
  exception NotInContextException {};

  /**
    You can serialize arbitary java objects into a
    server-side cache. This is useful for keeping
    around state between client restarts that is
    not on stored NWN local vars.
    Really untested.
  **/
  ["java:serializable:NWN.Persistable"]
  sequence<byte> Persistable;
  exception StateNotAvailableException {};

  exception InvalidObjectException {};
  exception InvalidEffectException {};
  exception InvalidItemPropertyException {};

  /**
    id is equivalent to the server-side object ID. As opposed to
    effects and iprps, you can access arbitary object-IDs by simply
    passing in the requested ID (for example, 0 for module).
  **/
  struct NWObject {
    long id;
  };
  sequence<NWObject> NWObjectSeq;

  /**
    A vector, pretty much like the NWN engine structure.
    Should be idempotent and non-mutable.
  **/
  struct NWVector {
    double x;
    double y;
    double z;
  };

  /**
    A location, just like the engine structure.
  **/
  struct NWLocation {
    NWObject area;
    double x;
    double y;
    double z;
    double orientationX;
    double orientationY;
    double orientationZ;
  };

  /**
    The struct returned by getAllEquipped(). Should be self-
    explainatory.
  **/
  struct NWCreatureEquipped {
    NWObjectSeq all;

    NWObject HeadSlot;
    NWObject ChestSlot;
    NWObject BootsSlot;
    NWObject ArmsSlot;
    NWObject RighthandSlot;
    NWObject LefthandSlot;
    NWObject CloakSlot;
    NWObject LeftringSlot;
    NWObject RightringSlot;
    NWObject NeckSlot;
    NWObject BeltSlot;
    NWObject ArrowsSlot;
    NWObject BulletsSlot;
    NWObject BoltsSlot;
    NWObject CreatureLefthandSlot;
    NWObject CreatureRighthandSlot;
    NWObject CreatureBiteSlot;
    NWObject CreatureArmorSlot;
  };



  /**
    id refers to a server-side mapping. Note that effects are only valid PER EVENT.
    Do not bother keeping around effect id references
    clientside, they will not be valid on the next round.
    If you pass in a id that has expired, InvalidEffectException
    will be raised to you.

    Any members other than id are read-only and provided so that you do
    not have to place extra calls. They will be ignored when passed in as a
    function call argument.

    Watch out for object equality - the generated struct classes consider
    ALL members.
  **/
  struct NWEffect {
    long id;

    DurationType tDurationType;
    EffectType tType;
    EffectSubType tSubType;
    bool tIconShown;
    NWObject tCreator;

    /*long id;
    long type;
    long durationType;
    long field4;
    long fieldC;
    long expireDay;
    long expireTime;
    long isExposed;
    long field28;
    long linkEffectID;
    long link2;

    long spellId;
    long creatorId;
    long isIconShown; */
  };
  sequence<NWEffect> NWEffectSeq;

  /**
    id refers to a server-side mapping. Note that effects are only valid PER EVENT.
    Do not bother keeping around effect id references
    clientside, they will not be valid on the next round.
    If you pass in a id that has expired, InvalidItemPropertyException
    will be raised to you.

    Any members other than id are read-only and provided so that you do
    not have to place extra calls. They will be ignored when passed in as a
    function call argument.

    Watch out for object equality - the generated struct classes consider
    ALL members.
  **/
  struct NWItemProperty {
    long id;

    DurationType tDurationType;
    int tType;
    int tSubType;
    int tCostTable;
    int tCostTableValue;
    int tParam1;
    int tParam1Value;
  };
  sequence<NWItemProperty> NWItemPropertySeq;


  interface NWScript {

    idempotent bool hasState(string key);
    idempotent Persistable getState(string key) throws StateNotAvailableException;
    idempotent void putState(string key, Persistable state);
    idempotent void delState(string key);
    idempotent void clearState();

    /**
     * Returns a sequence of all players currently online.
     * This simply wraps GetFirst/Next to be idempotent.
     */
    idempotent NWObjectSeq allPCs() throws NotInContextException;

    /**
     * Returns a sequence of all effects on the given object.
     * This simply wraps GetFirst/Next to be idempotent.
     */
    idempotent NWEffectSeq allEffects(NWObject o) throws NotInContextException;

    /**
     * Returns a sequence of all objects in the given area.
     * This simply wraps GetFirst/Next to be idempotent.
     */
    idempotent NWObjectSeq allInArea(NWObject area) throws NotInContextException;

    /**
     * Returns a sequence of all objects with the given tag.
     * This simply wraps GetByTag to be idempotent.
     */
    idempotent NWObjectSeq allByTag(string tag) throws NotInContextException;

    /**
     * Returns a sequence of all items in the given objects' inventory, EXCLUDING equipped.
     * This simply wraps GetFirst/Next to be idempotent.
     */
    idempotent NWObjectSeq allInInventory(NWObject o) throws NotInContextException;

    /**
     * Returns a struct describing the equipped inventory of the given object, EXCLUDING normal inventory pages.
     * This simply wraps GetFirst/Next to be idempotent.
     */
    idempotent NWCreatureEquipped allEquipped(NWObject o) throws NotInContextException;

    /**
     * Returns a sequence of all itempoperties on the given item.
     * This simply wraps GetFirst/Next to be idempotent.
     */
    idempotent NWItemPropertySeq allItemProperties(NWObject item) throws NotInContextException;

    /**
     * Returns a sequence of all objects in the given shape.
     * This simply wraps GetFirst/Next to be idempotent.
     */
    idempotent NWObjectSeq allInShape(ShapeType tShapeType, double fSize,
      NWLocation lTarget, bool bLineOfSight, ObjectType tObjectType, NWVector vOrigin) throws NotInContextException;

    /**
     * Returns a sequence of all members in the given faction source.
     * This simply wraps GetFirst/Next to be idempotent.
     */
    idempotent NWObjectSeq allInFaction(NWObject memberOf, bool bPCOnly) throws NotInContextException;

    /**
     * Returns if the given effect is shown to clients (in the upper right corner and in the character sheet).
     */
    idempotent bool getEffectIconShown(NWEffect eff) throws NotInContextException, InvalidEffectException;

    /**
     * Sets if the given effect should be shown to clients (in the upper right corner and in the character sheet).
     * This will be cached by clients and is probably only reliable when setting BEFORE applying the effect.
     */
    idempotent void setEffectIconShown(NWEffect eff, bool bShown) throws NotInContextException, InvalidEffectException;


    /**<br>
     * Attack oAttackee.<br>
     * - bPassive: If this is TRUE, attack is in passive mode.<br>
    **/
    void actionAttack(NWObject oAttackee, bool bPassive) throws NotInContextException;

    /**<br>
     * The action subject will fake casting a spell at lLocation; the conjure and<br>
     * cast animations and visuals will occur, nothing else.<br>
     * - nSpell<br>
     * - lTarget<br>
     * - nProjectilePathType: PROJECTILE_PATH_TYPE_*<br>
    **/
    void actionCastFakeSpellAtLocation(int nSpell, NWLocation lTarget, ProjectilePathType tProjectilePathType) throws NotInContextException;

    /**<br>
     * The action subject will fake casting a spell at oTarget; the conjure and cast<br>
     * animations and visuals will occur, nothing else.<br>
     * - nSpell<br>
     * - oTarget<br>
     * - nProjectilePathType: PROJECTILE_PATH_TYPE_*<br>
    **/
    void actionCastFakeSpellAtObject(int nSpell, NWObject oTarget, ProjectilePathType tProjectilePathType) throws NotInContextException;

    /**<br>
     * Cast spell nSpell at lTargetLocation.<br>
     * - nSpell: SPELL_*<br>
     * - lTargetLocation<br>
     * - nMetaMagic: METAMAGIC_*<br>
     * - bCheat: If this is TRUE, then the executor of the action doesn't have to be<br>
     * able to cast the spell.<br>
     * - nProjectilePathType: PROJECTILE_PATH_TYPE_*<br>
     * - bInstantSpell: If this is TRUE, the spell is cast immediately; this allows<br>
     * the end-user to simulate<br>
     * a high-level magic user having lots of advance warning of impending trouble.<br>
    **/
    void actionCastSpellAtLocation(int nSpell, NWLocation lTargetLocation, MetaMagic tMetaMagic, bool bCheat, ProjectilePathType tProjectilePathType, bool bInstantSpell) throws NotInContextException;

    /**<br>
     * This action casts a spell at oTarget.<br>
     * - nSpell: SPELL_*<br>
     * - oTarget: Target for the spell<br>
     * - nMetamagic: METAMAGIC_*<br>
     * - bCheat: If this is TRUE, then the executor of the action doesn't have to be<br>
     * able to cast the spell.<br>
     * - nDomainLevel: TBD - SS<br>
     * - nProjectilePathType: PROJECTILE_PATH_TYPE_*<br>
     * - bInstantSpell: If this is TRUE, the spell is cast immediately. This allows<br>
     * the end-user to simulate a high-level magic-user having lots of advance<br>
     * warning of impending trouble<br>
    **/
    void actionCastSpellAtObject(int nSpell, NWObject oTarget, MetaMagic tMetaMagic, bool bCheat, int nDomainLevel, ProjectilePathType tProjectilePathType, bool bInstantSpell) throws NotInContextException;

    /**<br>
     * Cause the action subject to close oDoor<br>
    **/
    void actionCloseDoor(NWObject oDoor) throws NotInContextException;

    /**<br>
     * Counterspell oCounterSpellTarget.<br>
    **/
    void actionCounterSpell(NWObject oCounterSpellTarget) throws NotInContextException;

    /**<br>
     * Equip oItem into nInventorySlot.<br>
     * - nInventorySlot: INVENTORY_SLOT_*<br>
     * * No return value, but if an error occurs the log file will contain<br>
     * "ActionEquipItem failed."<br>
     * <br>
     * Note:<br>
     * If the creature already has an item equipped in the slot specified, it will be<br>
     * unequipped automatically by the call to ActionEquipItem.<br>
     * <br>
     * In order for ActionEquipItem to succeed the creature must be able to equip the<br>
     * item oItem normally. This means that:<br>
     * 1) The item is in the creature's inventory.<br>
     * 2) The item must already be identified (if magical).<br>
     * 3) The creature has the level required to equip the item (if magical and ILR is on).<br>
     * 4) The creature possesses the required feats to equip the item (such as weapon proficiencies).<br>
    **/
    void actionEquipItem(NWObject oItem, InventorySlot tInventorySlot) throws NotInContextException;

    /**<br>
     * The creature will equip the melee weapon in its possession that can do the<br>
     * most damage. If no valid melee weapon is found, it will equip the most<br>
     * damaging range weapon. This function should only ever be called in the<br>
     * EndOfCombatRound scripts, because otherwise it would have to stop the combat<br>
     * round to run simulation.<br>
     * - oVersus: You can try to get the most damaging weapon against oVersus<br>
     * - bOffHand<br>
    **/
    void actionEquipMostDamagingMelee(NWObject oVersus, bool bOffHand) throws NotInContextException;

    /**<br>
     * The creature will equip the range weapon in its possession that can do the<br>
     * most damage.<br>
     * If no valid range weapon can be found, it will equip the most damaging melee<br>
     * weapon.<br>
     * - oVersus: You can try to get the most damaging weapon against oVersus<br>
    **/
    void actionEquipMostDamagingRanged(NWObject oVersus) throws NotInContextException;

    /**<br>
     * The creature will equip the armour in its possession that has the highest<br>
     * armour class.<br>
    **/
    void actionEquipMostEffectiveArmor() throws NotInContextException;

    /**<br>
     * Makes a player examine the object oExamine. This causes the examination<br>
     * pop-up box to appear for the object specified.<br>
    **/
    void actionExamine(NWObject oExamine) throws NotInContextException;

    /**<br>
     * The action subject will follow oFollow until a ClearAllActions() is called.<br>
     * - oFollow: this is the object to be followed<br>
     * - fFollowDistance: follow distance in metres<br>
     * * No return value<br>
    **/
    void actionForceFollowObject(NWObject oFollow, double fFollowDistance) throws NotInContextException;

    /**<br>
     * Force the action subject to move to lDestination.<br>
    **/
    void actionForceMoveToLocation(NWLocation lDestination, bool bRun, double fTimeout) throws NotInContextException;

    /**<br>
     * Force the action subject to move to oMoveTo.<br>
    **/
    void actionForceMoveToObject(NWObject oMoveTo, bool bRun, double fRange, double fTimeout) throws NotInContextException;

    /**<br>
     * Give oItem to oGiveTo<br>
     * If oItem is not a valid item, or oGiveTo is not a valid object, nothing will<br>
     * happen.<br>
    **/
    void actionGiveItem(NWObject oItem, NWObject oGiveTo) throws NotInContextException;

    /**<br>
     * Use oPlaceable.<br>
    **/
    void actionInteractObject(NWObject oPlaceable) throws NotInContextException;

    /**<br>
     * The subject will jump to lLocation instantly (even between areas).<br>
     * If lLocation is invalid, nothing will happen.<br>
    **/
    void actionJumpToLocation(NWLocation lLocation) throws NotInContextException;

    /**<br>
     * Jump to an object ID, or as near to it as possible.<br>
    **/
    void actionJumpToObject(NWObject oToJumpTo, bool bWalkStraightLineToPoint) throws NotInContextException;

    /**<br>
     * The action subject will lock oTarget, which can be a door or a placeable<br>
     * object.<br>
    **/
    void actionLockObject(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Causes the action subject to move away from lMoveAwayFrom.<br>
    **/
    void actionMoveAwayFromLocation(NWLocation lMoveAwayFrom, bool bRun, double fMoveAwayRange) throws NotInContextException;

    /**<br>
     * Cause the action subject to move to a certain distance away from oFleeFrom.<br>
     * - oFleeFrom: This is the object we wish the action subject to move away from.<br>
     * If oFleeFrom is not in the same area as the action subject, nothing will<br>
     * happen.<br>
     * - bRun: If this is TRUE, the action subject will run rather than walk<br>
     * - fMoveAwayRange: This is the distance we wish the action subject to put<br>
     * between themselves and oFleeFrom<br>
     * * No return value, but if an error occurs the log file will contain<br>
     * "ActionMoveAwayFromObject failed."<br>
    **/
    void actionMoveAwayFromObject(NWObject oFleeFrom, bool bRun, double fMoveAwayRange) throws NotInContextException;

    /**<br>
     * The action subject will move to lDestination.<br>
     * - lDestination: The object will move to this location.  If the location is<br>
     * invalid or a path cannot be found to it, the command does nothing.<br>
     * - bRun: If this is TRUE, the action subject will run rather than walk<br>
     * * No return value, but if an error occurs the log file will contain<br>
     * "MoveToPoint failed."<br>
    **/
    void actionMoveToLocation(NWLocation lDestination, bool bRun) throws NotInContextException;

    /**<br>
     * Cause the action subject to move to a certain distance from oMoveTo.<br>
     * If there is no path to oMoveTo, this command will do nothing.<br>
     * - oMoveTo: This is the object we wish the action subject to move to<br>
     * - bRun: If this is TRUE, the action subject will run rather than walk<br>
     * - fRange: This is the desired distance between the action subject and oMoveTo<br>
     * * No return value, but if an error occurs the log file will contain<br>
     * "ActionMoveToObject failed."<br>
    **/
    void actionMoveToObject(NWObject oMoveTo, bool bRun, double fRange) throws NotInContextException;

    /**<br>
     * Cause the action subject to open oDoor<br>
    **/
    void actionOpenDoor(NWObject oDoor) throws NotInContextException;

    /**<br>
     * Pause the current conversation.<br>
    **/
    void actionPauseConversation() throws NotInContextException;

    /**<br>
     * Pick up oItem from the ground.<br>
     * * No return value, but if an error occurs the log file will contain<br>
     * "ActionPickUpItem failed."<br>
    **/
    void actionPickUpItem(NWObject oItem) throws NotInContextException;

    /**<br>
     * Cause the action subject to play an animation<br>
     * - nAnimation: ANIMATION_*<br>
     * - fSpeed: Speed of the animation<br>
     * - fDurationSeconds: Duration of the animation (this is not used for Fire and<br>
     * Forget animations)<br>
    **/
    void actionPlayAnimation(int nAnimation, double fSpeed, double fDurationSeconds) throws NotInContextException;

    /**<br>
     * Put down oItem on the ground.<br>
     * * No return value, but if an error occurs the log file will contain<br>
     * "ActionPutDownItem failed."<br>
    **/
    void actionPutDownItem(NWObject oItem) throws NotInContextException;

    /**<br>
     * The action subject will generate a random location near its current location<br>
     * and pathfind to it.  ActionRandomwalk never ends, which means it is neccessary<br>
     * to call ClearAllActions in order to allow a creature to perform any other action<br>
     * once ActionRandomWalk has been called.<br>
     * * No return value, but if an error occurs the log file will contain<br>
     * "ActionRandomWalk failed."<br>
    **/
    void actionRandomWalk() throws NotInContextException;

    /**<br>
     * The creature will rest if not in combat and no enemies are nearby.<br>
     * - bCreatureToEnemyLineOfSightCheck: TRUE to allow the creature to rest if enemies<br>
     * are nearby, but the creature can't see the enemy.<br>
     * FALSE the creature will not rest if enemies are<br>
     * nearby regardless of whether or not the creature<br>
     * can see them, such as if an enemy is close by,<br>
     * but is in a different room behind a closed door.<br>
    **/
    void actionRest(bool bCreatureToEnemyLineOfSightCheck) throws NotInContextException;

    /**<br>
     * Resume a conversation after it has been paused.<br>
    **/
    void actionResumeConversation() throws NotInContextException;

    /**<br>
     * Sit in oChair.<br>
     * Note: Not all creatures will be able to sit and not all<br>
     * objects can be sat on.<br>
     * The object oChair must also be marked as usable in the toolset.<br>
     * <br>
     * For Example: To get a player to sit in oChair when they click on it,<br>
     * place the following script in the OnUsed event for the object oChair.<br>
     * void main()<br>
     * {<br>
     * object oChair = OBJECT_SELF;<br>
     * AssignCommand(GetLastUsedBy(),ActionSit(oChair));<br>
     * }<br>
    **/
    void actionSit(NWObject oChair) throws NotInContextException;

    /**<br>
     * Add a speak action to the action subject.<br>
     * - sStringToSpeak: String to be spoken<br>
     * - nTalkVolume: TALKVOLUME_*<br>
    **/
    void actionSpeakString(string sStringToSpeak, TalkVolume tTalkVolume) throws NotInContextException;

    /**<br>
     * Causes the creature to speak a translated string.<br>
     * - nStrRef: Reference of the string in the talk table<br>
     * - nTalkVolume: TALKVOLUME_*<br>
    **/
    void actionSpeakStringByStrRef(int nStrRef, TalkVolume tTalkVolume) throws NotInContextException;

    /**<br>
     * Starts a conversation with oObjectToConverseWith - this will cause their<br>
     * OnDialog event to fire.<br>
     * - oObjectToConverseWith<br>
     * - sDialogResRef: If this is blank, the creature's own dialogue file will be used<br>
     * - bPrivateConversation<br>
     * Turn off bPlayHello if you don't want the initial greeting to play<br>
    **/
    void actionStartConversation(NWObject oObjectToConverseWith, string sDialogResRef, bool bPrivateConversation, bool bPlayHello) throws NotInContextException;

    /**<br>
     * Take oItem from oTakeFrom<br>
     * If oItem is not a valid item, or oTakeFrom is not a valid object, nothing<br>
     * will happen.<br>
    **/
    void actionTakeItem(NWObject oItem, NWObject oTakeFrom) throws NotInContextException;

    /**<br>
     * Unequip oItem from whatever slot it is currently in.<br>
    **/
    void actionUnequipItem(NWObject oItem) throws NotInContextException;

    /**<br>
     * The action subject will unlock oTarget, which can be a door or a placeable<br>
     * object.<br>
    **/
    void actionUnlockObject(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Use nFeat on oTarget.<br>
     * - nFeat: FEAT_*<br>
     * - oTarget<br>
    **/
    void actionUseFeat(int nFeat, NWObject oTarget) throws NotInContextException;

    /**<br>
     * Runs the action "UseSkill" on the current creature<br>
     * Use nSkill on oTarget.<br>
     * - nSkill: SKILL_*<br>
     * - oTarget<br>
     * - nSubSkill: SUBSKILL_*<br>
     * - oItemUsed: Item to use in conjunction with the skill<br>
    **/
    void actionUseSkill(int nSkill, NWObject oTarget, int nSubSkill, NWObject oItemUsed) throws NotInContextException;

    /**<br>
     * Do nothing for fSeconds seconds.<br>
    **/
    void actionWait(double fSeconds) throws NotInContextException;

    /**<br>
     * Try to send oTarget to a new server defined by sIPaddress.<br>
     * - oTarget<br>
     * - sIPaddress: this can be numerical "192.168.0.84" or alphanumeric<br>
     * "www.bioware.com". It can also contain a port "192.168.0.84:5121" or<br>
     * "www.bioware.com:5121"; if the port is not specified, it will default to<br>
     * 5121.<br>
     * - sPassword: login password for the destination server<br>
     * - sWaypointTag: if this is set, after portalling the character will be moved<br>
     * to this waypoint if it exists<br>
     * - bSeamless: if this is set, the client wil not be prompted with the<br>
     * information window telling them about the server, and they will not be<br>
     * allowed to save a copy of their character if they are using a local vault<br>
     * character.<br>
    **/
    void activatePortal(NWObject oTarget, string sIPaddress, string sPassword, string sWaypointTag, bool bSeemless) throws NotInContextException;

    /**<br>
     * Add oHenchman as a henchman to oMaster<br>
     * If oHenchman is either a DM or a player character, this will have no effect.<br>
    **/
    void addHenchman(NWObject oMaster, NWObject oHenchman) throws NotInContextException;

    /**<br>
     * ***********************  START OF ITEM PROPERTY FUNCTIONS  **********************<br>
     * <br>
     * adds an item property to the specified item<br>
     * Only temporary and permanent duration types are allowed.<br>
    **/
    void addItemProperty(DurationType tDurationType, NWItemProperty ipProperty, NWObject oItem, double fDuration) throws NotInContextException, InvalidItemPropertyException;

    /**<br>
     * Add a journal quest entry to oCreature.<br>
     * - szPlotID: the plot identifier used in the toolset's Journal Editor<br>
     * - nState: the state of the plot as seen in the toolset's Journal Editor<br>
     * - oCreature<br>
     * - bAllPartyMembers: If this is TRUE, the entry will show up in the journal of<br>
     * everyone in the party<br>
     * - bAllPlayers: If this is TRUE, the entry will show up in the journal of<br>
     * everyone in the world<br>
     * - bAllowOverrideHigher: If this is TRUE, you can set the state to a lower<br>
     * number than the one it is currently on<br>
    **/
    void addJournalQuestEntry(string szPlotID, int nState, NWObject oCreature, bool bAllPartyMembers, bool bAllPlayers, bool bAllowOverrideHigher) throws NotInContextException;

    /**<br>
     * Add oPC to oPartyLeader's party.  This will only work on two PCs.<br>
     * - oPC: player to add to a party<br>
     * - oPartyLeader: player already in the party<br>
    **/
    idempotent void addToParty(NWObject oPC, NWObject oPartyLeader) throws NotInContextException;

    /**<br>
     * Adjust the alignment of oSubject.<br>
     * - oSubject<br>
     * - nAlignment:<br>
     * -> ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_GOOD/ALIGNMENT_EVIL: oSubject's<br>
     * alignment will be shifted in the direction specified<br>
     * -> ALIGNMENT_ALL: nShift will be added to oSubject's law/chaos and<br>
     * good/evil alignment values<br>
     * -> ALIGNMENT_NEUTRAL: nShift is applied to oSubject's law/chaos and<br>
     * good/evil alignment values in the direction which is towards neutrality.<br>
     * e.g. If oSubject has a law/chaos value of 10 (i.e. chaotic) and a<br>
     * good/evil value of 80 (i.e. good) then if nShift is 15, the<br>
     * law/chaos value will become (10+15)=25 and the good/evil value will<br>
     * become (80-25)=55<br>
     * Furthermore, the shift will at most take the alignment value to 50 and<br>
     * not beyond.<br>
     * e.g. If oSubject has a law/chaos value of 40 and a good/evil value of 70,<br>
     * then if nShift is 15, the law/chaos value will become 50 and the<br>
     * good/evil value will become 55<br>
     * - nShift: this is the desired shift in alignment<br>
     * - bAllPartyMembers: when TRUE the alignment shift of oSubject also has a<br>
     * diminished affect all members of oSubject's party (if oSubject is a Player).<br>
     * When FALSE the shift only affects oSubject.<br>
     * * No return value<br>
    **/
    void adjustAlignment(NWObject oSubject, Alignment tAlignment, int nShift, bool bAllPartyMembers) throws NotInContextException;

    /**<br>
     * Adjust how oSourceFactionMember's faction feels about oTarget by the<br>
     * specified amount.<br>
     * Note: This adjusts Faction Reputation, how the entire faction that<br>
     * oSourceFactionMember is in, feels about oTarget.<br>
     * * No return value<br>
     * Note: You can't adjust a player character's (PC) faction towards<br>
     * NPCs, so attempting to make an NPC hostile by passing in a PC object<br>
     * as oSourceFactionMember in the following call will fail:<br>
     * AdjustReputation(oNPC,oPC,-100);<br>
     * Instead you should pass in the PC object as the first<br>
     * parameter as in the following call which should succeed:<br>
     * AdjustReputation(oPC,oNPC,-100);<br>
     * Note: Will fail if oSourceFactionMember is a plot object.<br>
    **/
    void adjustReputation(NWObject oTarget, NWObject oSourceFactionMember, int nAdjustment) throws NotInContextException;

    /**<br>
     * Change the ambient day track for oArea to nTrack.<br>
     * - oArea<br>
     * - nTrack<br>
    **/
    idempotent void ambientSoundChangeDay(NWObject oArea, int nTrack) throws NotInContextException;

    /**<br>
     * Change the ambient night track for oArea to nTrack.<br>
     * - oArea<br>
     * - nTrack<br>
    **/
    idempotent void ambientSoundChangeNight(NWObject oArea, int nTrack) throws NotInContextException;

    /**<br>
     * Play the ambient sound for oArea.<br>
    **/
    idempotent void ambientSoundPlay(NWObject oArea) throws NotInContextException;

    /**<br>
     * Set the ambient day volume for oArea to nVolume.<br>
     * - oArea<br>
     * - nVolume: 0 - 100<br>
    **/
    idempotent void ambientSoundSetDayVolume(NWObject oArea, int nVolume) throws NotInContextException;

    /**<br>
     * Set the ambient night volume for oArea to nVolume.<br>
     * - oArea<br>
     * - nVolume: 0 - 100<br>
    **/
    idempotent void ambientSoundSetNightVolume(NWObject oArea, int nVolume) throws NotInContextException;

    /**<br>
     * Stop the ambient sound for oArea.<br>
    **/
    idempotent void ambientSoundStop(NWObject oArea) throws NotInContextException;

    /**<br>
     * Convert fAngle to a vector<br>
    **/
    idempotent NWVector angleToVector(double fAngle) throws NotInContextException;

    /**<br>
     * Apply eEffect at lLocation.<br>
    **/
    void applyEffectAtLocation(DurationType tDurationType, NWEffect eEffect, NWLocation lLocation, double fDuration) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Apply eEffect to oTarget.<br>
    **/
    void applyEffectToObject(DurationType tDurationType, NWEffect eEffect, NWObject oTarget, double fDuration) throws NotInContextException, InvalidEffectException;

    /**<br>
     * replace this function it does nothing.<br>
    **/
    NWItemProperty badBadReplaceMeThisDoesNothing() throws NotInContextException;

    /**<br>
     * Use this in an OnDialog script to start up the dialog tree.<br>
     * - sResRef: if this is not specified, the default dialog file will be used<br>
     * - oObjectToDialog: if this is not specified the person that triggered the<br>
     * event will be used<br>
    **/
    int beginConversation(string sResRef, NWObject oObjectToDialog) throws NotInContextException;

    /**<br>
     * Sets the screen to black.  Can be used in preparation for a fade-in (FadeFromBlack)<br>
     * Can be cleared by either doing a FadeFromBlack, or by calling StopFade.<br>
     * - oCreature: creature controlled by player that should see black screen<br>
    **/
    void blackScreen(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Remove oPlayer from the server.<br>
    **/
    void bootPC(NWObject oPlayer) throws NotInContextException;

    /**<br>
     * Make oObjectToChangeFaction join the faction of oMemberOfFactionToJoin.<br>
     * NB. ** This will only work for two NPCs **<br>
    **/
    void changeFaction(NWObject oObjectToChangeFaction, NWObject oMemberOfFactionToJoin) throws NotInContextException;

    /**<br>
     * Make oCreatureToChange join one of the standard factions.<br>
     * ** This will only work on an NPC **<br>
     * - nStandardFaction: STANDARD_FACTION_*<br>
    **/
    void changeToStandardFaction(NWObject oCreatureToChange, StandardFaction tStandardFaction) throws NotInContextException;

    /**<br>
     * Clear all the actions of the caller.<br>
     * * No return value, but if an error occurs, the log file will contain<br>
     * "ClearAllActions failed.".<br>
     * - nClearCombatState: if true, this will immediately clear the combat state<br>
     * on a creature, which will stop the combat music and allow them to rest,<br>
     * engage in dialog, or other actions that they would normally have to wait for.<br>
    **/
    void clearAllActions(bool bClearCombatState) throws NotInContextException;

    /**<br>
     * Clear all personal feelings that oSource has about oTarget.<br>
    **/
    void clearPersonalReputation(NWObject oTarget, NWObject oSource) throws NotInContextException;

    /**<br>
     * duplicates the item and returns a new object<br>
     * oItem - item to copy<br>
     * oTargetInventory - create item in this object's inventory. If this parameter<br>
     * is not valid, the item will be created in oItem's location<br>
     * bCopyVars - copy the local variables from the old item to the new one<br>
     * * returns the new item<br>
     * * returns OBJECT_INVALID for non-items.<br>
     * * can only copy empty item containers. will return OBJECT_INVALID if oItem contains<br>
     * other items.<br>
     * * if it is possible to merge this item with any others in the target location,<br>
     * then it will do so and return the merged object.<br>
    **/
    NWObject copyItem(NWObject oItem, NWObject oTargetInventory, bool bCopyVars) throws NotInContextException;

    /**<br>
     * Creates a new copy of an item, while making a single change to the appearance of the item.<br>
     * Helmet models and simple items ignore iIndex.<br>
     * iType                            iIndex                      iNewValue<br>
     * ITEM_APPR_TYPE_SIMPLE_MODEL      [Ignored]                   Model #<br>
     * ITEM_APPR_TYPE_WEAPON_COLOR      ITEM_APPR_WEAPON_COLOR_*    1-4<br>
     * ITEM_APPR_TYPE_WEAPON_MODEL      ITEM_APPR_WEAPON_MODEL_*    Model #<br>
     * ITEM_APPR_TYPE_ARMOR_MODEL       ITEM_APPR_ARMOR_MODEL_*     Model #<br>
     * ITEM_APPR_TYPE_ARMOR_COLOR       ITEM_APPR_ARMOR_COLOR_*     0-175<br>
    **/
    NWObject copyItemAndModify(NWObject oItem, int nType, int nIndex, int nNewValue, bool bCopyVars) throws NotInContextException;

    /**<br>
     * Duplicates the object specified by oSource.<br>
     * ONLY creatures and items can be specified.<br>
     * If an owner is specified and the object is an item, it will be put into their inventory<br>
     * If the object is a creature, they will be created at the location.<br>
     * If a new tag is specified, it will be assigned to the new object.<br>
    **/
    NWObject copyObject(NWObject oSource, NWLocation locLocation, NWObject oOwner, string sNewTag) throws NotInContextException;

    /**<br>
     * Create an item with the template sItemTemplate in oTarget's inventory.<br>
     * - nStackSize: This is the stack size of the item to be created<br>
     * - sNewTag: If this string is not empty, it will replace the default tag from the template<br>
     * * Return value: The object that has been created.  On error, this returns<br>
     * OBJECT_INVALID.<br>
     * If the item created was merged into an existing stack of similar items,<br>
     * the function will return the merged stack object. If the merged stack<br>
     * overflowed, the function will return the overflowed stack that was created.<br>
    **/
    NWObject createItemOnObject(string sItemTemplate, NWObject oTarget, int nStackSize, string sNewTag) throws NotInContextException;

    /**<br>
     * Create an object of the specified type at lLocation.<br>
     * - nObjectType: OBJECT_TYPE_ITEM, OBJECT_TYPE_CREATURE, OBJECT_TYPE_PLACEABLE,<br>
     * OBJECT_TYPE_STORE, OBJECT_TYPE_WAYPOINT<br>
     * - sTemplate<br>
     * - lLocation<br>
     * - bUseAppearAnimation<br>
     * - sNewTag - if this string is not empty, it will replace the default tag from the template<br>
    **/
    NWObject createObject(ObjectType tObjectType, string sTemplate, NWLocation lLocation, bool bUseAppearAnimation, string sNewTag) throws NotInContextException;

    /**<br>
     * Creates a square Trap object.<br>
     * - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)<br>
     * - lLocation: The location and orientation that the trap will be created at.<br>
     * - fSize: The size of the trap. Minimum size allowed is 1.0f.<br>
     * - sTag: The tag of the trap being created.<br>
     * - nFaction: The faction of the trap (STANDARD_FACTION_*).<br>
     * - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.<br>
     * If "" no script will fire.<br>
     * - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the<br>
     * trap is triggered.<br>
     * If "" the default OnTrapTriggered script for the trap<br>
     * type specified will fire instead (as specified in the<br>
     * traps.2da).<br>
    **/
    NWObject createTrapAtLocation(TrapType tTrapType, NWLocation lLocation, double fSize, string sTag, StandardFaction tStandardFaction, string sOnDisarmScript, string sOnTrapTriggeredScript) throws NotInContextException;

    /**<br>
     * Creates a Trap on the object specified.<br>
     * - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)<br>
     * - oObject: The object that the trap will be created on. Works only on Doors and Placeables.<br>
     * - nFaction: The faction of the trap (STANDARD_FACTION_*).<br>
     * - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.<br>
     * If "" no script will fire.<br>
     * - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the<br>
     * trap is triggered.<br>
     * If "" the default OnTrapTriggered script for the trap<br>
     * type specified will fire instead (as specified in the<br>
     * traps.2da).<br>
     * Note: After creating a trap on an object, you can change the trap's properties<br>
     * using the various SetTrap* scripting commands by passing in the object<br>
     * that the trap was created on (i.e. oObject) to any subsequent SetTrap* commands.<br>
    **/
    void createTrapOnObject(TrapType tTrapType, NWObject oObject, StandardFaction tStandardFaction, string sOnDisarmScript, string sOnTrapTriggeredScript) throws NotInContextException;

    /**<br>
     * Changes the current Day/Night cycle for this player to night<br>
     * - oPlayer: which player to change the lighting for<br>
     * - fTransitionTime: how long the transition should take<br>
    **/
    idempotent void dayToNight(NWObject oPlayer, double fTransitionTime) throws NotInContextException;

    /**<br>
     * Decrement the remaining uses per day for this creature by one.<br>
     * - oCreature: creature to modify<br>
     * - nFeat: constant FEAT_*<br>
    **/
    void decrementRemainingFeatUses(NWObject oCreature, int nFeat) throws NotInContextException;

    /**<br>
     * Decrement the remaining uses per day for this creature by one.<br>
     * - oCreature: creature to modify<br>
     * - nSpell: constant SPELL_*<br>
    **/
    void decrementRemainingSpellUses(NWObject oCreature, int nSpell) throws NotInContextException;

    /**<br>
     * This will remove ANY campaign variable. Regardless of type.<br>
     * Note that by normal database standards, deleting does not actually removed the entry from<br>
     * the database, but flags it as deleted. Do not expect the database files to shrink in size<br>
     * from this command. If you want to 'pack' the database, you will have to do it externally<br>
     * from the game.<br>
    **/
    idempotent void deleteCampaignVariable(string sCampaignName, string sVarName, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * Delete oObject's local float variable sVarName<br>
    **/
    idempotent void deleteLocalFloat(NWObject oObject, string sVarName) throws NotInContextException;

    /**<br>
     * Delete oObject's local integer variable sVarName<br>
    **/
    idempotent void deleteLocalInt(NWObject oObject, string sVarName) throws NotInContextException;

    /**<br>
     * Delete oObject's local location variable sVarName<br>
    **/
    idempotent void deleteLocalLocation(NWObject oObject, string sVarName) throws NotInContextException;

    /**<br>
     * Delete oObject's local object variable sVarName<br>
    **/
    idempotent void deleteLocalObject(NWObject oObject, string sVarName) throws NotInContextException;

    /**<br>
     * Delete oObject's local string variable sVarName<br>
    **/
    idempotent void deleteLocalString(NWObject oObject, string sVarName) throws NotInContextException;

    /**<br>
     * This will delete the entire campaign database if it exists.<br>
    **/
    idempotent void destroyCampaignDatabase(string sCampaignName) throws NotInContextException;

    /**<br>
     * Destroy oObject (irrevocably).<br>
     * This will not work on modules and areas.<br>
    **/
    void destroyObject(NWObject oDestroy, double fDelay) throws NotInContextException;

    /**<br>
     * Perform nDoorAction on oTargetDoor.<br>
    **/
    idempotent void doDoorAction(NWObject oTargetDoor, DoorAction tDoorAction) throws NotInContextException;

    /**<br>
     * The caller performs nPlaceableAction on oPlaceable.<br>
     * - oPlaceable<br>
     * - nPlaceableAction: PLACEABLE_ACTION_*<br>
    **/
    idempotent void doPlaceableObjectAction(NWObject oPlaceable, PlaceableAction tPlaceableAction) throws NotInContextException;

    /**<br>
     * Only if we are in a single player game, AutoSave the game.<br>
    **/
    idempotent void doSinglePlayerAutoSave() throws NotInContextException;

    /**<br>
     * Does a single attack on every hostile creature within 10ft. of the attacker<br>
     * and determines damage accordingly.  If the attacker has a ranged weapon<br>
     * equipped, this will have no effect.<br>
     * ** NOTE ** This is meant to be called inside the spell script for whirlwind<br>
     * attack, it is not meant to be used to queue up a new whirlwind attack.  To do<br>
     * that you need to call ActionUseFeat(FEAT_WHIRLWIND_ATTACK, oEnemy)<br>
     * - int bDisplayFeedback: TRUE or FALSE, whether or not feedback should be<br>
     * displayed<br>
     * - int bImproved: If TRUE, the improved version of whirlwind is used<br>
    **/
    idempotent void doWhirlwindAttack(bool bDisplayFeedback, bool bImproved) throws NotInContextException;

    /**<br>
     * Create an AC Decrease effect.<br>
     * - nValue<br>
     * - nModifyType: AC_*<br>
     * - nDamageType: DAMAGE_TYPE_*<br>
     * * Default value for nDamageType should only ever be used in this function prototype.<br>
    **/
    idempotent NWEffect effectACDecrease(int nValue, ACModifyType tACModifyType, DamageType tDamageType) throws NotInContextException;

    /**<br>
     * Create an AC Increase effect<br>
     * - nValue: size of AC increase<br>
     * - nModifyType: AC_*_BONUS<br>
     * - nDamageType: DAMAGE_TYPE_*<br>
     * * Default value for nDamageType should only ever be used in this function prototype.<br>
    **/
    idempotent NWEffect effectACIncrease(int nValue, ACModifyType tACModifyType, DamageType tDamageType) throws NotInContextException;

    /**<br>
     * Create an Ability Decrease effect.<br>
     * - nAbility: ABILITY_*<br>
     * - nModifyBy: This is the amount by which to decrement the ability<br>
    **/
    idempotent NWEffect effectAbilityDecrease(Ability tAbility, int nModifyBy) throws NotInContextException;

    /**<br>
     * Create an Ability Increase effect<br>
     * - bAbilityToIncrease: ABILITY_*<br>
    **/
    idempotent NWEffect effectAbilityIncrease(Ability tAbility, int nModifyBy) throws NotInContextException;

    /**<br>
     * Create an Appear effect to make the object "fly in".<br>
     * - nAnimation determines which appear and disappear animations to use. Most creatures<br>
     * only have animation 1, although a few have 2 (like beholders)<br>
    **/
    idempotent NWEffect effectAppear(int nAnimation) throws NotInContextException;

    /**<br>
     * Create an Area Of Effect effect in the area of the creature it is applied to.<br>
     * If the scripts are not specified, default ones will be used.<br>
    **/
    idempotent NWEffect effectAreaOfEffect(int nAreaEffectId, string sOnEnterScript, string sHeartbeatScript, string sOnExitScript) throws NotInContextException;

    /**<br>
     * Create an Attack Decrease effect.<br>
     * - nPenalty<br>
     * - nModifierType: ATTACK_BONUS_*<br>
    **/
    idempotent NWEffect effectAttackDecrease(int nPenalty, AttackBonus tAttackBonus) throws NotInContextException;

    /**<br>
     * Create an Attack Increase effect<br>
     * - nBonus: size of attack bonus<br>
     * - nModifierType: ATTACK_BONUS_*<br>
    **/
    idempotent NWEffect effectAttackIncrease(int nBonus, AttackBonus tAttackBonus) throws NotInContextException;

    /**<br>
     * Create a Beam effect.<br>
     * - nBeamVisualEffect: VFX_BEAM_*<br>
     * - oEffector: the beam is emitted from this creature<br>
     * - nBodyPart: BODY_NODE_*<br>
     * - bMissEffect: If this is TRUE, the beam will fire to a random vector near or<br>
     * past the target<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nBeamVisualEffect is<br>
     * not valid.<br>
    **/
    idempotent NWEffect effectBeam(int nBeamVisualEffect, NWObject oEffector, CreaturePart tCreaturePart, bool bMissEffect) throws NotInContextException;

    /**<br>
     * Create a Blindness effect.<br>
    **/
    idempotent NWEffect effectBlindness() throws NotInContextException;

    /**<br>
     * Create a Charm effect<br>
    **/
    idempotent NWEffect effectCharmed() throws NotInContextException;

    /**<br>
     * Create a Concealment effect.<br>
     * - nPercentage: 1-100 inclusive<br>
     * - nMissChanceType: MISS_CHANCE_TYPE_*<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or<br>
     * nPercentage > 100.<br>
    **/
    idempotent NWEffect effectConcealment(int nPercentage, MissChanceType tMissChanceType) throws NotInContextException;

    /**<br>
     * Create a Confuse effect<br>
    **/
    idempotent NWEffect effectConfused() throws NotInContextException;

    /**<br>
     * Create a Curse effect.<br>
     * - nStrMod: strength modifier<br>
     * - nDexMod: dexterity modifier<br>
     * - nConMod: constitution modifier<br>
     * - nIntMod: intelligence modifier<br>
     * - nWisMod: wisdom modifier<br>
     * - nChaMod: charisma modifier<br>
    **/
    idempotent NWEffect effectCurse(int nStrMod, int nDexMod, int nConMod, int nIntMod, int nWisMod, int nChaMod) throws NotInContextException;

    /**<br>
     * Returns an effect that is guaranteed to dominate a creature<br>
     * Like EffectDominated but cannot be resisted<br>
    **/
    idempotent NWEffect effectCutsceneDominated() throws NotInContextException;

    /**<br>
     * Creates a cutscene ghost effect, this will allow creatures<br>
     * to pathfind through other creatures without bumping into them<br>
     * for the duration of the effect.<br>
    **/
    idempotent NWEffect effectCutsceneGhost() throws NotInContextException;

    /**<br>
     * Returns an effect that when applied will paralyze the target's legs, rendering<br>
     * them unable to walk but otherwise unpenalized. This effect cannot be resisted.<br>
    **/
    idempotent NWEffect effectCutsceneImmobilize() throws NotInContextException;

    /**<br>
     * returns an effect that is guaranteed to paralyze a creature.<br>
     * this effect is identical to EffectParalyze except that it cannot be resisted.<br>
    **/
    idempotent NWEffect effectCutsceneParalyze() throws NotInContextException;

    /**<br>
     * Create a Damage effect<br>
     * - nDamageAmount: amount of damage to be dealt. This should be applied as an<br>
     * instantaneous effect.<br>
     * - nDamageType: DAMAGE_TYPE_*<br>
     * - nDamagePower: DAMAGE_POWER_*<br>
    **/
    idempotent NWEffect effectDamage(int nDamageAmount, DamageType tDamageType, DamagePower tDamagePower) throws NotInContextException;

    /**<br>
     * Create a Damage Decrease effect.<br>
     * - nPenalty<br>
     * - nDamageType: DAMAGE_TYPE_*<br>
    **/
    idempotent NWEffect effectDamageDecrease(int nPenalty, DamageType tDamageType) throws NotInContextException;

    /**<br>
     * Create a Damage Immunity Decrease effect.<br>
     * - nDamageType: DAMAGE_TYPE_*<br>
     * - nPercentImmunity<br>
    **/
    idempotent NWEffect effectDamageImmunityDecrease(DamageType tDamageType, int nPercentImmunity) throws NotInContextException;

    /**<br>
     * Creates a Damage Immunity Increase effect.<br>
     * - nDamageType: DAMAGE_TYPE_*<br>
     * - nPercentImmunity<br>
    **/
    idempotent NWEffect effectDamageImmunityIncrease(DamageType tDamageType, int nPercentImmunity) throws NotInContextException;

    /**<br>
     * Create a Damage Increase effect<br>
     * - nBonus: DAMAGE_BONUS_*<br>
     * - nDamageType: DAMAGE_TYPE_*<br>
     * NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may<br>
     * result in odd behaviour.<br>
    **/
    idempotent NWEffect effectDamageIncrease(int nBonus, DamageType tDamageType) throws NotInContextException;

    /**<br>
     * Create a Damage Reduction effect<br>
     * - nAmount: amount of damage reduction<br>
     * - nDamagePower: DAMAGE_POWER_*<br>
     * - nLimit: How much damage the effect can absorb before disappearing.<br>
     * Set to zero for infinite<br>
    **/
    idempotent NWEffect effectDamageReduction(int nAmount, DamagePower tDamagePower, int nLimit) throws NotInContextException;

    /**<br>
     * Create a Damage Resistance effect that removes the first nAmount points of<br>
     * damage of type nDamageType, up to nLimit (or infinite if nLimit is 0)<br>
     * - nDamageType: DAMAGE_TYPE_*<br>
     * - nAmount<br>
     * - nLimit<br>
    **/
    idempotent NWEffect effectDamageResistance(DamageType tDamageType, int nAmount, int nLimit) throws NotInContextException;

    /**<br>
     * Create a Damage Shield effect which does (nDamageAmount + nRandomAmount)<br>
     * damage to any melee attacker on a successful attack of damage type nDamageType.<br>
     * - nDamageAmount: an integer value<br>
     * - nRandomAmount: DAMAGE_BONUS_*<br>
     * - nDamageType: DAMAGE_TYPE_*<br>
     * NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may<br>
     * result in odd behaviour.<br>
    **/
    idempotent NWEffect effectDamageShield(int nDamageAmount, int nRandomAmount, DamageType tDamageType) throws NotInContextException;

    /**<br>
     * Create a Darkness effect.<br>
    **/
    idempotent NWEffect effectDarkness() throws NotInContextException;

    /**<br>
     * Create a Daze effect<br>
    **/
    idempotent NWEffect effectDazed() throws NotInContextException;

    /**<br>
     * Create a Deaf effect<br>
    **/
    idempotent NWEffect effectDeaf() throws NotInContextException;

    /**<br>
     * Create a Death effect<br>
     * - nSpectacularDeath: if this is TRUE, the creature to which this effect is<br>
     * applied will die in an extraordinary fashion<br>
     * - nDisplayFeedback<br>
    **/
    idempotent NWEffect effectDeath(bool bSpectacularDeath, bool bDisplayFeedback) throws NotInContextException;

    /**<br>
     * Create a Disappear effect to make the object "fly away" and then destroy<br>
     * itself.<br>
     * - nAnimation determines which appear and disappear animations to use. Most creatures<br>
     * only have animation 1, although a few have 2 (like beholders)<br>
    **/
    idempotent NWEffect effectDisappear(int nAnimation) throws NotInContextException;

    /**<br>
     * Create a Disappear/Appear effect.<br>
     * The object will "fly away" for the duration of the effect and will reappear<br>
     * at lLocation.<br>
     * - nAnimation determines which appear and disappear animations to use. Most creatures<br>
     * only have animation 1, although a few have 2 (like beholders)<br>
    **/
    idempotent NWEffect effectDisappearAppear(NWLocation lLocation, int nAnimation) throws NotInContextException;

    /**<br>
     * Create a Disease effect.<br>
     * - nDiseaseType: DISEASE_*<br>
    **/
    idempotent NWEffect effectDisease(int nDiseaseType) throws NotInContextException;

    /**<br>
     * Create a Dispel Magic All effect.<br>
     * If no parameter is specified, USE_CREATURE_LEVEL will be used. This will<br>
     * cause the dispel effect to use the level of the creature that created the<br>
     * effect.<br>
    **/
    idempotent NWEffect effectDispelMagicAll(int nCasterLevel) throws NotInContextException;

    /**<br>
     * Create a Dispel Magic Best effect.<br>
     * If no parameter is specified, USE_CREATURE_LEVEL will be used. This will<br>
     * cause the dispel effect to use the level of the creature that created the<br>
     * effect.<br>
    **/
    idempotent NWEffect effectDispelMagicBest(int nCasterLevel) throws NotInContextException;

    /**<br>
     * Create a Dominate effect<br>
    **/
    idempotent NWEffect effectDominated() throws NotInContextException;

    /**<br>
     * Create an Entangle effect<br>
     * When applied, this effect will restrict the creature's movement and apply a<br>
     * (-2) to all attacks and a -4 to AC.<br>
    **/
    idempotent NWEffect effectEntangle() throws NotInContextException;

    /**<br>
     * Returns an effect of type EFFECT_TYPE_ETHEREAL which works just like EffectSanctuary<br>
     * except that the observers get no saving throw<br>
    **/
    idempotent NWEffect effectEthereal() throws NotInContextException;

    /**<br>
     * Create a Frighten effect<br>
    **/
    idempotent NWEffect effectFrightened() throws NotInContextException;

    /**<br>
     * Create a Haste effect.<br>
    **/
    idempotent NWEffect effectHaste() throws NotInContextException;

    /**<br>
     * Create a Heal effect. This should be applied as an instantaneous effect.<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDamageToHeal < 0.<br>
    **/
    idempotent NWEffect effectHeal(int nDamageToHeal) throws NotInContextException;

    /**<br>
     * Create a Hit Point Change When Dying effect.<br>
     * - fHitPointChangePerRound: this can be positive or negative, but not zero.<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if fHitPointChangePerRound is 0.<br>
    **/
    idempotent NWEffect effectHitPointChangeWhenDying(double fHitPointChangePerRound) throws NotInContextException;

    /**<br>
     * Create an Immunity effect.<br>
     * - nImmunityType: IMMUNITY_TYPE_*<br>
    **/
    idempotent NWEffect effectImmunity(ImmunityType tImmunityType) throws NotInContextException;

    /**<br>
     * Create an Invisibility effect.<br>
     * - nInvisibilityType: INVISIBILITY_TYPE_*<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nInvisibilityType<br>
     * is invalid.<br>
    **/
    idempotent NWEffect effectInvisibility(int nInvisibilityType) throws NotInContextException;

    /**<br>
     * Create a Knockdown effect<br>
     * This effect knocks creatures off their feet, they will sit until the effect<br>
     * is removed. This should be applied as a temporary effect with a 3 second<br>
     * duration minimum (1 second to fall, 1 second sitting, 1 second to get up).<br>
    **/
    idempotent NWEffect effectKnockdown() throws NotInContextException;

    /**<br>
     * Link the two supplied effects, returning eChildEffect as a child of<br>
     * eParentEffect.<br>
     * Note: When applying linked effects if the target is immune to all valid<br>
     * effects all other effects will be removed as well. This means that if you<br>
     * apply a visual effect and a silence effect (in a link) and the target is<br>
     * immune to the silence effect that the visual effect will get removed as well.<br>
     * Visual Effects are not considered "valid" effects for the purposes of<br>
     * determining if an effect will be removed or not and as such should never be<br>
     * packaged *only* with other visual effects in a link.<br>
    **/
    idempotent NWEffect effectLinkEffects(NWEffect eChildEffect, NWEffect eParentEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Create a Miss Chance effect.<br>
     * - nPercentage: 1-100 inclusive<br>
     * - nMissChanceType: MISS_CHANCE_TYPE_*<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or<br>
     * nPercentage > 100.<br>
    **/
    idempotent NWEffect effectMissChance(int nPercentage, MissChanceType tMissChanceType) throws NotInContextException;

    /**<br>
     * Create a Modify Attacks effect to add attacks.<br>
     * - nAttacks: maximum is 5, even with the effect stacked<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nAttacks > 5.<br>
    **/
    idempotent NWEffect effectModifyAttacks(int nAttacks) throws NotInContextException;

    /**<br>
     * Create a Movement Speed Decrease effect.<br>
     * - nPercentChange - range 0 through 99<br>
     * eg.<br>
     * 0 = no change in speed<br>
     * 50 = 50% slower<br>
     * 99 = almost immobile<br>
    **/
    idempotent NWEffect effectMovementSpeedDecrease(int nPercentChange) throws NotInContextException;

    /**<br>
     * Create a Movement Speed Increase effect.<br>
     * - nPercentChange - range 0 through 99<br>
     * eg.<br>
     * 0 = no change in speed<br>
     * 50 = 50% faster<br>
     * 99 = almost twice as fast<br>
    **/
    idempotent NWEffect effectMovementSpeedIncrease(int nPercentChange) throws NotInContextException;

    /**<br>
     * Create a Negative Level effect.<br>
     * - nNumLevels: the number of negative levels to apply.<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nNumLevels > 100.<br>
    **/
    idempotent NWEffect effectNegativeLevel(int nNumLevels, bool bHPBonus) throws NotInContextException;

    /**<br>
     * Create a Paralyze effect<br>
    **/
    idempotent NWEffect effectParalyze() throws NotInContextException;

    /**<br>
     * returns an effect that will petrify the target<br>
     * * currently applies EffectParalyze and the stoneskin visual effect.<br>
    **/
    idempotent NWEffect effectPetrify() throws NotInContextException;

    /**<br>
     * Create a Poison effect.<br>
     * - nPoisonType: POISON_*<br>
    **/
    idempotent NWEffect effectPoison(int nPoisonType) throws NotInContextException;

    /**<br>
     * Create a Polymorph effect.<br>
    **/
    idempotent NWEffect effectPolymorph(int nPolymorphSelection, bool bLocked) throws NotInContextException;

    /**<br>
     * Create a Regenerate effect.<br>
     * - nAmount: amount of damage to be regenerated per time interval<br>
     * - fIntervalSeconds: length of interval in seconds<br>
    **/
    idempotent NWEffect effectRegenerate(int nAmount, double fIntervalSeconds) throws NotInContextException;

    /**<br>
     * Create a Resurrection effect. This should be applied as an instantaneous effect.<br>
    **/
    idempotent NWEffect effectResurrection() throws NotInContextException;

    /**<br>
     * Create a Sanctuary effect.<br>
     * - nDifficultyClass: must be a non-zero, positive number<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDifficultyClass <= 0.<br>
    **/
    idempotent NWEffect effectSanctuary(int nDifficultyClass) throws NotInContextException;

    /**<br>
     * Create a Saving Throw Decrease effect.<br>
     * - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)<br>
     * SAVING_THROW_ALL<br>
     * SAVING_THROW_FORT<br>
     * SAVING_THROW_REFLEX<br>
     * SAVING_THROW_WILL<br>
     * - nValue: size of the Saving Throw decrease<br>
     * - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )<br>
    **/
    idempotent NWEffect effectSavingThrowDecrease(int nSave, int nValue, SaveType tSaveType) throws NotInContextException;

    /**<br>
     * Create a Saving Throw Increase effect<br>
     * - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)<br>
     * SAVING_THROW_ALL<br>
     * SAVING_THROW_FORT<br>
     * SAVING_THROW_REFLEX<br>
     * SAVING_THROW_WILL<br>
     * - nValue: size of the Saving Throw increase<br>
     * - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )<br>
    **/
    idempotent NWEffect effectSavingThrowIncrease(int nSave, int nValue, SaveType tSaveType) throws NotInContextException;

    /**<br>
     * Create a See Invisible effect.<br>
    **/
    idempotent NWEffect effectSeeInvisible() throws NotInContextException;

    /**<br>
     * Create a Silence effect.<br>
    **/
    idempotent NWEffect effectSilence() throws NotInContextException;

    /**<br>
     * Create a Skill Decrease effect.<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.<br>
    **/
    idempotent NWEffect effectSkillDecrease(int nSkill, int nValue) throws NotInContextException;

    /**<br>
     * Create a Skill Increase effect.<br>
     * - nSkill: SKILL_*<br>
     * - nValue<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.<br>
    **/
    idempotent NWEffect effectSkillIncrease(int nSkill, int nValue) throws NotInContextException;

    /**<br>
     * Create a Sleep effect<br>
    **/
    idempotent NWEffect effectSleep() throws NotInContextException;

    /**<br>
     * Create a Slow effect.<br>
    **/
    idempotent NWEffect effectSlow() throws NotInContextException;

    /**<br>
     * Creates an effect that inhibits spells<br>
     * - nPercent - percentage of failure<br>
     * - nSpellSchool - the school of spells affected.<br>
    **/
    idempotent NWEffect effectSpellFailure(int nPercent, SpellSchool tSpellSchool) throws NotInContextException;

    /**<br>
     * Create a Spell Immunity effect.<br>
     * There is a known bug with this function. There *must* be a parameter specified<br>
     * when this is called (even if the desired parameter is SPELL_ALL_SPELLS),<br>
     * otherwise an effect of type EFFECT_TYPE_INVALIDEFFECT will be returned.<br>
     * - nImmunityToSpell: SPELL_*<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nImmunityToSpell is<br>
     * invalid.<br>
    **/
    idempotent NWEffect effectSpellImmunity(int nImmunityToSpell) throws NotInContextException;

    /**<br>
     * Create a Spell Level Absorption effect.<br>
     * - nMaxSpellLevelAbsorbed: maximum spell level that will be absorbed by the<br>
     * effect<br>
     * - nTotalSpellLevelsAbsorbed: maximum number of spell levels that will be<br>
     * absorbed by the effect<br>
     * - nSpellSchool: SPELL_SCHOOL_*<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if:<br>
     * nMaxSpellLevelAbsorbed is not between -1 and 9 inclusive, or nSpellSchool<br>
     * is invalid.<br>
    **/
    idempotent NWEffect effectSpellLevelAbsorption(int nMaxSpellLevelAbsorbed, int nTotalSpellLevelsAbsorbed, SpellSchool tSpellSchool) throws NotInContextException;

    /**<br>
     * Create a Spell Resistance Decrease effect.<br>
    **/
    idempotent NWEffect effectSpellResistanceDecrease(int nValue) throws NotInContextException;

    /**<br>
     * Create a Spell Resistance Increase effect.<br>
     * - nValue: size of spell resistance increase<br>
    **/
    idempotent NWEffect effectSpellResistanceIncrease(int nValue) throws NotInContextException;

    /**<br>
     * Create a Stun effect<br>
    **/
    idempotent NWEffect effectStunned() throws NotInContextException;

    /**<br>
     * Create a Summon Creature effect.  The creature is created and placed into the<br>
     * caller's party/faction.<br>
     * - sCreatureResref: Identifies the creature to be summoned<br>
     * - nVisualEffectId: VFX_*<br>
     * - fDelaySeconds: There can be delay between the visual effect being played, and the<br>
     * creature being added to the area<br>
     * - nUseAppearAnimation: should this creature play it's "appear" animation when it is<br>
     * summoned. If zero, it will just fade in somewhere near the target.  If the value is 1<br>
     * it will use the appear animation, and if it's 2 it will use appear2 (which doesn't exist for most creatures)<br>
    **/
    idempotent NWEffect effectSummonCreature(string sCreatureResref, int nVisualEffectId, double fDelaySeconds, bool bUseAppearAnimation) throws NotInContextException;

    /**<br>
     * Create a Swarm effect.<br>
     * - nLooping: If this is TRUE, for the duration of the effect when one creature<br>
     * created by this effect dies, the next one in the list will be created.  If<br>
     * the last creature in the list dies, we loop back to the beginning and<br>
     * sCreatureTemplate1 will be created, and so on...<br>
     * - sCreatureTemplate1<br>
     * - sCreatureTemplate2<br>
     * - sCreatureTemplate3<br>
     * - sCreatureTemplate4<br>
    **/
    idempotent NWEffect effectSwarm(bool bLooping, string sCreatureTemplate1, string sCreatureTemplate2, string sCreatureTemplate3, string sCreatureTemplate4) throws NotInContextException;

    /**<br>
     * Create a Temporary Hitpoints effect.<br>
     * - nHitPoints: a positive integer<br>
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nHitPoints < 0.<br>
    **/
    idempotent NWEffect effectTemporaryHitpoints(int nHitPoints) throws NotInContextException;

    /**<br>
     * Create a Time Stop effect.<br>
    **/
    idempotent NWEffect effectTimeStop() throws NotInContextException;

    /**<br>
     * Create a True Seeing effect.<br>
    **/
    idempotent NWEffect effectTrueSeeing() throws NotInContextException;

    /**<br>
     * Create a Turn Resistance Decrease effect.<br>
     * - nHitDice: a positive number representing the number of hit dice for the<br>
     * /  decrease<br>
    **/
    idempotent NWEffect effectTurnResistanceDecrease(int nHitDice) throws NotInContextException;

    /**<br>
     * Create a Turn Resistance Increase effect.<br>
     * - nHitDice: a positive number representing the number of hit dice for the<br>
     * increase<br>
    **/
    idempotent NWEffect effectTurnResistanceIncrease(int nHitDice) throws NotInContextException;

    /**<br>
     * Create a Turned effect.<br>
     * Turned effects are supernatural by default.<br>
    **/
    idempotent NWEffect effectTurned() throws NotInContextException;

    /**<br>
     * Create an Ultravision effect.<br>
    **/
    idempotent NWEffect effectUltravision() throws NotInContextException;

    /**<br>
     * * Create a Visual Effect that can be applied to an object.<br>
     * - nVisualEffectId<br>
     * - nMissEffect: if this is TRUE, a random vector near or past the target will<br>
     * be generated, on which to play the effect<br>
    **/
    idempotent NWEffect effectVisualEffect(int nVisualEffectId, bool bMissEffect) throws NotInContextException;

    /**<br>
     * End the currently running game, play sEndMovie then return all players to the<br>
     * game's main menu.<br>
    **/
    void endGame(string sEndMovie) throws NotInContextException;

    /**<br>
     * Make oTarget run sScript and then return execution to the calling script.<br>
     * If sScript does not specify a compiled script, nothing happens.<br>
    **/
    void executeScript(string sScript, NWObject oTarget) throws NotInContextException;

    /**<br>
     * Expose/Hide the entire map of oArea for oPlayer.<br>
     * - oArea: The area that the map will be exposed/hidden for.<br>
     * - oPlayer: The player the map will be exposed/hidden for.<br>
     * - bExplored: TRUE/FALSE. Whether the map should be completely explored or hidden.<br>
    **/
    void exploreAreaForPlayer(NWObject oArea, NWObject oPlayer, bool bExplored) throws NotInContextException;

    /**<br>
     * Force all the characters of the players who are currently in the game to<br>
     * be exported to their respective directories i.e. LocalVault/ServerVault/ etc.<br>
    **/
    void exportAllCharacters() throws NotInContextException;

    /**<br>
     * Force the character of the player specified to be exported to its respective directory<br>
     * i.e. LocalVault/ServerVault/ etc.<br>
    **/
    void exportSingleCharacter(NWObject oPlayer) throws NotInContextException;

    /**<br>
     * Set the subtype of eEffect to Extraordinary and return eEffect.<br>
     * (Effects default to magical if the subtype is not set)<br>
     * Extraordinary effects are removed by resting, but not by dispel magic<br>
    **/
    idempotent NWEffect extraordinaryEffect(NWEffect eEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Fades the screen for the given creature/player from black to regular screen<br>
     * - oCreature: creature controlled by player that should fade from black<br>
    **/
    idempotent void fadeFromBlack(NWObject oCreature, double fSpeed) throws NotInContextException;

    /**<br>
     * Fades the screen for the given creature/player from regular screen to black<br>
     * - oCreature: creature controlled by player that should fade to black<br>
    **/
    idempotent void fadeToBlack(NWObject oCreature, double fSpeed) throws NotInContextException;

    /**<br>
     * Display floaty text above the specified creature.<br>
     * The text will also appear in the chat buffer of each player that receives the<br>
     * floaty text.<br>
     * - nStrRefToDisplay: String ref (therefore text is translated)<br>
     * - oCreatureToFloatAbove<br>
     * - bBroadcastToFaction: If this is TRUE then only creatures in the same faction<br>
     * as oCreatureToFloatAbove<br>
     * will see the floaty text, and only if they are within range (30 metres).<br>
    **/
    void floatingTextStrRefOnCreature(int nStrRefToDisplay, NWObject oCreatureToFloatAbove, bool bBroadcastToFaction) throws NotInContextException;

    /**<br>
     * Display floaty text above the specified creature.<br>
     * The text will also appear in the chat buffer of each player that receives the<br>
     * floaty text.<br>
     * - sStringToDisplay: String<br>
     * - oCreatureToFloatAbove<br>
     * - bBroadcastToFaction: If this is TRUE then only creatures in the same faction<br>
     * as oCreatureToFloatAbove<br>
     * will see the floaty text, and only if they are within range (30 metres).<br>
    **/
    void floatingTextStringOnCreature(string sStringToDisplay, NWObject oCreatureToFloatAbove, bool bBroadcastToFaction) throws NotInContextException;

    /**<br>
     * Instantly gives this creature the benefits of a rest (restored hitpoints, spells, feats, etc..)<br>
    **/
    void forceRest(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Do a Fortitude Save check for the given DC<br>
     * - oCreature<br>
     * - nDC: Difficulty check<br>
     * - nSaveType: SAVING_THROW_TYPE_*<br>
     * - oSaveVersus<br>
     * Returns: 0 if the saving throw roll failed<br>
     * Returns: 1 if the saving throw roll succeeded<br>
     * Returns: 2 if the target was immune to the save type specified<br>
     * Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass<br>
     * GetAreaOfEffectCreator() into oSaveVersus!!<br>
    **/
    SavingThrowResult fortitudeSave(NWObject oCreature, int nDC, SaveType tSaveType, NWObject oSaveVersus) throws NotInContextException;

    /**<br>
     * Gets a value from a 2DA file on the server and returns it as a string<br>
     * avoid using this function in loops<br>
     * - s2DA: the name of the 2da file, 16 chars max<br>
     * - sColumn: the name of the column in the 2da<br>
     * - nRow: the row in the 2da<br>
     * * returns an empty string if file, row, or column not found<br>
    **/
    idempotent string get2DAString(string s2DA, string sColumn, int nRow) throws NotInContextException;

    /**<br>
     * If oObject is a creature, this will return that creature's armour class<br>
     * If oObject is an item, door or placeable, this will return zero.<br>
     * - nForFutureUse: this parameter is not currently used<br>
     * * Return value if oObject is not a creature, item, door or placeable: -1<br>
    **/
    idempotent int getAC(NWObject oObject) throws NotInContextException;

    /**<br>
     * Gets the current AI Level that the creature is running at.<br>
     * Returns one of the following:<br>
     * AI_LEVEL_INVALID, AI_LEVEL_VERY_LOW, AI_LEVEL_LOW, AI_LEVEL_NORMAL, AI_LEVEL_HIGH, AI_LEVEL_VERY_HIGH<br>
    **/
    idempotent AILevel getAILevel(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Returns the ability modifier for the specified ability<br>
     * Get oCreature's ability modifier for nAbility.<br>
     * - nAbility: ABILITY_*<br>
     * - oCreature<br>
    **/
    idempotent int getAbilityModifier(Ability tAbility, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the ability score of type nAbility for a creature (otherwise 0)<br>
     * - oCreature: the creature whose ability score we wish to find out<br>
     * - nAbilityType: ABILITY_*<br>
     * - nBaseAbilityScore: if set to true will return the base ability score without<br>
     * bonuses (e.g. ability bonuses granted from equipped items).<br>
     * Return value on error: 0<br>
    **/
    idempotent int getAbilityScore(NWObject oCreature, Ability tAbility, bool bBaseAbilityScore) throws NotInContextException;

    /**<br>
     * Gets the status of ACTION_MODE_* modes on a creature.<br>
    **/
    idempotent bool getActionMode(NWObject oCreature, ActionMode tActionMode) throws NotInContextException;

    /**<br>
     * Get oCreature's age.<br>
     * * Returns 0 if oCreature is invalid.<br>
    **/
    idempotent int getAge(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Return an ALIGNMENT_* constant to represent oCreature's good/evil alignment<br>
     * * Return value if oCreature is not a valid creature: -1<br>
    **/
    idempotent Alignment getAlignmentGoodEvil(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Return an ALIGNMENT_* constant to represent oCreature's law/chaos alignment<br>
     * * Return value if oCreature is not a valid creature: -1<br>
    **/
    idempotent Alignment getAlignmentLawChaos(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get oCreature's animal companion creature type<br>
     * (ANIMAL_COMPANION_CREATURE_TYPE_*).<br>
     * * Returns ANIMAL_COMPANION_CREATURE_TYPE_NONE if oCreature is invalid or does<br>
     * not currently have an animal companion.<br>
    **/
    idempotent int getAnimalCompanionCreatureType(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get oCreature's animal companion's name.<br>
     * * Returns "" if oCreature is invalid, does not currently<br>
     * have an animal companion or if the animal companion's name is blank.<br>
    **/
    idempotent string getAnimalCompanionName(NWObject oTarget) throws NotInContextException;

    /**<br>
     * returns the appearance type of the specified creature.<br>
     * * returns a constant APPEARANCE_TYPE_* for valid creatures<br>
     * * returns APPEARANCE_TYPE_INVALID for non creatures/invalid creatures<br>
    **/
    idempotent int getAppearanceType(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Returns the current arcane spell failure factor of a creature<br>
    **/
    idempotent int getArcaneSpellFailure(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the area that oTarget is currently in<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getArea(NWObject oTarget) throws NotInContextException;

    /**<br>
     * This returns the creator of oAreaOfEffectObject.<br>
     * * Returns OBJECT_INVALID if oAreaOfEffectObject is not a valid Area of Effect object.<br>
    **/
    idempotent NWObject getAreaOfEffectCreator(NWObject oAreaOfEffectObject) throws NotInContextException;

    /**<br>
     * Gets the size of the area.<br>
     * - nAreaDimension: The area dimension that you wish to determine.<br>
     * AREA_HEIGHT<br>
     * AREA_WIDTH<br>
     * - oArea: The area that you wish to get the size of.<br>
     * Returns: The number of tiles that the area is wide/high, or zero on an error.<br>
     * If no valid area (or object) is specified, it uses the area of the caller.<br>
     * If an object other than an area is specified, will use the area that the object is currently in.<br>
    **/
    idempotent int getAreaSize(int nAreaDimension, NWObject oArea) throws NotInContextException;

    /**<br>
     * Get the associate of type nAssociateType belonging to oMaster.<br>
     * - nAssociateType: ASSOCIATE_TYPE_*<br>
     * - nMaster<br>
     * - nTh: Which associate of the specified type to return<br>
     * * Returns OBJECT_INVALID if no such associate exists.<br>
    **/
    idempotent NWObject getAssociate(AssociateType tAssociateType, NWObject oMaster, int nTh) throws NotInContextException;

    /**<br>
     * Returns the associate type of the specified creature.<br>
     * - Returns ASSOCIATE_TYPE_NONE if the creature is not the associate of anyone.<br>
    **/
    idempotent AssociateType getAssociateType(NWObject oAssociate) throws NotInContextException;

    /**<br>
     * Get the attack target of oCreature.<br>
     * This only works when oCreature is in combat.<br>
    **/
    idempotent NWObject getAttackTarget(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the target that the caller attempted to attack - this should be used in<br>
     * conjunction with GetAttackTarget(). This value is set every time an attack is<br>
     * made, and is reset at the end of combat.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid creature.<br>
    **/
    idempotent NWObject getAttemptedAttackTarget() throws NotInContextException;

    /**<br>
     * Get the target at which the caller attempted to cast a spell.<br>
     * This value is set every time a spell is cast and is reset at the end of<br>
     * combat.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid creature.<br>
    **/
    idempotent NWObject getAttemptedSpellTarget() throws NotInContextException;

    /**<br>
     * Returns the base attach bonus for the given creature.<br>
    **/
    idempotent int getBaseAttackBonus(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the base item type (BASE_ITEM_*) of oItem.<br>
     * * Returns BASE_ITEM_INVALID if oItem is an invalid item.<br>
    **/
    idempotent int getBaseItemType(NWObject oItem) throws NotInContextException;

    /**<br>
     * Get the last blocking door encountered by the caller of this function.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid creature.<br>
    **/
    idempotent NWObject getBlockingDoor() throws NotInContextException;

    /**<br>
     * Get the current calendar day.<br>
    **/
    idempotent int getCalendarDay() throws NotInContextException;

    /**<br>
     * Get the current calendar month.<br>
    **/
    idempotent int getCalendarMonth() throws NotInContextException;

    /**<br>
     * Get the current calendar year.<br>
    **/
    idempotent int getCalendarYear() throws NotInContextException;

    /**<br>
     * This will read a float from the  specified campaign database<br>
     * The database name IS case sensitive and it must be the same for both set and get functions.<br>
     * The var name must be unique across the entire database, regardless of the variable type.<br>
     * If you want a variable to pertain to a specific player in the game, provide a player object.<br>
    **/
    idempotent double getCampaignFloat(string sCampaignName, string sVarName, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * This will read an int from the  specified campaign database<br>
     * The database name IS case sensitive and it must be the same for both set and get functions.<br>
     * The var name must be unique across the entire database, regardless of the variable type.<br>
     * If you want a variable to pertain to a specific player in the game, provide a player object.<br>
    **/
    idempotent int getCampaignInt(string sCampaignName, string sVarName, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * This will read a location from the  specified campaign database<br>
     * The database name IS case sensitive and it must be the same for both set and get functions.<br>
     * The var name must be unique across the entire database, regardless of the variable type.<br>
     * If you want a variable to pertain to a specific player in the game, provide a player object.<br>
    **/
    idempotent NWLocation getCampaignLocation(string sCampaignName, string sVarName, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * This will read a string from the  specified campaign database<br>
     * The database name IS case sensitive and it must be the same for both set and get functions.<br>
     * The var name must be unique across the entire database, regardless of the variable type.<br>
     * If you want a variable to pertain to a specific player in the game, provide a player object.<br>
    **/
    idempotent string getCampaignString(string sCampaignName, string sVarName, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * This will read a vector from the  specified campaign database<br>
     * The database name IS case sensitive and it must be the same for both set and get functions.<br>
     * The var name must be unique across the entire database, regardless of the variable type.<br>
     * If you want a variable to pertain to a specific player in the game, provide a player object.<br>
    **/
    idempotent NWVector getCampaignVector(string sCampaignName, string sVarName, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * Get the level at which this creature cast it's last spell (or spell-like ability)<br>
     * * Return value on error, or if oCreature has not yet cast a spell: 0;<br>
    **/
    idempotent int getCasterLevel(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get oCreature's challenge rating.<br>
     * * Returns 0.0 if oCreature is invalid.<br>
    **/
    idempotent double getChallengeRating(NWObject oCreature) throws NotInContextException;

    /**<br>
     * A creature can have up to three classes.  This function determines the<br>
     * creature's class (CLASS_TYPE_*) based on nClassPosition.<br>
     * - nClassPosition: 1, 2 or 3<br>
     * - oCreature<br>
     * * Returns CLASS_TYPE_INVALID if the oCreature does not have a class in<br>
     * nClassPosition (i.e. a single-class creature will only have a value in<br>
     * nClassLocation=1) or if oCreature is not a valid creature.<br>
    **/
    idempotent int getClassByPosition(int nClassPosition, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Use this in a trigger's OnClick event script to get the object that last<br>
     * clicked on it.<br>
     * This is identical to GetEnteringObject.<br>
     * GetClickingObject() should not be called from a placeable's OnClick event,<br>
     * instead use GetPlaceableLastClickedBy();<br>
    **/
    idempotent NWObject getClickingObject() throws NotInContextException;

    /**<br>
     * Get the Color of oObject from the color channel specified.<br>
     * - oObject: the object from which you are obtaining the color.<br>
     * Can be a creature that has color information (i.e. the playable races).<br>
     * - nColorChannel: The color channel that you want to get the color value of.<br>
     * COLOR_CHANNEL_SKIN<br>
     * COLOR_CHANNEL_HAIR<br>
     * COLOR_CHANNEL_TATTOO_1<br>
     * COLOR_CHANNEL_TATTOO_2<br>
     * * Returns -1 on error.<br>
    **/
    idempotent int getColor(NWObject oObject, int nColorChannel) throws NotInContextException;

    /**<br>
     * Determine whether oTarget's action stack can be modified.<br>
    **/
    idempotent bool getCommandable(NWObject oTarget) throws NotInContextException;

    /**<br>
     * returns the model number being used for the body part and creature specified<br>
     * The model number returned is for the body part when the creature is not wearing<br>
     * armor (i.e. whether or not the creature is wearing armor does not affect<br>
     * the return value).<br>
     * Note: Only works on part based creatures, which is typically restricted to<br>
     * the playable races (unless some new part based custom content has been<br>
     * added to the module).<br>
     * <br>
     * returns CREATURE_PART_INVALID if used on a non-creature object,<br>
     * or if the creature does not use a part based model.<br>
     * <br>
     * - nPart (CREATURE_PART_*)<br>
     * CREATURE_PART_RIGHT_FOOT<br>
     * CREATURE_PART_LEFT_FOOT<br>
     * CREATURE_PART_RIGHT_SHIN<br>
     * CREATURE_PART_LEFT_SHIN<br>
     * CREATURE_PART_RIGHT_THIGH<br>
     * CREATURE_PART_LEFT_THIGH<br>
     * CREATURE_PART_PELVIS<br>
     * CREATURE_PART_TORSO<br>
     * CREATURE_PART_BELT<br>
     * CREATURE_PART_NECK<br>
     * CREATURE_PART_RIGHT_FOREARM<br>
     * CREATURE_PART_LEFT_FOREARM<br>
     * CREATURE_PART_RIGHT_BICEP<br>
     * CREATURE_PART_LEFT_BICEP<br>
     * CREATURE_PART_RIGHT_SHOULDER<br>
     * CREATURE_PART_LEFT_SHOULDER<br>
     * CREATURE_PART_RIGHT_HAND<br>
     * CREATURE_PART_LEFT_HAND<br>
     * CREATURE_PART_HEAD<br>
    **/
    idempotent int getCreatureBodyPart(CreaturePart tCreaturePart, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the size (CREATURE_SIZE_*) of oCreature.<br>
    **/
    idempotent CreatureSize getCreatureSize(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Returns the default package selected for this creature to level up with<br>
     * - returns PACKAGE_INVALID if error occurs<br>
    **/
    idempotent int getCreatureStartingPackage(NWObject oCreature) throws NotInContextException;

    /**<br>
     * returns the Tail type of the creature specified.<br>
     * CREATURE_TAIL_TYPE_NONE<br>
     * CREATURE_TAIL_TYPE_LIZARD<br>
     * CREATURE_TAIL_TYPE_BONE<br>
     * CREATURE_TAIL_TYPE_DEVIL<br>
     * returns CREATURE_TAIL_TYPE_NONE if used on a non-creature object,<br>
     * if the creature has no Tail, or if the creature can not have its<br>
     * Tail type changed in the toolset.<br>
    **/
    idempotent int getCreatureTailType(NWObject oCreature) throws NotInContextException;

    /**<br>
     * returns the Wing type of the creature specified.<br>
     * CREATURE_WING_TYPE_NONE<br>
     * CREATURE_WING_TYPE_DEMON<br>
     * CREATURE_WING_TYPE_ANGEL<br>
     * CREATURE_WING_TYPE_BAT<br>
     * CREATURE_WING_TYPE_DRAGON<br>
     * CREATURE_WING_TYPE_BUTTERFLY<br>
     * CREATURE_WING_TYPE_BIRD<br>
     * returns CREATURE_WING_TYPE_NONE if used on a non-creature object,<br>
     * if the creature has no wings, or if the creature can not have its<br>
     * wing type changed in the toolset.<br>
    **/
    idempotent int getCreatureWingType(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the current action (ACTION_*) that oObject is executing.<br>
    **/
    idempotent Action getCurrentAction(NWObject oObject) throws NotInContextException;

    /**<br>
     * Get the current hitpoints of oObject<br>
     * * Return value on error: 0<br>
    **/
    idempotent int getCurrentHitPoints(NWObject oObject) throws NotInContextException;

    /**<br>
     * Returns the current movement rate factor<br>
     * of the cutscene 'camera man'.<br>
     * NOTE: This will be a value between 0.1, 2.0 (10%-200%)<br>
    **/
    idempotent double getCutsceneCameraMoveRate(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Gets the current cutscene state of the player specified by oCreature.<br>
     * Returns TRUE if the player is in cutscene mode.<br>
     * Returns FALSE if the player is not in cutscene mode, or on an error<br>
     * (such as specifying a non creature object).<br>
    **/
    idempotent bool getCutsceneMode(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the amount of damage of type nDamageType that has been dealt to the caller.<br>
     * - nDamageType: DAMAGE_TYPE_*<br>
    **/
    idempotent int getDamageDealtByType(DamageType tDamageType) throws NotInContextException;

    /**<br>
     * Returns the defensive casting mode of the specified creature.<br>
     * - oCreature<br>
     * * Returns a constant DEFENSIVE_CASTING_MODE_*<br>
    **/
    idempotent int getDefensiveCastingMode(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the name of oCreature's deity.<br>
     * * Returns "" if oCreature is invalid (or if the deity name is blank for<br>
     * oCreature).<br>
    **/
    idempotent string getDeity(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the description of oObject.<br>
     * - oObject: the object from which you are obtaining the description.<br>
     * Can be a creature, item, placeable, door, trigger or module object.<br>
     * - bOriginalDescription:  if set to true any new description specified via a SetDescription scripting command<br>
     * is ignored and the original object's description is returned instead.<br>
     * - bIdentified: If oObject is an item, setting this to TRUE will return the identified description,<br>
     * setting this to FALSE will return the unidentified description. This flag has no<br>
     * effect on objects other than items.<br>
    **/
    idempotent string getDescription(NWObject oObject, bool bOriginalDescription, bool bIdentifiedDescription) throws NotInContextException;

    /**<br>
     * Returns the detection mode of the specified creature.<br>
     * - oCreature<br>
     * * Returns a constant DETECT_MODE_*<br>
    **/
    idempotent int getDetectMode(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Gets the length of the specified wavefile, in seconds<br>
     * Only works for sounds used for dialog.<br>
    **/
    idempotent double getDialogSoundLength(int nStrRef) throws NotInContextException;

    /**<br>
     * Get the distance in metres between oObjectA and oObjectB.<br>
     * * Return value if either object is invalid: 0.0f<br>
    **/
    idempotent double getDistanceBetween(NWObject oObjectA, NWObject oObjectB) throws NotInContextException;

    /**<br>
     * Get the distance between lLocationA and lLocationB.<br>
    **/
    idempotent double getDistanceBetweenLocations(NWLocation lLocationA, NWLocation lLocationB) throws NotInContextException;

    /**<br>
     * Get the distance from the caller to oObject in metres.<br>
     * * Return value on error: -1.0f<br>
    **/
    idempotent double getDistanceToObject(NWObject oObject) throws NotInContextException;

    /**<br>
     * returns TRUE if the item CAN be dropped<br>
     * Droppable items will appear on a creature's remains when the creature is killed.<br>
    **/
    idempotent bool getDroppableFlag(NWObject oItem) throws NotInContextException;

    /**<br>
     * Get the object that created eEffect.<br>
     * * Returns OBJECT_INVALID if eEffect is not a valid effect.<br>
    **/
    idempotent NWObject getEffectCreator(NWEffect eEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Get the duration type (DURATION_TYPE_*) of eEffect.<br>
     * * Return value if eEffect is not valid: -1<br>
    **/
    idempotent DurationType getEffectDurationType(NWEffect eEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Get the spell (SPELL_*) that applied eSpellEffect.<br>
     * * Returns -1 if eSpellEffect was applied outside a spell script.<br>
    **/
    idempotent int getEffectSpellId(NWEffect eSpellEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Get the subtype (SUBTYPE_*) of eEffect.<br>
     * * Return value on error: 0<br>
    **/
    idempotent EffectSubType getEffectSubType(NWEffect eEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Get the effect type (EFFECT_TYPE_*) of eEffect.<br>
     * * Return value if eEffect is invalid: EFFECT_INVALIDEFFECT<br>
    **/
    idempotent EffectType getEffectType(NWEffect eEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Determine whether oEncounter is active.<br>
    **/
    idempotent int getEncounterActive(NWObject oEncounter) throws NotInContextException;

    /**<br>
     * Get the difficulty level of oEncounter.<br>
    **/
    idempotent int getEncounterDifficulty(NWObject oEncounter) throws NotInContextException;

    /**<br>
     * Get the number of times that oEncounter has spawned so far<br>
    **/
    idempotent int getEncounterSpawnsCurrent(NWObject oEncounter) throws NotInContextException;

    /**<br>
     * Get the maximum number of times that oEncounter will spawn.<br>
    **/
    idempotent int getEncounterSpawnsMax(NWObject oEncounter) throws NotInContextException;

    /**<br>
     * The value returned by this function depends on the object type of the caller:<br>
     * 1) If the caller is a door it returns the object that last<br>
     * triggered it.<br>
     * 2) If the caller is a trigger, area of effect, module, area or encounter it<br>
     * returns the object that last entered it.<br>
     * * Return value on error: OBJECT_INVALID<br>
     * When used for doors, this should only be called from the OnAreaTransitionClick<br>
     * event.  Otherwise, it should only be called in OnEnter scripts.<br>
    **/
    idempotent NWObject getEnteringObject() throws NotInContextException;

    /**<br>
     * Get the object that last left the caller.  This function works on triggers,<br>
     * areas of effect, modules, areas and encounters.<br>
     * * Return value on error: OBJECT_INVALID<br>
     * Should only be called in OnExit scripts.<br>
    **/
    idempotent NWObject getExitingObject() throws NotInContextException;

    /**<br>
     * Get the direction in which oTarget is facing, expressed as a float between<br>
     * 0.0f and 360.0f<br>
     * * Return value on error: -1.0f<br>
    **/
    idempotent double getFacing(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get an integer between 0 and 100 (inclusive) that represents the average<br>
     * good/evil alignment of oFactionMember's faction.<br>
     * * Return value on error: -1<br>
    **/
    idempotent int getFactionAverageGoodEvilAlignment(NWObject oFactionMember) throws NotInContextException;

    /**<br>
     * Get an integer between 0 and 100 (inclusive) that represents the average<br>
     * law/chaos alignment of oFactionMember's faction.<br>
     * * Return value on error: -1<br>
    **/
    idempotent int getFactionAverageLawChaosAlignment(NWObject oFactionMember) throws NotInContextException;

    /**<br>
     * Get the average level of the members of the faction.<br>
     * * Return value on error: -1<br>
    **/
    idempotent int getFactionAverageLevel(NWObject oFactionMember) throws NotInContextException;

    /**<br>
     * Get an integer between 0 and 100 (inclusive) that represents how<br>
     * oSourceFactionMember's faction feels about oTarget.<br>
     * * Return value on error: -1<br>
    **/
    idempotent int getFactionAverageReputation(NWObject oSourceFactionMember, NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get the average XP of the members of the faction.<br>
     * * Return value on error: -1<br>
    **/
    idempotent int getFactionAverageXP(NWObject oFactionMember) throws NotInContextException;

    /**<br>
     * Get the object faction member with the highest armour class.<br>
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.<br>
    **/
    idempotent NWObject getFactionBestAC(NWObject oFactionMember, bool bMustBeVisible) throws NotInContextException;

    /**<br>
     * * Returns TRUE if the Faction Ids of the two objects are the same<br>
    **/
    idempotent bool getFactionEqual(NWObject oFirstObject, NWObject oSecondObject) throws NotInContextException;

    /**<br>
     * Get the amount of gold held by oFactionMember's faction.<br>
     * * Returns -1 if oFactionMember's faction is invalid.<br>
    **/
    idempotent int getFactionGold(NWObject oFactionMember) throws NotInContextException;

    /**<br>
     * Get the player leader of the faction of which oMemberOfFaction is a member.<br>
     * * Returns OBJECT_INVALID if oMemberOfFaction is not a valid creature,<br>
     * or oMemberOfFaction is a member of a NPC faction.<br>
    **/
    idempotent NWObject getFactionLeader(NWObject oMemberOfFaction) throws NotInContextException;

    /**<br>
     * Get the member of oFactionMember's faction that has taken the fewest hit<br>
     * points of damage.<br>
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.<br>
    **/
    idempotent NWObject getFactionLeastDamagedMember(NWObject oFactionMember, bool bMustBeVisible) throws NotInContextException;

    /**<br>
     * Get the member of oFactionMember's faction that has taken the most hit points<br>
     * of damage.<br>
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.<br>
    **/
    idempotent NWObject getFactionMostDamagedMember(NWObject oFactionMember, bool bMustBeVisible) throws NotInContextException;

    /**<br>
     * Get the most frequent class in the faction - this can be compared with the<br>
     * constants CLASS_TYPE_*.<br>
     * * Return value on error: -1<br>
    **/
    idempotent int getFactionMostFrequentClass(NWObject oFactionMember) throws NotInContextException;

    /**<br>
     * Get the strongest member of oFactionMember's faction.<br>
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.<br>
    **/
    idempotent NWObject getFactionStrongestMember(NWObject oFactionMember, bool bMustBeVisible) throws NotInContextException;

    /**<br>
     * Get the weakest member of oFactionMember's faction.<br>
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.<br>
    **/
    idempotent NWObject getFactionWeakestMember(NWObject oFactionMember, bool bMustBeVisible) throws NotInContextException;

    /**<br>
     * Get the object faction member with the lowest armour class.<br>
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.<br>
    **/
    idempotent NWObject getFactionWorstAC(NWObject oFactionMember, bool bMustBeVisible) throws NotInContextException;

    /**<br>
     * Get oCreature's familiar creature type (FAMILIAR_CREATURE_TYPE_*).<br>
     * * Returns FAMILIAR_CREATURE_TYPE_NONE if oCreature is invalid or does not<br>
     * currently have a familiar.<br>
    **/
    idempotent int getFamiliarCreatureType(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get oCreature's familiar's name.<br>
     * * Returns "" if oCreature is invalid, does not currently<br>
     * have a familiar or if the familiar's name is blank.<br>
    **/
    idempotent string getFamiliarName(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Gets the fog amount in the area specified.<br>
     * nFogType = nFogType specifies wether the Sun, or Moon fog type is returned.<br>
     * Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.<br>
     * If no valid area (or object) is specified, it uses the area of caller.<br>
     * If an object other than an area is specified, will use the area that the object is currently in.<br>
    **/
    idempotent int getFogAmount(int nFogType, NWObject oArea) throws NotInContextException;

    /**<br>
     * Gets the fog color in the area specified.<br>
     * nFogType specifies wether the Sun, or Moon fog type is returned.<br>
     * Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.<br>
     * If no valid area (or object) is specified, it uses the area of caller.<br>
     * If an object other than an area is specified, will use the area that the object is currently in.<br>
    **/
    idempotent int getFogColor(int nFogType, NWObject oArea) throws NotInContextException;

    /**<br>
     * returns the footstep type of the creature specified.<br>
     * The footstep type determines what the creature's footsteps sound<br>
     * like when ever they take a step.<br>
     * returns FOOTSTEP_TYPE_INVALID if used on a non-creature object, or if<br>
     * used on creature that has no footstep sounds by default (e.g. Will-O'-Wisp).<br>
    **/
    idempotent int getFootstepType(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get oTarget's base fortitude saving throw value (this will only work for<br>
     * creatures, doors, and placeables).<br>
     * * Returns 0 if oTarget is invalid.<br>
    **/
    idempotent int getFortitudeSavingThrow(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get the game difficulty (GAME_DIFFICULTY_*).<br>
    **/
    idempotent int getGameDifficulty() throws NotInContextException;

    /**<br>
     * Get the gender of oCreature.<br>
    **/
    idempotent Gender getGender(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the creature that is going to attack oTarget.<br>
     * Note: This value is cleared out at the end of every combat round and should<br>
     * not be used in any case except when getting a "going to be attacked" shout<br>
     * from the master creature (and this creature is a henchman)<br>
     * * Returns OBJECT_INVALID if oTarget is not a valid creature.<br>
    **/
    idempotent NWObject getGoingToBeAttackedBy(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get the amount of gold possessed by oTarget.<br>
    **/
    idempotent int getGold(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get the gold piece value of oItem.<br>
     * * Returns 0 if oItem is not a valid item.<br>
    **/
    idempotent int getGoldPieceValue(NWObject oItem) throws NotInContextException;

    /**<br>
     * Get an integer between 0 and 100 (inclusive) to represent oCreature's<br>
     * Good/Evil alignment<br>
     * (100=good, 0=evil)<br>
     * * Return value if oCreature is not a valid creature: -1<br>
    **/
    idempotent int getGoodEvilValue(NWObject oCreature) throws NotInContextException;

    /**<br>
     * returns the Hardness of a Door or Placeable object.<br>
     * - oObject: a door or placeable object.<br>
     * returns -1 on an error or if used on an object that is<br>
     * neither a door nor a placeable object.<br>
    **/
    idempotent int getHardness(NWObject oObject) throws NotInContextException;

    /**<br>
     * Determine whether oCreature has nFeat, and nFeat is useable.<br>
     * - nFeat: FEAT_*<br>
     * - oCreature<br>
    **/
    idempotent bool getHasFeat(int nFeat, NWObject oCreature) throws NotInContextException;

    /**<br>
     * - nFeat: FEAT_*<br>
     * - oObject<br>
     * * Returns TRUE if oObject has effects on it originating from nFeat.<br>
    **/
    idempotent bool getHasFeatEffect(int nFeat, NWObject oObject) throws NotInContextException;

    /**<br>
     * Determine whether oObject has an inventory.<br>
     * * Returns TRUE for creatures and stores, and checks to see if an item or placeable object is a container.<br>
     * * Returns FALSE for all other object types.<br>
    **/
    idempotent bool getHasInventory(NWObject oObject) throws NotInContextException;

    /**<br>
     * Determine whether oCreature has nSkill, and nSkill is useable.<br>
     * - nSkill: SKILL_*<br>
     * - oCreature<br>
    **/
    idempotent bool getHasSkill(int nSkill, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Determines the number of times that oCreature has nSpell memorised.<br>
     * - nSpell: SPELL_*<br>
     * - oCreature<br>
    **/
    idempotent bool getHasSpell(int nSpell, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Determines whether oObject has any effects applied by nSpell<br>
     * - nSpell: SPELL_*<br>
     * - oObject<br>
     * * The spell id on effects is only valid if the effect is created<br>
     * when the spell script runs. If it is created in a delayed command<br>
     * then the spell id on the effect will be invalid.<br>
    **/
    idempotent bool getHasSpellEffect(int nSpell, NWObject oObject) throws NotInContextException;

    /**<br>
     * Get the henchman belonging to oMaster.<br>
     * * Return OBJECT_INVALID if oMaster does not have a henchman.<br>
     * -nNth: Which henchman to return.<br>
    **/
    idempotent NWObject getHenchman(NWObject oMaster, int nNth) throws NotInContextException;

    /**<br>
     * Get the number of hitdice for oCreature.<br>
     * * Return value if oCreature is not a valid creature: 0<br>
    **/
    idempotent int getHitDice(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Determined whether oItem has been identified.<br>
    **/
    idempotent bool getIdentified(NWObject oItem) throws NotInContextException;

    /**<br>
     * Get the immortal flag on a creature<br>
    **/
    idempotent bool getImmortal(NWObject oTarget) throws NotInContextException;

    /**<br>
     * returns TRUE if the item is flagged as infinite.<br>
     * - oItem: an item.<br>
     * The infinite property affects the buying/selling behavior of the item in a store.<br>
     * An infinite item will still be available to purchase from a store after a player<br>
     * buys the item (non-infinite items will disappear from the store when purchased).<br>
    **/
    idempotent bool getInfiniteFlag(NWObject oItem) throws NotInContextException;

    /**<br>
     * get the item that caused the caller's OnInventoryDisturbed script to fire.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid object.<br>
    **/
    idempotent NWObject getInventoryDisturbItem() throws NotInContextException;

    /**<br>
     * Get the type of disturbance (INVENTORY_DISTURB_*) that caused the caller's<br>
     * OnInventoryDisturbed script to fire.  This will only work for creatures and<br>
     * placeables.<br>
    **/
    idempotent int getInventoryDisturbType() throws NotInContextException;

    /**<br>
     * Returns AREA_ABOVEGROUND if the area oArea is above ground, AREA_UNDERGROUND otherwise.<br>
     * Returns AREA_INVALID, on an error.<br>
    **/
    idempotent bool getIsAreaAboveGround(NWObject oArea) throws NotInContextException;

    /**<br>
     * This will return TRUE if the area is flagged as either interior or underground.<br>
    **/
    idempotent bool getIsAreaInterior(NWObject oArea) throws NotInContextException;

    /**<br>
     * Returns AREA_NATURAL if the area oArea is natural, AREA_ARTIFICIAL otherwise.<br>
     * Returns AREA_INVALID, on an error.<br>
    **/
    idempotent bool getIsAreaNatural(NWObject oArea) throws NotInContextException;

    /**<br>
     * Is this creature able to be disarmed? (checks disarm flag on creature, and if<br>
     * the creature actually has a weapon equipped in their right hand that is droppable)<br>
    **/
    idempotent bool getIsCreatureDisarmable(NWObject oCreature) throws NotInContextException;

    /**<br>
     * * Returns TRUE if oCreature is the Dungeon Master.<br>
     * Note: This will return FALSE if oCreature is a DM Possessed creature.<br>
     * To determine if oCreature is a DM Possessed creature, use GetIsDMPossessed()<br>
    **/
    idempotent bool getIsDM(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Returns TRUE if the creature oCreature is currently possessed by a DM character.<br>
     * Returns FALSE otherwise.<br>
     * Note: GetIsDMPossessed() will return FALSE if oCreature is the DM character.<br>
     * To determine if oCreature is a DM character use GetIsDM()<br>
    **/
    idempotent bool getIsDMPossessed(NWObject oCreature) throws NotInContextException;

    /**<br>
     * * Returns TRUE if it is currently dawn.<br>
    **/
    idempotent bool getIsDawn() throws NotInContextException;

    /**<br>
     * * Returns TRUE if it is currently day.<br>
    **/
    idempotent bool getIsDay() throws NotInContextException;

    /**<br>
     * * Returns TRUE if oCreature is a dead NPC, dead PC or a dying PC.<br>
    **/
    idempotent bool getIsDead(NWObject oCreature) throws NotInContextException;

    /**<br>
     * - oTargetDoor<br>
     * - nDoorAction: DOOR_ACTION_*<br>
     * * Returns TRUE if nDoorAction can be performed on oTargetDoor.<br>
    **/
    idempotent bool getIsDoorActionPossible(NWObject oTargetDoor, DoorAction tDoorAction) throws NotInContextException;

    /**<br>
     * * Returns TRUE if it is currently dusk.<br>
    **/
    idempotent bool getIsDusk() throws NotInContextException;

    /**<br>
     * * Returns TRUE if eEffect is a valid effect. The effect must have been applied to<br>
     * * an object or else it will return FALSE<br>
    **/
    idempotent bool getIsEffectValid(NWEffect eEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * * Returns TRUE if oCreature was spawned from an encounter.<br>
    **/
    idempotent bool getIsEncounterCreature(NWObject oCreature) throws NotInContextException;

    /**<br>
     * * Returns TRUE if oSource considers oTarget as an enemy.<br>
    **/
    idempotent bool getIsEnemy(NWObject oTarget, NWObject oSource) throws NotInContextException;

    /**<br>
     * * Returns TRUE if oSource considers oTarget as a friend.<br>
    **/
    idempotent bool getIsFriend(NWObject oTarget, NWObject oSource) throws NotInContextException;

    /**<br>
     * - oCreature<br>
     * - nImmunityType: IMMUNITY_TYPE_*<br>
     * - oVersus: if this is specified, then we also check for the race and<br>
     * alignment of oVersus<br>
     * * Returns TRUE if oCreature has immunity of type nImmunity versus oVersus.<br>
    **/
    idempotent bool getIsImmune(NWObject oCreature, ImmunityType tImmunityType, NWObject oVersus) throws NotInContextException;

    /**<br>
     * * Returns TRUE if oCreature is in combat.<br>
    **/
    idempotent bool getIsInCombat(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Is this creature in the given subarea? (trigger, area of effect object, etc..)<br>
     * This function will tell you if the creature has triggered an onEnter event,<br>
     * not if it is physically within the space of the subarea<br>
    **/
    idempotent bool getIsInSubArea(NWObject oCreature, NWObject oSubArea) throws NotInContextException;

    /**<br>
     * if the item property is valid this will return true<br>
    **/
    idempotent bool getIsItemPropertyValid(NWItemProperty ipProperty) throws NotInContextException, InvalidItemPropertyException;

    /**<br>
     * * Returns TRUE if oObject is listening for something<br>
    **/
    idempotent bool getIsListening(NWObject oObject) throws NotInContextException;

    /**<br>
     * * Returns TRUE if oSource considers oTarget as neutral.<br>
    **/
    idempotent bool getIsNeutral(NWObject oTarget, NWObject oSource) throws NotInContextException;

    /**<br>
     * * Returns TRUE if it is currently night.<br>
    **/
    idempotent bool getIsNight() throws NotInContextException;

    /**<br>
     * * Returns TRUE if oObject is a valid object.<br>
    **/
    idempotent bool getIsObjectValid(NWObject oObject) throws NotInContextException;

    /**<br>
     * * Returns TRUE if oObject (which is a placeable or a door) is currently open.<br>
    **/
    idempotent bool getIsOpen(NWObject oObject) throws NotInContextException;

    /**<br>
     * * Returns TRUE if oCreature is a Player Controlled character.<br>
    **/
    idempotent bool getIsPC(NWObject oCreature) throws NotInContextException;

    /**<br>
     * - oPlaceable<br>
     * - nPlaceableAction: PLACEABLE_ACTION_*<br>
     * * Returns TRUE if nPlacebleAction is valid for oPlaceable.<br>
    **/
    idempotent bool getIsPlaceableObjectActionPossible(NWObject oPlaceable, PlaceableAction tPlaceableAction) throws NotInContextException;

    /**<br>
     * * Returns TRUE if oCreature is of a playable racial type.<br>
    **/
    idempotent bool getIsPlayableRacialType(NWObject oCreature) throws NotInContextException;

    /**<br>
     * This will return TRUE if the creature running the script is a familiar currently<br>
     * possessed by his master.<br>
     * returns FALSE if not or if the creature object is invalid<br>
    **/
    idempotent bool getIsPossessedFamiliar(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Determine whether oSource has a friendly reaction towards oTarget, depending<br>
     * on the reputation, PVP setting and (if both oSource and oTarget are PCs),<br>
     * oSource's Like/Dislike setting for oTarget.<br>
     * Note: If you just want to know how two objects feel about each other in terms<br>
     * of faction and personal reputation, use GetIsFriend() instead.<br>
     * * Returns TRUE if oSource has a friendly reaction towards oTarget<br>
    **/
    idempotent bool getIsReactionTypeFriendly(NWObject oTarget, NWObject oSource) throws NotInContextException;

    /**<br>
     * Determine whether oSource has a Hostile reaction towards oTarget, depending<br>
     * on the reputation, PVP setting and (if both oSource and oTarget are PCs),<br>
     * oSource's Like/Dislike setting for oTarget.<br>
     * Note: If you just want to know how two objects feel about each other in terms<br>
     * of faction and personal reputation, use GetIsEnemy() instead.<br>
     * * Returns TRUE if oSource has a hostile reaction towards oTarget<br>
    **/
    idempotent bool getIsReactionTypeHostile(NWObject oTarget, NWObject oSource) throws NotInContextException;

    /**<br>
     * Determine whether oSource has a neutral reaction towards oTarget, depending<br>
     * on the reputation, PVP setting and (if both oSource and oTarget are PCs),<br>
     * oSource's Like/Dislike setting for oTarget.<br>
     * Note: If you just want to know how two objects feel about each other in terms<br>
     * of faction and personal reputation, use GetIsNeutral() instead.<br>
     * * Returns TRUE if oSource has a neutral reaction towards oTarget<br>
    **/
    idempotent bool getIsReactionTypeNeutral(NWObject oTarget, NWObject oSource) throws NotInContextException;

    /**<br>
     * * Returns TRUE if oCreature is resting.<br>
    **/
    idempotent bool getIsResting(NWObject oCreature) throws NotInContextException;

    /**<br>
     * ***********************  END OF ITEM PROPERTY FUNCTIONS  **************************<br>
     * <br>
     * Returns true if 1d20 roll + skill rank is greater than or equal to difficulty<br>
     * - oTarget: the creature using the skill<br>
     * - nSkill: the skill being used<br>
     * - nDifficulty: Difficulty class of skill<br>
    **/
    idempotent bool getIsSkillSuccessful(NWObject oTarget, int nSkill, int nDifficulty) throws NotInContextException;

    /**<br>
     * Note: Only placeables, doors and triggers can be trapped.<br>
     * * Returns TRUE if oObject is trapped.<br>
    **/
    idempotent bool getIsTrapped(NWObject oObject) throws NotInContextException;

    /**<br>
     * * Returns TRUE if the weapon equipped is capable of damaging oVersus.<br>
    **/
    idempotent bool getIsWeaponEffective(NWObject oVersus, bool bOffHand) throws NotInContextException;

    /**<br>
     * Get the Armour Class of oItem.<br>
     * * Return 0 if the oItem is not a valid item, or if oItem has no armour value.<br>
    **/
    idempotent int getItemACValue(NWObject oItem) throws NotInContextException;

    /**<br>
     * Use this in an OnItemActivated module script to get the item that was activated.<br>
    **/
    idempotent NWObject getItemActivated() throws NotInContextException;

    /**<br>
     * Use this in an OnItemActivated module script to get the item's target.<br>
    **/
    idempotent NWObject getItemActivatedTarget() throws NotInContextException;

    /**<br>
     * Use this in an OnItemActivated module script to get the location of the item's<br>
     * target.<br>
    **/
    idempotent NWLocation getItemActivatedTargetLocation() throws NotInContextException;

    /**<br>
     * Use this in an OnItemActivated module script to get the creature that<br>
     * activated the item.<br>
    **/
    idempotent NWObject getItemActivator() throws NotInContextException;

    /**<br>
     * Queries the current value of the appearance settings on an item. The parameters are<br>
     * identical to those of CopyItemAndModify().<br>
    **/
    idempotent int getItemAppearance(NWObject oItem, int nType, int nIndex) throws NotInContextException;

    /**<br>
     * Returns charges left on an item<br>
     * - oItem: item to query<br>
    **/
    idempotent int getItemCharges(NWObject oItem) throws NotInContextException;

    /**<br>
     * Returns TRUE if the item is cursed and cannot be dropped<br>
    **/
    idempotent bool getItemCursedFlag(NWObject oItem) throws NotInContextException;

    /**<br>
     * Determines whether oItem has nProperty.<br>
     * - oItem<br>
     * - nProperty: ITEM_PROPERTY_*<br>
     * * Returns FALSE if oItem is not a valid item, or if oItem does not have<br>
     * nProperty.<br>
    **/
    idempotent bool getItemHasItemProperty(NWObject oItem, int nProperty) throws NotInContextException;

    /**<br>
     * Get the object which is in oCreature's specified inventory slot<br>
     * - nInventorySlot: INVENTORY_SLOT_*<br>
     * - oCreature<br>
     * * Returns OBJECT_INVALID if oCreature is not a valid creature or there is no<br>
     * item in nInventorySlot.<br>
    **/
    idempotent NWObject getItemInSlot(InventorySlot tInventorySlot, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the object possessed by oCreature with the tag sItemTag<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getItemPossessedBy(NWObject oCreature, string sItemTag) throws NotInContextException;

    /**<br>
     * Get the possessor of oItem<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getItemPossessor(NWObject oItem) throws NotInContextException;

    /**<br>
     * Returns the Cost Table number of the item property. See the 2DA files for value definitions.<br>
    **/
    idempotent int getItemPropertyCostTable(NWItemProperty iProp) throws NotInContextException, InvalidItemPropertyException;

    /**<br>
     * Returns the Cost Table value (index of the cost table) of the item property.<br>
     * See the 2DA files for value definitions.<br>
    **/
    idempotent int getItemPropertyCostTableValue(NWItemProperty iProp) throws NotInContextException, InvalidItemPropertyException;

    /**<br>
     * will return the duration type of the item property<br>
    **/
    idempotent DurationType getItemPropertyDurationType(NWItemProperty ip) throws NotInContextException, InvalidItemPropertyException;

    /**<br>
     * Returns the Param1 number of the item property. See the 2DA files for value definitions.<br>
    **/
    idempotent int getItemPropertyParam1(NWItemProperty iProp) throws NotInContextException, InvalidItemPropertyException;

    /**<br>
     * Returns the Param1 value of the item property. See the 2DA files for value definitions.<br>
    **/
    idempotent int getItemPropertyParam1Value(NWItemProperty iProp) throws NotInContextException, InvalidItemPropertyException;

    /**<br>
     * Returns the SubType number of the item property. See the 2DA files for value definitions.<br>
    **/
    idempotent int getItemPropertySubType(NWItemProperty iProperty) throws NotInContextException, InvalidItemPropertyException;

    /**<br>
     * will return the item property type (ie. holy avenger)<br>
    **/
    idempotent int getItemPropertyType(NWItemProperty ip) throws NotInContextException, InvalidItemPropertyException;

    /**<br>
     * Returns stack size of an item<br>
     * - oItem: item to query<br>
    **/
    idempotent int getItemStackSize(NWObject oItem) throws NotInContextException;

    /**<br>
     * Get the experience assigned in the journal editor for szPlotID.<br>
    **/
    idempotent int getJournalQuestExperience(string szPlotID) throws NotInContextException;

    /**<br>
     * Get the feedback message that will be displayed when trying to unlock the object oObject.<br>
     * - oObject: a door or placeable.<br>
     * Returns an empty string "" on an error or if the game's default feedback message is being used<br>
    **/
    idempotent string getKeyRequiredFeedback(NWObject oObject) throws NotInContextException;

    /**<br>
     * Get the last command (ASSOCIATE_COMMAND_*) issued to oAssociate.<br>
    **/
    idempotent AssociateCommand getLastAssociateCommand(NWObject oAssociate) throws NotInContextException;

    /**<br>
     * Get the attack mode (COMBAT_MODE_*) of oCreature's last attack.<br>
     * This only works when oCreature is in combat.<br>
    **/
    idempotent CombatMode getLastAttackMode(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the attack type (SPECIAL_ATTACK_*) of oCreature's last attack.<br>
     * This only works when oCreature is in combat.<br>
    **/
    idempotent SpecialAttack getLastAttackType(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the last attacker of oAttackee.  This should only be used ONLY in the<br>
     * OnAttacked events for creatures, placeables and doors.<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getLastAttacker(NWObject oAttackee) throws NotInContextException;

    /**<br>
     * Use this in an OnClosed script to get the object that closed the door or placeable.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid door or placeable.<br>
    **/
    idempotent NWObject getLastClosedBy() throws NotInContextException;

    /**<br>
     * Get the last object that damaged oObject<br>
     * * Returns OBJECT_INVALID if the passed in object is not a valid object.<br>
    **/
    idempotent NWObject getLastDamager(NWObject oObject) throws NotInContextException;

    /**<br>
     * Get the last object that disarmed the trap on the caller.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid placeable, trigger or<br>
     * door.<br>
    **/
    idempotent NWObject getLastDisarmed() throws NotInContextException;

    /**<br>
     * Get the last object that disturbed the inventory of the caller.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid creature or placeable.<br>
    **/
    idempotent NWObject getLastDisturbed() throws NotInContextException;

    /**<br>
     * Get the last object that was sent as a GetLastAttacker(), GetLastDamager(),<br>
     * GetLastSpellCaster() (for a hostile spell), or GetLastDisturbed() (when a<br>
     * creature is pickpocketed).<br>
     * Note: Return values may only ever be:<br>
     * 1) A Creature<br>
     * 2) Plot Characters will never have this value set<br>
     * 3) Area of Effect Objects will return the AOE creator if they are registered<br>
     * as this value, otherwise they will return INVALID_OBJECT_ID<br>
     * 4) Traps will not return the creature that set the trap.<br>
     * 5) This value will never be overwritten by another non-creature object.<br>
     * 6) This value will never be a dead/destroyed creature<br>
    **/
    idempotent NWObject getLastHostileActor(NWObject oVictim) throws NotInContextException;

    /**<br>
     * Get the object that killed the caller.<br>
    **/
    idempotent NWObject getLastKiller() throws NotInContextException;

    /**<br>
     * Get the last object that locked the caller.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid door or placeable.<br>
    **/
    idempotent NWObject getLastLocked() throws NotInContextException;

    /**<br>
     * Get the last creature that opened the caller.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid door, placeable or store.<br>
    **/
    idempotent NWObject getLastOpenedBy() throws NotInContextException;

    /**<br>
     * Get the last PC that has rested in the module.<br>
    **/
    idempotent NWObject getLastPCRested() throws NotInContextException;

    /**<br>
     * Gets the last player character to cancel from a cutscene.<br>
    **/
    idempotent NWObject getLastPCToCancelCutscene() throws NotInContextException;

    /**<br>
     * Use this in an OnPerception script to get the object that was perceived.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid creature.<br>
    **/
    idempotent NWObject getLastPerceived() throws NotInContextException;

    /**<br>
     * Use this in an OnPerception script to determine whether the object that was<br>
     * perceived was heard.<br>
    **/
    idempotent bool getLastPerceptionHeard() throws NotInContextException;

    /**<br>
     * Use this in an OnPerception script to determine whether the object that was<br>
     * perceived has become inaudible.<br>
    **/
    idempotent bool getLastPerceptionInaudible() throws NotInContextException;

    /**<br>
     * Use this in an OnPerception script to determine whether the object that was<br>
     * perceived was seen.<br>
    **/
    idempotent bool getLastPerceptionSeen() throws NotInContextException;

    /**<br>
     * Use this in an OnPerception script to determine whether the object that was<br>
     * perceived has vanished.<br>
    **/
    idempotent bool getLastPerceptionVanished() throws NotInContextException;

    /**<br>
     * Use this in an OnPlayerDeath module script to get the last player that died.<br>
    **/
    idempotent NWObject getLastPlayerDied() throws NotInContextException;

    /**<br>
     * Use this in an OnPlayerDying module script to get the last player who is dying.<br>
    **/
    idempotent NWObject getLastPlayerDying() throws NotInContextException;

    /**<br>
     * Use this in an OnRespawnButtonPressed module script to get the object id of<br>
     * the player who last pressed the respawn button.<br>
    **/
    idempotent NWObject getLastRespawnButtonPresser() throws NotInContextException;

    /**<br>
     * Determine the type (REST_EVENTTYPE_REST_*) of the last rest event (as<br>
     * returned from the OnPCRested module event).<br>
    **/
    idempotent int getLastRestEventType() throws NotInContextException;

    /**<br>
     * Use this in a conversation script to get the person with whom you are conversing.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid creature.<br>
    **/
    idempotent NWObject getLastSpeaker() throws NotInContextException;

    /**<br>
     * This is for use in a "Spell Cast" script, it gets the ID of the spell that<br>
     * was cast.<br>
    **/
    idempotent int getLastSpell() throws NotInContextException;

    /**<br>
     * Returns the class that the spellcaster cast the<br>
     * spell as.<br>
     * - Returns CLASS_TYPE_INVALID if the caster has<br>
     * no valid class (placeables, etc...)<br>
    **/
    idempotent int getLastSpellCastClass() throws NotInContextException;

    /**<br>
     * This is for use in a "Spell Cast" script, it gets who cast the spell.<br>
     * The spell could have been cast by a creature, placeable or door.<br>
     * * Returns OBJECT_INVALID if the caller is not a creature, placeable or door.<br>
    **/
    idempotent NWObject getLastSpellCaster() throws NotInContextException;

    /**<br>
     * Use this in a SpellCast script to determine whether the spell was considered<br>
     * harmful.<br>
     * * Returns TRUE if the last spell cast was harmful.<br>
    **/
    idempotent bool getLastSpellHarmful() throws NotInContextException;

    /**<br>
     * Get the last trap detected by oTarget.<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getLastTrapDetected(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get the last object that unlocked the caller.<br>
     * * Returns OBJECT_INVALID if the caller is not a valid door or placeable.<br>
    **/
    idempotent NWObject getLastUnlocked() throws NotInContextException;

    /**<br>
     * Get the last object that used the placeable object that is calling this function.<br>
     * * Returns OBJECT_INVALID if it is called by something other than a placeable or<br>
     * a door.<br>
    **/
    idempotent NWObject getLastUsedBy() throws NotInContextException;

    /**<br>
     * Get the last weapon that oCreature used in an attack.<br>
     * * Returns OBJECT_INVALID if oCreature did not attack, or has no weapon equipped.<br>
    **/
    idempotent NWObject getLastWeaponUsed(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get an integer between 0 and 100 (inclusive) to represent oCreature's<br>
     * Law/Chaos alignment<br>
     * (100=law, 0=chaos)<br>
     * * Return value if oCreature is not a valid creature: -1<br>
    **/
    idempotent int getLawChaosValue(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Determine the levels that oCreature holds in nClassType.<br>
     * - nClassType: CLASS_TYPE_*<br>
     * - oCreature<br>
    **/
    idempotent int getLevelByClass(int nClassType, NWObject oCreature) throws NotInContextException;

    /**<br>
     * A creature can have up to three classes.  This function determines the<br>
     * creature's class level based on nClass Position.<br>
     * - nClassPosition: 1, 2 or 3<br>
     * - oCreature<br>
     * * Returns 0 if oCreature does not have a class in nClassPosition<br>
     * (i.e. a single-class creature will only have a value in nClassLocation=1)<br>
     * or if oCreature is not a valid creature.<br>
    **/
    idempotent int getLevelByPosition(int nClassPosition, NWObject oCreature) throws NotInContextException;

    /**<br>
     * In an onConversation script this gets the number of the string pattern<br>
     * matched (the one that triggered the script).<br>
     * * Returns -1 if no string matched<br>
    **/
    idempotent int getListenPatternNumber() throws NotInContextException;

    /**<br>
     * Get oObject's local float variable sVarName<br>
     * * Return value on error: 0.0f<br>
    **/
    idempotent double getLocalFloat(NWObject oObject, string sVarName) throws NotInContextException;

    /**<br>
     * Get oObject's local integer variable sVarName<br>
     * * Return value on error: 0<br>
    **/
    idempotent int getLocalInt(NWObject oObject, string sVarName) throws NotInContextException;

    /**<br>
     * Get oObject's local location variable sVarname<br>
    **/
    idempotent NWLocation getLocalLocation(NWObject oObject, string sVarName) throws NotInContextException;

    /**<br>
     * Get oObject's local object variable sVarName<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getLocalObject(NWObject oObject, string sVarName) throws NotInContextException;

    /**<br>
     * Get oObject's local string variable sVarName<br>
     * * Return value on error: ""<br>
    **/
    idempotent string getLocalString(NWObject oObject, string sVarName) throws NotInContextException;

    /**<br>
     * Get the location of oObject.<br>
    **/
    idempotent NWLocation getLocation(NWObject oObject) throws NotInContextException;

    /**<br>
     * * Returns TRUE if a specific key is required to open the lock on oObject.<br>
    **/
    idempotent bool getLockKeyRequired(NWObject oObject) throws NotInContextException;

    /**<br>
     * Get the tag of the key that will open the lock on oObject.<br>
    **/
    idempotent string getLockKeyTag(NWObject oObject) throws NotInContextException;

    /**<br>
     * Get the DC for locking oObject.<br>
    **/
    idempotent int getLockLockDC(NWObject oObject) throws NotInContextException;

    /**<br>
     * * Returns TRUE if the lock on oObject is lockable.<br>
    **/
    idempotent bool getLockLockable(NWObject oObject) throws NotInContextException;

    /**<br>
     * Get the DC for unlocking oObject.<br>
    **/
    idempotent int getLockUnlockDC(NWObject oObject) throws NotInContextException;

    /**<br>
     * Get the locked state of oTarget, which can be a door or a placeable object.<br>
    **/
    idempotent bool getLocked(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Returns the lootable state of a creature.<br>
    **/
    idempotent bool getLootable(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the master of oAssociate.<br>
    **/
    idempotent NWObject getMaster(NWObject oAssociate) throws NotInContextException;

    /**<br>
     * Get the appropriate matched string (this should only be used in<br>
     * OnConversation scripts).<br>
     * * Returns the appropriate matched string, otherwise returns ""<br>
    **/
    idempotent string getMatchedSubstring(int nString) throws NotInContextException;

    /**<br>
     * Get the number of string parameters available.<br>
     * * Returns -1 if no string matched (this could be because of a dialogue event)<br>
    **/
    idempotent int getMatchedSubstringsCount() throws NotInContextException;

    /**<br>
     * Gets the maximum number of henchmen<br>
    **/
    idempotent int getMaxHenchmen() throws NotInContextException;

    /**<br>
     * Get the maximum hitpoints of oObject<br>
     * * Return value on error: 0<br>
    **/
    idempotent int getMaxHitPoints(NWObject oObject) throws NotInContextException;

    /**<br>
     * Get the metamagic type (METAMAGIC_*) of the last spell cast by the caller<br>
     * * Return value if the caster is not a valid object: -1<br>
    **/
    idempotent MetaMagic getMetaMagicFeat() throws NotInContextException;

    /**<br>
     * Get the module.<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getModule() throws NotInContextException;

    /**<br>
     * Use this in an OnItemAcquired script to get the item that was acquired.<br>
     * * Returns OBJECT_INVALID if the module is not valid.<br>
    **/
    idempotent NWObject getModuleItemAcquired() throws NotInContextException;

    /**<br>
     * Gets the object that acquired the module item.  May be a creature, item, or placeable<br>
    **/
    idempotent NWObject getModuleItemAcquiredBy() throws NotInContextException;

    /**<br>
     * Use this in an OnItemAcquired script to get the creatre that previously<br>
     * possessed the item.<br>
     * * Returns OBJECT_INVALID if the item was picked up from the ground.<br>
    **/
    idempotent NWObject getModuleItemAcquiredFrom() throws NotInContextException;

    /**<br>
     * in an onItemAcquired script, returns the size of the stack of the item<br>
     * that was just acquired.<br>
     * * returns the stack size of the item acquired<br>
    **/
    idempotent int getModuleItemAcquiredStackSize() throws NotInContextException;

    /**<br>
     * Use this in an OnItemLost script to get the item that was lost/dropped.<br>
     * * Returns OBJECT_INVALID if the module is not valid.<br>
    **/
    idempotent NWObject getModuleItemLost() throws NotInContextException;

    /**<br>
     * Use this in an OnItemLost script to get the creature that lost the item.<br>
     * * Returns OBJECT_INVALID if the module is not valid.<br>
    **/
    idempotent NWObject getModuleItemLostBy() throws NotInContextException;

    /**<br>
     * Get the module's name in the language of the server that's running it.<br>
     * * If there is no entry for the language of the server, it will return an<br>
     * empty string<br>
    **/
    idempotent string getModuleName() throws NotInContextException;

    /**<br>
     * Get the XP scale being used for the module.<br>
    **/
    idempotent int getModuleXPScale() throws NotInContextException;

    /**<br>
     * Get oCreature's movement rate.<br>
     * * Returns 0 if oCreature is invalid.<br>
    **/
    idempotent int getMovementRate(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the name of oObject.<br>
     * - bOriginalName:  if set to true any new name specified via a SetName scripting command<br>
     * is ignored and the original object's name is returned instead.<br>
    **/
    idempotent string getName(NWObject oObject, bool bOriginalName) throws NotInContextException;

    /**<br>
     * Get the creature nearest to oTarget, subject to all the criteria specified.<br>
     * - nFirstCriteriaType: CREATURE_TYPE_*<br>
     * - nFirstCriteriaValue:<br>
     * -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS<br>
     * -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT<br>
     * or CREATURE_TYPE_HAS_SPELL_EFFECT<br>
     * -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE<br>
     * -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION<br>
     * -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was<br>
     * CREATURE_TYPE_PLAYER_CHAR<br>
     * -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE<br>
     * -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION<br>
     * For example, to get the nearest PC, use:<br>
     * (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)<br>
     * - oTarget: We're trying to find the creature of the specified type that is<br>
     * nearest to oTarget<br>
     * - nNth: We don't have to find the first nearest: we can find the Nth nearest...<br>
     * - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to<br>
     * further specify the type of creature that we are looking for.<br>
     * - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue<br>
     * to further specify the type of creature that we are looking for.<br>
     * - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to<br>
     * further specify the type of creature that we are looking for.<br>
     * - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to<br>
     * further specify the type of creature that we are looking for.<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getNearestCreature(int nFirstCriteriaType, int nFirstCriteriaValue, NWObject oTarget, int nNth, int nSecondCriteriaType, int nSecondCriteriaValue, int nThirdCriteriaType, int nThirdCriteriaValue) throws NotInContextException;

    /**<br>
     * Get the creature nearest to lLocation, subject to all the criteria specified.<br>
     * - nFirstCriteriaType: CREATURE_TYPE_*<br>
     * - nFirstCriteriaValue:<br>
     * -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS<br>
     * -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT<br>
     * or CREATURE_TYPE_HAS_SPELL_EFFECT<br>
     * -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE<br>
     * -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION<br>
     * -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was<br>
     * CREATURE_TYPE_PLAYER_CHAR<br>
     * -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE<br>
     * -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION<br>
     * For example, to get the nearest PC, use<br>
     * (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)<br>
     * - lLocation: We're trying to find the creature of the specified type that is<br>
     * nearest to lLocation<br>
     * - nNth: We don't have to find the first nearest: we can find the Nth nearest....<br>
     * - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to<br>
     * further specify the type of creature that we are looking for.<br>
     * - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue<br>
     * to further specify the type of creature that we are looking for.<br>
     * - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to<br>
     * further specify the type of creature that we are looking for.<br>
     * - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to<br>
     * further specify the type of creature that we are looking for.<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getNearestCreatureToLocation(int nFirstCriteriaType, int nFirstCriteriaValue, NWLocation lLocation, int nNth, int nSecondCriteriaType, int nSecondCriteriaValue, int nThirdCriteriaType, int nThirdCriteriaValue) throws NotInContextException;

    /**<br>
     * Get the Nth object nearest to oTarget that is of the specified type.<br>
     * - nObjectType: OBJECT_TYPE_*<br>
     * - oTarget<br>
     * - nNth<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getNearestObject(ObjectType tObjectType, NWObject oTarget, int nNth) throws NotInContextException;

    /**<br>
     * Get the nth Object nearest to oTarget that has sTag as its tag.<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getNearestObjectByTag(string sTag, NWObject oTarget, int nNth) throws NotInContextException;

    /**<br>
     * Get the nNth object nearest to lLocation that is of the specified type.<br>
     * - nObjectType: OBJECT_TYPE_*<br>
     * - lLocation<br>
     * - nNth<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getNearestObjectToLocation(ObjectType tObjectType, NWLocation lLocation, int nNth) throws NotInContextException;

    /**<br>
     * Get the trap nearest to oTarget.<br>
     * Note : "trap objects" are actually any trigger, placeable or door that is<br>
     * trapped in oTarget's area.<br>
     * - oTarget<br>
     * - nTrapDetected: if this is TRUE, the trap returned has to have been detected<br>
     * by oTarget.<br>
    **/
    idempotent NWObject getNearestTrapToObject(NWObject oTarget, bool bTrapDetected) throws NotInContextException;

    /**<br>
     * Get the number of stacked items that oItem comprises.<br>
    **/
    idempotent int getNumStackedItems(NWObject oItem) throws NotInContextException;

    /**<br>
     * Get the nNth object with the specified tag.<br>
     * - sTag<br>
     * - nNth: the nth object with this tag may be requested<br>
     * * Returns OBJECT_INVALID if the object cannot be found.<br>
     * Note: The module cannot be retrieved by GetObjectByTag(), use GetModule() instead.<br>
    **/
    idempotent NWObject getObjectByTag(string sTag, int nNth) throws NotInContextException;

    /**<br>
     * Determine whether oSource hears oTarget.<br>
     * NOTE: This *only* works on creatures, as visibility lists are not<br>
     * maintained for non-creature objects.<br>
    **/
    idempotent bool getObjectHeard(NWObject oTarget, NWObject oSource) throws NotInContextException;

    /**<br>
     * Determine whether oSource sees oTarget.<br>
     * NOTE: This *only* works on creatures, as visibility lists are not<br>
     * maintained for non-creature objects.<br>
    **/
    idempotent bool getObjectSeen(NWObject oTarget, NWObject oSource) throws NotInContextException;

    /**<br>
     * Get the object type (OBJECT_TYPE_*) of oTarget<br>
     * * Return value if oTarget is not a valid object: -1<br>
    **/
    idempotent ObjectType getObjectType(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get the last player chat(text) message that was sent.<br>
     * Should only be called from a module's OnPlayerChat event script.<br>
     * * Returns empty string "" on error.<br>
     * Note: Private tells do not trigger a OnPlayerChat event.<br>
    **/
    idempotent string getPCChatMessage() throws NotInContextException;

    /**<br>
     * Get the PC that sent the last player chat(text) message.<br>
     * Should only be called from a module's OnPlayerChat event script.<br>
     * * Returns OBJECT_INVALID on error.<br>
     * Note: Private tells do not trigger a OnPlayerChat event.<br>
    **/
    idempotent NWObject getPCChatSpeaker() throws NotInContextException;

    /**<br>
     * Get the volume of the last player chat(text) message that was sent.<br>
     * Returns one of the following TALKVOLUME_* constants based on the volume setting<br>
     * that the player used to send the chat message.<br>
     * TALKVOLUME_TALK<br>
     * TALKVOLUME_WHISPER<br>
     * TALKVOLUME_SHOUT<br>
     * TALKVOLUME_SILENT_SHOUT (used for DM chat channel)<br>
     * TALKVOLUME_PARTY<br>
     * Should only be called from a module's OnPlayerChat event script.<br>
     * * Returns -1 on error.<br>
     * Note: Private tells do not trigger a OnPlayerChat event.<br>
    **/
    idempotent int getPCChatVolume() throws NotInContextException;

    /**<br>
     * Get the IP address from which oPlayer has connected.<br>
    **/
    idempotent string getPCIPAddress(NWObject oPlayer) throws NotInContextException;

    /**<br>
     * Use this to get the item last equipped by a player character in OnPlayerEquipItem..<br>
    **/
    idempotent NWObject getPCItemLastEquipped() throws NotInContextException;

    /**<br>
     * Use this to get the player character who last equipped an item in OnPlayerEquipItem..<br>
    **/
    idempotent NWObject getPCItemLastEquippedBy() throws NotInContextException;

    /**<br>
     * Use this to get the item last unequipped by a player character in OnPlayerEquipItem..<br>
    **/
    idempotent NWObject getPCItemLastUnequipped() throws NotInContextException;

    /**<br>
     * Use this to get the player character who last unequipped an item in OnPlayerUnEquipItem..<br>
    **/
    idempotent NWObject getPCItemLastUnequippedBy() throws NotInContextException;

    /**<br>
     * Get the last PC that levelled up.<br>
    **/
    idempotent NWObject getPCLevellingUp() throws NotInContextException;

    /**<br>
     * Get the name of oPlayer.<br>
    **/
    idempotent string getPCPlayerName(NWObject oPlayer) throws NotInContextException;

    /**<br>
     * Get the public part of the CD Key that oPlayer used when logging in.<br>
     * - nSinglePlayerCDKey: If set to TRUE, the player's public CD Key will<br>
     * be returned when the player is playing in single player mode<br>
     * (otherwise returns an empty string in single player mode).<br>
    **/
    idempotent string getPCPublicCDKey(NWObject oPlayer, bool bSinglePlayerCDKey) throws NotInContextException;

    /**<br>
     * Get the PC that is involved in the conversation.<br>
     * * Returns OBJECT_INVALID on error.<br>
    **/
    idempotent NWObject getPCSpeaker() throws NotInContextException;

    /**<br>
     * Returns the creature's currently set PhenoType (body type).<br>
    **/
    idempotent PhenoType getPhenoType(NWObject oCreature) throws NotInContextException;

    /**<br>
     * returns TRUE if the item CAN be pickpocketed<br>
    **/
    idempotent bool getPickpocketableFlag(NWObject oItem) throws NotInContextException;

    /**<br>
     * * Returns TRUE if the illumination for oPlaceable is on<br>
    **/
    idempotent int getPlaceableIllumination(NWObject oPlaceable) throws NotInContextException;

    /**<br>
     * Get the last object that default clicked (left clicked) on the placeable object<br>
     * that is calling this function.<br>
     * Should only be called from a placeables OnClick event.<br>
     * * Returns OBJECT_INVALID if it is called by something other than a placeable.<br>
    **/
    idempotent NWObject getPlaceableLastClickedBy() throws NotInContextException;

    /**<br>
     * Determine whether oTarget is a plot object.<br>
    **/
    idempotent bool getPlotFlag(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get the PortraitId of oTarget.<br>
     * - oTarget: the object for which you are getting the portrait Id.<br>
     * Returns: The Portrait Id number being used for the object oTarget.<br>
     * The Portrait Id refers to the row number of the Portraits.2da<br>
     * that this portrait is from.<br>
     * If a custom portrait is being used, oTarget is a player object,<br>
     * or on an error returns PORTRAIT_INVALID. In these instances<br>
     * try using GetPortraitResRef() instead.<br>
    **/
    idempotent int getPortraitId(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get the Portrait ResRef of oTarget.<br>
     * - oTarget: the object for which you are getting the portrait ResRef.<br>
     * Returns: The Portrait ResRef being used for the object oTarget.<br>
     * The Portrait ResRef will not include a trailing size letter.<br>
    **/
    idempotent string getPortraitResRef(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get the position of oTarget<br>
     * * Return value on error: vector (0.0f, 0.0f, 0.0f)<br>
    **/
    idempotent NWVector getPosition(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get the racial type (RACIAL_TYPE_*) of oCreature<br>
     * * Return value if oCreature is not a valid creature: RACIAL_TYPE_INVALID<br>
    **/
    idempotent RacialType getRacialType(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Use this in spell scripts to get nDamage adjusted by oTarget's reflex and<br>
     * evasion saves.<br>
     * - nDamage<br>
     * - oTarget<br>
     * - nDC: Difficulty check<br>
     * - nSaveType: SAVING_THROW_TYPE_*<br>
     * - oSaveVersus<br>
    **/
    idempotent int getReflexAdjustedDamage(int nDamage, NWObject oTarget, int nDC, SaveType tSaveType, NWObject oSaveVersus) throws NotInContextException;

    /**<br>
     * Get oTarget's base reflex saving throw value (this will only work for<br>
     * creatures, doors, and placeables).<br>
     * * Returns 0 if oTarget is invalid.<br>
    **/
    idempotent int getReflexSavingThrow(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get an integer between 0 and 100 (inclusive) that represents how oSource<br>
     * feels about oTarget.<br>
     * -> 0-10 means oSource is hostile to oTarget<br>
     * -> 11-89 means oSource is neutral to oTarget<br>
     * -> 90-100 means oSource is friendly to oTarget<br>
     * * Returns -1 if oSource or oTarget does not identify a valid object<br>
    **/
    idempotent int getReputation(NWObject oSource, NWObject oTarget) throws NotInContextException;

    /**<br>
     * returns the template used to create this object (if appropriate)<br>
     * * returns an empty string when no template found<br>
    **/
    idempotent string getResRef(NWObject oObject) throws NotInContextException;

    /**<br>
     * Get the creature that is currently sitting on the specified object.<br>
     * - oChair<br>
     * * Returns OBJECT_INVALID if oChair is not a valid placeable.<br>
    **/
    idempotent NWObject getSittingCreature(NWObject oChair) throws NotInContextException;

    /**<br>
     * Get the number of ranks that oTarget has in nSkill.<br>
     * - nSkill: SKILL_*<br>
     * - oTarget<br>
     * - nBaseSkillRank: if set to true returns the number of base skill ranks the target<br>
     * has (i.e. not including any bonuses from ability scores, feats, etc).<br>
     * * Returns -1 if oTarget doesn't have nSkill.<br>
     * * Returns 0 if nSkill is untrained.<br>
    **/
    idempotent int getSkillRank(int nSkill, NWObject oTarget, bool bBaseSkillRank) throws NotInContextException;

    /**<br>
     * Gets the skybox that is currently displayed in the specified area.<br>
     * Returns:<br>
     * SKYBOX_* constant<br>
     * If no valid area (or object) is specified, it uses the area of caller.<br>
     * If an object other than an area is specified, will use the area that the object is currently in.<br>
    **/
    idempotent int getSkyBox(NWObject oArea) throws NotInContextException;

    /**<br>
     * Use this in a spell script to get the item used to cast the spell.<br>
    **/
    idempotent NWObject getSpellCastItem() throws NotInContextException;

    /**<br>
     * This is for use in a Spell script, it gets the ID of the spell that is being<br>
     * cast (SPELL_*).<br>
    **/
    idempotent int getSpellId() throws NotInContextException;

    /**<br>
     * Returns the spell resistance of the specified creature.<br>
     * - Returns 0 if the creature has no spell resistance or an invalid<br>
     * creature is passed in.<br>
    **/
    idempotent int getSpellResistance(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the DC to save against for a spell (10 + spell level + relevant ability<br>
     * bonus).  This can be called by a creature or by an Area of Effect object.<br>
    **/
    idempotent int getSpellSaveDC() throws NotInContextException;

    /**<br>
     * Get the location of the caller's last spell target.<br>
    **/
    idempotent NWLocation getSpellTargetLocation() throws NotInContextException;

    /**<br>
     * Get the object at which the caller last cast a spell<br>
     * * Return value on error: OBJECT_INVALID<br>
    **/
    idempotent NWObject getSpellTargetObject() throws NotInContextException;

    /**<br>
     * Find out how nStandardFaction feels about oCreature.<br>
     * - nStandardFaction: STANDARD_FACTION_*<br>
     * - oCreature<br>
     * Returns -1 on an error.<br>
     * Returns 0-100 based on the standing of oCreature within the faction nStandardFaction.<br>
     * 0-10   :  Hostile.<br>
     * 11-89  :  Neutral.<br>
     * 90-100 :  Friendly.<br>
    **/
    idempotent int getStandardFactionReputation(StandardFaction tStandardFaction, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the starting location of the module.<br>
    **/
    idempotent NWLocation getStartingLocation() throws NotInContextException;

    /**<br>
     * Returns the stealth mode of the specified creature.<br>
     * - oCreature<br>
     * * Returns a constant STEALTH_MODE_*<br>
    **/
    idempotent int getStealthMode(NWObject oCreature) throws NotInContextException;

    /**<br>
     * returns TRUE if the item is stolen<br>
    **/
    idempotent bool getStolenFlag(NWObject oStolen) throws NotInContextException;

    /**<br>
     * Returns the amount of gold a store currently has. -1 indicates it is not using gold.<br>
     * -2 indicates the store could not be located.<br>
    **/
    idempotent int getStoreGold(NWObject oidStore) throws NotInContextException;

    /**<br>
     * Gets the amount a store charges for identifying an item. Default is 100. -1 means<br>
     * the store will not identify items.<br>
     * -2 indicates the store could not be located.<br>
    **/
    idempotent int getStoreIdentifyCost(NWObject oidStore) throws NotInContextException;

    /**<br>
     * Gets the maximum amount a store will pay for any item. -1 means price unlimited.<br>
     * -2 indicates the store could not be located.<br>
    **/
    idempotent int getStoreMaxBuyPrice(NWObject oidStore) throws NotInContextException;

    /**<br>
     * Get the duration (in seconds) of the sound attached to nStrRef<br>
     * * Returns 0.0f if no duration is stored or if no sound is attached<br>
    **/
    idempotent double getStrRefSoundDuration(int nStrRef) throws NotInContextException;

    /**<br>
     * Get a string from the talk table using nStrRef.<br>
    **/
    idempotent string getStringByStrRef(int nStrRef, Gender tGender) throws NotInContextException;

    /**<br>
     * Get the name of oCreature's sub race.<br>
     * * Returns "" if oCreature is invalid (or if sub race is blank for oCreature).<br>
    **/
    idempotent string getSubRace(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get the Tag of oObject<br>
     * * Return value if oObject is not a valid object: ""<br>
    **/
    idempotent string getTag(NWObject oObject) throws NotInContextException;

    /**<br>
     * Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 1 of the tile at<br>
     * lTile.<br>
     * - lTile: the vector part of this is the tile grid (x,y) coordinate of the tile.<br>
    **/
    idempotent TileMainLightColor getTileMainLight1Color(NWLocation lTile) throws NotInContextException;

    /**<br>
     * Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 2 of the tile at<br>
     * lTile.<br>
     * - lTile: the vector part of this is the tile grid (x,y) coordinate of the<br>
     * tile.<br>
    **/
    idempotent TileMainLightColor getTileMainLight2Color(NWLocation lTile) throws NotInContextException;

    /**<br>
     * Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 1 of the tile<br>
     * at lTile.<br>
     * - lTile: the vector part of this is the tile grid (x,y) coordinate of the<br>
     * tile.<br>
    **/
    idempotent TileSourceLightColor getTileSourceLight1Color(NWLocation lTile) throws NotInContextException;

    /**<br>
     * Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 2 of the tile<br>
     * at lTile.<br>
     * - lTile: the vector part of this is the tile grid (x,y) coordinate of the<br>
     * tile.<br>
    **/
    idempotent TileSourceLightColor getTileSourceLight2Color(NWLocation lTile) throws NotInContextException;

    /**<br>
     * returns the resref (TILESET_RESREF_*) of the tileset used to create area oArea.<br>
     * TILESET_RESREF_BEHOLDER_CAVES<br>
     * TILESET_RESREF_CASTLE_INTERIOR<br>
     * TILESET_RESREF_CITY_EXTERIOR<br>
     * TILESET_RESREF_CITY_INTERIOR<br>
     * TILESET_RESREF_CRYPT<br>
     * TILESET_RESREF_DESERT<br>
     * TILESET_RESREF_DROW_INTERIOR<br>
     * TILESET_RESREF_DUNGEON<br>
     * TILESET_RESREF_FOREST<br>
     * TILESET_RESREF_FROZEN_WASTES<br>
     * TILESET_RESREF_ILLITHID_INTERIOR<br>
     * TILESET_RESREF_MICROSET<br>
     * TILESET_RESREF_MINES_AND_CAVERNS<br>
     * TILESET_RESREF_RUINS<br>
     * TILESET_RESREF_RURAL<br>
     * TILESET_RESREF_RURAL_WINTER<br>
     * TILESET_RESREF_SEWERS<br>
     * TILESET_RESREF_UNDERDARK<br>
     * * returns an empty string on an error.<br>
    **/
    idempotent string getTilesetResRef(NWObject oArea) throws NotInContextException;

    /**<br>
     * Get the current hour.<br>
    **/
    idempotent int getTimeHour() throws NotInContextException;

    /**<br>
     * Get the current millisecond<br>
    **/
    idempotent int getTimeMillisecond() throws NotInContextException;

    /**<br>
     * Get the current minute<br>
    **/
    idempotent int getTimeMinute() throws NotInContextException;

    /**<br>
     * Get the current second<br>
    **/
    idempotent int getTimeSecond() throws NotInContextException;

    /**<br>
     * Get the total amount of damage that has been dealt to the caller.<br>
    **/
    idempotent int getTotalDamageDealt() throws NotInContextException;

    /**<br>
     * Get the destination (a waypoint or a door) for a trigger or a door.<br>
     * * Returns OBJECT_INVALID if oTransition is not a valid trigger or door.<br>
    **/
    idempotent NWObject getTransitionTarget(NWObject oTransition) throws NotInContextException;

    /**<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * * Returns TRUE if oTrapObject is active<br>
    **/
    idempotent bool getTrapActive(NWObject oTrapObject) throws NotInContextException;

    /**<br>
     * Get the trap base type (TRAP_BASE_TYPE_*) of oTrapObject.<br>
     * - oTrapObject: a placeable, door or trigger<br>
    **/
    idempotent int getTrapBaseType(NWObject oTrapObject) throws NotInContextException;

    /**<br>
     * Get the creator of oTrapObject, the creature that set the trap.<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * * Returns OBJECT_INVALID if oTrapObject was created in the toolset.<br>
    **/
    idempotent NWObject getTrapCreator(NWObject oTrapObject) throws NotInContextException;

    /**<br>
     * Get the DC for detecting oTrapObject.<br>
     * - oTrapObject: a placeable, door or trigger<br>
    **/
    idempotent int getTrapDetectDC(NWObject oTrapObject) throws NotInContextException;

    /**<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * * Returns TRUE if oTrapObject is detectable.<br>
    **/
    idempotent bool getTrapDetectable(NWObject oTrapObject) throws NotInContextException;

    /**<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * - oCreature<br>
     * * Returns TRUE if oCreature has detected oTrapObject<br>
    **/
    idempotent bool getTrapDetectedBy(NWObject oTrapObject, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the DC for disarming oTrapObject.<br>
     * - oTrapObject: a placeable, door or trigger<br>
    **/
    idempotent int getTrapDisarmDC(NWObject oTrapObject) throws NotInContextException;

    /**<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * * Returns TRUE if oTrapObject is disarmable.<br>
    **/
    idempotent bool getTrapDisarmable(NWObject oTrapObject) throws NotInContextException;

    /**<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * * Returns TRUE if oTrapObject has been flagged as visible to all creatures.<br>
    **/
    idempotent bool getTrapFlagged(NWObject oTrapObject) throws NotInContextException;

    /**<br>
     * Get the tag of the key that will disarm oTrapObject.<br>
     * - oTrapObject: a placeable, door or trigger<br>
    **/
    idempotent string getTrapKeyTag(NWObject oTrapObject) throws NotInContextException;

    /**<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * * Returns TRUE if oTrapObject is one-shot (i.e. it does not reset itself<br>
     * after firing.<br>
    **/
    idempotent bool getTrapOneShot(NWObject oTrapObject) throws NotInContextException;

    /**<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * * Returns TRUE if oTrapObject can be recovered.<br>
    **/
    idempotent bool getTrapRecoverable(NWObject oTrapObject) throws NotInContextException;

    /**<br>
     * Get the number of Hitdice worth of Turn Resistance that oUndead may have.<br>
     * This will only work on undead creatures.<br>
    **/
    idempotent int getTurnResistanceHD(NWObject oUndead) throws NotInContextException;

    /**<br>
     * returns TRUE if the placeable object is usable<br>
    **/
    idempotent bool getUseableFlag(NWObject oObject) throws NotInContextException;

    /**<br>
     * This is for use in a user-defined script, it gets the event number.<br>
    **/
    idempotent int getUserDefinedEventNumber() throws NotInContextException;

    /**<br>
     * Get the first waypoint with the specified tag.<br>
     * * Returns OBJECT_INVALID if the waypoint cannot be found.<br>
    **/
    idempotent NWObject getWaypointByTag(string sWaypointTag) throws NotInContextException;

    /**<br>
     * * Returns TRUE if oItem is a ranged weapon.<br>
    **/
    idempotent bool getWeaponRanged(NWObject oItem) throws NotInContextException;

    /**<br>
     * Gets the current weather conditions for the area oArea.<br>
     * Returns: WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW, WEATHER_INVALID<br>
     * Note: If called on an Interior area, this will always return WEATHER_CLEAR.<br>
    **/
    idempotent Weather getWeather(NWObject oArea) throws NotInContextException;

    /**<br>
     * Gets the weight of an item, or the total carried weight of a creature in tenths<br>
     * of pounds (as per the baseitems.2da).<br>
     * - oTarget: the item or creature for which the weight is needed<br>
    **/
    idempotent int getWeight(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get oTarget's base will saving throw value (this will only work for creatures,<br>
     * doors, and placeables).<br>
     * * Returns 0 if oTarget is invalid.<br>
    **/
    idempotent int getWillSavingThrow(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Get oCreature's experience.<br>
    **/
    idempotent int getXP(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Give nGP gold to oCreature.<br>
    **/
    void giveGoldToCreature(NWObject oCreature, int nGP) throws NotInContextException;

    /**<br>
     * Gives nXpAmount to oCreature.<br>
    **/
    void giveXPToCreature(NWObject oCreature, int nXpAmount) throws NotInContextException;

    /**<br>
     * Convert nHours into a number of seconds<br>
     * The result will depend on how many minutes there are per hour (game-time)<br>
    **/
    idempotent double hoursToSeconds(int nHours) throws NotInContextException;

    /**<br>
     * Increment the remaining uses per day for this creature by one.<br>
     * Total number of feats per day can not exceed the maximum.<br>
     * - oCreature: creature to modify<br>
     * - nFeat: constant FEAT_*<br>
    **/
    void incrementRemainingFeatUses(NWObject oCreature, int nFeat) throws NotInContextException;

    /**<br>
     * Determine whether oObject is in conversation.<br>
    **/
    idempotent bool isInConversation(NWObject oObject) throws NotInContextException;

    /**<br>
     * Returns Item property AC bonus.  You need to specify the bonus.<br>
     * The bonus should be a positive integer between 1 and 20. The modifier<br>
     * type depends on the item it is being applied to.<br>
    **/
    idempotent NWItemProperty itemPropertyACBonus(int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property AC bonus vs. alignment group.  An example of<br>
     * an alignment group is Chaotic, or Good.  You need to specify the<br>
     * alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the AC bonus.<br>
     * The AC bonus should be an integer between 1 and 20.  The modifier<br>
     * type depends on the item it is being applied to.<br>
    **/
    idempotent NWItemProperty itemPropertyACBonusVsAlign(IPAlignGroup tIPAlignGroup, int nACBonus) throws NotInContextException;

    /**<br>
     * Returns Item property AC bonus vs. Damage type (ie. piercing).  You<br>
     * need to specify the damage type constant(IP_CONST_DAMAGETYPE_*) and the<br>
     * AC bonus.  The AC bonus should be an integer between 1 and 20.  The<br>
     * modifier type depends on the item it is being applied to.<br>
     * NOTE: Only the first 3 damage types may be used here, the 3 basic<br>
     * physical types.<br>
    **/
    idempotent NWItemProperty itemPropertyACBonusVsDmgType(IPDamageType tIPDamageType, int nACBonus) throws NotInContextException;

    /**<br>
     * Returns Item property AC bonus vs. Racial group.  You need to specify<br>
     * the racial group constant(IP_CONST_RACIALTYPE_*) and the AC bonus.  The AC<br>
     * bonus should be an integer between 1 and 20.  The modifier type depends<br>
     * on the item it is being applied to.<br>
    **/
    idempotent NWItemProperty itemPropertyACBonusVsRace(IPRacialType tIPRacialType, int nACBonus) throws NotInContextException;

    /**<br>
     * Returns Item property AC bonus vs. Specific alignment.  You need to<br>
     * specify the specific alignment constant(IP_CONST_ALIGNMENT_*) and the AC<br>
     * bonus.  The AC bonus should be an integer between 1 and 20.  The<br>
     * modifier type depends on the item it is being applied to.<br>
    **/
    idempotent NWItemProperty itemPropertyACBonusVsSAlign(Alignment tAlignment, int nACBonus) throws NotInContextException;

    /**<br>
     * Returns Item property ability bonus.  You need to specify an<br>
     * ability constant(IP_CONST_ABILITY_*) and the bonus.  The bonus should<br>
     * be a positive integer between 1 and 12.<br>
    **/
    idempotent NWItemProperty itemPropertyAbilityBonus(Ability tAbility, int nBonus) throws NotInContextException;

    /**<br>
     * Returns a generic Additional Item property. You need to specify the Additional property.<br>
     * - nProperty: The item property to create (see iprp_addcost.2da).<br>
     * IP_CONST_ADDITIONAL_*<br>
     * Note: The additional property only affects the cost of the item if you modify the cost in the iprp_addcost.2da.<br>
    **/
    idempotent NWItemProperty itemPropertyAdditional(int nAdditionalProperty) throws NotInContextException;

    /**<br>
     * Creates an item property that offsets the effect on arcane spell failure<br>
     * that a particular item has. Parameters come from the ITEM_PROP_ASF_* group.<br>
    **/
    idempotent NWItemProperty itemPropertyArcaneSpellFailure(int nModLevel) throws NotInContextException;

    /**<br>
     * Returns Item property Attack bonus.  You must specify an attack bonus.  The bonus<br>
     * must be an integer between 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyAttackBonus(int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property Attack bonus vs. alignment group.  You must specify the<br>
     * alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the attack bonus.  The<br>
     * bonus must be an integer between 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyAttackBonusVsAlign(IPAlignGroup tIPAlignGroup, int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property attack bonus vs. racial group.  You must specify the<br>
     * racial group constant(IP_CONST_RACIALTYPE_*) and the attack bonus.  The bonus<br>
     * must be an integer between 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyAttackBonusVsRace(IPRacialType tIPRacialType, int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property attack bonus vs. a specific alignment.  You must specify<br>
     * the alignment you want the bonus to work against(IP_CONST_ALIGNMENT_*) and the<br>
     * attack bonus.  The bonus must be an integer between 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyAttackBonusVsSAlign(Alignment tAlignment, int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property attack penalty.  You must specify the attack penalty.<br>
     * The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).<br>
    **/
    idempotent NWItemProperty itemPropertyAttackPenalty(int nPenalty) throws NotInContextException;

    /**<br>
     * Returns Item property Bonus Feat.  You need to specify the the feat<br>
     * constant(IP_CONST_FEAT_*).<br>
    **/
    idempotent NWItemProperty itemPropertyBonusFeat(int nFeat) throws NotInContextException;

    /**<br>
     * Returns Item property Bonus level spell (Bonus spell of level).  You must<br>
     * specify the class constant(IP_CONST_CLASS_*) of the bonus spell(MUST BE a<br>
     * spell casting class) and the level of the bonus spell.  The level of the<br>
     * bonus spell should be an integer between 0 and 9.<br>
    **/
    idempotent NWItemProperty itemPropertyBonusLevelSpell(int nClass, int nSpellLevel) throws NotInContextException;

    /**<br>
     * Returns Item property saving throw bonus to the base type (ie. will, reflex,<br>
     * fortitude).  You must specify the base type constant(IP_CONST_SAVEBASETYPE_*)<br>
     * to which the user gets the bonus and the bonus that he/she will get.  The<br>
     * bonus must be an integer between 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyBonusSavingThrow(int nBaseSaveType, int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property saving throw bonus vs. a specific effect or damage type.<br>
     * You must specify the save type constant(IP_CONST_SAVEVS_*) that the bonus is<br>
     * applied to and the bonus that is be applied.  The bonus must be an integer<br>
     * between 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyBonusSavingThrowVsX(int nBonusType, int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property bonus spell resistance.  You must specify the bonus spell<br>
     * resistance constant(IP_CONST_SPELLRESISTANCEBONUS_*).<br>
    **/
    idempotent NWItemProperty itemPropertyBonusSpellResistance(int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property Cast spell.  You must specify the spell constant<br>
     * (IP_CONST_CASTSPELL_*) and the number of uses constant(IP_CONST_CASTSPELL_NUMUSES_*).<br>
     * NOTE: The number after the name of the spell in the constant is the level<br>
     * at which the spell will be cast.  Sometimes there are multiple copies<br>
     * of the same spell but they each are cast at a different level.  The higher<br>
     * the level, the more cost will be added to the item.<br>
     * NOTE: The list of spells that can be applied to an item will depend on the<br>
     * item type.  For instance there are spells that can be applied to a wand<br>
     * that cannot be applied to a potion.  Below is a list of the types and the<br>
     * spells that are allowed to be placed on them.  If you try to put a cast<br>
     * spell effect on an item that is not allowed to have that effect it will<br>
     * not work.<br>
     * NOTE: Even if spells have multiple versions of different levels they are only<br>
     * listed below once.<br>
     * <br>
     * WANDS:<br>
     * Acid_Splash<br>
     * Activate_Item<br>
     * Aid<br>
     * Amplify<br>
     * Animate_Dead<br>
     * AuraOfGlory<br>
     * BalagarnsIronHorn<br>
     * Bane<br>
     * Banishment<br>
     * Barkskin<br>
     * Bestow_Curse<br>
     * Bigbys_Clenched_Fist<br>
     * Bigbys_Crushing_Hand<br>
     * Bigbys_Forceful_Hand<br>
     * Bigbys_Grasping_Hand<br>
     * Bigbys_Interposing_Hand<br>
     * Bless<br>
     * Bless_Weapon<br>
     * Blindness/Deafness<br>
     * Blood_Frenzy<br>
     * Bombardment<br>
     * Bulls_Strength<br>
     * Burning_Hands<br>
     * Call_Lightning<br>
     * Camoflage<br>
     * Cats_Grace<br>
     * Charm_Monster<br>
     * Charm_Person<br>
     * Charm_Person_or_Animal<br>
     * Clairaudience/Clairvoyance<br>
     * Clarity<br>
     * Color_Spray<br>
     * Confusion<br>
     * Continual_Flame<br>
     * Cure_Critical_Wounds<br>
     * Cure_Light_Wounds<br>
     * Cure_Minor_Wounds<br>
     * Cure_Moderate_Wounds<br>
     * Cure_Serious_Wounds<br>
     * Darkness<br>
     * Darkvision<br>
     * Daze<br>
     * Death_Ward<br>
     * Dirge<br>
     * Dismissal<br>
     * Dispel_Magic<br>
     * Displacement<br>
     * Divine_Favor<br>
     * Divine_Might<br>
     * Divine_Power<br>
     * Divine_Shield<br>
     * Dominate_Animal<br>
     * Dominate_Person<br>
     * Doom<br>
     * Dragon_Breath_Acid<br>
     * Dragon_Breath_Cold<br>
     * Dragon_Breath_Fear<br>
     * Dragon_Breath_Fire<br>
     * Dragon_Breath_Gas<br>
     * Dragon_Breath_Lightning<br>
     * Dragon_Breath_Paralyze<br>
     * Dragon_Breath_Sleep<br>
     * Dragon_Breath_Slow<br>
     * Dragon_Breath_Weaken<br>
     * Drown<br>
     * Eagle_Spledor<br>
     * Earthquake<br>
     * Electric_Jolt<br>
     * Elemental_Shield<br>
     * Endurance<br>
     * Endure_Elements<br>
     * Enervation<br>
     * Entangle<br>
     * Entropic_Shield<br>
     * Etherealness<br>
     * Expeditious_Retreat<br>
     * Fear<br>
     * Find_Traps<br>
     * Fireball<br>
     * Firebrand<br>
     * Flame_Arrow<br>
     * Flame_Lash<br>
     * Flame_Strike<br>
     * Flare<br>
     * Foxs_Cunning<br>
     * Freedom_of_Movement<br>
     * Ghostly_Visage<br>
     * Ghoul_Touch<br>
     * Grease<br>
     * Greater_Magic_Fang<br>
     * Greater_Magic_Weapon<br>
     * Grenade_Acid<br>
     * Grenade_Caltrops<br>
     * Grenade_Chicken<br>
     * Grenade_Choking<br>
     * Grenade_Fire<br>
     * Grenade_Holy<br>
     * Grenade_Tangle<br>
     * Grenade_Thunderstone<br>
     * Gust_of_wind<br>
     * Hammer_of_the_Gods<br>
     * Haste<br>
     * Hold_Animal<br>
     * Hold_Monster<br>
     * Hold_Person<br>
     * Ice_Storm<br>
     * Identify<br>
     * Improved_Invisibility<br>
     * Inferno<br>
     * Inflict_Critical_Wounds<br>
     * Inflict_Light_Wounds<br>
     * Inflict_Minor_Wounds<br>
     * Inflict_Moderate_Wounds<br>
     * Inflict_Serious_Wounds<br>
     * Invisibility<br>
     * Invisibility_Purge<br>
     * Invisibility_Sphere<br>
     * Isaacs_Greater_Missile_Storm<br>
     * Isaacs_Lesser_Missile_Storm<br>
     * Knock<br>
     * Lesser_Dispel<br>
     * Lesser_Restoration<br>
     * Lesser_Spell_Breach<br>
     * Light<br>
     * Lightning_Bolt<br>
     * Mage_Armor<br>
     * Magic_Circle_against_Alignment<br>
     * Magic_Fang<br>
     * Magic_Missile<br>
     * Manipulate_Portal_Stone<br>
     * Mass_Camoflage<br>
     * Melfs_Acid_Arrow<br>
     * Meteor_Swarm<br>
     * Mind_Blank<br>
     * Mind_Fog<br>
     * Negative_Energy_Burst<br>
     * Negative_Energy_Protection<br>
     * Negative_Energy_Ray<br>
     * Neutralize_Poison<br>
     * One_With_The_Land<br>
     * Owls_Insight<br>
     * Owls_Wisdom<br>
     * Phantasmal_Killer<br>
     * Planar_Ally<br>
     * Poison<br>
     * Polymorph_Self<br>
     * Prayer<br>
     * Protection_from_Alignment<br>
     * Protection_From_Elements<br>
     * Quillfire<br>
     * Ray_of_Enfeeblement<br>
     * Ray_of_Frost<br>
     * Remove_Blindness/Deafness<br>
     * Remove_Curse<br>
     * Remove_Disease<br>
     * Remove_Fear<br>
     * Remove_Paralysis<br>
     * Resist_Elements<br>
     * Resistance<br>
     * Restoration<br>
     * Sanctuary<br>
     * Scare<br>
     * Searing_Light<br>
     * See_Invisibility<br>
     * Shadow_Conjuration<br>
     * Shield<br>
     * Shield_of_Faith<br>
     * Silence<br>
     * Sleep<br>
     * Slow<br>
     * Sound_Burst<br>
     * Spike_Growth<br>
     * Stinking_Cloud<br>
     * Stoneskin<br>
     * Summon_Creature_I<br>
     * Summon_Creature_I<br>
     * Summon_Creature_II<br>
     * Summon_Creature_III<br>
     * Summon_Creature_IV<br>
     * Sunburst<br>
     * Tashas_Hideous_Laughter<br>
     * True_Strike<br>
     * Undeaths_Eternal_Foe<br>
     * Unique_Power<br>
     * Unique_Power_Self_Only<br>
     * Vampiric_Touch<br>
     * Virtue<br>
     * Wall_of_Fire<br>
     * Web<br>
     * Wounding_Whispers<br>
     * <br>
     * POTIONS:<br>
     * Activate_Item<br>
     * Aid<br>
     * Amplify<br>
     * AuraOfGlory<br>
     * Bane<br>
     * Barkskin<br>
     * Barkskin<br>
     * Barkskin<br>
     * Bless<br>
     * Bless_Weapon<br>
     * Bless_Weapon<br>
     * Blood_Frenzy<br>
     * Bulls_Strength<br>
     * Bulls_Strength<br>
     * Bulls_Strength<br>
     * Camoflage<br>
     * Cats_Grace<br>
     * Cats_Grace<br>
     * Cats_Grace<br>
     * Clairaudience/Clairvoyance<br>
     * Clairaudience/Clairvoyance<br>
     * Clairaudience/Clairvoyance<br>
     * Clarity<br>
     * Continual_Flame<br>
     * Cure_Critical_Wounds<br>
     * Cure_Critical_Wounds<br>
     * Cure_Critical_Wounds<br>
     * Cure_Light_Wounds<br>
     * Cure_Light_Wounds<br>
     * Cure_Minor_Wounds<br>
     * Cure_Moderate_Wounds<br>
     * Cure_Moderate_Wounds<br>
     * Cure_Moderate_Wounds<br>
     * Cure_Serious_Wounds<br>
     * Cure_Serious_Wounds<br>
     * Cure_Serious_Wounds<br>
     * Darkness<br>
     * Darkvision<br>
     * Darkvision<br>
     * Death_Ward<br>
     * Dispel_Magic<br>
     * Dispel_Magic<br>
     * Displacement<br>
     * Divine_Favor<br>
     * Divine_Might<br>
     * Divine_Power<br>
     * Divine_Shield<br>
     * Dragon_Breath_Acid<br>
     * Dragon_Breath_Cold<br>
     * Dragon_Breath_Fear<br>
     * Dragon_Breath_Fire<br>
     * Dragon_Breath_Gas<br>
     * Dragon_Breath_Lightning<br>
     * Dragon_Breath_Paralyze<br>
     * Dragon_Breath_Sleep<br>
     * Dragon_Breath_Slow<br>
     * Dragon_Breath_Weaken<br>
     * Eagle_Spledor<br>
     * Eagle_Spledor<br>
     * Eagle_Spledor<br>
     * Elemental_Shield<br>
     * Elemental_Shield<br>
     * Endurance<br>
     * Endurance<br>
     * Endurance<br>
     * Endure_Elements<br>
     * Entropic_Shield<br>
     * Ethereal_Visage<br>
     * Ethereal_Visage<br>
     * Etherealness<br>
     * Expeditious_Retreat<br>
     * Find_Traps<br>
     * Foxs_Cunning<br>
     * Foxs_Cunning<br>
     * Foxs_Cunning<br>
     * Freedom_of_Movement<br>
     * Ghostly_Visage<br>
     * Ghostly_Visage<br>
     * Ghostly_Visage<br>
     * Globe_of_Invulnerability<br>
     * Greater_Bulls_Strength<br>
     * Greater_Cats_Grace<br>
     * Greater_Dispelling<br>
     * Greater_Dispelling<br>
     * Greater_Eagles_Splendor<br>
     * Greater_Endurance<br>
     * Greater_Foxs_Cunning<br>
     * Greater_Magic_Weapon<br>
     * Greater_Owls_Wisdom<br>
     * Greater_Restoration<br>
     * Greater_Spell_Mantle<br>
     * Greater_Stoneskin<br>
     * Grenade_Acid<br>
     * Grenade_Caltrops<br>
     * Grenade_Chicken<br>
     * Grenade_Choking<br>
     * Grenade_Fire<br>
     * Grenade_Holy<br>
     * Grenade_Tangle<br>
     * Grenade_Thunderstone<br>
     * Haste<br>
     * Haste<br>
     * Heal<br>
     * Hold_Animal<br>
     * Hold_Monster<br>
     * Hold_Person<br>
     * Identify<br>
     * Invisibility<br>
     * Lesser_Dispel<br>
     * Lesser_Dispel<br>
     * Lesser_Mind_Blank<br>
     * Lesser_Restoration<br>
     * Lesser_Spell_Mantle<br>
     * Light<br>
     * Light<br>
     * Mage_Armor<br>
     * Manipulate_Portal_Stone<br>
     * Mass_Camoflage<br>
     * Mind_Blank<br>
     * Minor_Globe_of_Invulnerability<br>
     * Minor_Globe_of_Invulnerability<br>
     * Mordenkainens_Disjunction<br>
     * Negative_Energy_Protection<br>
     * Negative_Energy_Protection<br>
     * Negative_Energy_Protection<br>
     * Neutralize_Poison<br>
     * One_With_The_Land<br>
     * Owls_Insight<br>
     * Owls_Wisdom<br>
     * Owls_Wisdom<br>
     * Owls_Wisdom<br>
     * Polymorph_Self<br>
     * Prayer<br>
     * Premonition<br>
     * Protection_From_Elements<br>
     * Protection_From_Elements<br>
     * Protection_from_Spells<br>
     * Protection_from_Spells<br>
     * Raise_Dead<br>
     * Remove_Blindness/Deafness<br>
     * Remove_Curse<br>
     * Remove_Disease<br>
     * Remove_Fear<br>
     * Remove_Paralysis<br>
     * Resist_Elements<br>
     * Resist_Elements<br>
     * Resistance<br>
     * Resistance<br>
     * Restoration<br>
     * Resurrection<br>
     * Rogues_Cunning<br>
     * See_Invisibility<br>
     * Shadow_Shield<br>
     * Shapechange<br>
     * Shield<br>
     * Shield_of_Faith<br>
     * Special_Alcohol_Beer<br>
     * Special_Alcohol_Spirits<br>
     * Special_Alcohol_Wine<br>
     * Special_Herb_Belladonna<br>
     * Special_Herb_Garlic<br>
     * Spell_Mantle<br>
     * Spell_Resistance<br>
     * Spell_Resistance<br>
     * Stoneskin<br>
     * Tensers_Transformation<br>
     * True_Seeing<br>
     * True_Strike<br>
     * Unique_Power<br>
     * Unique_Power_Self_Only<br>
     * Virtue<br>
     * <br>
     * GENERAL USE (ie. everything else):<br>
     * Just about every spell is useable by all the general use items so instead we<br>
     * will only list the ones that are not allowed:<br>
     * Special_Alcohol_Beer<br>
     * Special_Alcohol_Spirits<br>
     * Special_Alcohol_Wine<br>
     * <br>
    **/
    idempotent NWItemProperty itemPropertyCastSpell(int nSpell, int nNumUses) throws NotInContextException;

    /**<br>
     * Returns Item property container reduced weight.  This is used for special<br>
     * containers that reduce the weight of the objects inside them.  You must<br>
     * specify the container weight reduction type constant(IP_CONST_CONTAINERWEIGHTRED_*).<br>
    **/
    idempotent NWItemProperty itemPropertyContainerReducedWeight(int nContainerType) throws NotInContextException;

    /**<br>
     * Returns Item property damage bonus.  You must specify the damage type constant<br>
     * (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).<br>
     * NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,<br>
     * Cold, Electrical, Fire, Piercing, Slashing, Sonic.<br>
    **/
    idempotent NWItemProperty itemPropertyDamageBonus(IPDamageType tIPDamageType, int nDamage) throws NotInContextException;

    /**<br>
     * Returns Item property damage bonus vs. Alignment groups.  You must specify the<br>
     * alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the damage type constant<br>
     * (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).<br>
     * NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,<br>
     * Cold, Electrical, Fire, Piercing, Slashing, Sonic.<br>
    **/
    idempotent NWItemProperty itemPropertyDamageBonusVsAlign(IPAlignGroup tIPAlignGroup, IPDamageType tIPDamageType, int nDamage) throws NotInContextException;

    /**<br>
     * Returns Item property damage bonus vs. specific race.  You must specify the<br>
     * racial group constant(IP_CONST_RACIALTYPE_*) and the damage type constant<br>
     * (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).<br>
     * NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,<br>
     * Cold, Electrical, Fire, Piercing, Slashing, Sonic.<br>
    **/
    idempotent NWItemProperty itemPropertyDamageBonusVsRace(IPRacialType tIPRacialType, IPDamageType tIPDamageType, int nDamage) throws NotInContextException;

    /**<br>
     * Returns Item property damage bonus vs. specific alignment.  You must specify the<br>
     * specific alignment constant(IP_CONST_ALIGNMENT_*) and the damage type constant<br>
     * (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).<br>
     * NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,<br>
     * Cold, Electrical, Fire, Piercing, Slashing, Sonic.<br>
    **/
    idempotent NWItemProperty itemPropertyDamageBonusVsSAlign(Alignment tAlignment, IPDamageType tIPDamageType, int nDamage) throws NotInContextException;

    /**<br>
     * Returns Item property damage immunity.  You must specify the damage type constant<br>
     * (IP_CONST_DAMAGETYPE_*) that you want to be immune to and the immune bonus percentage<br>
     * constant(IP_CONST_DAMAGEIMMUNITY_*).<br>
     * NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,<br>
     * Cold, Electrical, Fire, Piercing, Slashing, Sonic.<br>
    **/
    idempotent NWItemProperty itemPropertyDamageImmunity(IPDamageType tIPDamageType, int nImmuneBonus) throws NotInContextException;

    /**<br>
     * Returns Item property damage penalty.  You must specify the damage penalty.<br>
     * The damage penalty should be a POSITIVE integer between 1 and 5 (ie. 1 = -1).<br>
    **/
    idempotent NWItemProperty itemPropertyDamagePenalty(int nPenalty) throws NotInContextException;

    /**<br>
     * Returns Item property damage reduction.  You must specify the enhancment level<br>
     * (IP_CONST_DAMAGEREDUCTION_*) that is required to get past the damage reduction<br>
     * and the amount of HP of damage constant(IP_CONST_DAMAGESOAK_*) will be soaked<br>
     * up if your weapon is not of high enough enhancement.<br>
    **/
    idempotent NWItemProperty itemPropertyDamageReduction(int nEnhancement, int nHPSoak) throws NotInContextException;

    /**<br>
     * Returns Item property damage resistance.  You must specify the damage type<br>
     * constant(IP_CONST_DAMAGETYPE_*) and the amount of HP of damage constant<br>
     * (IP_CONST_DAMAGERESIST_*) that will be resisted against each round.<br>
    **/
    idempotent NWItemProperty itemPropertyDamageResistance(IPDamageType tIPDamageType, int nHPResist) throws NotInContextException;

    /**<br>
     * Returns Item property damage vulnerability.  You must specify the damage type<br>
     * constant(IP_CONST_DAMAGETYPE_*) that you want the user to be extra vulnerable to<br>
     * and the percentage vulnerability constant(IP_CONST_DAMAGEVULNERABILITY_*).<br>
    **/
    idempotent NWItemProperty itemPropertyDamageVulnerability(IPDamageType tIPDamageType, int nVulnerability) throws NotInContextException;

    /**<br>
     * Return Item property Darkvision.<br>
    **/
    idempotent NWItemProperty itemPropertyDarkvision() throws NotInContextException;

    /**<br>
     * Returns Item property decrease Armor Class.  You must specify the armor<br>
     * modifier type constant(IP_CONST_ACMODIFIERTYPE_*) and the armor class penalty.<br>
     * The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).<br>
    **/
    idempotent NWItemProperty itemPropertyDecreaseAC(int nModifierType, int nPenalty) throws NotInContextException;

    /**<br>
     * Return Item property decrease ability score.  You must specify the ability<br>
     * constant(IP_CONST_ABILITY_*) and the modifier constant.  The modifier must be<br>
     * a POSITIVE integer between 1 and 10 (ie. 1 = -1).<br>
    **/
    idempotent NWItemProperty itemPropertyDecreaseAbility(Ability tAbility, int nModifier) throws NotInContextException;

    /**<br>
     * Returns Item property decrease skill.  You must specify the constant for the<br>
     * skill to be decreased(SKILL_*) and the amount of the penalty.  The penalty<br>
     * must be a POSITIVE integer between 1 and 10 (ie. 1 = -1).<br>
    **/
    idempotent NWItemProperty itemPropertyDecreaseSkill(int nSkill, int nPenalty) throws NotInContextException;

    /**<br>
     * Returns Item property Enhancement bonus.  You need to specify the<br>
     * enhancement bonus.  The Enhancement bonus should be an integer between<br>
     * 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyEnhancementBonus(int nEnhancementBonus) throws NotInContextException;

    /**<br>
     * Returns Item property Enhancement bonus vs. an Alignment group.  You<br>
     * need to specify the alignment group constant(IP_CONST_ALIGNMENTGROUP_*)<br>
     * and the enhancement bonus.  The Enhancement bonus should be an integer<br>
     * between 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyEnhancementBonusVsAlign(IPAlignGroup tIPAlignGroup, int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property Enhancement bonus vs. Racial group.  You need<br>
     * to specify the racial group constant(IP_CONST_RACIALTYPE_*) and the<br>
     * enhancement bonus.  The enhancement bonus should be an integer between<br>
     * 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyEnhancementBonusVsRace(IPRacialType tIPRacialType, int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property Enhancement bonus vs. a specific alignment.  You<br>
     * need to specify the alignment constant(IP_CONST_ALIGNMENT_*) and the<br>
     * enhancement bonus.  The enhancement bonus should be an integer between<br>
     * 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyEnhancementBonusVsSAlign(Alignment tAlignment, int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property Enhancment penalty.  You need to specify the<br>
     * enhancement penalty.  The enhancement penalty should be a POSITIVE<br>
     * integer between 1 and 5 (ie. 1 = -1).<br>
    **/
    idempotent NWItemProperty itemPropertyEnhancementPenalty(int nPenalty) throws NotInContextException;

    /**<br>
     * Returns Item property extra melee damage type.  You must specify the extra<br>
     * melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).<br>
     * NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable<br>
     * here.<br>
     * NOTE: It is also only applicable to melee weapons.<br>
    **/
    idempotent NWItemProperty itemPropertyExtraMeleeDamageType(IPDamageType tIPDamageType) throws NotInContextException;

    /**<br>
     * Returns Item property extra ranged damage type.  You must specify the extra<br>
     * melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).<br>
     * NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable<br>
     * here.<br>
     * NOTE: It is also only applicable to ranged weapons.<br>
    **/
    idempotent NWItemProperty itemPropertyExtraRangeDamageType(IPDamageType tIPDamageType) throws NotInContextException;

    /**<br>
     * Returns Item property free action.<br>
    **/
    idempotent NWItemProperty itemPropertyFreeAction() throws NotInContextException;

    /**<br>
     * Returns Item property haste.<br>
    **/
    idempotent NWItemProperty itemPropertyHaste() throws NotInContextException;

    /**<br>
     * Returns Item property healers kit.  You must specify the level of the kit.<br>
     * The modifier must be an integer between 1 and 12.<br>
    **/
    idempotent NWItemProperty itemPropertyHealersKit(int nModifier) throws NotInContextException;

    /**<br>
     * Returns Item property Holy Avenger.<br>
    **/
    idempotent NWItemProperty itemPropertyHolyAvenger() throws NotInContextException;

    /**<br>
     * Returns Item property immunity to miscellaneous effects.  You must specify the<br>
     * effect to which the user is immune, it is a constant(IP_CONST_IMMUNITYMISC_*).<br>
    **/
    idempotent NWItemProperty itemPropertyImmunityMisc(IPMiscImmunityType tIPMiscImmunityType) throws NotInContextException;

    /**<br>
     * Returns Item property immunity to spell level.  You must specify the level of<br>
     * which that and below the user will be immune.  The level must be an integer<br>
     * between 1 and 9.  By putting in a 3 it will mean the user is immune to all<br>
     * 3rd level and lower spells.<br>
    **/
    idempotent NWItemProperty itemPropertyImmunityToSpellLevel(int nLevel) throws NotInContextException;

    /**<br>
     * Returns Item property improved evasion.<br>
    **/
    idempotent NWItemProperty itemPropertyImprovedEvasion() throws NotInContextException;

    /**<br>
     * Returns Item property keen.  This means a critical threat range of 19-20 on a<br>
     * weapon will be increased to 17-20 etc.<br>
    **/
    idempotent NWItemProperty itemPropertyKeen() throws NotInContextException;

    /**<br>
     * Returns Item property light.  You must specify the intesity constant of the<br>
     * light(IP_CONST_LIGHTBRIGHTNESS_*) and the color constant of the light<br>
     * (IP_CONST_LIGHTCOLOR_*).<br>
    **/
    idempotent NWItemProperty itemPropertyLight(int nBrightness, int nColor) throws NotInContextException;

    /**<br>
     * Returns Item property limit use by alignment group.  You must specify the<br>
     * alignment group(s) that you want to be able to use this item(IP_CONST_ALIGNMENTGROUP_*).<br>
    **/
    idempotent NWItemProperty itemPropertyLimitUseByAlign(IPAlignGroup tIPAlignGroup) throws NotInContextException;

    /**<br>
     * Returns Item property limit use by class.  You must specify the class(es) who<br>
     * are able to use this item(IP_CONST_CLASS_*).<br>
    **/
    idempotent NWItemProperty itemPropertyLimitUseByClass(int nClass) throws NotInContextException;

    /**<br>
     * Returns Item property limit use by race.  You must specify the race(s) who are<br>
     * allowed to use this item(IP_CONST_RACIALTYPE_*).<br>
    **/
    idempotent NWItemProperty itemPropertyLimitUseByRace(IPRacialType tIPRacialType) throws NotInContextException;

    /**<br>
     * Returns Item property limit use by specific alignment.  You must specify the<br>
     * alignment(s) of those allowed to use the item(IP_CONST_ALIGNMENT_*).<br>
    **/
    idempotent NWItemProperty itemPropertyLimitUseBySAlign(Alignment tAlignment) throws NotInContextException;

    /**<br>
     * Returns Item property Massive Critical.  You must specify the extra damage<br>
     * constant(IP_CONST_DAMAGEBONUS_*) of the criticals.<br>
    **/
    idempotent NWItemProperty itemPropertyMassiveCritical(int nDamage) throws NotInContextException;

    /**<br>
     * Returns Item property Material.  You need to specify the Material Type.<br>
     * - nMasterialType: The Material Type should be a positive integer between 0 and 77 (see iprp_matcost.2da).<br>
     * Note: The Material Type property will only affect the cost of the item if you modify the cost in the iprp_matcost.2da.<br>
    **/
    idempotent NWItemProperty itemPropertyMaterial(int nMaterialType) throws NotInContextException;

    /**<br>
     * Returns Item property Max range strength modification (ie. mighty).  You must<br>
     * specify the maximum modifier for strength that is allowed on a ranged weapon.<br>
     * The modifier must be a positive integer between 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyMaxRangeStrengthMod(int nModifier) throws NotInContextException;

    /**<br>
     * Returns Item property monster damage.  You must specify the amount of damage<br>
     * the monster's attack will do(IP_CONST_MONSTERDAMAGE_*).<br>
     * NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,<br>
     * gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.<br>
    **/
    idempotent NWItemProperty itemPropertyMonsterDamage(int nDamage) throws NotInContextException;

    /**<br>
     * Returns Item property no damage.  This means the weapon will do no damage in<br>
     * combat.<br>
    **/
    idempotent NWItemProperty itemPropertyNoDamage() throws NotInContextException;

    /**<br>
     * Creates an item property that (when applied to a weapon item) causes a spell to be cast<br>
     * when a successful strike is made, or (when applied to armor) is struck by an opponent.<br>
     * - nSpell uses the IP_CONST_ONHIT_CASTSPELL_* constants<br>
    **/
    idempotent NWItemProperty itemPropertyOnHitCastSpell(int nSpell, int nLevel) throws NotInContextException;

    /**<br>
     * Returns Item property on hit -> do effect property.  You must specify the on<br>
     * hit property constant(IP_CONST_ONHIT_*) and the save DC constant(IP_CONST_ONHIT_SAVEDC_*).<br>
     * Some of the item properties require a special parameter as well.  If the<br>
     * property does not require one you may leave out the last one.  The list of<br>
     * the ones with 3 parameters and what they are are as follows:<br>
     * ABILITYDRAIN      :nSpecial is the ability it is to drain.<br>
     * constant(IP_CONST_ABILITY_*)<br>
     * BLINDNESS         :nSpecial is the duration/percentage of effecting victim.<br>
     * constant(IP_CONST_ONHIT_DURATION_*)<br>
     * CONFUSION         :nSpecial is the duration/percentage of effecting victim.<br>
     * constant(IP_CONST_ONHIT_DURATION_*)<br>
     * DAZE              :nSpecial is the duration/percentage of effecting victim.<br>
     * constant(IP_CONST_ONHIT_DURATION_*)<br>
     * DEAFNESS          :nSpecial is the duration/percentage of effecting victim.<br>
     * constant(IP_CONST_ONHIT_DURATION_*)<br>
     * DISEASE           :nSpecial is the type of desease that will effect the victim.<br>
     * constant(DISEASE_*)<br>
     * DOOM              :nSpecial is the duration/percentage of effecting victim.<br>
     * constant(IP_CONST_ONHIT_DURATION_*)<br>
     * FEAR              :nSpecial is the duration/percentage of effecting victim.<br>
     * constant(IP_CONST_ONHIT_DURATION_*)<br>
     * HOLD              :nSpecial is the duration/percentage of effecting victim.<br>
     * constant(IP_CONST_ONHIT_DURATION_*)<br>
     * ITEMPOISON        :nSpecial is the type of poison that will effect the victim.<br>
     * constant(IP_CONST_POISON_*)<br>
     * SILENCE           :nSpecial is the duration/percentage of effecting victim.<br>
     * constant(IP_CONST_ONHIT_DURATION_*)<br>
     * SLAYRACE          :nSpecial is the race that will be slain.<br>
     * constant(IP_CONST_RACIALTYPE_*)<br>
     * SLAYALIGNMENTGROUP:nSpecial is the alignment group that will be slain(ie. chaotic).<br>
     * constant(IP_CONST_ALIGNMENTGROUP_*)<br>
     * SLAYALIGNMENT     :nSpecial is the specific alignment that will be slain.<br>
     * constant(IP_CONST_ALIGNMENT_*)<br>
     * SLEEP             :nSpecial is the duration/percentage of effecting victim.<br>
     * constant(IP_CONST_ONHIT_DURATION_*)<br>
     * SLOW              :nSpecial is the duration/percentage of effecting victim.<br>
     * constant(IP_CONST_ONHIT_DURATION_*)<br>
     * STUN              :nSpecial is the duration/percentage of effecting victim.<br>
     * constant(IP_CONST_ONHIT_DURATION_*)<br>
    **/
    idempotent NWItemProperty itemPropertyOnHitProps(int nProperty, int nSaveDC, int nSpecial) throws NotInContextException;

    /**<br>
     * Returns Item property Monster on hit apply effect property.  You must specify<br>
     * the property that you want applied on hit.  There are some properties that<br>
     * require an additional special parameter to be specified.  The others that<br>
     * don't require any additional parameter you may just put in the one.  The<br>
     * special cases are as follows:<br>
     * ABILITYDRAIN:nSpecial is the ability to drain.<br>
     * constant(IP_CONST_ABILITY_*)<br>
     * DISEASE     :nSpecial is the disease that you want applied.<br>
     * constant(DISEASE_*)<br>
     * LEVELDRAIN  :nSpecial is the number of levels that you want drained.<br>
     * integer between 1 and 5.<br>
     * POISON      :nSpecial is the type of poison that will effect the victim.<br>
     * constant(IP_CONST_POISON_*)<br>
     * WOUNDING    :nSpecial is the amount of wounding.<br>
     * integer between 1 and 5.<br>
     * NOTE: Any that do not appear in the above list do not require the second<br>
     * parameter.<br>
     * NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,<br>
     * gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.<br>
    **/
    idempotent NWItemProperty itemPropertyOnMonsterHitProperties(int nProperty, int nSpecial) throws NotInContextException;

    /**<br>
     * Returns Item property Quality. You need to specify the Quality.<br>
     * - nQuality:  The Quality of the item property to create (see iprp_qualcost.2da).<br>
     * IP_CONST_QUALITY_*<br>
     * Note: The quality property will only affect the cost of the item if you modify the cost in the iprp_qualcost.2da.<br>
    **/
    idempotent NWItemProperty itemPropertyQuality(int nQuality) throws NotInContextException;

    /**<br>
     * Returns Item property reduced saving to base type.  You must specify the base<br>
     * type to which the penalty applies (ie. will, reflex, or fortitude) and the penalty<br>
     * to be applied.  The constant for the base type starts with (IP_CONST_SAVEBASETYPE_*).<br>
     * The penalty must be a POSITIVE integer between 1 and 20 (ie. 1 = -1).<br>
    **/
    idempotent NWItemProperty itemPropertyReducedSavingThrow(int nBonusType, int nPenalty) throws NotInContextException;

    /**<br>
     * Returns Item property reduced saving throw vs. an effect or damage type.  You must<br>
     * specify the constant to which the penalty applies(IP_CONST_SAVEVS_*) and the<br>
     * penalty to be applied.  The penalty must be a POSITIVE integer between 1 and 20<br>
     * (ie. 1 = -1).<br>
    **/
    idempotent NWItemProperty itemPropertyReducedSavingThrowVsX(int nBaseSaveType, int nPenalty) throws NotInContextException;

    /**<br>
     * Returns Item property regeneration.  You must specify the regeneration amount.<br>
     * The amount must be an integer between 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyRegeneration(int nRegenAmount) throws NotInContextException;

    /**<br>
     * Returns Item property skill bonus.  You must specify the skill to which the user<br>
     * will get a bonus(SKILL_*) and the amount of the bonus.  The bonus amount must<br>
     * be an integer between 1 and 50.<br>
    **/
    idempotent NWItemProperty itemPropertySkillBonus(int nSkill, int nBonus) throws NotInContextException;

    /**<br>
     * Returns Item property special walk.  If no parameters are specified it will<br>
     * automatically use the zombie walk.  This will apply the special walk animation<br>
     * to the user.<br>
    **/
    idempotent NWItemProperty itemPropertySpecialWalk(int nWalkType) throws NotInContextException;

    /**<br>
     * Returns Item property spell immunity vs. spell school.  You must specify the<br>
     * school to which the user will be immune(IP_CONST_SPELLSCHOOL_*).<br>
    **/
    idempotent NWItemProperty itemPropertySpellImmunitySchool(IPSpellSchool tIPSpellSchool) throws NotInContextException;

    /**<br>
     * Returns Item property spell immunity vs. specific spell.  You must specify the<br>
     * spell to which the user will be immune(IP_CONST_IMMUNITYSPELL_*).<br>
    **/
    idempotent NWItemProperty itemPropertySpellImmunitySpecific(int nSpell) throws NotInContextException;

    /**<br>
     * Returns Item property Thieves tools.  You must specify the modifier you wish<br>
     * the tools to have.  The modifier must be an integer between 1 and 12.<br>
    **/
    idempotent NWItemProperty itemPropertyThievesTools(int nModifier) throws NotInContextException;

    /**<br>
     * Returns Item property Trap.  You must specify the trap level constant<br>
     * (IP_CONST_TRAPSTRENGTH_*) and the trap type constant(IP_CONST_TRAPTYPE_*).<br>
    **/
    idempotent NWItemProperty itemPropertyTrap(int nTrapLevel, IPTrapType tIPTrapType) throws NotInContextException;

    /**<br>
     * Returns Item property true seeing.<br>
    **/
    idempotent NWItemProperty itemPropertyTrueSeeing() throws NotInContextException;

    /**<br>
     * Returns Item property turn resistance.  You must specify the resistance bonus.<br>
     * The bonus must be an integer between 1 and 50.<br>
    **/
    idempotent NWItemProperty itemPropertyTurnResistance(int nModifier) throws NotInContextException;

    /**<br>
     * Returns Item property unlimited ammo.  If you leave the parameter field blank<br>
     * it will be just a normal bolt, arrow, or bullet.  However you may specify that<br>
     * you want the ammunition to do special damage (ie. +1d6 Fire, or +1 enhancement<br>
     * bonus).  For this parmeter you use the constants beginning with:<br>
     * (IP_CONST_UNLIMITEDAMMO_*).<br>
    **/
    idempotent NWItemProperty itemPropertyUnlimitedAmmo(int nAmmoDamage) throws NotInContextException;

    /**<br>
     * Returns Item property vampiric regeneration.  You must specify the amount of<br>
     * regeneration.  The regen amount must be an integer between 1 and 20.<br>
    **/
    idempotent NWItemProperty itemPropertyVampiricRegeneration(int nRegenAmount) throws NotInContextException;

    /**<br>
     * Creates a visual effect (ITEM_VISUAL_*) that may be applied to<br>
     * melee weapons only.<br>
    **/
    idempotent NWItemProperty itemPropertyVisualEffect(int nEffect) throws NotInContextException;

    /**<br>
     * Returns Item property weight increase.  You must specify the weight increase<br>
     * constant(IP_CONST_WEIGHTINCREASE_*).<br>
    **/
    idempotent NWItemProperty itemPropertyWeightIncrease(int nWeight) throws NotInContextException;

    /**<br>
     * Returns Item property weight reduction.  You need to specify the weight<br>
     * reduction constant(IP_CONST_REDUCEDWEIGHT_*).<br>
    **/
    idempotent NWItemProperty itemPropertyWeightReduction(int nReduction) throws NotInContextException;

    /**<br>
     * Jump to lDestination.  The action is added to the TOP of the action queue.<br>
    **/
    idempotent void jumpToLocation(NWLocation lDestination) throws NotInContextException;

    /**<br>
     * Jump to oToJumpTo (the action is added to the top of the action queue).<br>
    **/
    idempotent void jumpToObject(NWObject oToJumpTo, bool bWalkStraightLineToPoint) throws NotInContextException;

    /**<br>
     * Levels up a creature using default settings.<br>
     * If successfull it returns the level the creature now is, or 0 if it fails.<br>
     * If you want to give them a different level (ie: Give a Fighter a level of Wizard)<br>
     * you can specify that in the nClass.<br>
     * However, if you specify a class to which the creature no package specified,<br>
     * they will use the default package for that class for their levelup choices.<br>
     * (ie: no Barbarian Savage/Wizard Divination combinations)<br>
     * If you turn on bReadyAllSpells, all memorized spells will be ready to cast without resting.<br>
     * if nPackage is PACKAGE_INVALID then it will use the starting package assigned to that class or just the class package<br>
    **/
    int levelUpHenchman(NWObject oCreature, int nClass, bool bReadyAllSpells, int nPackage) throws NotInContextException;

    /**<br>
     * Returns whether or not there is a direct line of sight<br>
     * between the two objects. (Not blocked by any geometry).<br>
     * <br>
     * PLEASE NOTE: This is an expensive function and may<br>
     * degrade performance if used frequently.<br>
    **/
    idempotent int lineOfSightObject(NWObject oSource, NWObject oTarget) throws NotInContextException;

    /**<br>
     * Returns whether or not there is a direct line of sight<br>
     * between the two vectors. (Not blocked by any geometry).<br>
     * <br>
     * This function must be run on a valid object in the area<br>
     * it will not work on the module or area.<br>
     * <br>
     * PLEASE NOTE: This is an expensive function and may<br>
     * degrade performance if used frequently.<br>
    **/
    idempotent int lineOfSightVector(NWVector vSource, NWVector vTarget) throws NotInContextException;

    /**<br>
     * Locks the player's camera direction to its current direction,<br>
     * or unlocks the player's camera direction to enable it to move<br>
     * freely again.<br>
     * Stops the player from being able to rotate the camera direction.<br>
     * - oPlayer: A player object.<br>
     * - bLocked: TRUE/FALSE.<br>
    **/
    idempotent void lockCameraDirection(NWObject oPlayer, bool bLocked) throws NotInContextException;

    /**<br>
     * Locks the player's camera distance to its current distance setting,<br>
     * or unlocks the player's camera distance.<br>
     * Stops the player from being able to zoom in/out the camera.<br>
     * - oPlayer: A player object.<br>
     * - bLocked: TRUE/FALSE.<br>
    **/
    idempotent void lockCameraDistance(NWObject oPlayer, bool bLocked) throws NotInContextException;

    /**<br>
     * Locks the player's camera pitch to its current pitch setting,<br>
     * or unlocks the player's camera pitch.<br>
     * Stops the player from tilting their camera angle.<br>
     * - oPlayer: A player object.<br>
     * - bLocked: TRUE/FALSE.<br>
    **/
    idempotent void lockCameraPitch(NWObject oPlayer, bool bLocked) throws NotInContextException;

    /**<br>
     * Set the subtype of eEffect to Magical and return eEffect.<br>
     * (Effects default to magical if the subtype is not set)<br>
     * Magical effects are removed by resting, and by dispel magic<br>
    **/
    idempotent NWEffect magicalEffect(NWEffect eEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Change the background day track for oArea to nTrack.<br>
     * - oArea<br>
     * - nTrack<br>
    **/
    idempotent void musicBackgroundChangeDay(NWObject oArea, int nTrack) throws NotInContextException;

    /**<br>
     * Change the background night track for oArea to nTrack.<br>
     * - oArea<br>
     * - nTrack<br>
    **/
    idempotent void musicBackgroundChangeNight(NWObject oArea, int nTrack) throws NotInContextException;

    /**<br>
     * Get the Battle Track for oArea.<br>
    **/
    idempotent int musicBackgroundGetBattleTrack(NWObject oArea) throws NotInContextException;

    /**<br>
     * Get the Day Track for oArea.<br>
    **/
    idempotent int musicBackgroundGetDayTrack(NWObject oArea) throws NotInContextException;

    /**<br>
     * Get the Night Track for oArea.<br>
    **/
    idempotent int musicBackgroundGetNightTrack(NWObject oArea) throws NotInContextException;

    /**<br>
     * Play the background music for oArea.<br>
    **/
    idempotent void musicBackgroundPlay(NWObject oArea) throws NotInContextException;

    /**<br>
     * Set the delay for the background music for oArea.<br>
     * - oArea<br>
     * - nDelay: delay in milliseconds<br>
    **/
    idempotent void musicBackgroundSetDelay(NWObject oArea, int nDelay) throws NotInContextException;

    /**<br>
     * Stop the background music for oArea.<br>
    **/
    idempotent void musicBackgroundStop(NWObject oArea) throws NotInContextException;

    /**<br>
     * Change the battle track for oArea.<br>
     * - oArea<br>
     * - nTrack<br>
    **/
    idempotent void musicBattleChange(NWObject oArea, int nTrack) throws NotInContextException;

    /**<br>
     * Play the battle music for oArea.<br>
    **/
    idempotent void musicBattlePlay(NWObject oArea) throws NotInContextException;

    /**<br>
     * Stop the battle music for oArea.<br>
    **/
    idempotent void musicBattleStop(NWObject oArea) throws NotInContextException;

    /**<br>
     * Changes the current Day/Night cycle for this player to daylight<br>
     * - oPlayer: which player to change the lighting for<br>
     * - fTransitionTime: how long the transition should take<br>
    **/
    idempotent void nightToDay(NWObject oPlayer, double fTransitionTime) throws NotInContextException;

    /**<br>
     * Open's this creature's inventory panel for this player<br>
     * - oCreature: creature to view<br>
     * - oPlayer: the owner of this creature will see the panel pop up<br>
     * * DM's can view any creature's inventory<br>
     * * Players can view their own inventory, or that of their henchman, familiar or animal companion<br>
    **/
    void openInventory(NWObject oCreature, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * Open oStore for oPC.<br>
     * - nBonusMarkUp is added to the stores default mark up percentage on items sold (-100 to 100)<br>
     * - nBonusMarkDown is added to the stores default mark down percentage on items bought (-100 to 100)<br>
    **/
    void openStore(NWObject oStore, NWObject oPC, int nBonusMarkUp, int nBonusMarkDown) throws NotInContextException;

    /**<br>
     * Play nAnimation immediately.<br>
     * - nAnimation: ANIMATION_*<br>
     * - fSpeed<br>
     * - fSeconds<br>
    **/
    void playAnimation(int nAnimation, double fSpeed, double fSeconds) throws NotInContextException;

    /**<br>
     * Play sSoundName<br>
     * - sSoundName: TBD - SS<br>
     * This will play a mono sound from the location of the object running the command.<br>
    **/
    void playSound(string sSoundName) throws NotInContextException;

    /**<br>
     * This will play a sound that is associated with a stringRef, it will be a mono sound from the location of the object running the command.<br>
     * if nRunAsAction is off then the sound is forced to play intantly.<br>
    **/
    void playSoundByStrRef(int nStrRef, int nRunAsAction) throws NotInContextException;

    /**<br>
     * Play a voice chat.<br>
     * - nVoiceChatID: VOICE_CHAT_*<br>
     * - oTarget<br>
    **/
    void playVoiceChat(int nVoiceChatID, NWObject oTarget) throws NotInContextException;

    /**<br>
     * Spawn in the Death GUI.<br>
     * The default (as defined by BioWare) can be spawned in by PopUpGUIPanel, but<br>
     * if you want to turn off the "Respawn" or "Wait for Help" buttons, this is the<br>
     * function to use.<br>
     * - oPC<br>
     * - bRespawnButtonEnabled: if this is TRUE, the "Respawn" button will be enabled<br>
     * on the Death GUI.<br>
     * - bWaitForHelpButtonEnabled: if this is TRUE, the "Wait For Help" button will<br>
     * be enabled on the Death GUI (Note: This button will not appear in single player games).<br>
     * - nHelpStringReference<br>
     * - sHelpString<br>
    **/
    void popUpDeathGUIPanel(NWObject oPC, bool bRespawnButtonEnabled, bool bWaitForHelpButtonEnabled, int nHelpStringReference, string sHelpString) throws NotInContextException;

    /**<br>
     * Spawn a GUI panel for the client that controls oPC.<br>
     * - oPC<br>
     * - nGUIPanel: GUI_PANEL_*<br>
     * * Nothing happens if oPC is not a player character or if an invalid value is<br>
     * used for nGUIPanel.<br>
    **/
    void popUpGUIPanel(NWObject oPC, int nGUIPanel) throws NotInContextException;

    /**<br>
     * Generate a random name.<br>
     * nNameType: The type of random name to be generated (NAME_*)<br>
    **/
    string randomName(int nNameType) throws NotInContextException;

    /**<br>
     * All clients in oArea will recompute the static lighting.<br>
     * This can be used to update the lighting after changing any tile lights or if<br>
     * placeables with lights have been added/deleted.<br>
    **/
    void recomputeStaticLighting(NWObject oArea) throws NotInContextException;

    /**<br>
     * Does a Reflex Save check for the given DC<br>
     * - oCreature<br>
     * - nDC: Difficulty check<br>
     * - nSaveType: SAVING_THROW_TYPE_*<br>
     * - oSaveVersus<br>
     * Returns: 0 if the saving throw roll failed<br>
     * Returns: 1 if the saving throw roll succeeded<br>
     * Returns: 2 if the target was immune to the save type specified<br>
     * Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass<br>
     * GetAreaOfEffectCreator() into oSaveVersus!!<br>
    **/
    SavingThrowResult reflexSave(NWObject oCreature, int nDC, SaveType tSaveType, NWObject oSaveVersus) throws NotInContextException;

    /**<br>
     * Remove eEffect from oCreature.<br>
     * * No return value<br>
    **/
    idempotent void removeEffect(NWObject oCreature, NWEffect eEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Remove oPC from their current party. This will only work on a PC.<br>
     * - oPC: removes this player from whatever party they're currently in.<br>
    **/
    idempotent void removeFromParty(NWObject oPC) throws NotInContextException;

    /**<br>
     * Remove oHenchman from the service of oMaster, returning them to their original faction.<br>
    **/
    idempotent void removeHenchman(NWObject oMaster, NWObject oHenchman) throws NotInContextException;

    /**<br>
     * removes an item property from the specified item<br>
    **/
    idempotent void removeItemProperty(NWObject oItem, NWItemProperty ipProperty) throws NotInContextException, InvalidItemPropertyException;

    /**<br>
     * Remove a journal quest entry from oCreature.<br>
     * - szPlotID: the plot identifier used in the toolset's Journal Editor<br>
     * - oCreature<br>
     * - bAllPartyMembers: If this is TRUE, the entry will be removed from the<br>
     * journal of everyone in the party<br>
     * - bAllPlayers: If this is TRUE, the entry will be removed from the journal of<br>
     * everyone in the world<br>
    **/
    idempotent void removeJournalQuestEntry(string szPlotID, NWObject oCreature, bool bAllPartyMembers, bool bAllPlayers) throws NotInContextException;

    /**<br>
     * Removes oAssociate from the service of oMaster, returning them to their<br>
     * original faction.<br>
    **/
    idempotent void removeSummonedAssociate(NWObject oMaster, NWObject oAssociate) throws NotInContextException;

    /**<br>
     * Do a Spell Resistance check between oCaster and oTarget, returning TRUE if<br>
     * the spell was resisted.<br>
     * * Return value if oCaster or oTarget is an invalid object: FALSE<br>
     * * Return value if spell cast is not a player spell: - 1<br>
     * * Return value if spell resisted: 1<br>
     * * Return value if spell resisted via magic immunity: 2<br>
     * * Return value if spell resisted via spell absorption: 3<br>
    **/
    int resistSpell(NWObject oCaster, NWObject oTarget) throws NotInContextException;

    /**<br>
     * Restores the number of base attacks back to it's<br>
     * original state.<br>
    **/
    void restoreBaseAttackBonus(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Restores the camera mode and position to what they were last time StoreCameraFacing<br>
     * was called.  RestoreCameraFacing can only be called once, and must correspond to a<br>
     * previous call to StoreCameraFacing.<br>
    **/
    idempotent void restoreCameraFacing() throws NotInContextException;

    /**<br>
     * Use RetrieveCampaign with the given id to restore it.<br>
     * If you specify an owner, the object will try to be created in their repository<br>
     * If the owner can't handle the item (or if it's a creature) it will be created on the ground.<br>
    **/
    idempotent NWObject retrieveCampaignObject(string sCampaignName, string sVarName, NWLocation locLocation, NWObject oOwner, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * Convert nRounds into a number of seconds<br>
     * A round is always 6.0 seconds<br>
    **/
    idempotent double roundsToSeconds(int nRounds) throws NotInContextException;

    /**<br>
     * Sends szMessage to all the Dungeon Masters currently on the server.<br>
    **/
    void sendMessageToAllDMs(string szMessage) throws NotInContextException;

    /**<br>
     * Send a server message (szMessage) to the oPlayer.<br>
    **/
    void sendMessageToPC(NWObject oPlayer, string szMessage) throws NotInContextException;

    /**<br>
     * Send a server message (szMessage) to the oPlayer.<br>
    **/
    void sendMessageToPCByStrRef(NWObject oPlayer, int nStrRef) throws NotInContextException;

    /**<br>
     * Sets the current AI Level of the creature to the value specified. Does not work on Players.<br>
     * The game by default will choose an appropriate AI level for<br>
     * creatures based on the circumstances that the creature is in.<br>
     * Explicitly setting an AI level will over ride the game AI settings.<br>
     * The new setting will last until SetAILevel is called again with the argument AI_LEVEL_DEFAULT.<br>
     * AI_LEVEL_DEFAULT  - Default setting. The game will take over seting the appropriate AI level when required.<br>
     * AI_LEVEL_VERY_LOW - Very Low priority, very stupid, but low CPU usage for AI. Typically used when no players are in the area.<br>
     * AI_LEVEL_LOW      - Low priority, mildly stupid, but slightly more CPU usage for AI. Typically used when not in combat, but a player is in the area.<br>
     * AI_LEVEL_NORMAL   - Normal priority, average AI, but more CPU usage required for AI. Typically used when creature is in combat.<br>
     * AI_LEVEL_HIGH     - High priority, smartest AI, but extremely high CPU usage required for AI. Avoid using this. It is most likely only ever needed for cutscenes.<br>
    **/
    idempotent void setAILevel(NWObject oTarget, AILevel tAILevel) throws NotInContextException;

    /**<br>
     * Sets the status of modes ACTION_MODE_* on a creature.<br>
    **/
    idempotent void setActionMode(NWObject oCreature, ActionMode tActionMode, bool bStatus) throws NotInContextException;

    /**<br>
     * Set the transition bitmap of a player; this should only be called in area<br>
     * transition scripts. This action should be run by the person "clicking" the<br>
     * area transition via AssignCommand.<br>
     * - nPredefinedAreaTransition:<br>
     * -> To use a predefined area transition bitmap, use one of AREA_TRANSITION_*<br>
     * -> To use a custom, user-defined area transition bitmap, use<br>
     * AREA_TRANSITION_USER_DEFINED and specify the filename in the second<br>
     * parameter<br>
     * - sCustomAreaTransitionBMP: this is the filename of a custom, user-defined<br>
     * area transition bitmap<br>
    **/
    idempotent void setAreaTransitionBMP(int nPredefinedAreaTransition, string sCustomAreaTransitionBMP) throws NotInContextException;

    /**<br>
     * Initialise oTarget to listen for the standard Associates commands.<br>
    **/
    idempotent void setAssociateListenPatterns(NWObject oTarget) throws NotInContextException;

    /**<br>
     * Sets the number of base attacks for the specified<br>
     * creatures. The range of values accepted are from<br>
     * 1 to 6<br>
     * Note: This function does not work on Player Characters<br>
    **/
    idempotent void setBaseAttackBonus(int nBaseAttackBonus, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Set the calendar to the specified date.<br>
     * - nYear should be from 0 to 32000 inclusive<br>
     * - nMonth should be from 1 to 12 inclusive<br>
     * - nDay should be from 1 to 28 inclusive<br>
     * 1) Time can only be advanced forwards; attempting to set the time backwards<br>
     * will result in no change to the calendar.<br>
     * 2) If values larger than the month or day are specified, they will be wrapped<br>
     * around and the overflow will be used to advance the next field.<br>
     * e.g. Specifying a year of 1350, month of 33 and day of 10 will result in<br>
     * the calender being set to a year of 1352, a month of 9 and a day of 10.<br>
    **/
    idempotent void setCalendar(int nYear, int nMonth, int nDay) throws NotInContextException;

    /**<br>
     * Change the direction in which the camera is facing<br>
     * - fDirection is expressed as anticlockwise degrees from Due East.<br>
     * (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)<br>
     * A value of -1.0f for any parameter will be ignored and instead it will<br>
     * use the current camera value.<br>
     * This can be used to change the way the camera is facing after the player<br>
     * emerges from an area transition.<br>
     * - nTransitionType: CAMERA_TRANSITION_TYPE_*  SNAP will immediately move the<br>
     * camera to the new position, while the other types will result in the camera moving gradually into position<br>
     * Pitch and distance are limited to valid values for the current camera mode:<br>
     * Top Down: Distance = 5-20, Pitch = 1-50<br>
     * Driving camera: Distance = 6 (can't be changed), Pitch = 1-62<br>
     * Chase: Distance = 5-20, Pitch = 1-50<br>
     * *** NOTE *** In NWN:Hordes of the Underdark the camera limits have been relaxed to the following:<br>
     * Distance 1-25<br>
     * Pitch 1-89<br>
    **/
    idempotent void setCameraFacing(double fDirection, double fDistance, double fPitch, int nTransitionType) throws NotInContextException;

    /**<br>
     * Forces this player's camera to be set to this height. Setting this value to zero will<br>
     * restore the camera to the racial default height.<br>
    **/
    idempotent void setCameraHeight(NWObject oPlayer, double fHeight) throws NotInContextException;

    /**<br>
     * Set the camera mode for oPlayer.<br>
     * - oPlayer<br>
     * - nCameraMode: CAMERA_MODE_*<br>
     * * If oPlayer is not player-controlled or nCameraMode is invalid, nothing<br>
     * happens.<br>
    **/
    idempotent void setCameraMode(NWObject oPlayer, int nCameraMode) throws NotInContextException;

    /**<br>
     * This stores a float out to the specified campaign database<br>
     * The database name IS case sensitive and it must be the same for both set and get functions.<br>
     * The var name must be unique across the entire database, regardless of the variable type.<br>
     * If you want a variable to pertain to a specific player in the game, provide a player object.<br>
    **/
    idempotent void setCampaignFloat(string sCampaignName, string sVarName, double flFloat, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * This stores an int out to the specified campaign database<br>
     * The database name IS case sensitive and it must be the same for both set and get functions.<br>
     * The var name must be unique across the entire database, regardless of the variable type.<br>
     * If you want a variable to pertain to a specific player in the game, provide a player object.<br>
    **/
    idempotent void setCampaignInt(string sCampaignName, string sVarName, int nInt, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * This stores a location out to the specified campaign database<br>
     * The database name IS case sensitive and it must be the same for both set and get functions.<br>
     * The var name must be unique across the entire database, regardless of the variable type.<br>
     * If you want a variable to pertain to a specific player in the game, provide a player object.<br>
    **/
    idempotent void setCampaignLocation(string sCampaignName, string sVarName, NWLocation locLocation, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * This stores a string out to the specified campaign database<br>
     * The database name IS case sensitive and it must be the same for both set and get functions.<br>
     * The var name must be unique across the entire database, regardless of the variable type.<br>
     * If you want a variable to pertain to a specific player in the game, provide a player object.<br>
    **/
    idempotent void setCampaignString(string sCampaignName, string sVarName, string sString, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * This stores a vector out to the specified campaign database<br>
     * The database name IS case sensitive and it must be the same for both set and get functions.<br>
     * The var name must be unique across the entire database, regardless of the variable type.<br>
     * If you want a variable to pertain to a specific player in the game, provide a player object.<br>
    **/
    idempotent void setCampaignVector(string sCampaignName, string sVarName, NWVector vVector, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * Set the color channel of oObject to the color specified.<br>
     * - oObject: the object for which you are changing the color.<br>
     * Can be a creature that has color information (i.e. the playable races).<br>
     * - nColorChannel: The color channel that you want to set the color value of.<br>
     * COLOR_CHANNEL_SKIN<br>
     * COLOR_CHANNEL_HAIR<br>
     * COLOR_CHANNEL_TATTOO_1<br>
     * COLOR_CHANNEL_TATTOO_2<br>
     * - nColorValue: The color you want to set (0-175).<br>
    **/
    idempotent void setColor(NWObject oObject, int nColorChannel, int nColorValue) throws NotInContextException;

    /**<br>
     * Set whether oTarget's action stack can be modified<br>
    **/
    idempotent void setCommandable(bool bCommandable, NWObject oTarget) throws NotInContextException;

    /**<br>
     * Sets the creature's appearance type to the value specified (uses the APPEARANCE_TYPE_XXX constants)<br>
    **/
    idempotent void setCreatureAppearanceType(NWObject oCreature, int nAppearanceType) throws NotInContextException;

    /**<br>
     * Sets the body part model to be used on the creature specified.<br>
     * The model names for parts need to be in the following format:<br>
     * p<m/f><race letter><phenotype>_<body part><model number>.mdl<br>
     * <br>
     * - nPart (CREATURE_PART_*)<br>
     * CREATURE_PART_RIGHT_FOOT<br>
     * CREATURE_PART_LEFT_FOOT<br>
     * CREATURE_PART_RIGHT_SHIN<br>
     * CREATURE_PART_LEFT_SHIN<br>
     * CREATURE_PART_RIGHT_THIGH<br>
     * CREATURE_PART_LEFT_THIGH<br>
     * CREATURE_PART_PELVIS<br>
     * CREATURE_PART_TORSO<br>
     * CREATURE_PART_BELT<br>
     * CREATURE_PART_NECK<br>
     * CREATURE_PART_RIGHT_FOREARM<br>
     * CREATURE_PART_LEFT_FOREARM<br>
     * CREATURE_PART_RIGHT_BICEP<br>
     * CREATURE_PART_LEFT_BICEP<br>
     * CREATURE_PART_RIGHT_SHOULDER<br>
     * CREATURE_PART_LEFT_SHOULDER<br>
     * CREATURE_PART_RIGHT_HAND<br>
     * CREATURE_PART_LEFT_HAND<br>
     * CREATURE_PART_HEAD<br>
     * - nModelNumber: CREATURE_MODEL_TYPE_*<br>
     * CREATURE_MODEL_TYPE_NONE<br>
     * CREATURE_MODEL_TYPE_SKIN (not for use on shoulders, pelvis or head).<br>
     * CREATURE_MODEL_TYPE_TATTOO (for body parts that support tattoos, i.e. not heads/feet/hands).<br>
     * CREATURE_MODEL_TYPE_UNDEAD (undead model only exists for the right arm parts).<br>
     * - oCreature: the creature to change the body part for.<br>
     * Note: Only part based creature appearance types are supported.<br>
     * i.e. The model types for the playable races ('P') in the appearance.2da<br>
    **/
    idempotent void setCreatureBodyPart(CreaturePart tCreaturePart, int nModelNumber, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Sets the Tail type of the creature specified.<br>
     * - nTailType (CREATURE_TAIL_TYPE_*)<br>
     * CREATURE_TAIL_TYPE_NONE<br>
     * CREATURE_TAIL_TYPE_LIZARD<br>
     * CREATURE_TAIL_TYPE_BONE<br>
     * CREATURE_TAIL_TYPE_DEVIL<br>
     * - oCreature: the creature to change the Tail type for.<br>
     * Note: Only two creature model types will support Tails.<br>
     * The MODELTYPE for the part based (playable) races 'P'<br>
     * and MODELTYPE 'T'in the appearance.2da<br>
    **/
    idempotent void setCreatureTailType(int nTailType, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Sets the Wing type of the creature specified.<br>
     * - nWingType (CREATURE_WING_TYPE_*)<br>
     * CREATURE_WING_TYPE_NONE<br>
     * CREATURE_WING_TYPE_DEMON<br>
     * CREATURE_WING_TYPE_ANGEL<br>
     * CREATURE_WING_TYPE_BAT<br>
     * CREATURE_WING_TYPE_DRAGON<br>
     * CREATURE_WING_TYPE_BUTTERFLY<br>
     * CREATURE_WING_TYPE_BIRD<br>
     * - oCreature: the creature to change the wing type for.<br>
     * Note: Only two creature model types will support wings.<br>
     * The MODELTYPE for the part based (playable races) 'P'<br>
     * and MODELTYPE 'W'in the appearance.2da<br>
    **/
    idempotent void setCreatureWingType(int nWingType, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Set the value for a custom token.<br>
    **/
    idempotent void setCustomToken(int nCustomTokenNumber, string sTokenValue) throws NotInContextException;

    /**<br>
     * Sets the current movement rate factor for the cutscene<br>
     * camera man.<br>
     * NOTE: You can only set values between 0.1, 2.0 (10%-200%)<br>
    **/
    idempotent void setCutsceneCameraMoveRate(NWObject oCreature, double fRate) throws NotInContextException;

    /**<br>
     * Sets the given creature into cutscene mode.  This prevents the player from<br>
     * using the GUI and camera controls.<br>
     * - oCreature: creature in a cutscene<br>
     * - nInCutscene: TRUE to move them into cutscene, FALSE to remove cutscene mode<br>
     * - nLeftClickingEnabled: TRUE to allow the user to interact with the game world using the left mouse button only.<br>
     * FALSE to stop the user from interacting with the game world.<br>
     * Note: SetCutsceneMode(oPlayer, TRUE) will also make the player 'plot' (unkillable).<br>
     * SetCutsceneMode(oPlayer, FALSE) will restore the player's plot flag to what it<br>
     * was when SetCutsceneMode(oPlayer, TRUE) was called.<br>
    **/
    idempotent void setCutsceneMode(NWObject oCreature, bool bInCutscene, bool bLeftClickingEnabled) throws NotInContextException;

    /**<br>
     * Set the name of oCreature's Deity to sDeity.<br>
    **/
    idempotent void setDeity(NWObject oCreature, string sDeity) throws NotInContextException;

    /**<br>
     * Set the description of oObject.<br>
     * - oObject: the object for which you are changing the description<br>
     * Can be a creature, placeable, item, door, or trigger.<br>
     * - sNewDescription: the new description that the object will use.<br>
     * - bIdentified: If oObject is an item, setting this to TRUE will set the identified description,<br>
     * setting this to FALSE will set the unidentified description. This flag has no<br>
     * effect on objects other than items.<br>
     * Note: Setting an object's description to "" will make the object<br>
     * revert to using the description it originally had before any<br>
     * SetDescription() calls were made on the object.<br>
    **/
    idempotent void setDescription(NWObject oObject, string sNewDescription, bool bIdentifiedDescription) throws NotInContextException;

    /**<br>
     * Sets the droppable flag on an item<br>
     * - oItem: the item to change<br>
     * - bDroppable: TRUE or FALSE, whether the item should be droppable<br>
     * Droppable items will appear on a creature's remains when the creature is killed.<br>
    **/
    idempotent void setDroppableFlag(NWObject oItem, bool bDroppable) throws NotInContextException;

    /**<br>
     * Set oEncounter's active state to nNewValue.<br>
     * - nNewValue: TRUE/FALSE<br>
     * - oEncounter<br>
    **/
    idempotent void setEncounterActive(bool bNewValue, NWObject oEncounter) throws NotInContextException;

    /**<br>
     * Set the difficulty level of oEncounter.<br>
     * - nEncounterDifficulty: ENCOUNTER_DIFFICULTY_*<br>
     * - oEncounter<br>
    **/
    idempotent void setEncounterDifficulty(int nEncounterDifficulty, NWObject oEncounter) throws NotInContextException;

    /**<br>
     * Set the number of times that oEncounter has spawned so far<br>
    **/
    idempotent void setEncounterSpawnsCurrent(int nNewValue, NWObject oEncounter) throws NotInContextException;

    /**<br>
     * Set the maximum number of times that oEncounter can spawn<br>
    **/
    idempotent void setEncounterSpawnsMax(int nNewValue, NWObject oEncounter) throws NotInContextException;

    /**<br>
     * Cause the caller to face fDirection.<br>
     * - fDirection is expressed as anticlockwise degrees from Due East.<br>
     * DIRECTION_EAST, DIRECTION_NORTH, DIRECTION_WEST and DIRECTION_SOUTH are<br>
     * predefined. (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)<br>
    **/
    idempotent void setFacing(double fDirection) throws NotInContextException;

    /**<br>
     * Cause the caller to face vTarget<br>
    **/
    idempotent void setFacingPoint(NWVector vTarget) throws NotInContextException;

    /**<br>
     * Sets the fog amount in the area specified.<br>
     * nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.<br>
     * nFogAmount = specifies the density that the fog is being set to.<br>
     * If no valid area (or object) is specified, it uses the area of caller.<br>
     * If an object other than an area is specified, will use the area that the object is currently in.<br>
    **/
    idempotent void setFogAmount(int nFogType, int nFogAmount, NWObject oArea) throws NotInContextException;

    /**<br>
     * Sets the fog color in the area specified.<br>
     * nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.<br>
     * nFogColor = FOG_COLOR_* specifies the color the fog is being set to.<br>
     * The fog color can also be represented as a hex RGB number if specific color shades<br>
     * are desired.<br>
     * The format of a hex specified color would be 0xFFEEDD where<br>
     * FF would represent the amount of red in the color<br>
     * EE would represent the amount of green in the color<br>
     * DD would represent the amount of blue in the color.<br>
     * If no valid area (or object) is specified, it uses the area of caller.<br>
     * If an object other than an area is specified, will use the area that the object is currently in.<br>
    **/
    idempotent void setFogColor(int nFogType, int nFogColor, NWObject oArea) throws NotInContextException;

    /**<br>
     * Sets the footstep type of the creature specified.<br>
     * Changing a creature's footstep type will change the sound that<br>
     * its feet make when ever the creature makes takes a step.<br>
     * By default a creature's footsteps are detemined by the appearance<br>
     * type of the creature. SetFootstepType() allows you to make a<br>
     * creature use a difference footstep type than it would use by default<br>
     * for its given appearance.<br>
     * - nFootstepType (FOOTSTEP_TYPE_*):<br>
     * FOOTSTEP_TYPE_NORMAL<br>
     * FOOTSTEP_TYPE_LARGE<br>
     * FOOTSTEP_TYPE_DRAGON<br>
     * FOOTSTEP_TYPE_SoFT<br>
     * FOOTSTEP_TYPE_HOOF<br>
     * FOOTSTEP_TYPE_HOOF_LARGE<br>
     * FOOTSTEP_TYPE_BEETLE<br>
     * FOOTSTEP_TYPE_SPIDER<br>
     * FOOTSTEP_TYPE_SKELETON<br>
     * FOOTSTEP_TYPE_LEATHER_WING<br>
     * FOOTSTEP_TYPE_FEATHER_WING<br>
     * FOOTSTEP_TYPE_DEFAULT - Makes the creature use its original default footstep sounds.<br>
     * FOOTSTEP_TYPE_NONE<br>
     * - oCreature: the creature to change the footstep sound for.<br>
    **/
    idempotent void setFootstepType(int nFootstepType, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Set the Fortitude saving throw value of the Door or Placeable object oObject.<br>
     * - oObject: a door or placeable object.<br>
     * - nFortitudeSave: must be between 0 and 250.<br>
    **/
    idempotent void setFortitudeSavingThrow(NWObject oObject, int nFortitudeSave) throws NotInContextException;

    /**<br>
     * Sets the Hardness of a Door or Placeable object.<br>
     * - nHardness: must be between 0 and 250.<br>
     * - oObject: a door or placeable object.<br>
     * Does nothing if used on an object that is neither<br>
     * a door nor a placeable.<br>
    **/
    idempotent void setHardness(int nHardness, NWObject oObject) throws NotInContextException;

    /**<br>
     * Set whether oItem has been identified.<br>
    **/
    idempotent void setIdentified(NWObject oItem, bool bIdentified) throws NotInContextException;

    /**<br>
     * Set a creature's immortality flag.<br>
     * -oCreature: creature affected<br>
     * -bImmortal: TRUE = creature is immortal and cannot be killed (but still takes damage)<br>
     * FALSE = creature is not immortal and is damaged normally.<br>
     * This scripting command only works on Creature objects.<br>
    **/
    idempotent void setImmortal(NWObject oCreature, bool bImmortal) throws NotInContextException;

    /**<br>
     * Sets the Infinite flag on an item<br>
     * - oItem: the item to change<br>
     * - bInfinite: TRUE or FALSE, whether the item should be Infinite<br>
     * The infinite property affects the buying/selling behavior of the item in a store.<br>
     * An infinite item will still be available to purchase from a store after a player<br>
     * buys the item (non-infinite items will disappear from the store when purchased).<br>
    **/
    idempotent void setInfiniteFlag(NWObject oItem, bool bInfinite) throws NotInContextException;

    /**<br>
     * Set the destroyable status of the caller.<br>
     * - bDestroyable: If this is FALSE, the caller does not fade out on death, but<br>
     * sticks around as a corpse.<br>
     * - bRaiseable: If this is TRUE, the caller can be raised via resurrection.<br>
     * - bSelectableWhenDead: If this is TRUE, the caller is selectable after death.<br>
    **/
    idempotent void setIsDestroyable(bool bDestroyable, bool bRaiseable, bool bSelectableWhenDead) throws NotInContextException;

    /**<br>
     * Make oSource into a temporary enemy of oTarget using personal reputation.<br>
     * - oTarget<br>
     * - oSource<br>
     * - bDecays: If this is TRUE, the enmity decays over fDurationInSeconds;<br>
     * otherwise it is indefinite.<br>
     * - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long<br>
     * the enmity lasts.<br>
     * Note: If bDecays is TRUE, the personal reputation amount decreases in size<br>
     * over fDurationInSeconds. Enmity will only be in effect as long as<br>
     * (faction reputation + total personal reputation) <= REPUTATION_TYPE_ENEMY.<br>
    **/
    idempotent void setIsTemporaryEnemy(NWObject oTarget, NWObject oSource, bool bDecays, double fDurationInSeconds) throws NotInContextException;

    /**<br>
     * oSource will temporarily be friends towards oTarget.<br>
     * bDecays determines whether the personal reputation value decays over time<br>
     * fDurationInSeconds is the length of time that the temporary friendship lasts<br>
     * Make oSource into a temporary friend of oTarget using personal reputation.<br>
     * - oTarget<br>
     * - oSource<br>
     * - bDecays: If this is TRUE, the friendship decays over fDurationInSeconds;<br>
     * otherwise it is indefinite.<br>
     * - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long<br>
     * the friendship lasts.<br>
     * Note: If bDecays is TRUE, the personal reputation amount decreases in size<br>
     * over fDurationInSeconds. Friendship will only be in effect as long as<br>
     * (faction reputation + total personal reputation) >= REPUTATION_TYPE_FRIEND.<br>
    **/
    idempotent void setIsTemporaryFriend(NWObject oTarget, NWObject oSource, bool bDecays, double fDurationInSeconds) throws NotInContextException;

    /**<br>
     * Make oSource temporarily neutral to oTarget using personal reputation.<br>
     * - oTarget<br>
     * - oSource<br>
     * - bDecays: If this is TRUE, the neutrality decays over fDurationInSeconds;<br>
     * otherwise it is indefinite.<br>
     * - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long<br>
     * the neutrality lasts.<br>
     * Note: If bDecays is TRUE, the personal reputation amount decreases in size<br>
     * over fDurationInSeconds. Neutrality will only be in effect as long as<br>
     * (faction reputation + total personal reputation) > REPUTATION_TYPE_ENEMY and<br>
     * (faction reputation + total personal reputation) < REPUTATION_TYPE_FRIEND.<br>
    **/
    idempotent void setIsTemporaryNeutral(NWObject oTarget, NWObject oSource, bool bDecays, double fDurationInSeconds) throws NotInContextException;

    /**<br>
     * Sets charges left on an item.<br>
     * - oItem: item to change<br>
     * - nCharges: number of charges.  If value below 0 is passed, # charges will<br>
     * be set to 0.  If value greater than maximum is passed, # charges will<br>
     * be set to maximum.  If the # charges drops to 0 the item<br>
     * will be destroyed.<br>
    **/
    idempotent void setItemCharges(NWObject oItem, int nCharges) throws NotInContextException;

    /**<br>
     * When cursed, items cannot be dropped<br>
    **/
    idempotent void setItemCursedFlag(NWObject oItem, bool bCursed) throws NotInContextException;

    /**<br>
     * Sets stack size of an item.<br>
     * - oItem: item to change<br>
     * - nSize: new size of stack.  Will be restricted to be between 1 and the<br>
     * maximum stack size for the item type.  If a value less than 1 is passed it<br>
     * will set the stack to 1.  If a value greater than the max is passed<br>
     * then it will set the stack to the maximum size<br>
    **/
    idempotent void setItemStackSize(NWObject oItem, int nSize) throws NotInContextException;

    /**<br>
     * Set the feedback message that is displayed when trying to unlock the object oObject.<br>
     * This will only have an effect if the object is set to<br>
     * "Key required to unlock or lock" either in the toolset<br>
     * or by using the scripting command SetLockKeyRequired().<br>
     * - oObject: a door or placeable.<br>
     * - sFeedbackMessage: the string to be displayed in the player's text window.<br>
     * to use the game's default message, set sFeedbackMessage to ""<br>
    **/
    idempotent void setKeyRequiredFeedback(NWObject oObject, string sFeedbackMessage) throws NotInContextException;

    /**<br>
     * Set the string for oObject to listen for.<br>
     * Note: this does not set oObject to be listening.<br>
    **/
    idempotent void setListenPattern(NWObject oObject, string sPattern, int nNumber) throws NotInContextException;

    /**<br>
     * Set whether oObject is listening.<br>
    **/
    idempotent void setListening(NWObject oObject, bool bValue) throws NotInContextException;

    /**<br>
     * Set oObject's local float variable sVarName to nValue<br>
    **/
    idempotent void setLocalFloat(NWObject oObject, string sVarName, double fValue) throws NotInContextException;

    /**<br>
     * Set oObject's local integer variable sVarName to nValue<br>
    **/
    idempotent void setLocalInt(NWObject oObject, string sVarName, int nValue) throws NotInContextException;

    /**<br>
     * Set oObject's local location variable sVarname to lValue<br>
    **/
    idempotent void setLocalLocation(NWObject oObject, string sVarName, NWLocation lValue) throws NotInContextException;

    /**<br>
     * Set oObject's local object variable sVarName to nValue<br>
    **/
    idempotent void setLocalObject(NWObject oObject, string sVarName, NWObject oValue) throws NotInContextException;

    /**<br>
     * Set oObject's local string variable sVarName to nValue<br>
    **/
    idempotent void setLocalString(NWObject oObject, string sVarName, string sValue) throws NotInContextException;

    /**<br>
     * When set the object can not be opened unless the<br>
     * opener possesses the required key. The key tag required<br>
     * can be specified either in the toolset, or by using<br>
     * the SetLockKeyTag() scripting command.<br>
     * - oObject: a door, or placeable.<br>
     * - nKeyRequired: TRUE/FALSE<br>
    **/
    idempotent void setLockKeyRequired(NWObject oObject, bool bKeyRequired) throws NotInContextException;

    /**<br>
     * Set the key tag required to open object oObject.<br>
     * This will only have an effect if the object is set to<br>
     * "Key required to unlock or lock" either in the toolset<br>
     * or by using the scripting command SetLockKeyRequired().<br>
     * - oObject: a door, placeable or trigger.<br>
     * - sNewKeyTag: the key tag required to open the locked object.<br>
    **/
    idempotent void setLockKeyTag(NWObject oObject, string sNewKeyTag) throws NotInContextException;

    /**<br>
     * Sets the DC for locking the object.<br>
     * - oObject: a door or placeable object.<br>
     * - nNewLockDC: must be between 0 and 250.<br>
    **/
    idempotent void setLockLockDC(NWObject oObject, int nNewLockDC) throws NotInContextException;

    /**<br>
     * Sets whether or not the object can be locked.<br>
     * - oObject: a door or placeable.<br>
     * - nLockable: TRUE/FALSE<br>
    **/
    idempotent void setLockLockable(NWObject oObject, bool bLockable) throws NotInContextException;

    /**<br>
     * Sets the DC for unlocking the object.<br>
     * - oObject: a door or placeable object.<br>
     * - nNewUnlockDC: must be between 0 and 250.<br>
    **/
    idempotent void setLockUnlockDC(NWObject oObject, int nNewUnlockDC) throws NotInContextException;

    /**<br>
     * Set the locked state of oTarget, which can be a door or a placeable object.<br>
    **/
    idempotent void setLocked(NWObject oTarget, bool bLocked) throws NotInContextException;

    /**<br>
     * Sets the lootable state of a *living* NPC creature.<br>
     * This function will *not* work on players or dead creatures.<br>
    **/
    idempotent void setLootable(NWObject oCreature, bool bLootable) throws NotInContextException;

    /**<br>
     * Set whether oMapPin is enabled.<br>
     * - oMapPin<br>
     * - nEnabled: 0=Off, 1=On<br>
    **/
    idempotent void setMapPinEnabled(NWObject oMapPin, bool bEnabled) throws NotInContextException;

    /**<br>
     * Sets the maximum number of henchmen<br>
    **/
    idempotent void setMaxHenchmen(int nNumHenchmen) throws NotInContextException;

    /**<br>
     * Set the XP scale used by the module.<br>
     * - nXPScale: The XP scale to be used. Must be between 0 and 200.<br>
    **/
    idempotent void setModuleXPScale(int nXPScale) throws NotInContextException;

    /**<br>
     * Set the name of oObject.<br>
     * - oObject: the object for which you are changing the name (a creature, placeable, item, or door).<br>
     * - sNewName: the new name that the object will use.<br>
     * Note: SetName() does not work on player objects.<br>
     * Setting an object's name to "" will make the object<br>
     * revert to using the name it had originally before any<br>
     * SetName() calls were made on the object.<br>
    **/
    idempotent void setName(NWObject oObject, string sNewName) throws NotInContextException;

    /**<br>
     * Set the last player chat(text) message before it gets sent to other players.<br>
     * - sNewChatMessage: The new chat text to be sent onto other players.<br>
     * Setting the player chat message to an empty string "",<br>
     * will cause the chat message to be discarded<br>
     * (i.e. it will not be sent to other players).<br>
     * Note: The new chat message gets sent after the OnPlayerChat script exits.<br>
    **/
    idempotent void setPCChatMessage(string sNewChatMessage) throws NotInContextException;

    /**<br>
     * Set the last player chat(text) volume before it gets sent to other players.<br>
     * - nTalkVolume: The new volume of the chat text to be sent onto other players.<br>
     * TALKVOLUME_TALK<br>
     * TALKVOLUME_WHISPER<br>
     * TALKVOLUME_SHOUT<br>
     * TALKVOLUME_SILENT_SHOUT (used for DM chat channel)<br>
     * TALKVOLUME_PARTY<br>
     * TALKVOLUME_TELL (sends the chat message privately back to the original speaker)<br>
     * Note: The new chat message gets sent after the OnPlayerChat script exits.<br>
    **/
    idempotent void setPCChatVolume(TalkVolume tTalkVolume) throws NotInContextException;

    /**<br>
     * Sets oPlayer and oTarget to dislike each other.<br>
    **/
    idempotent void setPCDislike(NWObject oPlayer, NWObject oTarget) throws NotInContextException;

    /**<br>
     * Sets oPlayer and oTarget to like each other.<br>
    **/
    idempotent void setPCLike(NWObject oPlayer, NWObject oTarget) throws NotInContextException;

    /**<br>
     * Make the corresponding panel button on the player's client start or stop<br>
     * flashing.<br>
     * - oPlayer<br>
     * - nButton: PANEL_BUTTON_*<br>
     * - nEnableFlash: if this is TRUE nButton will start flashing.  It if is FALSE,<br>
     * nButton will stop flashing.<br>
    **/
    idempotent void setPanelButtonFlash(NWObject oPlayer, Button tButton, bool bEnableFlash) throws NotInContextException;

    /**<br>
     * Sets the creature's PhenoType (body type) to the type specified.<br>
     * nPhenoType = PHENOTYPE_NORMAL<br>
     * nPhenoType = PHENOTYPE_BIG<br>
     * nPhenoType = PHENOTYPE_CUSTOM* - The custom PhenoTypes should only ever<br>
     * be used if you have specifically created your own custom content that<br>
     * requires the use of a new PhenoType and you have specified the appropriate<br>
     * custom PhenoType in your custom content.<br>
     * SetPhenoType will only work on part based creature (i.e. the starting<br>
     * default playable races).<br>
    **/
    idempotent void setPhenoType(PhenoType tPhenoType, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Sets the Pickpocketable flag on an item<br>
     * - oItem: the item to change<br>
     * - bPickpocketable: TRUE or FALSE, whether the item can be pickpocketed.<br>
    **/
    idempotent void setPickpocketableFlag(NWObject oItem, bool bPickpocketable) throws NotInContextException;

    /**<br>
     * Set the status of the illumination for oPlaceable.<br>
     * - oPlaceable<br>
     * - bIlluminate: if this is TRUE, oPlaceable's illumination will be turned on.<br>
     * If this is FALSE, oPlaceable's illumination will be turned off.<br>
     * Note: You must call RecomputeStaticLighting() after calling this function in<br>
     * order for the changes to occur visually for the players.<br>
     * SetPlaceableIllumination() buffers the illumination changes, which are then<br>
     * sent out to the players once RecomputeStaticLighting() is called.  As such,<br>
     * it is best to call SetPlaceableIllumination() for all the placeables you wish<br>
     * to set the illumination on, and then call RecomputeStaticLighting() once after<br>
     * all the placeable illumination has been set.<br>
     * * If oPlaceable is not a placeable object, or oPlaceable is a placeable that<br>
     * doesn't have a light, nothing will happen.<br>
    **/
    idempotent void setPlaceableIllumination(NWObject oPlaceable, bool bIlluminate) throws NotInContextException;

    /**<br>
     * Set oTarget's plot object status.<br>
    **/
    idempotent void setPlotFlag(NWObject oTarget, bool bPlotFlag) throws NotInContextException;

    /**<br>
     * Change the portrait of oTarget to use the Portrait Id specified.<br>
     * - oTarget: the object for which you are changing the portrait.<br>
     * - nPortraitId: The Id of the new portrait to use.<br>
     * nPortraitId refers to a row in the Portraits.2da<br>
     * Note: Not all portrait Ids are suitable for use with all object types.<br>
     * Setting the portrait Id will also cause the portrait ResRef<br>
     * to be set to the appropriate portrait ResRef for the Id specified.<br>
    **/
    idempotent void setPortraitId(NWObject oTarget, int nPortraitId) throws NotInContextException;

    /**<br>
     * Change the portrait of oTarget to use the Portrait ResRef specified.<br>
     * - oTarget: the object for which you are changing the portrait.<br>
     * - sPortraitResRef: The ResRef of the new portrait to use.<br>
     * The ResRef should not include any trailing size letter ( e.g. po_el_f_09_ ).<br>
     * Note: Not all portrait ResRefs are suitable for use with all object types.<br>
     * Setting the portrait ResRef will also cause the portrait Id<br>
     * to be set to PORTRAIT_INVALID.<br>
    **/
    idempotent void setPortraitResRef(NWObject oTarget, string sPortraitResRef) throws NotInContextException;

    /**<br>
     * Set the Reflex saving throw value of the Door or Placeable object oObject.<br>
     * - oObject: a door or placeable object.<br>
     * - nReflexSave: must be between 0 and 250.<br>
    **/
    idempotent void setReflexSavingThrow(NWObject oObject, int nReflexSave) throws NotInContextException;

    /**<br>
     * Changes the sky that is displayed in the specified area.<br>
     * nSkyBox = SKYBOX_* constants (associated with skyboxes.2da)<br>
     * If no valid area (or object) is specified, it uses the area of caller.<br>
     * If an object other than an area is specified, will use the area that the object is currently in.<br>
    **/
    idempotent void setSkyBox(int nSkyBox, NWObject oArea) throws NotInContextException;

    /**<br>
     * Set how nStandardFaction feels about oCreature.<br>
     * - nStandardFaction: STANDARD_FACTION_*<br>
     * - nNewReputation: 0-100 (inclusive)<br>
     * - oCreature<br>
    **/
    idempotent void setStandardFactionReputation(StandardFaction tStandardFaction, int nNewReputation, NWObject oCreature) throws NotInContextException;

    /**<br>
     * Sets whether this item is 'stolen' or not<br>
    **/
    idempotent void setStolenFlag(NWObject oItem, bool bStolenFlag) throws NotInContextException;

    /**<br>
     * Sets the amount of gold a store has. -1 means the store does not use gold.<br>
    **/
    idempotent void setStoreGold(NWObject oidStore, int nGold) throws NotInContextException;

    /**<br>
     * Sets the amount a store charges for identifying an item. Default is 100. -1 means<br>
     * the store will not identify items.<br>
    **/
    idempotent void setStoreIdentifyCost(NWObject oidStore, int nCost) throws NotInContextException;

    /**<br>
     * Sets the maximum amount a store will pay for any item. -1 means price unlimited.<br>
    **/
    idempotent void setStoreMaxBuyPrice(NWObject oidStore, int nMaxBuy) throws NotInContextException;

    /**<br>
     * Set the name of oCreature's sub race to sSubRace.<br>
    **/
    idempotent void setSubRace(NWObject oCreature, string sSubRace) throws NotInContextException;

    /**<br>
     * Set the main light color on the tile at lTileLocation.<br>
     * - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of<br>
     * the tile.<br>
     * - nMainLight1Color: TILE_MAIN_LIGHT_COLOR_*<br>
     * - nMainLight2Color: TILE_MAIN_LIGHT_COLOR_*<br>
    **/
    idempotent void setTileMainLightColor(NWLocation lTileLocation, TileMainLightColor nMainLight1Color, TileMainLightColor nMainLight2Color) throws NotInContextException;

    /**<br>
     * Set the source light color on the tile at lTileLocation.<br>
     * - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of<br>
     * the tile.<br>
     * - nSourceLight1Color: TILE_SOURCE_LIGHT_COLOR_*<br>
     * - nSourceLight2Color: TILE_SOURCE_LIGHT_COLOR_*<br>
    **/
    idempotent void setTileSourceLightColor(NWLocation lTileLocation, TileSourceLightColor nSourceLight1Color, TileSourceLightColor nSourceLight2Color) throws NotInContextException;

    /**<br>
     * Set the time to the time specified.<br>
     * - nHour should be from 0 to 23 inclusive<br>
     * - nMinute should be from 0 to 59 inclusive<br>
     * - nSecond should be from 0 to 59 inclusive<br>
     * - nMillisecond should be from 0 to 999 inclusive<br>
     * 1) Time can only be advanced forwards; attempting to set the time backwards<br>
     * will result in the day advancing and then the time being set to that<br>
     * specified, e.g. if the current hour is 15 and then the hour is set to 3,<br>
     * the day will be advanced by 1 and the hour will be set to 3.<br>
     * 2) If values larger than the max hour, minute, second or millisecond are<br>
     * specified, they will be wrapped around and the overflow will be used to<br>
     * advance the next field, e.g. specifying 62 hours, 250 minutes, 10 seconds<br>
     * and 10 milliseconds will result in the calendar day being advanced by 2<br>
     * and the time being set to 18 hours, 10 minutes, 10 milliseconds.<br>
    **/
    idempotent void setTime(int nHour, int nMinute, int nSecond, int nMillisecond) throws NotInContextException;

    /**<br>
     * Sets whether or not the trap is an active trap<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * - nActive: TRUE/FALSE<br>
     * Notes:<br>
     * Setting a trap as inactive will not make the<br>
     * trap disappear if it has already been detected.<br>
     * Call SetTrapDetectedBy() to make a detected trap disappear.<br>
     * To make an inactive trap not detectable call SetTrapDetectable()<br>
    **/
    idempotent void setTrapActive(NWObject oTrapObject, bool bActive) throws NotInContextException;

    /**<br>
     * Set the DC for detecting oTrapObject.<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * - nDetectDC: must be between 0 and 250.<br>
    **/
    idempotent void setTrapDetectDC(NWObject oTrapObject, int nDetectDC) throws NotInContextException;

    /**<br>
     * Sets whether or not the trapped object can be detected.<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * - nDetectable: TRUE/FALSE<br>
     * Note: Setting a trapped object to not be detectable will<br>
     * not make the trap disappear if it has already been detected.<br>
    **/
    idempotent void setTrapDetectable(NWObject oTrapObject, bool bDetectable) throws NotInContextException;

    /**<br>
     * Set whether or not the creature oDetector has detected the trapped object oTrap.<br>
     * - oTrap: A trapped trigger, placeable or door object.<br>
     * - oDetector: This is the creature that the detected status of the trap is being adjusted for.<br>
     * - bDetected: A Boolean that sets whether the trapped object has been detected or not.<br>
    **/
    idempotent int setTrapDetectedBy(NWObject oTrap, NWObject oDetector, bool bDetected) throws NotInContextException;

    /**<br>
     * Disable oTrap.<br>
     * - oTrap: a placeable, door or trigger.<br>
    **/
    idempotent void setTrapDisabled(NWObject oTrap) throws NotInContextException;

    /**<br>
     * Set the DC for disarming oTrapObject.<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * - nDisarmDC: must be between 0 and 250.<br>
    **/
    idempotent void setTrapDisarmDC(NWObject oTrapObject, int nDisarmDC) throws NotInContextException;

    /**<br>
     * Sets whether or not the trapped object can be disarmed.<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * - nDisarmable: TRUE/FALSE<br>
    **/
    idempotent void setTrapDisarmable(NWObject oTrapObject, bool bDisarmable) throws NotInContextException;

    /**<br>
     * Set the tag of the key that will disarm oTrapObject.<br>
     * - oTrapObject: a placeable, door or trigger<br>
    **/
    idempotent void setTrapKeyTag(NWObject oTrapObject, string sKeyTag) throws NotInContextException;

    /**<br>
     * Sets whether or not the trap is a one-shot trap<br>
     * (i.e. whether or not the trap resets itself after firing).<br>
     * - oTrapObject: a placeable, door or trigger<br>
     * - nOneShot: TRUE/FALSE<br>
    **/
    idempotent void setTrapOneShot(NWObject oTrapObject, bool bOneShot) throws NotInContextException;

    /**<br>
     * Sets whether or not the trapped object can be recovered.<br>
     * - oTrapObject: a placeable, door or trigger<br>
    **/
    idempotent void setTrapRecoverable(NWObject oTrapObject, bool bRecoverable) throws NotInContextException;

    /**<br>
     * Set oPlaceable's useable object status.<br>
     * Note: Only works on non-static placeables.<br>
    **/
    idempotent void setUseableFlag(NWObject oPlaceable, bool bUseableFlag) throws NotInContextException;

    /**<br>
     * Set the weather for oTarget.<br>
     * - oTarget: if this is GetModule(), all outdoor areas will be modified by the<br>
     * weather constant. If it is an area, oTarget will play the weather only if<br>
     * it is an outdoor area.<br>
     * - nWeather: WEATHER_*<br>
     * -> WEATHER_USER_AREA_SETTINGS will set the area back to random weather.<br>
     * -> WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW will make the weather go to<br>
     * the appropriate precipitation *without stopping*.<br>
    **/
    idempotent void setWeather(NWObject oTarget, Weather tWeather) throws NotInContextException;

    /**<br>
     * Set the Will saving throw value of the Door or Placeable object oObject.<br>
     * - oObject: a door or placeable object.<br>
     * - nWillSave: must be between 0 and 250.<br>
    **/
    idempotent void setWillSavingThrow(NWObject oObject, int nWillSave) throws NotInContextException;

    /**<br>
     * Sets oCreature's experience to nXpAmount.<br>
    **/
    idempotent void setXP(NWObject oCreature, int nXpAmount) throws NotInContextException;

    /**<br>
     * Play oSound.<br>
    **/
    idempotent void soundObjectPlay(NWObject oSound) throws NotInContextException;

    /**<br>
     * Set the position of oSound.<br>
    **/
    idempotent void soundObjectSetPosition(NWObject oSound, NWVector vPosition) throws NotInContextException;

    /**<br>
     * Set the volume of oSound.<br>
     * - oSound<br>
     * - nVolume: 0-127<br>
    **/
    idempotent void soundObjectSetVolume(NWObject oSound, int nVolume) throws NotInContextException;

    /**<br>
     * Stop playing oSound.<br>
    **/
    idempotent void soundObjectStop(NWObject oSound) throws NotInContextException;

    /**<br>
     * Immediately speak a conversation one-liner.<br>
     * - sDialogResRef<br>
     * - oTokenTarget: This must be specified if there are creature-specific tokens<br>
     * in the string.<br>
    **/
    void speakOneLinerConversation(string sDialogResRef, NWObject oTokenTarget) throws NotInContextException;

    /**<br>
     * The caller will immediately speak sStringToSpeak (this is different from<br>
     * ActionSpeakString)<br>
     * - sStringToSpeak<br>
     * - nTalkVolume: TALKVOLUME_*<br>
    **/
    void speakString(string sStringToSpeak, TalkVolume tTalkVolume) throws NotInContextException;

    /**<br>
     * Causes the object to instantly speak a translated string.<br>
     * (not an action, not blocked when uncommandable)<br>
     * - nStrRef: Reference of the string in the talk table<br>
     * - nTalkVolume: TALKVOLUME_*<br>
    **/
    void speakStringByStrRef(int nStrRef, TalkVolume tTalkVolume) throws NotInContextException;

    /**<br>
     * Shut down the currently loaded module and start a new one (moving all<br>
     * currently-connected players to the starting point.<br>
    **/
    void startNewModule(string sModuleName) throws NotInContextException;

    /**<br>
     * Removes any fading or black screen.<br>
     * - oCreature: creature controlled by player that should be cleared<br>
    **/
    void stopFade(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Stores the current camera mode and position so that it can be restored (using<br>
     * RestoreCameraFacing())<br>
    **/
    idempotent void storeCameraFacing() throws NotInContextException;

    /**<br>
     * Stores an object with the given id.<br>
     * NOTE: this command can only be used for storing Creatures and Items.<br>
     * Returns 0 if it failled, 1 if it worked.<br>
    **/
    idempotent int storeCampaignObject(string sCampaignName, string sVarName, NWObject oObject, NWObject oPlayer) throws NotInContextException;

    /**<br>
     * Summon an Animal Companion<br>
    **/
    idempotent void summonAnimalCompanion(NWObject oMaster) throws NotInContextException;

    /**<br>
     * Summon a Familiar<br>
    **/
    idempotent void summonFamiliar(NWObject oMaster) throws NotInContextException;

    /**<br>
     * Set the subtype of eEffect to Supernatural and return eEffect.<br>
     * (Effects default to magical if the subtype is not set)<br>
     * Permanent supernatural effects are not removed by resting<br>
    **/
    idempotent NWEffect supernaturalEffect(NWEffect eEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Use this on an NPC to cause all creatures within a 10-metre radius to stop<br>
     * what they are doing and sets the NPC's enemies within this range to be<br>
     * neutral towards the NPC for roughly 3 minutes. If this command is run on a PC<br>
     * or an object that is not a creature, nothing will happen.<br>
    **/
    idempotent void surrenderToEnemies() throws NotInContextException;

    /**<br>
     * Take nAmount of gold from oCreatureToTakeFrom.<br>
     * - nAmount<br>
     * - oCreatureToTakeFrom: If this is not a valid creature, nothing will happen.<br>
     * - bDestroy: If this is TRUE, the caller will not get the gold.  Instead, the<br>
     * gold will be destroyed and will vanish from the game.<br>
    **/
    void takeGoldFromCreature(int nAmount, NWObject oCreatureToTakeFrom, bool bDestroy) throws NotInContextException;

    /**<br>
     * The caller will perform a Melee Touch Attack on oTarget<br>
     * This is not an action, and it assumes the caller is already within range of<br>
     * oTarget<br>
     * * Returns 0 on a miss, 1 on a hit and 2 on a critical hit<br>
    **/
    AttackResult touchAttackMelee(NWObject oTarget, bool bDisplayFeedback) throws NotInContextException;

    /**<br>
     * The caller will perform a Ranged Touch Attack on oTarget<br>
     * * Returns 0 on a miss, 1 on a hit and 2 on a critical hit<br>
    **/
    AttackResult touchAttackRanged(NWObject oTarget, bool bDisplayFeedback) throws NotInContextException;

    /**<br>
     * Convert nTurns into a number of seconds<br>
     * A turn is always 60.0 seconds<br>
    **/
    idempotent double turnsToSeconds(int nTurns) throws NotInContextException;

    /**<br>
     * This will cause a Player Creature to unpossess his/her familiar.  It will work if run<br>
     * on the player creature or the possessed familiar.  It does not work in conjunction with<br>
     * any DM possession.<br>
    **/
    void unpossessFamiliar(NWObject oCreature) throws NotInContextException;

    /**<br>
     * Get the magnitude of vVector; this can be used to determine the<br>
     * distance between two points.<br>
     * * Return value on error: 0.0f<br>
    **/
    idempotent double vectorMagnitude(NWVector vVector) throws NotInContextException;

    /**<br>
     * Normalize vVector<br>
    **/
    idempotent NWVector vectorNormalize(NWVector vVector) throws NotInContextException;

    /**<br>
     * Convert vVector to an angle<br>
    **/
    idempotent double vectorToAngle(NWVector vVector) throws NotInContextException;

    /**<br>
     * Set eEffect to be versus a specific alignment.<br>
     * - eEffect<br>
     * - nLawChaos: ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_ALL<br>
     * - nGoodEvil: ALIGNMENT_GOOD/ALIGNMENT_EVIL/ALIGNMENT_ALL<br>
    **/
    idempotent NWEffect versusAlignmentEffect(NWEffect eEffect, int nLawChaos, int nGoodEvil) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Set eEffect to be versus nRacialType.<br>
     * - eEffect<br>
     * - nRacialType: RACIAL_TYPE_*<br>
    **/
    idempotent NWEffect versusRacialTypeEffect(NWEffect eEffect, RacialType tRacialType) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Set eEffect to be versus traps.<br>
    **/
    idempotent NWEffect versusTrapEffect(NWEffect eEffect) throws NotInContextException, InvalidEffectException;

    /**<br>
     * Does a Will Save check for the given DC<br>
     * - oCreature<br>
     * - nDC: Difficulty check<br>
     * - nSaveType: SAVING_THROW_TYPE_*<br>
     * - oSaveVersus<br>
     * Returns: 0 if the saving throw roll failed<br>
     * Returns: 1 if the saving throw roll succeeded<br>
     * Returns: 2 if the target was immune to the save type specified<br>
     * Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass<br>
     * GetAreaOfEffectCreator() into oSaveVersus!!<br>
    **/
    SavingThrowResult willSave(NWObject oCreature, int nDC, SaveType tSaveType, NWObject oSaveVersus) throws NotInContextException;

    /**<br>
     * Write sLogEntry as a timestamped entry into the log file<br>
    **/
    void writeTimestampedLogEntry(string sLogEntry) throws NotInContextException;
  };
};
