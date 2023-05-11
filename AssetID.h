#pragma once
//////////////////////////////////////////////////////////////////////////////
// BILL PART
#define GROUND_Y 300.0f
#define Bill_GRAVITY -0.001f
#define BILL_RUN_SPEED  0.065f
#define BILL_JUMP_SPEED_Y 0.3f

#define object_type_bill 1

#define BILL_STATE_IDLE 100
#define BILL_STATE_SWIM 200
#define BILL_STATE_RUN 300
#define BILL_STATE_JUMP 400
#define BILL_STATE_LAYDOWN 500
#define BILL_STATE_DEAD 600
#define BILL_STATE_SWIM_MOVE 700


#pragma once ANIMATION_ID
#define ID_ANI_BILL_IDLE_RIGHT 100
#define ID_ANI_BILL_IDLE_SHOT_UP_RIGHT 101
#define ID_ANI_BILL_IDLE_LEFT 150
#define ID_ANI_BILL_IDLE_SHOT_UP_LEFT 151
#define ID_ANI_BILL_SWIMMING_RIGHT 200
#define ID_ANI_BILL_SWIMMING_SHOT_RIGHT 201
#define ID_ANI_BILL_SWIMMING_SHOT_UP_RIGHT 202
#define ID_ANI_BILL_SWIMMING_SHOT_UP_STAND_RIGHT 203
#define ID_ANI_BILL_SWIMMING_LEFT 250
#define ID_ANI_BILL_SWIMMING_SHOT_LEFT 251
#define ID_ANI_BILL_SWIMMING_SHOT_UP_LEFT 252
#define ID_ANI_BILL_SWIMMING_SHOT_UP_STAND_LEFT 253
#define ID_ANI_BILL_SWIMMING_START 299
#define ID_ANI_BILL_RUN_RIGHT 300
#define ID_ANI_BILL_RUN_SHOT_RIGHT 301
#define ID_ANI_BILL_RUN_SHOT_UP_RIGHT 302
#define ID_ANI_BILL_RUN_SHOT_DOWN_RIGHT 303
#define ID_ANI_BILL_RUN_LEFT 350
#define ID_ANI_BILL_RUN_SHOT_LEFT 351
#define ID_ANI_BILL_RUN_SHOT_UP_LEFT 352
#define ID_ANI_BILL_RUN_SHOT_DOWN_LEFT 353
#define ID_ANI_BILL_JUMP_RIGHT 400
#define ID_ANI_BILL_JUMP_LEFT 450
#define ID_ANI_BILL_LAYDOWN_RIGHT 500
#define ID_ANI_BILL_LAYDOWN_LEFT 550
#define ID_ANI_BILL_DEAD 600

#define TEXTURE_RIGHT_PATH L"./Resources/Images/bill_animation.png"
#define TEXTURE_RIGHT_ID 0
#define TEXTURE_LEFT_ID 1
#pragma once ANIMATION_DURATION
#define DURATION_ANI_BILL_IDLE 20
#define DURATION_ANI_BILL_SWIMMING 100
#define DURATION_ANI_BILL_RUN 100
#define DURATION_ANI_BILL_JUMP 100
////////////////////////////////////////////////////////////////////////
//BULLETPART
#define ID_BULLET_TEXTURE 2
#define TEXTURE_BULET_PATH  L"./Resources/Images/Bullets.png"
//Bullet go from 1000 to 1100
#define ID_ANI_BULLET_NORMAL 1000
#define ID_ANI_BULLET_L 1001
#define ID_ANI_BULLET_F 1002
#define ID_ANI_BULLET_S 1003
#define ID_ANI_BULLET_RIFLE 1004

#define RECOID_TIME 100
///////////////////////////////////////////////////////////////////////
// Sodier
#define TEXTURE_SODIER_ID 3
#define ID_SODIER 3
#define SODIER_STATE_RUNNING 2100
#define SODIER_STATE_JUMPING 2110
#define SODIER_STATE_DEATH 2120
#define SODIER_STATE_SHOTED 2130
#define SODIER_STATE_SHOT 2140
#define SODIER_STATE_LAYDOWN 2140

#define ID_ANI_SODIER_RUNNING 2100
#define ID_ANI_SODIER_JUMPING 2110
#define ID_ANI_SODIER_SHOTED 2130
#define ID_ANI_SODIER_DEATH 2120
#define ID_ANI_SODIER_SHOT 2140
#define ID_ANI_SODIER_LAYDOWN 2150

#define ID_ANI_SODIER_RUNNING_RIGHT 2160
#define ID_ANI_SODIER_JUMPING_RIGHT 2170
#define ID_ANI_SODIER_LAYDOWN_RIGHT 2180 
#define ID_ANI_SODIER_SHOT_RIGHT 2190

//Sniper
#define ID_SNIPER 7
#define ID_SNIPER_HIDDEN 12
#define TEXTURE_SNIPER_ID 7
#define SNIPER_STATE_HIDDEN 2200
#define SNIPER_STATE_SHOT 2210
#define SNIPER_STATE_SHOTED 2230
#define SNIPER_STATE_DIE 2240
#define SNIPER_STATE_NORMAl 2250

