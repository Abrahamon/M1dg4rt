from Tkinter import *
import tkFileDialog
from PIL import Image
import time
from threading import Thread
import threading
import tkMessageBox
import os


def save():
    if(checkMATRIX()):
        global MAP_CANVAS
        window = Toplevel(takefocus=True)
        window.title("Enter file name")
        window.geometry("300x150+500+250")
        
        
        def ok():
            if(InputA.get() != ""):
                mapName = "MapFiles/" + InputA.get() + ".map"
                imgName = "MapImages/" + InputA.get() + ".eps"
                finalImage = "MapImages/" + InputA.get() + ".png"
                window.destroy()
                MAP_CANVAS.postscript(file=imgName)
                img = Image.open(imgName)
                img.save(finalImage,"png")
                with open(mapName, "w") as file:
                    for i in range(0,len(matrix)):
                        for j in range(0,len(matrix[i])):
                            file.write(str(matrix[i][j]))
                        file.write("\n")
                os.remove(imgName)
                tkMessageBox.showinfo("", "Map saved succesfully")
            else:
                tkMessageBox.showwarning("", "Name is empty")
                window.destroy()
                save()
        def cancel():
            window.destroy()

        InputA = Entry(window,width=25)
        InputA.place(x=45,y=30)
        botonA = Button(window,width=7,height=2,command=ok,text="Ok",bg="#5BB228",fg="#000000")
        botonA.place(x=50,y=80)
        botonB = Button(window,width=7,height=2,command=cancel,text="Cancel",bg="#5BB228",fg="#000000")
        botonB.place(x=150,y=80)
    
def load():
    mapName = tkFileDialog.askopenfilename(filetypes = (("Map Files", "*.map"),("All files", "*.*")))
    global matrix

    col_width = MAP_CANVAS.winfo_width()/COLS
    row_height = MAP_CANVAS.winfo_height()/ROWS

    def removeCurrent_I_J():
        MAP_CANVAS.delete(tiles[i][j])
        tiles[i][j] = None
        matrix[i][j]=0

    def fill_and_done(code):
        removeCurrent_I_J()
        if(code == 1):
            tiles[i][j] = MAP_CANVAS.create_rectangle(j*col_width, i*row_height,(j+1)*col_width,(i+1)*row_height,width=0,fill="green")
            setTileCode("green",i,j)
        elif(code == 2):
            tiles[i][j] = MAP_CANVAS.create_rectangle(j*col_width, i*row_height,(j+1)*col_width,(i+1)*row_height,width=0,fill="blue")
            setTileCode("blue",i,j)
        elif(code == 3):
            tiles[i][j] = MAP_CANVAS.create_rectangle(j*col_width, i*row_height,(j+1)*col_width,(i+1)*row_height,width=0,fill="red")
            setTileCode("red",i,j)
        elif(code == 4):
            tiles[i][j] = MAP_CANVAS.create_rectangle(j*col_width, i*row_height,(j+1)*col_width,(i+1)*row_height,width=0,fill="black")
            setTileCode("black",i,j) 
        
    with open(mapName, "r") as file:
        for i in range(0,30):
            for j in range(0,30):
                text = file.read(1)
                if(text != "\n"):
                    code = int(text)
                    fill_and_done(code)
                else:
                    code = int(file.read(1))
                    fill_and_done(code)
def checkMATRIX():
    for i in range(0,len(matrix)):
        for j in range(0,len(matrix[i])):
            if(matrix[i][j] == 0):
                tkMessageBox.showerror("Map couldn't be save", "You have not fill all available spaces in the map")
                return False
    return True
def create_MATRIX(rows,cols):
    global matrix,tiles
    matrix = []
    tiles = []
    tiles = [[None for _ in range(cols)] for _ in range(rows)]
    for i in range(0,rows):
        matrix.append([])
        for j in range(0,cols):
            matrix[i].append(0)
def setTileCode(color,i,j):
        global matrix
        if(color == "blue"):
            matrix[i][j]=2
        elif(color == "red"):
            matrix[i][j]=3
        elif(color == "black"):
            matrix[i][j]=4
        elif(color == "green"):
            matrix[i][j]=1
def fill():
    global En1,En2,En3,En4,matrix,tiles
    def badINPUT():
        tkMessageBox.showwarning("Bad input", "Input not match matrix")
    try:
        X1 = int(En1.get())
        Y1 = int(En2.get())
        X2 = int(En3.get())
        Y2 = int(En4.get())
    except:
        tkMessageBox.showwarning("Bad input", "Blank input")
        return
    if(X1 < 0 or X1 > 30):
        badINPUT()
        return
    if(Y1 < 0 or Y1 > 30):
        badINPUT()
        return
    if(X2 < 0 or X2 > 30):
        badINPUT()
        return
    if(Y2 < 0 or Y2 > 30):
        badINPUT()
        return
    En1.delete(0, 'end')
    En2.delete(0, 'end')
    En3.delete(0, 'end')
    En4.delete(0, 'end')

    col_width = MAP_CANVAS.winfo_width()/COLS
    row_height = MAP_CANVAS.winfo_height()/ROWS
    def removeCurrent_I_J():
        MAP_CANVAS.delete(tiles[i][j])
        tiles[i][j] = None
        matrix[i][j]=0
    for i in range(X1,Y1):
        for j in range(X2,Y2):
            if(v.get()=="blue" or v.get()=="red" or v.get() =="black"):
                removeCurrent_I_J()
                tiles[i][j] = MAP_CANVAS.create_rectangle(j*col_width, i*row_height,
                                                      (j+1)*col_width,(i+1)*row_height,width=0,fill=v.get())
                setTileCode(v.get(),i,j)
            elif(v.get()=="green"):
                removeCurrent_I_J()
                tiles[i][j] = MAP_CANVAS.create_rectangle(j*col_width, i*row_height,
                                                       (j+1)*col_width,(i+1)*row_height,width=0,fill=v.get())
                setTileCode(v.get(),i,j)
            elif(v.get()=="null"):
                removeCurrent_I_J()
        

