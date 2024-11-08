import tkinter as tk
from tkinter import ttk

# Initialize the main window
root = tk.Tk()
root.title("Employee Management")

# Labels and Entry Widgets
tk.Label(root, text="Empid").grid(row=0, column=0, sticky=tk.W, padx=5, pady=5)
empid_entry = tk.Entry(root)
empid_entry.grid(row=0, column=1, padx=5, pady=5)

tk.Label(root, text="Employee Name :").grid(row=1, column=0, sticky=tk.W, padx=5, pady=5)
empname_entry = tk.Entry(root)
empname_entry.grid(row=1, column=1, padx=5, pady=5)

tk.Label(root, text="Job").grid(row=2, column=0, sticky=tk.W, padx=5, pady=5)
job_entry = tk.Entry(root)
job_entry.grid(row=2, column=1, padx=5, pady=5)

# Radio Buttons for Employee Type
tk.Label(root, text="Employee type").grid(row=3, column=0, sticky=tk.W, padx=5, pady=5)
emp_type = tk.StringVar(value="Regular")
tk.Radiobutton(root, text="Regular", variable=emp_type, value="Regular").grid(row=3, column=1, sticky=tk.W)
tk.Radiobutton(root, text="Temporary", variable=emp_type, value="Temporary").grid(row=3, column=2, sticky=tk.W)

# Salary Spinbox
tk.Label(root, text="Salary").grid(row=4, column=0, sticky=tk.W, padx=5, pady=5)
salary_spinbox = ttk.Spinbox(root, from_=0, to=100000, increment=1000, width=10)
salary_spinbox.grid(row=4, column=1, padx=5, pady=5)

# Buttons for actions
insert_button = tk.Button(root, text="Insert")
insert_button.grid(row=5, column=0, padx=5, pady=5)

delete_button = tk.Button(root, text="Delete")
delete_button.grid(row=6, column=0, padx=5, pady=5)

update_button = tk.Button(root, text="Update")
update_button.grid(row=5, column=1, padx=5, pady=5)

select_button = tk.Button(root, text="Select")
select_button.grid(row=6, column=1, padx=5, pady=5)

# Run the application
root.mainloop()
