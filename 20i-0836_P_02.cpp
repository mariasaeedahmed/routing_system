#include<iostream>
#include<fstream>
#include<string>
using namespace std;
bool spl = false;
template<class T>

class Splaying_treee
{
private:
protected:
public:
	string destination;
	T next_router;
	//T destination;
	Splaying_treee* left;
	Splaying_treee* right;
	Splaying_treee* parent;
	Splaying_treee* child;
	//template<class T>

	Splaying_treee<T>* N_Node(T des, T nr)
	{
		Splaying_treee<T>* NN_Node = new Splaying_treee<T>();
		NN_Node->destination = des;
		NN_Node->next_router = nr;
		NN_Node->left = NULL;
		NN_Node->right = NULL;
		return NN_Node;
	}
	//	template<class T>

	Splaying_treee<T>* Rotation_R_Zig(Splaying_treee<T>* R_val)//zig means Right
	{
		Splaying_treee<T>* R_val_left = R_val->left;
		//cout << R_val_left->destination << endl;;
		R_val->left = R_val_left->right;
		if (R_val->left == nullptr)
		{
			//continue;
		}

		else
			//cout << R_val->left->destination << endl;
			R_val_left->right = R_val;
		//cout << R_val_left->right << endl;
		//cout << R_val_left->destination << endl;
		return R_val_left;

	}
	//template<class T>

	Splaying_treee<T>* Rotation_L_Zag(Splaying_treee<T>* R_val)//zag means left
	{
		Splaying_treee<T>* R_val_right = R_val->right;
		R_val->right = R_val_right->left;
		R_val_right->left = R_val;
		return R_val_right;


	}
	//AVL and RB tree O(logn)
	//splay trees have better time complexity then these
	//Splay tree => Self-adjusted BST
	//same as AVL insertion deletion searching
	//
	//template<class T>

	Splaying_treee<T>* Splaying_tree(Splaying_treee<T>* T_rooot, string dest/*key*/)
	{
		//Jenn's lecture
		//search item => root node
		//  //    //  => child of root node
		// => left child or right child
		// => grand child or etc
		cout << dest << endl;
		if (T_rooot == nullptr)//afar root null
		{
			return T_rooot;
		}
		//if (T_rooot->destination == dest)//agar value pehlay hi 
			//root par ho
		//{
			//cout << T_rooot->destination << endl;
			//return T_rooot;
		//}
	//	cout << T_rooot->destination << endl;
		//error at this point
		//T_rooot->destination mai value sahi nahi ja rahiiii
		if (T_rooot->destination == dest)
		{

			return T_rooot;
		}




		else
		{
			if (T_rooot->destination > dest)//root ki value greatr than key
				//passed in func
			{
				//agar val left Sub tree ki taraf ho
				//like chances tu 
				if (T_rooot->left == nullptr)
				{
					//returning the root
					//coz root ka left null hai
					//nhi hai node
					return T_rooot;
				}
				//if next condition true to zig ki zig rotation will be performed
				//
				if (T_rooot->left->destination > dest)//grandchild left check ki val 
					//kay liay
				{
					//Revursion left-left...
					T_rooot->left->left = Splaying_tree(T_rooot->left->left, dest);
					////////
					//cout << T_rooot->left->Value_of_Node;
					T_rooot = Rotation_R_Zig(T_rooot);//zig rotating

				}
				else if (T_rooot->left->destination < dest)
				{
					T_rooot->left->right = Splaying_tree(T_rooot->left->right, dest);
					//if (T_rooot->left->right == nullptr)
					//{
						//T_rooot->left = Rotation_L_Zag(T_rooot->left);
					//}
					/*else*/ if (T_rooot->left->right)
					{
						T_rooot->left = Rotation_L_Zag(T_rooot->left);
					}

				}
				if (T_rooot->left == nullptr)
				{
					//cout << T_rooot->left->Value_of_Node << endl;
					return T_rooot;

				}
				else

				{
					//cout << T_rooot->left->destination << endl;
					return Rotation_R_Zig(T_rooot);
				}

			}
			else if (T_rooot->destination < dest) //
			{
				if (T_rooot->right == nullptr)
				{
					//isn't present
					//cout << T_rooot->right->Value_of_Node << endl;
					return T_rooot;
				}
				//right_left 
				if (T_rooot->right->destination > dest)
				{
					//right ka left
					//cout << T_rooot->right->destination << endl;
					T_rooot->right->left = Splaying_tree(T_rooot->right->left, dest);
					//if (T_rooot->right->left == nullptr)
					//{

					//}
					//else
					if (T_rooot->right->left != nullptr)
					{
						//cout << "here";
						//cout << T_rooot->right->left->destination << endl;
						T_rooot->right = Rotation_R_Zig(T_rooot->right);
						//T_roooot->rigth = Rotation_R_Zig(T_roooot->right);
					}
					if (T_rooot->right == nullptr)
					{
						return T_rooot;
					}
					else
					{
						return Rotation_L_Zag(T_rooot);
					}

				}
				else if (T_rooot->right->destination < dest)
				{
					//right ka right
					T_rooot->right->right = Splaying_tree(T_rooot->right->right, dest);
					//if (T_rooot->right->left == nullptr)
					//{

					//}
					//else if (T_rooot->right->left != nullptr)
					//{
						//cout << "here";
					T_rooot = Rotation_L_Zag(T_rooot);
					//T_roooot->rigth = Rotation_R_Zig(T_roooot->right);
				//}

					if (T_rooot->right == nullptr)
					{
						return T_rooot;
					}
					else
					{
						return Rotation_L_Zag(T_rooot);
					}
				}




			}
		}
	}
	//template<class T>

