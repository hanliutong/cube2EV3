#include "define.h"
#include "motorControlV2.c"
#include "move2MotorV2.c"
#include "io.h"
#include "step.h"

task main()
{
	//turnCube();
	//sleep(1000);

	//char step[] = "L F' L B2 L' F L B2 L2";
	//char step[] = "R' U' R U' R' U2 R B U B' U B U2 B' L U L' U L U2 L' B' U' B U' B' U2 B";
	//char step[] = "R' U' R U' R' U' R U' R' U' R U' R' U' R U' R' U' R U'";
	//char step[] = "L' L' L' L' L' L' R' R' R' R' R' R'";
	//char step[] = "R' D' R B D F' D U' R B D";
	//char step[] = "D' B' R' U D' F D' B' R' D R";
	//char step[] = "L L L L R' R' R' R' B B' U U' F F' D D'";
	//char step[] = "D F B R' B' U B' D L D L' D' D' U' F R F B U L' F' L F U' F' L' F L";


	resetMotor();
	lastStep = 0;
	for(int i = 0; i < strlen(step); i++) {
		char c = step[i];
		if(c == 'W') {
			i++;
			waitButton();
			continue;
		}
		i++;
		if(step[i] == '\'') {
			switch(c) {
			case 'L': Lr(); break;
			case 'R': R(); break;
			case 'U': Ur(); break;
			case 'D': Dr(); break;
			case 'F': Fr(); break;
			case 'B': Br(); break;
			}
			i++;
		}
		else if(step[i] == '2') {
			switch(c) {
			case 'L': L2(); break;
			case 'R': R2(); break;
			case 'U': U2(); break;
			case 'D': D2(); break;
			case 'F': F2(); break;
			case 'B': B2(); break;
			}
			i++;
		}
		else {
			switch(c) {
			case 'L': L(); break;
			case 'R': Rr(); break;
			case 'U': U(); break;
			case 'D': D(); break;
			case 'F': F(); break;
			case 'B': B(); break;
			}
		}
		//waitButton();
		sleep(400);
	}
	playTone(440, 500);

}


void waitButton() {
	while(SensorValue[S1] == 0) {
		sleep(10);
	}
	while(SensorValue[S1] == 1) {
		sleep(10);
	}
}


/*Examples:
1. L' B' F D' B' L F D U R2 L D' R2 B L'
2. U2 L B2 U2 F' L' B2 D F U L R2 U2 D L'
3. B2 L' R' U F R D L U D2 B' U R' B' F
4. D' F' L D2 B R U B2 L R' D F' B' L F'
5. B' L' R U' D' L' B2 U' D2 B' R D' F' B' D'
6. L F B' R' F2 L' D2 F2 U2 B2 R2 L2 D B L
7. D' B' U2 F R' B' L' F2 R L' D R B D2 U'
8. D F U' L R' F' L B2 F D B R' D L R
9. L B2 D2 F R' B' L' F B' D' U R' L F U2
10. B2 F2 R' B2 F R L2 D' U2 L' F2 D2 B L D2
11. D R' B U D' B' U2 D L' U2 B R L U D'
12. B' U F' R B' D' U' F' B2 D' L' U2 B' F' U2
13. L' R' U' D' L' F2 B' L' F' D U R' B' L D
14. D L' B2 F' R B' F L' B R2 F2 L' D' R' L'
15. F U' B' F R' D' F B' U D' F2 B2 D2 U F'
16. L R' B' U L B2 R' D U' F B U' L' F' B'
17. L' B R' U' L' D2 U R' D2 F2 B R' F' L B2
18. R2 F' U2 L B' U' R' B2 F' D' U' L' B2 R F'
19. R' D' L2 F2 U L' D R U B' L F' B D' F
20. L2 R' F B' L F' D' U2 B' L' F B2 U F' L2
21. F U2 D' R' F2 U2 D' F2 R2 U' L2 B2 R D' L 22. F2 B' R2 L B2 U' R D U B2 R2 U F L R2 23. F' L U' F2 L2 U' F' L D2 R' U L2 D' U' F' 24. L U F L B' D R' B' L D' U2 L' F' R L2 25. L' U' D' F L D F L D F2 U' L' B D' F2 26. U' D2 R2 L U D F' L2 B R' L U' R B D2 27. U2 D' L' R' F' U R2 F B' L2 R D U L' B' 28. B L U' D R' U' F B L' F B' R2 U' B2 R 29. F2 D' B' F' R2 B' U' F' D R2 U' L' F B L' 30. R2 U' D2 B' F U D R' L U2 D2 B U' D R' 31. R' L2 F' U2 R2 F' D U' B' L F' U D F2 U' 32. U' F R2 L2 F D' B' F' D B2 U2 D F' L R 33. L2 B' U D R2 U2 D L U2 R2 D' L' F R2 U' 34. D2 B' L' F' U B R L B2 F D L' R2 B D' 35. L U' B R' F' U R B' L2 U D' L2 F U' R 36. B' U R' D B L2 U R2 D' F U R L F' B' 37. B2 F U R' L U' F R' D' L' U2 R L U2 B' 38. D' L U R L B F D' L R F L2 U B F' 39. R' B U' D L' F' B L' D' B2 L2 R' U L' B' 40. B' R2 L' B D L2 F' R D' F' B D L B' D*/
