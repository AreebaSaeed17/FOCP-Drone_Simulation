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
| **Function**           | **Description** |
|-------------------------|-----------------|
| `BatteryLevel()`        | Initializes the drone’s battery with a random value between 15 and 85. |
| `WeatherInfo()`         | Randomly generates a number between 0 and 2 to assign a weather condition (sunny, windy, or rainy), then selects one randomly. |
| `Check_For_Obstacle()`  | Randomly determines whether an obstacle is present in the path. |
| `SystemMalfunction()`   | Checks the possibility of a system malfunction in the drone. |
| `Delivery_Time()`       | Displays the estimated time required for delivery at each location. |
| `Location_From_User()`  | Prompts the user to input the order of deliveries. |
| `Battery_Drain()`       | Randomly generates the amount of battery drain per trip. |
| `Intro()`               | Displays the battery level and weather condition, then prompts the user to start the day. |
| `Summary()`             | Displays a summary at the end of deliveries, including total, successful, and failed deliveries, plus remaining battery. |
| `Decision_Logic()`      | Core decision-making function that evaluates all conditions and updates delivery status for each delivery. |
# Logic Flow :
1. The program begins with Intro() in which weather and battery level are initialized and the user is asked to start the simulation.   
2. If the user enters 'yes' to proceed with the delivery, Delivery_Time() showcases the estimated time of arrival for each location.   
3. Then Location_From_User() takes input from the user to specify the order of the deliveries.
4. For each location, Decision_Logic() :    
Checks the essential conditions and looks for system malfunction.    
Decides whether to proceed with the delivery, delay it or fail the delivery.    
Updates battery level and delivery counters accordingly.
5. Summary() then displays the final report after all the deliveries.
# - Description of how random environmental factors are simulated :
Environmental factors (weather, obstacles, battery level, battery drain, and malfunction) are randomized using  to simulate real-world unpredictability.
# Execution Instructions :


