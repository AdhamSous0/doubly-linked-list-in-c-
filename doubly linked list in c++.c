#include<iostream>
#include<stdio.h>
#include <string.h>
using namespace std;
class Node{
private:
	Node * prev; 
	char name[20]; 
	int ID; 
	double score; 
	Node * next;
public:
	//constructor
	Node(){prev=NULL; strcpy(name, ""); ID=-1; score=0; next=NULL;}
	//setters
	void setPrev(Node *p){prev=p;}
	void setName(char *n){strcpy (name,n);}
	void setID(int I){ID=I;}
	void setScore(double s){score=s;}
	void setNext(Node *n){next=n;}
	
	Node* getPrev(){return prev;}
	char * getName(){ return name;}
	int getID(){ return ID;}
	double getScore(){ return score;}
	Node* getNext(){ return next;}

};



class StudentDLL{// student double linked list
private:
	Node * First;
	Node * last;
public:
//constructor 
	StudentDLL(){
		First=new Node;
		last=new Node;

	First->setNext(last);
	last->setPrev(First);
	

}

// print students data in the list on screen each student on a separate line
void print(){

	Node *f;
	f=last->getPrev();
	
	while(f!=First){
		cout<<f->getName()<<endl;
		cout<<f->getID()<<endl;
		cout<<f->getScore()<<endl;
		f=f->getPrev();
	}}

//determine number of nodes (students)
int listSize(){
	if(First->getNext()==last){
		
		return 0;
	}
	int f=0;
	Node *m=First;
	while(m->getNext()!=last){
		f++;
		m=m->getNext();
	}
	return f-2;
}





void deleteNode(int k){
	if(k>listSize()){
		cout<<"the namber bigar in size";
		return;
	}
	k++;
	int m;
	Node *b=First;
	for(m=0;m<=k;m++){
		b=b->getNext();}


	if(b->getNext()==last){
		Node * f=b->getPrev();
		b->setNext(NULL);
		last->setPrev(b->getPrev());
		f->setNext(last);
		b->setPrev(NULL);
		delete b;
		return;
}
	if(b->getPrev()==First){

		Node * f=b->getNext();
		b->setNext(NULL);
		First->setNext(f);
		f->setPrev(First);
		b->setPrev(NULL);
		delete b;
		return;
	}
	b->getNext()->setPrev(b->getPrev());
	b->getPrev()->setNext(b->getNext());
	b->setNext(NULL);

	b->setPrev(NULL);
	delete b;
	return;

	
	}



// insert a new student at position n
void insertStudent(char n[20], int ID, double score, int h){
	Node*a=new Node;
	a->setName(n);
	a->setID(ID);
	a->setScore(score);

	if(First->getNext()==last && h==1){
		First->setNext(a);
		a->setPrev(First);
		last->setPrev(a);
		a->setNext(last);

	}
	
	int m;
	Node *b=First;
	if(h < listSize()){
	for(m=0;m<=h;m++){
		b=b->getNext();
	}
	Node *g=b->getPrev();
	
		g->setNext(a);
		a->setPrev(g);
		b->setPrev(a);
		a->setNext(b);
	}//n>=1

// find average of students scores
double average(){
	int i=0;
	Node*a=First->getNext();
	while(a->getNext()!= last){
		i+=a->getScore();
		a=a->getNext();
	}
	return i;

	}



//find maximum score
double maxScore( ){
	Node*b=First->getNext();
	int max=b->getScore();
	for(int i=0;i<+listSize();i++){
		if(max <= b->getScore()){
			max=b->getScore();
		}
		b=b->getNext();
	}
	return max;

}

//sort nodes in ascending order of score
void sort(){
	Node *a=First;
	Node*b=First;
	while(b->getNext()!=last){
		while(a->getNext() !=last){
			if(a->getScore() > a->getNext()->getScore()){



			}}}
}
//append elements of an array at end of DLL
void append(int A[], int size){}


};

void main(){
	
	StudentDLL  L;
	cout<<L.listSize();
	L.insertStudent("ali", 2222, 70, 1);
	L.insertStudent("ahmad", 4444, 80,1);
	L.insertStudent("jamal", 8888, 90,2);
	L.print();
	L.sort();
	L.print();
	cout<<L.maxScore();
	cout<<L.average();
	cout<<L.listSize();
	L.deleteNode(1);
	L.print(); 
	L.deleteNode(2);
	L.print(); 
}//main
