num = 13

def brute(num):
	if(num == 1):
		return 0
	if(num%3==0):
		temp = brute(num/2)
	if(num%2==0):
		ops = brute(num/3)
	return temp if temp > ops else ops

brute(10)
