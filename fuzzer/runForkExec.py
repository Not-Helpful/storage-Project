
import time
import os


def runTest():
    while(1):
        if os.waitpid(pid, os.WNOHANG) != 0:
            break
        os.system("echo \"Entry:\" >> ./forkexecData/data.txt")
        cmd = "vmstat -s >> ./forkexecData/data.txt"
        os.system(cmd)
        time.sleep(10)

if __name__ == "__main__":
    pid = os.fork()
    if pid != 0:
        runTest()

    
    if (pid == 0):
        os.execvp("./forkexec", ["-h"])

    # Cant happen
        
    

