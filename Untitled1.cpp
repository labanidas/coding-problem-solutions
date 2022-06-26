#include<bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* Structure of linked list Node

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method

Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    int size1=0,size2=0;
    Node* temp1=l1, *temp2=l2;
    while(temp1!=NULL){
        temp1=temp1->next;
        size1++;
    }
//    cout<<size1<<endl;
    while(temp2!=NULL){
        temp2=temp2->next;
        size2++;
    }
//     cout<<size2<<endl;
    temp1=l1; temp2=l2;
    int num1=0,num2=0;
    while(size1!=0){
        num1+=temp1->data*pow(10,size1-1);
        temp1=temp1->next;
        size1--;
    }
//    cout<<num1<<endl;
    while(size2!=0){
        num2+=temp2->data*pow(10,size2-1);
//        cout<<"temp 2"<<temp2->data<<endl;
        temp2=temp2->next;
        size2--;
    }
//    cout<<num2<<endl;
    
    //answer
    int ans=0;
    if(num1>=num2) ans=num1-num2;
    else ans=num2-num1;
    
//    cout<<"ans "<<ans<<endl;
    int size=ceil(log10(ans));
    int arr[size];
//    cout<<"size "<<size<<endl;
	    for(int i=size-1;i>=0;i--){
        arr[i]=ans%10;
        ans=ans/10;
//        cout<<arr[i]<<" ";
    }
    
    Node *head=new Node(arr[0]);
    Node *temp=head;
    for(int i=1;i<size;i++){
        temp->next=new Node(arr[i]);
        temp=temp->next;
    }
    return head;
    
}
