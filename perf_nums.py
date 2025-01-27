import os, threading, time

perfectNumsFound = []
threads = []
i = 1

# A script that finds perfect numbers (https://en.wikipedia.org/wiki/Perfect_number).

def main():
    global i
    os.system('clear')
    try:
        while i < float('inf'):
            sum = 0
            for div in range(1, i):
                if i % div == 0:
                    sum += div
            if sum == i:
                perfectNumsFound.append(i)
            i += 1
    except KeyboardInterrupt:
        quit()

def interface():
    while True:
        os.system('clear')
        print(f"""
    Perfect Number finder

    Processing... {i}
    
    Perfects found: """)
        for number in perfectNumsFound:
            print(f"        > {number} ")
        time.sleep(0.5)

interfaceThread = threading.Thread(target=interface)
interfaceThread.daemon = True              
interfaceThread.start()
main()
