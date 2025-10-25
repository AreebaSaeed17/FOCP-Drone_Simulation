//This is a C++ program that simulates the working of a delivery Drone
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;			
//__________________Creating all the necessary functions__________________

int BatteryLevel() {
	//I want the battery level to be btw 85 and 15
	int battery_level = (rand() % 71) + 15;
	return battery_level;
}

string WeatherInfo() {
	int random_number = rand() % 3;
	if (random_number == 0) {
		return "Sunny";
	}
	else if (random_number == 1)
	{
		return "Rainy";
	}
	else{
		return "Windy";
	}
}

bool Check_For_Obstacle() {
	// no of choices = 2
	return (rand() % 2) == 1;
}

/*This is to create an error in the system functioning to depict real life sceanrio.
I've added a 10% malfunction chance.
If the number is exactly divisible by 10, only then it will flag it as true, else it stays false
Chances of obtaining 10 out of 100 numbers is exactly 10.*/
bool SystemMalfunction() {
	return (rand() % 10) == 0;
}

void Delivery_Time() {
	//Hardcoding ETA to display before proceeding to take the order
	cout << "Estimated Time Of Arrival for the Eligible Locations is: \n";
	cout << "Location A: 10 mins\n";
	cout << "Location B: 15 mins\n";
	cout << "Location C: 33 mins\n";
	cout << "__________________________________________________________\n";
}
void Location_From_User(string& loc1, string& loc2, string& loc3) {
	//prompting to get order of delivery
	//since this doesn't return anything hence void is used
	cout << "Where do you want to deliver the package first? (Loc A,B,C? )\n";
	cin >> loc1;
	cout << "Where do you want to deliver the package next? (Loc A,B,C? )\n";
	cin >> loc2;
	cout << "Where do you want to make the final delivery to? (Loc A,B,C? )\n";
	cin >> loc3;
}

int Battery_Drain() {
	//to keep in between 10 & 25 as per the qs req
	int battery_drain = (rand() % 16) + 10;
	return battery_drain;
}

void intro(int& battery, string& weather, string& start) {
	//& modifies the actual variables from main
	//I created variables as parameters in the intro function
	//these 2 lines store values in them from the other functions

	battery = BatteryLevel();
	weather = WeatherInfo();
	cout << "********** Welcome to the Delivery Program! ********** \n";
	cout << endl;
	cout << "System Information is as follows: \n";
	cout << "Battery: " << battery << " %\n";
	cout << "Current Weather: " << weather;
	cout << endl;
	cout << "Do you want to start today's delivery? \n";
	cout << "Type 'yes' to proceed \n";
	cin >> start;
	cout << "________________________________________________________ \n";
}
void SuccessRate(int successful, int unsuccessful, int delayed) {
    double rate = (static_cast<double>(successful) / (successful + unsuccessful + delayed)) * 100.0;
    cout << "Success Rate: " << rate << "%\n";
}
bool heavyload()
{cout<<"----------Measuring Weight-----------\n";
 int weight = rand()%10+1;
 
 if(weight > 5)
   { cout<<"HEAVY LOAD WARNING!!!!\nWeight is more than 5kg, Drone might slow down during mission\n";
   return 0;}
 else 
   {cout<<"Weight is within the limit Drone taking off \n";
   return 1;}
  }
void DelayTimer(int DelayTime) {
    Sleep(DelayTime);}	

void summary(int successful, int delayed, int failed, int battery) {
	cout << "\n";
	cout << " ************ DAILY SUMMARY ***********\n";
	cout << "Today's Operation Summary is as Follows: \n";
	cout << "Successful Deliveries: " << successful << endl;
	cout << "Delayed Deliveries: " << delayed << endl;
	cout << "Failed Deliveries: " << failed << endl;
	cout << "Remaining Battery: " << battery << " %\n";
	cout << "***************************************\n";
	SuccessRate(successful,delayed,failed);
}

