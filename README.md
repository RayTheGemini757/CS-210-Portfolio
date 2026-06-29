# Grocery Item Frequency Tracker

## Project Summary
This application was built to solve a standard inventory data problem: parsing an unorganized transaction log (`CS210_Project_Three_Input_File.txt`) and generating clean, actionable metrics from it. The C++ program reads the raw text file, processes the exact total for each item, and outputs a clean interface where a user can search individual items, print a master frequency list, or look at a text-based histogram.

## Reflection

### What I Did Well
Coming from a technical background where layout and structure matter, I focused heavily on the architecture of the program. Instead of letting the logic turn into a messy, single-file script, I treated it like a clean hardware installation—breaking the program down into distinct, modular classes. The separation between the file-parsing backend and the user-facing menu loop is incredibly tight and well-organized.

### Areas for Enhancement
If I were taking this build to the next stage, I’d focus on defensive programming. Right now, the menu loop is vulnerable if a user inputs characters instead of integers, so I need to implement tighter input validation to make the program completely crash-proof. On the data side, shifting from a standard `std::map` to an `std::unordered_map` would optimize lookup efficiency from $O(\log n)$ to $O(1)$, which is the kind of optimization that matters when scaling up to massive datasets.

### Challenges and Overcoming Them
The most tedious part of the build was getting the text-based histogram formatting to align perfectly regardless of how long the item names were. It’s a layout issue, and I had to get under the hood of the `iomanip` library to lock down the column widths. When troubleshooting the formatting syntax, I relied on standard documentation and technical programming references to get the output looking sharp and professional.

### Transferable Skills
The core mechanics of this project—handling file streams (`ifstream`/`ofstream`) and using key-value data structures to map information—are highly transferable. Getting comfortable managing how data flows into and out of a system is a fundamental skill that I know will translate directly into my future object-oriented programming courses, like working with data models in Java.

### Maintainability, Readability, and Adaptability
I built this program with the mindset that the next person looking at it should be able to understand the layout immediately without a map. I used highly descriptive variable names and commented the logic clearly. Because the system is modular, it’s incredibly adaptable; you could swap out the grocery list for a completely different inventory file, like tracking warehouse parts or tool counts, and the program would handle it perfectly without needing a rebuild.
