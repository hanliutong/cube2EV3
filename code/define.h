#define CONSTRAIN(x, lower, upper) ( x >= 0 ? ( (x)<(lower)? (lower) : ((x)>(upper)?(upper):(x)) ) : ((x) > (-lower) ? (-lower) : ((x)<(-upper)?(-upper):(x))) )


#define KP_CUBE 0.8
#define KI_CUBE 0.05
#define KD_CUBE 2.5
#define KI_CUBE_START_PERCENT 0.90

#define KP_SIDE 0.7
#define KI_SIDE 0.04
#define KD_SIDE 2.2
#define KI_SIDE_START_PERCENT 0.95

#define KP_BACK_1 0.6
#define KI_BACK_1 0.01
#define KD_BACK_1 1.0
#define KI_BACK_1_START_PERCENT 0.9

#define KP_BACK_2 0.6
#define KI_BACK_2 0.01
#define KD_BACK_2 0.8
#define KI_BACK_2_START_PERCENT 0.9

#define DEGREE_SIDE 93.0
#define DEGREE_TURN_1 97.0
#define DEGREE_TURN_2 90.0
#define DEGREE_BACK_1 126.0

#define leftMotor motorD
#define rightMotor motorA
#define backMotor motorC

#define ROTATE_LEFT 0xFF
#define ROTATE_LEFT_REVERSE 0xFE
#define ROTATE_RIGHT 0xFD
#define ROTATE_RIGHT_REVERSE 0xFC
#define ROTATE_BACK 0xFB
#define ROTATE_BACK_REVERSE 0xFA

int lastStep;
void waitButton();
