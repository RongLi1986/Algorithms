## C++ Split String 

1. Put it in a stringstream and extract the tokens
```c++
template <class Container>
void split1(const std::string& str, Container& cont)
{
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         std::back_inserter(cont));
}
```

2. Use string::find progressively
```c++
template <class Container>
void split2(const std::string& str, Container& cont,
              char delim = ' ')
{
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}
```

3. Use my C split function
```c++
template <class Container>
void add_to_container(const char *str, size_t len, void *data)
{
    Container *cont = static_cast<Container*>(data);
    cont->push_back(std::string(str, len));
}
 
template <class Container>
void split3(const std::string& str, Container& cont, char delim = ' ')
{
    split(str.c_str(), delim, static_cast<split_fn>(add_to_container<Container>), &cont);
}
```

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
 
int main()
{
    char str[] = "The quick brown fox jumps over the lazy dog";
    std::vector<std::string> words;
    split1(str, words);
    std::copy(words.begin(), words.end(),
         std::ostream_iterator<std::string>(std::cout, "\n"));
}
```