N,M = map(int, input().split())
d,b = [],[]

for i in range(N):
    name = input()
    d.append(name)

for i in range(M):
    name = input()
    b.append(name)


s1 = set(d)
s2 = set(b)

s3 = s1 & s2


print(len(s3))


for i in sorted(s3):
    print(i)
