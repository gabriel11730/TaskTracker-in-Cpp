# Task Tracker CLI

This command-line program is part of the [Task Tracker CLI](https://roadmap.sh/projects/task-tracker) by *Roadmap.sh*.

I developed this application using C++ and functional programming, deliberately avoiding OOP.

Using **positional arguments** to capture user input and saving tasks in **.json** files
## 🧩 What can you do?

- Add, Update, and Delete tasks
- Mark a task as in progress or done
- List all tasks
- List all tasks are not done
- List all tasks are in progress
- List all tasks are done

## 👨🏻‍💻 What technologies did I use?

- Only **C++ 17** and **VS Code**

## 🏃🏻‍♂️‍➡️ How to Run the Program

   ```bash
   git clone https://github.com/gabriel11730/TaskTracker-in-Cpp.git
   cd .\TaskTracker-in-Cpp\main
   ```

## 📖 How to Usage
```bash
# Adding a new task
.\task-cli add "Buy groceries"
# output: Task added successfully (ID: 1)

# Updating task
.\task-cli update 1 "Buy groceries and cook dinner"

# Deleting task
.\task-cli delete 1
# output: Task deleted

# Marking a task as in progress
.\task-cli mark-in-progress 1

# Marking a task as done
.\task-cli mark-done 1

# Listing all tasks
.\task-cli list

# Listing tasks by status
.\task-cli list todo
.\task-cli list in-progress
.\task-cli list done
```
