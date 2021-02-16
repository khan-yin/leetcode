import math

n = input()
s = input()

a = "1"
for i in range(int(n)):
    ans = ""
    for item in a:
        item = int(item)
        temp = int(math.pow(2,item))
        temp = str(temp)
        
        ans += temp
    a = ans
    # print(a)

print(a.count(s))

