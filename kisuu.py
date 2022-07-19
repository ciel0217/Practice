str1 = str(input())
str2 = str(input())
n = int(input())
for i in range(len(str1)-n+1):
	print(str1[i:i+n])

