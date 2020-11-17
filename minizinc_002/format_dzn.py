# header
sc_330_0 = open("..\data\sc_330_0", "r")
sc_330_0_header = sc_330_0.readline()
sc_330_0_header_items = sc_330_0_header.split();
# body
dzn_file = ""
dzn_file += "M = " + sc_330_0_header_items[1] + ";\n"
dzn_file += "N = " + sc_330_0_header_items[0] + ";\n\n"
dzn_file += "problem_sets = [\n"
line = sc_330_0.readline()
while line != "":
    dzn_file += "\t{"
    numbers_in_line = line.split()
    for number in numbers_in_line[1:-1]:
        dzn_file += (number + ", ")
    dzn_file += numbers_in_line[-1:][0]
    line = sc_330_0.readline()
    dzn_file += "},\n"
sc_330_0.close()
dzn_file = dzn_file[:-2] + "\n];"
sc_330_0_dzn = open(".\data\sc_330_0.dzn", "w")
sc_330_0_dzn.write(dzn_file)
sc_330_0_dzn.close()