#define ID_ANI_SNIPER_SHOT 2210
#define ID_ANI_SNIPER_SHOT_RIGHT 2215
#define ID_ANI_SNIPER_SHOT_UP 2211
#define ID_ANI_SNIPER_SHOT_DOWN 2212
#define ID_ANI_SNIPER_SHOT_UP_RIGHT 2213
#define ID_ANI_SNIPER_SHOT_DOWN_RIGHT 2214
#define ID_ANI_SNIPER_HIDDEN 2200
#define ID_ANI_SNIPER_HIDDEN_RIGHT 2201
#define ID_ANI_SNIPER_SHOW 2230
#define ID_ANI_SNIPER_SHOW_RIGHT 2231
#define ID_ANI_SNIPER_HIDDEN_SHOT 2240
#define ID_ANI_SNIPER_HIDDEN_SHOT_RIGHT 2241
#define ID_ANI_SNIPER_NORMAL 2250
#define ID_ANI_SNIPER_NORMAL_RIGHT 2251


//GunRotation
#define ID_GUNROTATION 4
#define TEXTURE_GUNROTATION_ID 4
#define GUNROTATION_STATE_HIDDEN 2000
#define GUNROTATION_STATE_NORMAL 2010
#define GUNROTATION_STATE_DIE 2099

#define ID_ANI_GUNROTATION_HIDDEN 2000
#define ID_ANI_GUNROTATION_SHOW 2005
#define ID_ANI_GUNROTATION_SHOT_0 2010
#define ID_ANI_GUNROTATION_SHOT_1 2015
#define ID_ANI_GUNROTATION_SHOT_2 2020
#define ID_ANI_GUNROTATION_SHOT_3 2025
#define ID_ANI_GUNROTATION_SHOT_4 2030
#define ID_ANI_GUNROTATION_SHOT_5 2035
#define ID_ANI_GUNROTATION_SHOT_6 2040
#define ID_ANI_GUNROTATION_SHOT_7 2045
#define ID_ANI_GUNROTATION_SHOT_8 2050
#define ID_ANI_GUNROTATION_SHOT_9 2055
#define ID_ANI_GUNROTATION_SHOT_10 2060
#define ID_ANI_GUNROTATION_SHOT_11 2065
//Bridge
#define ID_BRIDGE 8
#define TEXTURE_BRIDGE_ID 8
#define BRIDGE_STATE_ALIVE 2300
#define BRIDGE_STATE_EXPLOSIVE 2310

#define ID_ANI_BRIDGE_ALIVE_PLATFORM_BLOCK1 2301
#define ID_ANI_BRIDGE_ALIVE_PLATFORM_BLOCK2 2302
#define ID_ANI_BRIDGE_ALIVE_BELOW_BLOCK3 2303
#define ID_ANI_BRIDGE_ALIVE_START_BLOCK 2304
#define ID_ANI_BRIDGE_ALIVE_END_BLOCK 2305
#define ID_ANI_BRIDGE_EXPLOSIVE 2310

//Canon
#define ID_CANON 10
#define TEXTURE_CANON_ID 10
#define CANON_STATE_NORMAL 2400
#define CANON_STATE_HIDDEN 2410

#define ID_ANI_CANON_NORMAL 2400
#define ID_ANI_CANON_NORMAL_1 2401
#define ID_ANI_CANON_NORMAL_2 2402
#define ID_ANI_CANON_HIDDEN 2410
///////////////////////////////////////////////////////////////////////
//MISC
#define TEXTURE_GRASS_ID 5
#define ID_GRASS 9999
#define ID_BLOCK_OBJECT 9998
#define AIRCRAFT_TEXTURE_ID 6
#define PI 3.141517

//ROCKFALL
#define TEXTURE_ROCKFALL_ID 9
#define ROCKFALL_STATE_IDLE 3000
#define ROCKFALL_STATE_SHAKING 3010
#define ROCKFALL_STATE_FALL 3020

#define ID_ANI_ROCKFALL_STAY 3000
#define ID_ANI_ROCKFALL_FALL 3020
//////////////////////////////////////////////////////////////////////
//TILEMAP
#define TEXTURE_TILEMAP_STAGE_1_ID 10000

//////////////////////////////////////////////////////////////////////
//Boss
///Stage1
#define TEXTURE_BOSS_STAGE_1_ID 11
#define BOSS_STAGE_1_GUN_1_ALIVE 4000
#define BOSS_STAGE_1_GUN_1_DEAD 4001
#define BOSS_STATE_1_GUN_2_ALIVE 4010
#define BOSS_STAGE_1_GUN_2_DEAD 4011
#define BOSS_STAGE_1_MOLDER_ALIVE 4020
#define BOSS_STAGE_1_MOLDER_DEAD 4021

#define ID_ANI_BOSS_STAGE_1_GUN_1_ALIVE 4000
#define BOSS_STAGE_1_GUN_1_DEAD 4005
#define BOSS_STAGE_1_GUN_2_ALIVE 4010
#define BOSS_STAGE_1_GUN_2_DEAD 4015
#define BOSS_STAGE_1_MOLDER_ALIVE 4020
#define BOSS_STAGE_1_MOLDER_DEAD 4021
