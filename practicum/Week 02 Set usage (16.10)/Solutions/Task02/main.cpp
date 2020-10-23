#include "list.h"
#include "set.h"
#include "task.h"

int main()
{
    List<Task> taskList;

    taskList.addFirst(Task("25.10_12:00_Work1"));
    taskList.addLast(Task("25.10_12:00_Work2"));
    taskList.addLast(Task("12.10_12:00_Work1"));
    taskList.addLast(Task("31.10_12:00_Work1"));

    taskList.print();

    taskList.toSet().print();

    // taskList.remove(Task("25.10_12:00_Work2"));

    // taskList.print();

    // Set<Task> taskSet;

    // taskSet.add(Task("25.10_12:00_Work1"));
    // taskSet.add(Task("25.10_12:00_Work2"));
    // taskSet.add(Task("12.10_12:00_Work1"));
    // taskSet.add(Task("31.10_12:00_Work1"));

    // taskSet.print();

    // taskSet.remove(Task("25.10_12:00_Work2"));

    // taskSet.print();

    return 0;
}