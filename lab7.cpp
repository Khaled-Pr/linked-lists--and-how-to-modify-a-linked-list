/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab7.cpp
 * Author: Khaled.Dz
 *
 * Created on October 9, 2019, 8:47 AM
 */


#include <cstdlib>
#include <iostream>


using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain, not used for lab 7
};

// Print details about the given list, one Node per line
void show(Node* head)
{
    Node* current = head;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node " << i << "\tElem: " << '\t' << current->elem << "\tAddress: " << current << "\tNext Address: " << current->next << endl;
        current = current->next;
        i++;
    }
    
 
    cout << "----------------------------------------------------------------------" << endl;
}
//looking for the first matching value
Node* find_first_of(Node* head, int value)
{
       
    Node* current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        
        //comparison of the element with the value 
        if(current->elem==value)
        {
        
            return current;
        }
        
        current = next;
    }
    return nullptr;
}


int main() 
{
    const int size = 15;

    Node* head    = new Node();
    Node* current = head;

    // Create a linked list from the nodes
    for (int i = 0; i < size; i++)
    {
        current->elem = i;
        current->next = new Node();
        current       = current->next;
    }
    
    // Set the properties of the last Node (including setting 'next' to NULL)
    current->elem = size;
    current->next = NULL;
    show(head);

    // TODO: Your Code Here
    
    cout<<endl<<"   Removing the first element"<<endl;
//***(1.)Removing the first element***//
    //creating a temporary pointer that points to the beginning of our link list
    Node* tmp= head;
    
    //now we move the head pointer that point the the beginning
    //of our link list to the second element of our link list
    head= tmp->next;
    
    // now we delete the first element since our head pointer is pointing
    //to the second element
    delete tmp;
    
    //printing the resulting link list
    show(head);
    
   cout<<endl<<"   Removing the last element"<<endl;
//***(2.)Removing the last element**//
    
    //storing current and previous
    // Getting the first and the second element
    Node* prev_N =head; //pointer to the first node
    Node* current_N=head->next; //pointer to the second node
    
    //The temporary pointer
    Node* tmp_N;
    
    //looping through our link list
    for(int i=0;current_N!=NULL ;i++){
        
        tmp_N= current_N;
        Node* next_N= current_N->next;
       
        //Removing the last element
        if(next_N ==NULL){
            delete tmp_N;
            prev_N->next=next_N;
        }
        
    prev_N =current_N;
    current_N=next_N;
        
    } 

     //printing the resulting link list
    show(head);
   
    cout<<endl<<"   Inserting the ten elements"<<endl;
//***(3.)Inserting the ten elements to the beginning if the current link list***//
    
    //current =new Node;
   // Node* inserted_N = head;
   // head = current;
    
    
    for(int i=0; i<10; i++){
        current =new Node();//creating a new node
        current->next=head;
        head =current;
        head->elem=i;
       Node* inserted_N = head;
       
        
    }
   
         //printing the resulting link list
    show(head);

    cout<<endl<<"   Inserting the ten elements after 7"<<endl;
//***(4.)Inserting the ten element after the first node has 7 the current link list***//

    //Finding where the & located and setting a pointer to it
    Node* target_N = find_first_of(head,7); 
    
   
    // getting the list of the nodes after 7
    //the list from 6,5,4,3,2,1,0,1,2,3,4,5,6,7,8,9
    
    Node* after_target_N= new Node();// Creating a new node
   // after_target_N->prev=target_N->next->prev;
    after_target_N->elem=target_N->next->elem; //getting element after 7 
    after_target_N->next=target_N->next->next;
    
    
    Node* temp_N=new Node();
    target_N->next=temp_N;
    
    
    //Creating a list from 0 to 9
    for(int i=0; i<10;i++){
        temp_N->elem=i;
        temp_N->next=new Node();
        temp_N=temp_N->next;
    }
    
    //connecting all the nodes together
    temp_N->elem=after_target_N->elem;
    //temp_N->prev=after_target_N->prev;
    temp_N->next=after_target_N->next;
    
    
    delete after_target_N;
    
        
         //printing the resulting link list
    show(head);

    // Clean up
    current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
}
