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

4. using getline function
```c++
std::vector<std::string> split(const std::string& s, char delimiter){
    std::vector<std::string> splits;
    std::string split;
    std::istringstream ss(s);
    while (std::getline(ss, split, delimiter){
        splits.push_back(split);
    }

    return splits;
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

## C++ Transfer String to lower/upper Case
```c++
// Functions used :
// transform : Performs a transformation on given array/string.
// toupper(int c) : Returns upper case version of character c. If c is already in uppercase, return c itself.
// tolower(int c) : Returns lower case version of character c. If c is already in lowercase, return c itself.

int main(){ 
    std::string s = "ABcDeFgH"
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::cout << s << std::endl;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    std::cout << s << std::endl;

    return 0;
}
```


