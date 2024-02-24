n = int(input())
sum = int(input())
val = input()

vallist = val.split()
res = [eval(i) for i in vallist]
res.sort(reverse = True)

num = [0]*n

i = 0
for ele in res:
    num[i] = int(sum/ele)
    sum = sum - (ele *num[i])
    i += 1

total = 0

for ele in num:
    total += ele

if sum == 0:
    print(total)
else :
    print("Not Possible")