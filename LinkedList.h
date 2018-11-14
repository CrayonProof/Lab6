
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
    	    cout << "insertHead(" << value << ")" << endl;
    	    
    	    if (head == NULL)
    	    {
    	        head = new Node(value);
    	        listSize ++;
    	        return;
    	    }
    	    
    	    Node* check = head;
    	    
    	    for (int i = 0; i < listSize - 1; i++)
    	    {
    	        cout << "(i) " << i << ": " << endl;
    	        if (check->value == value)
    	            return;
	            check = check->next;
    	    }
    	    
    	    Node *node = new Node(value);
            node->next = head;
            head = node;
            listSize ++;
    	}
    
        void insertTail(T value)
        {
            cout << "insertTail(" << value << ")" << endl;
            
            Node* check = head;
    	    
    	    for (int i = 0; i < listSize; i++)
    	    {
    	        if (check->value == value)
    	            return;
	            check = check->next;
    	    }
            
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
            cout << "insertAfter(" << value << "," << insertionNode << ")" << endl;
            Node* check = head;
            Node* insrtNode;
    	    
    	    for (int i = 0; i < listSize - 1; i++)
    	    {
    	       if (check->value == value)
    	            return;
    	       if (insertionNode == check->value)
    	       {
    	            if (check->next == NULL)
            	    {
            	        check->next = new Node(value);
            	    }
            	    else
            	    {
            	       Node* node = new Node(value);
            	       node->next = check->next;
            	       check->next = node;
            	    }
            	    listSize++;
            	    return;
    	       }
	           check = check->next;
    	    }
        }
    
        void remove(T value)
        {
            cout << "remove(" << value << ")" << endl;
            
            Node* check = head;
            int i = 0;
                
            for (i = 0; i < listSize; i++)
    	    {
    	       if (check->value == value)
    	       {
    	            break;
    	       }
               check = check->next;
    	    }
            
            if (i == 0)
            {
                Node *del = head;
                head = head->next;
                delete del;
                listSize --;
            }
            else
            {
                Node *node = head;
                for (int c = 0; c < i-1; c++) {
                    node = node->next;
                }
                Node *del = check;
                node->next = del->next;
                delete del;
                listSize--;
            }
        }
    
        void clear()
        {
            cout << "clear()" << endl;
            
            Node* nextNode;
            Node* node = head;
            
            for(int i = 0; i < listSize; i++)
            {
                nextNode = node->next;
                delete node;
                node = nextNode;
            }
            
            listSize = 0;
            head = NULL;
        }
    
        T at(int index)
        {
            cout << "at(" << index << ")" << endl;
            
            Node* atNode = head;
            
            if ((index >= listSize) || (index < 0))
            {
                cout << "Error: Out of range" << endl;
                throw out_of_range("out of range");
            }
            else
            {
               for(int i = 0; i < index; i++)
                {
                    atNode = atNode->next;
                }
                return atNode->value;
            }
            
        }
        
    	int size()
    	{
    	    return listSize;
    	}
    	
    	string toString()
    	{
    	    cout << "toString()" << endl;
    	    
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
            
            return "string"; //out.str();
    	}
    	private:
    	    Node* head;
    	    int listSize;
};
