#include <iostream>
#include <vector>
using namespace std;

class VeryHeavyDatabase
{
private:
  vector<int> DB = {};

public:
  VeryHeavyDatabase()
  {
    for (int i = 0; i < 9; ++i)
    {
      this->DB.push_back(i + 1);
    }
  }

  void set(int index, int value)
  {
    this->DB[index] = value;
  }

  int get(int index)
  {
    return this->DB[index];
  }
};

class OneShotDB : private VeryHeavyDatabase
{
private:
  int count;
  int limit;

public:
  OneShotDB(size_t shorts = 1) : VeryHeavyDatabase()
  {
    this->limit = shorts;
    this->count = 0;
  }

  string GetData(int key)
  {
    if (this->count < this->limit)
    {
      char res = this->get(key) + 48;
      string result = "";
      result.push_back(res);

      this->count++;
      return result;
    }
    return "ERROR!";
  }
};

int main()
{
  VeryHeavyDatabase real_db = VeryHeavyDatabase();
  OneShotDB limit_db = OneShotDB(2);

  cout << limit_db.GetData(0) << endl;
  cout << limit_db.GetData(1) << endl;
  cout << limit_db.GetData(2) << endl;

  return 0;
}