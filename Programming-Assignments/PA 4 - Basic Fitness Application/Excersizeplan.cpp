#include "Fitness.h"

ExercisePlan::ExercisePlan()
{
	this->goalStep = 0;
	this->planName = "";
	this->date = "";
}
ExercisePlan::ExercisePlan(int newGoalStep, string newPlanName, string newDate)
{
	goalStep = newGoalStep;
	planName = newPlanName;
	date = newDate;
}
ExercisePlan::ExercisePlan(ExercisePlan& copy)
{
	setGoalStep(copy.getGoalStep());
	setPlanName(copy.getPlanName());
	setDate(copy.getDate());
}
ExercisePlan::~ExercisePlan()
{
	cout << "Inside destructor for ExercisePlan" << endl;
}
void ExercisePlan::setGoalStep(int newGoal)
{
	goalStep = newGoal;
}
void ExercisePlan::setPlanName(string newName)
{
	planName = newName;
}
void ExercisePlan::setDate(string newDate)
{
	date = newDate;
}
string ExercisePlan::getPlanName()
{
	return planName;
}
string ExercisePlan::getDate()
{
	return date;
}
int ExercisePlan::getGoalStep()
{
	return goalStep;
}
void ExercisePlan::editGoal()
{
	int newGoal = 0;
	cout << "edit Goal steps : " << getGoalStep() << "->";
	cin >> newGoal;
	setGoalStep(newGoal);
	cout << endl;
}
