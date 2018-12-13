#include  "Node.h"
#include "Student.h"

using namespace std;

int main () {
  Student* student1 = new Student();
  student1->setName("Joe");
  student1->setId(351013);
  student1->setGpa(4.00);
  Student* student2 = new Student();
  student2->setName("Bob");
  student2->setId(39549);
  student2->setGpa(1.00);
  
  Node* node1 = new Node(student1);
  node1->setNext(new Node(student2));
  cout << "Student of Node 1:" << endl;
  cout << node1->getValue()->getName() << " ";
  cout << node1->getValue()->getId() << endl;
  cout << "Student of Node 2:" << endl;
  cout << node1->getNext()->getValue()->getName() << " ";
  cout << node1->getNext()->getValue()->getId() << " ";
}

