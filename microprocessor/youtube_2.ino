//https://www.youtube.com/watch?v=ZlaXao6m7zE
#include <Servo.h>

#define MAX_NUM 10
int value_list[MAX_NUM];
int reading_index = 0;

Servo servo[6];


int target_angle_list[6];
int cur_angle_list[6];


void setup()   {
  Serial.begin(9600);
  
  servo[0].attach(3);
  servo[1].attach(5);
  servo[2].attach(6);
  servo[3].attach(9);
  servo[4].attach(10);
  servo[5].attach(11);

}


void loop() {
  
}
void angle(int angles[6]) {
  for(int i =0; i<6;i++)
  {
    if(target_angle_list[i]>cur_angle_list[i])//목표 각도보다 현재 각도가 작은경우
    {
      cur_angle_list[i]++; //현재 각도를 1도 증가
    }
    if(target_angle_list[i]<cur_angle_list[i])//목표 각도보다 현재 각도가 큰경우
    {
      cur_angle_list[i]--; //현재 각도를 1도 감소
    }
    servo[i].write(cur_angle_list[i]);//서보에 현재 각도를 반영
  }
  delay(30); //회전속도 딜레이
  
}