	Splaying_treee<T>* insertingNode(T dest, T next_router, Splaying_treee<T>* Rt)//rt is rrot// idhar we insert the routing table and woh wala keh kon kis keh sath hai 
	{
		if (Rt == nullptr)//khali 
		{
			return  N_Node(dest, next_router);
		}
		//so agar pehlay say value present hai in tree
		//tu usko spay kartay hain 
		//i.e root pai value lai aatay hai and then return kardein gae
		Rt = Splaying_tree(Rt, dest);//splaying: akhri node ko root agar given ho tree mai
		//agar value isn't in root tu leaf node ko splay karein gae
		if (Rt->destination == dest)
		{
			//agar root pai wohi value hai jo insert karni hai
			//after splayig
			return Rt;
		}
		//and if not tu aik newnode banaein gae
		//like memory
		Splaying_treee<T>* temp_N_node = N_Node(dest, next_router);//new node baba rahein hain
		if (Rt->destination > dest)
		{

			temp_N_node->right = Rt;
			temp_N_node->left = Rt->left;
			Rt->left = nullptr;

		}
		else //if (Rt->Value_of_Node > val)
		{
			//naye node kay left ko rrot ki value
			//kay right ko root ka right
			//root ka right null;
			temp_N_node->left = Rt;
			temp_N_node->right = Rt->right;
			Rt->right = nullptr;






		}
		return temp_N_node;

	}
	//void insertion(Node* rt,Node*N)
	//template<class T>

	void inorderTrav(Splaying_treee<T>* Rt)
	{
		if (Rt != nullptr)
		{
			//inorder
			//cout << Rt->destination;
			cout << endl;
			//Traversal_Display(Rt->left);
			//Traversal_Display(Rt->right);

		}
	}
	//template<typename T>
	void Traversal_Display(Splaying_treee<T>* T_root)
		//inorder mai kar rahay hain 
	{
		if (T_root != nullptr)
		{
			//inorder
			cout << T_root->destination;
			cout << "\t" << T_root->next_router;
			cout << endl;
			Traversal_Display(T_root->left);
			Traversal_Display(T_root->right);

		}
		//else if (T_root == nullptr)
	   // {

	   // }

	}

	//
	//for deletion of node using the concept of splaying the tree
	//sab say pehlay we have to splay the tree
	//agar key present hogi that will become root otherwise last 
	//node (leaf) will key ban jaye ga
	//
	//template<class T>

	Splaying_treee<T>* Deleting_Node(Splaying_treee<T>* R/*rooot hai*/, T val)
	{

		Splaying_treee<T>* N_Node_T;
		if (R == nullptr)//khali 
		{
			return NULL;// N_Node(val);
		}
		R = Splaying_tree(R, val);//splayyy
		//if val not present tu splay kay baad jo root hogi that 
		//will be returned
		if (val != R->destination)
		{
			return R;
		}
		//new root ka left null ho 
		//    example:  5->left =NULL
		//     root = root right
		if (R->left == NULL)
		{
			N_Node_T = R;
			R = R->right;
			delete N_Node_T;
		}
		else
		{
			//left child ko root banaen gae
			N_Node_T = R;
			R = Splaying_tree(R->left, val);
			//left child jo keh root ban chuka hoga
			//us kay right main old root ka right aa jaye ga
			//old root delete kardein gay
			R->right = N_Node_T->right;
			delete N_Node_T;
		}
		return R;

	}
};



class message {

	int messID;
	int priority;
	string sourceAdd;
	string destAdd;
	string trace;
	string payload;

public:

	message()
	{
		messID = 0;
		priority = -1;
		sourceAdd = "";
		destAdd = "";
		trace = "";
		payload = "";
	}

	//getters and setters
	void setPayLoad(string p)
	{
		payload = p;
	}

	string getPayLoad()const
	{
		return payload;
	}

	string getTrace()const
	{
		return trace;
	}

	void setDest(string d)
	{
		this->destAdd = d;
	}

	string getDest()const
	{
		return destAdd;
	}

	void setID(int id)
	{
		this->messID = id;
	}

	int getID()const
	{
		return messID;
	}

	void setPrio(int p)
	{
		this->priority = p;
	}

	int getPrio()const
	{
		return priority;
	}

	void setSource(string s)
	{
		this->sourceAdd = s;
	}

