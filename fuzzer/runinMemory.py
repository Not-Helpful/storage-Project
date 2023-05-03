
import time
import os

NUMBER_OF_CBOTS = 5
NUMBER_OF_PRINTS = 50

pid = os.fork()
if (pid == 0):
    os.execvp("./linux/cbot", ["cbot"])

for i in range(NUMBER_OF_PRINTS):
    os.system("echo \"Entry:\" >> ./inMemory/data" +str(NUMBER_OF_CBOTS)+".txt")
    cmd = "vmstat -s >> ./inMemory/data" +str(NUMBER_OF_CBOTS)+".txt"
    os.system(cmd)
    time.sleep(10)
