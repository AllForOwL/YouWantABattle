#include <string>

using std::string;

const string PATH_TO_RESOURCES = "E:/programming/cocos/project/YouWantABattle/proj.win32/res";

const int SCALE_X = 7;
const int SCALE_Y = 7;

const int BULLET_COAL		= 0;
const int BULLET_DIAMOND	= 1;
const int BULLET_ONYX		= 2;
const int BULLET_ORE		= 3;
const int BULLET_RUBY		= 4;

const int TAG_HERO	= 1000;
const int TAG_ENEMY = 1001;

#define COLLISION_BITMASK_BOAR		0x000001
#define COLLISION_BITMASK_BOWMAN	0x000002
#define COLLISION_BITMASK_GIANT		0x000003
#define COLLISION_BITMASK_KNIGHT	0x000004
#define COLLISION_BITMASK_OCTOPUS	0x000005
#define COLLISION_BITMASK_PALADIN	0x000006
#define COLLISION_BITMASK_WIZARD	0x000007
#define COLLISION_BITMASK_YETI		0x000008
#define COLLISION_BITMASK_BULLET	0x000009