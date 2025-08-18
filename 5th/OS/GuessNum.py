import curses
import random


def main(stdscr):
    counter = 0
    maxCount = 300
    cc = 1000
    num = 0
    goal = round(random.random() * 100)
    hint = ""

    stdscr.clear()
    stdscr.nodelay(True)
    #curses.curs_set(0)

    while True:
        stdscr.clear()
        stdscr.addstr(0, 20, "Your score: " + str(cc))
        stdscr.addstr(5, 23, "Guess: " + str(num))
        stdscr.addstr(7, 20, hint)
        key = stdscr.getch()
        
        if (key == ord('q')):
            break
        elif (key >= ord('0') and key <= ord('9')):
            num = (num * 10) + (key - ord('0'))
        elif (key == ord('\n')):
            if (num == goal):
                hint = "You Won!"
                
            elif (num < goal):
                hint = "Go higher!"
            else:
                hint = "Go lower!"
            num = 0
                
        if (counter == maxCount):
            if (hint != "You Won!"): cc -= 1
            counter = 0
    
        counter += 1

        stdscr.refresh()

curses.wrapper(main)
