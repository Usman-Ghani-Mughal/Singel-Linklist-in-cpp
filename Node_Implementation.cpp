#include <iostream>
#include "Node_Functionality.h"
using namespace std;

NodeImplementation::NodeImplementation()
	{
		this->SIZE=0;
		this->START=NULL;
	}
void NodeImplementation::create_list(int d)
{
	Node *move;
	if(this->START==NULL)
	{
		//Node *temps=new Node();
		//this->START=temps;
		Node *temp=new Node();
		temp->DATA=d;
		temp->NEXT=NULL;
		this->START=temp;
		this->SIZE++;
	}
	else
	{
		Node *temp=new Node();
		temp->DATA=d;
		temp->NEXT=NULL;
		move=this->START;
		while(move->NEXT!=NULL)
		{
			move=move->NEXT;
		}
		move->NEXT=temp;
		this->SIZE++;
	}
}
void NodeImplementation::add_at_beg(int d)
{
	Node *temp=new Node();
	temp->DATA=d;
	temp->NEXT=this->START;
	this->START=temp;
	this->SIZE++;
}
void NodeImplementation::add_at_pos(int pos,int d)
{
	if(pos==1)
	{
		this->add_at_beg(d);
	}
	else if(pos==this->SIZE+1)
	{
		this->create_list(d);
	}
	else if(pos>1&&pos<=this->SIZE)
	{
		Node *move=this->START;
		for(int i=1;i<pos-1;i++)
		{
			move=move->NEXT;
		}
		Node *temp=new Node();
		temp->DATA=d;
		temp->NEXT=move->NEXT;
		move->NEXT=temp;
		this->SIZE++;
	}
	else
	{
		cout<<"Sorry!!! you gave wrong position"<<endl;
	}
}
void NodeImplementation::del(int d)
{
	if(this->START==NULL)
	{
		cout<<"Sorry list is empty"<<endl;
	}
	else
	{
		Node *move=this->START;
		while(move!=NULL)
		{
			if(move->DATA==d)
			{
				Node *temp=move;
				move=move->NEXT;
				delete temp;
				this->SIZE--;
				return;
			}
			move=move->NEXT;
		}
		cout<<"Data has not been found"<<endl;
	}
}
void NodeImplementation::display()
{
	Node *move=this->START;
	if(this->START==NULL)
	{
		cout<<"List is Empty!!!!!!!"<<endl;
	}
	else
	{
		while(move!=NULL)
	     {
		   cout<<move->DATA<<" ";
		   move=move->NEXT;
	     }
	}
	
}
int NodeImplementation::count()
{
	return this->SIZE;
} 
void NodeImplementation::rev()
{
	if(this->SIZE>1)
	{
		if(this->SIZE>1)
		{
			Node *pos1,*pos2,*pos3;
			pos1=this->START;
			pos2=pos1->NEXT;
			pos3=pos2->NEXT;
			pos1->NEXT=NULL;
			pos2->NEXT=pos1;
			while(pos3!=NULL)
			{
				pos1=pos2;
				pos2=pos3;
				pos3=pos3->NEXT;
				pos2->NEXT=pos1;
			}
			this->START=pos2;
		}
	}
	else
	{
		cout<<"Sorry!!! Reversing is not posible"<<endl;
	}
	
}
bool NodeImplementation::search(int d)
{
	Node *move=this->START;
		while(move!=NULL)
		{
			if(move->DATA==d)
			{
				return true;
			}
			move=move->NEXT;
		}
		return false;
}