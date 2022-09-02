#include<SoftwareSerial.h>
#include<AFMotor.h>
AF_DCMotor motor_L(1);
AF_DCMotor motor_R(4);

void setup(){
  motor_L.setSpeed(200);
  motor_L.run(RELEASE);
  motor_R.setSpeed(200);
  motor_R.run(RELEASE);
}

void loop(){
  int val1 = digitalRead(A0);
  int val2 = digitalRead(A5);

    if (val1 == 0 && val2 == 0){
      motor_L.run(FORWARD);
      motor_R.run(FORWARD);
    }
    else if (val1 == 0 & val2 == 1){//  우회전
      motor_L.setSpeed(230);
      motor_R.setSpeed(0);
      motor_L.run(FORWARD);
      motor_R.run(FORWARD);
    }
    else if (val1 == 1 && val2 == 0){ // 좌회전
      motor_L.setSpeed(0);
      motor_R.setSpeed(230);
      motor_L.run(FORWARD);
      motor_R.run(FORWARD);
    }

    else if (val1 == 1 && val2 == 1){
      motor_L.setSpeed(200);
      motor_R.setSpeed(200);
      motor_L.run(FORWARD);
      motor_R.run(FORWARD);
    }
}
//46 (150,30) ,40 (180,0), 38 (190,0), 34 (210,0), 34 (210,20)    32 (220,0) 33 (220,10)=== 30 (220,20) ==== 32 (230,0)배터리 교체 후 28, 30 (230,20)
// 풀 배터리 28 (210,0) ---> 30      32(190,0)  
// 왼쪽 바퀴 배터리 2개 교체, 배터리 차이가 심함 2초
// 베스트= 풀 배터리 (230,0) 26초
// 센서 위치 조정 (1)
// 센서 위치 조정 (2) 19 (230,0  , 200 200)
