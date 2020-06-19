## C++ Regex

```C++
#include <regex>
#include <string>

int main()
{
    std::regex rx ("\\d+");
    std::regex_search("12345abc1234", rx, std::regex_constants::match_continuous));
    std::regex_search("abc12345", rx, std::regex_constants::match_continuous));
    return 0;
}
```