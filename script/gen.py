import sys
import re

if len(sys.argv) < 2:
    print("Day wasn't specified")
    sys.exit()

day = sys.argv[1]

# Generate header file
with open("script/templates/header.txt", "r") as file:
	data = file.read()
	data = data.replace("${DAY}", day)
    
	header = open("inc/day" + day + ".h", "w")
	header.write(data)

# Generate source file
with open("script/templates/source.txt", "r") as file:
	data = file.read()
	data = data.replace("${DAY}", day)
    
	source = open("src/day" + day + ".cpp", "w")
	source.write(data)

# Modify main.cpp
with open("main.cpp", "r+") as file:
	data = file.read()
	
	positions = [pos.start() for pos in re.finditer("day", data)]
	for pos in reversed(positions):
		data = data[:pos + 3] + day + data[pos + 5:]
    
	file.seek(0)
	file.write(data)

# Modify src/CMakeLists.txt
with open("src/CMakeLists.txt", "r+") as file:
	data = file.read()
	pos = data.find("PARENT_SCOPE")
	data = data[:pos] + "${{CMAKE_CURRENT_SOURCE_DIR}}/day{}.cpp\n\t".format(day) + data[pos:]
    
	file.seek(0)
	file.write(data)
