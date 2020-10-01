#include<iostream>
using namespace std;

template<class T>
class Deque
{
    public: T* a;
            long long int capacity;
            long long int front,rear;
            long long int count=0;
    
    public: Deque()
            {
                a=new T[5];
                capacity=5;
                front=-1;
                rear=-1;
                count=0;
            }

            Deque(long long int n, T x)
            {
                a=new T[n];
                for(long long int i=0;i<n;i++)
                {
                    a[i]=x;
                }
                front=0;
                rear=n-1;
                capacity=n;
                count=n;
            }

            void push_back(T x)
            {
                if((rear+1)%capacity==front)  //when deque is full
                {
                    T* t = new T[2*capacity];
                    long long int z=front;
                    long long int k=0;
                    for(long long int i=z;(i!=rear);(i=(i+1)%capacity))
                    {
                        t[k]=a[i];
                        k++;
                    }
                    t[k]=a[rear];
                    front=0;
                    rear=k;
                    delete[] a;
                    capacity=capacity*2;
                    a=t;
                    rear++;
                    a[rear]=x;
                    count=count+1;
                }
                else if(front==-1 && rear==-1) //when deque is empty
                {
                    front++;
                    rear++;
                    a[rear]=x;
                    count++;
                }
                else  //when deque is neither full nor empty
                {
                    rear=(rear+1)%capacity;
                    a[rear]=x;
                    count++;
                }
            }

            void pop_back()
            {
                
                if(front==-1 && rear==-1) // when deque is empty
                {
                    cout<<"Deque is Empty"<<endl;
                }
                else if(front==rear) //when deque has only one element
                {
                    rear=-1;
                    front=-1;
                    count=0;
                }
                else //normal case
                {
                    if(rear==0)
                    {
                        rear=capacity-1;
                    }
                    else rear--;
                    count--;
                }
            }

            void push_front(T x)
            {
                if((rear+1)%capacity==front) //when deque is full
                {
                    T* t = new T[2*capacity];
                    long long int z=front;
                    long long int k=0;
                    for(long long int i=z;i!=rear;(i=(i+1)%capacity))
                    {
                        t[k]=a[i];
                        k++;
                    }
                    t[k]=a[rear];
                    front=0;
                    rear=k;
                    delete[] a;
                    a=t;
                    capacity=capacity*2;
                    if(front==0)
                    {
                        front = capacity-1;
                    }
                    else front--;
                    
                    a[front]=x;
                    count=count+1;
                }
                else if(front==-1 && rear==-1)  // when deque is empty
                {
                    front++;
                    rear++;
                    a[front]=x;
                    count++;
                }
                else //normal case
                {
                    if(front==0)
                    {
                        front = capacity-1;
                    }
                    else front--;
                    a[front]=x;
                    count++;
                }
            }

            void pop_front()
            {
                if(front==-1 && rear==-1) // when deque is empty
                {
                    cout<<"Deque is Empty"<<endl;
                }
                else if(front==rear) //when deque has only one element
                {
                    rear=-1;
                    front=-1;
                    count=0;
                }
                else //normal case
                {
                    front=(front+1)%capacity;
                    count--;
                }
            }

            T Front()
            {
                return a[front];
            }

            T back()
            {
                return a[rear];
            }

            bool empty()
            {
                if(front==-1 && rear==-1)
                    return true;
                return false;
            }

            long long int size()
            {
                if(front == -1 && rear==-1)
                    return 0;
                else if(front==rear)
                    return 1;
                else 
                {
                    return count;
                }
            }

            void resize(long long int x, T d)
            {
                long long int s=size();
                if(empty()){
                    T* temp=new T[x];
                    for(int i=0; i<x; i++){
                        temp[i] = d;
                    }
                    delete[] a;
                    a=temp;
                    front=0;
                    rear=x-1;
                    count=x;
                    capacity=x;
                }
                else if(x<s)
                {
                    T* temp=new T[x];
                    long long int z=front;
                    for(long long int i=0;i<x;i++)
                    {
                        temp[i]=a[z];
                        z=(z+1)%capacity;
                    }
                    delete[] a;
                    a=temp;
                    front=0;
                    rear=x-1;
                    count=x;
                    capacity=x;
                }
                else if(x>s)
                {
                    T* temp=new T[x];
                    long long int z=0;
                    for(long long int i=front;i!=rear;i=(i+1)%capacity)
                        {
                            temp[z]=a[i];
                            z++;
                        }
                    temp[z]=a[rear];
                    delete[] a;
                    a=temp;
                    front=0;
                    rear=z;
                    capacity=x;
                    count=s;
                    for(long long int p=z+1;p<x;p++)
                    {
                        a[p]=d;
                    }
                    rear=x-1;
                    count=x;
                }
            }

            void clear()
            {
                T* temp=new T[10];
                delete[] a;
                a=temp;
                capacity=10;
                front=-1;
                rear=-1;
                count=0;
            }

            T &operator[](long long int i)
            {
                long long int s=size();
                long long int index=((front+i)%capacity);    
                return a[index];
            }


            void display()
            {
                for(long long int i=front;i!=rear;i=(i+1)%capacity)
                {
                    cout<<a[i]<<" ";
                }
                cout<<a[rear]<<endl;
            }
};




int main()
{ 
Deque<string> *arr =NULL;
    int Q,c,n;
    string x;
    cin>>Q;
    while (Q--){      
 
 cin>>c;

 switch (c)
 {
//push-front
 case 1: cin>>x;
         arr->push_front(x);  
         arr->display();

         break;
//pop-front
 case 2: arr->pop_front();
         arr->display();
         break;
 //push-back
 case 3: cin>>x;
         arr->push_back(x);
         arr->display();
         break;
 
 //pop-back
 case 4: arr->pop_back();
         arr->display();
         break;
 
 //deque constructor calling
 case 5: if(arr !=NULL)
         delete arr;
         arr = new Deque<string>();
         break;

//paramatrised constructor calling
 case 6: cin>>n>>x;
         if(arr !=NULL)
         delete arr;
         arr = new Deque<string>(n,x);
         arr->display();
         break;

//get the front element
 case 7: cout<<arr->Front()<<endl;
         break;

//get the back element
 case 8: cout<<arr->back()<<endl;
         break;
 
 //check empty
 case 9: if(arr->empty())
          cout<<"true\n";
         else
          cout<<"false\n";
         break;

//print size
 case 10: cout<<arr->size()<<endl;
          break;

//resize the deque
 case 11: cin>>n>>x;
          arr->resize(n,x);
          arr->display();
          break;

//clear the dequq
 case 12: arr->clear();
          break;
 
 //get the value at an index
 case 13: cin>>n;
          cout<<(*arr)[n]<<endl;
          break;
//display the dequq
 case 14: arr->display();
         break;

 default:
     break;
 }
    }


delete arr;
return 0;
}