def show_MAIN_WINDOW():
    root = Tk()                     #Crea ventana Principal
    root.title("Midgard Map Editor")#Nombre de la ventana
    root.configure(background="#BCBCB2")
    root.geometry("1050x650+200+70")
    root.resizable(width=False,height=False)#No permitir cambiar la ventana
    
    global MAP_CANVAS,ROWS,COLS

    ROWS = 30
    COLS = 30
                                    #780 #600
    MAP_CANVAS = Canvas(root,width=780,height=600,bg="white")
    MAP_CANVAS.place(x=20,y=20)

    
    create_MATRIX(ROWS,COLS)        #Crea la matriz en funcion del
                                    #numero de filas y columnas. (30x30)
    def createRadioButtons():
        i=10
        for text, mode in MODES:
            b = Radiobutton(root, text=text,variable=v, value=mode,bg="#BCBCB2",highlightbackground="#BCBCB2",highlightcolor="#BCBCB2")
            b.place(x=805,y=i)
            i+=50
            
    def callback(event):
        global v,matrix,tiles
        
        col_width = MAP_CANVAS.winfo_width()/COLS
        row_height = MAP_CANVAS.winfo_height()/ROWS
        
        #Calcular la fila y la columna en la que se hizo click
        col = event.x//col_width
        row = event.y//row_height
        #Si no hay ningun rectangulo, crear uno
        try:
            if not tiles[row][col]:
                if(v.get()=="blue" or v.get()=="red" or v.get() =="black"):
                    tiles[row][col] = MAP_CANVAS.create_rectangle(col*col_width, row*row_height,
                                                          (col+1)*col_width,(row+1)*row_height,width=0,fill=v.get())
                    setTileCode(v.get(),row,col)
                elif(v.get()=="green"):
                    tiles[row][col] = MAP_CANVAS.create_rectangle(col*col_width, row*row_height,
                                                           (col+1)*col_width,(row+1)*row_height,width=0,fill=v.get())
                    setTileCode(v.get(),row,col)
            #Si se va a borrar, eliminar el rectangulo y eliminar la referencia.
            else:
                if(v.get()=="null"):
                    MAP_CANVAS.delete(tiles[row][col])
                    tiles[row][col] = None
                    matrix[row][col]=0
        except:#Si se sal de los limites del canvas
            return
    
    MAP_CANVAS.bind("<B1-Motion>", callback) #arrastre del mouse al canvas
    MAP_CANVAS.bind("<Button-1>", callback)  #click del mouse al canvas

    ############################################################################################
    ##### INTERFAZ GRAFICA #####################################################################
    ############################################################################################

    #------ Botones -------#
    botonA = Button(root,width=7,height=2,command=save,text="Save Map",bg="#5BB228",fg="#000000")
    botonA.place(x=810,y=380)
    botonB = Button(root,width=7,height=2,command=load,text="Load Map",bg="#5BB228",fg="#000000")
    botonB.place(x=900,y=380)
    botonB = Button(root,width=7,height=2,command=exit,text="Exit",bg="#5BB228",fg="#000000")
    botonB.place(x=810,y=428)
    
    botonD = Button(root,width=7,height=2,command=fill,text="Fill",bg="#5BB228",fg="#000000")
    botonD.place(x=915,y=272)

    #------ Entrys -------#
    global En1,En2,En3,En4
    En1 = Entry(root,width=5)
    En2 = Entry(root,width=5)
    En3 = Entry(root,width=5)
    En4 = Entry(root,width=5)
    Tx1 = Label(root, text="Y Start",bg="#BCBCB2")
    Tx2 = Label(root, text="Y End",bg="#BCBCB2")
    Tx3 = Label(root, text="X Start",bg="#BCBCB2")
    Tx4 = Label(root, text="X End",bg="#BCBCB2")
    
    En1.place(x=815,y=260)
    En2.place(x=865,y=260)
    En3.place(x=815,y=310)
    En4.place(x=865,y=310)
    Tx1.place(x=815,y=240)
    Tx2.place(x=865,y=240)
    Tx3.place(x=815,y=290)
    Tx4.place(x=865,y=290)

    for i in range(1,31):
        pText = str(i-1)
        y=Label(root, text=pText,bg="#BCBCB2")
        x=Label(root,text=pText,bg="#BCBCB2")
        
        pY=i*20
        pX=i*26
        y.place(x=0,y=pY-3)
        x.place(x=pX-3,y=0)

    #------ Modo de Pintado -------#
    #------ Radio Buttons   -------#
    MODES = [("Agua", "blue"),("Zacate", "green"),("Fuego", "red"),("Muro","black"),("Remover","null")]

    global v
    v = StringVar()
    v.set("blue")

    
    createRadioButtons()
    root.mainloop()

show_MAIN_WINDOW()
   




