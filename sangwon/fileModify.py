with open("header.cpp", "r") as f:
    h_lines = f.readlines()
with open("footer.cpp", "r") as f:
    f_lines = f.readlines()

with open("ch21_TreeTraversal/21-2.cpp", "r") as f:
    lines = f.readlines()
        
with open("test.cpp", "w") as f:
    for line in h_lines:
        f.write(line)
    for line in lines:
        f.write(line)
    for line in f_lines:
        f.write(line)