	string getSource()const
	{
		return this->sourceAdd;
	}

	void display()
	{
		cout << messID << " ";
		cout << priority << " ";
		cout << sourceAdd << " ";
		cout << destAdd << " ";
		cout << trace << " ";
		cout << payload << " " << endl;
	}

	~message()
	{

	}
};

//gloabal variable
message* newMess = nullptr;
int line_count = 0;
void loadMessages(const char* fileName) {

	//variables
	ifstream fin;
	string str[30];
	string msg[5];
	int count = 0;
	string temp = "";
	int index;
	string line;

	fin.open(fileName);

	while (getline(fin, temp))
	{
		str[count] = temp;
		line_count++;
		count++;
	}

	fin.close();

	newMess = new message[line_count];

	for (int i = 0; i < line_count; i++)
	{
		line = str[i];
		temp = "";
		count = 0;
		index = 0;
		bool flag = true;

		for (int i = 0; i < 5; i++)
		{
			msg[i] = "";
		}

		while (flag == true)
		{
			if (line[count] != ':')
			{
				temp += line[count];
			}

			if (line[count] == ':')
			{
				msg[index] = temp;
				index++;
				temp = "";
			}

			if (line[count] == '\0')
			{
				msg[index] = temp;
				index++;
				temp = "";
				flag = false;    //setting flag false to terminate loop
			}

			count++;
		}

		int id = stoi(msg[0]);
		newMess[i].setID(id);
		int prio = stoi(msg[1]);
		newMess[i].setPrio(prio);
		newMess[i].setSource(msg[2]);
		newMess[i].setDest(msg[3]);
		newMess[i].setPayLoad(msg[4]);
	}

	//check
	for (int i = 0; i < line_count; i++)
	{
		newMess[i].display();
	}

}
template<class T>
class maxHeap {

	T* array;
	int sizeOfArr;
	int index;

public:

	bool isEmpty()
	{
		bool flag;

		if (index == 0)
		{
			flag = true;
		}

		else
		{
			flag = false;
		}

		return flag;
	}


	maxHeap()
	{
		this->array = nullptr;
		this->sizeOfArr = 0;
		index = 0;
	}

	maxHeap(int size)
	{
		this->sizeOfArr = size;
		this->array = new int[sizeOfArr];
		index = 0;
	}

	~maxHeap()
	{
		delete[]array;
	}

	//gets index of parent
	int getParent(int ind)
	{
		return (ind) / 2;
	}

	//returns index of the right child
	int getRightChild(int ind)
	{
		return (ind * 2) + 1;
	}

	//returns index of the left child
	int getLeftChild(int ind)
	{
		return (ind * 2);
	}

	void enqueue(T value)
	{

		this->index++;

		// value will be inserted without comparing with parent (no parent in this case)
		if (this->index == 1)
		{
			array[this->index] = value;

		}

		else
		{

			// inserting the value at the last index
			array[this->index] = value;

			//local vars
			int tempI;

			// comparing value with roots and swapping if the value is greater than the root/parent

			tempI = index;

			while (tempI != 1 && array[getParent(tempI)] < array[tempI])
			{

				//swapping
				int temp = array[getParent(tempI)];
				array[getParent(tempI)] = array[tempI];
				array[tempI] = temp;

				//updating variables
				tempI = getParent(tempI);

			}

		}

	}


	void heapify(int array[], int sizeOfArr, int parent)
	{

		int left = getLeftChild(parent);
		int right = getRightChild(parent);

		if (parent < sizeOfArr)
		{

			if (array[parent] < array[left] || array[parent] < array[right])
			{

				if (array[left] < array[right])
				{
					swap(array[right], array[parent]);
					heapify(array, sizeOfArr, right);
				}

				else
				{
					swap(array[left], array[parent]);
					heapify(array, sizeOfArr, right);
				}
			}
		}

	}

	T dequeue()
	{
		//checking if the queue is empty
		if (isEmpty())
		{
			cout << "Queue is empty" << endl;
			return -1;
		}

		if (index == 1)
		{
			T valR = array[1];
			index = 0;
			cout << "The queue has been emptied" << endl;
			return valR;
		}

		T valR = array[1];      //storing the max value in a temp var

		array[1] = array[index];
		this->index--;
		int tempI = this->index;

		heapify(array, tempI, 1);

		return valR;

	}

	void displayHeap()
	{
		for (int i = 1; i <= index; i++)
		{
			cout << array[i] << " ";
		}
		cout << "\n";
	}

};



template<class T>
// this is for the outgoing 
class Node
{
public:
	Node* next;
	message data;

  string getData() {
		return data.getPayLoad();
	}
	void setData(T something) {
		data = something;
	}
	void setnextnull() {
		this->next = NULL;
	}
	Node<T>* getNext() {
		return next;
	}
	void setnext(Node<T>* newnode) {
		this->next = newnode;
	}


};

template<class T>
class Queue {
public:
	Node<message>* front;
	Node<message>* rare;
	int numofelements = 0;

