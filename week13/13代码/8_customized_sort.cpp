#include <algorithm>
#include <vector>
using namespace std;
class People
{
public:
	int age, weight;
	bool operator<(const People &b) const
	{
		return age < b.age;
	}
};
int main() {
	vector<People> vec = {{18, 50}, {16, 40}};
	sort(vec.begin(), vec.end());
	return 0;
}

