# 535-project-1

# **Electric Car Traveler   |   Team Xeno**



# _**Description:**_

The algorithm for electric car traveler problem is designed and implemented in the given report. The electric car has capacity C which is the maximum number of miles the electric car can drive. After the capacity is reached the car needs to be recharged. From source to destination, car travels through n cities which have charging stations. There are cases where the chargers may not function in a particular city, in that situation the car should go back to previous station and recharge.



# _**Group members:**_

Hardik Bhawsar  hardik_bhawsar@csu.fullerton.edu

Anvit Patil     anvit.patil@csu.fullerton.edu     

Praveen Singh   praveen.singh@csu.fullerton.edu



# _**Assumptions:**_ 

Given a capacity C in miles that represents the maximum number of miles your electric car can drive, n cities and (n-1) distances between two consecutive cities, design an algorithm that outputs the list L of cities where one need to stop and charge the car such that:
1. L is if minimum length among all possible list of cities
2. the starting city, which is the first city, is the first element of L
3. The destination city, which is the last city, is the last element of L
4. If j and k are two consecutive cities in L, then when the car is in city j, the car can drive to city k and back to the city before city k, in case the charge station in city k is broken.
5. The capacity C in miles is not fixed, but one can assume that is a positive integer between 250 and 350.
6. The number of cities n is not fixed, but you can assume that it is greater than 3 and less than 20. 
7. The distance between cities is a positive integer and always less than C/2 and greater than 10.

