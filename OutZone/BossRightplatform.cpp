
#include "BossRightplatform.h"


BossRPlat::BossRPlat(int x, int y) : Terrainmod(x, y){
	plat.PushBack({ 61, 99, 192, 95 });
	animation = &plat;
}

