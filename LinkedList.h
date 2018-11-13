
#include <string>
#include <iostream>
#include "LinkedListInterface.h"

using namespace std;


template<typename T>
class LinkedList
{

    public:
    
    	LinkedList(void)
    	{
    	    head = NULL;
            listSize = 0;
    	};
    	~LinkedList(void)
    	{
    	    clear();
    	};
    	
        struct Node 
        {
            T value;
            Node *next;
            
            Node(T value)
            {
                this->value = value;
                next = NULL;
            }
        };
    
    	void insertHead(T value)
    	
    	{
    	    if (head = NULL)
    	        return;
    	    Node* check = head;
    	    
    	    for (int i = 0; i < listSize; i++)
    	    {
    	        if (check->value == value)
    	            return;
	            check = check->next;
    	    
    	    
    	    Node *n = new Node(value);
            n->next = head;
            head = n;
            listSize ++;
    	}
    
        void insertTail(T value)
        {
            Node* check = head;
    	    
    	    do
    	    {
    	        if (check->value == value)
    	            return;
	            check = check->next;
    	    } while (check->next != NULL);
            
            if (head == NULL)
            {
                head = new Node(value);
            }
            else
            {
                Node *node = head;
                for (int i = 0; i < listSize-1; i++)
                {
                    node = node->next;
                }
                node->next = new Node(value);
            }
            listSize ++;
        }
    	
        void insertAfter(T value, T insertionNode)
        {
            Node* check = head;
            Node* insrtNode;
    	    
    	    do
    	    {
    	       if (check->value == value)
    	            return;
    	       if (insertionNode == check->value)
    	            insrtNode = check;
	            check = check->next;
    	    } while (check->next != NULL);
    	    
    	    listSize++;
    	    Node* nextNext = insrtNode->next;
    	    insrtNode->next = new Node(value);
    	    insrtNode->next->next = nextNext;   
        }
    
        void remove(T value)
        {
            Node* preCheck;
            int counter = 0;
            
            if (head == NULL)
                return;
            else if (head->value == value)
            {
                listSize--;
                head = head->next;
                return;
            }
            
            Node* check = head;
            
            do
    	    {
    	       if (check->next->value == value)
    	       {
    	           listSize--;
    	           check->next = check->next->next;
    	           return;
    	       }
	           check = check->next;
    	    } while (check->next != NULL);
        }
    
        void clear()
        {
            Node* node = head;
            
            for(int i = 0; i < listSize; i++)
            {
                delete node;
            }
            
            listSize = 0;
            head = NULL;
        }
    
        T at(int index)
        {
            Node* atNode = head;
            
            if ((index >= listSize) || (index < 0))
            {
                cout << "Error: Out of range" << endl;
            }
            else
            {
               for(int i = 0; i < index; i++)
                {
                    atNode = atNode->next;
                } 
            }
            
            return atNode->value;
        }
        
    	int size()
    	{
    	    return listSize;
    	}
    	
    	string toString()
    	{
    	    Node* node = head;
    	    //basic_stringstream<T> out;
            string s = "";
            
            for(int i = 0; i < listSize; i++)
            {
                
                if(node->next != NULL)
                {
                    //out << node->value << " ";
                }
                else
                {
                   //out << node->value; 
                }
                node = node->next;
            }
            
            return "the string"; //out.str();
    	}
    	private:
    	    Node* head;
    	    int listSize;
};
