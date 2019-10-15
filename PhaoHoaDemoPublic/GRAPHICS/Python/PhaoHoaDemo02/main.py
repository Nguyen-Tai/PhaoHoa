import time
from tkinter import *
from global_helper import *
from phao_hoa_manager import *


if __name__ == "__main__":
    window = Tk()
    window.title("Phao hoa demo 02")
    window.resizable(0, 0)

    canvas = Canvas(window, width = Global.WindowWidth, height = Global.WindowHeight, bg="black")
    canvas.pack()
    Global.winCanvas = canvas

    manager = PhaoHoaManager()

    while True:
        manager.CapNhat()
        window.update()
        time.sleep(0.03)
