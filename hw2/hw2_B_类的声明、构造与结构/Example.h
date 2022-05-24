#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
private:
	// (1)
	int data;	
	static int num_added;
	static int num_obj;
	int own_num;
public:
	Example(int data);
	void getData();
	~Example();
};
		
#endif