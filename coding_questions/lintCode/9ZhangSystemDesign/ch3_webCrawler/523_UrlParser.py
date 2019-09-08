'''
Url Parser 

 Description
 Notes
 Testcase
 Judge
Parse a html page, extract the Urls in it.

Hint: use regex to parse html.

Have you met this question in a real interview? Yes
Example
Given the following html page:

<html>
  <body>
    <div>
      <a href="http://www.google.com" class="text-lg">Google</a>
      <a href="http://www.facebook.com" style="display:none">Facebook</a>
    </div>
    <div>
      <a href="https://www.linkedin.com">Linkedin</a>
      <a href = "http://github.io">LintCode</a>
    </div>
  </body>
</html>
You should return the Urls in it:

[
  "http://www.google.com",
  "http://www.facebook.com",
  "https://www.linkedin.com",
  "http://github.io"
]
'''
class HtmlParser:
    # @param {string} content source code
    # @return {string[]} a list of links
    def parseUrls(self, content):
        # Write your code here
        import re
        links = re.findall(r'\s*(?i)href\s*=\s*"?\'?([^"\'>\s]*)', content, re.I)
        links = [link for link in links]
        return list(links)