void Decision_Logic(string location, int& battery, int& successful, int& delayed, int& failed) {
	//I've created this funCtion to easily check the constraints for delivery each time
      heavyload();
	//displaying where The Drone is Delivering
	cout << "Delivering to: " << location << endl;

	//safety check before proceeding
	if (battery <= 5) {
		cout << "Battery Critically LOW!";
		failed += 1;
		return;
	}
	//calling in the conditions that have been generated in other functions
	string weather = WeatherInfo();
	int battery_drain = Battery_Drain();
	bool obstacle = Check_For_Obstacle();
	DelayTimer(3000);

	//displaying conditions to the user
	cout << "Battery: " << battery << " %\n";
	cout << "Current Weather: " << weather << endl;
	//if SystemMalfunction istrue, then this block of code gets executed, else not
	//This will result in a failed delivery attempt
	if (SystemMalfunction()) {
		cout << "ERROR!\n";
		cout << "System Failure!! \n";
		cout << "Sorry, The Drone Cannot Perform This Delivery.\n";
		battery -= battery_drain;
		failed += 1;
		return;
	}
	Adding a feature thats asks the user if he wants to recharge the battery mid mission if it reaches a certain value.
	if (battery <=25 && battery > 5) {
	cout << battery << "% battery reached\n Do you want to recharge it ?\n";
	string choice;
	cin >> choice;
	if (choice == "yes" || choice == "Yes" || choice == "YES") {
		cout << "Returning to base to recharge\n";
		battery += 30;
		cout << battery << "%\n";
	}
	else {
		cout << "Continuing with the deliveries\n";
	}
}
	//Checking for the conditions specified in the Assignment problem
	if (weather == "rainy") {
		cout << "Delivery delayed due to Rainy Weather.\n";
		delayed += 1;
		return;
	}
	if (weather == "windy" && battery < 40) {
		cout << "Battery is LOW for safe operation in Windy Weather.\n";
		cout << "Do you want to recharge the battery? (yes/no? ) \n";
		string recharge_choice;
		cin >> recharge_choice;
		if (recharge_choice == "yes" || recharge_choice == "YES" || recharge_choice == "Yes") {
			//This is the incremented value of battery after recharging from the base(+10%)
			battery += 10;
			cout << "Returning To The Base To recharge.\n";
			cout << "Current Battery Level: " << battery << endl;

			//After recharging, the drone attempts the delivery, so we subtract the battery used for the trip
			battery -= battery_drain;

			//This is a safety check i.e if battery is still too low, the drone should not fly
			//Even after recharging and subtracting the drain I want to make sure the drone has enough battery left to complete the delivery safely
			if (battery > 15) {
				cout << "Battery sufficiently recharged to resume delivery.\n";
				cout << "Path clear, System functional. Performing Delivery Successfully!\n";
				successful += 1;
			}
			//if the battery is still too Low
			else {
				cout << "Battery too LOW to resume delivery.\n";
				cout << "Delivery Failed\n";
				failed += 1;
			}
			//Return in void is used to stop further execution of the function when a condition is met
			return;
		}

		//if user says No to recharge
		else {
			cout << "Delivery delayed due to low Battery.\n";
			delayed += 1;
			return;
		}
	}

	if (obstacle) {
		cout << "Obstacle Detected! Rerouting.....\n";
		//Due to rerouting, extra battery is spent which then causes extra battery drain
		battery_drain += 5;
		battery -= battery_drain;

		/*safety check to see if drone should go to the location after rerouting
		Battery has already been decremented due to rerouting
		Now I want to see if drone can safely start moving towards location or just come back*/
		if (battery > 15) {
			cout << "Delivery Successful After Rerouting.\n";
			successful += 1;
		}
		else {
			cout << "Battery too LOW to resume delivery! Returning To Base.\n";
			cout << "Delivery Failed.\n";
			failed += 1;
		}
		return;
	}

	//Default working if none of above cases(weather, battery or obstacle) were generated and faced
	cout << "Path clear, System functional. Performing Delivery Successfully!\n";
	battery -= battery_drain;
	successful += 1;
}

//____________________Defining the main function____________________

int main() {
	//Seed the rand function to get different result each time
	srand(time(NULL));
	string start, weather;
	int battery;

	//Calling in the intro function to display the Welcome msg
	intro(battery, weather, start);

	if (start == "yes" || start == "Yes" || start == "YES") {
		//Calling Delivery_Time() function to display ETA
		Delivery_Time();
		
		//initializing counters to store status of delivery
		int successful = 0, delayed = 0, failed = 0;
		string location;
		string loc1, loc2, loc3;

		//This function call runs the code to ask for location of delivery
		Location_From_User(loc1, loc2, loc3);

		/*Implements the delivery logic for delivering to each of the locations
		Calling the Delive function three times, each time with:
		1- A new location
		2-The updated battery
		3-Randomly generated weather, obstacle, and drain*/


		/*For all the delivery attempts, the battery value is carried on,
		only new drain is found and decremented*/
		Decision_Logic(loc1, battery, successful, delayed, failed);
		cout << endl;
		Decision_Logic(loc2, battery, successful, delayed, failed);
		cout << endl;
		Decision_Logic(loc3, battery, successful, delayed, failed);
		cout << endl;

		//Displaying the overall summary
		summary(successful, delayed, failed, battery);
	}
	else{
		cout<<"You haven't started the delivery program. The program will now exit.";
		cout<<"____________________________________________________________________\n";
	return 0;
}








