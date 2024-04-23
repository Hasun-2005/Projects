import tkinter as tk
from tkinter import ttk
import numpy as np
import matplotlib.pyplot as plt
import math

def open_graph():
    # Function to open graph plotting GUI
    # Remove previous version if exists
    remove_previous_version()

    # Create the graph window
    graph_window = tk.Toplevel(root)
    graph_window.title("Graph Plotter")

    # Add graph plotting GUI elements here
    equation_label = ttk.Label(graph_window, text="Enter equations (separated by comma):")
    equation_label.pack()

    function_entry = ttk.Entry(graph_window)
    function_entry.pack()

    # Add entry fields for range and domain
    range_label = ttk.Label(graph_window, text="Range (e.g., [start, end]):")
    range_label.pack()
    range_entry = ttk.Entry(graph_window)
    range_entry.pack()

    # Add a button to plot the graph
    plot_button = ttk.Button(graph_window, text="Plot Graph", command=lambda: plot_graph(function_entry.get(), range_entry.get()))
    plot_button.pack()

def plot_graph(equations_str, range_str):
    # Function to plot the graph based on user input
    try:
        # Parse equations
        equations = equations_str.split(',')
        num_equations = len(equations)

        # Parse range
        range_vals = [int(x) for x in range_str[1:-1].split(',')]  # Remove brackets and split by comma

        x = np.linspace(range_vals[0], range_vals[1], 400)

        # Plot each equation
        for i, equation in enumerate(equations):
            y = eval(equation)  # Evaluate the user input as a mathematical expression
            plt.plot(x, y, label=f"Line {i+1}")

        plt.xlabel('x')
        plt.ylabel('y')
        plt.title('Graph Plot')
        plt.grid(True)
        plt.legend()
        plt.show()
    except Exception as e:
        tk.messagebox.showerror("Error", str(e))

def remove_previous_version():
    # Function to remove the previous version of GUI window if exists
    for widget in root.winfo_children():
        if isinstance(widget, tk.Toplevel):
            widget.destroy()
def open_calculator():
    # Function to open calculator GUI
    # Remove previous version if exists
    remove_previous_version()

    # Create the calculator window
    calculator_window = tk.Toplevel(root)
    calculator_window.title("Calculator")

    # Variable to store the input expression
    expression = tk.StringVar()
    expression.set("")

    # Function to update the expression when a button is clicked
    def update_expression(value):
        nonlocal expression
        current_expression = expression.get()
        if value == "=":
            try:
                result = eval(current_expression)
                expression.set(str(result))
            except Exception as e:
                expression.set("Error")
        elif value == "C":
            expression.set("")
        elif value == "Reset":
            expression.set("")  # Clear the input box
        elif value == "sin":
            expression.set(current_expression + "math.sin")
        elif value == "cos":
            expression.set(current_expression + "math.cos")
        elif value == "tan":
            expression.set(current_expression + "math.tan")
        elif value == "log":
            expression.set(current_expression + "math.log10")
        elif value == "e":
            expression.set(current_expression + "math.e")
        elif value == "pi":
            expression.set(current_expression + "math.pi")
        else:
            expression.set(current_expression + value)

    # Add calculator GUI elements
    input_box = ttk.Entry(calculator_window, textvariable=expression, font=('Arial', 14))
    input_box.grid(row=0, column=0, columnspan=4, padx=10, pady=10)

    # Add buttons for numbers, operators, etc.
    buttons = [
        '7', '8', '9', '/',
        '4', '5', '6', '*',
        '1', '2', '3', '-',
        '0', '.', '=', '+',
        'cos', 'sin', 'tan',
        'log', 'e', 'pi',
        'Reset', '(',')',
    ]

    row = 1
    col = 0
    for btn_text in buttons:
        if btn_text == '=':
            ttk.Button(calculator_window, text=btn_text, command=lambda t=btn_text: update_expression(t), width=8).grid(row=row, column=col, padx=5, pady=5, columnspan=2)
            col += 2
        elif btn_text == 'Reset':
            ttk.Button(calculator_window, text=btn_text, command=lambda t=btn_text: update_expression(t), width=8).grid(row=row, column=col, padx=5, pady=5, columnspan=4)
            col += 4
        else:
            ttk.Button(calculator_window, text=btn_text, command=lambda t=btn_text: update_expression(t), width=8).grid(row=row, column=col, padx=5, pady=5)
            col += 1
        if col > 3:
            col = 0
            row += 1




def remove_previous_version():
    # Function to remove the previous version of GUI window if exists
    for widget in root.winfo_children():
        if isinstance(widget, tk.Toplevel):
            widget.destroy()

def main():
    global root
    root = tk.Tk()
    root.title("Graphical Calculator")

    # Styling
    root.geometry("300x200")
    root.resizable(False, False)

    style = ttk.Style(root)
    style.configure('TLabel', font=('Arial', 12))
    style.configure('TEntry', font=('Arial', 12))
    style.configure('TButton', font=('Arial', 12))

    # Create the main frame
    main_frame = ttk.Frame(root, padding="20")
    main_frame.grid(row=0, column=0)

    # Create buttons
    calc_button = ttk.Button(main_frame, text="Calculator", command=open_calculator)
    calc_button.grid(row=0, column=0, padx=10, pady=5, sticky=tk.W+tk.E)

    graph_button = ttk.Button(main_frame, text="Graph", command=open_graph)
    graph_button.grid(row=1, column=0, padx=10, pady=5, sticky=tk.W+tk.E)

    root.mainloop()

if __name__ == "__main__":
    main()

