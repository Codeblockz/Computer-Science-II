#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

template <class T>
class Node {
public:
  Node( const T& data ); //Overloaded constructor
  T& GetData(); //Getter
  void SetData( const T& data ); //Setter
  Node<T>* GetNext(); //Getter
  void SetNext( Node<T>* next ); //Setter
private:
  T m_data; //Data stored in node
  Node<T>* m_next; //Pointer to next node
};

template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

template <class T>
T& Node<T>::GetData() {
   return m_data;
}

template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Lqueue {
 public:
  // Name: Lqueue() (Linked List Queue) - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new lqueue where m_head and m_tail point to NULL
  Lqueue();
  // Name: ~Lqueue() - Destructor
  // Desc: Used to destruct a Lqueue
  // Preconditions: There is an existing lqueue with at least one node
  // Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
  //                 to have no memory leaks!
 ~Lqueue();
  // Name: Lqueue (Copy Constructor)
  // Preconditions: Creates a copy of existing LQueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue(const Lqueue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: Copies an Lqueue into an existing Lqueue
  //                Requires a Lqueue
  // Postconditions: Copy of existing Lqueue
  Lqueue<T>& operator = (Lqueue&);
  // Name: Push
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Lqueue
  // Postconditions: Adds a new node to the end of the lqueue.
  void Push(const T&);
  // Name: Pop
  // Preconditions: Lqueue with at least one node. 
  // Postconditions: Removes first node in the lqueue, returns data from first node.
  T Pop();
  // Name: Display
  // Preconditions: Outputs the lqueue.
  // Postconditions: Displays the data in each node of lqueue
  void Display();
  // Name: Front
  // Preconditions: Requires a populated lqueue
  // Postconditions: Returns whatever data is in front 
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a lqueue
  // Postconditions: Returns if the lqueue is empty.
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
  int GetSize();
  // Name: Swap(int)
  // Preconditions: Requires a lqueue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  void Swap(int);
  // Name: Clear
  // Preconditions: Requires a lqueue
  // Postconditions: Removes all nodes in a lqueue
  void Clear();
  // Name: RemoveInsertEnd
  // Preconditions: Requires a lqueue
  // Postconditions: Moves a node from somewhere to the end of the lqueue
  void RemoveInsertEnd(int);
  // Name: TestHeadTail() (Optional test function)
  // Preconditions: Requires a lqueue
  // Postconditions: Returns the value of the head and the tail (used for main below)
  void TestHeadTail();
  // Name: operator<< (Overloaded << operator)
  // Preconditions: Requires a lqueue
  // Postconditions: Returns an ostream with the data from each node on different line
  template <class U>
  friend ostream& operator<<(ostream& output, const Lqueue<U>&);
  //Name: Overloaded [] operator
  //Precondition: Existing Lqueue
  //Postcondition: Returns object from Lqueue using []
  T& operator[] (int x);//Overloaded [] operator to pull data from Lqueue
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};
//*********************************************************************
//******************Implement Lqueue Functions Here********************

// Name: Lqueue() (Linked List Queue) - Default Constructor
// Desc: Used to build a new linked queue (as a linked list)
// Preconditions: None
// Postconditions: Creates a new lqueue where m_head and m_tail point to NULL
template <class T>
Lqueue<T>:: Lqueue(){
  m_head = NULL; //Sets the pointer to point at nothing
  m_tail = NULL; //Sets the pointer to point at nothing
  m_size = 0; //Sets the size of the linked list to 0
}
// Name: ~Lqueue() - Destructor
// Desc: Used to destruct a Lqueue
// Preconditions: There is an existing lqueue with at least one node
// Postconditions: An lqueue is deallocated (including dynamically allocated nodes)
//                 to have no memory leaks!
template <class T>
Lqueue<T>::~Lqueue(){
  Clear();
}
// Name: Lqueue (Copy Constructor)
// Preconditions: Creates a copy of existing LQueue
//                Requires a Lqueue
// Postconditions: Copy of existing Lqueue
template <class T>
Lqueue<T>::Lqueue(const Lqueue& copyL){
  m_head = new Node<T>(copyL.m_head->GetData());
  Node<T>*tempOld = copyL.m_head;
  Node<T>*cur = m_head;
  if(tempOld->GetNext() != NULL){
    while(tempOld->GetNext() != NULL ){
      Node<T>*temp = new Node<T>(tempOld->GetNext()->GetData());
      cur->SetNext(temp);
      cur = cur->GetNext();
      tempOld = tempOld->GetNext();
    }
  }
  m_size = copyL.m_size;
  m_tail = cur;
  m_tail->SetNext(NULL);
}
// Name: operator= (Overloaded Assignment Operator)
// Preconditions: Copies an Lqueue into an existing Lqueue
//                Requires a Lqueue
// Postconditions: Copy of existing Lqueue
template <class T>
Lqueue<T>& Lqueue<T>::operator = (Lqueue& Lque){
  if(this != &Lque){
    Clear();

    m_head = new Node<T>(Lque.m_head->GetData());
    Node<T>*tempOld = Lque.m_head;
    Node<T>*cur = m_head;
    if(tempOld->GetNext() != NULL){
      while(tempOld->GetNext() != NULL ){
	Node<T>*temp = new Node<T>(tempOld->GetNext()->GetData());
	cur->SetNext(temp);
	cur = cur->GetNext();
	tempOld = tempOld->GetNext();
	
      }
    }
    m_size= Lque.m_size;
    m_tail = cur;
    m_tail->SetNext(NULL);
  }
  return *this;
}
// Name: Push
// Preconditions: Takes in data. Creates new node. 
//                Requires a Lqueue
// Postconditions: Adds a new node to the end of the lqueue.
template <class T>
void Lqueue<T>::Push(const T& data){
  Node<T> *temp = new Node<T>(data); //Builds a new node
  temp->SetNext(NULL);//Sets the first node in the linked list to point to nothing

  if(m_head == NULL){ //Checks to see if the linked list is empty
    m_head = temp; //Inserts the first node to the linked list
    m_tail = temp; //Inserts the first node to the linked list
    m_size = 1; //Updates the size
  }
  else{
    m_tail->SetNext(temp);
    m_tail = temp; //Because this is inserting in the end
    m_size++;
  }
}
// Name: Pop
// Preconditions: Lqueue with at least one node. 
// Postconditions: Removes first node in the lqueue, returns data from first node.
template <class T>
T Lqueue<T>::Pop(){
  T data = m_head->GetData();
  Node<T> *temp =  m_head->GetNext();
  delete m_head;
  m_head = temp;
  m_size--;
  return data;
}

