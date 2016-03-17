import random
import string
import math
import operator
numbers = 100000
ops = 100000
operators = ["i", "g", "h", "d", "e", "f"]
ip = ""
output = ""
elements = [];
for i in range(0, ops):
	if len(elements) == 0:
		command = "i"
	else:
		command = operators[random.randrange(0, 6)]
	ip += command
	if command == "i":
		num = random.randrange(0, numbers)
		ip += " " + str(num)
		elements.append(num)
	elif command == "g":
		output += str(max(elements)) + "\n"
	elif command == "h":
		output += str(min(elements)) + "\n"
	elif command == "d":
		val = max(elements)
		elements.remove(val)
	elif command == "e":
		val = min(elements)
		elements.remove(val)
	elif command == "f":
		elements = [x for x in elements if x % 2 != 0]
	ip += "\n"
ip += "q\n";
f = open('input5.txt','w')
f.write(ip)
f.close()
f = open('output5.txt','w')
f.write(output)
f.close()