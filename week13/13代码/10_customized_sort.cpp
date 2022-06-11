#include <algorithm>
#include <vector>
using namespace std;
class People
{  public:	int age, weight;  };

class AgeComp {
public:
	bool operator()(const People &a, const People &b) const 
		{ 	return a.age < b.age; 	}
};

int main() {
	vector<People> vec = {{18, 50}, {16, 40}};
	sort(vec.begin(), vec.end(), AgeComp());
	return 0;
}

