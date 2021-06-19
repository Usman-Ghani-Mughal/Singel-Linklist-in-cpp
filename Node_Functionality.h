#include <iostream>
#include "Node.h"

struct NodeImplementation
{
private:
	Node *START;
	int SIZE;
public:
	NodeImplementation();
	void create_list(int);
	void add_at_beg(int);
	void add_at_pos(int,int);
	void del(int);
	void display();
	int count();
	void rev();
	bool search(int);
};