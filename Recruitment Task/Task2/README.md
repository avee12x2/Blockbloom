# BlockBloom - Recruitment Task

## Task 2
**Aarav Oswal**  
**230012**  

---

## Assumptions:
1. Number of Customers are fixed.
2. Maximum number of movies exist.
3. Each customer is identified with a unique username.
4. Money is dealt strictly in integers.
5. There is a specified format for entering the start time and duration (hr min).
6. Choosing a movie is done strictly by choosing its No. in the list.

---

## Guide to Handle System:
1. There is **1 Manager** and **N (fixed) Customers** who can access the system.
2. The Manager and each of the Customers are initialized at the beginning.
3. The Manager is initialized with:
   - Name
   - Password
   - 0 Account Balance initially
4. Each Customer is initialized with:
   - Unique Username
   - Password
   - Account Balance
5. Note:
   - The **username and password** of the Manager and Customers are **strings**.
   - The **account balance** is strictly an **integer**.
6. There is also a **Maximum Number of Movies** that can be added, which is specified during initialization.
7. After Initialization, the System allows you to **log in** as:
   - Manager
   - Customer
   - End the Program
8. **Manager Actions:**
   - View List of Movies
   - Add a New Movie
   - Remove an Existing Movie
   - View List of Customers for a Particular Movie
   - View Account Balance
   - Change Password
   - Log Out
9. **Movie Start Time and Duration Format:**
   - The required format is **hr min** (hours-space-minutes).  
     Example: `3 45`
10. **Movie Removal & Customer Viewing:**
    - To **remove a movie**, specify the **No.** of the movie.
    - **Specifying the name** of the movie will **crash the program**.
    - The same applies when viewing the list of customers for a movie.
11. **Customer Actions:**
    - View List of Movies
    - View Their Booked Movies
    - Book Tickets
    - Cancel Tickets
    - View Account Balance
    - Add Money to Account
    - Change Password
    - Log Out
12. **Booking & Cancelling Tickets:**
    - The same **No.-based selection rule** as point **10** applies to customers.
