import random
import string


def header(file):
    file.write("#include <stdio.h>\n")
    file.write("int main() {\n")


def randomPrints(file):
    for i in range(5000000):
        file.write("printf(\"")
        file.write(''.join(random.choices(string.ascii_lowercase, k=5)))
        file.write("\");\n")


def closing(file):
    file.write("}")


if __name__=="__main__":
    file = open("target.c", 'w')
    header(file)
    randomPrints(file)
    closing(file)
    file.close()