	Queue() {
		front = NULL;
		rare = NULL;
	}
	Node<T>* getRear() {
		return rare;
	}
	bool isEmpty() {
		if (front == NULL)
			return true;
		else
			return false;
	}

	void enqueue(T num)
	{
		Node<T>* newnode;
		newnode = new Node<T>;
		newnode->setnextnull();
		newnode->setData(num);

		if (isEmpty()) {
			front = newnode;
			rare = newnode;
		}
		else {
			rare->setnext(newnode);
			rare = newnode;
		}
		numofelements++;
	}
	Node<T>* dequeue(void)
	{
		Node<T>* s;
		Node<T>* the_deleted;

		if (isEmpty()) {
			cout << "The queue is empty.\n";
			return NULL;

		}
			
		else {
			Node<T>* the_deleted = Front();
			s = front->getNext();
			delete front;
			front = s;
			numofelements--;
			if (!numofelements)
				rare = NULL;
		}
		return the_deleted;

	}
	Node<T>* Front() {
		return front;
	}
	void display() {
		Node<message>* current = front;
		while (current) {
			cout << current->getData();
				current = current->next;
		}
	}

};
// first we get the number of machines phir ussay array declare hojayega machines ka 
// also bool router set up karna hai
// iskay sath sath jo path ata hai for each machine usko dekhna paray gaa
//uss main end par machine and first router check karna paray gaa
// and that will be inserted into the routing table
// or routing table ki linked list hogee?!?!?






class routing_table_node {
	//int *no_of_machines
public:
	string destination;// can add string here
	Queue<message> outgoing;
	string passed_to_router;// can use string here
	routing_table_node* next;
	routing_table_node() {
		this->next = NULL;
	}



};
class routingtable {
public:
	routing_table_node* head;
	routingtable() {
		head = NULL;
	}
	void insert(string dest, string pr) {
		routing_table_node* newnode = new routing_table_node;
		newnode->destination = dest;
		newnode->passed_to_router = pr;
		if (head == NULL) {

			head = newnode;

		}
		else {
			routing_table_node* current = new routing_table_node;
			current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newnode;
		}
	}
	void display() {
		routing_table_node* current = new routing_table_node;
		current = head;
		while (current != NULL) {
			cout << endl << current->destination << "\t" << current->passed_to_router << endl;
			current = current->next;
		}
	
		
	}
};
template< class T>
struct graph_node {
	int weight;
	T name_of;
	bool router;
	string ip_add;
	maxHeap<message> incoming;
	Queue<message> outgoing;
	routingtable routingtable;// linked list 
	Splaying_treee<string>* routingtabletree;// = NULL;// routing table using splay treessssss 

	graph_node* next;
	graph_node() {
		this->next = NULL;
		weight = 0;
	}

};
struct machine {
	string name_of;
	string next_router;
	maxHeap<message> incoming;
	Queue<message> outgoing;
	machine* next;
	machine() {
		this->next = NULL;
	}

};
struct router {
	string name_of;
	routingtable routingtable;
	Queue<message> *outgoing;
	string ip_add;
	router* next;
	router() {
		this->next = NULL;
	}
	void initializing(int num) {
		outgoing = new Queue<message>[num];
	}
};

struct machinell {
	machine *head;
	machinell() {
		this->head = NULL;
	}
	void insert_machine(string name, string router_connected) {
		machine* newnode = new machine;
		newnode->name_of = name;
		newnode->next_router = router_connected;
		if (head == NULL) {

			head = newnode;

		}
		else {
			machine* current = new machine;
			current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newnode;
		}

	}
	void display() {
		cout << "---------------------ALL MACHINES-------------------------\n";
		machine* current = new machine;
		current = head;
		while (current != NULL) {
			cout << endl << current->name_of;// << "\t" << current->passed_to_router << endl;
			current = current->next;
		}


	}

};
machinell* all_machines = new machinell;
struct routerll {
	router* head;
	routerll() {
		this->head = NULL;
	}
	void insertnode(routingtable rooting, string nameof, int total) {
		router* newnode = new router;
		newnode->name_of = nameof;
		newnode->routingtable = rooting;
		if (head == NULL) {

			head = newnode;

		}
		else {
			router* current = new router;
			current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newnode;
		}

	}
	void display() {
		cout << "---------------------ALL ROUTERS-------------------------\n";
		router* current = new router;
		current = head;
		while (current != NULL) {
			cout << endl << current->name_of;// << "\t" << current->passed_to_router << endl;
			current = current->next;
		}


	}
};
routerll* all_routers = new routerll;

