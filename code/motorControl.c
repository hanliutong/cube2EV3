int leftDegree;
int rightDegree;
int backDegree;

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

float targetDegree(tMotor num, float delta) {
	if(num == backMotor) {
		float temp = backDegree + delta;
		if(delta > 0) backDegree += 90.0;
		else if(delta < 0)	backDegree -= 90.0;
		else	return backDegree;
		return temp;
	}
	else if(num == leftMotor){
		float temp = leftDegree + delta;
		if(delta > 0) leftDegree += 90.0;
		else if(delta < 0)	leftDegree -= 90.0;
		else	return leftDegree;
		return temp;
	}
	else if(num == rightMotor) {
		float temp = rightDegree + delta;
		if(delta > 0) rightDegree += 90.0;
		else if(delta < 0)	rightDegree -= 90.0;
		else	return rightDegree;
		return temp;
	}
	return 0;
}

void turnSide(tMotor side) {
	float target = targetDegree(side, DEGREE_SIDE);
	float dis = target - getMotorEncoder(side);
	float err = 0.0;
	float last_err = 0.0;
  float total_err = 0.0;
	float delta_err = 0.0;
	float speed = 0.0;
	while(true) {
  	float cur = getMotorEncoder(side);
  	err = target - cur;
  	if(cur / dis > KI_SIDE_START_PERCENT)  total_err += err;
  	delta_err = err - last_err;
  	if(err < 0){
	  	while(getMotorEncoder(side) < targetDegree(side, 0)) {
	  		motor[side] = 3;
	  	}
  		motor[side] = 0;
  		return;
  	}

	  speed = KP_SIDE * err + KI_SIDE * total_err + KD_SIDE * delta_err;
	  motor[side] = CONSTRAIN(speed, 3, 100);
	  last_err = err;

	  sleep(10);
	}
}

void turnCube() {
	float targetL = targetDegree(leftMotor, -DEGREE_TURN_1);
	float targetR = targetDegree(rightMotor, -DEGREE_TURN_1);
	float disL = targetL - getMotorEncoder(leftMotor);
	float disR = targetR - getMotorEncoder(rightMotor);
	float errL = 0.0;
	float errR = 0.0;
	float last_errL = 0.0;
	float last_errR = 0.0;
  float total_errL = 0.0;
  float total_errR = 0.0;
	float delta_errL = 0.0;
	float delta_errR = 0.0;
	float speedL = 0.0;
	float speedR = 0.0;
	while(true) {
  	float curL = getMotorEncoder(leftMotor);
  	float curR = getMotorEncoder(rightMotor);
  	errL = targetL - curL;
  	errR = targetR - curR;
  	if(curL / disL > KI_CUBE_START_PERCENT)  total_errL += errL;
  	if(curR / disR > KI_CUBE_START_PERCENT)  total_errR += errR;
  	delta_errL = errL - last_errL;
    delta_errR = errR - last_errR;
  	if(abs(errL) < 1 || abs(errR) < 1){
	  	motor[leftMotor] = 0;
	  	motor[rightMotor] = 0;
  		return;
  	}

	  speedL = KP_CUBE * errL + KI_CUBE * total_errL + KD_CUBE * delta_errL;
    speedR = KP_CUBE * errR + KI_CUBE * total_errR + KD_CUBE * delta_errR;
	  motor[leftMotor] = speedL;
	  motor[rightMotor] = speedR;
	  last_errL = errL;
    last_errR = errR;

	  sleep(10);
	}
}

void back() {
	setMotorBrakeMode(leftMotor, motorCoast);
	setMotorBrakeMode(rightMotor, motorCoast);
	//float target = targetDegree(backMotor, DEGREE_BACK_1);
	float target = DEGREE_BACK_1;
	resetMotorEncoder(backMotor);
	float err = 0.0;
	float last_err = 0.0;
  float total_err = 0.0;
	float delta_err = 0.0;
	float speed = 0.0;
	while(true) {
  	float cur = getMotorEncoder(backMotor);
  	err = target - cur;
  	if(cur / target > KI_BACK_START_PERCENT)  total_err += err;
  	delta_err = err - last_err;
  	if(err < 0){
	  	motor[backMotor] = 0;
  		break;
  	}

	  speed = KP_BACK * err + KI_BACK * total_err + KD_BACK * delta_err;
	  motor[backMotor] = speed;
	  last_err = err;

	  sleep(10);
	}
	//while(SensorValue[S1] == 0) {sleep(10);}while(SensorValue[S1] == 1) {sleep(10);}
	target = DEGREE_BACK_2;
	//target = targetDegree(backMotor, 0);
	while(true) {
  	float cur = getMotorEncoder(backMotor);
  	err = target - cur;
  	if(cur / target > KI_BACK_START_PERCENT)  total_err += err;
  	delta_err = err - last_err;
  	if(err > 0){
	  	motor[backMotor] = 0;
			setMotorBrakeMode(leftMotor, motorHold);
			setMotorBrakeMode(rightMotor, motorHold);
			return;
  	}

	  speed = KP_BACK * err + KI_BACK * total_err + KD_BACK * delta_err;
	  motor[backMotor] = speed;
	  last_err = err;
	  sleep(10);
	}
}

void backReverse() {
	setMotorBrakeMode(leftMotor, motorCoast);
	setMotorBrakeMode(rightMotor, motorCoast);
	//float target = targetDegree(backMotor, -DEGREE_BACK_1);
	float target = -DEGREE_BACK_1;
	resetMotorEncoder(backMotor);
	float err = 0.0;
	float last_err = 0.0;
  float total_err = 0.0;
	float delta_err = 0.0;
	float speed = 0.0;
	while(true) {
  	float cur = getMotorEncoder(backMotor);
  	err = target - cur;
  	if(cur / target > KI_BACK_START_PERCENT)  total_err += err;
  	delta_err = err - last_err;
  	if(err > 0){
	  	motor[backMotor] = 0;
  		break;
  	}

	  speed = KP_BACK * err + KI_BACK * total_err + KD_BACK * delta_err;
	  motor[backMotor] = speed;
	  last_err = err;

	  sleep(10);
	}
	//while(SensorValue[S1] == 0) {sleep(10);}while(SensorValue[S1] == 1) {sleep(10);}
	target = -DEGREE_BACK_2;
	//target = targetDegree(backMotor, 0);
	while(true) {
  	float cur = getMotorEncoder(backMotor);
  	err = target - cur;
  	if(cur / target > KI_BACK_START_PERCENT)  total_err += err;
  	delta_err = err - last_err;
  	if(err < 0){
	  	motor[backMotor] = 0;
			setMotorBrakeMode(leftMotor, motorHold);
			setMotorBrakeMode(rightMotor, motorHold);
  		return;
  	}

	  speed = KP_BACK * err + KI_BACK * total_err + KD_BACK * delta_err;
	  motor[backMotor] = speed;
	  last_err = err;
	  sleep(10);
	}
}
