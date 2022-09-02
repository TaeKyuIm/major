#include <Servo.h>
#include <ServoEasing.hpp>

#define BASE 3
#define SHOULDEDR 4
#define ELBOW 5
#define WRIST 6
#define GRIP 7
#define GRIPPER 8

const int toggle_pin =13;
int flag = 0;
boolean toggle_state = 0;

ServoEasing S1, S2, S3, S4, S5, S6;

void setup() {
  Serial.begin(9600);
pinMode(toggle_pin,INPUT_PULLUP);

S1.attach(BASE);
S2.attach(SHOULDEDR);
S3.attach(ELBOW);
S4.attach(WRIST);
S5.attach(GRIP);
S6.attach(GRIPPER);

S1.setSpeed(250);
S2.setSpeed(250);
S3.setSpeed(250);
S4.setSpeed(300);
S5.setSpeed(300);
S6.setSpeed(300);
}

void loop() {
  if(digitalRead(toggle_pin)==0){
    if(flag==0){
      flag = 1;
      toggle_state = !toggle_state;
      set_arm(138,70,43,177,140,0);
    }
  }
  else{
    if(flag ==1){
      flag = 0;
      set_arm(138,70,43,177,140,0);
      set_arm(138,93,42,175, 140,40); //7번큐브 위
      set_arm(138,93,42,175, 140,80); //잡고
      set_arm(138,73,42,175, 140,80);// 위로
      set_arm(17,71,43,177,45,80); //박스위
      set_arm(17,71,43,177,45,0);//투하

      set_arm(150,71,48, 160, 55,0);
      set_arm(150, 101, 48, 160, 55, 40); //8번큐브 위
      set_arm(150, 101, 48, 160, 55, 40); //아래
      set_arm(150, 101, 48, 160, 55, 80); //잡고
      set_arm(150, 65, 48, 164, 55, 80);// 위로
      set_arm(19, 65, 48, 164, 55, 80); //박스위
      set_arm(19, 67, 31, 180, 55, 0);//투하
  
      set_arm(19, 67, 87, 167, 56, 0);
      set_arm(155, 67, 87, 167, 56, 0);
      set_arm(155, 113, 87, 167, 56, 0);
      set_arm(155, 123, 77, 160, 65, 0); //아래
      set_arm(155, 123, 77, 160, 65, 80); //잡고
      set_arm(155, 85, 77, 160, 65, 80);// 위로
      set_arm(21, 92, 58, 175, 56, 80); //박스위
      set_arm(21, 92, 58, 175, 56, 0);//투하
      
      set_arm(148,62,3,152,110,1); //4번공 위
      set_arm(148,77,3,159,110,1); //아래
      set_arm(148,77,3,159,110,76); //잡고
      set_arm(148,35,3,159,110,76); //탁구공 위
      set_arm(37,35,29,128,110,76);
      set_arm(37,89,29,128,110,76); //놓는 곳 위
      set_arm(37,100,29,128,110,76);//아래
      set_arm(37,100,29,128,110,24);//놓고
      set_arm(37,89,29,128,110,24);//위로
    
      set_arm(158,77,16,148,106,13); //5번공 위
      set_arm(158,83,16,148,106,13); //아래
      set_arm(158,83,16,148,106,76); //잡고
      set_arm(158,63,16,148,106,76); //큐브 위
      set_arm(43,47,42,160,106,76);
      set_arm(43,90,42,160,106,76);//아래
      set_arm(43,90,42,160,106,13);//놓고
      set_arm(43,78,42,160,106,13);//위로
    
      set_arm(165,94,52,159,106,0); //6번공 위
      set_arm(165,109,52,154,106,0); //아래
      set_arm(165,109,52,154,106,70); //잡고
      set_arm(165,89,52,154,106,70); //큐브 위
      set_arm(54,64,43,173,99,70);
      set_arm(54,70,43,173,99,70); //놓는 곳 위
      set_arm(54,91,43,173,99,70);//아래
      set_arm(54,91,43,173,99,0);//놓고
      set_arm(54,70,43,173,99,0);//위로
    
      set_arm(54,80,43,173,99,0);
      set_arm(176,80,40,155,83,0); //3번큐브 위
      set_arm(176,96,40,155,83,52); //아래
      set_arm(176,96,40,155,83,80); //잡고
      set_arm(176,80,40,155,83,80); //큐브 위
      set_arm(23,80,40,155,83,80); //박스위
      set_arm(23,80,40,155,83,0);//투하
    
      set_arm(23,70,40,155,83,0);
      set_arm(176,70,24,162,83,12); //2번큐브 위
      set_arm(176,85,24,162,83,12); //아래
      set_arm(176,85,24,162,83,80); //잡고
      set_arm(176,70,24,162,83,80); //큐브 위
      set_arm(23,70,24,162,83,80); //박스위
      set_arm(23,70,24,162,83,0);//투하
    
      set_arm(173,39,9,180,83,0); //1번큐브 위
      set_arm(173,68,9,180,83,0); //아래
      set_arm(173,68,9,180,83,80); //잡고
      set_arm(173,39,9,180,83,80); //큐브 위
      set_arm(23,39,9,180,83,80); //박스위
      set_arm(23,39,9,180,83,50);//투하
    }
  }
}

void set_arm(int s1, int s2, int s3, int s4, int s5, int s6){

  S1.setEasingType(EASE_LINEAR);
  S2.setEasingType(EASE_LINEAR);
  S3.setEasingType(EASE_LINEAR);
  S4.setEasingType(EASE_CUBIC_IN_OUT);
  S5.setEasingType(EASE_CUBIC_IN_OUT);
  S6.setEasingType(EASE_CUBIC_IN_OUT);
  
  S1.easeTo(s1,105);
  S2.easeTo(s2,105);
  S3.easeTo(s3,105);
  S4.easeTo(s4,105);
  S5.easeTo(s5,105);
  S6.easeTo(s6,105);
  delay(50);
  
}
