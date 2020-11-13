#include <iostream>

#include "developer.h"
#include "task.h"
#include "set.h"

int main()
{
    Set<Developer *> developers;

    developers.add(new Developer("Dev 1", "Web", 80, "Senior"));
    developers.add(new Developer("Dev 2", "Backend", 80, "Senior"));
    developers.add(new Developer("Dev 3", "Mobile", 80, "Senior"));
    developers.add(new Developer("Dev 4", "Backend", 80, "Junior"));
    developers.add(new Developer("Dev 5", "Web", 80, "Middle"));

    Set<Task> tasks;

    tasks.add(Task("Task 1", "Web", 10, 3));
    tasks.add(Task("Task 2", "Web", 20, 2));
    tasks.add(Task("Task 3", "Web", 30, 1));
    tasks.add(Task("Task 4", "Backend", 10, 2));
    tasks.add(Task("Task 5", "Backend", 20, 1));
    tasks.add(Task("Task 6", "Backend", 30, 3));
    tasks.add(Task("Task 7", "Mobile", 10, 1));
    tasks.add(Task("Task 8", "Mobile", 20, 2));
    tasks.add(Task("Task 9", "Backend", 20, 2));
    tasks.add(Task("Task 10", "Backend", 20, 3));

    Set<Task> unassignedTasks;

    // Task distribution
    Set<Task>::Iterator it = tasks.begin();
    Set<Developer *>::Iterator devIt = developers.begin();
    Developer *lastDeveloper = nullptr;

    while (it.hasNext())
    {
        Task currentTask = it.next();

        while (devIt.hasNext())
        {
            Developer *currentDeveloper = devIt.next();

            // If last developer then start from beginning
            if (!devIt.hasNext())
            {
                devIt = developers.begin();
            }

            // Same developer reached again
            if (currentDeveloper == lastDeveloper)
            {
                unassignedTasks.add(currentTask);

                break;
            }

            // Trying to add task
            if (currentDeveloper->addTask(currentTask))
            {
                lastDeveloper = currentDeveloper;

                break;
            }
        }
    }

    // Printing developers with their tasks
    devIt = developers.begin();
    while (devIt.hasNext())
    {
        (*(devIt.next())).print();
    }

    // Printing unassigned tasks
    std::cout << "Unassigned tasks: " << std::endl;
    
    unassignedTasks.print();

    return 0;
}