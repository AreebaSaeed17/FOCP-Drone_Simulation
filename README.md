# FOCP-Drone_Simulation
# TITLE AND TEAM INFORMATION
# TITLE : DELIVERY DRONE SIMULATOR
# Team Name : 
# Team Memebrs & Roles :
# Areeba Saeed : Team Leader & Programmer 1 ( Designed and implemented core functions, managed user interaction, and coordinated overall project development ).
# Urooj Fatima : Programmer 2 & Logic Designer ( Created the program’s logic flow and flowchart, integrated additional features, and refined the code for efficiency ).
# Heeba Aamir : Git Manager & Tester ( Handled version control and documentation, and performed extensive testing across different inputs and conditions to ensure reliability ).

# Overview / Program Description:
We have created a drone simulator, a program tasked with managing the daily operations of an autonomous delivery drone. Each day the drone completes three deliveries, at location A, B and C. Priot to each delivery, the drone assess the essential conditions such as the current weather (sunny, windy, rainy), battery level and it checks for the presence of potential  obstacles in the path (birds, aircrafts, restricted zones, etc). Based on these conditions, the drone is programmed to take a decision of whether to proceed with the delivery, delay the delivery or return to the base for charging. At the end of each simulated day, the drone generates a mission summary displaying the total number of deliveries deliveries, successful drops, failed attempts, delayed missions, and remaining battery life.
This program simulates real-world decision-making in autonomous systems, integrating environmental awareness, logic, and adaptability. The drone evaluates factors like weather, battery, and obstacles to decide whether to proceed, delay, or return—mirroring real delivery challenges where safety and efficiency matter. Its relevance is clear, as autonomous drones are widely used in logistics, disaster response, agriculture, and surveillance. By modeling these dynamics, the simulator helps developers design modular systems that react intelligently to changing, real-time conditions.
# Program Design / Logic :
# Included Functions :
We have designed the following functions:
BatteryLevel() : We have initialized battery of the drone with a random number between 15 and 85.
WeatherInfo () : Randomly generates a number between 0 and 2 and assigns a particular in this range to each weather (sunny, windy or rainy ) and then randomly selects a weather condition.
Check_For_Obstacle() : Randomly determines whether a potential obstacle in present in the way.
SystemMalfunction () : Checks the possibility of a system malfunction in the drone.
Delivery_Time () : Displays the time it will take to deliver at each particular location.
Location_From_User () : Prompts the user to input the order in which the delivery will take place.
Battery_Drain () : Randomly generates a battery drain per trip.
Intro () : Displays the battery level and the weather condition and prompts the user to start the day.
Summary () : Displays the end of the delivery summary i.e. total deliveries, successful and failed atttempts and the remaining battery.
Decision_Logic () :  Core decision-making function that evaluates conditions and updates delivery status for each delivery. Optimizes the main function as the key decisions are taken here.
