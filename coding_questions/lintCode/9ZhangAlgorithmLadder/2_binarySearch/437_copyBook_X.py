/*
Copy Books

Given n books and the ith book has A[i] pages. You are given k people to copy the n books.

n books list in a row and each person can claim a continous range of the n books. For example one copier can copy
 the books from ith to jth continously, but he can not copy the 1st book, 2nd book and 4th book (without 3rd book).

They start copying books at the same time and they all cost 1 minute to copy 1 page of a book. What's the best 
strategy to assign books so that the slowest copier can finish at earliest time?
*/


class Solution:
    # @param pages: a list of integers
    # @param k: an integer
    # @return: an integer
    def copyBooks(self, pages, k):
        # write your code here
        n = len(pages)
        if (k>n): k = n
        if n == 0:
            return 0
        sum = []
        for i in xrange(n): sum.append(0)
        sum[0] = pages[0]
        for i in xrange(1, n): sum[i] = sum[i-1]+pages[i]
        f = []        
        for i in xrange(n):
            f.append([])
            for j in xrange(k): f[i].append(0)
        for i in xrange(n): f[i][0] = sum[i];
        for j in xrange(1, k):
            p = 0
            f[0][j] = pages[0]
            for i in xrange(1, j): f[i][j] = max(f[i-1][j], pages[i]) 
            for i in xrange(j, n):
                while (p<i and f[p][j-1]<sum[i]-sum[p]): p += 1
                f[i][j] = max(f[p][j-1], sum[i]-sum[p])               
                if (p>0): p -= 1
                f[i][j] = min(f[i][j], max(f[p][j-1], sum[i]-sum[p]))         
        return f[n-1][k-1]