import tkinter as tk

root=tk.Tk()
root.geometry("500x500")
root.title("APP")

label = tk.Label(root, text="HEllo World", font =('Arial',18))
label.pack(padx=20,pady=20)

textbox = tk.Text(root,height=3,font=('Arial',15))
textbox.pack()


myentry = tk.Entry(root)
myentry.pack()



# button = tk.Button(root, text = "Click me" , font =('Arial',20), background='RED')
# button.pack(pady=20)


mybuttonframe = tk.Frame(root)
mybuttonframe.columnconfigure(0,weight=1)
mybuttonframe.columnconfigure(1,weight=1)
mybuttonframe.columnconfigure(2,weight=1)


btn1 = tk.Button(mybuttonframe,text='1',font=('Arial',18))
btn1.grid(row=0 , column=0, sticky=tk.W+tk.E)

btn2 = tk.Button(mybuttonframe,text='2',font=('Arial',18))
btn2.grid(row=0 , column=1, sticky=tk.W+tk.E)

btn3 = tk.Button(mybuttonframe,text='3',font=('Arial',18))
btn3.grid(row=0 , column=2, sticky=tk.W+tk.E)

btn4 = tk.Button(mybuttonframe,text='4',font=('Arial',18))
btn4.grid(row=1 , column=0, sticky=tk.W+tk.E)

btn5 = tk.Button(mybuttonframe,text='5',font=('Arial',18))
btn5.grid(row=1 , column=1, sticky=tk.W+tk.E)

btn6 = tk.Button(mybuttonframe,text='6',font=('Arial',18))
btn6.grid(row=1 , column=2, sticky=tk.W+tk.E)

mybuttonframe.pack(fill='x')
root.mainloop()


