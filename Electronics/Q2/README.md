# Programming a Humanoid’s Wheelbase for Movement 

## Explaining the code

Well so this is the code I've used for the Tinker CAD simulation

I defined variables and wrote some functions to make the code readable and clean.

Sharp turns basically are spinning the right and left motors in opposite direction.

Smooth Turns are basically turning off the side where turn has to be taken and let the opposite side motors move forward.

Since Tinker CAD has a lot of limitations here are some of the assumptions:
- Since RPM is not known accurately , instead of 5 rotations I set it to rotate for 5sec.
- A rough assumption that all turns happen in 2 sec.
- Since 90 deg turn happens in 2 sec , a U Turn would take 4 seconds.
- Loop goes on forever and bot initially starts from G to A.

A U-Turn can be taken by taking sharp left or right for time double a 90-degree Turn.
It is true that smooth turn takes longer than sharp turns but rather than complicating the code with more variables,
I've tried to keep the code since here my concepts , understanding and efforts are being analysed rather than the actual code.

I wanted to incorporate an ultrasonic sensor and path planning algo too for the ***NOTE*** in the question , but it is very inconvinient to add it in the Tinker CAD Environment
Instead I will mention my logic here - 
<br>
We could use some sensor like ultrasonic sensor to detect obstacle and use path planning algos to reroute the bot but making it turn around the obstacle or backtracking. 
