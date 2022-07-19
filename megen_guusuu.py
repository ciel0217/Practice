
class Test:
	def __init__(self,x):
		self.x=x

	def __iter__(self):
		return self

	def __next__(self):
		num = self.x
		self.x += 2
		return num

a = Test(0)
for i in a:
	print(i)