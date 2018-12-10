#include  "Node.h"
#include "Student.h"

using namespace std;

int main () {
  Student* student1 = new Student();
  newStudent->setName("Joe");
  newStudent->setId(351013);
  newStudent->setGpa(4.00);
  Student* student2 = new Student();
  student2->setName("Bob");
  student2->setid(39549);
  student3->setGpa(1.00);
  
  Node node1 = new Node(student1);
  Node node2  = new Node(student2);
  node1.setNext(node2);
  cout << "Student of Node 1:" << endl;
  cout << node1.getValue()->getName() << " ";
  cout << node1.getValue()->getId() << " ";
}

