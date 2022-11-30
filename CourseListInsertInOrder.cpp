/*
    Coffee Addicts

    Aung, Phyo Pyae Moe
    Hlaing, Yu Yu

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#include "CourseList.h"

// Definition function insertInOrder
// Assume there are no duplicates.
void CourseList::insertInOrder(Node* newNode) {
    Node* current = first;
    Node* previous = nullptr;
    bool isInserted = false;
    while (current != nullptr && !isInserted) {
        //
        if (newNode->getCourse().getCourseNumber() <= current->getCourse().getCourseNumber()) {
            newNode->setNext(current);
            previous->setNext(newNode);
        } else {
            previous = current;
            current = current->getNext();
        }
    }
    if (!isInserted) {
        last->setNext(newNode);
        last = last->getNext();
    }
    count++;
}