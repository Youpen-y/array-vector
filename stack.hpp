/* Implement a stack class template */
#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;

template <typename T>
class Stack{
    private:
        std::vector<T> elems;   //store elements in vector container.

    public:
        Stack(){
            elems=0;
        }          //default constructor
        void push(T const&);       //push a element into stack
        void pop();                 //pop a element out of stack
        T top() const;          //return top element of stack
        bool empty() const{         //return if a stack is empty
            return elems.empty();
        }
};

template<typename T>
void Stack<T>::push(T const& e_em)
{
    elems.push_back(e_em);
}

template<typename T>
void Stack<T>::pop()
{
    if(elems.empty()){
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();   
}

template<typename T>
T Stack<T>::top() const
{
    if(elems.empty()){
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back();
}