template< class T>
class head_array {// sara graph iss main hai
public:
	graph_node<T>** array;
	int no_of;
		head_array(int no_of_vertices) {
		array = new graph_node<T>*[no_of_vertices];
		no_of = no_of_vertices;
	}
		head_array() {

	}
	void allocatem(int memory) {
		array = new graph_node<T>*[memory];
		no_of = memory;
	}
	void inserting_all(string full_Array[] ){
		//cout << "number of vertices:"<<no_of<<endl;

		for (int i = 0; i < no_of; i++) {
			//cout << i<<endl;
			//cout << "dddddddd";
			//cout << full_Array[i] << endl;
			graph_node<T>* newnode = new graph_node<T>;
			newnode->name_of = full_Array[i];
			array[i] = newnode;
			array[i]->name_of = full_Array[i];
			cout << array[i]->name_of;
		}
		
	}
	void separating_mr(int count) {
		for (int i = 0; i < count; i++) {
			if (this->array[i]->name_of[0] == 'M') {
				all_machines->insert_machine(array[i]->name_of, array[i]->next->name_of);
			}
			else {
				graph_node<string>* current = array[i]->next;
				int total = 0;
				while (current) {
					current = current->next;
					total++;
				}
				all_routers->insertnode(array[i]->routingtable, array[i]->name_of,total);
			}
		}
		all_machines->display();
		all_routers->display();
	}
};

class linkedlists {
public:
	graph_node<string>* head;
	linkedlists() {
		head = NULL;
	}
	void insert(graph_node<string>* tt) {
		graph_node<string>* newnode = new graph_node<string>;
		newnode->name_of = tt->name_of;;
		newnode->weight = tt->weight;
		if (head == NULL) {
			head = newnode;

		}
		else {
			graph_node<string>* current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next=newnode;
		}
	}
	bool isEmpty() {
		if (head == NULL)
			return true;
		else
			return false;
	}
	void update(string name, int w) {
		graph_node<string>* current = head;
		cout << "updated";
		while (current != NULL) {
			if (current->name_of == name) {

				current->weight = w;
				break;
			}
			current = current->next;
		}

	}
	void deletion(string name) {
		graph_node<string>* current = head;
		graph_node<string>* to_del;
		graph_node<string>* prev = NULL;
		if (head->name_of == name) {
			to_del = head;
			head = head->next;
			delete to_del;
			return;
		}
		while (current != NULL) {
			prev = current;
			current = current->next;
			if (current->name_of == name)
				break;
		}
		to_del = current;
		prev->next = current->next;
		delete to_del;
		return;
	}
	graph_node<string>* find_min() {
		graph_node<string>* current = head;
		graph_node<string>* min = head;
		while (current != NULL) {
			cout << min->weight << "\t" << current->weight<<endl;
			if (min->weight > current->weight) {
				min = current;
			}
			current = current->next;
	   }
		return min;
	}

};
template<class T>
graph_node<T>* find_head(T source, graph_node<T>* array_of_heads[], int total) {
	for (int i = 0; i < total; i++) {
		if (array_of_heads[i]->name_of == source) {
			return array_of_heads[i];
		}
	}

}
template<typename T>
//class linkedlist {
	void insert_node(graph_node<T>* head, int weight,T  destination) {
		
		graph_node<T>* currentnode = head;
		while (currentnode->next) {
			currentnode = currentnode->next;
		}
		graph_node<T>* newnode = new graph_node<T>;
		newnode->name_of = destination;
		newnode->weight = weight;
		currentnode->next = newnode;


	}
//};


	
	string finding_route(string source, string destination, string full_path[], int count) {
		// woh ent ari main dhunday ga source uss node keh object keh routing table ko access karay gaa
		// aur uss main phir ek node insert  kardeta hai jiss main destination  aur next cheez store hojatee hai 
		// BOOMM ROUTING TABLE 
		//cout << "source:" << source<<endl;
		cout << endl;
		cout << "destination:" << destination <<"\t";
		string temp_dest;
		string temp_src;
		string temp_word;
		string parent;
		bool founder = false;
		while (destination!=source) {
			
			//cout << "we here";
			for (int i = 0; i < count; i++) {
				temp_word = full_path[i];
				int k = 0;
				while (temp_word[k] != ',') {
					temp_src = temp_src + temp_word[k];
					k++;
				}
				k++;
				while (temp_word[k] != '\0') {
					temp_dest = temp_dest + temp_word[k];
					k++;
				}
				if (temp_dest == destination) {
					// we search for temp source
					//cout << "first destination found";
					if (temp_src == source) {
						//cout << "we have found";
						//cout << temp_dest;
						founder = true;
						break;
					}
					destination = temp_src;
					parent = temp_src;
					//temp_src = "";
					//temp_dest = "";
					break;

				}
				else {
					//cout << "kuch";
					temp_src = "";
					temp_dest = "";
				}
			}
			if (founder == true)
				break;
		}
		//cout << source;
		cout << "outgoing queue"<<"\t";
		cout << temp_dest<<endl;
		return temp_dest;



	}
	

