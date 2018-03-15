import matplotlib.pyplot as plt
import pandas as pd

fileName = ['MAXN', 'MAXQ', 'MAXP_CORE_ALL', 'MAXP_CORE_ARM', 'MAXP_CORE_DENVER']

color = ['red', 'orange', 'purple', 'green', 'blue']

for i in range(0, len(fileName)): 
	df = pd.read_csv('result/' + fileName[i] + '/vips.csv', sep=';', header=None)
	arrX = []
	arrY = []
	for j in range(1, len(df[0])):
		temp=df[0][j]
		arr2 = temp.split("m ")
		arr3 = arr2[1].split("s ")
		second = int(arr2[0]) * 60 + int(arr3[0])
		if len(arr3[1]) == 3:
			milisec = float(str(second) + '.' + str(arr3[1])) 
		elif len(arr3[1]) == 2:
			milisec = float(str(second) + '.0' + str(arr3[1])) 
		elif len(arr3[1]) == 1:
			milisec = float(str(second) + '.00' + str(arr3[1])) 
		else:
			milisec = float(str(second) + '.000') 
		if j == 1:
			first = milisec
		arrX.append(milisec - first)
		arrY.append(int(df[15][j]))
	plt.plot(arrX, arrY, color[i])

plt.show()
