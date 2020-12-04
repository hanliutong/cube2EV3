void L();
void Lr();
void L2();
void R();
void Rr();
void R2();

void L() {
	turnSide(leftMotor); sleep(100);
	lastStep = ROTATE_LEFT;
}

void Lr() {
	L(); sleep(100);
	L(); sleep(100);
	L(); sleep(100);
}

void L2() {
	L(); sleep(100);
	L(); sleep(100);
}

void R() {
	turnSide(rightMotor); sleep(100);
	lastStep = ROTATE_RIGHT;
}

void Rr() {
	R(); sleep(100);
	R(); sleep(100);
	R(); sleep(100);
}

void R2() {
	R(); sleep(100);
	R(); sleep(100);
}

void U() {
	if(lastStep == ROTATE_RIGHT) {
		back(); sleep(100);
		back(); sleep(100);
		back(); sleep(100);
		lastStep = ROTATE_BACK;
	}
	backReverse(); sleep(100);
	lastStep = ROTATE_BACK_REVERSE;
}

void Ur() {
	if(lastStep == ROTATE_LEFT) {
		backReverse(); sleep(100);
		backReverse(); sleep(100);
		backReverse(); sleep(100);
		lastStep = ROTATE_BACK_REVERSE;
	}
	else {
		back(); sleep(100);
		lastStep = ROTATE_BACK;
	}
}

void U2() {
	U(); sleep(100);
	U(); sleep(100);
}

void D() {
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	U(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
}

void Dr() {
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	Ur(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
}

void D2() {
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	U(); sleep(100);
	U(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
}

void F() {
	turnCube(); sleep(100);
	U(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
}

void Fr() {
	turnCube(); sleep(100);
	Ur(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
}

void F2() {
	turnCube(); sleep(100);
	U(); sleep(100);
	U(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
}

void B() {
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	U(); sleep(100);
	turnCube(); sleep(100);
}

void Br() {
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	Ur(); sleep(100);
	turnCube(); sleep(100);
}

void B2() {
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	turnCube(); sleep(100);
	U(); sleep(100);
	U(); sleep(100);
	turnCube(); sleep(100);
}
