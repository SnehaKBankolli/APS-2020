  
from sys import maxsize 
  


def maxSubArraySum(a,size): 
  
    l=[]
    max_so_far = -float('inf')
    max_ending_here = 0
    start = 0
    end = 0
    s = 0
  
    for i in range(0,size): 
  
        max_ending_here += a[i] 
  
        if max_so_far < max_ending_here: 
            max_so_far = max_ending_here 
            start = s 
            end = i 
  
        if max_ending_here < 0: 
            max_ending_here = 0
            s = i+1
    
            
    l.append(start)
    l.append(end)
    if max_so_far==-float('inf'):
        max_so_far=0
    print(max_so_far)
    return l 
  
# Driver program to test maxSubArraySum 

n=int(input())
a=[int(o) for o in input().split()]
z=maxSubArraySum(a,n)

b=[]
for i in range(0,n):
    if i<z[0] or i>z[1]:
        b.append(a[i])

maxSubArraySum(b,len(b))