// Name: Display
// Preconditions: Outputs the lqueue.
// Postconditions: Displays the data in each node of lqueue
template <class T>
void Lqueue<T>::Display(){
  Node<T>* temp= m_head;

  // if temp not NULL
  if(temp != NULL){
    while(temp != NULL){
    // for(int i = 0; i<m_size;i++){
      cout<<temp->GetData()<<endl;
      temp = temp->GetNext();
    }
  }
}
// Name: Front
// Preconditions: Requires a populated lqueue
// Postconditions: Returns whatever data is in front
template <class T>
T Lqueue<T>::Front(){
  return (m_head->GetData());
}
// Name: IsEmpty
// Preconditions: Requires a lqueue
// Postconditions: Returns if the lqueue is empty.
template <class T>
bool Lqueue<T>::IsEmpty(){
  if (m_size == 0){
    return true;
  }
  else{
    return false;
  }
}
 // Name: GetSize
  // Preconditions: Requires a lqueue
  // Postconditions: Returns m_size
template <class T>
int Lqueue<T>:: GetSize(){
  return m_size;
}

// Name: Swap(int)
// Preconditions: Requires a lqueue
// Postconditions: Swaps the nodes at the index with the node prior to it.
template<class T>
void Lqueue<T>::Swap(int index){
  Node<T>*temp = m_head;
  Node<T>*first = NULL;
  Node<T>*second = NULL;
  Node<T>*swap = NULL;
  // if index is 2 swap with head
  if(index == 1){
    first = temp;
    swap = temp->GetNext();
    first->SetNext(swap->GetNext());
    swap->SetNext(first);
    m_head = swap;
  }
  // if index is tail
  else if(index == (m_size-1)){
    for(int i = 0; i<index; i++){
      if(index -2 ==i){
	first = temp;
      }
      else if(index -1==i){
	second = temp;
      }
      temp = temp->GetNext();
    }
    swap = temp;
    first->SetNext(swap);
    second->SetNext(swap->GetNext());
    m_tail = second;
    swap->SetNext(m_tail);
  }
  // if index in between
  if(index >1 && index < (m_size-1)){
    for(int i = 0; i<index; i++){
      if(index -2 ==i){
	first = temp;
      }
      else if(index -1==i){
	second = temp;
      }
      temp = temp->GetNext();
    }
    swap = temp;
    first->SetNext(swap);
    second->SetNext(swap->GetNext());
    swap->SetNext(second);
  }
}
// Name: RemoveInsertEnd
// Preconditions: Requires a lqueue
// Postconditions: Moves a node from somewhere to the end of the lqueue
template <class T>
void  Lqueue<T>::RemoveInsertEnd(int index){
  for(int i = 0; i< m_size; i++){
    if(i>index){
      Swap(i);
    }
  }
}
// Name: Clear
// Preconditions: Requires a lqueue
// Postconditions: Removes all nodes in a lqueue
template <class T>
void Lqueue<T>::Clear(){
  Node<T>* current = m_head;
  while( current != 0 ) {
    Node<T>* next = current->GetNext();
    current->SetNext(next);
    delete current;
    current = next;
    m_size--;
  }
  m_head = NULL;
  m_tail = NULL;
}


