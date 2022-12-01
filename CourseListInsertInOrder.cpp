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
        if (newNode->getCourse().getCourseNumber() <= current->getCourse().getCourseNumber()) {
            // inserting as first
            if (current == first) {
                first = newNode;
                first->setNext(current);
            } else {
                newNode->setNext(current);
                previous->setNext(newNode);
            }
            isInserted = !isInserted;
        } else {
            previous = current;
            current = current->getNext();
        }

    }
    if (!isInserted) {
        // handling for empty list
        if (count == 0) {
            first = last = newNode;
        } else {
            last->setNext(newNode);
            last = last->getNext();
        }

    }
    count++;
}