# Deadlocks-Algorithm-Simulation - The ☠️🔒 Prevention Software

This Software is a C++ and Qt based university project which goal it is to visually understand the phenomenon of "deadlocks" in operating systems and to learn about algorithms for preventing them.

## Description
All the processes in a system require some resources such as central processing unit(CPU), file storage, input/output devices, etc to execute it. 

Once the execution is finished, the process releases the resource it was holding. However, when many processes run on a system they also compete for these resources they require for execution. This may arise a deadlock situation.

A **deadlock** is a situation in which more than one process is blocked because it is holding a resource and also requires some resource that is acquired by some other process. Therefore, none of the processes gets executed.

As you could guess: Deadlock prevention is a big and important topic, which is why there are many different approaches to prevention, reversal and elimination.

The program has 4 built-in algorithms to visually show you how they work against Deadlocks:

-Eliminate **Hold And Wait** ⌛

-Eliminate **Circular Wait** 🔃

-Eliminate **No Preemption** 🚦

-**Bankier Algorithm** 💸

![image](https://github.com/breathTake/Deadlocks-Algorithm-Simulation/assets/104220135/78ce6c3d-74ee-4a63-ab08-91ce015ee5c2)


Deadlocks are only able to occur if all four conditions are true. Each of the four algorithms is against one of those conditions, so you only need one algorithm and a Deadlock cannot be created. 

## Installation
1. Clone the GitHub repository:

   ```bash
   git clone https://github.com/breathTake/Deadlocks-Algorithm-Simulation.git
   ```

2. Install any required dependencies and configurations as instructed in the project documentation.

3. Build the project using the appropriate build tool (e.g., CMake or qmake).

4. Launch the application and start simulating the network.

## Operation manual - Get to know the Software
At First you have the starting window in which you can choose the Algorithm and the number of resources.
![image](https://github.com/breathTake/Deadlocks-Algorithm-Simulation/assets/104220135/130da475-099b-4e1b-be44-ee33829b43ce)

The Main-GUI is seperated into four different parts, with each one being necessary for the general understanding of deadlocks.

### 1. Control Panel & Time Stamps

Here you can find:
- the time the algorithm is running
- the current used algorithm to prevent a deadlock situation
- a log-output field where you can see which process acquires how much of a resource
- the start, stop and restart button
  
![image](https://github.com/breathTake/Deadlocks-Algorithm-Simulation/assets/104220135/561e7438-4645-4321-b46e-3183139eb57e)

### 2. Requirements
- On the left side of the matrix are the four different processes used to show the general algorithm. 
- The Top shows different Resources: Printer, CD...
-> The numbers inside the matrix: **The needed count of resources a process needs to work with**.

During the Simulation you will notice, that the numbers are shrinking. This is because the matrix only shows the **still** needed resources and subtracts the already acquired ones.

![image](https://github.com/breathTake/Deadlocks-Algorithm-Simulation/assets/104220135/0ca8329f-1908-4bc3-84f5-ed8a361425b5)


### 3. Availability Panel
This table has many functionalities:
1. The green colour indicates, that the resources is used by at least one process
2. The numbers (e.g. 0/1) show how many of the given resources are being used right know ( 1/1 Printer used)
3. Processes who use some of the resources at the moment, are being listed inside the white label bar

![image](https://github.com/breathTake/Deadlocks-Algorithm-Simulation/assets/104220135/725a7769-7d69-4ae8-ab42-5d3ba4642d8a)


### 4. Occupation
The Occupation matrix gives another overview of the whole situation. 

You can see which **process** has which **resources** and how **many** of them

![image](https://github.com/breathTake/Deadlocks-Algorithm-Simulation/assets/104220135/280a4707-269f-4a9f-8cad-92252050eed4)

This is based on the Occupation matrix given in the Book from A. Tanenbaum

![image](https://github.com/breathTake/Deadlocks-Algorithm-Simulation/assets/104220135/87310fba-8d58-4776-99ac-2eeb609995f1)


## Literature & Links
-[**Moderne Betriebssysteme**] by Andrew S. Tanenbaum

-[**Qt Framework**], [link](https://doc.qt.io)

