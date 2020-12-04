int leftDegree;
int rightDegree;
float backDegree;

//float curBackMotorEncoder;
//float curMotorEncoder;

void resetMotor() {
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	resetMotorEncoder(backMotor);
	leftDegree = 0;
	rightDegree = 0;
	backDegree = 0;
	setMotorBrakeMode(leftMotor, motorHold);
	setMotorBrakeMode(rightMotor, motorHold);
}

void back(bool clockwise) {
	setMotorBrakeMode(leftMotor, motorCoast);
	setMotorBrakeMode(rightMotor, motorCoast);
	float target;
	if(!clockwise) {
		target = backDegree + DEGREE_BACK_1 + 3;
		backDegree += 90.0;
	}
	else {
		target = backDegree - DEGREE_BACK_1;
		backDegree -= 90.0;
	}
	float err = 0.0;
	float speed = 0.0;
	while(true) {
  	float cur = getMotorEncoder(backMotor);
  	//curBackMotorEncoder = cur;
  	err = target - cur;
  	if(abs(err) < 2.0){
	  	motor[backMotor] = 0;
  		break;
  	}
	  speed = KP_BACK_1 * err;
	  motor[backMotor] = CONSTRAIN(speed, 5, 17);
	  sleep(10);
	}

	target = backDegree;
	while(true) {
  	float cur = getMotorEncoder(backMotor);
  	//curBackMotorEncoder = cur;
  	err = target - cur;
  	if(abs(err) < 1.0){
	  	motor[backMotor] = 0;
			setMotorBrakeMode(leftMotor, motorHold);
			setMotorBrakeMode(rightMotor, motorHold);
			return;
  	}
	  speed = KP_BACK_2 * err;
	  motor[backMotor] = CONSTRAIN(speed, 5, 17);
	  sleep(10);
	}
}

void turnSide(tMotor side) {
	setMotorBrakeMode(backMotor, motorCoast);
	float target;
	if(side == leftMotor) {
		target = leftDegree + DEGREE_SIDE;
		leftDegree += 90.0;
	}
	else {
		target = rightDegree + DEGREE_SIDE + 3;
		rightDegree += 90.0;
	}
	float err = 0.0;
	float speed = 0.0;
	while(true) {
  	float cur = getMotorEncoder(side);
  	//curMotorEncoder = cur;
  	err = target - cur;
  	if(abs(err) < 0.5){
	  	motor[side] = 0;
	  	setMotorBrakeMode(backMotor, motorHold);
  		break;
  	}
	  speed = KP_BACK_1 * err;
	  if(side == leftMotor) speed *= 1.03;
	  motor[side] = CONSTRAIN(speed, 13, 23);
	  sleep(10);
	}

	target = backDegree;
}

void turnCube() {
	setMotorBrakeMode(backMotor, motorCoast);
	float targetL = leftDegree - DEGREE_TURN_1;
	float targetR = rightDegree - DEGREE_TURN_1;
	float err = leftDegree - rightDegree;
	leftDegree -= 90.0;
	rightDegree -= 90.0;
	float errL = 0.0;
	float errR = 0.0;
	float speedL = 0.0;
	float speedR = 0.0;
	while(true) {
  	float curL = getMotorEncoder(leftMotor);
  	float curR = getMotorEncoder(rightMotor);
  	errL = targetL - curL;
  	errR = targetR - curR;
  	if(abs(errL) < 0.5 && abs(errR) < 0.5){
	  	motor[leftMotor] = 0;
	  	motor[rightMotor] = 0;
	  	setMotorBrakeMode(backMotor, motorHold);
  		break;
  	}
	  speedL = KP_CUBE * errL;
	  speedR = KP_CUBE * errR;

	  float rpmAdjust = 1.0 * (getMotorRPM(leftMotor) - getMotorRPM(rightMotor));
		float rotationAdjust = 1.0 * (getMotorEncoder(leftMotor) - getMotorEncoder(rightMotor) - err);

		motor[leftMotor] = 1.1 * CONSTRAIN(speedL, 3, 13);
		motor[rightMotor] = CONSTRAIN(speedR, 3, 13);

	  sleep(10);
	}

	while(true) {
  	float curL = getMotorEncoder(leftMotor);
  	float curR = getMotorEncoder(rightMotor);
  	errL = leftDegree - curL;
  	errR = rightDegree - curR;
  	if(abs(errL) < 0.5 && abs(errR) < 0.5){
	  	motor[leftMotor] = 0;
	  	motor[rightMotor] = 0;
	  	setMotorBrakeMode(backMotor, motorHold);
  		break;
  	}
	  speedL = KP_CUBE * errL;
	  speedR = KP_CUBE * errR;

	  float rpmAdjust = 1.0 * (getMotorRPM(leftMotor) - getMotorRPM(rightMotor));
		float rotationAdjust = 1.0 * (getMotorEncoder(leftMotor) - getMotorEncoder(rightMotor) - err);

		motor[leftMotor] = 1.1 * CONSTRAIN(speedL, 3, 13);
		motor[rightMotor] = CONSTRAIN(speedR, 3, 13);

	  sleep(10);
	}
}
