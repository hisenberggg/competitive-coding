from tkinter import *

def demo():
    s=txt1.get()
    s='Hello '+s
    l2.configure(text=s)
    b1.configure(fg='red',bg='yellow')
    b2.configure(fg='red',bg='yellow')

win = Tk()
win.geometry('800x500')
win.title('My Window')

l1=Label(text='name:')
txt1=Entry(width=10)
b1=Button(text='OK',command=demo)
b2=Button(text='CLOSE',command=win.destroy)
l2=Label(text='',width=60,fg='red',bg='cyan')

l1.place(x=50,y=50)
txt1.place(x=100,y=50)
b1.place(x=50,y=100)
b2.place(x=100,y=100)
l2.place(x=60,y=200)

