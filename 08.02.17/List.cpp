#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node{
	int data;
	Node *next;
};

class List{
private:
	Node *head;
	int size = 0;
public:
	List(int data){
		head = new Node;
		head->data = data;
		head->next = NULL;
		size++;
	}

	~List(){
		while (head != NULL){
			Node *tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	bool operator == (const List &list2) {
		if (this->size != list2.size)
			return false;
	}

	int operator[] (int n) {
		return head->data * n;
	}

	void pushBack(int data){
		Node *tmp = new Node;
		tmp->data = data;
		tmp->next = NULL;
		Node *index = head;
		while (index->next != NULL){
			index = index->next;
		}
		index->next = tmp;
		size++;
	}

	void pushHead(int data){
		Node *tmp = new Node;
		tmp->data = head->data;
		tmp->next = head->next;
		head->data = data;
		head->next = tmp;
		size++;
	}

	void pushAfterData(int afterData, int data){
		Node *index = head;
		while (index != NULL && index->data != afterData)
			index = index->next;
		Node *tmp = new Node;
		tmp->data = data;
		tmp->next = index->next;
		index->next = tmp;
		size++;
	}

	int delFromEnd(){
		Node *index = head;
		while (index->next->next != NULL)
			index = index->next;
		int a = index->next->data;
		Node *tmp = index->next;
		delete tmp;
		index->next = NULL;
		size--;
		return a;
	}

	int delFromBegin(){
		Node *index = head;
		head = index->next;
		size--;
		int a = index->data;
		delete index;
		return a;
	}

	int getElementByKey(int key){
		Node *index = head;
		if (key > size)
			return NULL;
		for (int i = 0; i < key; i++)
		{
			index = index->next;
		}
		return index->data;
	}

	int getElementBydata(int data){
		Node *index = head;
		while (index->next != NULL && index->data != data){
			index = index->next;
		}
		if (index->data == data)
			return index->data;
		return NULL;

	}

	int delByData(int data){
		if (head->data == data){
			return delFromBegin();
		}
		Node *index = head;
		while (index->next->data != data && index->next->next != NULL){
			index = index->next;
		}
		if (index->next->data == data)
		{
			int a = index->next->data;
			Node *tmp = index->next;
			index->next = index->next->next;
			delete tmp;
			size--;
			return a;
		}
		return NULL;
	}

	int delByIndex(int index){
		if (index > size)
			return NULL;
		if (index == 0)
			return delFromBegin();
		Node *tmp = head;
		for (int i = 1; i < index; i++)
			tmp = tmp->next;
		int a = tmp->next->data;
		Node *toDel = tmp->next;
		tmp->next = tmp->next->next;
		delete toDel;
		return a;
	}

	void setElementByKey(int key, int data){
		Node *index = head;
		if (key > size)
			return;
		for (int i = 1; i < key; i++)
		{
			index = index->next;
		}
		index->data = data;
	}

	void printAll(){
		Node *index = head;
		cout << "\n";
		while (index != NULL){
			cout << index->data << "\n";
			index = index->next;
		}
	}
};
int main(){
	List *list = new List(10);

	list->pushBack(100);
	list->pushHead(400);
	list->printAll();

	cout <<"DELETED:" << list->delFromEnd();
	list->printAll();
}
