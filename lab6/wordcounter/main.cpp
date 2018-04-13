#include <WordCounter.h>
#include <iostream>

using namespace datastructures;
using namespace std;

int main()
{
    WordCounter counter {Word("a"), Word("p"), Word("a"), Word("a"), Word("hi"), Word("voltage")};
    cout<<counter;
    return 0;
}
