# datastructure

Program 1:Write a C++ program for implementing Singly Linked list.

     #include<iostream>
     #include<cstdlib>
     using namespace std;
      struct node
     {
	int info;
	struct node *next;
     }* start;
     class single_llist
      {
	public:
		node* create_node(int);
		void insert_begin();
		void insert_last();
		void insert_pos();
		void delete_begin();
		void delete_last();
		void delete_pos();
		void update_begin();
		void update_last();
		void update_pos();
		void sort();
		void reverse();
		void search();
		void display();
		single_llist()
		{
			start=NULL;
		}
	};
	int main()
	{
		int choice;
		single_llist sl ,s2;
		start=NULL;
		do
		{
			cout<<"---------------------------"<<endl;
			cout<<"Operations on singly linked list"<<endl;
			cout<<"----------------------------"<<endl;
			cout<<"1.Insert at first"<<endl;
			cout<<"2.Insert at last"<<endl;
			cout<<"3.Insert at position"<<endl;
			cout<<"4.Delete at first"<<endl;
			cout<<"5.Delete at last"<<endl;
			cout<<"6.Delete at position"<<endl;
			cout<<"7.Update at first"<<endl;
			cout<<"8.Update at last"<<endl;
			cout<<"9.Update at position"<<endl;
			cout<<"10.Ascending order"<<endl;
			cout<<"11.Descending order"<<endl;
			cout<<"12.Search"<<endl;
			cout<<"13.Display"<<endl;
			cout<<"14.Exit"<<endl;
			cout<<"Enter your choice:";
			cin>>choice;
			switch(choice)
			{
				case 1:sl.insert_begin();
				sl.display();
				break;
				case 2:sl.insert_last();
				sl.display();
				break;
				case 3:sl.insert_pos();
				sl.display();
				break;
				case 4:s2.delete_begin();
				sl.display();
				break;
				case 5:s2.delete_last();
					sl.display();
				break;
				case 6:sl.delete_pos();
				sl.display();	break;
				case 7:sl.update_begin();
				sl.display();
				break;
				case 8:sl.update_last();
					sl.display();
				break;
			    case 9:sl.update_pos();
					sl.display();
				break;
				case 10:sl.sort();
					sl.display();
				break;
				case 11:sl.reverse();
				sl.display();
				break;
				case 12:sl.search();
					sl.display();
				break;
				case 13:sl.display();
				break;
				case 14:exit(0);
				break;
				default:cout<<"Wrong Choice---???"<<endl;
				break;
			}
		}
		while(choice!=14);
	}
	node*single_llist::create_node(int value)
	{
		struct node *temp,*s;
		temp=new(struct node);
		if(temp==NULL)
		{
			cout<<"Memory not allocated"<<endl;
			return 0;
		}
		else
		{
			temp->info=value;
			temp->next=NULL;
			return temp;
		}
	}
	void single_llist::insert_begin()
	{
		int value;
		cout<<"Enter the value to be inserted:";
		cin>>value;
		struct node *temp,*s;
		temp=create_node(value);
		if(start==NULL)
		{
			start=temp;
			start->next=NULL;
			cout<<temp->info<<"Is inserted at first in the empty list"<<endl;
		}
		else
		{
			s=start;
			start=temp;
			start->next=s;
			cout<<temp->info<<"Is inserted at first"<<endl;
		}
	}
	void single_llist::insert_last()
	{
		int value;
		cout<<"Enter the value to be inserted:";
		cin>>value;
		struct node *temp,*s;
		temp=create_node(value);
		if(start==NULL)
		{
			start=temp;
			start->next=NULL;
			cout<<temp->info<<"Is inserted at last in the empty list"<<endl;
		}
		else
		{
			s=start;
			while(s->next!=NULL)
			{
				s=s->next;
			}
			temp->next=NULL;
				s->next=temp;
				cout<<temp->info<<"is inserted at last"<<endl;
			}
		}
		void single_llist::insert_pos()
		{
			int value,pos,counter=0,loc=1;
			struct node*temp,*s,*ptr;
			s=start;
			while(s!=NULL)
			{
				s=s->next;
				counter++;
			}
			if(counter==0){}
			else
			{
				cout<<"Enter the position from"<<loc<<"to"<<counter+1<<":";
				cin>>pos;
				s=start;
				if(pos==1)
				{
					cout<<"enter the value to be inserted:";
					cin>>value;
					temp=create_node(value);
					start=temp;
					start->next=s;
					cout<<temp->info<<"is inserted at first"<<endl;
				}
				else if(pos>1&&pos<=counter)
				{
					cout<<"enter the value to be inserted:";
					cin>>value;
					temp=create_node(value);
					for(int i=1;i<pos;i++)
					{
						ptr=s;
						s=s->next;
					}
					ptr->next=temp;
					temp->next=s;
					cout<<temp->info<<"is inserted at position"<<pos<<endl;
				}
				else if(pos==counter+1)
				{
					cout<<"Enter the value to be inserted:";
					cin>>value;
					temp=create_node(value);
					while(s->next!=NULL)
					{
						s=s->next;
					}
					temp->next=NULL;
						s->next=temp;
						cout<<temp->info<<"is inserted at last"<<endl;
						}
						else
						{
							cout<<"Position out of range---!!!"<<endl;
						}
					}
				}
				void single_llist::delete_begin()
				{
					if(start==NULL){}
					else
					{
						struct node *s,*ptr;
						s=start;
						start=s->next;
						cout<<s->info<<"delete from first"<<endl;
						free(s);
					}
				}
				void single_llist::delete_last()
				{
					int i,counter=0;
					struct node *s,*ptr;
					if(start==NULL){}
					else
					{
						s=start;
						while(s!=NULL)
						{
							s=s->next;
							counter++;
						}
						s=start;
						if(counter==1)
						{
							start=s->next;
							cout<<s->info<<"deleted from last"<<endl;
							free(s);
						}
						else
						{
							for(i=1;i<counter;i++)
						{
							ptr=s;
							s=s->next;
						}
						ptr->next=s->next;
						cout<<s->info<<"deleted from last"<<endl;
						free(s);
					}
				}
			}
			void single_llist::delete_pos()
			{
				int pos,i,counter=0,loc=1;
				struct node *s,*ptr;
				s=start;
				while(s!=NULL)
				{
					s=s->next;
					counter++;
				}
				if(counter==0){}
				else
				{
					if(counter==1)
					{
						cout<<"Enter the position[SAY"<<loc<<"]:";
						cin>>pos;
						s=start;
						if(pos==1)
						{
							start=s->next;
							cout<<s->info<<"deleted from first"<<endl;
							free(s);
						}
						else
						cout<<"Position out of range..!!!"<<endl;
					}
					else
					{
						cout<<"Enter the position from"<<loc<<"to"<<counter<<":";
						cin>>pos;
						s=start;
						if(pos==1)
						{
							start=s->next;
							cout<<s->info<<"deleted from first"<<endl;
							free(s);
						}
						else if(pos>1&&pos<=counter)
						{
							for(i=1;i<pos;i++)
							{
								ptr=s;
								s=s->next;
							}
							ptr->next=s->next;
							if(pos==counter)
							{
								cout<<s->info<<"deleted from last"<<endl;
								free(s);
								}
								else
								{
									cout<<s->info<<"deleted from position"<<pos<<endl;
									free(s);
									}
								}
								cout<<"Position out of range...!!!"<<endl;
							}
						}
					}
					void single_llist::update_begin()
					{
						int value,pos=1,i,counter=0;
						struct node*s,*ptr;
						s=start;
						while(s!=NULL)
						{
							s=s->next;
							counter++;
						}
						if(counter==0){}
						else if(pos==1)
						{
							cout<<"Enter the new node:";
							cin>>value;
							start->info=value;
							cout<<"Node updated at first position:"<<pos<<"="<<start->info<<endl;
							}
							}
							void single_llist::update_last()
							{
								int value,pos,i,counter=0;
								struct node *s,*ptr;
								s=start;
								while(s!=NULL)
								{
									s=s->next;
									counter++;
								}
								s=start;
								if(counter==0){}
								else
								{
									cout<<"Enter the new node:";
									cin>>value;
									for(i=1;i<counter;i++)
									{
										s=s->next;
									}
									s->info=value;
									cout<<"Node updated at last position:"<<counter<<"="<<s->info<<endl;
								}
							}
							void single_llist::update_pos()
							{
								int value,pos,i,counter=0,loc=1;
								struct node *s,*ptr;
								s=start;
								while(s!=NULL)
								{
									s=s->next;
									counter++;
								}
								if(counter=0){}
								else
								{
									if(counter==1)
									{
										cout<<"Enter the position[SAY"<<loc<<"]:";
										cin>>pos;
										s=start;
										if(pos==1)
										{
											cout<<"Enter the new node:";
											cin>>value;
											start->info=value;
											cout<<"Node updated at position:"<<pos<<"="<<start->info<<endl;
										}
										else
										cout<<"Position out of range....!!!"<<endl;
									}
									else
									{
										cout<<"Enter the position from"<<loc<<"to"<<counter<<":";
										cin>>pos;
										s=start;
										if(pos==1)
										{
											cout<<"Enter the new node:";
											cin>>value;
											start->info=value;
											cout<<"Node updated at position:"<<pos<<"="<<start->info<<endl;
											}
											else if(pos>1&&pos<=counter)
											{
											cout<<"enter the new node:";
											cin>>value;
											for(i=1;i<pos;i++)
											{
												s=s->next;
											}
											s->info=value;
											cout<<"Node updated at position:"<<pos<<"="<<s->info<<endl;
										}
										else
										cout<<"Position out of range...!!!"<<endl;
									}
								}
							}
							void single_llist::sort()
							{
								struct node *ptr,*s;
								int value;
								if(start==NULL){}
								else
								{
									ptr=start;
									while(ptr!=NULL)
									{
										for(s=ptr->next;s!=NULL;s=s->next)
										{
											if(ptr->info=s->info)
											{
												value=ptr->info;
												ptr->info=s->info;
												s->info=value;
											}
										}
										ptr=ptr->next;
									}
								}
							}
						
					void single_llist::search()
					{
						int value,loc=0,pos=0,counter=0;
						struct node *s;
						s=start;
						while(s!=NULL)
						{
							s=s->next;
							counter++;
						}
						if(start==NULL){}
						else
						{
							cout<<"Enter the value to be searched:";
							cin>>value;
							struct node *s;
							s=start;
							while(s!=NULL)
							{
								pos++;
								if(s->info==value)
								{
									loc++;
									if(loc==1)
									cout<<"Element"<<value<<"is found at position"<<pos;
									else if(loc<=counter)
									cout<<","<<pos;
								}
								s=s->next;
							}
							cout<<endl;
							if(loc==0)
							cout<<"Element"<<value<<"not found in the list"<<endl;
						}
					}
					void single_llist::display()
					{
						struct node *temp;
						if(start==NULL)
						cout<<"Linkedlist contains:";
						temp=start;
						while(temp!=NULL)
						{
							cout<<temp->info<<"";
							temp=temp->next;
						}
						cout<<endl;
					}
 OUTPUT:<br>
        ![image](https://user-images.githubusercontent.com/97939284/154905536-baa85636-0018-4a4b-a66a-d08abdb82462.png)
![image](https://user-images.githubusercontent.com/97939284/154905640-be53ed95-1ce5-417b-89ba-04e0ca01422c.png)
![image](https://user-images.githubusercontent.com/97939284/154905743-339d1586-553e-41c5-92c1-ad25743a7961.png)
![image](https://user-images.githubusercontent.com/97939284/154905861-7885a30e-9d66-46fc-8ac1-e4f0fc772de6.png)
![image](https://user-images.githubusercontent.com/97939284/154905905-ff63f39e-bdac-4548-b54f-854745e98266.png)
![image](https://user-images.githubusercontent.com/97939284/154905957-783c83ea-c2a4-44ef-9ff7-efd5641fbfa0.png)
![image](https://user-images.githubusercontent.com/97939284/154905987-5444df75-2440-4140-8b47-5ed54506bd84.png)
![image](https://user-images.githubusercontent.com/97939284/154906060-47c5a978-6486-4361-8450-06c006f05a1f.png)
![image](https://user-images.githubusercontent.com/97939284/154906091-afef4a85-7140-4ea7-a56f-af4c7e1545fa.png)
![image](https://user-images.githubusercontent.com/97939284/154906168-0c7488a0-f939-4cae-8341-6aa3e4de336f.png)
![image](https://user-images.githubusercontent.com/97939284/154906239-f15fa5f8-1a76-414d-9ab0-3bb132a62c71.png)
![image](https://user-images.githubusercontent.com/97939284/154906401-f2bc4dce-d78a-40e6-bd0e-b444524f0a96.png)
![image](https://user-images.githubusercontent.com/97939284/154906523-d3dceb56-bd10-4212-9842-fa7de4404be8.png)
![image](https://user-images.githubusercontent.com/97939284/154906593-39b7a883-b708-4623-923a-43d6b56f661b.png)
![image](https://user-images.githubusercontent.com/97939284/154906733-7b832eed-8d71-421c-80b5-a6cd2c8cdd69.png)

Program 2:Write a C++ program to split the linked list into two halves such that the element ‘e’ should be the first element of second list.
       
    #include<iostream>
    using namespace std;
    struct Node{
    int value;
    struct Node *next;
    };
    struct Node* head = NULL;
    struct Node* sHead = NULL;
    struct Node* temp = NULL;
    void insert(int new_data){
    struct Node* new_node = new Node(); //(struct Node*)malloc(sizeof(struct Node));
    new_node->value = new_data;
    new_node->next = head;
    head = new_node;
    }
    int n;
    int ele;
    int splitIndex;
    int main()
    {
    int i;
    cout<<"Enter number of elements you want in the list\t";
    cin>>n;
    cout<<"Enter elements :" <<endl;
    for(i=0;i<n;i++){
    cin>>ele;
    insert(ele);
    }
    cout<<"\nList of elements : "<<endl;
    Node *t;
    t = head;
    while(t != NULL)
    {
    cout<<t->value<<"\t";
    t = t->next;
    }
    cout<<"\n\nEnter the position you want the list to split ";
    cin>>splitIndex;
    while(splitIndex < 0 || splitIndex > n-1){
    cout<<"Invalid position. Try again."<<endl;
    cin>>splitIndex;
    }
    temp = head;
    for(i=0;i<=splitIndex;i++)
    {
    if(i==splitIndex-1){
     Node *tN;
     tN = temp->next;
    sHead = tN;
    temp->next = NULL;
    break;
     }
    temp = temp->next;
    }
    temp = head;
    if(temp == NULL)
    {
    cout<<"\nFirst list is empty"<<endl;
    }else
    {
    cout<<"\n\nFirst list element "<<endl;
    while(temp != NULL)
    {
    cout<<temp->value<<"\t";
    temp = temp->next;
    }
    }
    temp = sHead;
    if(temp == NULL)
    {
    cout<<"\nSecond list is empty"<<endl;
    }else
    {
    cout<<"\n\nSecond list elements "<<endl;
    while(temp != NULL)
    {
    cout<<temp->value<<"\t";
    temp = temp->next;
    }
    }
    return 0;
    }
   
     OUTPUT:<BR>
![image](https://user-images.githubusercontent.com/97939284/157169648-a8fdee45-2cfe-434b-ba11-3017d45052c9.png)
![image](https://user-images.githubusercontent.com/97939284/157169744-ed0a1787-f8e9-46d3-bb21-b8f7892b6010.png)
	
      Program 3:
	
	
	#include<bits/stdc++.h>
        using namespace std;
        struct Node
        {
	int data;
	struct Node*left,*right;
	Node(int data)
	{
		this->data =data;
		left=right=NULL;
	}
        };
        bool isBSTUtil(struct Node*root,Node*&prev)
        {
	if(root)
	{
		if(!isBSTUtil(root->left,prev))
		return false;
		if(prev !=NULL&&root->data<=prev->data)
		return false;
		prev=root;
		return isBSTUtil(root->right,prev);
	}
	return true;
        }
        bool isBST(Node *root)
        {
	Node *prev=NULL;
	return isBSTUtil(root, prev);
        }
        int main()
        {
	struct Node*root=new Node(200);
	root->left=new Node(6);
	root->left->right=new Node(80);
	root->left->right->left=new Node(9);
	root->left->right->left->left=new Node(7);
        root->left->right->left->right=new Node(30);
        root->left->right->left->right->left=new Node(17);
        root->left->right->left->right->right=new Node(65);
        root->left->right->left->right->right->left=new Node(58);
        root->left->right->right=new Node(100);
	root->left->right->right=new Node(150);
        if (isBST(root))
        cout << "Is BST";
        else
        cout << "Not a BST";
       return 0;
        }
	
    OUTPUT:<BR>
   ![image](https://user-images.githubusercontent.com/97939284/157179442-75fff524-411f-4603-9982-a93c19173bf7.png)

PROGRAM 4:Construct a binary search tree (BST) to support the following operations. 
Given a key, perform a search in the BST. If the key is found then display “key found”.
i.	Insert an element into a binary search tree.
ii.	Delete an element from a binary search tree.
Display the tree using inorder, preorder and post order traversal methods(a). 

	
    # include <iostream> 
    # include <cstdlib> 
    using namespace std; 
    struct node 
    { 
     int info; 
     struct node *left; 
     struct node *right; 
     }*root; 
    class BST 
    { 

    public: 
    
    void find(int, node **, node **); 
    void insert(node *, node *); 
    void del(int); 
    void case_a(node *,node *); 
    void case_b(node *,node *); 
    void case_c(node *,node *); 
    void preorder(node *); 
    void inorder(node *); 
     void postorder(node *); 
    void display(node *, int); 
    BST() 
    { 
    root = NULL; 
    } 
    }; 
    int main() 
    { 
    int choice, num; 
    BST bst; 
    node *temp; 
    while (1) 
    { 
    cout<<"-----------------"<<endl; 
    cout<<"Operations on BST"<<endl; 
    cout<<"-----------------"<<endl; 
    cout<<"1.Insert Element "<<endl; 
    cout<<"2.Delete Element "<<endl; 
    cout<<"3.Inorder Traversal"<<endl; 
    cout<<"4.Preorder Traversal"<<endl; 
    cout<<"5.Postorder Traversal"<<endl; 
    cout<<"6.Display"<<endl; 
    cout<<"7.Quit"<<endl; 
    cout<<"Enter your choice : "; 
    cin>>choice; 
    switch(choice) 
    { 
    case 1: 
    temp = new node; 
    cout<<"Enter the number to be inserted : "; 
    cin>>temp->info; 
    bst.insert(root, temp); 
    break; 
    case 2: 
    if (root == NULL) 
    { 
    cout<<"Tree is empty, nothing to delete"<<endl; 
    continue; 
    } 
    cout<<"Enter the number to be deleted : "; 
     cin>>num; 
    bst.del(num); 
    break; 
    case 3: 
    cout<<"Inorder Traversal of BST:"<<endl; 
    bst.inorder(root); 
    cout<<endl; 
    break; 
    case 4: 
    cout<<"Preorder Traversal of BST:"<<endl; 
    bst.preorder(root); 
    cout<<endl; 
    break; 
    case 5: 
    cout<<"Postorder Traversal of BST:"<<endl; 
    bst.postorder(root); 
    cout<<endl; 
    break; 
    case 6: 
    cout<<"Display BST:"<<endl; 
    bst.display(root,1); 
    cout<<endl; 
    break; 
    case 7: 
    exit(1); 
    default: 
    cout<<"Wrong choice"<<endl; 
    } 
    } 
    } 
    void BST::find(int item, node **par, node **loc) 
    { 
     node *ptr, *ptrsave; 
     if (root == NULL) 
    { 
     *loc = NULL; 
    *par = NULL; 
    return; 
    } 
    if (item == root->info) 
    { 
    *loc = root; 
    *par = NULL; 
    return; 
    } 
    if (item < root->info) 
    ptr = root->left; 
    else 
    ptr = root->right; 
    ptrsave = root; 
    while (ptr != NULL) 
    { 
    if (item == ptr->info) 
    { 
    *loc = ptr; 
    *par = ptrsave; 
     return; 
     } 
    ptrsave = ptr; 
    if (item < ptr->info) 
    ptr = ptr->left; 
    else 
    ptr = ptr->right; 
    } 
    *loc = NULL; 
    *par = ptrsave; 
     } 

    void BST::insert(node *tree, node *newnode) 
    { 
    if (root == NULL) 
    { 
    root = new node; 
    root->info = newnode->info; 
    root->left = NULL; 
    root->right = NULL; 
     cout<<"Root Node is Added"<<endl; 
     return; 
     } 
    if (tree->info == newnode->info) 
     { 
    cout<<"Element already in the tree"<<endl; 
    return; 
    } 
    if (tree->info > newnode->info) 
    { 
    if (tree->left != NULL) 
    { 
    insert(tree->left, newnode); 
    } 
    else 
    { 
    tree->left = newnode; 
    (tree->left)->left = NULL; 
    (tree->left)->right = NULL; 
    cout<<"Node Added To Left"<<endl; 
    return; 
    } 
    } 
    else 
    { 
    if (tree->right != NULL) 
    { 
    insert(tree->right, newnode); 
     } 
    else 
    { 
    tree->right = newnode; 
    (tree->right)->left = NULL; 
    (tree->right)->right = NULL; 
    cout<<"Node Added To Right"<<endl; 
    return; 
    } 
    } 
    } 

    void BST::del(int item) 
    { 
    node *parent, *location; 
    if (root == NULL) 
    { 
    cout<<"Tree empty"<<endl; 
    return; 
    } 
    find(item, &parent, &location); 
    if (location == NULL) 
    { 
    cout<<"Item not present in tree"<<endl; 
    return; 
     } 
    if (location->left == NULL && location->right == NULL) 
    case_a(parent, location); 
    if (location->left != NULL && location->right == NULL) 
    case_b(parent, location); 
    if (location->left == NULL && location->right != NULL) 
    case_b(parent, location); 
    if (location->left != NULL && location->right != NULL) 
    case_c(parent, location); 
    free(location); 
    } 
 

    void BST::case_a(node *par, node *loc ) 
    { 
    if (par == NULL) 
     { 
     root = NULL; 
     } 
    else 
    { 
     if (loc == par->left) 
    par->left = NULL; 
    else 
    par->right = NULL; 
    } 
    } 
 

    void BST::case_b(node *par, node *loc) 
    { 
    node *child; 
    if (loc->left != NULL) 
    child = loc->left; 
    else 
     child = loc->right; 
    if (par == NULL) 
    { 
    root = child; 
    } 
    else 
    { 
    if (loc == par->left) 
     par->left = child; 
    else 
    par->right = child; 
    } 
    } 
 

    void BST::case_c(node *par, node *loc) 
    { 
    node *ptr, *ptrsave, *suc, *parsuc; 
    ptrsave = loc; 
    ptr = loc->right; 
    while (ptr->left != NULL) 
    { 
    ptrsave = ptr; 
    ptr = ptr->left; 
    } 
    suc = ptr; 
    parsuc = ptrsave; 
    if (suc->left == NULL && suc->right == NULL) 
    case_a(parsuc, suc); 
    else 
    case_b(parsuc, suc); 
    if (par == NULL) 
    { 
    root = suc; 
    } 
    else 
     { 
    if (loc == par->left) 
    par->left = suc; 
    else 
    par->right = suc; 
    } 
    suc->left = loc->left; 
    suc->right = loc->right; 
    } 
 
 
    void BST::preorder(node *ptr) 
    { 
    if (root == NULL) 
    { 
    cout<<"Tree is empty"<<endl; 
    return; 
    } 
    if (ptr != NULL) 
    { 
    cout<<ptr->info<<" "; 
    preorder(ptr->left); 
    preorder(ptr->right); 
    } 
    } 

    void BST::inorder(node *ptr) 
    { 
    if (root == NULL) 
    { 
    cout<<"Tree is empty"<<endl; 
    return; 
    } 
    if (ptr != NULL) 
    { 
    inorder(ptr->left); 
    cout<<ptr->info<<" "; 
    inorder(ptr->right); 
    } 
    } 
 
    void BST::postorder(node *ptr) 
     { 
     if (root == NULL) 
    { 
     cout<<"Tree is empty"<<endl; 
    return; 
    } 
    if (ptr != NULL) 
    { 
    postorder(ptr->left); 
    postorder(ptr->right); 
     cout<<ptr->info<<" "; 
     } 
    } 
 
    void BST::display(node *ptr, int level) 
    { 
    int i; 
    if (ptr != NULL) 
    { 
     display(ptr->right, level+1); 
     cout<<endl; 
    if (ptr == root) 
     cout<<"Root->: "; 
    else 
    { 
    for (i = 0;i < level;i++) 
    cout<<" "; 
    } 
    cout<<ptr->info; 
    display(ptr->left, level+1); 
    } 
    }
    
    REDBLACKTREE 
    #include<iostream>
    using namespace std;

    struct node
    {
       int key;
       node *parent;
       char color;
       node *left;
       node *right;
            };
    class RBtree
    {
      node *root;
      node *q;
      public :
      RBtree()
      {
              q=NULL;
              root=NULL;
      }
      void insert();
      void insertfix(node *);
      void leftrotate(node *);
      void rightrotate(node *);
      void del();
      node* successor(node *);
      void delfix(node *);
      void disp();
      void display( node *);
      void search();
      };
      void RBtree::insert()
     {
     int z,i=0;
     cout<<"\nEnter key of the node to be inserted: ";
     cin>>z;
     node *p,*q;
     node *t=new node;
     t->key=z;
     t->left=NULL;
     t->right=NULL;
     t->color='r';
     p=root;
     q=NULL;
     if(root==NULL)
     {
           root=t;
           t->parent=NULL;
     }
     else
     {
         while(p!=NULL)
         {
              q=p;
              if(p->key<t->key)
                  p=p->right;
              else
                  p=p->left;
         }
         t->parent=q;
         if(q->key<t->key)
              q->right=t;
         else
              q->left=t;
     }
     insertfix(t);
     }
     void RBtree::insertfix(node *t)
     {
     node *u;
     if(root==t)
     {
         t->color='b';
         return;
     }
     while(t->parent!=NULL&&t->parent->color=='r')
     {
           node *g=t->parent->parent;
           if(g->left==t->parent)
           {
                        if(g->right!=NULL)
                        {
                              u=g->right;
                              if(u->color=='r')
                              {
                                   t->parent->color='b';
                                   u->color='b';
                                   g->color='r';
                                   t=g;
                              }
                        }
                        else
                        {
                            if(t->parent->right==t)
                            {
                                 t=t->parent;
                                 leftrotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            rightrotate(g);
                        }
           }
           else
           {
                        if(g->left!=NULL)
                        {
                             u=g->left;
                             if(u->color=='r')
                             {
                                  t->parent->color='b';
                                  u->color='b';
                                  g->color='r';
                                  t=g;
                             }
                        }
                        else
                        {
                            if(t->parent->left==t)
                            {
                                   t=t->parent;
                                   rightrotate(t);
                            }
                            t->parent->color='b';
                            g->color='r';
                            leftrotate(g);
                        }
           }
           root->color='b';
     }
    }

    void RBtree::del()
    {
     if(root==NULL)
     {
           cout<<"\nEmpty Tree." ;
           return ;
     }
     int x;
     cout<<"\nEnter the key of the node to be deleted: ";
     cin>>x;
     node *p;
     p=root;
     node *y=NULL;
     node *q=NULL;
     int found=0;
     while(p!=NULL&&found==0)
     {
           if(p->key==x)
               found=1;
           if(found==0)
           {
                 if(p->key<x)
                    p=p->right;
                 else
                    p=p->left;
           }
     }
     if(found==0)
     {
            cout<<"\nElement Not Found.";
            return ;
     }
     else
     {
         cout<<"\nDeleted Element: "<<p->key;
         cout<<"\nColour: ";
         if(p->color=='b')
     cout<<"Black\n";
    else
     cout<<"Red\n";

         if(p->parent!=NULL)
               cout<<"\nParent: "<<p->parent->key;
         else
               cout<<"\nThere is no parent of the node.  ";
         if(p->right!=NULL)
               cout<<"\nRight Child: "<<p->right->key;
         else
               cout<<"\nThere is no right child of the node.  ";
         if(p->left!=NULL)
               cout<<"\nLeft Child: "<<p->left->key;
         else
               cout<<"\nThere is no left child of the node.  ";
         cout<<"\nNode Deleted.";
         if(p->left==NULL||p->right==NULL)
              y=p;
         else
              y=successor(p);
         if(y->left!=NULL)
              q=y->left;
         else
         {
              if(y->right!=NULL)
                   q=y->right;
              else
                   q=NULL;
         }
         if(q!=NULL)
              q->parent=y->parent;
         if(y->parent==NULL)
              root=q;
         else
         {
             if(y==y->parent->left)
                y->parent->left=q;
             else
                y->parent->right=q;
         }
         if(y!=p)
         {
             p->color=y->color;
             p->key=y->key;
         }
         if(y->color=='b')
             delfix(q);
     }
    }

    void RBtree::delfix(node *p)
    {
    node *s;
    while(p!=root&&p->color=='b')
    {
          if(p->parent->left==p)
          {
                  s=p->parent->right;
                  if(s->color=='r')
                  {
                         s->color='b';
                         p->parent->color='r';
                         leftrotate(p->parent);
                         s=p->parent->right;
                  }
                  if(s->right->color=='b'&&s->left->color=='b')
                  {
                         s->color='r';
                         p=p->parent;
                  }
                  else
                  {
                      if(s->right->color=='b')
                      {
                             s->left->color=='b';
                             s->color='r';
                             rightrotate(s);
                             s=p->parent->right;
                      }
                      s->color=p->parent->color;
                      p->parent->color='b';
                      s->right->color='b';
                      leftrotate(p->parent);
                      p=root;
                  }
          }
          else
          {
                  s=p->parent->left;
                  if(s->color=='r')
                  {
                        s->color='b';
                        p->parent->color='r';
                        rightrotate(p->parent);
                        s=p->parent->left;
                  }
                  if(s->left->color=='b'&&s->right->color=='b')
                  {
                        s->color='r';
                        p=p->parent;
                  }
                  else
                  {
                        if(s->left->color=='b')
                        {
                              s->right->color='b';
                              s->color='r';
                              leftrotate(s);
                              s=p->parent->left;
                        }
                        s->color=p->parent->color;
                        p->parent->color='b';
                        s->left->color='b';
                        rightrotate(p->parent);
                        p=root;
                  }
          }
       p->color='b';
       root->color='b';
    }
    }

    void RBtree::leftrotate(node *p)
     {
     if(p->right==NULL)
           return ;
     else
     {
           node *y=p->right;
           if(y->left!=NULL)
           {
                  p->right=y->left;
                  y->left->parent=p;
           }
           else
                  p->right=NULL;
           if(p->parent!=NULL)
                y->parent=p->parent;
           if(p->parent==NULL)
                root=y;
           else
           {
               if(p==p->parent->left)
                       p->parent->left=y;
               else
                       p->parent->right=y;
           }
           y->left=p;
           p->parent=y;
     }
     }
    void RBtree::rightrotate(node *p)
     {
      if(p->left==NULL)
          return ;
     else
     {
         node *y=p->left;
         if(y->right!=NULL)
         {
                  p->left=y->right;
                  y->right->parent=p;
         }
         else
                 p->left=NULL;
         if(p->parent!=NULL)
                 y->parent=p->parent;
         if(p->parent==NULL)
               root=y;
         else
         {
             if(p==p->parent->left)
                   p->parent->left=y;
             else
                   p->parent->right=y;
         }
         y->right=p;
         p->parent=y;
     }
     }

    node* RBtree::successor(node *p)
    {
      node *y=NULL;
     if(p->left!=NULL)
     {
         y=p->left;
         while(y->right!=NULL)
              y=y->right;
     }
     else
     {
         y=p->right;
         while(y->left!=NULL)
              y=y->left;
     }
     return y;
     }

    void RBtree::disp()
    {
     display(root);
     }
     void RBtree::display(node *p)
     {
     if(root==NULL)
     {
          cout<<"\nEmpty Tree.";
          return ;
     }
     if(p!=NULL)
     {
                cout<<"\n\t NODE: ";
                cout<<"\n Key: "<<p->key;
                cout<<"\n Colour: ";
    if(p->color=='b')
     cout<<"Black";
    else
     cout<<"Red";
                if(p->parent!=NULL)
                       cout<<"\n Parent: "<<p->parent->key;
                else
                       cout<<"\n There is no parent of the node.  ";
                if(p->right!=NULL)
                       cout<<"\n Right Child: "<<p->right->key;
                else
                       cout<<"\n There is no right child of the node.  ";
                if(p->left!=NULL)
                       cout<<"\n Left Child: "<<p->left->key;
                else
                       cout<<"\n There is no left child of the node.  ";
                cout<<endl;
    if(p->left)
    {
                 cout<<"\n\nLeft:\n";
     display(p->left);
    }
    /*else
     cout<<"\nNo Left Child.\n";*/
    if(p->right)
    {
     cout<<"\n\nRight:\n";
                 display(p->right);
    }
    /*else
     cout<<"\nNo Right Child.\n"*/
     }
     }
    void RBtree::search()
     {
     if(root==NULL)
     {
           cout<<"\nEmpty Tree\n" ;
           return  ;
     }
     int x;
     cout<<"\n Enter key of the node to be searched: ";
     cin>>x;
     node *p=root;
     int found=0;
     while(p!=NULL&& found==0)
     {
            if(p->key==x)
                found=1;
            if(found==0)
            {
                 if(p->key<x)
                      p=p->right;
                 else
                      p=p->left;
            }
     }
     if(found==0)
          cout<<"\nElement Not Found.";
     else
     {
                cout<<"\n\t FOUND NODE: ";
                cout<<"\n Key: "<<p->key;
                cout<<"\n Colour: ";
    if(p->color=='b')
     cout<<"Black";
    else
     cout<<"Red";
                if(p->parent!=NULL)
                       cout<<"\n Parent: "<<p->parent->key;
                else
                       cout<<"\n There is no parent of the node.  ";
                if(p->right!=NULL)
                       cout<<"\n Right Child: "<<p->right->key;
                else
                       cout<<"\n There is no right child of the node.  ";
                if(p->left!=NULL)
                       cout<<"\n Left Child: "<<p->left->key;
                else
                       cout<<"\n There is no left child of the node.  ";
                cout<<endl;

     }
     }
    int main()
    {
    int ch,y=0;
    RBtree obj;
    do
    {
                cout<<"\n\t RED BLACK TREE " ;
                cout<<"\n 1. Insert in the tree ";
                cout<<"\n 2. Delete a node from the tree";
                cout<<"\n 3. Search for an element in the tree";
                cout<<"\n 4. Display the tree ";
                cout<<"\n 5. Exit " ;
                cout<<"\nEnter Your Choice: ";
                cin>>ch;
                switch(ch)
                {
                          case 1 : obj.insert();
                                   cout<<"\nNode Inserted.\n";
                                   break;
                          case 2 : obj.del();
                                   break;
                          case 3 : obj.search();
                                   break;
                          case 4 : obj.disp();
                                   break;
                          case 5 : y=1;
                                   break;
                          default : cout<<"\nEnter a Valid Choice.";
                }
                cout<<endl;

    }while(y!=1);
    return 1;
    }
    
    OUTPUT:<br>
   ![image](https://user-images.githubusercontent.com/97939284/159217270-955e1b5e-e337-4ddc-99d1-78485b928752.png)
   ![image](https://user-images.githubusercontent.com/97939284/159217616-4750c463-35d6-4f33-b297-0ff8aa245c92.png)
   ![image](https://user-images.githubusercontent.com/97939284/159217830-93b7d6d3-11d5-4bbf-9623-764f8006f1d1.png)
   ![image](https://user-images.githubusercontent.com/97939284/159217923-de970607-da1f-4b4a-ae8c-1ea2ecfc2238.png)
   ![image](https://user-images.githubusercontent.com/97939284/159218017-98de0229-2bc6-49d6-9449-569d9a4d04d9.png)<br>
   ![image](https://user-images.githubusercontent.com/97939284/159218210-1e625d7c-93c0-4132-a628-e08087a0de34.png)
   ![image](https://user-images.githubusercontent.com/97939284/159218315-43bf36b2-a1fb-48e5-adde-2a3ce399bda1.png)
   ![image](https://user-images.githubusercontent.com/97939284/159218439-584f11f2-7355-42f5-80c4-777c84f9c4e6.png)
   
   Write a C++ program for solving the N-Queen’s Problem using backtracking
   
      #include <bits/stdc++.h>
      #define N 4
      using namespace std;
      void printSolution(int board[N][N])
      {
      for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
      cout << " " << board[i][j] << " ";
        printf("\n");
    }
    }
    bool isSafe(int board[N][N], int row, int col)
    {
    int i, j;
 
    
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
 
   
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
    }
    bool solveNQUtil(int board[N][N], int col)
    {
  
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++)
    {
     if (isSafe(board, i, col))
     {
     board[i][col] = 1;
     if (solveNQUtil(board, col + 1))
      return true;
      board[i][col]=0;
      }
      }
    return false;
    }
    bool solveNQ()
    {
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } 
		      };
 
    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }
    printSolution(board);
    return true;
    }
    int main()
    {
    solveNQ();
    return 0;
    }
    
   Write a C++ program to implement merge sort technique using divide and conquer method.
    
    #include <iostream>
    #include<conio.h>
    using namespace std;

    void Merge(int *a, int low, int high, int mid)
    {
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
        j = mid + 1;
        while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
        }
       void MergeSort(int *a, int low, int high)
        {
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
			MergeSort(a, low, mid);
		              MergeSort(a, mid+1, high);
			Merge(a, low, high, mid);
	}
        }
        int main()
        {
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
                           MergeSort(arr, 0, n-1);
		cout<<"\nSorted Data ";
	           for (i = 0; i < n; i++)
                         cout<<"->"<<arr[i];

    return 0;
    } 
    
 OUTPUT:![image](https://user-images.githubusercontent.com/97939284/163926107-a4fbdd38-b594-472d-8170-9e7153605e82.png)
 
 
    #include <iostream>
    using namespace std;
    void MaxHeapify (int a[], int i, int n)
    {
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
    if (j < n && a[j+1] > a[j])
    j = j+1;
    if (temp > a[j])
    break;
    else if (temp <= a[j])
     {
	a[j/2] = a[j];
	j = 2*j;
	}
	}
	a[j/2] = temp;
	return;
	}
	void HeapSort(int a[], int n)
        {
	int i, temp;
	for (i = n; i >= 2; i--)
		{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		MaxHeapify(a, 1, i - 1);
		}
		}
		void Build_MaxHeap(int a[], int n)
		{
			int i;
			for(i = n/2; i >= 1; i--)
				MaxHeapify(a, i, n);
		}
		int main()
		{
		int n, i,arr[100];
		cout<<"\nEnter the number of data element to be sorted: ";
		cin>>n;
		n++;
		for(i=1;i<n;i++)
		 {
		 cout<<"Enter element"<<i<<":";
		 cin>>arr[i];
		 }
		Build_MaxHeap(arr, n-1);
		HeapSort(arr, n-1);
		cout<<"\nSorted Data ";
		for (i = 1; i < n; i++)
		cout<<" "<<arr[i];
		return 0;
		}

OUTPUT:![image](https://user-images.githubusercontent.com/97939284/163927588-36df6b89-59c4-425b-aaeb-5597f55028ea.png)

program 6: Write C++ program for implementing the max Heap and min heap  Sort technique.

     #include <iostream>
    using namespace std;
    void MaxHeapify (int *a, int m, int n) {
    int j, t;
    t = a[m];
    j = 2 * m;
    while (j <= n) {
    if (j < n && a[j+1] > a[j])
    j = j + 1;
    if (t > a[j])
    break;
    else if (t <= a[j]) 
    {
    a[j / 2] = a[j];
    j = 2 * j;
    }
    }
    a[j/2] = t;
    return;
    }
    void MinHeapify (int *a,int i, int n)
    {
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
    if (j < n && a[j+1] < a[j])
    j = j+1;
    if (temp < a[j])
    break;
    else if (temp >= a[j])
    {
    a[j/2] = a[j];
    j = 2*j;
    } 
    }
    a[j/2] = temp;
    return;
    }
			
    /*void HeapSort(int a[], int n)
    {
    int i, temp;
    for (i = n; i >= 2; i--)
    {
				temp = a[i];
				a[i] = a[1];
				a[1] = temp;
				MaxHeapify(a, 1, i - 1);
			}
			} */
			
			void build_maxheap(int *a,int n) {
			 int k;
			 for(k = n/2; k >= 1; k--) {
			  MaxHeapify(a,k,n);
			  }
			}
			void Build_MinHeap(int *a, int n)
			{
			int i;
			for(i = n/2; i >= 1; i--)
			{
			
				MinHeapify(a, i, n);
			}
			
			}
			
			int main()
			{
			    int n, i,arr[100];
			cout<<"\nEnter the number of data element to be sorted: ";
			cin>>n;
			//n++;
			for(i=1;i<=n;i++)
			 {
			 cout<<"Enter element"<<i<<":";
			 cin>>arr[i];
			 }
			 
			 
			Build_MinHeap(arr, n);
			cout<<"\nMin heap Sorted Data \n";//correct
			for (i = 1; i <= n; i++)
			{
			
				cout<<" "<<arr[i];
			}
			
			  build_maxheap(arr,n-1);
			  cout<<"\nMax heap Sorted Data \n";
			 for (i = 1; i <= n; i++) 
			 {
			  cout<<" "<<arr[i];
			 }
			}

OUTPUT:![image](https://user-images.githubusercontent.com/97939284/163935872-dc44185e-d7d3-41c3-9fbe-d32568eababd.png)

Write a C++ program to find subset of a given sets.
   
     #include <iostream>
     #include<stack>
     using namespace std;
     int set[]={4,6,3,7,5,8,1};
     int numberOfElements=7,sum=11;
     class Subset
     {
	public:
		stack<int> solutionSet;
		bool hasSolution;
		void solve(int s,int idx)
		{
			if(s>sum)
			return;
			if(s==sum)
			{
				hasSolution=true;
				displaySolutionSet();
				return;
				
			}
			for(int i=idx;i<numberOfElements;i++)
			{
				solutionSet.push(set[i]);
				solve(s+set[i],i+1);
				solutionSet.pop();
			}
		}
		void displaySolutionSet()
		{
			stack<int> temp;
			while(!solutionSet.empty())
			{
				cout<<solutionSet.top()<<" ";
				temp.push(solutionSet.top());
				solutionSet.pop();
			}
			cout<< '\n';
			while(!temp.empty())
			{
				solutionSet.push(temp.top());
				temp.pop();
				
			}
		}
      };
       int main()
       {
	Subset ss;
	ss.solve(0,0);
	if(ss.hasSolution==false)
	cout<<"no solution";
	return 0;
	
      }
      
  OUTPUT:![image](https://user-images.githubusercontent.com/97939284/163941798-d876504d-712d-48bc-a224-c949dae2436d.png)
  
    #include<iostream>
    using namespace std;
    int grid[100][100];
    //print the solution
    void print(int n) 
    {
    for (int i = 0;i <= n-1; i++) 
    {
    for (int j = 0;j <= n-1; j++)
    {
		           cout <<grid[i][j]<< " ";
		           
		        }
		        cout<<endl;
		    }
		    cout<<endl;
		    cout<<endl;
		}
		//function for check the position is safe or not
		//row is indicates the queen no. and col represents the possible positions
		bool isSafe(int col, int row, int n) 
		{
		  //check for same column
		    for (int i = 0; i < row; i++) 
			{
		        if (grid[i][col]) 
				{
		            return false;
		        }
		    }
		    //check for upper left diagonal
		    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) 
			{
		        if (grid[i][j]) 
				{
		            return false;
		        }
		    }
		    //check for upper right diagonal
		    for (int i = row, j = col; i >= 0 && j < n; j++, i--) 
			{
		        if (grid[i][j]) 
				{
		            return false;
		        }
		    }
		    return true;
		}
		//function to find the position for each queen
		//row is indicates the queen no. and col represents the possible positions
		bool solve (int n, int row) 
		{
		    if (n == row) 
			{
		        print(n);
		        return true;
		    }
		    //variable res is use for possible backtracking
		    bool res = false;
		    for (int i = 0;i <=n-1;i++) 
			{
		        if (isSafe(i, row, n)) 
				{
		            grid[row][i] = 1;
		            //recursive call solve(n, row+1) for next queen (row+1)
		            res = solve(n, row+1) || res;//if res ==false then backtracking will occur
		            //by assigning the grid[row][i] = 0
		           
		            grid[row][i] = 0;
		        }
		    }
		    return res;
		}
		int main()
		{
		  ios_base::sync_with_stdio(false);
		    cin.tie(NULL);
		        int n;
		        cout<<"Enter the number of queen"<<endl;
		        cin >> n;
		        for (int i = 0;i < n;i++)
		            for (int j = 0;j < n;j++) 
					{
		                grid[i][j] = 0;
		            }
		        
		        bool res = solve(n, 0);
		        if(res == false) 
				{
		            cout << -1 << endl; //if there is no possible solution
		        } else 
				{
		            cout << endl;
		        }
		  return 0;
		}
	

	  #include<iostream>
		using namespace std;
		int grid[100][100];
		//print the solution
		void print(int n) 
		{
		    for (int i = 0;i <= n-1; i++) 
			{
		        for (int j = 0;j <= n-1; j++)
				{
		           
		                cout <<grid[i][j]<< " ";
		           
		        }
		        cout<<endl;
		    }
		    cout<<endl;
		    cout<<endl;
		}
		//function for check the position is safe or not
		//row is indicates the queen no. and col represents the possible positions
		bool isSafe(int col, int row, int n) 
		{
		  //check for same column
		    for (int i = 0; i < row; i++) 
			{
		        if (grid[i][col]) 
				{
		            return false;
		        }
		    }
		    //check for upper left diagonal
		    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) 
			{
		        if (grid[i][j]) 
				{
		            return false;
		        }
		    }
		    //check for upper right diagonal
		    for (int i = row, j = col; i >= 0 && j < n; j++, i--) 
			{
		        if (grid[i][j]) 
				{
		            return false;
		        }
		    }
		    return true;
		}
		//function to find the position for each queen
		//row is indicates the queen no. and col represents the possible positions
		bool solve (int n, int row) 
		{
		    if (n == row) 
			{
		        print(n);
		        return true;
		    }
		    //variable res is use for possible backtracking
		    bool res = false;
		    for (int i = 0;i <=n-1;i++) 
			{
		        if (isSafe(i, row, n)) 
				{
		            grid[row][i] = 1;
		            //recursive call solve(n, row+1) for next queen (row+1)
		            res = solve(n, row+1) || res;//if res ==false then backtracking will occur
		            //by assigning the grid[row][i] = 0
		           
		            grid[row][i] = 0;
		        }
		    }
		    return res;
		}
		int main()
		{
		  ios_base::sync_with_stdio(false);
		    cin.tie(NULL);
		        int n;
		        cout<<"Enter the number of queen"<<endl;
		        cin >> n;
		        for (int i = 0;i < n;i++)
		            for (int j = 0;j < n;j++) 
					{
		                grid[i][j] = 0;
		            }
		        
		        bool res = solve(n, 0);
		        if(res == false) 
				{
		            cout << -1 << endl; //if there is no possible solution
		        } else 
				{
		            cout << endl;
		        }
		  return 0;
		}
					 

 







    




	
	
	
 
	
	

   
   
   
   


         
			
					
