#include "Fitness.h"

DietPlan::DietPlan()
{
	this->goalCalories = 0;
	this->planName = "";
	this->date = "";
}
DietPlan::DietPlan(int newGoalCalories, string newPlanName, string newDate)
{
	goalCalories = newGoalCalories;
	planName = newPlanName;
	date = newDate;
}
DietPlan::DietPlan(DietPlan& copy)
{
	setGoalCalories(copy.getGoalCalories());
	setPlanName(copy.getPlanName());
	setDate(copy.getDate());
}
DietPlan::~DietPlan()
{
	cout << "Inside destructor for DietPlan" << endl;
}
void DietPlan::setGoalCalories(int newGoal)
{
	goalCalories = newGoal;
}
void DietPlan::setPlanName(string newName)
{
	planName = newName;
}
void DietPlan::setDate(string newDate)
{
	date = newDate;
}
string DietPlan::getPlanName()
{
	return planName;
}
string DietPlan::getDate()
{
	return date;
}
int DietPlan::getGoalCalories()
{
	return goalCalories;
}
void DietPlan::editGoal()
{
	int newGoal = 0;
	cout << "edit Goal Calories : " << getGoalCalories() << "->";
	cin >> newGoal;
	setGoalCalories(newGoal);
	cout << endl;
}
