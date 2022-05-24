#include <iostream>
#include <string>
#include <regex>
using namespace std;

void extract(string input) {
	smatch sm;
	regex get_name(R"((My name is |I am )(\w+)\.)");
	regex get_date(R"((\d{4})[\.-](\d{1,2})[\.-](\d{1,2}))");
	regex get_mobile(R"([1-9]\d{10})");
	regex get_email(R"([\w]+@[\w\.]+)");
	if (std::regex_search(input, sm, get_name))
		cout << sm[2] << endl;
	int date[3] = {0};
	if (regex_search(input, sm, get_date)){
		for (int i = 1; i <= 3; i++)
			date[i - 1] = stoi(sm[i]);
		cout << date[0] << "." << date[1] << "." << date[2] <<endl;
	}
	if (regex_search(input, sm, get_mobile))
		cout << sm[0] << endl;
	if (regex_search(input, sm, get_email))
		cout << sm[0] << endl;
}

int main() {
    string str("I am zhangshuaishuai. \
		I was born on 2000.10.2. \
		My phone number is 18866667777 and you can also \
		reach me by my email: zhangss@tsinghua.edu.cn");
    extract(str);
    return 0;
}




