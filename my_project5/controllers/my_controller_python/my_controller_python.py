"""my_controller_python controller."""

# You may need to import some classes of the controller module. Ex:
#  from controller import Robot, Motor, DistanceSensor
#//from controller import Robot
#//from controller import Keyboard


# create the Robot instance.
#//robot = Robot()

# get the time step of the current world.
#//timestep = int(robot.getBasicTimeStep())

# You should insert a getDevice-like function in order to get the
# instance of a device of the robot. Something like:
#  motor = robot.getMotor('motorname')
#  ds = robot.getDistanceSensor('dsname')
#  ds.enable(timestep)

# Main loop:
# - perform simulation steps until Webots is stopping the controller
#//while robot.step(timestep) != -1:
    # Read the sensors:
    # Enter here functions to read sensor data, like:
    #  val = ds.getValue()

    # Process sensor data here.

    # Enter here functions to send actuator commands, like:
    #  motor.setPosition(10.0)
    #//pass

# Enter here exit cleanup code.
from controller import Robot
from controller import Keyboard
#LEFTSPEED=0
#RIGHTSPEED=0
LEFTSPEED=10
RIGHTSPEED=10
WHEEL1 = 5.0
WHEEL2 = 5.0
WHEEL3 = 5.0
WHEEL4 = 5.0
TIME_STEP = 64
#CRUISING_SPEED = 5.0
#TURN_SPEED = CRUISING_SPEED/2.0
#TIME_STEP=64

robot = Robot()

#initialize devices
#motor= [4]
#wheel_names=['wheel1' , 'wheel2', 'wheel3','wheel4']
#for i in range (4):
#	motor.append(robot.getDevice(wheel_names[i]))
#	motor[i].enable(TIME_STEP)

#left_wheel = robot.getDevice('left wheel')
#right_wheel = robot.getDevice('right wheel')
#left_wheel.setPosition(float('inf'))
#right_wheel.setPosition(float('inf'))
#left_wheel.setVelocity(0.0)
#right_wheel.setVelocity(0.0)

wheel1=robot.getDevice('wheel1')
wheel2=robot.getDevice('wheel2')
wheel3=robot.getDevice('wheel3')
wheel4=robot.getDevice('wheel4')

wheel1.setPosition(float('inf'))
wheel2.setPosition(float('inf'))
wheel3.setPosition(float('inf'))
wheel4.setPosition(float('inf'))

wheel1.setVelocity(0.0)
wheel2.setVelocity(0.0)
wheel3.setVelocity(0.0)
wheel4.setVelocity(0.0)
#left_wheel.setVelocity(0.0)
#right_wheel.setVelocity(0.0)

keyboard = Keyboard()
keyboard.enable(TIME_STEP)


motor_cmd ={
	#ord('W'): (WHEEL1,WHEEL2,WHEEL3,WHEEL4), #move forward
	#ord('S'): (-WHEEL1,-WHEEL2,-WHEEL3,-WHEEL4),#move backward
	#ord('A'): (-WHEEL1,WHEEL2,-WHEEL3,WHEEL4), #Turn left
	#ord('D'): (WHEEL1,-WHEEL2,WHEEL3,-WHEEL4), #Turn Right
	#ord('X'): (0.0,0.0,0.0,0.0)#MotorCommand(0.0,0.0,0.0,0.0), #stop
	ord('W'): (LEFTSPEED,RIGHTSPEED), #move forward
	ord('S'): (-LEFTSPEED,-RIGHTSPEED),#move backward
	ord('A'): (-LEFTSPEED,RIGHTSPEED), #Turn left
	ord('D'): (LEFTSPEED,-RIGHTSPEED), #Turn Right
	ord('X'): (0.0,0.0,0.0,0.0)#MotorCommand(0.0,0.0,0.0,0.0), #stop

}

def command_motors(cmd):
	wheel1.setVelocity(cmd[0])
	wheel2.setVelocity(cmd[1])
	wheel3.setVelocity(cmd[0])
	wheel4.setVelocity(cmd[1])

while robot.step(TIME_STEP) != -1:

    key=keyboard.getKey()
#    if (key == ord('W')):
#        LEFTSPEED=10
#        RIGHTSPEED=10
#    elif (key == ord('S')) : 
#        LEFTSPEED=-10
#        RIGHTSPEED=-10
#    elif (key==ord('A')) :
#        LEFTSPEED=-10
#        RIGHTSPEED=10
#    elif (key==ord('D')) :
#        LEFTSPEED=10
#        RIGHTSPEED=-10
#    else :
#        LEFTSPEED=0
#        RIGHTSPEED=0

#wheel1.setVelocity(LEFTSPEED)
#wheel2.setVelocity(RIGHTSPEED)
#wheel3.setVelocity(LEFTSPEED)
#wheel4.setVelocity(RIGHTSPEED)
    if key in motor_cmd.keys():
        command_motors(motor_cmd[key])
	   