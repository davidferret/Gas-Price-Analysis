# Gas Price Analysis Program
You can use this program to analyze gas price data by reading monthly gas prices from a file and sorting it by either regular gas price or month. It calculates the average prices for both regular and premium gas, and compares historical price trends over time. Additionally, it can help you identify the months with the lowest gas prices, and lets you search for months where prices were below a user-defined threshold.

I created this program since I started driving in the Summer of 2022, when gas prices were nearly $5 in Florida, and to this day, it is listed by AAA as the highest prices ever. I thought it would be useful to have a tool that could not only display the trends but also provide some deeper insights into which months have historically been the cheapest. It was a fun project to build and a great way to practice working with data analysis and file handling.

## Example Output
```
Choose sorting method:
1 - Sort by Regular Gas Price
2 - Sort by Month
3 - No Sorting
Enter choice: 1

Choose sorting order:
1 - Ascending
2 - Descending
Enter choice: 1

Month     Year      Regular   Premium    
March     2023      3.10      3.80      
January   2023      3.25      3.90      
February  2023      3.50      4.10      

The average regular gasoline price: 3.28
The average premium gasoline price: 3.93

Cheapest months with regular gas price of 3.10:
March 2023

Historical Gas Price Comparison:
2022 vs 2023 - Regular: 3.00 -> 3.10, Premium: 3.75 -> 3.80

Enter a price threshold to find months with regular gas price below this value: 3.30
Months with regular gas price below 3.30:
Regular: 3.10 | Premium: 3.80

```
