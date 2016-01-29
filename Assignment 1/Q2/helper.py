import random
pageids = 100000
frames = 100000
refs = 100000
output = str(pageids) + " " + str(frames) + " " + str(refs) + "\n"
for i in range(1, refs + 1):
	output += str(random.randrange(0, pageids)) + " ";
f = open('1.in','w')
f.write(output) # python will convert \n to os.linesep
f.close()