// Name: TestHeadTail() (Optional test function)
// Preconditions: Requires a lqueue
// Postconditions: Returns the value of the head and the tail (used for main below)
template <class T>
void  Lqueue<T>::TestHeadTail(){
  //  Node<T>* current = m_head;
  T current =m_head->GetData();
  T last = m_tail->GetData();
  //Node<T>* last = m_tail;
  cout<<"TEST"<<endl;
  cout<<current<<endl
      << last<<endl;
}

// Name: operator<< (Overloaded << operator)
// Preconditions: Requires a lqueue
// Postconditions: Returns an ostream with the data from each node on different line
template <class U>
ostream& operator<<(ostream& output, const Lqueue<U>& Lque){
  Node<U>* temp= Lque.m_head;
  //T tempData;
  if(temp != NULL){
    while(temp != NULL){
      output<<temp->GetData()<<endl;
      temp = temp->GetNext();
    }
  }
  return output;
}
//Name: Overloaded [] operator
//Precondition: Existing Lqueue
//Postcondition: Returns object from Lqueue using []
template <class T>
T& Lqueue<T>::operator[] (int x){//Overloaded [] operator to pull data from Lqueue
Node<T>*temp = m_head;
for(int i = 0; i<x; i++){
  temp = temp->GetNext();
 }


 return temp->GetData();
}


//************************Lqueue Tests Below***************************
// To test just Lqueue follow these instructions:
//   1.  mv Lqueue.h Lqueue.cpp
//   2.  Uncomment out int main below
//   3.  make Lqueue
//   4.  ./Lqueue

/*
int main () {

  //Test 1 - Default Constructor and Push
  cout << "Test 1 - Default Constructor and Push Running" << endl;
  //Test Default Constructor
  Lqueue <int> newLQ1;
  //Push 4 nodes into Lqueue
  newLQ1.Push(10);
  newLQ1.Push(11);
  newLQ1.Push(12);
  newLQ1.Push(13);
  cout << endl;


  //Test 2 - Copy Constructor and Assignment Operator
  cout << "Test 2 - Copy Constructor and Assignment Operator Running" << endl;
  //Test Copy constructor
  Lqueue <int> newLQ2(newLQ1);
  //Test Overloaded Assignment Operator
  Lqueue <int> newLQ3;
  newLQ3 = newLQ2;
  cout << endl;
  
  //Test 3 - Test Display and Overloaded <<
  cout << "Test 3 - Display and Overloaded << Running" << endl;
  cout << "newLQ1" << endl;
  newLQ1.Display();
  cout << "newLQ2" << endl;
  newLQ2.Display();
  cout << "newLQ3" << endl;
  newLQ3.Display();
  cout << "newLQ1" << endl;
  cout << newLQ1;
  cout << "newLQ2" << endl;
  cout << newLQ2;
  cout << "newLQ3" << endl;
  cout << newLQ3;
  cout << endl;


  //Test 4 - Test Front and Pop
  cout << "Test 4 - Front and Pop Running" << endl;
  //Test Front()
  cout << "Testing Front - Output 10" << endl;
  cout << newLQ1.Front() << endl;
  //Test Pop with Display of Pop
  cout << "Popping one node and displaying it" << endl;
  cout << newLQ1.Pop() << endl;
  //Test Pop with Display of Pop
  cout << "Popping one node and displaying it" << endl;
  cout << newLQ1.Pop() << endl;
  cout << endl;
  
  //Test 5 - Test GetSize and Clear
  cout << "Test 5 - GetSize and Clear Running" << endl;
  //Test GetSize()
  cout << "Outputting the size" << endl;
  cout << newLQ1.GetSize() << endl;
  //Test Clear()
  cout << "Clearing all nodes" << endl;
  newLQ1.Clear();
  cout << endl;
  
  //Test 6 - Test Swap
  cout << "Test 6 - Swap Running" << endl;
  newLQ2.Swap(2);
  int size = newLQ2.GetSize();
  int size1 = newLQ3.GetSize();
  cout << "Swap 2 - Should display 10->12->11->13->END" << endl;
  cout<<"Size1: "<< size<<endl<<"Size2: "<<size1<<endl;
  newLQ2.Display();

   cout << "Test 6-a - Swap Running" << endl;
  newLQ2.Swap(3);
  cout << "Swap 3 - Should display 10->11->13->12->END" << endl;
  newLQ2.Display();
  cout<<endl;
  //Testing to make sure head and tail point at the correct node
  newLQ2.TestHeadTail();
  cout << "Should display head 10 and tail 13" << endl;
  cout << endl;
  
  //Test 7 - Test RemoveInsertEnd(2)
  cout << "Test 7 - RemoveInsertEnd Running" << endl;
  cout << "Before RemoveInsertEnd" << endl;
  newLQ3.Display();
  newLQ3.TestHeadTail();
  newLQ3.RemoveInsertEnd(2);
  cout << "After RemoveInsertEnd 10->11->13->12->END" << endl;
  newLQ3.Display();
  newLQ3.TestHeadTail();
  cout<<"TEST"<<newLQ3[0]<<endl;
  return 0;
}
*/


