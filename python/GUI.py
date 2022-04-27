#GUI in python
'''
tkinter - toolkit interface

1)Root window
2) Canvas ,Frame
3)put window in loop
'''

from tkinter import *

win = Tk()         # root window
win.geometry('500x300')
win.title('My window')

l1=Label(text='Hello python' , fg='red' , bg='yellow', width=10,height=1,font=('Arial',20))
l2=Label(text='Its easy' , fg='red' , bg='cyan',width=10,height=1, font=('Arial',20))
l3=Label(text='hello' , fg='red' , bg='cyan',width=10,height=1, font=('Arial',20))
l4=Label(text='pycoders' , fg='red' , bg='yellow',width=10,height=1, font=('Arial',20))
'''
l1.pack()
l2.pack()


l1.grid(row=0,column=0,padx=10,pady=10)
l2.grid(row=0,column=1,padx=10,pady=10)
l3.grid(row=1,column=0,padx=10,pady=10)
l4.grid(row=1,column=1,padx=10,pady=10)
'''
l1.place(x=50,y=50)
l2.place(x=50,y=200)
l3.place(x=50,y=100)
l4.place(x=50,y=100)

win.mainloop()
