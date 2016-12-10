//
// Created by lishion on 2016/12/7.
//

#ifndef I_PTR_I_PTR_H
#define I_PTR_I_PTR_H

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class i_ptr {

public:

    i_ptr(T *p):ptr(p){ refCount = new int(1); };
    i_ptr(){ refCount = new int(1);ptr = nullptr; };
    void setPtr(const i_ptr &_ptr)
    {
            ptr = _ptr.ptr;
            refCount = _ptr.refCount;
            ( *refCount ) ++;
            cout<<"value: "<< ( ptr== nullptr ?"nullptr":(*ptr) ) <<"---reference :"<< *refCount<<endl;
    }

    i_ptr(const i_ptr &_ptr)//拷贝构造函数
    {
        setPtr(_ptr);
    }

    void operator=(const i_ptr &_ptr)//赋值运算符
    {
        if( ptr != _ptr.ptr )
        {
            if( (*refCount) ==  1 )//如果只存在一个引用 则释放该引用指向的内存
            {
                delete refCount;
                delete ptr;
            }
            else
            {
                (*refCount)--;//如果存在多个引用 则将引用计数减1
            }
            setPtr(_ptr);
        }
    }

    T* operator->()
    {
        if(ptr == nullptr){cout<<ERROR_INFO<<endl;exit(1);};
        return ptr;
    }

    T operator*()
    {
        if(ptr== nullptr){cout<<ERROR_INFO<<endl;exit(1);};
        return  *ptr;
    }

    T* get()
    {
        if(ptr == nullptr){cout<<ERROR_INFO<<endl;exit(1);};
        return ptr;
    }

    ~i_ptr()
    {
        ( *refCount )-- ;
        cout<<"value: "<< ( ptr== nullptr ?"nullptr":(*ptr) ) <<"---reference :"<< *refCount<<endl;
        if( *refCount == 0)
        {
            delete ptr;
            delete refCount;
            refCount = nullptr;
            ptr = nullptr;
            cout<<"all reference have been deleted!"<<endl;
        }

    }

private:
    T *ptr;
    const string ERROR_INFO = "Null Pointer Error!!!!";
    int *refCount;
};



#endif //I_PTR_I_PTR_H
