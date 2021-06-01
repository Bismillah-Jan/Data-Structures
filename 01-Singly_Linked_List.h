template <class T>
class Node
{
public:
	T data;
	Node<T> * next;
};

template<class T>
class LinkedList
{
	Node<T> * head;
	Node<T> * tail;
public:
	LinkedList();
	void insertAtStart(T data);
	void insertAtEnd(T data);
	bool search(const T & key) const;
	void deleteAkey(const T & key);
	void deleteAllOccurences(const T & key );
	void insertBefore(const T data, const T key); //insert data before key only once
	void printList() const;
	void destroyList();
	~LinkedList()
	{
		cout<<"\nFrom Destructor!\n";
		destroyList();
	}
};


//---------------Default Constructor-----------------
template<class T>
LinkedList<T>::LinkedList()
{
	head=NULL;
	tail=NULL;
}

//---------------InsertAtStartFunction---------------
template<class T>
void LinkedList<T>::insertAtStart(T data)
{
	Node<T>* nptr=new Node<T>;
	nptr->data=data;
	nptr->next=head;
		
	if(head==NULL)
	{
		head=nptr;
		tail=nptr;
		
	}
	else
		head=nptr;
		
	

}

//----------------InsertAtEnd Function-------------
template<class T>
void LinkedList<T>::insertAtEnd(T data)
{
	Node<T>* nptr=new Node<T>;
	nptr->data=data;
	if(head==NULL)
	{
		head=nptr;
		tail=nptr;
	}
	else
	{
		tail->next=nptr;
		nptr->next=NULL;
		tail=tail->next;
	}
}

//--------------PrintList Function---------------
template<class T>
void LinkedList<T>::printList() const
{
	if(head==NULL)
		cout<<"List is empty!";
	else
	{
		Node<T>* current=head;
		while(current!=NULL)
		{
			cout<<current->data<<"  ";
			current=current->next;
		}
		cout<<endl;
	}
}


//-------------------SEARCH Function-------------
template<class T>
bool LinkedList<T>::search(const T & key)const
{
	bool flag=false;
	if(head==NULL)
			cout<<"List is empty!"<<endl;
	else
	{
		Node<T>* current=head;
		while(current!=NULL)
		{
			if(current->data==key)
				return flag=true;
			else
			current=current->next;
		}
	}
	return flag;
}

//---------------Function to destroyList---------
template<class T>
void LinkedList<T>:: destroyList()
{
	if(head==NULL)
		cout<<"List is empty. No need to destroy! :)"<<endl;
	else
	{
		Node<T>* current;
		while(head!=NULL)
		{
			current=head;
			head=head->next;
			delete current;

		}
		cout<<"List has been destroyed"<<endl;
	}


}

//----------------Delete A Key function ----------------
template<class T>
void LinkedList<T>::deleteAkey(const T & key)
{
	Node<T>* current=head;
	if(head==NULL)			//case 01: if list is empty
		cout<<"List is empty!"<<endl;
	else if(head->data==key) //case 02: if key found in the first node
	{
		head=head->next;
		delete current;
	}
	else			//search for the key 
	{
		Node<T> * trailCur=NULL; //third pointer to be used for connecting the nodes after deletion

		while(current!=NULL)
		{
			if(current->data!=key)
			{
			trailCur=current;
			current=current->next;
			}
			else
				break;
		}

		if(current!=NULL && current->data==key)
		{
			trailCur->next=current->next;
			delete current;
		}
		else
		cout<<"Sorry! The key does not exist!"<<endl;
	}

	
}
//----------------DeleteAllOccurrences Function------------------
template<class T>
void LinkedList<T>::deleteAllOccurences(const T & key)
{
	
	if(head==NULL)
		cout<<"List is empty!"<<endl;
	else
	{
		Node<T>* current=head;
		Node<T>* trailCur=current;
		while (current!=NULL)
		{
			if(head->data==key)
			{
				head=head->next;
				delete current;
				current=head;
			}
			else if(current->data==key)
			{
				trailCur->next=current->next;
				delete current;
				current=trailCur->next;
			}
		
			else
			{
				trailCur=current;
				current=current->next;
			}
		}
		
	}
}


//----------------Insert Before Function---------------------
template<class T>
void LinkedList<T>:: insertBefore(const T data, const T key)
{
	
	if(head==NULL)
		cout<<"List is empty, can't insert "<<data<<" before "<<key<<endl;
	else
	{
		if(head->data==key)
		{
			Node<T>* nptr=new Node<T>;
			nptr->data=data;
			nptr->next=head;
			head=nptr;
		}
		else
		{
			Node<T>* current=head;
			Node<T>* trailCur=head;
			
			while(current!=NULL)
			{
				if(current->data!=key)
					{
						trailCur=current;
						current=current->next;

					}
				else
				{
					Node<T>* nptr=new Node<T>;
					nptr->data=data;
					nptr->next=current;
					trailCur->next=nptr;
					break;

				}

			}
			if(current==NULL)
				cout<<"Can't insert the data. The key doesn't exist\n";
			

		}
	}
}