head_array<string>* ent_ari= new head_array<string>;
int count = 0;
template<typename T>
void shortest_path(int count, graph_node<T>** array_of_heads, graph_node<T>* src, int index_sp) {
	cout << "inside shortest path";
	graph_node<T>* starting_point = src;
	linkedlists all_ver;
	int min_dist = -1;
	int min_index = -1;
	//bool spt[count];
	string* visited_nodes= new string [count];// this keeps count of the visited nodes
	string* parents= new string [count];// this will keep track of the parents

	int *des= new int [count];
	for (int i = 0; i < count; i++) {
		des[i] = 999;// saaray distances ko maximum infintity
		array_of_heads[i]->weight=999;
		all_ver.insert(array_of_heads[i]);

	}
	for (int i = 0; i < count; i++) {
		cout << array_of_heads[i] << endl;
	}
	// first node jo hai yaani abhi keh liye M1 uska ussay distacne 0
	int source_index = 0;
	for (int i = 0; i < count; i++) {
		if (src->name_of == array_of_heads[i]->name_of) {
			src = array_of_heads[i];
			source_index = i;
			break;
		}
	}
	des[source_index] = 0;

	int deq = 0;
	array_of_heads[0]->weight = 0;
	// koi node visited nahin
	for (int i = 0; i < count; i++) {
		visited_nodes[i] = "";
	}
	int checker = 0;
	visited_nodes[checker] = src->name_of;
	
	checker++;
	
	all_ver.deletion(src->name_of);

	cout << endl;
	
	while (!all_ver.isEmpty()) {
		 
		//cout << "first loop";
		graph_node<string>* current = src->next;
		
		while (current != NULL) {
		//	cout << "jrs";
			int g = 0;
			bool present = false;
			for (int i = checker; i <=0; i--) {
				if (current->name_of == visited_nodes[i]) {
					present = true;
				}
				
		}
			if (present == false) {
				while (current->name_of != array_of_heads[g]->name_of) {
					//cout << g << endl;
					g++;
				}
				// g main you have destination index;
				int destination_index = g;
				//cout << "something";
				cout << des[destination_index] << endl;
				cout << des[source_index] + current->weight << endl;
				if (des[destination_index] > des[source_index] + current->weight) {
					des[destination_index] = des[source_index] + current->weight;
					parents[destination_index] = array_of_heads[source_index]->name_of;
					// make an update weight function in the linked list
					all_ver.update(array_of_heads[destination_index]->name_of, des[source_index] + current->weight);
					array_of_heads[destination_index]->weight = des[source_index] + current->weight;
				}

			}

			current = current->next; 

		}
		//cout << "we here";
		src= all_ver.find_min();
		for (int i = 0; i < count; i++) {
			if (src->name_of == array_of_heads[i]->name_of) {
				src = array_of_heads[i];
				source_index = i;
				break;
			}
		}
		visited_nodes[checker] = src->name_of;
		checker++;
		cout << src->name_of;
		all_ver.deletion(src->name_of);
			// abb you go through the des wali cheez aur uss main minimun distance and aap woh wala dekho gay jo node already deque nahhin hochuka phir usko dequeue karo gay and then src= that node;

			//	if (current_node->weight < dis[checker]) {
			//		min = current_node->weight;
			//		minname = current_node->name_of;
			//	}
			//	current_node = current_node->next;
			//} 
			//

			//jo deque huaa hai uski linked list main jaa kar dekho jiska weight sabe kam hai usko ek toh que se deque kardo aglee bar main ussi ko dhundo all vertice main phir uss kee linked list dekho aur deque



		
	}
	string *full_path= new string [count];
	cout << "\n---------------------------------DATA WE GET FROM DIJEKSTRA"<<starting_point->name_of<<"------------------------------------------\n";
	for (int i = 0; i < count; i++) {
		full_path[i] = "";
		cout << endl;
		cout << parents[i] << "\t";
		cout << array_of_heads[i]->name_of<<"\t";
		
		cout << des[i] << "\t";
		cout << endl;
		full_path[i] = full_path[i] + parents[i] + "," + array_of_heads[i]->name_of;
		// ab idhar saree cheezain agayeen aagay we need to find poora track 
	}
	cout << "\n--------------------------------------END OF DIJEKSTRA DATA-----------------------------------------\n";
	// now we make a function jisko we keep passing machine names and router names aur unsay uskay path extract karlay
	// abhi we have the source
	//cout << "\n---------------------routing table for-----------------------\n";
	//cout << "\n-------------------------------------" << starting_point->name_of << "-----------------------\n";
	array_of_heads[index_sp]->routingtabletree = NULL;
	for (int i = 0; i < count; i++) {
		// issay we keep passing each machine and we get keh ussnay kahan kahan jana hai source tak pahunchnay keh liye
		if (array_of_heads[i]->name_of[0] == 'M') {
			// find keh woh kahan aata hai array main as a destination
	// now i just have to set up setting up ka tareeka
		string next_router = finding_route(starting_point->name_of, array_of_heads[i]->name_of, full_path, count);
		if(spl==false)
		array_of_heads[index_sp]->routingtable.insert( array_of_heads[i]->name_of, next_router);
	//	array_of_heads[index_sp]->routingtabletree  = 	array_of_heads[index_sp]->routingtabletree  .insertingNode(array_of_heads[i]->name_of, next_router, array_of_heads[index_sp]->routingtabletree);
		if(spl==true)
		array_of_heads[index_sp]->routingtabletree = array_of_heads[index_sp]->routingtabletree->insertingNode(array_of_heads[i]->name_of, next_router, array_of_heads[index_sp]->routingtabletree);
		//}
	}

	}
	if (spl == false) {
		cout << "\n---------------------ROUTING TABLE ----------------------\n";
		cout << "\n-------------------------------------" << starting_point->name_of << "-----------------------\n";

		//for (int i = 0; i < count; i++) {
			//if (array_of_heads[i]->name_of[0] == 'M') {
		
			array_of_heads[index_sp]->routingtable.display();
		cout << "\n---------------------END OF ROUTING TABLE FOR-----------------------\n";
		cout << "\n-------------------------------------" << starting_point->name_of << "-----------------------\n";
	}
	else {
		cout << "\n---------------------ROUTING TABLE FOR-----------------------\n";
		cout << "\n-------------------------------------" << starting_point->name_of << "-----------------------\n";
		array_of_heads[index_sp]->routingtabletree->Traversal_Display(array_of_heads[index_sp]->routingtabletree);
		cout << "\n---------------------END OF ROUTING TABLE FOR-----------------------\n";
		cout << "\n-------------------------------------" << starting_point->name_of << "-----------------------\n";
	}//cout << "ssssssssssss\nssssssssss\nssssssss\n\n";
			
		//}
	//}
		

}


