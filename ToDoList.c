/*
Features:
* Add Task
    * Show all tasks
    * Change Status

*/

#include <stdio.h>
#include <string.h>

#define MAX_LIST_SIZE 10
#define MAX_CHAR_LENGTH 20

typedef enum{
	Not_Started,
	Processing,
	Finished
}Status;

typedef struct{
    int priority;   	//initializion inside the struct is not allowed
    Status taskStatus;
    char taskName[MAX_CHAR_LENGTH];
}task;

int input = 0;
task taskList[MAX_LIST_SIZE];
static int taskCount;
int Prio;
Status tStatus;
char taskInfo[MAX_CHAR_LENGTH];

void AddNewTask(char *new, int Prio);
void ShowAllTasks();
void ChangeStatus(char *Changetask, Status tStatus);

int main(void)
{ 
    do
    {
		printf("\n---- A Simple Todo Console App ----\n\n");
        printf("\n Menu ");
        printf("\n 1. Add Task.");
        printf("\n 2. Show All Tasks.");
        printf("\n 3. Change the Status of the Task.");
        printf("\n 0. Exit.");
    
        printf("\n Please select an option : ");        
        scanf("%d", &input);

	switch(input)
		{
		case 1:
		if(taskCount < MAX_LIST_SIZE)
		{
			printf("\n Please enter the new task:\n");
			scanf("%s", taskInfo);
			printf("\n Please enter the priority:\n");
			scanf("%d",&Prio);
			AddNewTask(taskInfo, Prio);
		}
		else
		{
			printf("\n Maximum Task numbers Exceeds");
		}
		break;
		
		case 0:
            printf("\n Goodbye!\n");
            break;
  
		case 2:
		if(!taskCount)
		{
			printf("\nNo Tasks to Display..!\n");
		}
		else
		{
			ShowAllTasks();
		}
		break;
  
		case 3:
		if(!taskCount)
		{
			printf("\nNo Tasks to Change the Status..!\n");
		}
		else
		{
			printf("\n Please enter the status change task:\n");
			scanf("%s", taskInfo);
			printf("\n0:Not Started;\t1:Processing\t2:Finished\n");
			printf("\n Please enter the new Status:\n");
			scanf("%d",(int*)&tStatus);
			ChangeStatus(taskInfo,tStatus);
		}
		break;
  
        default:
            printf("\n Please enter a valid option!!");
            break;
		}
	}
    while(input !=0);    
    return  0;
}

void AddNewTask(char *taskInfo, int Prio)
{
	strcpy(taskList[taskCount].taskName, taskInfo);
	taskList[taskCount].priority = Prio;
	taskList[taskCount].taskStatus = Not_Started;
	printf("The entered new task is : %s\n", taskList[taskCount].taskName);
	printf("Task's priority is : %d\n", taskList[taskCount].priority);
	printf("Task's Status is : %d\n", taskList[taskCount].taskStatus);
	taskCount++;
}

void ShowAllTasks()
{
	printf("TaskName\tPriority\tTaskstatus\n\n");
	for ( int i = 0; i < taskCount; i++)
	{
		printf("%s\t\t%d\t\t%d\n", taskList[i].taskName, taskList[i].priority, taskList[i].taskStatus);
	}
}

void ChangeStatus(char *Changetask, Status tStatus)
{
	int i; 
	_Bool taskFound = 0;
	for (i = 0; i < taskCount; i++)
		{
			if(!strcmp(taskList[i].taskName,Changetask))
				{
					taskList[i].taskStatus = tStatus;
					taskFound = 1;
					break;
				}
		}
	if(taskFound == 1)
	{
		printf("The status changed task is : %s\n", taskList[i].taskName);
		printf("Task's Status is : %d\n", taskList[i].taskStatus);
	}
	else
	{
		printf("\nPlease enter the valid Task..!\n\n");
		ShowAllTasks();
	}
}
