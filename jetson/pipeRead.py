import os
import errno


class piper:

    FIFO='mypiper'

    try:
        os.mkfifo(FIFO)
    except OSError as oe:
        if oe.errno != errno.EEXIST:
            raise

    while True:
        print("Opening FIFO...")
        with open(FIFO) as fifo:
            print("FIFO opened")
            while True:
                data = fifo.read()
                if len(data) == 0:
                    print("Writer closed")
                    break
                #handle data here
                #Dispense function passing person data
                #Currently printing recognized person name
                print('Read: "{0}"'.format(data))
