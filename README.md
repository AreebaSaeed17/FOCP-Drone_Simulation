# FOCP-Drone_Simulation
# TITLE AND TEAM INFORMATION
# TITLE : DELIVERY DRONE SIMULATOR
# Team Name : Drone Engineers 🕹️✨
# Team Memebrs & Roles :
1. Areeba Saeed : Team Leader & Programmer 1       
2. Urooj Fatima : Programmer 2 & Logic Designer 
3. Heeba Aamir : Git Manager & Tester 

# Overview / Program Description:
We have created a drone simulator, a program tasked with managing the daily operations of an autonomous delivery drone. Each day the drone completes three deliveries, at location A, B and C. Priot to each delivery, the drone assess the essential conditions such as the current weather (sunny, windy, rainy), battery level and it checks for the presence of potential  obstacles in the path (birds, aircrafts, restricted zones, etc). Based on these conditions, the drone is programmed to take a decision of whether to proceed with the delivery, delay the delivery or return to the base for charging. At the end of each simulated day, the drone generates a mission summary displaying the total number of deliveries deliveries, successful drops, failed attempts, delayed missions, and remaining battery life.   
This program simulates real-world decision-making in autonomous systems, integrating environmental awareness, logic, and adaptability. The drone evaluates factors like weather, battery, and obstacles to decide whether to proceed, delay, or return—mirroring real delivery challenges where safety and efficiency matter. Its relevance is clear, as autonomous drones are widely used in logistics, disaster response, agriculture, and surveillance. By modeling these dynamics, the simulator helps developers design modular systems that react intelligently to changing, real-time conditions.
# Program Design / Logic :
# Included Functions :
We have designed the following functions:
| **Function**           | **Description** |
|-------------------------|-----------------|
| `BatteryLevel()`        | Initializes the drone’s battery with a random value between 15 and 85. |
| `WeatherInfo()`         | Randomly generates a number between 0 and 2 and assigns it a weather condition (sunny, windy, or rainy), then selects one randomly. |
| `Check_For_Obstacle()`  | Randomly determines whether an obstacle is present in the path. |
| `SystemMalfunction()`   | Checks the possibility of a system malfunction in the drone. |
| `Delivery_Time()`       | Displays the estimated time required for delivery at each location. |
| `Location_From_User()`  | Prompts the user to input the order of deliveries. |
| `Battery_Drain()`       | Randomly generates the amount of battery drain per trip. |
| `Intro()`               | Displays the battery level and weather condition, then prompts the user to start the day. |
| `Summary()`             | Displays a summary at the end of deliveries, including total, successful, and failed deliveries, plus remaining battery. |
| `Decision_Logic()`      | Core decision-making function that evaluates all conditions and updates delivery status for each delivery. |
| `SuccessRate()`         | Displays the success rate of the deliveries (performance score). |
| `HeavyLoad()`           |Displays the load that the drone carries and issues a warning if the load is over a specified threshold. |
| `DelayTimer()`          | Adds a small pause after each delivery to reflect realistic drone behavior and simulate time spent in transit or handling. |
# Logic Flow :
1. The program begins with Intro() in which weather and battery level are initialized and the user is asked to start the simulation.   
2. If the user enters 'yes' to proceed with the delivery, Delivery_Time() showcases the estimated time of arrival for each location.   
3. Then Location_From_User() takes input from the user to specify the order of the deliveries.
4. For each location, Decision_Logic() :    
Checks the essential conditions and looks for system malfunction.    
Decides whether to proceed with the delivery, delay it or fail the delivery.    
Updates battery level and delivery counters accordingly.
5. Summary() then displays the final report after all the deliveries.
# Description of how random environmental factors are simulated :
Environmental factors (weather, obstacles, battery level, battery drain, and malfunction) are randomized using  to simulate real-world unpredictability.
# Execution Instructions :
ON A COMPILER :    
Complile the code on a C++ compatible compiler like g++ and then run it.    
On Git Bash :   
Open a terminal in the folder containing the program file.       
Compile the program using:       
g++ -o drone_simulator "Final Optimized Code.cpp"            
Run the program:        
drone_simulator.exe           
# Team Collabration Summary :
TASK DISTRIBUTION :    
1. Areeba Saeed : Designed and implemented the core program functions focusing on efficient logic and modular structure, handled all aspects of user interaction and interface flow, and coordinated the overall project development to ensure smooth integration of all components.
2. Urooj Fatima : Created the program’s overall logic flow and designed the accompanying flowchart to visualize system behavior. Integrated additional features to enhance functionality and refined the code for greater efficiency and readability.
3. Heeba Aamir : Handled version control and project documentation, ensured smooth collaboration while conducting extensive testing across a variety of inputs and conditions to ensure the program’s accuracy, stability, and reliability.
# Evidence Of Git :
# AI Tool Reflection :
We have utilised the help of AI specifically Chat GPT for two things in our program:    
1. Function for delay timer : We have added the delay timer function with the help of AI. When encountred with the task, we tried several times before resorting to the help of AI. With the help of Chat GPT, we learned how to simulate real-time pauses in program execution using system-level functionality. Working with AI to implement this taught us how to use platform-specific libraries like windows.h to access built-in functions such as Sleep() and how to modularize functionality by creating reusable delay logic instead of repeating code.     
2. Performance Score Formula : With the help of Chat GPT, we developed a formula for performance score to evaluate the performance of our drone in order to see how effectively and reliably it operates under various conditions and determine mission success. We learned how to turn real-world behavior into measurable logic and use AI to design, refine, and implement a scoring system efficiently.



