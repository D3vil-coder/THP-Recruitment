# Multi Arduino Control Using I2C

## Description

So in this Simulation , We are using 3 Arduinos [1 Master and 2 Slaves].
<br>The Slave-1 has an Ultrasonic Distance Sensor attached to it, which continously reads echos ultrasonic waves.
<br>On detecting an object closer than Threshold limit, The slave sends a message to Master and Master relays the message to Slave-2 to stop the Motor.

The Adresses of the slaves help the master to distinguish between slaves.
<br>The Master here has the sole job to relay Messages and take decisions based on input.

