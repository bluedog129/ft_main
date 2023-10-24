#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    // Test with list
    std::cout << "Test with list" << std::endl;
    std::list<int> listMstack;
    listMstack.push_back(5); // push() becomes push_back()
    listMstack.push_back(17);

    std::cout << listMstack.back() << std::endl; // top() becomes back()

    listMstack.pop_back();

    std::cout << listMstack.size() << std::endl;

    listMstack.push_back(3);
    listMstack.push_back(5);
    listMstack.push_back(737);
    //[...]
    listMstack.push_back(0);

    std::list<int>::iterator listIt = listMstack.begin();
    std::list<int>::iterator listIte = listMstack.end();
    ++listIt;
    --listIt;
    while (listIt != listIte)
    {
        std::cout << *listIt << std::endl;
        ++listIt;
    }
    std::list<int> listS(listMstack);

    // reverse iterator
    std::cout << "reverse iterator" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    ++rit;
    --rit;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    // const iterator
    std::cout << "const iterator" << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
    ++cit;
    --cit;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }

    // insert const iterator element
    std::cout << "insert const iterator element" << std::endl;
    MutantStack<int>::const_iterator cit2 = mstack.begin();

    while (cit2 != cite)
    {
        std::cout << *cit2 << std::endl;
        
        // *cit2 = 42;  // this line will cause error 
        ++cit2;
    }

    return 0;
}