int file_reading() {// this works like our main
	
 //     //ab idhar aap ne first line get karke commas tak t


	fstream redeye("network.csv");
	if (!redeye) {
		cout << "cant open";
	}
	string firstline;
	// first we calculate number of commas required 
	// then we record the acutal machines store them in an array of that size
	// then we find links uskay 
	// we can make a 2d matrix uss main we can have that info 

	getline(redeye, firstline);
	int i = 0;
	int count = 0;
	string the_node;
	while (firstline[i] != '\0') {
		if (firstline[i] == ',')
			count++;
		i++;
	}
	//cout << "count:"<<count;
	string* nodes = new string[count];
	i = 0;
	int s = 0;
the_node="";
	bool first = false;
	while (firstline[i] != '\0') {
		cout<< firstline[i];
		if (i==0 )
		{
			i++;
			continue;
		}

		if (firstline[i] == ','  )
		{
			//cout << "the node"<<endl;
			//cout << the_node<<endl;
			nodes[s] = the_node;
			the_node = "";
			s = s + 1;
			i++;
			continue;
		}
		the_node = the_node + firstline[i];
		i++;
	}
	nodes[s] = the_node;
	for (int i = 0; i < count; i++) {
		cout << endl;
		//cout << "fn";
		//cout << nodes[i]<<endl;
	 }
	
	int total = count * count;
	int num = 0;
	while (redeye >> firstline) {
		int i = 0;
		while (firstline[i] != '\0') {
			if (firstline[i] == '?')
				num = num + 1;
			i++;

		}

	}
	redeye.close();
	total = total - num;

	string* between = new string[total * 2];
	//cout << "\nthe total of the thing is " << total;
	int* thew = new int[total];
	int w_ind = 0;
	int rel_ind = 0;
	fstream shuru;
	shuru.open("network.csv");
	if (!shuru) {
		cout << "not opened";
	}
	string words;
	string the_rel;
	int wght;
	string sweight;
	int checkr = 0;
	bool l1 = false;
	cout << "kk";
	int rows = 0;
	while (shuru >> words) {
		
		//cout << "\n\nrows:"<<rows << '\n';
		checkr = 0;
		cout << words << endl;
		if (l1 == false) {
			l1 = true;
			continue;
		}
		int i = 0;
		bool fit = false;
		while (words[i] != '\0') {
		
			if (words[i] == ',') {
				
				if (fit == false) {
					fit = true;
					i++;
					checkr = checkr + 1;
					sweight = "";
					continue;
				}
				
				checkr = checkr + 1;
				if (sweight != "?") {
					cout << sweight;
					//cout << "being inserted\n";
				//	cout << sweight << endl;
					//cout << w_ind;
					thew[w_ind] = stoi(sweight);
					//cout << endl;
					//cout << "row val\n";
					//cout << nodes[rows];
					//cout << "\ncolumn val:\n";
					//cout << checkr;
					//cout << nodes[checkr - 2]<<"\n";
					//cout << thew[w_ind];
					//cout << endl;
					between[rel_ind] =nodes[rows];
					rel_ind = rel_ind + 1;;
					between[rel_ind] = nodes[checkr - 2];
					w_ind = w_ind + 1;
					rel_ind = rel_ind + 1;
					
				}
				the_rel = "";
				sweight = "";
				//cout << "contine";
			}
			
			if (fit && words[i] != ',') {
				sweight = sweight + words[i];
			}
			i++;
		}
		checkr = checkr + 1;
		if (sweight != "?") {
			/*cout << sweight;
			cout << "being inserted\n";
			cout << sweight << endl;
			cout << w_ind;*/
			thew[w_ind] = stoi(sweight);
		/*	cout << endl;
			cout << "row val\n";
			cout << nodes[rows];
			cout << "\ncolumn val:\n";*/
			//cout << checkr;
			/*cout << nodes[checkr - 2] << "\n";
			cout << thew[w_ind];
			cout << endl;*/
			between[rel_ind] = nodes[rows];
			rel_ind = rel_ind + 1;;
			between[rel_ind] = nodes[checkr - 2];
			w_ind = w_ind + 1;
			rel_ind = rel_ind + 1;

		}
		rows = rows + 1;

	}
	int h = 0;
	int rr = 0;
	
	ent_ari->allocatem(count);
	ent_ari->inserting_all(nodes);

	for (int j = 0; j < total * 2; j = j + 2) {
		
		//cout << between[j] << "\t" << between[j + 1] << endl;
		graph_node<string>* head_send=find_head(between[j], ent_ari->array, count);
		insert_node(head_send, thew[h], between[j + 1]);
		//cout << thew[h] << endl;
		h++;
		rr++;
		
	}
	//cout << "we outttttt";
	cout << "\n---------------------------THE GRAPH---------------------------------\n";
	for (int i = 0; i < count; i++) {
		//cout<< ent_ari->array[i]->name_of;
		//cout << ",";
		graph_node<string>* curr = ent_ari->array[i];
		
		while (curr) {
			cout << curr->name_of<<"\t";
			cout << curr->weight;
			curr = curr->next;
			//if(curr->next!=NULL)
			cout << "->";
		}
		cout << endl;
	}
	cout << "\n----------------------------END OF GRAPH-------------------------------\n";
	for (int i = 0; i < count; i++) {
		if(ent_ari->array[i]->name_of[0]=='R'|| ent_ari->array[i]->name_of[0] == 'r')
		shortest_path<string>(count, ent_ari->array, ent_ari->array[i],i);
		else {
			continue;
		}
	}
	return count;
}

