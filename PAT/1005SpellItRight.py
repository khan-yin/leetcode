a=input()
sum=0
for i in a:
    sum+=int(i)
# print(sum)

sum=str(sum)

dict={
    "0":"zero",
    "1":"one",
    "2":"two",
    "3":"three",
    "4":"four",
    "5":"five",
    "6":"six",
    "7":"seven",
    "8":"eight",
    "9":"nine"
}
flag=True
for i in sum:
    if flag:
        print(dict[i],end="")
        flag=False
    else:
        print(" "+dict[i],end="")
print()