using namespace std;

class Student {
 public:
  Student(char* firstName, char* lastName, int id, float gpa);
  char* getFirst();
  char* getLast();
  int getId();
  float getGpa();
 private:
  char* first;
  char* last;
  int id;
  float gpa;
};
