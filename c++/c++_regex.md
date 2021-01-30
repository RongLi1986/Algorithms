## C++ Regex

```C++
#include <regex>
#include <string>

int main()
{
    //regex match
    std::regex rx ("\\d+");
    std::regex_search("12345abc1234", rx, std::regex_constants::match_continuous));
    std::regex_search("abc12345", rx, std::regex_constants::match_continuous));

    //regex replace
    std::regex e (" ");
    std::string number = "123 456";    
    
    number = std::regex_replace (number, e, "");
    std::cout<<number<<std::endl;

    return 0;
}
```