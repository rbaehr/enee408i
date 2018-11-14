import os
import json

class pipew:

    FIFO='mypiper'

    list= ["Anwaar", "Ross"]
    with open(FIFO, 'w+') as fifo:
        print("FIFO opened")
        fifo.write(list[0])
