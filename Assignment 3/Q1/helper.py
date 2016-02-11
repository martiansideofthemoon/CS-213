import random
import string
import math
def id_generator(size = 6, chars=string.ascii_uppercase + string.digits):
	return ''.join(random.choice(chars) for _ in range(size))
lines = 1000000
letters = 100
duplicates = random.randrange(math.floor(0.02*lines), math.ceil(0.05*lines))
f = open('1.in','w')
f.write("input.txt\n" + str(letters))
f.close()
output = ""
strs = []
str_map = {}
for i in range(1, lines - duplicates + 1):
	s = id_generator(letters)
	while s in str_map:
		print "It's unlikely that this should happen!"
		s = id_generator(letters)
	strs.append(s)
	str_map[s] = 1
for i in range(1, duplicates + 1):
	index1 = random.randrange(0, len(strs))
	index2 = random.randrange(0, len(strs))
	strs.insert(index1, strs[index2])
	#strs.append(strs[index2])
for line in strs:
	output += line
f = open('input.txt','w')
f.write(output)
f.close()
f = open('output.txt','w')
f.write(str(lines - duplicates) + "\n")
f.close()