class Test:
	def __init__(self,lst):
		self._lst = lst
		self._num=0
		self._len = len(self._lst)
		self._index = 0
	def __iter__(self):
		return  self

	def __next__(self):
		if self._index < self._len :
			self._num=self._lst[self._index]*2
			self._index += 1
			return self._num
		else:
			raise StopIteration

lst= [0,1,2,3,4]
a = Test(lst)
print(list(a))
