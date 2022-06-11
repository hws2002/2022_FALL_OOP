#include <algorithm>
#include <vector>
using namespace std;

class People
{  public: int age, weight;  };

bool compByAge(const People &a, const People &b)
	{	return a.age < b.age; }

int main() {
	vector<People> vec = {{18, 50}, {16, 40}};
	sort(vec.begin(), vec.end(), compByAge);
	return 0;
}

