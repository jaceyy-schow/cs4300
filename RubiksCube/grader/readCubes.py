def main():
    
    def readCubes(filename):
        fin = open(filename, "r")
        cubestring = []
        for line in fin:
            line = line.strip()
            print(line)
            cubestring.append(line)
        fin.close()
        return cubestring
     
    def writeCubes(filename, cubes):
        fout = open(filename, "w")

        for cube in cubes:
            fout.write("echo-------------------------------")
            fout.write("init cube ")
            fout.write(cube)
            fout.write("\n")
            fout.write("run solver_commands.cmd")
            fout.write("\n")
    

    cube1 = input('CubeFile?')
    cube2 = input('Outputfile?')

    cubes = readCubes(cube1)
    cubes2 = writeCubes(cube2, cubes)


main()
    
    
