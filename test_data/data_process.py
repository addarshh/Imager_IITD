with open('fc1.txt','r') as f:
	test_str = ""
	message = f.readline()
	# String temp_str = ""
	while message:
		flag = False
		for elem in message:
			if (elem == "\n"):
				elem = ""	
			if (elem == "]"):
				elem = ""
				flag = True
			if (elem == "["):
				flag = False
				elem = ""
			# if (elem == "]"):
			# 	message = f.readline()
			if (elem == "\t"):
				elem = "\n"
			if (elem == " "):
				if (flag):
					elem = ""
				else : 
					elem = "\n"

			test_str = test_str + elem
		print(test_str)


		file1 = open("output_fc1.txt",'w')
		message = f.readline()
	file1.writelines(test_str)
exit()