//int minDistance(int dist[], bool sptSet[], int count)
//{
//
//	// Initialize min value
//	int min = INT_MAX, min_index;
//
//	for (int v = 0; v < count; v++)
//		if (sptSet[v] == false && dist[v] <= min)
//			min = dist[v], min_index = v;
//
//	return min_index;
//}
void setting_routing_message(int count) {
	//machine* current = all_machines->head;
	for (int i = 0; i < line_count; i++) {
		machine* current = all_machines->head;
		while (current != NULL) {
			if (current->name_of == newMess->getSource()) {
				// then we find iska router in the router wali linked list
			//	cout << "we hereeeeeeeeeeeeeeeeeeeeeeee";
				current->outgoing.enqueue(newMess[i]);
				
				break;
			}
			current->outgoing.display();
			current = current->next;
		}
	}
	//////////////////////// ALL MESSAGES ARE LOADED//////////////////////


	
}
void change_wieghts(string source, string destination, int new_weight, int count) {
	bool sourcew = false;
	bool destw = false;
	for (int i = 0; i < count; i++) {
		if (ent_ari->array[i]->name_of == source) {
			graph_node<string>* current = ent_ari->array[i];
			while (current != NULL) {
				if (current->name_of == destination) {
					current->weight = new_weight;
					sourcew = true;
					break;
				}
					
				current = current->next;
			}
		}
		if (sourcew == true) {
			break;
		}
	}
	sourcew = false;
	destw = false;
	for (int i = 0; i < count; i++) {
		if (ent_ari->array[i]->name_of == destination) {
			graph_node<string>* current = ent_ari->array[i];
			while (current != NULL) {
				if (current->name_of == source) {
					current->weight = new_weight;
					sourcew = true;
					break;
				}

				current = current->next;
			}
		}
		if (sourcew == true) {
			break;
		}
	}
	for (int i = 0; i < count; i++) {
		if (ent_ari->array[i]->name_of[0] == 'R' || ent_ari->array[i]->name_of[0] == 'r')
			shortest_path<string>(count, ent_ari->array, ent_ari->array[i], i);
		else {
			continue;
		}
	}
	ent_ari->separating_mr(count);
	setting_routing_message(count);
}


int main() {
	
	loadMessages("mess.txt");
	char ll = 'n';
	cout << "do you want to use linked list?";
	cin >> ll;
	if (ll = 'n') {
		spl = false;
	}
	else {
		spl = true;
	}

	int count=file_reading();
	char in='n';
	string source;
	string destination;
	int w;
	cout << " do you want to change weights?\n";
	cin >> in;
	if (in == 'y') {
		cout << "enter the source?";
		cin >> source;
		cout << "enter the destination?";
		cin >> destination;
		cout << "enter new weight?";
		cin >> w;
		change_wieghts(source, destination, w, count);
	}
	

	
	//cout << "yeayyyyy";
	return 0;
}
