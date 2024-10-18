#include <string>
#include "studentRoll.h"
#include <sstream>

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node* pointer = new Node();
  pointer->s = new Student(s);

  if (tail == nullptr) {
    head = pointer;
    tail = pointer;
  } else {
    tail->next = pointer;
    tail = pointer;
  }
  pointer->next = nullptr;
}

std::string StudentRoll::toString() const {
  std::ostringstream oss;
  oss << "[";  
  Node* current = head;
  
  while (current != nullptr) {
    if (current != head) {
      oss << ",";
    }

    oss << current->s->toString();
    current = current->next;
  }

  oss << "]";
  return oss.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = nullptr;

  Node* current = orig.head;

  while (current != nullptr) {
    insertAtTail(*(current->s));
    current = current->next;
  }
}

StudentRoll::~StudentRoll() {
  Node* current = head;
  while (current != nullptr) {
    Node* del = current;
    current = current->next;
    delete del->s; 
    delete del;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right) {
  if (&right == this) 
    return (*this);

  Node* current = head;
  while (current != nullptr) {
    Node* del = current;
    current = current->next;
    delete del->s; 
    delete del;
  }

  head = tail = nullptr;
  current = right.head;

  while (current != nullptr) {
    insertAtTail(*(current->s));
    current = current->next;
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
}





