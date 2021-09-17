#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>
#include <webots/Robot.hpp>
#include <webots/Keyboard.hpp>
#include <webots/GPS.hpp>
#include <webots/InertialUnit.hpp>

#define TIME_STEP 64
using namespace webots;

int main(int argc, char **argv) {
 Robot *robot = new Robot();
 Keyboard kb;

/*Motor *gr1;//linear grabber 1
gr1=robot->getMotor("grabber1");

Motor *gr2;//linear grabber2
gr2=robot->getMotor("grabber2");*/

Motor *rm;//rotation motor 1 at twister 1
rm=robot->getMotor("twister1");

/*Motor *rm1;//rotation motor 2 at twister 2
rm1=robot->getMotor("twister2");*/

Motor *bm;//bend motor 1 at pivot 1
bm=robot->getMotor("pivot1");

Motor *bm1;//bend motor 2 at pivot 2
bm1=robot->getMotor("pivot2");

Motor *bm2;
bm2=robot->getMotor("pivot3");

Motor *rm1;//rotation motor 2 at twister 2
rm1=robot->getMotor("twister2");

Motor *gb;
gb=robot->getMotor("grabber1");

Motor *gb1;
gb1=robot->getMotor("grabber2");

Motor *gb2;
gb2=robot->getMotor("grabber3");

Motor *gb3;
gb3=robot->getMotor("grabber4");
//Motor *gb2;
//gb2=robot->getMotor("grabber3");

/*Motor *rm;//rotation motor 1 at twister 1
Motor *rm1;//rotation motor 2 at twister 2
Motor *bm;//bend motor 1 at pivot 1
Motor *bm1;//bend motor 2 at pivot 2*/
//rm=robot->getMotor("twister1");
//rm1=robot->getMotor("twister2");
//bm=robot->getMotor("pivot1");
//bm1=robot->getMotor("pivot2");

 Motor *wheels[4];
 char wheels_names[4][8] = {"wheel1", "wheel2", "wheel3", "wheel4"};
 for (int i = 0; i < 4; i++) {
   wheels[i] = robot->getMotor(wheels_names[i]);
   wheels[i]->setPosition(INFINITY);
   wheels[i]->setVelocity(0.0);
 }


 kb.enable(TIME_STEP);
 double leftSpeed = 0.00;
 double rightSpeed = 0.00;
 double rotate =0.00;
 double bend=0.00;
 double rotate1 =0.00; 
 double bend1=0.00;
 double bend2=0.00;
 double grabber=0.00;
 double grabber1=0.00;
 double grabber2=0.00;
 double grabber3=0.00;
 //double grabber2=0.00;
 /*double linear1=0.00;
 double linear2=0.00;*/
 
 while (robot->step(TIME_STEP) != -1) {
   int key=kb.getKey();
  
   if (key== 315){
   leftSpeed = 10.0;
   rightSpeed = 10.0;
   } else if (key==317){
   leftSpeed = -10.0;
   rightSpeed = -10.0;
   }else if (key==316){
   leftSpeed = 10.0;
   rightSpeed = -10.0;
   }else if (key==314){
   leftSpeed = -10.0;
   rightSpeed = 10.0;
   }else {
   leftSpeed = 0.0;
   rightSpeed = 0.0;
   }

   wheels[0]->setVelocity(leftSpeed);
   wheels[1]->setVelocity(rightSpeed);
   wheels[2]->setVelocity(leftSpeed);
   wheels[3]->setVelocity(rightSpeed);
  
 //twister 1 rotational 
 if(key==65) //&& rotate<6.283)//keyboard a
 {
 rotate += 0.05;
 }
 else if (key==68) //&& rotate>0)//keyboard d 
 {
 rotate += -0.05;
 }
 else {
 rotate +=0;
 }
 rm->setPosition(rotate);
 
 //bend 90 degree pivot 1 
 if(key==87 && bend>-1.57)//keyboard w
 {
 bend += -0.05;
 }
   else if (key==83 && bend<1.57)//keyboard s 
 {
 bend += 0.05;
 }
 else {
 bend +=0;
 }
 bm->setPosition(bend);
 
 //twister 2 rotational 
 if(key==90)//keyboard z
 {
 rotate1 += 0.05;
 }
 else if (key==88)//keyboard x 
 {
 rotate1 += -0.05;
 }
 else {
 rotate1 +=0;
 }
 rm1->setPosition(rotate1);
 
 
 //bend 90 degree pivot 2
 if(key==81 && bend1>-1.55)//keyboard q
 {
 bend1 += -0.05;
 }
 else if (key==69 && bend1<0)//keyboard e 
 {
 bend1 += 0.05;
 }
 else {
 bend1 +=0;
 }
 bm1->setPosition(bend1);

 //bend 90 degree pivot 3
 if(key==70 && bend2>-1.55)//keyboard f
 {
 bend2 += -0.05;
 }
 else if (key==67 && bend2<0)//keyboard c  
 {
 bend2 += 0.05;
 }
 else {
 bend2 +=0;
 }
 bm2->setPosition(bend2); 
 

if(key==79 && grabber>-0.9 && grabber1<0.9 && grabber2>-0.9 && grabber3<0.9)//keyboard o
 {
 grabber += -0.05;
 grabber1 += 0.05;
 grabber2 += -0.05;
 grabber3 += 0.05;
 //grabber2 += 0.05;
 }
 else if (key==80 && grabber<0 && grabber1>0 && grabber2<0 && grabber3>0)//keyboard p  
 {
 grabber += 0.05;
 grabber1 += -0.05;
 grabber2 += 0.05;
 grabber3 += -0.05;
 //grabber2 += -0.05;
 }
 else {
 grabber +=0;
 grabber1 +=0;
 grabber2 +=0;
 grabber3 +=0;
 //grabber1 +=0;
 //grabber2 +=0;
 }
 gb->setPosition(grabber); 
 gb1->setPosition(grabber1);
 gb2->setPosition(grabber2);
 gb3->setPosition(grabber3);
 //gb2->setPosition(grabber2);

/*if(key==75 && grabber3<0.7)//keyboard k
 {
 grabber3 += 0.05;
 //grabber1 += 0.05;
 //grabber2 += 0.05;
 }
 else if (key==76 && grabber3>0 )//keyboard l  
 {
 grabber3 += -0.05;
 //grabber1 += -0.05;
 //grabber2 += -0.05;
 }
 else {
 grabber3 +=0;
 //grabber1 +=0;
 //grabber2 +=0;
 }
 gb3->setPosition(grabber3); */
 }
 delete robot;
 return 0;  // EXIT_SUCCESS
}
