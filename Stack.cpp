#include <iostream>
using namespace std;

// create a class for grocery
class Grocery{
	public:
		int id;
		string name;
		string catagory;
		int price;
		string exp;
};


class Stack{
	public:
		Grocery data;
		Stack* next;

		Stack* top = NULL;

	//push method
	void push(Grocery g){
		Stack* st = new Stack();

		st->data = g;

		if(top == NULL){
			top = st;
			return;
		}

		st->next = top;
		top = st;
		return;
	}

	//pop method
	void pop(){
		if(top == NULL){
			cout << "Stack is Empty" << endl;
			return;
	    }
		cout << "Pop: " << top->data.name << endl;
		top = top->next;
	}

	bool isEmpty(){
		if(top == NULL){
			return true;
		}
		return false;
	}

	void print(){
		Stack* itr = top;

		while(itr != NULL){
			cout << itr->data.name << endl;
			itr = itr->next;
		}
	}
};


// create linked list
class Node{
	public:
		Grocery data;
		Node* next;

		Stack st;

		// constructor that takes gorcery data
		Node(Grocery data){
			this->data = data;
			this->next = NULL;
		}
};

// insert into the list
// i take reference &head coz i want to change in original list
void insert(Grocery g, Node* &head){
	Node* node = new Node(g);
	node->st.push(g);
	if(head == NULL){
		head = node;
		return;
	}
	Node* itr = head;
	bool found = false;
	while(itr->next != NULL){
		if(itr->data.catagory == g.catagory && itr->data.exp == g.exp){
		    itr->st.push(g);
		    found = true;
		    break;
	    }
	    itr = itr->next;
	}
	if(!found){
		if(itr->data.catagory == g.catagory && itr->data.exp == g.exp){
			itr->st.push(g);
		}
		else{
		   itr->next = node;
	    }
    }
}


//make the whole list NULL
void makeNull(Node* &head){
	head = NULL;
}

void deleteS(Node* &head, string s){
	Node* itr = head;

	while(itr != NULL){
		if(itr->data.catagory == s){
			itr->st.pop();
			break;
		}
		itr = itr->next;
   }
}

//delete method
void deleteFromList(Node* &head, string nm){
	Node* itr = head;
	Node* prev = NULL;
	if(head->data.catagory == nm){
		head = head->next;
	}
	else{
		while(itr != NULL){
			if(itr->data.catagory == nm){
				prev->next = itr->next;
			}
			prev = itr;
			itr = itr->next;
		}
    }
}

bool isEmptyQ(Node* head, string nm){
	Node* itr = head;
	while(itr != NULL){
		if(itr->data.catagory == nm){
			if(itr->st.isEmpty() == true){
				return true;
			}
			else{
				return false;
			}
	    }
		itr = itr->next;
	}
	return false;
}


void insertInst(Node* &head){
		Grocery myGrocery;
		cout << "Type Id: ";
		cin >> myGrocery.id;
		cout << "Type name: ";
		cin >> myGrocery.name;
		cout << "Type catagory: ";
		cin >> myGrocery.catagory;
		cout << "Type price: ";
		cin >> myGrocery.price;
		cout << "Type exp: ";
		cin >> myGrocery.exp;

		insert(myGrocery, head);
	    cout << "\n";
}

//print method
void print(Node* &head){
	Node* itr = head;

	while(itr != NULL){

		cout << "Id: " << itr->data.id << endl;
		cout << "Name: "<< itr->data.name << endl;
		cout << "Catagory: "<< itr->data.catagory << endl;
		cout << "Price: "<< itr->data.price << endl;
		cout << "Exp: "<< itr->data.exp << endl;
		cout << '\n';
		cout << "Stack Items: " << endl;
		itr->st.print();
		cout << '\n';
		itr = itr->next;
	}
}



int main(){

	//head initially points to NULL
	Node* head = NULL;

	Stack st;

	 cout << "Choose an option..." << endl;
	 cout << '\n';
	 cout << " 1 : Push" << endl;
	 cout << '\n';
     cout << " 2 : Pop" << endl;
     cout << '\n';
     cout << " 3 : Print List" << endl;
     cout << '\n';
     cout << " 0 : exit" << endl;
     cout << '\n';
    int x;
    while(true){
    	 cin >> x;
	    switch (x) {
	    case 1:
	        cout << "Insert items " << endl;
	        insertInst(head);
	        break;
	    case 2:{
	    	string s;
	    	cout << "Type which catagory you want to pop" << endl;
	    	cin >> s;
	        if(isEmptyQ(head, s)){
	        	cout << "The list is Empty so delete the node " << endl;
	        	deleteFromList(head, s);
			}
			else{
				deleteS(head, s);
			}
	        break;
	    }
	    case 3:{
	        cout << "Printing the items in List " << endl;
	        print(head);
	        break;
	    }
	    default:
	        exit(false);
	        break;
}
}
}

