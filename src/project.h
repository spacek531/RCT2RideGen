#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

#include<stdint.h>
#include<renderer.h>

#define TILE_SIZE 3.3


typedef enum //Ride flags
{
VEHICLE_TAB_SCALE_HALF=             0x00000001u,
NO_INVERSIONS=                      0x00000002u,
NO_BANKED_TRACK=                    0x00000004u,
PLAY_DEPART_SOUND=                  0x00000008u,// Steam locomotive chuffing
ALTERNATIVE_SWING_MODE_1=           0x00000010u,// Twist type rotation ride
ALTERNATIVE_ROTATION_MODE_1=        0x00000020u,// Lifting arm rotation ride (enterprise)
ALTERNATIVE_ROTATION_MODE_2=        0x00000040u,
FLAG_7=                             0x00000080u,
PLAY_SPLASH_SOUND=                  0x00000100u,
PLAY_SPLASH_SOUND_SLIDE=            0x00000200u,
COVERED_RIDE=                       0x00000400u,
LIMIT_AIRTIME_BONUS=                0x00000800u,
SEPARATE_RIDE_NAME=                 0x00001000u,
SEPARATE_RIDE=                      0x00002000u, //Not setting this prevents track designs from showing in the window
CANNOT_BREAK_DOWN=                  0x00004000u,
DISABLE_LAST_OPERATING_MODE=        0x00008000u,
FLAG_16=                            0x00010000u,
DISABLE_FIRST_TWO_OPERATING_MODES=  0x00020000u,
FLAG_18=                            0x00040000u,
FLAG_DISABLE_COLOUR_TAB=            0x00080000u,// Must be set with swing mode 1 as well.
ALTERNATIVE_SWING_MODE_2=           0x00100000u
}ride_flags_t;
typedef enum //Vehicle flags
{
FLAG_A_0=                           0x00000001u,
NO_UPSTOP_WHEELS=                   0x00000002u,
NO_UPSTOP_BOBSLEIGH=                0x00000004u,
MINI_GOLF=                          0x00000008u,
FLAG_A_4=                           0x00000010u,
FLAG_A_5=                           0x00000020u,
FLAG_A_6=                           0x00000040u,
FLAG_A_7=                           0x00000080u,
ALLOW_DOORS_DEPRECATED=             0x00000100u,
ENABLE_ADDITIONAL_COLOR_2=          0x00000200u,
FLAG_A_10=                          0x00000400u,
FLAG_A_11=                          0x00000800u,
FLAG_A_12=                          0x00001000u,
FLAG_A_13=                          0x00002000u,
FLAG_A_14=                          0x00004000u,
FLAG_A_15=                          0x00008000u,
ENABLE_ADDITIONAL_COLOR_1=          0x00010000u,
CAR_IS_SWINGING=                    0x00020000u,
CAR_IS_SPINNING=                    0x00040000u,
CAR_IS_POWERED=                     0x00080000u,
CAR_ENABLE_ROLLING_SOUND=           0x00100000u,
FLAG_B_5=                           0x00200000u,
FLAG_B_6=                           0x00400000u,
CAR_IS_ANIMATED=                    0x00800000u,
FLAG_B_8=                           0x01000000u,
FLAG_B_9=                           0x02000000u,
FLAG_B_10=                          0x04000000u,
FLAG_B_11=                          0x08000000u,
FLAG_B_12=                          0x10000000u,
FLAG_B_13=                          0x20000000u,
FLAG_B_14=                          0x40000000u,
FLAG_B_15=                          0x80000000u
}vehicle_flags_t;
typedef enum //Sprite flags
{
SPRITE_FLAT_SLOPE=0x0001,
SPRITE_GENTLE_SLOPE=0x0002,
SPRITE_STEEP_SLOPE=0x0004,
SPRITE_VERTICAL_SLOPE=0x0008,
SPRITE_DIAGONAL_SLOPE=0x0010,
SPRITE_BANKING=0x0020,
SPRITE_INLINE_TWIST=0x0040,
SPRITE_SLOPE_BANK_TRANSITION=0x0080,
SPRITE_DIAGONAL_BANK_TRANSITION=0x0100,
SPRITE_SLOPED_BANK_TRANSITION=0x0200,
SPRITE_SLOPED_BANKED_TURN=0x0400,
SPRITE_BANKED_SLOPE_TRANSITION=0x0800,
SPRITE_CORKSCREW=0x1000,
SPRITE_RESTRAINT_ANIMATION=0x2000,
SPRITE_SPIRAL_LIFT=0x4000
}sprite_flags_t;
typedef enum //Vehicle animation types
{
ANIMATION_TYPE_NONE=0,
ANIMATION_TYPE_STEAM=1,
ANIMATION_TYPE_2=2,
ANIMATION_TYPE_3=3,
ANIMATION_TYPE_4=4,
ANIMATION_TYPE_5=5,
ANIMATION_TYPE_OBS_TOWER=6,
ANIMATION_TYPE_7=7,
ANIMATION_TYPE_8=8,
ANIMATION_TYPE_MULTIDIMENSION=9
}animation_types_t;
typedef enum //Ride primary sounds
{
RUNNING_SOUND_WOODEN_OLD=1,
RUNNING_SOUND_WOODEN_MODERN=54,
RUNNING_SOUND_STEEL=2,
RUNNING_SOUND_STEEL_SMOOTH=57,
RUNNING_SOUND_WATERSLIDE=32,
RUNNING_SOUND_TRAIN=31,
RUNNING_SOUND_ENGINE=21,
RUNNING_SOUND_NONE=255
}running_sound_t;
typedef enum //Ride secondary sounds
{
SECONDARY_SOUND_SCREAMS_1=0,
SECONDARY_SOUND_SCREAMS_2=1,
SECONDARY_SOUND_SCREAMS_3=2,
SECONDARY_SOUND_WHISTLE=3,
SECONDARY_SOUND_BELL=4,
SECONDARY_SOUND_NONE=255,
}secondary_sound_t;
typedef enum //Car position indices
{
CAR_INDEX_DEFAULT=0,
CAR_INDEX_FRONT=1,
CAR_INDEX_SECOND=2,
CAR_INDEX_THIRD=4,
CAR_INDEX_REAR=3
}car_index_t;
typedef enum //Ride categories
{
CATEGORY_TRANSPORT_RIDE=0,
CATEGORY_GENTLE_RIDE=1,
CATEGORY_ROLLERCOASTER=2,
CATEGORY_THRILL_RIDE=3,
CATEGORY_WATER_RIDE=4,
CATEGORY_SHOP=5
}category_t;



