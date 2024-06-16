#include<iostream>
#include<fstream>
#include<string>

#define SIZE 7
using std::string;
using std::fstream;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;

class DietPlan
{
private:
	int goalCalories;
	string planName;
	string date;
	

public:
	//constructor
	DietPlan();
	DietPlan(int newGoalCalories, string newPlanName, string newDate);
	//copy constructor
	DietPlan(DietPlan& copy);
	//destructor
	~DietPlan();

	//setter
	void setGoalCalories(int newGoal);
	void setPlanName(string newName);
	void setDate(string newDate);
	//getter
	int getGoalCalories();
	string getPlanName();
	string getDate();

	//edit goal
	void editGoal();
};


class ExercisePlan
{
private:
	int goalStep;
	string planName;
	string date;
	//the next available position
public:
	//constructor
	ExercisePlan();
	ExercisePlan(int newGoalStep, string newPlanName, string newDate);
	//copy constructor
	ExercisePlan(ExercisePlan& copy);
	//destructor
	~ExercisePlan();

	//setter
	void setGoalStep(int newGoal);
	void setPlanName(string newName);
	void setDate(string newDate);
	//getter
	int getGoalStep();
	string getPlanName();
	string getDate();

	//edit goal
	void editGoal();

};
//non-member function
//The overloaded stream insertion (<<) for displaying a plan to the screen
ostream& operator<<(ostream& lhs, DietPlan& rhs);
ostream& operator<<(ostream& lhs, ExercisePlan& rhs);

//The overloaded stream insertion (<<) for writing a plan to a file,
fstream& operator<<(fstream& lhs, DietPlan& rhs);
fstream& operator<<(fstream& lhs, ExercisePlan& rhs);

//the extraction (>>) operator for reading a plan from a file. 
fstream& operator >> (fstream& lhs, DietPlan& rhs);
fstream& operator >> (fstream& lhs, ExercisePlan& rhs);

class FitnessAppWrapper
{
private:
	//two List of weekly plans .  Diet/Exercise
	DietPlan dp[7];
	ExercisePlan ep[7];

	//two fstream object
	fstream input;
	fstream output;

public:

	friend fstream& operator<<(fstream& lhs, DietPlan& rhs);
	friend fstream& operator<<(fstream& lhs, ExercisePlan& rhs);

	void runApp(void); // starts the main application.

	//This function reads one record from the given stream. 
	void loadDailyPlan(fstream& filestream, DietPlan& plan);
	void loadDailyPlan(fstream& filestream, ExercisePlan& plan);

	//This function must read in all seven daily plans from the given stream
	void loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);

	//writes a daily plan to the screen.
	void displayDailyPlan(DietPlan& rhs);
	void displayDailyPlan(ExercisePlan& rhs);

	//writes a weekly plan to a file.
	void displayWeeklyPlan(DietPlan dp[], int size);
	void displayWeeklyPlan(ExercisePlan ep[], int size);

	//writes a daily plan to a file.
	void storeDailyPlan(fstream& filestream, DietPlan& plan);
	void storeDailyPlan(fstream& filestream, ExercisePlan& plan);

	//writes a weekly plan to a file.
	void storeWeeklyPlan(fstream& filestream, DietPlan weeklyPlan[]);
	void storeWeeklyPlan(fstream& filestream, ExercisePlan weeklyPlan[]);

	void displayMenu(void);
	//1.    Load weekly diet plan from file.
	//2.    Load weekly exercise plan from file.
	//3.    Store weekly diet plan to file.
	//4.    Store weekly exercise plan to file.
	//5.    Display weekly diet plan to screen.
	//6.    Display weekly exercise plan to screen.
	//7.    Edit daily diet plan.
	//8.    Edit daily exercise plan.
	//9.    Exit.   // Note: this must write the most recent weekly plans to the corresponding files.

};
