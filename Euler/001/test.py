for i in range(1000):
	try:
		if i/(i%2):
			continue
	except:
		print(i)