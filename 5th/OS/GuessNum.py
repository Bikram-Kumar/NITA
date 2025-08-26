import curses
import random


def main(stdscr):
    counter = 0
    maxCount = 300000
    score = 1000
    num = 0
    goal = round(random.random() * 100)
    hint = "Start!" 
    border = "*" * 40

    stdscr.nodelay(True)
    curses.curs_set(0)

    while True:
        counter += 1
        
        if (counter != maxCount): continue
    
        counter = 0
        
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
                
        if (hint != "You Won!"): score -= 1
        
        stdscr.clear()
        stdscr.addstr(0, 8, border)
        stdscr.addstr(2,20,"Your score: "+str(score))
        stdscr.addstr(7, 23, "Guess: " + str(num))
        stdscr.addstr(12, 23, hint)
        stdscr.addstr(15, 8, border)
        
        stdscr.refresh()
    

curses.wrapper(main)