#define TRACK_STATION 0x0000000000000004l
#define TRACK_STRAIGHT 0x0000000000000002l
#define TRACK_CHAIN_LIFT 0x0000000000000008l
#define TRACK_STEEP_CHAIN_LIFT 0x0000000000000010l
#define TRACK_TIRE_DRIVE_LIFT 0x0000000000000020l //Junior only
#define TRACK_BANKING 0x0000000000000040l
#define TRACK_VERTICAL_LOOP 0x0000000000000080l
#define TRACK_GENTLE_SLOPE 0x0000000000000100l
#define TRACK_STEEP_SLOPE 0x0000000000000200l
#define TRACK_FLAT_TO_STEEP_SLOPE_SMALL 0x0000000000000400l
#define TRACK_SLOPED_TURNS 0x0000000000000800l //(Enables available turns)
#define TRACK_STEEP_SLOPED_TURNS 0x0000000000001000l
#define TRACK_S_BEND 0x0000000000002000l
#define TRACK_TINY_TURNS 0x0000000000004000l
#define TRACK_SMALL_TURN 0x0000000000008000l //(Flat enabled)
#define TRACK_LARGE_TURN 0x0000000000010000l
#define TRACK_INLINE_TWIST 0x0000000000020000l
#define TRACK_HALF_LOOP 0x0000000000040000l
#define TRACK_HALF_CORKSCREW 0x0000000000080000l
#define TRACK_VERTICAL_TOWER 0x0000000000100000l //Launched Freefall + Roto-Drop?)
#define TRACK_HELIX 0x0000000000200000l //(For upright track only)
#define TRACK_QUARTER_HELIX 0x0000000000400000l //(For inverted track only)
#define TRACK_UNBANKED_QUARTER_HELIX 0x0000000000800000l //Suspended Swinging only
#define TRACK_BRAKES 0x0000000001000000l
#define TRACK_ON_RIDE_PHOTO_SECTION 0x0000000004000000l
#define TRACK_WATER_SPLASH 0x0000000008000000l //Wooden only
#define TRACK_VERTICAL_SLOPE 0x0000000010000000l
#define TRACK_BARREL_ROLL 0x0000000020000000l
#define TRACK_LAUNCHED_LIFT 0x0000000040000000l
#define TRACK_LARGE_HALF_LOOP 0x0000000080000000l
#define TRACK_BANKED_FLAT_TO_UNBANKED_GENTLE_SLOPE_TURN 0x0000000100000000l
#define TRACK_HEARTLINE_ROLL 0x0000000400000000l //Heartline only
#define TRACK_REVERSER_TURNTABLE 0x0000000200000000l //Log Flume only
#define TRACK_REVERSER 0x0000000800000000l //Reverser only
#define TRACK_FLAT_TO_VERTICAL_SLOPE 0x0000001000000000l //Enables vertical track
#define TRACK_VERTICAL_TO_FLAT 0x0000002000000000l //Enables top section
#define TRACK_BLOCK_BRAKES 0x0000004000000000l
#define TRACK_GENTLE_SLOPE_BANKING 0x0000008000000000l //(Enables available turns)
#define TRACK_FLAT_TO_STEEP_SLOPE 0x0000010000000000l
#define TRACK_VERTICAL_SLOPED_TURNS 0x0000020000000000l
#define TRACK_CABLE_LIFT 0x0000080000000000 //Giga only
#define TRACK_SPIRAL_LIFT 0x0000100000000000l //Spiral Coaster only
#define TRACK_QUARTER_LOOP 0x0000200000000000l
#define TRACK_SPINNING_TUNNEL 0x0000400000000000l //(Ghost Train and Car Rides)
#define TRACK_SPINNING_TOGGLE 0x0000800000000000l //Spinning Wild Mouse only)
#define TRACK_INLINE_TWIST_UNINVERT 0x0001000000000000l
#define TRACK_INLINE_TWIST_INVERT 0x0002000000000000l
#define TRACK_QUARTER_LOOP_INVERT 0x0004000000000000l
#define TRACK_QUARTER_LOOP_UNINVERT 0x0008000000000000l
#define TRACK_RAPIDS 0x0010000000000000l //Rapids / Log Bumps, River Rapids / Monster Trucks only
#define TRACK_HALF_LOOP_UNINVERT 0x0020000000000000l
#define TRACK_HALF_LOOP_INVERT 0x0040000000000000l



typedef struct
{
mesh_t mesh;
uint32_t mass;
uint32_t sprite_flags;
uint32_t num_sprites;
float spacing;
}vehicle_t;

typedef struct
{
uint8_t* id;
uint32_t checksum;
uint8_t* name;
uint8_t* description;
uint8_t* capacity;
uint8_t* track_type;
uint8_t zero_cars;
uint8_t min_cars_per_train;
uint8_t max_cars_per_train;
uint8_t configuration[5];
uint32_t num_sprites;
uint32_t num_vehicles;
vehicle_t vehicles[4];
}project_t;

int project_export(project_t* project,context_t* context,const char* output_directory);

#endif
