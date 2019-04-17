using namespace std;

class Student {
 public:
  Student(char firstName[10], char lastName[10], int id, float gpa);
  char* getFirst();
  char* getLast();
  int getId();
  float getGpa();
 private:
  char first[10];
  char last[10];
  int id;
  float gpa;
};
