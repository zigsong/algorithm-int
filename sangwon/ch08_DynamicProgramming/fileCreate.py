i = 1 
while (i <= 24):
    with open(f"8-{i}.cpp", "w") as f:
        f.write("#include <iostream>\n")
        f.write("#include <string>\n")
        f.write("#include <vector>\n")
    i += 1

