#include "Fitness.h"

//non member function
//The overloaded stream insertion (<<) for displaying a plan to the screen
ostream& operator<<(ostream& lhs, DietPlan& rhs)
{
	lhs << "Plan name : " << rhs.getPlanName() << endl;
	lhs << "Goal Calories : " << rhs.getGoalCalories() << endl;
	lhs << "Date : " << rhs.getDate() << endl;
	return lhs;
}
ostream& operator<<(ostream& lhs, ExercisePlan& rhs)
{
	lhs << "Plan name : " << rhs.getPlanName() << endl;
	lhs << "Goal Steps : " << rhs.getGoalStep() << endl;
	lhs << "Date : " << rhs.getDate() << endl;
	lhs << endl;
	return lhs;
}

//The overloaded stream insertion (<<) for writing a plan to a file,
fstream& operator<<(fstream& lhs, DietPlan& rhs)
{

	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getGoalCalories() << endl;
	lhs << rhs.getDate() << endl;
	lhs << endl;
	return lhs;
}
fstream& operator<<(fstream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getPlanName() << endl;
	lhs << rhs.getGoalStep() << endl;
	lhs << rhs.getDate() << endl;
	lhs << endl;

	return lhs;
}

//the extraction (>>) operator for reading a plan from a file. 
fstream& operator >> (fstream& lhs, DietPlan& rhs)
{
	int goalCalories = 0;
	string planName = "";
	string date = "";

	lhs >> planName;
	lhs >> goalCalories;
	lhs >> date;

	rhs.setPlanName(planName);
	rhs.setGoalCalories(goalCalories);
	rhs.setDate(date);

	return lhs;
}
fstream& operator >> (fstream& lhs, ExercisePlan& rhs)
{
	int goalStep = 0;
	string planName = "";
	string date = "";

	lhs >> planName;
	lhs >> goalStep;
	lhs >> date;

	rhs.setPlanName(planName);
	rhs.setGoalStep(goalStep);
	rhs.setDate(date);

	return lhs;
}

void FitnessAppWrapper::runApp(void)
{
	int selectMenu = 0, flag_work = 0;

	do
	{
		displayMenu();
		cout << "Selet Menu : ";
		cin >> selectMenu;
		system("cls");
		switch (selectMenu)
		{
		case 1:		//1.Load weekly diet plan from file.
			input.open("Dietplan.txt");
			if (input.is_open())
			{
				flag_work = 1;
				loadWeeklyPlan(input, dp);
				cout << "Diet Plan was loaded successfully!" << endl << endl;
			}
			else
			{
				cout << "Can not open Diet Plan file...." << endl << endl;
			}
			input.close();
			break;

		case 2:		//2.Load weekly exercise plan from file.
			input.open("Excersizeplan.txt");
			if (input.is_open())
			{
				flag_work = 1;
				loadWeeklyPlan(input, ep);
				cout << "Exercise Plan was loaded successfully!" << endl << endl;
			}
			else
			{
				cout << "Can not open Exercise Plan file...." << endl << endl;
			}
			input.close();
			break;

		case 3:		//3.Store weekly diet plan to file.
			output.open("Dietplan.txt");
			storeWeeklyPlan(output, dp);
			output.close();
			break;

		case 4:		//4.Store weekly exercise plan to file.
			output.open("Excersizeplan.txt");
			storeWeeklyPlan(output, ep);
			output.close();
			break;

		case 5:		//5.Display weekly diet plan to screen.
			displayWeeklyPlan(dp, SIZE);
			break;
		case 6:		//6.Display weekly exercise plan to screen.
			displayWeeklyPlan(ep, SIZE);
			break;
		case 7:		//7.Edit daily diet plan.
			for (int i = 0; i < SIZE; ++i)
			{
				displayDailyPlan(dp[i]);
				dp[i].editGoal();
				displayDailyPlan(dp[i]);
				system("pause");
				system("cls");
			}
			break;
		case 8:		//8.Edit daily exercise plan.
			for (int i = 0; i < SIZE; ++i)
			{
				displayDailyPlan(ep[i]);
				ep[i].editGoal();
				displayDailyPlan(ep[i]);
				system("pause");
				system("cls");
			}
			break;
		case 9:		//9.Exit.   
					// Note: this must write the most recent weekly plans to the corresponding files.
			if (flag_work == 1)
			{// in the case that any file was open.
				output.open("Dietplan.txt");
				storeWeeklyPlan(output, dp);
				output.close();
				output.open("Excersizeplan.txt");
				storeWeeklyPlan(output, ep);
				output.close();
			}
			break;
		default:
			break;
		}
	} while ((selectMenu > 0) && (selectMenu < 9));
}
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, DietPlan& plan)
{
	fileStream >> plan;
}
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, ExercisePlan& plan)
{
	fileStream >> plan;
}
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[])
{
	for (int i = 0; i < SIZE; ++i)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < SIZE; ++i)
	{
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}
void FitnessAppWrapper::displayDailyPlan(DietPlan& rhs)
{
	cout << rhs << endl;
}
void FitnessAppWrapper::displayDailyPlan(ExercisePlan& rhs)
{
	cout << rhs << endl;
}
void FitnessAppWrapper::displayWeeklyPlan(DietPlan dp[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		displayDailyPlan(dp[i]);
	}
}
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan ep[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		displayDailyPlan(ep[i]);
	}
}
void FitnessAppWrapper::storeDailyPlan(fstream& filestream, DietPlan& plan)
{
	filestream << plan;
}
void FitnessAppWrapper::storeDailyPlan(fstream& filestream, ExercisePlan& plan)
{
	filestream << plan;
}
void FitnessAppWrapper::storeWeeklyPlan(fstream& filestream, DietPlan weeklyPlan[])
{
	for (int i = 0; i < SIZE; ++i)
	{
		storeDailyPlan(filestream, weeklyPlan[i]);
	}
}
void FitnessAppWrapper::storeWeeklyPlan(fstream& filestream, ExercisePlan weeklyPlan[])
{
	for (int i = 0; i < SIZE; ++i)
	{
		storeDailyPlan(filestream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayMenu(void)
{
	cout << "*** < MENU > ***************************" << endl;
	cout << "1. Load weekly diet plan from file" << endl;
	cout << "2. Load weekly exercise plan from file" << endl;
	cout << "3. Store weekly diet plan to file" << endl;
	cout << "4. Store weekly exercise plan to file" << endl;
	cout << "5. Display weekly diet plan to screen" << endl;
	cout << "6. Display weekly exercise plan to screen" << endl;
	cout << "7. Edit daily diet plan" << endl;
	cout << "8. Edit daily exercise plan" << endl;
	cout << "9. Exit" << endl;
	cout << "****************************************" << endl;
}
