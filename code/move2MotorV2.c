#define BACK 0
#define UP 1
#define FRONT 2
#define DOWN 3

int state = 0;

void turnTo(int target) {
	for(int i = 0; i < (target + 4 - state) % 4; i++) {
		turnCube();
		sleep(100);
	}
	state = target;
}

void L() {	turnSide(leftMotor); sleep(100);}

void Lr() {	L(); 	L();	L();}

void L2() {	L();	L();}

void R() {	turnSide(rightMotor);	sleep(100);}

void Rr() {	R();	R();	R();}

void R2() {	R();	R();}

void Back() {	back(true); sleep(100);}

void BackReverse() {	back(false); sleep(100);}

void Back2() {	Back();	Back();}

void U() {	turnTo(UP);	Back();}

void Ur() {	turnTo(UP); BackReverse();}

void U2() {	turnTo(UP); Back2();}

void D() {	turnTo(DOWN);	Back();}

void Dr() {	turnTo(DOWN);	BackReverse();}

void D2() {	turnTo(DOWN);	Back2();}

void F() {	turnTo(FRONT);	Back();}

void Fr() {	turnTo(FRONT);	BackReverse();}

void F2() {	turnTo(FRONT);	Back2();}

void B() {	turnTo(BACK);	Back();}

void Br() {	turnTo(BACK); BackReverse();}

void B2() {	turnTo(BACK); Back2();}
