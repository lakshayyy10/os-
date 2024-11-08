import tkinter as tk
from tkcalendar import Calendar

def get_date():
    selected_date = cal.get_date()
    print("Selected Date:", selected_date)

root = tk.Tk()
root.title("Calendar Example")

# Create a calendar widget
cal = Calendar(root, selectmode='day', year=2023, month=11, day=7)
cal.pack(pady=20)

# Button to get the selected date
btn = tk.Button(root, text="Get Date", command=get_date)
btn.pack(pady=10)

root.mainloop()
