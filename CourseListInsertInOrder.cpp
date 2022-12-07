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
void CourseList::insertInOrder(Node* node) {
    Node* current = first;
    Node* previous = nullptr;
    bool isInserted = false;
    int courseNumber = node->getCourse().getCourseNumber();

    // Finding the node that has larger course numbers
    while (current != nullptr && !isInserted) {
        if (courseNumber <= current->getCourse().getCourseNumber()) {
            // inserting as first
            if (current == first) {
                first = node;
                first->setNext(current);
            } else {
                node->setNext(current);
                previous->setNext(node);
            }
            isInserted = true;
        } else {
            previous = current;
            current = current->getNext();
        }
    }

    if (!isInserted) {
        // handling for empty list
        if (count == 0) {
            first = last = node;
        } else {
            // Inserting as the last node
            last->setNext(node);
            last = last->getNext();
        }
    }

    ++count;
}