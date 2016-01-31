import random
import string

def id_generator(size = 6, chars=string.ascii_uppercase + string.digits):
	return ''.join(random.choice(chars) for _ in range(size))
q = 10000
N = 3
input_file = str(q) + "\n"
output_file = ""
options = ['a', 'u', 'r', 'g', 'e']
operations = []
data = ""
redo_stack = []
for i in range(1, q + 1):
	choice = 0
	if len(data) == 0:
		choice = random.randrange(0, 3)
	else:
		choice = random.randrange(0, 5)
	choice = options[choice]
	s = ""
	if choice == 'a':
		s = id_generator(3);
		data += s
		operations.append(data)
		del redo_stack[:]
	elif choice == 'e':
		k = random.randrange(1, len(data) + 1)
		s = str(k)
		data = data[:-1*k]
		operations.append(data)
		del redo_stack[:]
	elif choice == 'g':
		k = random.randrange(0, len(data))
		s = str(k)
		output_file += data[k] + "\n"
	elif choice == 'u':
		if len(operations) > 0:
			redo_stack.append(operations[-1])
			operations.pop()
			if len(operations) == 0:
				data = ""
			else:
				data = operations[-1]
	elif choice == 'r':
		if len(redo_stack) > 0:
			operations.append(redo_stack[-1])
			redo_stack.pop()
			data = operations[-1]
	input_file += choice + " " + s + "\n"
	#print data
f = open('1.in','w')
f.write(input_file)
f.close()
f = open('1.out','w')
f.write(output_file)
f.close()