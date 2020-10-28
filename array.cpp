/* 
** array and vector
*/

#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

int main()
{
    std::cout << std::boolalpha;            //bool(true, false),  noboolalpha bool(1,0)  
    //empty array 
    std::array <int,0> empty;           
    std::cout <<"1)"
              <<(empty.begin() == empty.end()) <<' '
              <<(empty.cbegin() == empty.cend()) <<'\n';   

    std::array <int,4> numbers = {1, 2, 3, 4};

    //at (begin from 0)
    numbers.at(1) = 88;         //Set value
    int i = numbers.at(2);          //Read value
    try{                        //Edge check
        numbers.at(5) = 666;
    }catch(std::out_of_range const& exc){
        std::cout<<exc.what()<<'\n';
    }

    //operator[]    operator[5] undefined behavior
    i = numbers[1];        //Read value
    numbers[0] = 55;        //Set value

    //front & back
    i = numbers.front();        // == *numbers.begin()
    i = numbers.back();         // == *std::prev(numbers.end())

    //data
    i = *numbers.data();        //return pointer point to the address

    //begin, cbegin & end, cend, &rbegin, crbegin &rend, crend
    //return a iterator

    //empty 
    std::cout << numbers.empty()<<'\n';   //return bool

    //size
    int arraysize;
    std::cout << numbers.size()<<std::endl;          //size return the size of array.

    //max_size
    std::cout << numbers.max_size();    //return the array length N

    //fill
    numbers.fill({});

    //swap
    //a1.swap(a2);      

    //== & != & < & <= & > & >=             //return bool

    //std::get
    std::get<0>(numbers) = 66;          //set value
    std::cout << std::get<0>(numbers);      //get value

    //std::to_array
    //auto a1 = std::to_array<long>({3,4});     
    //auto a2 = std::to_array("foo");   // == std::array<char, 4>{'f','o','o','\0'}  

    //std::swap
    //std::swap(a1,a2);       //a1.size() == a2.size() same type

    //std::tuple_element
    std::array<int, 10>data {0,1,2,3,4,5,6,7,8,9};
    using T = std::tuple_element<0, decltype(data)>::type; //int

    std::cout << numbers.front() <<numbers.back()<<std::endl;       //空容器上front调用未定义
    std::cout << "2)"
              <<(numbers.begin() == numbers.end())<<' '
              <<(numbers.cbegin() == numbers.cend())<<'\n'
              << "3)"
              << *(numbers.begin()) << ' '
              << *(numbers.end()) << '\n';
        *numbers.begin() = 5;
    std::cout <<"4)" << *(numbers.begin()) << '\n';
    std::cout <<"5)";
    std::for_each(numbers.cbegin(),numbers.cend(),[](int x){std::cout <<x <<' ';});
    std::cout <<'\n';


}