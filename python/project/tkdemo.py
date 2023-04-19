# http://tkdocs.com/

# sudo apt install python3-tk
import tkinter as tk
from PIL import Image, ImageTk
import time

# https://stackoverflow.com/questions/66918142/another-method-to-move-canvas-objects
# Not needed in Python 3.8+, use moveto() instead
def abs_move(self, _object, new_x, new_y):
    # Get the current object position
    x, y, *_ = self.bbox(_object)
    # Move the object
    self.move(_object, new_x-x, new_y-y)
# Monkey patch the `abs_move` method
tk.Canvas.abs_move = abs_move

windowWidth = 500
windowHeight = 400

root = tk.Tk()
root.title("Drawing to the Canvas")
root.geometry(f'{windowWidth}x{windowHeight}')

canvas = tk.Canvas(root, background='gray75')
canvas.pack(fill="both", expand=True)

canvas.create_line(0, 0, windowWidth-1, windowHeight-1, fill='red', width=3)
canvas.create_line(0, windowHeight-1, windowWidth-1, 0, dash=(6, 2, 2, 2), width=4, arrow=tk.LAST, arrowshape=(16, 20, 6))

padding = 10

squareSide = 100
canvas.create_rectangle(padding, windowHeight/2-squareSide/2, 
    padding+squareSide, windowHeight/2+squareSide/2, 
    fill='red', outline='blue') 
    # top left - botton right

ellipseWidth = 200
ellipseHeight = 100
ellipseColors = ('red', 'yellow', '#00ff00')
ellipseCurrentColor = 0
ellipse = canvas.create_oval(windowWidth-padding-ellipseWidth, windowHeight/2-ellipseHeight/2, 
    windowWidth-padding, windowHeight/2+ellipseHeight/2, 
    fill=ellipseColors[ellipseCurrentColor], outline='blue')

triangleSide = 100
canvas.create_polygon(windowWidth/2-triangleSide/2, 
    padding, windowWidth/2+triangleSide/2,
    padding, windowWidth/2, triangleSide+padding)

# sudo apt-get install python3-pil python3-pil.imagetk
car = Image.open('kaefer.jpg')
width, height = car.size
requiredCarHeight = 100
carWidth, carHeight = round(width/(height/requiredCarHeight)), requiredCarHeight
carTk = ImageTk.PhotoImage(car.resize((carWidth, carHeight)))
# the position of the top left corner of the image is specified
carX = windowWidth/2-carWidth/2
carY = windowHeight-padding-carHeight
carImage = canvas.create_image(carX, carY, image=carTk)
carXMoveBy = -1
frames = 0

while(True):
    time.sleep(0.04) # 40ms = 25 frames per second
    if carX > padding:
        carX += carXMoveBy
    else:
        carX = windowWidth-padding-carWidth
    canvas.abs_move(carImage, carX, carY)

    if frames % 25 == 0:
        ellipseCurrentColor = (ellipseCurrentColor+1) % len(ellipseColors)
        canvas.itemconfigure(ellipse, fill=ellipseColors[ellipseCurrentColor])

    frames += 1
    root.update()
