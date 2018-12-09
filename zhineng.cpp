#include<iostream>
using namespace std;
class safepointer{
public :
    explicit safepointer(int v):m_value (new int(v)),m_used(1){}
    //not the thread safty
    ~safepointer(){
        m_used-- ;
        if(m_used<=0)
            delete m_value;
        }
    int *get(){return m_value ;}
private:
    int m_used ;
    int * m_value ;    
};
//shared_ptr //xi sheng xiao lv , que xian
int main(){

}

/*
template&lt;typename FriendClass, typename DataType&gt;
class PtrCount
{
	friend FriendClass;
	PtrCount(DataType* _p):p(_p),use(1){}
	~PtrCount(){delete p;}
	DataType* p;
	size_t use;
};
 
template&lt;typename DataType&gt;
class SmartPtr
{
public:
	SmartPtr(DataType *p)
		:m_ref(new PtrCount&lt;SmartPtr, DataType&gt;(p))
	{
	}
 
	SmartPtr(const SmartPtr &amp;orig)
		:m_ref(orig.m_ref)
	{
		++m_ref-&gt;use;
	}
 
	SmartPtr&amp; operator=(const SmartPtr &amp;rhs)
	{
		++rhs.m_ref-&gt;use;
		if (--m_ref-&gt;use == 0)
			delete m_ref;
		m_ref = rhs.m_ref;
		return *this;
	}
 
	~SmartPtr()
	{
		if (--m_ref-&gt;use == 0)
			delete m_ref;
	}
 
private:
	PtrCount&lt;SmartPtr, DataType&gt;* m_ref;
};
 
*/